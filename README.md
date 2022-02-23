[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
<br />
<p align="center">
  <a href="https://github.com/davideparpinello/SimuTorino">
    <img src="https://cdn-icons-png.flaticon.com/512/4353/4353327.png" alt="Logo" width="210"> 
  </a>
  <h3 align="center">Simulating 5G-enabled vehicular networks in a Turin urban context</h3>

  <p align="center">
    University of Trento - prof. Fabrizio Granelli
    <br />
    <a href="https://github.com/davideparpinello/SimuTorino/blob/main/utils/Presentation_SimuTorino.pdf"><strong>Download presentation »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Bralli99">Brando Chiminelli</a>
    |
    <a href="https://github.com/AlessioDP123">Alessio Juan De Paoli</a>
    |
    <a href="https://github.com/davideparpinello">Davide Parpinello</a>
    |
    <a href="https://github.com/davidezordan25">Davide Zordan</a>
  </p>
</p>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about">About</a>
      <ul>
        <li><a href="#team">Team</a></li>
        <li><a href="#project">Project</a></li>
          <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
      </ul>
    </li>
    <li><a href="#getting-started">Getting Started</a></li>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li>
      <a href="#credits">Credits</a>
    </li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->

## About

### Team

The team is composed by Brando Chiminelli, Alessio Juan De Paoli, Davide Parpinello and Davide Zordan, four students of the courses Next Generation Networks and Softwarized and Virtualized Mobile Networks given by prof. Fabrizio Granelli.

### Project

The goal of the project is to simulate the traffic in an urban context and implement a 5G network that enables vehicular communications, using real data about the traffic flows and the position of the antennas.\
The district analyzed is "Crocetta" located in the city centre of Turin. This map fits well the project as it has 10 road traffic sensors and 17 base stations (BTS).

#### Built With

* [INET 4.3.2](https://inet.omnetpp.org/)
* [Veins 5.2](https://veins.car2x.org/)
* [Simu5g 1.2](http://simu5g.org/)
* [OMNeT++ 6.0 pre11](https://github.com/omnetpp/omnetpp/releases/tag/omnetpp-6.0pre11)
* [SUMO 1.8.0](https://www.eclipse.org/sumo/)

## Getting Started
### Prerequisites
In order to run the project you need to have installed:
* [Vagrant 2.2.19](https://www.vagrantup.com/)
* [VirtualBox 6.1.32](https://www.virtualbox.org/)
* X11 Client:
  * [XQuartz](https://www.xquartz.org/) for macOS users, please note that you have to check if glx is enabled (1 = enabled)
    ```sh
    defaults read org.xquartz.X11 enable_iglx
    ```
    otherwise enter the following command and restart the machine
    ```sh
    defaults write org.xquartz.X11 enable_iglx -bool true
    ```
  * [MobaXterm](https://mobaxterm.mobatek.net/) for Windows users

### Installation

1. Clone this repository 
2. Enter the repo directory
3. ```sh
   vagrant up
   ```
   This command creates and configures guest machines according to the Vagrantfile.
   The first time you launch it, you have to wait for the project to build, it could take about one hour.
   

## Usage

1. With the following command you log into the VM.
   ```sh
   vagrant ssh
   ```
2. To enter the mounted directory:
   ```sh
   cd /vagrant
   ```
3. To launch the project:
   ```sh
   python3 launch_simu.py
   ```

Now you can have fun playing with the project as two windows will appear, one with the SUMO interface and the other with OMNet.

## Credits

Thanks to:
* [5T Srl](https://www.5t.torino.it/) for providing open data about traffic flow in Turin
* [LTE Italy](https://lteitaly.it/) for providing open data about BTS 
* [Giovanni Nardini](http://www.iet.unipi.it/g.nardini/research.html) for Simu5g support
