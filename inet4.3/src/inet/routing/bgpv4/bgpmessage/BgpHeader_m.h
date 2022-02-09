//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/bgpv4/bgpmessage/BgpHeader.msg.
//

#ifndef __INET__BGP_BGPHEADER_M_H
#define __INET__BGP_BGPHEADER_M_H

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
namespace bgp {

class BgpAsPathSegment;
class BgpHeader;
class BgpKeepAliveMessage;
class BgpOptionalParameterBase;
class BgpOptionalParameterRaw;
class BgpOpenMessage;
class BgpUpdatePathAttributes;
class BgpUpdatePathAttributesOrigin;
class BgpUpdatePathAttributesAsPath;
class BgpUpdatePathAttributesNextHop;
class BgpUpdatePathAttributesMultiExitDisc;
class BgpUpdatePathAttributesLocalPref;
class BgpUpdatePathAttributesAtomicAggregate;
class BgpUpdatePathAttributesAggregator;
struct BgpUpdateWithdrawnRoutes;
struct BgpUpdateNlri;
class BgpUpdateMessage;
} // namespace bgp
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/routing/bgpv4/BgpCommon_m.h" // import inet.routing.bgpv4.BgpCommon


namespace inet {
namespace bgp {

// cplusplus {{
const B BGP_HEADER_OCTETS = B(19);
const B BGP_OPEN_OCTETS = B(10);
const B BGP_EMPTY_UPDATE_OCTETS = B(4); // UnfeasibleRoutesLength (2) + TotalPathAttributeLength (2)
// }}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:38</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 AS_PATH path attribute (RFC 4271 Section 4.3)
 * //
 * class BgpAsPathSegment extends cObject
 * {
 *     BgpPathSegmentType type;
 *     uint8_t length;
 *     uint16_t asValue[];
 * }
 * </pre>
 */
class INET_API BgpAsPathSegment : public ::omnetpp::cObject
{
  protected:
    inet::bgp::BgpPathSegmentType type = static_cast<inet::bgp::BgpPathSegmentType>(-1);
    uint8_t length = 0;
    uint16_t *asValue = nullptr;
    size_t asValue_arraysize = 0;

  private:
    void copy(const BgpAsPathSegment& other);

  protected:
    bool operator==(const BgpAsPathSegment&) = delete;

  public:
    BgpAsPathSegment();
    BgpAsPathSegment(const BgpAsPathSegment& other);
    virtual ~BgpAsPathSegment();
    BgpAsPathSegment& operator=(const BgpAsPathSegment& other);
    virtual BgpAsPathSegment *dup() const override {return new BgpAsPathSegment(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::bgp::BgpPathSegmentType getType() const;
    virtual void setType(inet::bgp::BgpPathSegmentType type);
    virtual uint8_t getLength() const;
    virtual void setLength(uint8_t length);
    virtual void setAsValueArraySize(size_t size);
    virtual size_t getAsValueArraySize() const;
    virtual uint16_t getAsValue(size_t k) const;
    virtual void setAsValue(size_t k, uint16_t asValue);
    virtual void insertAsValue(uint16_t asValue);
    virtual void insertAsValue(size_t k, uint16_t asValue);
    virtual void eraseAsValue(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpAsPathSegment& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpAsPathSegment& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:49</tt> by nedtool.
 * <pre>
 * //
 * // BGPv4 message types
 * //
 * enum BgpType
 * {
 *     BGP_OPEN = 1;
 *     BGP_UPDATE = 2;
 *     BGP_NOTIFICATION = 3;
 *     BGP_KEEPALIVE = 4;
 * }
 * </pre>
 */
enum BgpType {
    BGP_OPEN = 1,
    BGP_UPDATE = 2,
    BGP_NOTIFICATION = 3,
    BGP_KEEPALIVE = 4
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpType& e) { int n; b->unpack(n); e = static_cast<BgpType>(n); }

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:65</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 message header.
 * //
 * // Header fields modeled:
 * //   - Marker: 16 octets (authentication)
 * //   - Length: 2 octets  (total size of the message)
 * //   - Type: 1 octet
 * //
 * class BgpHeader extends FieldsChunk
 * {
 *     chunkLength = BGP_HEADER_OCTETS;
 *     uint8_t marker[16] = 0xFF;
 *     uint16_t totalLength = B(BGP_HEADER_OCTETS).get();
 *     BgpType type = static_cast<BgpType>(-1);
 * }
 * </pre>
 */
class INET_API BgpHeader : public ::inet::FieldsChunk
{
  protected:
    uint8_t marker[16];
    uint16_t totalLength = B(BGP_HEADER_OCTETS).get();
    inet::bgp::BgpType type = static_cast<BgpType>(-1);

  private:
    void copy(const BgpHeader& other);

  protected:
    bool operator==(const BgpHeader&) = delete;

  public:
    BgpHeader();
    BgpHeader(const BgpHeader& other);
    virtual ~BgpHeader();
    BgpHeader& operator=(const BgpHeader& other);
    virtual BgpHeader *dup() const override {return new BgpHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual size_t getMarkerArraySize() const;
    virtual uint8_t getMarker(size_t k) const;
    virtual void setMarker(size_t k, uint8_t marker);
    virtual uint16_t getTotalLength() const;
    virtual void setTotalLength(uint16_t totalLength);
    virtual inet::bgp::BgpType getType() const;
    virtual void setType(inet::bgp::BgpType type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:79</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 KEEPALIVE message.
 * //
 * // KEEPALIVE messages are exchanged as often as necessary between systems
 * // to avoid exceeding the BGP Hold Timer (constant defined in BgpOpen).
 * //
 * class BgpKeepAliveMessage extends BgpHeader
 * {
 *     type = BGP_KEEPALIVE;
 * }
 * </pre>
 */
class INET_API BgpKeepAliveMessage : public ::inet::bgp::BgpHeader
{
  protected:

  private:
    void copy(const BgpKeepAliveMessage& other);

  protected:
    bool operator==(const BgpKeepAliveMessage&) = delete;

  public:
    BgpKeepAliveMessage();
    BgpKeepAliveMessage(const BgpKeepAliveMessage& other);
    virtual ~BgpKeepAliveMessage();
    BgpKeepAliveMessage& operator=(const BgpKeepAliveMessage& other);
    virtual BgpKeepAliveMessage *dup() const override {return new BgpKeepAliveMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpKeepAliveMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpKeepAliveMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:84</tt> by nedtool.
 * <pre>
 * class BgpOptionalParameterBase
 * {
 *     \@packetData;
 *     short parameterType;
 *     unsigned short parameterValueLength;
 * }
 * 
 * //TODO add accepted BgpOptionalParameter variants
 * </pre>
 */
class INET_API BgpOptionalParameterBase
{
  protected:
    short parameterType = 0;
    unsigned short parameterValueLength = 0;

  private:
    void copy(const BgpOptionalParameterBase& other);

  protected:
    bool operator==(const BgpOptionalParameterBase&) = delete;

  public:
    BgpOptionalParameterBase();
    BgpOptionalParameterBase(const BgpOptionalParameterBase& other);
    virtual ~BgpOptionalParameterBase();
    BgpOptionalParameterBase& operator=(const BgpOptionalParameterBase& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual short getParameterType() const;
    virtual void setParameterType(short parameterType);
    virtual unsigned short getParameterValueLength() const;
    virtual void setParameterValueLength(unsigned short parameterValueLength);
};

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:93</tt> by nedtool.
 * <pre>
 * class BgpOptionalParameterRaw extends BgpOptionalParameterBase
 * {
 *     char value[];
 * }
 * </pre>
 */
class INET_API BgpOptionalParameterRaw : public ::inet::bgp::BgpOptionalParameterBase
{
  protected:
    char *value = nullptr;
    size_t value_arraysize = 0;

  private:
    void copy(const BgpOptionalParameterRaw& other);

  protected:
    bool operator==(const BgpOptionalParameterRaw&) = delete;

  public:
    BgpOptionalParameterRaw();
    BgpOptionalParameterRaw(const BgpOptionalParameterRaw& other);
    virtual ~BgpOptionalParameterRaw();
    BgpOptionalParameterRaw& operator=(const BgpOptionalParameterRaw& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual void setValueArraySize(size_t size);
    virtual size_t getValueArraySize() const;
    virtual char getValue(size_t k) const;
    virtual void setValue(size_t k, char value);
    virtual void insertValue(char value);
    virtual void insertValue(size_t k, char value);
    virtual void eraseValue(size_t k);
};

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:101</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 OPEN message.
 * //
 * class BgpOpenMessage extends BgpHeader
 * {
 *     type = BGP_OPEN;
 *     chunkLength = BGP_HEADER_OCTETS + BGP_OPEN_OCTETS;
 *     totalLength = B(BGP_HEADER_OCTETS + BGP_OPEN_OCTETS).get();
 * 
 *     uint8_t version = 4;    // BGP Version, 1 octet
 *     uint16_t myAS;    // My Autonomous system, 2 octets
 *     simtime_t holdTime;    // Hold Time in seconds, 2 octets
 *     Ipv4Address BGPIdentifier;    // 4 octets
 *     unsigned short optionalParametersLength;    // 1 octet, total length (in bytes) of optionalParameters[] (if = 0, no optional parameters)
 *     BgpOptionalParameterBase *optionalParameter[] \@owned;
 * }
 * </pre>
 */
class INET_API BgpOpenMessage : public ::inet::bgp::BgpHeader
{
  protected:
    uint8_t version = 4;
    uint16_t myAS = 0;
    omnetpp::simtime_t holdTime = SIMTIME_ZERO;
    Ipv4Address BGPIdentifier;
    unsigned short optionalParametersLength = 0;
    BgpOptionalParameterBase * *optionalParameter = nullptr;
    size_t optionalParameter_arraysize = 0;

  private:
    void copy(const BgpOpenMessage& other);

  protected:
    bool operator==(const BgpOpenMessage&) = delete;

  public:
    BgpOpenMessage();
    BgpOpenMessage(const BgpOpenMessage& other);
    virtual ~BgpOpenMessage();
    BgpOpenMessage& operator=(const BgpOpenMessage& other);
    virtual BgpOpenMessage *dup() const override {return new BgpOpenMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getVersion() const;
    virtual void setVersion(uint8_t version);
    virtual uint16_t getMyAS() const;
    virtual void setMyAS(uint16_t myAS);
    virtual omnetpp::simtime_t getHoldTime() const;
    virtual void setHoldTime(omnetpp::simtime_t holdTime);
    virtual const Ipv4Address& getBGPIdentifier() const;
    virtual Ipv4Address& getBGPIdentifierForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<BgpOpenMessage*>(this)->getBGPIdentifier());}
    virtual void setBGPIdentifier(const Ipv4Address& BGPIdentifier);
    virtual unsigned short getOptionalParametersLength() const;
    virtual void setOptionalParametersLength(unsigned short optionalParametersLength);
    virtual void setOptionalParameterArraySize(size_t size);
    virtual size_t getOptionalParameterArraySize() const;
    virtual const BgpOptionalParameterBase * getOptionalParameter(size_t k) const;
    virtual BgpOptionalParameterBase * getOptionalParameterForUpdate(size_t k) { handleChange();return const_cast<BgpOptionalParameterBase *>(const_cast<BgpOpenMessage*>(this)->getOptionalParameter(k));}
    virtual BgpOptionalParameterBase * dropOptionalParameter(size_t k);
    virtual void setOptionalParameter(size_t k, BgpOptionalParameterBase * optionalParameter);
    virtual void insertOptionalParameter(BgpOptionalParameterBase * optionalParameter);
    virtual void insertOptionalParameter(size_t k, BgpOptionalParameterBase * optionalParameter);
    virtual void eraseOptionalParameter(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpOpenMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpOpenMessage& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:115</tt> by nedtool.
 * <pre>
 * enum BgpUpdateAttributeTypeCode
 * {
 *     ORIGIN = 1;
 *     AS_PATH = 2;
 *     NEXT_HOP = 3;
 *     MULTI_EXIT_DISC = 4;
 *     LOCAL_PREF = 5;
 *     ATOMIC_AGGREGATE = 6;
 *     AGGREGATOR = 7;
 * }
 * </pre>
 */
enum BgpUpdateAttributeTypeCode {
    ORIGIN = 1,
    AS_PATH = 2,
    NEXT_HOP = 3,
    MULTI_EXIT_DISC = 4,
    LOCAL_PREF = 5,
    ATOMIC_AGGREGATE = 6,
    AGGREGATOR = 7
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdateAttributeTypeCode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdateAttributeTypeCode& e) { int n; b->unpack(n); e = static_cast<BgpUpdateAttributeTypeCode>(n); }

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:126</tt> by nedtool.
 * <pre>
 * class BgpUpdatePathAttributes extends cObject
 * {
 *     bool optionalBit = false;    // 1 bit, Optional bit. It defines whether the attribute is optional (if set to 1) or well-known (if set to 0).
 *     bool transitiveBit = false;    // 1 bit, Transitive bit. It defines whether an optional attribute is transitive (if set to 1) or non-transitive (if set to 0). Transitive bit MUST be set to 1 for well-known attributes
 *     bool partialBit = false;    // 1 bit, Partial bit. It defines whether the information contained in the optional transitive attribute is partial (if set to 1) or complete (if set to 0).  For well-known attributes and for optional non-transitive attributes, the Partial bit MUST be set to 0.
 *     bool extendedLengthBit = false;    // 1 bit, Extended Length bit. It defines whether the Attribute Length is one octet (if set to 0) or two octets (if set to 1).
 *     unsigned short reserved = 0;    // 4 bit
 *     BgpUpdateAttributeTypeCode typeCode;    // 1 octet
 *     unsigned short length; // 2 octets or just 1 depending on the value of flags.extendedLengthBit
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributes : public ::omnetpp::cObject
{
  protected:
    bool optionalBit = false;
    bool transitiveBit = false;
    bool partialBit = false;
    bool extendedLengthBit = false;
    unsigned short reserved = 0;
    inet::bgp::BgpUpdateAttributeTypeCode typeCode = static_cast<inet::bgp::BgpUpdateAttributeTypeCode>(-1);
    unsigned short length = 0;

  private:
    void copy(const BgpUpdatePathAttributes& other);

  protected:
    bool operator==(const BgpUpdatePathAttributes&) = delete;

  public:
    BgpUpdatePathAttributes();
    BgpUpdatePathAttributes(const BgpUpdatePathAttributes& other);
    virtual ~BgpUpdatePathAttributes();
    BgpUpdatePathAttributes& operator=(const BgpUpdatePathAttributes& other);
    virtual BgpUpdatePathAttributes *dup() const override {return new BgpUpdatePathAttributes(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getOptionalBit() const;
    virtual void setOptionalBit(bool optionalBit);
    virtual bool getTransitiveBit() const;
    virtual void setTransitiveBit(bool transitiveBit);
    virtual bool getPartialBit() const;
    virtual void setPartialBit(bool partialBit);
    virtual bool getExtendedLengthBit() const;
    virtual void setExtendedLengthBit(bool extendedLengthBit);
    virtual unsigned short getReserved() const;
    virtual void setReserved(unsigned short reserved);
    virtual inet::bgp::BgpUpdateAttributeTypeCode getTypeCode() const;
    virtual void setTypeCode(inet::bgp::BgpUpdateAttributeTypeCode typeCode);
    virtual unsigned short getLength() const;
    virtual void setLength(unsigned short length);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributes& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributes& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:138</tt> by nedtool.
 * <pre>
 * // ORIGIN (RFC4271 Section 4.3, Type code 1):
 * class BgpUpdatePathAttributesOrigin extends BgpUpdatePathAttributes
 * {
 *     typeCode = ORIGIN;
 *     optionalBit = false;
 *     transitiveBit = true;
 *     length = 1;
 *     BgpSessionType value;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesOrigin : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    inet::bgp::BgpSessionType value = static_cast<inet::bgp::BgpSessionType>(-1);

  private:
    void copy(const BgpUpdatePathAttributesOrigin& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesOrigin&) = delete;

  public:
    BgpUpdatePathAttributesOrigin();
    BgpUpdatePathAttributesOrigin(const BgpUpdatePathAttributesOrigin& other);
    virtual ~BgpUpdatePathAttributesOrigin();
    BgpUpdatePathAttributesOrigin& operator=(const BgpUpdatePathAttributesOrigin& other);
    virtual BgpUpdatePathAttributesOrigin *dup() const override {return new BgpUpdatePathAttributesOrigin(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::bgp::BgpSessionType getValue() const;
    virtual void setValue(inet::bgp::BgpSessionType value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesOrigin& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesOrigin& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:148</tt> by nedtool.
 * <pre>
 * // AS_PATH (RFC4271 Section 4.3, Type code 2):
 * class BgpUpdatePathAttributesAsPath extends BgpUpdatePathAttributes
 * {
 *     typeCode = AS_PATH;
 *     optionalBit = false;
 *     transitiveBit = true;
 *     length = 0;
 *     BgpAsPathSegment value[];
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesAsPath : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    BgpAsPathSegment *value = nullptr;
    size_t value_arraysize = 0;

  private:
    void copy(const BgpUpdatePathAttributesAsPath& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesAsPath&) = delete;

  public:
    BgpUpdatePathAttributesAsPath();
    BgpUpdatePathAttributesAsPath(const BgpUpdatePathAttributesAsPath& other);
    virtual ~BgpUpdatePathAttributesAsPath();
    BgpUpdatePathAttributesAsPath& operator=(const BgpUpdatePathAttributesAsPath& other);
    virtual BgpUpdatePathAttributesAsPath *dup() const override {return new BgpUpdatePathAttributesAsPath(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setValueArraySize(size_t size);
    virtual size_t getValueArraySize() const;
    virtual const BgpAsPathSegment& getValue(size_t k) const;
    virtual BgpAsPathSegment& getValueForUpdate(size_t k) { return const_cast<BgpAsPathSegment&>(const_cast<BgpUpdatePathAttributesAsPath*>(this)->getValue(k));}
    virtual void setValue(size_t k, const BgpAsPathSegment& value);
    virtual void insertValue(const BgpAsPathSegment& value);
    virtual void insertValue(size_t k, const BgpAsPathSegment& value);
    virtual void eraseValue(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesAsPath& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesAsPath& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:158</tt> by nedtool.
 * <pre>
 * //NEXT_HOP (RFC4271 Section 4.3, Type code 3):
 * class BgpUpdatePathAttributesNextHop extends BgpUpdatePathAttributes
 * {
 *     typeCode = NEXT_HOP;
 *     optionalBit = false;
 *     transitiveBit = true;
 *     length = 4;
 *     Ipv4Address value;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesNextHop : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    Ipv4Address value;

  private:
    void copy(const BgpUpdatePathAttributesNextHop& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesNextHop&) = delete;

  public:
    BgpUpdatePathAttributesNextHop();
    BgpUpdatePathAttributesNextHop(const BgpUpdatePathAttributesNextHop& other);
    virtual ~BgpUpdatePathAttributesNextHop();
    BgpUpdatePathAttributesNextHop& operator=(const BgpUpdatePathAttributesNextHop& other);
    virtual BgpUpdatePathAttributesNextHop *dup() const override {return new BgpUpdatePathAttributesNextHop(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const Ipv4Address& getValue() const;
    virtual Ipv4Address& getValueForUpdate() { return const_cast<Ipv4Address&>(const_cast<BgpUpdatePathAttributesNextHop*>(this)->getValue());}
    virtual void setValue(const Ipv4Address& value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesNextHop& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesNextHop& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:168</tt> by nedtool.
 * <pre>
 * //MULTI_EXIT_DISC (RFC4271 Section 4.3, Type code 4):
 * class BgpUpdatePathAttributesMultiExitDisc extends BgpUpdatePathAttributes
 * {
 *     typeCode = MULTI_EXIT_DISC;
 *     optionalBit = true;
 *     transitiveBit = false;
 *     length = 4;
 *     uint32_t value;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesMultiExitDisc : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    uint32_t value = 0;

  private:
    void copy(const BgpUpdatePathAttributesMultiExitDisc& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesMultiExitDisc&) = delete;

  public:
    BgpUpdatePathAttributesMultiExitDisc();
    BgpUpdatePathAttributesMultiExitDisc(const BgpUpdatePathAttributesMultiExitDisc& other);
    virtual ~BgpUpdatePathAttributesMultiExitDisc();
    BgpUpdatePathAttributesMultiExitDisc& operator=(const BgpUpdatePathAttributesMultiExitDisc& other);
    virtual BgpUpdatePathAttributesMultiExitDisc *dup() const override {return new BgpUpdatePathAttributesMultiExitDisc(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getValue() const;
    virtual void setValue(uint32_t value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesMultiExitDisc& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesMultiExitDisc& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:178</tt> by nedtool.
 * <pre>
 * //LOCAL_PREF (RFC4271 Section 4.3, Type code 5):
 * class BgpUpdatePathAttributesLocalPref extends BgpUpdatePathAttributes
 * {
 *     typeCode = LOCAL_PREF;
 *     optionalBit = false;
 *     transitiveBit = true;
 *     length = 4;
 *     uint32_t value;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesLocalPref : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    uint32_t value = 0;

  private:
    void copy(const BgpUpdatePathAttributesLocalPref& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesLocalPref&) = delete;

  public:
    BgpUpdatePathAttributesLocalPref();
    BgpUpdatePathAttributesLocalPref(const BgpUpdatePathAttributesLocalPref& other);
    virtual ~BgpUpdatePathAttributesLocalPref();
    BgpUpdatePathAttributesLocalPref& operator=(const BgpUpdatePathAttributesLocalPref& other);
    virtual BgpUpdatePathAttributesLocalPref *dup() const override {return new BgpUpdatePathAttributesLocalPref(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getValue() const;
    virtual void setValue(uint32_t value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesLocalPref& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesLocalPref& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:188</tt> by nedtool.
 * <pre>
 * //ATOMIC_AGGREGATE (RFC4271 Section 4.3, Type code 6):
 * class BgpUpdatePathAttributesAtomicAggregate extends BgpUpdatePathAttributes
 * {
 *     typeCode = ATOMIC_AGGREGATE;
 *     optionalBit = false;
 *     transitiveBit = true;
 *     length = 0;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesAtomicAggregate : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:

  private:
    void copy(const BgpUpdatePathAttributesAtomicAggregate& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesAtomicAggregate&) = delete;

  public:
    BgpUpdatePathAttributesAtomicAggregate();
    BgpUpdatePathAttributesAtomicAggregate(const BgpUpdatePathAttributesAtomicAggregate& other);
    virtual ~BgpUpdatePathAttributesAtomicAggregate();
    BgpUpdatePathAttributesAtomicAggregate& operator=(const BgpUpdatePathAttributesAtomicAggregate& other);
    virtual BgpUpdatePathAttributesAtomicAggregate *dup() const override {return new BgpUpdatePathAttributesAtomicAggregate(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesAtomicAggregate& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesAtomicAggregate& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:196</tt> by nedtool.
 * <pre>
 * class BgpUpdatePathAttributesAggregator extends BgpUpdatePathAttributes
 * {
 *     typeCode = AGGREGATOR;
 *     optionalBit = true;
 *     transitiveBit = true;
 *     length = 6;
 *     uint16_t asNumber;
 *     Ipv4Address bgpSpeaker;
 * }
 * </pre>
 */
class INET_API BgpUpdatePathAttributesAggregator : public ::inet::bgp::BgpUpdatePathAttributes
{
  protected:
    uint16_t asNumber = 0;
    Ipv4Address bgpSpeaker;

  private:
    void copy(const BgpUpdatePathAttributesAggregator& other);

  protected:
    bool operator==(const BgpUpdatePathAttributesAggregator&) = delete;

  public:
    BgpUpdatePathAttributesAggregator();
    BgpUpdatePathAttributesAggregator(const BgpUpdatePathAttributesAggregator& other);
    virtual ~BgpUpdatePathAttributesAggregator();
    BgpUpdatePathAttributesAggregator& operator=(const BgpUpdatePathAttributesAggregator& other);
    virtual BgpUpdatePathAttributesAggregator *dup() const override {return new BgpUpdatePathAttributesAggregator(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getAsNumber() const;
    virtual void setAsNumber(uint16_t asNumber);
    virtual const Ipv4Address& getBgpSpeaker() const;
    virtual Ipv4Address& getBgpSpeakerForUpdate() { return const_cast<Ipv4Address&>(const_cast<BgpUpdatePathAttributesAggregator*>(this)->getBgpSpeaker());}
    virtual void setBgpSpeaker(const Ipv4Address& bgpSpeaker);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdatePathAttributesAggregator& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdatePathAttributesAggregator& obj) {obj.parsimUnpack(b);}

/**
 * Struct generated from inet/routing/bgpv4/bgpmessage/BgpHeader.msg:206 by nedtool.
 */
struct INET_API BgpUpdateWithdrawnRoutes
{
    BgpUpdateWithdrawnRoutes();
    unsigned char length = 0;
    Ipv4Address prefix;
};

// helpers for local use
void INET_API __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateWithdrawnRoutes& a);
void INET_API __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateWithdrawnRoutes& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdateWithdrawnRoutes& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdateWithdrawnRoutes& obj) { __doUnpacking(b, obj); }

/**
 * Struct generated from inet/routing/bgpv4/bgpmessage/BgpHeader.msg:212 by nedtool.
 */
struct INET_API BgpUpdateNlri
{
    BgpUpdateNlri();
    uint8_t length = 0;
    Ipv4Address prefix;
};

// helpers for local use
void INET_API __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateNlri& a);
void INET_API __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateNlri& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdateNlri& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdateNlri& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>inet/routing/bgpv4/bgpmessage/BgpHeader.msg:224</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 UPDATE message.
 * //
 * // see RFC 4271 Section 4.3
 * //
 * class BgpUpdateMessage extends BgpHeader
 * {
 *     type = BGP_UPDATE;
 *     chunkLength = BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS;
 *     totalLength = B(BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS).get();
 * 
 *     uint16_t withDrawnRoutesLength = 0;    // This 2-octets unsigned integer indicates the total length of
 *                                            // the Withdrawn Routes field in octets.  Its value allows the
 *                                            // length of the Network Layer Reachability Information field to
 *                                            // be determined, as specified below.
 *                                            //
 *                                            // A value of 0 indicates that no routes are being withdrawn from
 *                                            // service, and that the WITHDRAWN ROUTES field is not present in
 *                                            // this UPDATE message.
 * 
 *     BgpUpdateWithdrawnRoutes withdrawnRoutes[];
 *     uint16_t totalPathAttributeLength = 0;    // This 2-octets unsigned integer indicates the total length of
 *                                               // Path Attributes field in octets.  Its value allows the length
 *                                               // of the Network Layer Reachability field to be determined as
 *                                               // specified below.
 *                                               //
 *                                               // A value of 0 indicates that neither the Network Layer
 *                                               // Reachability Information field nor the Path Attribute field is
 *                                               // present in this UPDATE message.
 *     BgpUpdatePathAttributes *pathAttributes[] \@owned \@allowReplace;
 *     BgpUpdateNlri NLRI[];
 * }
 * </pre>
 */
class INET_API BgpUpdateMessage : public ::inet::bgp::BgpHeader
{
  protected:
    uint16_t withDrawnRoutesLength = 0;
    BgpUpdateWithdrawnRoutes *withdrawnRoutes = nullptr;
    size_t withdrawnRoutes_arraysize = 0;
    uint16_t totalPathAttributeLength = 0;
    BgpUpdatePathAttributes * *pathAttributes = nullptr;
    size_t pathAttributes_arraysize = 0;
    BgpUpdateNlri *NLRI = nullptr;
    size_t NLRI_arraysize = 0;

  private:
    void copy(const BgpUpdateMessage& other);

  protected:
    bool operator==(const BgpUpdateMessage&) = delete;

  public:
    BgpUpdateMessage();
    BgpUpdateMessage(const BgpUpdateMessage& other);
    virtual ~BgpUpdateMessage();
    BgpUpdateMessage& operator=(const BgpUpdateMessage& other);
    virtual BgpUpdateMessage *dup() const override {return new BgpUpdateMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getWithDrawnRoutesLength() const;
    virtual void setWithDrawnRoutesLength(uint16_t withDrawnRoutesLength);
    virtual void setWithdrawnRoutesArraySize(size_t size);
    virtual size_t getWithdrawnRoutesArraySize() const;
    virtual const BgpUpdateWithdrawnRoutes& getWithdrawnRoutes(size_t k) const;
    virtual BgpUpdateWithdrawnRoutes& getWithdrawnRoutesForUpdate(size_t k) { handleChange();return const_cast<BgpUpdateWithdrawnRoutes&>(const_cast<BgpUpdateMessage*>(this)->getWithdrawnRoutes(k));}
    virtual void setWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes);
    virtual void insertWithdrawnRoutes(const BgpUpdateWithdrawnRoutes& withdrawnRoutes);
    virtual void insertWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes);
    virtual void eraseWithdrawnRoutes(size_t k);
    virtual uint16_t getTotalPathAttributeLength() const;
    virtual void setTotalPathAttributeLength(uint16_t totalPathAttributeLength);
    virtual void setPathAttributesArraySize(size_t size);
    virtual size_t getPathAttributesArraySize() const;
    virtual const BgpUpdatePathAttributes * getPathAttributes(size_t k) const;
    virtual BgpUpdatePathAttributes * getPathAttributesForUpdate(size_t k) { handleChange();return const_cast<BgpUpdatePathAttributes *>(const_cast<BgpUpdateMessage*>(this)->getPathAttributes(k));}
    virtual BgpUpdatePathAttributes * dropPathAttributes(size_t k);
    virtual void setPathAttributes(size_t k, BgpUpdatePathAttributes * pathAttributes);
    virtual void insertPathAttributes(BgpUpdatePathAttributes * pathAttributes);
    virtual void insertPathAttributes(size_t k, BgpUpdatePathAttributes * pathAttributes);
    virtual void erasePathAttributes(size_t k);
    virtual void setNLRIArraySize(size_t size);
    virtual size_t getNLRIArraySize() const;
    virtual const BgpUpdateNlri& getNLRI(size_t k) const;
    virtual BgpUpdateNlri& getNLRIForUpdate(size_t k) { handleChange();return const_cast<BgpUpdateNlri&>(const_cast<BgpUpdateMessage*>(this)->getNLRI(k));}
    virtual void setNLRI(size_t k, const BgpUpdateNlri& NLRI);
    virtual void insertNLRI(const BgpUpdateNlri& NLRI);
    virtual void insertNLRI(size_t k, const BgpUpdateNlri& NLRI);
    virtual void eraseNLRI(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BgpUpdateMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BgpUpdateMessage& obj) {obj.parsimUnpack(b);}

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPHEADER_M_H

