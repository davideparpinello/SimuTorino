//
// Generated file, do not edit! Created by nedtool 6.0 from inet/applications/dhcp/DhcpMessage.msg.
//

#ifndef __INET_DHCPMESSAGE_M_H
#define __INET_DHCPMESSAGE_M_H

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

class DhcpOptions;
class DhcpMessage;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Enum generated from <tt>inet/applications/dhcp/DhcpMessage.msg:29</tt> by nedtool.
 * <pre>
 * enum DhcpOpcode
 * {
 *     BOOTREQUEST = 1;
 *     BOOTREPLY = 2;
 * }
 * </pre>
 */
enum DhcpOpcode {
    BOOTREQUEST = 1,
    BOOTREPLY = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpOpcode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpOpcode& e) { int n; b->unpack(n); e = static_cast<DhcpOpcode>(n); }

/**
 * Enum generated from <tt>inet/applications/dhcp/DhcpMessage.msg:35</tt> by nedtool.
 * <pre>
 * enum DhcpMessageType
 * {
 *     DHCPDISCOVER = 1;
 *     DHCPOFFER = 2;
 *     DHCPREQUEST = 3;
 *     DHCPDECLINE = 4;
 *     DHCPACK = 5;
 *     DHCPNAK = 6;
 *     DHCPRELEASE = 7;
 *     DHCPINFORM = 8;
 * }
 * </pre>
 */
enum DhcpMessageType {
    DHCPDISCOVER = 1,
    DHCPOFFER = 2,
    DHCPREQUEST = 3,
    DHCPDECLINE = 4,
    DHCPACK = 5,
    DHCPNAK = 6,
    DHCPRELEASE = 7,
    DHCPINFORM = 8
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpMessageType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpMessageType& e) { int n; b->unpack(n); e = static_cast<DhcpMessageType>(n); }

/**
 * Enum generated from <tt>inet/applications/dhcp/DhcpMessage.msg:47</tt> by nedtool.
 * <pre>
 * enum DhcpOptionCode
 * {
 *     DHCP_MSG_TYPE = 53;
 *     CLIENT_ID = 61;
 *     HOSTNAME = 12;
 *     REQUESTED_IP = 50;
 *     PARAM_LIST = 55;
 *     SUBNET_MASK = 1;
 *     ROUTER = 3;
 *     DNS = 6;
 *     NTP_SRV = 42;
 *     RENEWAL_TIME = 58;
 *     REBIND_TIME = 59;
 *     LEASE_TIME = 51;
 *     SERVER_ID = 54;
 * }
 * </pre>
 */
enum DhcpOptionCode {
    DHCP_MSG_TYPE = 53,
    CLIENT_ID = 61,
    HOSTNAME = 12,
    REQUESTED_IP = 50,
    PARAM_LIST = 55,
    SUBNET_MASK = 1,
    ROUTER = 3,
    DNS = 6,
    NTP_SRV = 42,
    RENEWAL_TIME = 58,
    REBIND_TIME = 59,
    LEASE_TIME = 51,
    SERVER_ID = 54
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpOptionCode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpOptionCode& e) { int n; b->unpack(n); e = static_cast<DhcpOptionCode>(n); }

/**
 * Enum generated from <tt>inet/applications/dhcp/DhcpMessage.msg:65</tt> by nedtool.
 * <pre>
 * // DHCP timer types (RFC 2131 4.4.5)
 * enum DhcpTimerType
 * {
 *     WAIT_OFFER = 1;
 *     WAIT_ACK = 2;
 *     T1 = 3;
 *     T2 = 4;
 *     LEASE_TIMEOUT = 5;
 *     START_DHCP = 6;
 * }
 * </pre>
 */
enum DhcpTimerType {
    WAIT_OFFER = 1,
    WAIT_ACK = 2,
    T1 = 3,
    T2 = 4,
    LEASE_TIMEOUT = 5,
    START_DHCP = 6
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpTimerType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpTimerType& e) { int n; b->unpack(n); e = static_cast<DhcpTimerType>(n); }

/**
 * Class generated from <tt>inet/applications/dhcp/DhcpMessage.msg:84</tt> by nedtool.
 * <pre>
 * //
 * // Represents options in a DHCP message. In the DHCP protocol, options are
 * // added to the message as tagged data items. In the simulation, this DhcpOptions
 * // class statically holds the union of all options actually used by the DHCP
 * // protocol models. Options absent from a packet are represented by empty/unfilled
 * // DhcpOptions fields.
 * //
 * // \@see DhcpMessage, DhcpClient, DhcpServer
 * //
 * class DhcpOptions extends cObject
 * {
 *     DhcpMessageType messageType; // to convey the type of the DHCP message
 *     string hostName; // name of the client
 *     DhcpOptionCode parameterRequestList[]; // used by a DHCP client to request values for specified configuration parameters
 *     MacAddress clientIdentifier; // used by DHCP clients to specify their unique identifier
 *     Ipv4Address requestedIp; // used in a client request (DHCPDISCOVER) to allow the client to request that a particular IP address be assigned
 *     Ipv4Address subnetMask; // client's subnet mask
 *     Ipv4Address router[]; // IP addresses for routers on the client's subnet
 *     Ipv4Address dns[]; // list of DNSs available to the client
 *     Ipv4Address ntp[]; // list of IP addresses indicating NTP servers available to the client
 *     Ipv4Address serverIdentifier; // client use this field as the destination address for any unicast DHCP messages to the server
 *     simtime_t renewalTime; // time interval (T1) from address assignment until the client transitions to the RENEWING state
 *     simtime_t rebindingTime; // time interval (T2) from address assignment until the client transitions to the REBINDING state
 *     simtime_t leaseTime; // request for lease time (client), offered lease time (server)
 * }
 * </pre>
 */
class INET_API DhcpOptions : public ::omnetpp::cObject
{
  protected:
    inet::DhcpMessageType messageType = static_cast<inet::DhcpMessageType>(-1);
    omnetpp::opp_string hostName;
    inet::DhcpOptionCode *parameterRequestList = nullptr;
    size_t parameterRequestList_arraysize = 0;
    MacAddress clientIdentifier;
    Ipv4Address requestedIp;
    Ipv4Address subnetMask;
    Ipv4Address *router = nullptr;
    size_t router_arraysize = 0;
    Ipv4Address *dns = nullptr;
    size_t dns_arraysize = 0;
    Ipv4Address *ntp = nullptr;
    size_t ntp_arraysize = 0;
    Ipv4Address serverIdentifier;
    omnetpp::simtime_t renewalTime = SIMTIME_ZERO;
    omnetpp::simtime_t rebindingTime = SIMTIME_ZERO;
    omnetpp::simtime_t leaseTime = SIMTIME_ZERO;

  private:
    void copy(const DhcpOptions& other);

  protected:
    bool operator==(const DhcpOptions&) = delete;

  public:
    DhcpOptions();
    DhcpOptions(const DhcpOptions& other);
    virtual ~DhcpOptions();
    DhcpOptions& operator=(const DhcpOptions& other);
    virtual DhcpOptions *dup() const override {return new DhcpOptions(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::DhcpMessageType getMessageType() const;
    virtual void setMessageType(inet::DhcpMessageType messageType);
    virtual const char * getHostName() const;
    virtual void setHostName(const char * hostName);
    virtual void setParameterRequestListArraySize(size_t size);
    virtual size_t getParameterRequestListArraySize() const;
    virtual inet::DhcpOptionCode getParameterRequestList(size_t k) const;
    virtual void setParameterRequestList(size_t k, inet::DhcpOptionCode parameterRequestList);
    virtual void insertParameterRequestList(inet::DhcpOptionCode parameterRequestList);
    virtual void insertParameterRequestList(size_t k, inet::DhcpOptionCode parameterRequestList);
    virtual void eraseParameterRequestList(size_t k);
    virtual const MacAddress& getClientIdentifier() const;
    virtual MacAddress& getClientIdentifierForUpdate() { return const_cast<MacAddress&>(const_cast<DhcpOptions*>(this)->getClientIdentifier());}
    virtual void setClientIdentifier(const MacAddress& clientIdentifier);
    virtual const Ipv4Address& getRequestedIp() const;
    virtual Ipv4Address& getRequestedIpForUpdate() { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getRequestedIp());}
    virtual void setRequestedIp(const Ipv4Address& requestedIp);
    virtual const Ipv4Address& getSubnetMask() const;
    virtual Ipv4Address& getSubnetMaskForUpdate() { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getSubnetMask());}
    virtual void setSubnetMask(const Ipv4Address& subnetMask);
    virtual void setRouterArraySize(size_t size);
    virtual size_t getRouterArraySize() const;
    virtual const Ipv4Address& getRouter(size_t k) const;
    virtual Ipv4Address& getRouterForUpdate(size_t k) { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getRouter(k));}
    virtual void setRouter(size_t k, const Ipv4Address& router);
    virtual void insertRouter(const Ipv4Address& router);
    virtual void insertRouter(size_t k, const Ipv4Address& router);
    virtual void eraseRouter(size_t k);
    virtual void setDnsArraySize(size_t size);
    virtual size_t getDnsArraySize() const;
    virtual const Ipv4Address& getDns(size_t k) const;
    virtual Ipv4Address& getDnsForUpdate(size_t k) { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getDns(k));}
    virtual void setDns(size_t k, const Ipv4Address& dns);
    virtual void insertDns(const Ipv4Address& dns);
    virtual void insertDns(size_t k, const Ipv4Address& dns);
    virtual void eraseDns(size_t k);
    virtual void setNtpArraySize(size_t size);
    virtual size_t getNtpArraySize() const;
    virtual const Ipv4Address& getNtp(size_t k) const;
    virtual Ipv4Address& getNtpForUpdate(size_t k) { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getNtp(k));}
    virtual void setNtp(size_t k, const Ipv4Address& ntp);
    virtual void insertNtp(const Ipv4Address& ntp);
    virtual void insertNtp(size_t k, const Ipv4Address& ntp);
    virtual void eraseNtp(size_t k);
    virtual const Ipv4Address& getServerIdentifier() const;
    virtual Ipv4Address& getServerIdentifierForUpdate() { return const_cast<Ipv4Address&>(const_cast<DhcpOptions*>(this)->getServerIdentifier());}
    virtual void setServerIdentifier(const Ipv4Address& serverIdentifier);
    virtual omnetpp::simtime_t getRenewalTime() const;
    virtual void setRenewalTime(omnetpp::simtime_t renewalTime);
    virtual omnetpp::simtime_t getRebindingTime() const;
    virtual void setRebindingTime(omnetpp::simtime_t rebindingTime);
    virtual omnetpp::simtime_t getLeaseTime() const;
    virtual void setLeaseTime(omnetpp::simtime_t leaseTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpOptions& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpOptions& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/applications/dhcp/DhcpMessage.msg:107</tt> by nedtool.
 * <pre>
 * //
 * // Represents a DHCP message. DHCP (Dynamic Host Configuration Protocol, RFC 2131)
 * // provides a framework for passing configuration information to hosts on a TCP/IP network.
 * //
 * // \@see DhcpClient, DhcpServer
 * //
 * class DhcpMessage extends FieldsChunk
 * {
 *     DhcpOpcode op; // message op code / message type. 1 = BOOTREQUEST, 2 = BOOTREPLY
 *     int htype; // hardware address type, see Arp section in "Assigned Numbers" RFC; e.g., '1' = 10mb ethernet
 *     int hlen; // hardware address length (e.g.  '6' for 10mb ethernet)
 *     int hops; // client sets to zero, optionally used by relay agents when booting via a relay agent
 *     unsigned int xid; // transaction ID, a random number chosen by the client, used by the client and server to associate messages and responses between a client and a server
 *     int secs; // filled in by client, seconds elapsed since client began address acquisition or renewal process
 *     bool broadcast; // the broadcast bit in the flags field
 *     uint16_t reserved = 0; // MUST BE ZERO (reserved for future use)
 *     Ipv4Address ciaddr; // client IP address; only filled in if client is in BOUND, RENEW or REBINDING state and can respond to Arp requests
 *     Ipv4Address yiaddr; // 'your' (client) IP address
 *     Ipv4Address giaddr; // relay agent IP address, used in booting via a relay agent
 *     MacAddress chaddr; // client hardware address (MAC)
 *     string sname; // optional server host name
 *     string file; // boot file name (unused in the simulation)
 *     DhcpOptions options; // holds DHCP options
 * }
 * </pre>
 */
class INET_API DhcpMessage : public ::inet::FieldsChunk
{
  protected:
    inet::DhcpOpcode op = static_cast<inet::DhcpOpcode>(-1);
    int htype = 0;
    int hlen = 0;
    int hops = 0;
    unsigned int xid = 0;
    int secs = 0;
    bool broadcast = false;
    uint16_t reserved = 0;
    Ipv4Address ciaddr;
    Ipv4Address yiaddr;
    Ipv4Address giaddr;
    MacAddress chaddr;
    omnetpp::opp_string sname;
    omnetpp::opp_string file;
    DhcpOptions options;

  private:
    void copy(const DhcpMessage& other);

  protected:
    bool operator==(const DhcpMessage&) = delete;

  public:
    DhcpMessage();
    DhcpMessage(const DhcpMessage& other);
    virtual ~DhcpMessage();
    DhcpMessage& operator=(const DhcpMessage& other);
    virtual DhcpMessage *dup() const override {return new DhcpMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::DhcpOpcode getOp() const;
    virtual void setOp(inet::DhcpOpcode op);
    virtual int getHtype() const;
    virtual void setHtype(int htype);
    virtual int getHlen() const;
    virtual void setHlen(int hlen);
    virtual int getHops() const;
    virtual void setHops(int hops);
    virtual unsigned int getXid() const;
    virtual void setXid(unsigned int xid);
    virtual int getSecs() const;
    virtual void setSecs(int secs);
    virtual bool getBroadcast() const;
    virtual void setBroadcast(bool broadcast);
    virtual uint16_t getReserved() const;
    virtual void setReserved(uint16_t reserved);
    virtual const Ipv4Address& getCiaddr() const;
    virtual Ipv4Address& getCiaddrForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<DhcpMessage*>(this)->getCiaddr());}
    virtual void setCiaddr(const Ipv4Address& ciaddr);
    virtual const Ipv4Address& getYiaddr() const;
    virtual Ipv4Address& getYiaddrForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<DhcpMessage*>(this)->getYiaddr());}
    virtual void setYiaddr(const Ipv4Address& yiaddr);
    virtual const Ipv4Address& getGiaddr() const;
    virtual Ipv4Address& getGiaddrForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<DhcpMessage*>(this)->getGiaddr());}
    virtual void setGiaddr(const Ipv4Address& giaddr);
    virtual const MacAddress& getChaddr() const;
    virtual MacAddress& getChaddrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<DhcpMessage*>(this)->getChaddr());}
    virtual void setChaddr(const MacAddress& chaddr);
    virtual const char * getSname() const;
    virtual void setSname(const char * sname);
    virtual const char * getFile() const;
    virtual void setFile(const char * file);
    virtual const DhcpOptions& getOptions() const;
    virtual DhcpOptions& getOptionsForUpdate() { handleChange();return const_cast<DhcpOptions&>(const_cast<DhcpMessage*>(this)->getOptions());}
    virtual void setOptions(const DhcpOptions& options);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DhcpMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DhcpMessage& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_DHCPMESSAGE_M_H

