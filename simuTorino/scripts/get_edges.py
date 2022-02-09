import os, sys
import json
import xml.etree.ElementTree as ET

if 'SUMO_HOME' in os.environ:
    tools = os.path.join(os.environ['SUMO_HOME'], 'tools')
    sys.path.append(tools)
else:   
    sys.exit("please declare environment variable 'SUMO_HOME'")


import sumolib # type: ignore

net = sumolib.net.readNet('./utils/map.net.xml')

filename = './utils/calibrators_db.json'
with open(filename, "r+") as calibrators_db:
    data = json.load(calibrators_db)
    for calibrator in data['calibrators']:
        current_lat = calibrator['pos']['lat']
        current_lon = calibrator['pos']['lon']
        radius = 5
        x, y = net.convertLonLat2XY(current_lon, current_lat)
        edges = net.getNeighboringEdges(x, y, radius)

        # pick the closest edge
        if len(edges) > 0:
            distancesAndEdges = sorted([(dist, edge) for edge, dist in edges])
            dist, closestEdge = distancesAndEdges[0]
            root = ET.fromstring(str(closestEdge))
            current_edge_id = root.get('id')
            calibrator['edge'] = current_edge_id
    
    calibrators_db.truncate(0)
    calibrators_db.seek(0)
    json.dump(data, calibrators_db, ensure_ascii=False, indent=4)

