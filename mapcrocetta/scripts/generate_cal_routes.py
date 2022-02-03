import xml.etree.ElementTree as ET
import os

cal_num = 10
cal_routes_num = 100
rou_probability = 1/cal_routes_num

cal_sources_string = 'calibratorssources'
cal_routes_string = 'map.roucal'
route_dist_id_string = 'routedistcal'

output_file = './utils/cal.rou.xml'

sources_folder = './utils/cal_sources/'
routes_folder = './utils/cal_routes/'

for count in range(1, cal_num + 1):
    current_source_filename = sources_folder + cal_sources_string + str(count)
    current_routes_filename = routes_folder + cal_routes_string + str(count) + '.xml'
    os.system("python3 scripts/randomTrips.py -o ./utils/deafult.trips.xml -n ./utils/map.net.xml -r " + current_routes_filename + " -e " + str(cal_routes_num) + " -l --random --weights-prefix " + current_source_filename)

routes_files = os.listdir(routes_folder)
for file in routes_files:
    if file.endswith(".alt.xml"):
        os.remove(os.path.join(routes_folder, file))

output_file_root = ET.Element('routes')

for count in range(1, cal_num + 1):
    current_routes_filename = routes_folder + cal_routes_string + str(count) + '.xml'
    input_file_root = ET.parse(current_routes_filename).getroot()

    current_routedist_element = ET.SubElement(output_file_root, 'routeDistribution')
    current_routedist_element.set("id", route_dist_id_string + str(count))
    
    for route_tag in input_file_root.findall('vehicle/route'):
        route_tag.set("probability",str(rou_probability))
        current_routedist_element.append(route_tag)

tree = ET.ElementTree(output_file_root)
tree.write(output_file)
