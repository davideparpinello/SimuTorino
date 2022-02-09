#!/bin/bash

cd ../../simu5g
source setenv -f
cd ../simuTorino/utils
simu5g omnetpp.ini -u Qtenv -n ..:../../veins/subprojects/veins_inet/src/veins_inet:../../veins/subprojects/veins_inet/examples/veins_inet:../../veins/examples/veins:../../veins/src/veins --image-path=../../simu5g/images:../../veins/subprojects/veins_inet/images:../../inet4.3/images:../../veins/images

python3 kill_veins.py
