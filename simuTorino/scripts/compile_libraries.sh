#!/bin/bash

WORKDIR=$(pwd)
printf "Setting current working directory as $WORKDIR"

printf "\n\n--- Cleaning libraries... ---\n\n"

cd $WORKDIR/simu5g/
printf "Cleaning Simu5g...\n"
if [ ! -f "src/Makefile" ]; then
    echo "Simu5G already cleaned"
else
    make cleanall
    printf "Simu5G cleaned\n"
fi

cd $WORKDIR/veins/subprojects/veins_inet/
printf "\nCleaning veins_inet...\n"
if [ ! -f "src/Makefile" ]; then
    echo "veins_inet cleaned"
else
    make cleanall
    printf "veins_inet cleaned\n"
fi

cd $WORKDIR/veins/
printf "\nCleaning veins...\n"
if [ ! -f "src/Makefile" ]; then
    echo "veins cleaned"
else
    make cleanall
    printf "veins cleaned\n"
fi

cd $WORKDIR/inet4.3/
printf "\nCleaning inet4.3...\n"
if [ ! -f "src/Makefile" ]; then
    echo "inet4.3 cleaned"
else
    make cleanall
    printf "inet4.3 cleaned\n"
fi

printf "\n\n--- Compiling libraries... ---\n\n"

printf "\nCompiling inet4.3 ...\n"
cd $WORKDIR/inet4.3/
. setenv -f
make makefiles
make MODE=release -j4 all

printf "\nCompiling veins ...\n"
cd $WORKDIR/veins/
. setenv -f
./configure
make MODE=release -j4 all

printf "\nCompiling veins_inet ...\n"
cd $WORKDIR/veins/subprojects/veins_inet/
. setenv -f
INET_DIR="${WORKDIR}/inet4.3/"
./configure --with-inet=$INET_DIR
make MODE=release -j4 all

printf "\nCompiling simu5g ...\n"
cd $WORKDIR/simu5g/
. setenv -f
make makefiles
make MODE=release -j4 all