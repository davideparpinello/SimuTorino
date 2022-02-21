#!/bin/bash

cd /home/vagrant/simu5g
source setenv -f
cd ../simuTorino/utils
simu5g omnetpp.ini -u Qtenv -n ..:../../veins/subprojects/veins_inet/src/veins_inet:../../veins/subprojects/veins_inet/examples/veins_inet:../../veins/examples/veins:../../veins/src/veins --image-path=../../simu5g/images:../../veins/subprojects/veins_inet/images:../../inet4.3/images:../../veins/images -l ../../veins/subprojects/veins_inet/out/clang-release/src/veins_inet

python3 kill_veins.py
