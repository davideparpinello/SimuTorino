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

#include "inet/mobility/base/MovingMobilityBase.h"

namespace inet {

MovingMobilityBase::MovingMobilityBase() :
    moveTimer(nullptr),
    updateInterval(0),
    stationary(false),
    lastVelocity(Coord::ZERO),
    lastUpdate(0),
    nextChange(-1),
    faceForward(false)
{
}

MovingMobilityBase::~MovingMobilityBase()
{
    cancelAndDelete(moveTimer);
}

void MovingMobilityBase::initialize(int stage)
{
    MobilityBase::initialize(stage);
    EV_TRACE << "initializing MovingMobilityBase stage " << stage << endl;
    if (stage == INITSTAGE_LOCAL) {
        moveTimer = new cMessage("move");
        updateInterval = par("updateInterval");
        faceForward = par("faceForward");
    }
}

void MovingMobilityBase::initializePosition()
{
    MobilityBase::initializePosition();
    lastUpdate = simTime();
    scheduleUpdate();
}

void MovingMobilityBase::moveAndUpdate()
{
    simtime_t now = simTime();
    if (nextChange == now || lastUpdate != now) {
        move();
        orient();
        lastUpdate = simTime();
        emitMobilityStateChangedSignal();
    }
}

void MovingMobilityBase::orient()
{
    if (faceForward) {
        // determine orientation based on direction
        if (lastVelocity != Coord::ZERO) {
            Coord direction = lastVelocity;
            direction.normalize();
            auto alpha = rad(atan2(direction.y, direction.x));
            auto beta = rad(-asin(direction.z));
            auto gamma = rad(0.0);
            lastOrientation = Quaternion(EulerAngles(alpha, beta, gamma));
        }
    }
}

void MovingMobilityBase::handleSelfMessage(cMessage *message)
{
    moveAndUpdate();
    scheduleUpdate();
}

void MovingMobilityBase::scheduleUpdate()
{
    cancelEvent(moveTimer);
    if (!stationary && updateInterval != 0) {
        // periodic update is needed
        simtime_t nextUpdate = simTime() + updateInterval;
        if (nextChange != -1 && nextChange < nextUpdate)
            // next change happens earlier than next update
            scheduleAt(nextChange, moveTimer);
        else
            // next update happens earlier than next change or there is no change at all
            scheduleAt(nextUpdate, moveTimer);
    }
    else if (nextChange != -1)
        // no periodic update is needed
        scheduleAt(nextChange, moveTimer);
}

const Coord& MovingMobilityBase::getCurrentPosition()
{
    moveAndUpdate();
    return lastPosition;
}

const Coord& MovingMobilityBase::getCurrentVelocity()
{
    moveAndUpdate();
    return lastVelocity;
}

const Quaternion& MovingMobilityBase::getCurrentAngularPosition()
{
    moveAndUpdate();
    return lastOrientation;
}

const Quaternion& MovingMobilityBase::getCurrentAngularVelocity()
{
    moveAndUpdate();
    return lastAngularVelocity;
}

} // namespace inet
