//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ethernet/common/EthernetMacHeader.msg.
//

#ifndef __INET_ETHERNETMACHEADER_M_H
#define __INET_ETHERNETMACHEADER_M_H

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

class EthernetMacAddressFields;
class EthernetTypeOrLengthField;
class EthernetMacHeader;
class EthernetPadding;
class EthernetFcs;
class EthernetFragmentFcs;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/EtherType_m.h" // import inet.linklayer.common.EtherType

#include "inet/linklayer/common/FcsMode_m.h" // import inet.linklayer.common.FcsMode

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:41</tt> by nedtool.
 * <pre>
 * //
 * // This class represents the source and destination address fields of an IEEE
 * // 802.3 Ethernet MAC header as defined in the sections 3.2.3 Address fields,
 * // 3.2.4 Destination Address field, 3.2.5 Source Address field of the IEEE Std
 * // 802.3-2018, IEEE Standard for Ethernet.
 * //
 * //  0                   1                   2                   3                   4
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
 * // +-----------------------------------------------------------------------------------------------+
 * // |                                      Destination Address                                      |
 * // +-----------------------------------------------------------------------------------------------+
 * // |                                        Source Address                                         |
 * // +-------------------------------+---------------------------------------------------------------+
 * //
 * class EthernetMacAddressFields extends FieldsChunk
 * {
 *     chunkLength = B(12); // B(6) + B(6)
 *     // TODO rename to destinationAddress
 *     MacAddress dest; // The Destination Address field specifies the station(s) for which the MAC frame is intended. It may be an individual or multicast (including broadcast) address.
 *     // TODO rename to sourceAddress
 *     MacAddress src; // The Source Address field specifies the station sending the MAC frame.
 * }
 * </pre>
 */
class INET_API EthernetMacAddressFields : public ::inet::FieldsChunk
{
  protected:
    MacAddress dest;
    MacAddress src;

  private:
    void copy(const EthernetMacAddressFields& other);

  protected:
    bool operator==(const EthernetMacAddressFields&) = delete;

  public:
    EthernetMacAddressFields();
    EthernetMacAddressFields(const EthernetMacAddressFields& other);
    virtual ~EthernetMacAddressFields();
    EthernetMacAddressFields& operator=(const EthernetMacAddressFields& other);
    virtual EthernetMacAddressFields *dup() const override {return new EthernetMacAddressFields(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const MacAddress& getDest() const;
    virtual MacAddress& getDestForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<EthernetMacAddressFields*>(this)->getDest());}
    virtual void setDest(const MacAddress& dest);
    virtual const MacAddress& getSrc() const;
    virtual MacAddress& getSrcForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<EthernetMacAddressFields*>(this)->getSrc());}
    virtual void setSrc(const MacAddress& src);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetMacAddressFields& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetMacAddressFields& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:61</tt> by nedtool.
 * <pre>
 * //
 * // This class represents the EtherType field of an IEEE 802.3 Ethernet MAC header
 * // as defined in the section 3.2.6 Length/Type field of the IEEE Std 802.3-2018,
 * // IEEE Standard for Ethernet.
 * //
 * //  0                   1
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
 * // +-------------------------------+
 * // |        EtherType/Length       |
 * // +-------------------------------+
 * //
 * class EthernetTypeOrLengthField extends FieldsChunk
 * {
 *     chunkLength = B(2);
 *     uint16_t typeOrLength; // This two-octet field takes one of two meanings, depending on its numeric value. For numerical evaluation,
 *                            // the first octet is the most significant octet of this field.
 *                            // a) If the value of this field is less than or equal to 1500 decimal (05DC hexadecimal), then the Length/
 *                            //    Type field indicates the number of MAC client data octets contained in the subsequent MAC Client
 *                            //    Data field of the basic frame (Length interpretation).
 *                            // b) If the value of this field is greater than or equal to 1536 decimal (0600 hexadecimal), then the
 *                            //    Length/Type field indicates the Ethertype of the MAC client protocol (Type interpretation).
 * }
 * </pre>
 */
class INET_API EthernetTypeOrLengthField : public ::inet::FieldsChunk
{
  protected:
    uint16_t typeOrLength = 0;

  private:
    void copy(const EthernetTypeOrLengthField& other);

  protected:
    bool operator==(const EthernetTypeOrLengthField&) = delete;

  public:
    EthernetTypeOrLengthField();
    EthernetTypeOrLengthField(const EthernetTypeOrLengthField& other);
    virtual ~EthernetTypeOrLengthField();
    EthernetTypeOrLengthField& operator=(const EthernetTypeOrLengthField& other);
    virtual EthernetTypeOrLengthField *dup() const override {return new EthernetTypeOrLengthField(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getTypeOrLength() const;
    virtual void setTypeOrLength(uint16_t typeOrLength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetTypeOrLengthField& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetTypeOrLengthField& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:88</tt> by nedtool.
 * <pre>
 * //
 * // This class represents an IEEE 802.3 Ethernet MAC header as defined in the
 * // section 3.2 Elements of the MAC frame and packet of the IEEE Std 802.3-2018,
 * // IEEE Standard for Ethernet.
 * //
 * //  0                   1                   2                   3                   4
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
 * // +-----------------------------------------------------------------------------------------------+
 * // |                                      Destination Address                                      |
 * // +-----------------------------------------------------------------------------------------------+
 * // |                                        Source Address                                         |
 * // +-------------------------------+---------------------------------------------------------------+
 * // |           EtherType           |
 * // +-------------------------------+
 * //
 * class EthernetMacHeader extends EthernetMacAddressFields
 * {
 *     chunkLength = B(14); // B(6) + B(6) + B(2)
 *     uint16_t typeOrLength; // This two-octet field takes one of two meanings, depending on its numeric value. For numerical evaluation,
 *                            // the first octet is the most significant octet of this field.
 *                            // a) If the value of this field is less than or equal to 1500 decimal (05DC hexadecimal), then the Length/
 *                            //    Type field indicates the number of MAC client data octets contained in the subsequent MAC Client
 *                            //    Data field of the basic frame (Length interpretation).
 *                            // b) If the value of this field is greater than or equal to 1536 decimal (0600 hexadecimal), then the
 *                            //    Length/Type field indicates the Ethertype of the MAC client protocol (Type interpretation).
 * }
 * </pre>
 */
class INET_API EthernetMacHeader : public ::inet::EthernetMacAddressFields
{
  protected:
    uint16_t typeOrLength = 0;

  private:
    void copy(const EthernetMacHeader& other);

  protected:
    bool operator==(const EthernetMacHeader&) = delete;

  public:
    EthernetMacHeader();
    EthernetMacHeader(const EthernetMacHeader& other);
    virtual ~EthernetMacHeader();
    EthernetMacHeader& operator=(const EthernetMacHeader& other);
    virtual EthernetMacHeader *dup() const override {return new EthernetMacHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getTypeOrLength() const;
    virtual void setTypeOrLength(uint16_t typeOrLength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetMacHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetMacHeader& obj) {obj.parsimUnpack(b);}

// cplusplus {{
    inline bool isEth2Header(const EthernetMacHeader& hdr) { return isEth2Type(hdr.getTypeOrLength()); }
    inline bool isIeee8023Header(const EthernetMacHeader& hdr) { return isIeee8023Length(hdr.getTypeOrLength()); }
// }}

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:116</tt> by nedtool.
 * <pre>
 * //
 * // This class represents the variable length padding part of an Ethernet frame
 * // as defined in the section 3.2.8 Pad field of the IEEE Std 802.3-2018, IEEE
 * // Standard for Ethernet.
 * //
 * //  0                   1
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 ...
 * // +-------------------------------+
 * // |   Non-zero number of 0 bits   |
 * // +-------------------------------+
 * //
 * class EthernetPadding extends FieldsChunk
 * {
 * }
 * </pre>
 */
class INET_API EthernetPadding : public ::inet::FieldsChunk
{
  protected:

  private:
    void copy(const EthernetPadding& other);

  protected:
    bool operator==(const EthernetPadding&) = delete;

  public:
    EthernetPadding();
    EthernetPadding(const EthernetPadding& other);
    virtual ~EthernetPadding();
    EthernetPadding& operator=(const EthernetPadding& other);
    virtual EthernetPadding *dup() const override {return new EthernetPadding(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetPadding& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetPadding& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:131</tt> by nedtool.
 * <pre>
 * //
 * // This class represents an Ethernet FCS as defined in the section 3.2.9 Frame
 * // Check Sequence (FCS) field of the IEEE Std 802.3-2018, IEEE Standard for
 * // Ethernet.
 * //
 * //  0                   1                   2                   3
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * // +---------------------------------------------------------------+
 * // |                              FCS                              |
 * // +---------------------------------------------------------------+
 * //
 * class EthernetFcs extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     uint32_t fcs; // actual value may be omitted depending on the selected fcsMode
 * 
 *     FcsMode fcsMode = FCS_MODE_UNDEFINED; // meta information, not represented directly in the frame
 * }
 * </pre>
 */
class INET_API EthernetFcs : public ::inet::FieldsChunk
{
  protected:
    uint32_t fcs = 0;
    inet::FcsMode fcsMode = FCS_MODE_UNDEFINED;

  private:
    void copy(const EthernetFcs& other);

  protected:
    bool operator==(const EthernetFcs&) = delete;

  public:
    EthernetFcs();
    EthernetFcs(const EthernetFcs& other);
    virtual ~EthernetFcs();
    EthernetFcs& operator=(const EthernetFcs& other);
    virtual EthernetFcs *dup() const override {return new EthernetFcs(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getFcs() const;
    virtual void setFcs(uint32_t fcs);
    virtual inet::FcsMode getFcsMode() const;
    virtual void setFcsMode(inet::FcsMode fcsMode);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetFcs& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetFcs& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ethernet/common/EthernetMacHeader.msg:150</tt> by nedtool.
 * <pre>
 * //
 * // This class represents an Ethernet fragment FCS as defined in the section 3.2.9
 * // Frame Check Sequence (FCS) field of the IEEE Std 802.3-2018, IEEE Standard for
 * // Ethernet.
 * //
 * //  0                   1                   2                   3
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * // +---------------------------------------------------------------+
 * // |                              FCS                              |
 * // +---------------------------------------------------------------+
 * //
 * class EthernetFragmentFcs extends EthernetFcs
 * {
 *     bool mCrc; // meta information, not represented directly in the frame
 * }
 * </pre>
 */
class INET_API EthernetFragmentFcs : public ::inet::EthernetFcs
{
  protected:
    bool mCrc = false;

  private:
    void copy(const EthernetFragmentFcs& other);

  protected:
    bool operator==(const EthernetFragmentFcs&) = delete;

  public:
    EthernetFragmentFcs();
    EthernetFragmentFcs(const EthernetFragmentFcs& other);
    virtual ~EthernetFragmentFcs();
    EthernetFragmentFcs& operator=(const EthernetFragmentFcs& other);
    virtual EthernetFragmentFcs *dup() const override {return new EthernetFragmentFcs(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getMCrc() const;
    virtual void setMCrc(bool mCrc);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EthernetFragmentFcs& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EthernetFragmentFcs& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_ETHERNETMACHEADER_M_H

