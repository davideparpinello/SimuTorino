//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/flooding/FloodingHeader.msg.
//

#ifndef __INET_FLOODINGHEADER_M_H
#define __INET_FLOODINGHEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class FloodingHeader;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/networklayer/contract/NetworkHeaderBase_m.h" // import inet.networklayer.contract.NetworkHeaderBase

#include "inet/networklayer/common/L3Address_m.h" // import inet.networklayer.common.L3Address

#include "inet/networklayer/common/IpProtocolId_m.h" // import inet.networklayer.common.IpProtocolId

// cplusplus {{
#include "inet/common/ProtocolGroup.h"
// }}


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/flooding/FloodingHeader.msg:31</tt> by nedtool.
 * <pre>
 * class FloodingHeader extends NetworkHeaderBase
 * {
 *     L3Address srcAddr;
 *     L3Address destAddr;
 *     int ttl = 1;    // time to live field
 *     unsigned long seqNum = 0; // sequence number
 *     IpProtocolId protocolId;
 *     B payloadLengthField;
 * }
 * </pre>
 */
class INET_API FloodingHeader : public ::inet::NetworkHeaderBase
{
  protected:
    L3Address srcAddr;
    L3Address destAddr;
    int ttl = 1;
    unsigned long seqNum = 0;
    inet::IpProtocolId protocolId = static_cast<inet::IpProtocolId>(-1);
    B payloadLengthField = B(-1);

  private:
    void copy(const FloodingHeader& other);

  protected:
    bool operator==(const FloodingHeader&) = delete;

  public:
    FloodingHeader();
    FloodingHeader(const FloodingHeader& other);
    virtual ~FloodingHeader();
    FloodingHeader& operator=(const FloodingHeader& other);
    virtual FloodingHeader *dup() const override {return new FloodingHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const L3Address& getSrcAddr() const;
    virtual L3Address& getSrcAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<FloodingHeader*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const L3Address& srcAddr);
    virtual const L3Address& getDestAddr() const;
    virtual L3Address& getDestAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<FloodingHeader*>(this)->getDestAddr());}
    virtual void setDestAddr(const L3Address& destAddr);
    virtual int getTtl() const;
    virtual void setTtl(int ttl);
    virtual unsigned long getSeqNum() const;
    virtual void setSeqNum(unsigned long seqNum);
    virtual inet::IpProtocolId getProtocolId() const;
    virtual void setProtocolId(inet::IpProtocolId protocolId);
    virtual B getPayloadLengthField() const;
    virtual void setPayloadLengthField(B payloadLengthField);

  public:
    virtual L3Address getSourceAddress() const override { return L3Address(getSrcAddr()); }
    virtual void setSourceAddress(const L3Address& address) override { setSrcAddr(address); }
    virtual L3Address getDestinationAddress() const override { return L3Address(getDestAddr()); }
    virtual void setDestinationAddress(const L3Address& address) override { setDestAddr(address); }
    virtual const Protocol *getProtocol() const override { return ProtocolGroup::ipprotocol.findProtocol(getProtocolId()); }
    virtual void setProtocol(const Protocol *protocol) override { setProtocolId(static_cast<IpProtocolId>(ProtocolGroup::ipprotocol.getProtocolNumber(protocol))); }
    virtual bool isFragment() const override { return false; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FloodingHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FloodingHeader& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_FLOODINGHEADER_M_H

