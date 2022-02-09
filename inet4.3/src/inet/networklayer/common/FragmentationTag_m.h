//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/common/FragmentationTag.msg.
//

#ifndef __INET_FRAGMENTATIONTAG_M_H
#define __INET_FRAGMENTATIONTAG_M_H

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

class FragmentationReq;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/common/FragmentationTag.msg:27</tt> by nedtool.
 * <pre>
 * //
 * // Determines the fragmentation
 * //
 * class FragmentationReq extends TagBase
 * {
 *     bool dontFragment = false;   // "don't fragment" bit
 * }
 * </pre>
 */
class INET_API FragmentationReq : public ::inet::TagBase
{
  protected:
    bool dontFragment = false;

  private:
    void copy(const FragmentationReq& other);

  protected:
    bool operator==(const FragmentationReq&) = delete;

  public:
    FragmentationReq();
    FragmentationReq(const FragmentationReq& other);
    virtual ~FragmentationReq();
    FragmentationReq& operator=(const FragmentationReq& other);
    virtual FragmentationReq *dup() const override {return new FragmentationReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getDontFragment() const;
    virtual void setDontFragment(bool dontFragment);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FragmentationReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FragmentationReq& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_FRAGMENTATIONTAG_M_H

