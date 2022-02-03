import xml.etree.ElementTree as ET
import json


filename_xml = "./utils/prova5G.ned.xml"
tree = ET.parse(filename_xml)
root = tree.getroot()

filename_json = './utils/gnodeB_IDs.json'
i=0

with open(filename_json, "r") as gnodeB_IDs:
    data = json.load(gnodeB_IDs)
    for gnodeB in data['gnodeB']:
        current_name = gnodeB['name_Omnet']
        current_pos = gnodeB['pos']

        for name in root.findall(".//compound-module/submodules/submodule[@name='"+current_name+"']/parameters/property/property-key/literal"):
            name.set('text', '"p='+str(current_pos)+';is=s"')
            name.set('value', 'p='+str(current_pos)+';is=s')

tree.write(filename_xml)