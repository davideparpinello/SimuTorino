import os, subprocess
print("Calculating nearest edge to calibrators")
os.system("python3 scripts/get_edges.py")
print("Generating calibrator route sources")
os.system("python3 scripts/generate_cal_sources.py")
print("Generating random routes starting from each calibrator")
os.system("python3 scripts/generate_cal_routes.py")
print("Generating calibrator additional file to be opened with sumo")
os.system("python3 scripts/generate_calibrators_file.py")
print("Generating gnodeB positions")
os.system("python3 scripts/generate_pos_gnodes.py")
print("Convert .ned in .ned.xml")
os.system("opp_nedtool c utils/prova5G.ned -o utils/prova5G.ned.xml") #NB ricorda di cambiare nome file
print("Modifying NED network file")
os.system("python3 scripts/changeNEDfile.py")
print("Reconvert .ned.xml in .ned")
os.system("opp_nedtool c utils/prova5G.ned.xml -o utils/prova5G.ned")
print("Executing veins_launchd script..")
subprocess.run(["../../veins/bin/veins_launchd", "-vv"])
print("Executing TraCI script")
os.system("python3 scripts/traci_ex.py")



#add launch omnet simulation (muoviti alessio, una settimana che ci sei dietro)