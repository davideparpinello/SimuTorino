import os, sys
import csv
import json
import xml.etree.ElementTree as ET

if 'SUMO_HOME' in os.environ:
    tools = os.path.join(os.environ['SUMO_HOME'], 'tools')
    sys.path.append(tools)
else:   
    sys.exit("please declare environment variable 'SUMO_HOME'")

import sumolib # type: ignore

filenamexml = './utils/map.net.xml'
net = sumolib.net.readNet(filenamexml)

tree = ET.parse(filenamexml)
root = tree.getroot()

for name in root.findall(".//location"):
    string_extracted=name.get('convBoundary').split(",")
    ymax=float(string_extracted[3])

filename = './utils/tim_lteitaly.csv'
filename_json = './utils/gnodeB_IDs.json'
i=0

with open(filename_json, "r+") as gnodeB_IDs:
    data = json.load(gnodeB_IDs)
    for gnodeB in data['gnodeB']:
        current_id = gnodeB['id']
        current_cell = gnodeB['cell']

        with open(filename, 'r') as csvfile:
            datareader = csv.reader(csvfile, delimiter = ';')
            for row in datareader:
                if(row[4] == current_id and row[5] == current_cell):
                    i+=1
                    current_lat = row[10]
                    current_lon = row[11]
                    x, y = net.convertLonLat2XY(current_lon, current_lat)
                    gnodeB['name_Omnet'] = "gNodeB" + str(i)
                    gnodeB['lat'] =  current_lat
                    gnodeB['lon'] = current_lon
                    gnodeB['pos'] = str(x)+","+str((ymax - y))

    gnodeB_IDs.truncate(0)
    gnodeB_IDs.seek(0)
    json.dump(data, gnodeB_IDs, ensure_ascii=False, indent=4)
