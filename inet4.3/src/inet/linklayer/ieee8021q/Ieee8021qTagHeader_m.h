//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ieee8021q/Ieee8021qTagHeader.msg.
//

#ifndef __INET_IEEE8021QTAGHEADER_M_H
#define __INET_IEEE8021QTAGHEADER_M_H

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

class Ieee8021qTagTpidHeader;
class Ieee8021qTagEpdHeader;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/ieee8021q/Ieee8021qTagHeader.msg:35</tt> by nedtool.
 * <pre>
 * //
 * // This chunk represents an IEEE 802.1Q tag header as defined by the section
 * // 9.3 Tag format of the IEEE Std 802.1Q-2018, IEEE Standard for Local and
 * // Metropolitan Area Networks, Bridges and Bridged Networks.
 * //
 * //  0                   1                   2                   3
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * // +-------------------------------+-----+-+-----------------------+
 * // |       TPID (e.g. 0x8100)      | PCP |D|        VLAN ID        |
 * // +-------------------------------+-----+-+-----------------------+
 * //
 * class Ieee8021qTagTpidHeader extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     uint16_t tpid; // Tag Protocol Identifier (TPID): 16-bit field specifying an EtherType value that is used to identify the frame as a tagged frame and to select the correct tag decoding functions. 
 *     uint8_t pcp;   // Priority Code Point (PCP): a 3-bit field which refers to the IEEE 802.1p priority. It indicates the frame priority level.
 *                    // Values are from 0 (best effort) to 7 (highest); 1 represents the lowest priority.
 *                    // Priority order lowest to highest: 1 0 2 3 4 5 6 7
 *     bool dei;      // Drop Eligible Indicator (DEI): a 1-bit field. May be used separately or in conjunction with PCP to indicate frames eligible to be dropped in the presence of congestion.
 *     uint16_t vid;  // VLAN Identifier (VID): a 12-bit field specifying the VLAN to which the frame belongs.
 *                    // The hexadecimal values of 0x000 and 0xFFF are reserved. All other values may be used as VLAN identifiers, allowing up to 4,094 VLANs.
 *                    // The reserved value 0x000 indicates that the frame does not belong to any VLAN; in this case,
 *                    // the 802.1Q tag specifies only a priority and is referred to as a priority tag. On bridges,
 *                    // VLAN 1 (the default VLAN ID) is often reserved for a management VLAN; this is vendor-specific.
 * }
 * </pre>
 */
class INET_API Ieee8021qTagTpidHeader : public ::inet::FieldsChunk
{
  protected:
    uint16_t tpid = 0;
    uint8_t pcp = 0;
    bool dei = false;
    uint16_t vid = 0;

  private:
    void copy(const Ieee8021qTagTpidHeader& other);

  protected:
    bool operator==(const Ieee8021qTagTpidHeader&) = delete;

  public:
    Ieee8021qTagTpidHeader();
    Ieee8021qTagTpidHeader(const Ieee8021qTagTpidHeader& other);
    virtual ~Ieee8021qTagTpidHeader();
    Ieee8021qTagTpidHeader& operator=(const Ieee8021qTagTpidHeader& other);
    virtual Ieee8021qTagTpidHeader *dup() const override {return new Ieee8021qTagTpidHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getTpid() const;
    virtual void setTpid(uint16_t tpid);
    virtual uint8_t getPcp() const;
    virtual void setPcp(uint8_t pcp);
    virtual bool getDei() const;
    virtual void setDei(bool dei);
    virtual uint16_t getVid() const;
    virtual void setVid(uint16_t vid);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee8021qTagTpidHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee8021qTagTpidHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ieee8021q/Ieee8021qTagHeader.msg:64</tt> by nedtool.
 * <pre>
 * //
 * // This chunk represents an IEEE 802.1Q tag header without the TPID field and
 * // with the following EtherType Protocol Discrimination (EPD) in the packet.
 * // The reason for this shifted representation is that it's often easier to look
 * // at a 802.1Q tag this way during processing. The typeOrLength field contains
 * // the EtherType as defined in the section 9.2 EtherTypes of the IEEE Std 802-2014,
 * // IEEE Standard for Local and Metropolitan Area Networks: Overview and Architecture.
 * //
 * //  0                   1                   2                   3
 * //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 * // +-----+-+-----------------------+-------------------------------+
 * // | PCP |D|        VLAN ID        |        EtherType/Length       |
 * // +-----+-+-----------------------+-------------------------------+
 * //
 * class Ieee8021qTagEpdHeader extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     uint8_t pcp;           // Priority Code Point (PCP): a 3-bit field which refers to the IEEE 802.1p priority. It indicates the frame priority level.
 *                            // Values are from 0 (best effort) to 7 (highest); 1 represents the lowest priority.
 *                            // Priority order lowest to highest: 1 0 2 3 4 5 6 7
 *     bool dei;              // Drop Eligible Indicator (DEI): a 1-bit field. May be used separately or in conjunction with PCP to indicate frames eligible to be dropped in the presence of congestion.
 *     uint16_t vid;          // VLAN Identifier (VID): a 12-bit field specifying the VLAN to which the frame belongs.
 *                            // The hexadecimal values of 0x000 and 0xFFF are reserved. All other values may be used as VLAN identifiers, allowing up to 4,094 VLANs.
 *                            // The reserved value 0x000 indicates that the frame does not belong to any VLAN; in this case,
 *                            // the 802.1Q tag specifies only a priority and is referred to as a priority tag. On bridges,
 *                            // VLAN 1 (the default VLAN ID) is often reserved for a management VLAN; this is vendor-specific.
 *     uint16_t typeOrLength; // This field contains the 16 bits immediately following the 802.1Q tag header TCI field:
 *                            // I. Tag Protocol Identifier (TPID) of the following tag header: 16-bit field specifying an EtherType value that is used to identify the frame as a tagged frame and to select the correct tag decoding functions.
 *                            // II. This two-octet field takes one of two meanings, depending on its numeric value. For numerical evaluation,
 *                            //     the first octet is the most significant octet of this field.
 *                            //     a) If the value of this field is less than or equal to 1500 decimal (05DC hexadecimal), then the Length/
 *                            //        Type field indicates the number of MAC client data octets contained in the subsequent MAC Client
 *                            //        Data field of the basic frame (Length interpretation).
 *                            //     b) If the value of this field is greater than or equal to 1536 decimal (0600 hexadecimal), then the
 *                            //        Length/Type field indicates the Ethertype of the MAC client protocol (Type interpretation).    
 * }
 * </pre>
 */
class INET_API Ieee8021qTagEpdHeader : public ::inet::FieldsChunk
{
  protected:
    uint8_t pcp = 0;
    bool dei = false;
    uint16_t vid = 0;
    uint16_t typeOrLength = 0;

  private:
    void copy(const Ieee8021qTagEpdHeader& other);

  protected:
    bool operator==(const Ieee8021qTagEpdHeader&) = delete;

  public:
    Ieee8021qTagEpdHeader();
    Ieee8021qTagEpdHeader(const Ieee8021qTagEpdHeader& other);
    virtual ~Ieee8021qTagEpdHeader();
    Ieee8021qTagEpdHeader& operator=(const Ieee8021qTagEpdHeader& other);
    virtual Ieee8021qTagEpdHeader *dup() const override {return new Ieee8021qTagEpdHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getPcp() const;
    virtual void setPcp(uint8_t pcp);
    virtual bool getDei() const;
    virtual void setDei(bool dei);
    virtual uint16_t getVid() const;
    virtual void setVid(uint16_t vid);
    virtual uint16_t getTypeOrLength() const;
    virtual void setTypeOrLength(uint16_t typeOrLength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee8021qTagEpdHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee8021qTagEpdHeader& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_IEEE8021QTAGHEADER_M_H

