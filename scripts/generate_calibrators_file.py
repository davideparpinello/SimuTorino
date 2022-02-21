import json
import xml.etree.ElementTree as ET
import requests
import random

color_value = 'yellow'
route_prefix = 'route_'
cal_prefix = 'calibrator_'
pos_value = 0.00
freq_value = 0.1

flow_begin_value = 0
flow_end_value = 3600
flow_departPos_value = "free"
flow_departSpeed_value = "max"
flow_route_prefix = "routedistcal"
flow_vehsPerHour_value = 0
flow_speed_value = 10

output_file = './utils/cal_add.xml'

output_file_root = ET.Element('additional')
output_file_root.set("xmlns:xsi","http://www.w3.org/2001/XMLSchema-instance")
output_file_root.set("xsi:noNamespaceSchemaLocation","http://sumo.dlr.de/xsd/additional_file.xsd")


input_file = './utils/calibrators_db.json'

traffic_file_url = "https://opendata.5t.torino.it/get_fdt"
xml_node_elem = 'FDT_data'

namespaces = {'': 'https://simone.5t.torino.it/ns/traffic_data.xsd'}

response = requests.get(traffic_file_url)
string_xml = response.content

try:
    root = ET.fromstring(string_xml)    

    with open(input_file, "r") as calibrators_db:
        data = json.load(calibrators_db)
        i = 1
        for calibrator in data['calibrators']:
            current_lat = calibrator['pos']['lat']
            current_lon = calibrator['pos']['lon']
            for node in root.findall(xml_node_elem, namespaces):
                if node.attrib['lat'] == str(current_lat) and node.attrib['lng'] == str(current_lon) :
                    speedflow = node.find('speedflow', namespaces)
                    current_flow = speedflow.attrib['flow']
                    current_speed = speedflow.attrib['speed']

            current_route_elem = ET.SubElement(output_file_root, 'route')
            current_route_elem.set("edges", calibrator['edge'])
            current_route_elem.set("color", color_value)
            current_route_elem.set("id", route_prefix + calibrator['id'])

            current_cal_elem = ET.SubElement(output_file_root, 'calibrator')
            current_cal_elem.set("id", cal_prefix + calibrator['id'])
            current_cal_elem.set("edge", calibrator['edge'])
            current_cal_elem.set("pos", str(pos_value))
            current_cal_elem.set("freq", str(freq_value))

            current_flow_elem = ET.SubElement(current_cal_elem, 'flow')
            current_flow_elem.set("begin", str(flow_begin_value))
            current_flow_elem.set("end", str(flow_end_value))
            current_flow_elem.set("departPos", flow_departPos_value)
            current_flow_elem.set("departSpeed", flow_departSpeed_value)
            current_flow_elem.set("route", flow_route_prefix + str(i))
            current_flow_elem.set("vehsPerHour", str(current_flow))
            current_flow_elem.set("speed", str(flow_speed_value))
            i += 1

except ET.ParseError:
    print("Error in XML parsing, probably because of Opendata Server not responding.\n")
    print("Generating calibrators with random flows..\n")

    with open(input_file, "r") as calibrators_db:
        data = json.load(calibrators_db)
        i = 1
        for calibrator in data['calibrators']:
            current_lat = calibrator['pos']['lat']
            current_lon = calibrator['pos']['lon']
       
            current_route_elem = ET.SubElement(output_file_root, 'route')
            current_route_elem.set("edges", calibrator['edge'])
            current_route_elem.set("color", color_value)
            current_route_elem.set("id", route_prefix + calibrator['id'])

            current_cal_elem = ET.SubElement(output_file_root, 'calibrator')
            current_cal_elem.set("id", cal_prefix + calibrator['id'])
            current_cal_elem.set("edge", calibrator['edge'])
            current_cal_elem.set("pos", str(pos_value))
            current_cal_elem.set("freq", str(freq_value))

            current_flow_elem = ET.SubElement(current_cal_elem, 'flow')
            current_flow_elem.set("begin", str(flow_begin_value))
            current_flow_elem.set("end", str(flow_end_value))
            current_flow_elem.set("departPos", flow_departPos_value)
            current_flow_elem.set("departSpeed", flow_departSpeed_value)
            current_flow_elem.set("route", flow_route_prefix + str(i))
            current_flow_elem.set("vehsPerHour", str(random.randrange(50,800)))
            current_flow_elem.set("speed", str(flow_speed_value))
            i += 1

tree = ET.ElementTree(output_file_root)
tree.write(output_file)