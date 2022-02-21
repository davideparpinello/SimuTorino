#!/bin/bash

# COMMAND FOR GLX
# defaults write org.xquartz.X11 enable_iglx -bool true 

export DEBIAN_FRONTEND=noninteractive
export LIBGL_ALWAYS_INDIRECT=1

echo "export LIBGL_ALWAYS_INDIRECT=1" >> ~/.bashrc

echo "Installing base libraries.."

sudo apt-get update
sudo apt-get install -y x11-apps xterm build-essential clang lld gdb bison flex perl python3 qt5-default libqt5opengl5-dev libxml2-dev zlib1g-dev doxygen graphviz libwebkit2gtk-4.0-37 python3-pip openscenegraph-plugin-osgearth libosgearth-dev cmake python g++ libxerces-c-dev libfox-1.6-dev libgdal-dev libproj-dev libgl2ps-dev swig default-jdk xauth xvfb mesa-utils libgl1-mesa-glx

sudo apt-get autoremove -y

echo "Installing Google Chrome and Chromedriver for selenium"
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt-get install -y ./google-chrome-stable_current_amd64.deb 
wget https://chromedriver.storage.googleapis.com/98.0.4758.102/chromedriver_linux64.zip
unzip chromedriver_linux64.zip 
sudo mv chromedriver /usr/local/bin/

echo "Installing Python packages required by OMNeT++"

echo "export PATH=$PATH:/home/vagrant/.local/bin" >> ~/.bashrc
export PATH=$PATH:/home/vagrant/.local/bin
python3 -m pip install --upgrade pip
python3 -m pip install --user --upgrade numpy pandas matplotlib scipy seaborn posix_ipc pyproj selenium rtree requests urllib3 chardet PyVirtualDisplay

echo "Downloading and compiling OMNeT++ 6.0 pre11"

wget https://github.com/omnetpp/omnetpp/releases/download/omnetpp-6.0pre11/omnetpp-6.0pre11-src-linux.tgz

tar xvfz omnetpp-6.0pre11-src-linux.tgz
mv omnetpp-6.0pre11 omnetpp
cd omnetpp
source setenv -f

echo "export PATH=$PATH:$HOME/omnetpp/bin" >> ~/.bashrc
export PATH=$PATH:$HOME/omnetpp/bin

sed -i '1s/^/#include <limits>\n /' src/sim/chistogramstrategy.cc
sed -i '1s/^/#include <limits>\n /' src/sim/simtime.cc

./configure
make MODE=release -j4

echo "Downloading and compiling SUMO 1.8.0"

cd

wget https://netcologne.dl.sourceforge.net/project/sumo/sumo/version%201.8.0/sumo-src-1.8.0.tar.gz

tar xvfz sumo-src-1.8.0.tar.gz
mv sumo-1.8.0 sumo

cd sumo
export SUMO_HOME="$PWD"
mkdir build/cmake-build && cd build/cmake-build
cmake ../..
make -j4

sudo make install

export SUMO_HOME=/usr/local/share/sumo
echo "export SUMO_HOME=/usr/local/share/sumo" >> ~/.bashrc

python3 -m pip install --user --upgrade traci sumolib

echo "Downloading INET, Veins and Simu5g"
cd
wget https://github.com/inet-framework/inet/releases/download/v4.3.2/inet-4.3.2-src.tgz
tar xzvf inet-4.3.2-src.tgz

wget https://veins.car2x.org/download/veins-5.2.zip
unzip veins-5.2.zip
mv veins-veins-5.2 veins

wget https://github.com/Unipisa/Simu5G/archive/refs/tags/v1.2.0.tar.gz
tar xzvf v1.2.0.tar.gz
mv Simu5G-1.2.0 simu5g

chmod +x /vagrant/scripts/compile_libraries.sh
/vagrant/scripts/compile_libraries.sh 

printf "\n\n-----\tVAGRANT READY\t-----\n"
printf "Please login into the VM using \'vagrant ssh\'"