//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
/* -*- mode:c++ -*- ********************************************************
 * author:      Jerome Rousselot <jerome.rousselot@csem.ch>
 *
 * copyright:   (C) 2008 Centre Suisse d'Electronique et Microtechnique (CSEM) SA
 * 				Systems Engineering
 *              Real-Time Software and Networking
 *              Jaquet-Droz 1, CH-2002 Neuchatel, Switzerland.
 *
 * description: this class holds constants specified in IEEE 802.15.4A UWB-IR Phy
 * acknowledgment: this work was supported (in part) by the National Competence
 * 			    Center in Research on Mobile Information and Communication Systems
 * 				NCCR-MICS, a center supported by the Swiss National Science
 * 				Foundation under grant number 5005-67322.
 ***************************************************************************/

#ifndef __INET_IEEE802154UWBIRTRANSMITTER_H
#define __INET_IEEE802154UWBIRTRANSMITTER_H

#include <vector>

#include "inet/common/math/Functions.h"
#include "inet/physicallayer/wireless/common/base/packetlevel/TransmitterBase.h"
#include "inet/physicallayer/wireless/ieee802154/bitlevel/Ieee802154UwbIrMode.h"

namespace inet {

namespace physicallayer {

using namespace inet::math;

/**
 * This generates pulse-level representation of an IEEE 802.15.4A UWB PHY frame
 * using the mandatory mode (high PRF).
 */
// This class was created by porting some C++ code from the IEEE802154A class in MiXiM.
class INET_API Ieee802154UwbIrTransmitter : public TransmitterBase
{
  protected:
    Ieee802154UwbIrMode cfg;

  protected:
    virtual void initialize(int stage) override;

    simtime_t getFrameDuration(int psduLength) const;
    simtime_t getMaxFrameDuration() const;
    simtime_t getPhyMaxFrameDuration() const;
    simtime_t getThdr() const;

    virtual void generateSyncPreamble(std::map<simsec, WpHz>& data, simtime_t& time, const simtime_t startTime) const;
    virtual void generateSFD(std::map<simsec, WpHz>& data, simtime_t& time, const simtime_t startTime) const;
    virtual void generatePhyHeader(std::map<simsec, WpHz>& data, simtime_t& time, const simtime_t startTime) const;
    virtual void generateBurst(std::map<simsec, WpHz>& data, simtime_t& time, const simtime_t startTime, const simtime_t burstStart, short polarity) const;
    virtual void generatePulse(std::map<simsec, WpHz>& data, simtime_t& time, const simtime_t startTime, short polarity, double peak, const simtime_t chip) const;

    virtual Ptr<const IFunction<WpHz, Domain<simsec, Hz>>> generateIEEE802154AUWBSignal(const simtime_t startTime, std::vector<bool> *bits) const;

  public:
    Ieee802154UwbIrTransmitter();

    virtual const ITransmission *createTransmission(const IRadio *transmitter, const Packet *packet, const simtime_t startTime) const override;

    virtual std::ostream& printToStream(std::ostream& stream, int level, int evFlags = 0) const override;
};

} // namespace physicallayer

} // namespace inet

#endif

