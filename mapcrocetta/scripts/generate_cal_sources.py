import json
import xml.etree.ElementTree as ET

file_prefix = 'calibratorssources'
file_ext = '.src.xml'
begin_value = 0
end_value = 10
value_value = 1


input_file = './utils/calibrators_db.json'

with open(input_file, "r") as calibrators_db:
    data = json.load(calibrators_db)
    i = 1
    for calibrator in data['calibrators']:
        current_output_file = './utils/cal_sources/' + file_prefix + str(i) + file_ext
        current_root = ET.Element('edgedata')

        current_interval_elem = ET.SubElement(current_root, 'interval')
        current_interval_elem.set("begin", str(begin_value))
        current_interval_elem.set("end", str(end_value))

        current_edge_elem = ET.SubElement(current_interval_elem, 'edge')
        current_edge_elem.set("id", calibrator['edge'])
        current_edge_elem.set("value", str(value_value))

        tree = ET.ElementTree(current_root)
        tree.write(current_output_file)
        i = i + 1

