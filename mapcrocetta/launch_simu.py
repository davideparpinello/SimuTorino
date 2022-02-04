import os, subprocess

print("\nCalculating nearest edge to calibrators..")
os.system("python3 scripts/get_edges.py")

print("\nGenerating calibrator route sources..")
os.system("python3 scripts/generate_cal_sources.py")

print("\nGenerating random routes starting from each calibrator..")
os.system("python3 scripts/generate_cal_routes.py")

print("\nGenerating calibrator additional file to be opened with Sumo..")
os.system("python3 scripts/generate_calibrators_file.py")

print("\nDownloading gNodes opendata through Selenium script..")
os.system("python3 scripts/selenium_autologin.py")

print("\nGenerating gnodeB positions for Omnet simulation..")
os.system("python3 scripts/generate_pos_gnodes.py")

print("\nConverting .ned config file in .ned.xml to be manipulated..")
os.system("opp_nedtool c utils/Crocetta.ned -o utils/Crocetta.ned.xml") 

print("\nModifying ned.xml network file..")
os.system("python3 scripts/changeNEDfile.py")

print("\nReconverting .ned.xml in .ned..")
os.system("opp_nedtool c utils/Crocetta.ned.xml -o utils/Crocetta.ned")

print("\nExecuting veins_launchd script..")
subprocess.Popen(["../../veins/bin/veins_launchd", "-vv"], shell=True)

print("\nExecuting TraCI script that controls Sumo..")
os.system("python3 scripts/traci_ex.py")

#add launch omnet simulation (muoviti alessio, una settimana che ci sei dietro)