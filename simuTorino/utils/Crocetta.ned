// 
//                  Simu5G
//
// Authors: Giovanni Nardini, Giovanni Stea, Antonio Virdis (University of Pisa)
// 
// This file is part of a software released under the license included in file
// "license.pdf". Please read LICENSE and README files before using it.
// The above files and the present reference are part of the software itself, 
// and cannot be removed from it.
//
package utils;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.inet.AdhocHost;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.node.ethernet.Eth10G;

import simu5g.world.radio.LteChannelControl;
import simu5g.common.carrierAggregation.CarrierAggregation;
import simu5g.nodes.Upf;
import simu5g.common.binder.Binder;
import simu5g.nodes.NR.gNodeB;
import simu5g.nodes.cars.Car;

//import simu5g.nodes.PgwStandard;
import simu5g.nodes.eNodeB;

import org.car2x.veins.subprojects.veins_inet.VeinsInetManager;

//#if INET_VERSION < 0x0403
import inet.physicallayer*.ieee80211.packetlevel.Ieee80211DimensionalRadioMedium;
//#else
import inet.physicallayer*.wireless.ieee80211.packetlevel.Ieee80211DimensionalRadioMedium;
//#endif
import org.car2x.veins.subprojects.veins_inet.VeinsInetCar;
import org.car2x.veins.subprojects.veins_inet.VeinsInetManager;
//#if INET_VERSION < 0x0403
import inet.visualizer*.integrated.IntegratedVisualizer;
//#else
import inet.visualizer*.common.IntegratedVisualizer;
//#endif
//import inet.environment.common.PhysicalEnvironment;
import org.car2x.veins.visualizer.roads.RoadsCanvasVisualizer;
import org.car2x.veins.visualizer.roads.RoadsOsgVisualizer;

network Crocetta
{
    parameters:
        bool useOsg = default(false);
        double playgroundSizeX @unit(m); // x size of the area the nodes are in (in meters)
        double playgroundSizeY @unit(m); // y size of the area the nodes are in (in meters)
        double playgroundSizeZ @unit(m); // z size of the area the nodes are in (in meters)
        @display("bgb=2116.82,2985.67");

    submodules:
//        visualizer: IntegratedVisualizer {
//            @display("p=0,0");
//        }
        //physicalEnvironment: PhysicalEnvironment {
          //  @display("p=192,224");
        //}
        roadsCanvasVisualizer: RoadsCanvasVisualizer {
            @display("p=0,0");
        }
        roadsOsgVisualizer: RoadsOsgVisualizer if useOsg {
            @display("p=0,0");
        }

        routingRecorder: RoutingTableRecorder {
            @display("p=0,0;is=vs");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=0,0");
            config = xmldoc("demo.xml");
        }

        //# Veins manager module
        veinsManager: VeinsInetManager {
            @display("p=0,0;is=vs");
        }

        //# LTE modules
        channelControl: LteChannelControl {
            @display("p=0,0;is=vs");
        }
        binder: Binder {
            @display("p=0,0;is=vs");
        }
        carrierAggregation: CarrierAggregation {
            @display("p=0,0;is=vs");
        }
        server: StandardHost {
            @display("p=1086.168,100.2;is=vs;i=device/server");
        }
        router: Router {
            @display("p=561,135;i=device/smallrouter;is=vs");
        }
        upf: Upf {
            @display("p=1400,1900;is=s");
        }
        gNodeB1: gNodeB {
            @display("p=1417.8899251577677,1219.7765837452189;is=s"); //5G
        }
        gNodeB2: gNodeB {
            @display("p=1709.4876840490033,1092.596233805716;is=s");
        }
        gNodeB3: gNodeB {
            @display("p=1875.8854095420684,1688.2205557525904;is=s");
        }
        gNodeB4: gNodeB {
            @display("p=1408.559107588313,2176.3311311426387;is=s");
        }
        gNodeB5: gNodeB {
            @display("p=926.1877084053122,2380.019163072184;is=s");
        }
        gNodeB6: gNodeB {
            @display("p=819.0341264724266,2284.139697887078;is=s");
        }
        gNodeB7: gNodeB {
            @display("p=515.195682732563,1766.4994010860846;is=s");
        }
        gNodeB8: gNodeB {
            @display("p=708.1747828541556,1763.356134731397;is=s"); //5G
        }
        gNodeB9: gNodeB {
            @display("p=979.3204984455951,1731.85335039448;is=s");
        }
        gNodeB10: gNodeB {
            @display("p=1194.33863408037,1641.1315679690615;is=s");
        }
        gNodeB11: gNodeB {
            @display("p=1066.195015572186,1517.2520302842186;is=s");
        }
        gNodeB12: gNodeB {
            @display("p=1020.7213499112986,1474.7532956740633;is=s");
        }
        gNodeB13: gNodeB {
            @display("p=876.0248205079115,1573.878312112838;is=s");
        }
        gNodeB14: gNodeB {
            @display("p=600.9538728193147,1588.8324306133018;is=s");
        }
        gNodeB15: gNodeB {
            @display("p=817.5133103507687,1368.4953517095;is=s");
        }
        gNodeB16: gNodeB {
            @display("p=988.2245955443941,1247.6115022628383;is=s");
        }
        gNodeB17: gNodeB {
            @display("p=866.0843144871178,755.656256107688;is=s");
        }

    connections allowunconnected:
        server.pppg++ <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> upf.filterGate;
        upf.pppg++ <--> Eth10G <--> gNodeB1.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB2.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB3.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB4.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB5.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB6.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB7.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB8.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB9.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB10.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB11.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB12.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB13.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB14.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB15.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB16.ppp;
        upf.pppg++ <--> Eth10G <--> gNodeB17.ppp;

        //# X2 connections
        gNodeB1.x2++ <--> Eth10G <--> gNodeB2.x2++;
        gNodeB2.x2++ <--> Eth10G <--> gNodeB3.x2++;
        gNodeB3.x2++ <--> Eth10G <--> gNodeB4.x2++;
        gNodeB4.x2++ <--> Eth10G <--> gNodeB5.x2++;
        gNodeB5.x2++ <--> Eth10G <--> gNodeB6.x2++;
        gNodeB6.x2++ <--> Eth10G <--> gNodeB7.x2++;
        gNodeB7.x2++ <--> Eth10G <--> gNodeB8.x2++;
        gNodeB8.x2++ <--> Eth10G <--> gNodeB9.x2++;
        gNodeB9.x2++ <--> Eth10G <--> gNodeB10.x2++;
        gNodeB10.x2++ <--> Eth10G <--> gNodeB11.x2++;
        gNodeB11.x2++ <--> Eth10G <--> gNodeB12.x2++;
        gNodeB12.x2++ <--> Eth10G <--> gNodeB13.x2++;
        gNodeB13.x2++ <--> Eth10G <--> gNodeB14.x2++;
        gNodeB14.x2++ <--> Eth10G <--> gNodeB15.x2++;
        gNodeB15.x2++ <--> Eth10G <--> gNodeB16.x2++;
        gNodeB16.x2++ <--> Eth10G <--> gNodeB17.x2++;
        gNodeB17.x2++ <--> Eth10G <--> gNodeB1.x2++;
}
