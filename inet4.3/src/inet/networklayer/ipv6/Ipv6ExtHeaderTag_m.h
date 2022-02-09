//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/ipv6/Ipv6ExtHeaderTag.msg.
//

#ifndef __INET_IPV6EXTHEADERTAG_M_H
#define __INET_IPV6EXTHEADERTAG_M_H

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

class Ipv6ExtHeaderTagBase;
class Ipv6ExtHeaderReq;
class Ipv6ExtHeaderInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase

#include "inet/networklayer/ipv6/Ipv6Header_m.h" // import inet.networklayer.ipv6.Ipv6Header


namespace inet {

// cplusplus {{
std::ostream& operator<<(std::ostream& os, Ipv6ExtensionHeader *eh);
// }}

/**
 * Class generated from <tt>inet/networklayer/ipv6/Ipv6ExtHeaderTag.msg:30</tt> by nedtool.
 * <pre>
 * class Ipv6ExtHeaderTagBase extends TagBase
 * {
 *     Ipv6ExtensionHeader *extensionHeader[] \@owned; // array of extension headers, subclassed from ~IPv6ExtensionHeader   //TODO IPv6ExtensionHeadersTag
 * }
 * </pre>
 */
class INET_API Ipv6ExtHeaderTagBase : public ::inet::TagBase
{
  protected:
    Ipv6ExtensionHeader * *extensionHeader = nullptr;
    size_t extensionHeader_arraysize = 0;

  private:
    void copy(const Ipv6ExtHeaderTagBase& other);

  protected:
    bool operator==(const Ipv6ExtHeaderTagBase&) = delete;

  public:
    Ipv6ExtHeaderTagBase();
    Ipv6ExtHeaderTagBase(const Ipv6ExtHeaderTagBase& other);
    virtual ~Ipv6ExtHeaderTagBase();
    Ipv6ExtHeaderTagBase& operator=(const Ipv6ExtHeaderTagBase& other);
    virtual Ipv6ExtHeaderTagBase *dup() const override {return new Ipv6ExtHeaderTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setExtensionHeaderArraySize(size_t size);
    virtual size_t getExtensionHeaderArraySize() const;
    virtual const Ipv6ExtensionHeader * getExtensionHeader(size_t k) const;
    virtual Ipv6ExtensionHeader * getExtensionHeaderForUpdate(size_t k) { return const_cast<Ipv6ExtensionHeader *>(const_cast<Ipv6ExtHeaderTagBase*>(this)->getExtensionHeader(k));}
    virtual Ipv6ExtensionHeader * dropExtensionHeader(size_t k);
    virtual void setExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader);
    virtual void insertExtensionHeader(Ipv6ExtensionHeader * extensionHeader);
    virtual void insertExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader);
    virtual void eraseExtensionHeader(size_t k);

  public:
    /**
     * Remove the first extension header and return it.
     */
    Ipv6ExtensionHeader *removeFirstExtensionHeader();
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6ExtHeaderTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6ExtHeaderTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv6/Ipv6ExtHeaderTag.msg:43</tt> by nedtool.
 * <pre>
 * class Ipv6ExtHeaderReq extends Ipv6ExtHeaderTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv6ExtHeaderReq : public ::inet::Ipv6ExtHeaderTagBase
{
  protected:

  private:
    void copy(const Ipv6ExtHeaderReq& other);

  protected:
    bool operator==(const Ipv6ExtHeaderReq&) = delete;

  public:
    Ipv6ExtHeaderReq();
    Ipv6ExtHeaderReq(const Ipv6ExtHeaderReq& other);
    virtual ~Ipv6ExtHeaderReq();
    Ipv6ExtHeaderReq& operator=(const Ipv6ExtHeaderReq& other);
    virtual Ipv6ExtHeaderReq *dup() const override {return new Ipv6ExtHeaderReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6ExtHeaderReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6ExtHeaderReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv6/Ipv6ExtHeaderTag.msg:47</tt> by nedtool.
 * <pre>
 * class Ipv6ExtHeaderInd extends Ipv6ExtHeaderTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv6ExtHeaderInd : public ::inet::Ipv6ExtHeaderTagBase
{
  protected:

  private:
    void copy(const Ipv6ExtHeaderInd& other);

  protected:
    bool operator==(const Ipv6ExtHeaderInd&) = delete;

  public:
    Ipv6ExtHeaderInd();
    Ipv6ExtHeaderInd(const Ipv6ExtHeaderInd& other);
    virtual ~Ipv6ExtHeaderInd();
    Ipv6ExtHeaderInd& operator=(const Ipv6ExtHeaderInd& other);
    virtual Ipv6ExtHeaderInd *dup() const override {return new Ipv6ExtHeaderInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6ExtHeaderInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6ExtHeaderInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_IPV6EXTHEADERTAG_M_H

