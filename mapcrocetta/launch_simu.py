import os
print("Calculating nearest edge to calibrators")
os.system("python3 scripts/get_edges.py")
print("Generating calibrator route sources")
os.system("python3 scripts/generate_cal_sources.py")
print("Generating random routes starting from each calibrator")
os.system("python3 scripts/generate_cal_routes.py")
print("Generating calibrator additional file to be opened with sumo")
os.system("python3 scripts/generate_calibrators_file.py")
print("Executing TraCI script")
os.system("python3 scripts/traci_ex.py")

#su un nuovo terminale
#add generate_pos_gnodes.py
#add changeNEDfile.py
#add launch omnet simulation (muoviti alessio, una settimana che ci sei dietro)