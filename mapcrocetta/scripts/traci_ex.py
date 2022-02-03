import os, sys
import requests
import xml.etree.ElementTree as ET
import json

if 'SUMO_HOME' in os.environ:
    tools = os.path.join(os.environ['SUMO_HOME'], 'tools')
    sys.path.append(tools)
else:
    sys.exit("please declare environment variable 'SUMO_HOME'")


import traci      # type: ignore
import sumolib    # type: ignore

sumoBinary = sumolib.checkBinary('sumo-gui')

print(os.getcwd())
sumoCmd = [sumoBinary, "-c", os.getcwd()+ "/utils/map.sumo.cfg"]


calibrators_db_file = './utils/calibrators_db.json'
traffic_file_url = "https://opendata.5t.torino.it/get_fdt"
xml_node_elem = 'FDT_data'

namespaces = {'': 'https://simone.5t.torino.it/ns/traffic_data.xsd'}
counter=0
step=0
time=100
traci.start(sumoCmd)
while traci.simulation.getMinExpectedNumber() > 0 :
    traci.simulationStep()
    
    if (step % time)<0.1:     #every "time"(100) seconds of simulation
        counter+=1
        response = requests.get(traffic_file_url)
        string_xml = response.content
        root = ET.fromstring(string_xml)

        with open(calibrators_db_file, "r") as calibrators_db:
            calibrators = json.load(calibrators_db)
            i=1
            print("\nSynchronizing " + str(counter) + " current flow with opendata")
            for calibrator in calibrators['calibrators']:
                current_lat = calibrator['pos']['lat']
                current_lon = calibrator['pos']['lon']
                for node in root.findall(xml_node_elem, namespaces):
                    if node.attrib['lat'] == str(current_lat) and node.attrib['lng'] == str(current_lon) :
                        speedflow = node.find('speedflow', namespaces)
                        current_flow = speedflow.attrib['flow']
                        current_speed = speedflow.attrib['speed']
                        print("calibrator_"+calibrator['id'] + " " + current_flow)
                        traci.calibrator.setFlow("calibrator_"+calibrator['id'], 0, 3600, current_flow, 10, 'DEFAULT_VEHTYPE' , "routedistcal"+str(i), departLane='free', departSpeed='max')
                i+=1
    step += 0.1
traci.close()



    
