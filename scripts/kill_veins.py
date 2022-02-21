import os

filepath="./utils/veins.pid"

with open(filepath, "r") as veins_id:
    id=veins_id.read()
    print("\nKilling Veins daemon process with id: "+id)
    os.system("kill "+str(id))