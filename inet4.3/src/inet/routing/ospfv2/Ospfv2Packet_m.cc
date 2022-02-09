//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/ospfv2/Ospfv2Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "Ospfv2Packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {
namespace ospfv2 {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline typename std::enable_if<!std::is_base_of<omnetpp::cObject, T>::value, std::ostream&>::type
operator<<(std::ostream& out,const T&) {const char *s = omnetpp::opp_typename(typeid(T)); out.put('<'); out.write(s, strlen(s)); out.put('>'); return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospfv2::Ospfv2TimerType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospfv2::Ospfv2TimerType"));
    e->insert(INTERFACE_HELLO_TIMER, "INTERFACE_HELLO_TIMER");
    e->insert(INTERFACE_WAIT_TIMER, "INTERFACE_WAIT_TIMER");
    e->insert(INTERFACE_ACKNOWLEDGEMENT_TIMER, "INTERFACE_ACKNOWLEDGEMENT_TIMER");
    e->insert(NEIGHBOR_INACTIVITY_TIMER, "NEIGHBOR_INACTIVITY_TIMER");
    e->insert(NEIGHBOR_POLL_TIMER, "NEIGHBOR_POLL_TIMER");
    e->insert(NEIGHBOR_DD_RETRANSMISSION_TIMER, "NEIGHBOR_DD_RETRANSMISSION_TIMER");
    e->insert(NEIGHBOR_UPDATE_RETRANSMISSION_TIMER, "NEIGHBOR_UPDATE_RETRANSMISSION_TIMER");
    e->insert(NEIGHBOR_REQUEST_RETRANSMISSION_TIMER, "NEIGHBOR_REQUEST_RETRANSMISSION_TIMER");
    e->insert(DATABASE_AGE_TIMER, "DATABASE_AGE_TIMER");
)

Ospfv2Options::Ospfv2Options()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Ospfv2Options& a)
{
    doParsimPacking(b,a.unused_1);
    doParsimPacking(b,a.E_ExternalRoutingCapability);
    doParsimPacking(b,a.MC_MulticastForwarding);
    doParsimPacking(b,a.NP_Type7LSA);
    doParsimPacking(b,a.EA_ForwardExternalLSAs);
    doParsimPacking(b,a.DC_DemandCircuits);
    doParsimPacking(b,a.unused_2);
    doParsimPacking(b,a.unused_3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ospfv2Options& a)
{
    doParsimUnpacking(b,a.unused_1);
    doParsimUnpacking(b,a.E_ExternalRoutingCapability);
    doParsimUnpacking(b,a.MC_MulticastForwarding);
    doParsimUnpacking(b,a.NP_Type7LSA);
    doParsimUnpacking(b,a.EA_ForwardExternalLSAs);
    doParsimUnpacking(b,a.DC_DemandCircuits);
    doParsimUnpacking(b,a.unused_2);
    doParsimUnpacking(b,a.unused_3);
}

class Ospfv2OptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_unused_1,
        FIELD_E_ExternalRoutingCapability,
        FIELD_MC_MulticastForwarding,
        FIELD_NP_Type7LSA,
        FIELD_EA_ForwardExternalLSAs,
        FIELD_DC_DemandCircuits,
        FIELD_unused_2,
        FIELD_unused_3,
    };
  public:
    Ospfv2OptionsDescriptor();
    virtual ~Ospfv2OptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2OptionsDescriptor)

Ospfv2OptionsDescriptor::Ospfv2OptionsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2Options)), "")
{
    propertynames = nullptr;
}

Ospfv2OptionsDescriptor::~Ospfv2OptionsDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2OptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2Options *>(obj)!=nullptr;
}

const char **Ospfv2OptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2OptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2OptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Ospfv2OptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_unused_1
        FD_ISEDITABLE,    // FIELD_E_ExternalRoutingCapability
        FD_ISEDITABLE,    // FIELD_MC_MulticastForwarding
        FD_ISEDITABLE,    // FIELD_NP_Type7LSA
        FD_ISEDITABLE,    // FIELD_EA_ForwardExternalLSAs
        FD_ISEDITABLE,    // FIELD_DC_DemandCircuits
        FD_ISEDITABLE,    // FIELD_unused_2
        FD_ISEDITABLE,    // FIELD_unused_3
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2OptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused_1",
        "E_ExternalRoutingCapability",
        "MC_MulticastForwarding",
        "NP_Type7LSA",
        "EA_ForwardExternalLSAs",
        "DC_DemandCircuits",
        "unused_2",
        "unused_3",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int Ospfv2OptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_1") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ExternalRoutingCapability") == 0) return base+1;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MC_MulticastForwarding") == 0) return base+2;
    if (fieldName[0] == 'N' && strcmp(fieldName, "NP_Type7LSA") == 0) return base+3;
    if (fieldName[0] == 'E' && strcmp(fieldName, "EA_ForwardExternalLSAs") == 0) return base+4;
    if (fieldName[0] == 'D' && strcmp(fieldName, "DC_DemandCircuits") == 0) return base+5;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_2") == 0) return base+6;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_3") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2OptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_unused_1
        "bool",    // FIELD_E_ExternalRoutingCapability
        "bool",    // FIELD_MC_MulticastForwarding
        "bool",    // FIELD_NP_Type7LSA
        "bool",    // FIELD_EA_ForwardExternalLSAs
        "bool",    // FIELD_DC_DemandCircuits
        "bool",    // FIELD_unused_2
        "bool",    // FIELD_unused_3
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2OptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2OptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2OptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2OptionsDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2Options'", field);
    }
}

const char *Ospfv2OptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2OptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: return bool2string(pp->unused_1);
        case FIELD_E_ExternalRoutingCapability: return bool2string(pp->E_ExternalRoutingCapability);
        case FIELD_MC_MulticastForwarding: return bool2string(pp->MC_MulticastForwarding);
        case FIELD_NP_Type7LSA: return bool2string(pp->NP_Type7LSA);
        case FIELD_EA_ForwardExternalLSAs: return bool2string(pp->EA_ForwardExternalLSAs);
        case FIELD_DC_DemandCircuits: return bool2string(pp->DC_DemandCircuits);
        case FIELD_unused_2: return bool2string(pp->unused_2);
        case FIELD_unused_3: return bool2string(pp->unused_3);
        default: return "";
    }
}

void Ospfv2OptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: pp->unused_1 = string2bool(value); break;
        case FIELD_E_ExternalRoutingCapability: pp->E_ExternalRoutingCapability = string2bool(value); break;
        case FIELD_MC_MulticastForwarding: pp->MC_MulticastForwarding = string2bool(value); break;
        case FIELD_NP_Type7LSA: pp->NP_Type7LSA = string2bool(value); break;
        case FIELD_EA_ForwardExternalLSAs: pp->EA_ForwardExternalLSAs = string2bool(value); break;
        case FIELD_DC_DemandCircuits: pp->DC_DemandCircuits = string2bool(value); break;
        case FIELD_unused_2: pp->unused_2 = string2bool(value); break;
        case FIELD_unused_3: pp->unused_3 = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Options'", field);
    }
}

const char *Ospfv2OptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2OptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ospfv2OptionsDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Options *pp = (Ospfv2Options *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Options'", field);
    }
}

Register_Class(Ospfv2Packet)

Ospfv2Packet::Ospfv2Packet() : ::inet::ospf::OspfPacketBase()
{
    this->setChunkLength(B(24));
    this->setVersion(2);

}

Ospfv2Packet::Ospfv2Packet(const Ospfv2Packet& other) : ::inet::ospf::OspfPacketBase(other)
{
    copy(other);
}

Ospfv2Packet::~Ospfv2Packet()
{
}

Ospfv2Packet& Ospfv2Packet::operator=(const Ospfv2Packet& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacketBase::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2Packet::copy(const Ospfv2Packet& other)
{
    this->authenticationType = other.authenticationType;
    for (size_t i = 0; i < 8; i++) {
        this->authentication[i] = other.authentication[i];
    }
}

void Ospfv2Packet::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacketBase::parsimPack(b);
    doParsimPacking(b,this->authenticationType);
    doParsimArrayPacking(b,this->authentication,8);
}

void Ospfv2Packet::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacketBase::parsimUnpack(b);
    doParsimUnpacking(b,this->authenticationType);
    doParsimArrayUnpacking(b,this->authentication,8);
}

short Ospfv2Packet::getAuthenticationType() const
{
    return this->authenticationType;
}

void Ospfv2Packet::setAuthenticationType(short authenticationType)
{
    handleChange();
    this->authenticationType = authenticationType;
}

size_t Ospfv2Packet::getAuthenticationArraySize() const
{
    return 8;
}

char Ospfv2Packet::getAuthentication(size_t k) const
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return this->authentication[k];
}

void Ospfv2Packet::setAuthentication(size_t k, char authentication)
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    handleChange();
    this->authentication[k] = authentication;
}

class Ospfv2PacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_authenticationType,
        FIELD_authentication,
    };
  public:
    Ospfv2PacketDescriptor();
    virtual ~Ospfv2PacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2PacketDescriptor)

Ospfv2PacketDescriptor::Ospfv2PacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2Packet)), "inet::ospf::OspfPacketBase")
{
    propertynames = nullptr;
}

Ospfv2PacketDescriptor::~Ospfv2PacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2PacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2Packet *>(obj)!=nullptr;
}

const char **Ospfv2PacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2PacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2PacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ospfv2PacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_authenticationType
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_authentication
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2PacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "authenticationType",
        "authentication",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ospfv2PacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authenticationType") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authentication") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2PacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_authenticationType
        "char",    // FIELD_authentication
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2PacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2PacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2PacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        case FIELD_authentication: return 8;
        default: return 0;
    }
}

void Ospfv2PacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2Packet'", field);
    }
}

const char *Ospfv2PacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2PacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        case FIELD_authenticationType: return long2string(pp->getAuthenticationType());
        case FIELD_authentication: return long2string(pp->getAuthentication(i));
        default: return "";
    }
}

void Ospfv2PacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        case FIELD_authenticationType: pp->setAuthenticationType(string2long(value)); break;
        case FIELD_authentication: pp->setAuthentication(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Packet'", field);
    }
}

const char *Ospfv2PacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2PacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ospfv2PacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Packet *pp = (Ospfv2Packet *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Packet'", field);
    }
}

Register_Class(Ospfv2HelloPacket)

Ospfv2HelloPacket::Ospfv2HelloPacket() : ::inet::ospfv2::Ospfv2Packet()
{
    this->setType(HELLO_PACKET);

}

Ospfv2HelloPacket::Ospfv2HelloPacket(const Ospfv2HelloPacket& other) : ::inet::ospfv2::Ospfv2Packet(other)
{
    copy(other);
}

Ospfv2HelloPacket::~Ospfv2HelloPacket()
{
    delete [] this->neighbor;
}

Ospfv2HelloPacket& Ospfv2HelloPacket::operator=(const Ospfv2HelloPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Packet::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2HelloPacket::copy(const Ospfv2HelloPacket& other)
{
    this->networkMask = other.networkMask;
    this->helloInterval = other.helloInterval;
    this->options = other.options;
    this->routerPriority = other.routerPriority;
    this->routerDeadInterval = other.routerDeadInterval;
    this->designatedRouter = other.designatedRouter;
    this->backupDesignatedRouter = other.backupDesignatedRouter;
    delete [] this->neighbor;
    this->neighbor = (other.neighbor_arraysize==0) ? nullptr : new Ipv4Address[other.neighbor_arraysize];
    neighbor_arraysize = other.neighbor_arraysize;
    for (size_t i = 0; i < neighbor_arraysize; i++) {
        this->neighbor[i] = other.neighbor[i];
    }
}

void Ospfv2HelloPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Packet::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->helloInterval);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->routerPriority);
    doParsimPacking(b,this->routerDeadInterval);
    doParsimPacking(b,this->designatedRouter);
    doParsimPacking(b,this->backupDesignatedRouter);
    b->pack(neighbor_arraysize);
    doParsimArrayPacking(b,this->neighbor,neighbor_arraysize);
}

void Ospfv2HelloPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->helloInterval);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->routerPriority);
    doParsimUnpacking(b,this->routerDeadInterval);
    doParsimUnpacking(b,this->designatedRouter);
    doParsimUnpacking(b,this->backupDesignatedRouter);
    delete [] this->neighbor;
    b->unpack(neighbor_arraysize);
    if (neighbor_arraysize == 0) {
        this->neighbor = nullptr;
    } else {
        this->neighbor = new Ipv4Address[neighbor_arraysize];
        doParsimArrayUnpacking(b,this->neighbor,neighbor_arraysize);
    }
}

const Ipv4Address& Ospfv2HelloPacket::getNetworkMask() const
{
    return this->networkMask;
}

void Ospfv2HelloPacket::setNetworkMask(const Ipv4Address& networkMask)
{
    handleChange();
    this->networkMask = networkMask;
}

short Ospfv2HelloPacket::getHelloInterval() const
{
    return this->helloInterval;
}

void Ospfv2HelloPacket::setHelloInterval(short helloInterval)
{
    handleChange();
    this->helloInterval = helloInterval;
}

const Ospfv2Options& Ospfv2HelloPacket::getOptions() const
{
    return this->options;
}

void Ospfv2HelloPacket::setOptions(const Ospfv2Options& options)
{
    handleChange();
    this->options = options;
}

char Ospfv2HelloPacket::getRouterPriority() const
{
    return this->routerPriority;
}

void Ospfv2HelloPacket::setRouterPriority(char routerPriority)
{
    handleChange();
    this->routerPriority = routerPriority;
}

long Ospfv2HelloPacket::getRouterDeadInterval() const
{
    return this->routerDeadInterval;
}

void Ospfv2HelloPacket::setRouterDeadInterval(long routerDeadInterval)
{
    handleChange();
    this->routerDeadInterval = routerDeadInterval;
}

const Ipv4Address& Ospfv2HelloPacket::getDesignatedRouter() const
{
    return this->designatedRouter;
}

void Ospfv2HelloPacket::setDesignatedRouter(const Ipv4Address& designatedRouter)
{
    handleChange();
    this->designatedRouter = designatedRouter;
}

const Ipv4Address& Ospfv2HelloPacket::getBackupDesignatedRouter() const
{
    return this->backupDesignatedRouter;
}

void Ospfv2HelloPacket::setBackupDesignatedRouter(const Ipv4Address& backupDesignatedRouter)
{
    handleChange();
    this->backupDesignatedRouter = backupDesignatedRouter;
}

size_t Ospfv2HelloPacket::getNeighborArraySize() const
{
    return neighbor_arraysize;
}

const Ipv4Address& Ospfv2HelloPacket::getNeighbor(size_t k) const
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size neighbor_arraysize indexed by %lu", (unsigned long)k);
    return this->neighbor[k];
}

void Ospfv2HelloPacket::setNeighborArraySize(size_t newSize)
{
    handleChange();
    Ipv4Address *neighbor2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = neighbor_arraysize < newSize ? neighbor_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighbor2[i] = this->neighbor[i];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

void Ospfv2HelloPacket::setNeighbor(size_t k, const Ipv4Address& neighbor)
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->neighbor[k] = neighbor;
}

void Ospfv2HelloPacket::insertNeighbor(size_t k, const Ipv4Address& neighbor)
{
    if (k > neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = neighbor_arraysize + 1;
    Ipv4Address *neighbor2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbor2[i] = this->neighbor[i];
    neighbor2[k] = neighbor;
    for (i = k + 1; i < newSize; i++)
        neighbor2[i] = this->neighbor[i-1];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

void Ospfv2HelloPacket::insertNeighbor(const Ipv4Address& neighbor)
{
    insertNeighbor(neighbor_arraysize, neighbor);
}

void Ospfv2HelloPacket::eraseNeighbor(size_t k)
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = neighbor_arraysize - 1;
    Ipv4Address *neighbor2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbor2[i] = this->neighbor[i];
    for (i = k; i < newSize; i++)
        neighbor2[i] = this->neighbor[i+1];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

class Ospfv2HelloPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_helloInterval,
        FIELD_options,
        FIELD_routerPriority,
        FIELD_routerDeadInterval,
        FIELD_designatedRouter,
        FIELD_backupDesignatedRouter,
        FIELD_neighbor,
    };
  public:
    Ospfv2HelloPacketDescriptor();
    virtual ~Ospfv2HelloPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2HelloPacketDescriptor)

Ospfv2HelloPacketDescriptor::Ospfv2HelloPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2HelloPacket)), "inet::ospfv2::Ospfv2Packet")
{
    propertynames = nullptr;
}

Ospfv2HelloPacketDescriptor::~Ospfv2HelloPacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2HelloPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2HelloPacket *>(obj)!=nullptr;
}

const char **Ospfv2HelloPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2HelloPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2HelloPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Ospfv2HelloPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISEDITABLE,    // FIELD_helloInterval
        FD_ISCOMPOUND,    // FIELD_options
        FD_ISEDITABLE,    // FIELD_routerPriority
        FD_ISEDITABLE,    // FIELD_routerDeadInterval
        0,    // FIELD_designatedRouter
        0,    // FIELD_backupDesignatedRouter
        FD_ISARRAY | FD_ISRESIZABLE,    // FIELD_neighbor
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2HelloPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "helloInterval",
        "options",
        "routerPriority",
        "routerDeadInterval",
        "designatedRouter",
        "backupDesignatedRouter",
        "neighbor",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int Ospfv2HelloPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "helloInterval") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerPriority") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerDeadInterval") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "designatedRouter") == 0) return base+5;
    if (fieldName[0] == 'b' && strcmp(fieldName, "backupDesignatedRouter") == 0) return base+6;
    if (fieldName[0] == 'n' && strcmp(fieldName, "neighbor") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2HelloPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "short",    // FIELD_helloInterval
        "inet::ospfv2::Ospfv2Options",    // FIELD_options
        "char",    // FIELD_routerPriority
        "long",    // FIELD_routerDeadInterval
        "inet::Ipv4Address",    // FIELD_designatedRouter
        "inet::Ipv4Address",    // FIELD_backupDesignatedRouter
        "inet::Ipv4Address",    // FIELD_neighbor
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2HelloPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2HelloPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2HelloPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_neighbor: return pp->getNeighborArraySize();
        default: return 0;
    }
}

void Ospfv2HelloPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_neighbor: pp->setNeighborArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2HelloPacket'", field);
    }
}

const char *Ospfv2HelloPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2HelloPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_helloInterval: return long2string(pp->getHelloInterval());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case FIELD_routerPriority: return long2string(pp->getRouterPriority());
        case FIELD_routerDeadInterval: return long2string(pp->getRouterDeadInterval());
        case FIELD_designatedRouter: return pp->getDesignatedRouter().str();
        case FIELD_backupDesignatedRouter: return pp->getBackupDesignatedRouter().str();
        case FIELD_neighbor: return pp->getNeighbor(i).str();
        default: return "";
    }
}

void Ospfv2HelloPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_helloInterval: pp->setHelloInterval(string2long(value)); break;
        case FIELD_routerPriority: pp->setRouterPriority(string2long(value)); break;
        case FIELD_routerDeadInterval: pp->setRouterDeadInterval(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2HelloPacket'", field);
    }
}

const char *Ospfv2HelloPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ospfv2Options));
        default: return nullptr;
    };
}

void *Ospfv2HelloPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        case FIELD_designatedRouter: return toVoidPtr(&pp->getDesignatedRouter()); break;
        case FIELD_backupDesignatedRouter: return toVoidPtr(&pp->getBackupDesignatedRouter()); break;
        case FIELD_neighbor: return toVoidPtr(&pp->getNeighbor(i)); break;
        default: return nullptr;
    }
}

void Ospfv2HelloPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2HelloPacket *pp = (Ospfv2HelloPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2HelloPacket'", field);
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospfv2::Ospfv2LsaType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospfv2::Ospfv2LsaType"));
    e->insert(ROUTERLSA_TYPE, "ROUTERLSA_TYPE");
    e->insert(NETWORKLSA_TYPE, "NETWORKLSA_TYPE");
    e->insert(SUMMARYLSA_NETWORKS_TYPE, "SUMMARYLSA_NETWORKS_TYPE");
    e->insert(SUMMARYLSA_ASBOUNDARYROUTERS_TYPE, "SUMMARYLSA_ASBOUNDARYROUTERS_TYPE");
    e->insert(AS_EXTERNAL_LSA_TYPE, "AS_EXTERNAL_LSA_TYPE");
)

Register_Class(Ospfv2LsaHeader)

Ospfv2LsaHeader::Ospfv2LsaHeader() : ::omnetpp::cObject()
{
}

Ospfv2LsaHeader::Ospfv2LsaHeader(const Ospfv2LsaHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ospfv2LsaHeader::~Ospfv2LsaHeader()
{
}

Ospfv2LsaHeader& Ospfv2LsaHeader::operator=(const Ospfv2LsaHeader& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2LsaHeader::copy(const Ospfv2LsaHeader& other)
{
    this->lsAge = other.lsAge;
    this->lsOptions = other.lsOptions;
    this->lsType = other.lsType;
    this->linkStateID = other.linkStateID;
    this->advertisingRouter = other.advertisingRouter;
    this->lsSequenceNumber = other.lsSequenceNumber;
    this->lsCrc = other.lsCrc;
    this->lsCrcMode = other.lsCrcMode;
    this->lsaLength = other.lsaLength;
}

void Ospfv2LsaHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->lsAge);
    doParsimPacking(b,this->lsOptions);
    doParsimPacking(b,this->lsType);
    doParsimPacking(b,this->linkStateID);
    doParsimPacking(b,this->advertisingRouter);
    doParsimPacking(b,this->lsSequenceNumber);
    doParsimPacking(b,this->lsCrc);
    doParsimPacking(b,this->lsCrcMode);
    doParsimPacking(b,this->lsaLength);
}

void Ospfv2LsaHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->lsAge);
    doParsimUnpacking(b,this->lsOptions);
    doParsimUnpacking(b,this->lsType);
    doParsimUnpacking(b,this->linkStateID);
    doParsimUnpacking(b,this->advertisingRouter);
    doParsimUnpacking(b,this->lsSequenceNumber);
    doParsimUnpacking(b,this->lsCrc);
    doParsimUnpacking(b,this->lsCrcMode);
    doParsimUnpacking(b,this->lsaLength);
}

unsigned short Ospfv2LsaHeader::getLsAge() const
{
    return this->lsAge;
}

void Ospfv2LsaHeader::setLsAge(unsigned short lsAge)
{
    this->lsAge = lsAge;
}

const Ospfv2Options& Ospfv2LsaHeader::getLsOptions() const
{
    return this->lsOptions;
}

void Ospfv2LsaHeader::setLsOptions(const Ospfv2Options& lsOptions)
{
    this->lsOptions = lsOptions;
}

inet::ospfv2::Ospfv2LsaType Ospfv2LsaHeader::getLsType() const
{
    return this->lsType;
}

void Ospfv2LsaHeader::setLsType(inet::ospfv2::Ospfv2LsaType lsType)
{
    this->lsType = lsType;
}

const Ipv4Address& Ospfv2LsaHeader::getLinkStateID() const
{
    return this->linkStateID;
}

void Ospfv2LsaHeader::setLinkStateID(const Ipv4Address& linkStateID)
{
    this->linkStateID = linkStateID;
}

const Ipv4Address& Ospfv2LsaHeader::getAdvertisingRouter() const
{
    return this->advertisingRouter;
}

void Ospfv2LsaHeader::setAdvertisingRouter(const Ipv4Address& advertisingRouter)
{
    this->advertisingRouter = advertisingRouter;
}

int32_t Ospfv2LsaHeader::getLsSequenceNumber() const
{
    return this->lsSequenceNumber;
}

void Ospfv2LsaHeader::setLsSequenceNumber(int32_t lsSequenceNumber)
{
    this->lsSequenceNumber = lsSequenceNumber;
}

uint16_t Ospfv2LsaHeader::getLsCrc() const
{
    return this->lsCrc;
}

void Ospfv2LsaHeader::setLsCrc(uint16_t lsCrc)
{
    this->lsCrc = lsCrc;
}

inet::CrcMode Ospfv2LsaHeader::getLsCrcMode() const
{
    return this->lsCrcMode;
}

void Ospfv2LsaHeader::setLsCrcMode(inet::CrcMode lsCrcMode)
{
    this->lsCrcMode = lsCrcMode;
}

uint16_t Ospfv2LsaHeader::getLsaLength() const
{
    return this->lsaLength;
}

void Ospfv2LsaHeader::setLsaLength(uint16_t lsaLength)
{
    this->lsaLength = lsaLength;
}

class Ospfv2LsaHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsAge,
        FIELD_lsOptions,
        FIELD_lsType,
        FIELD_linkStateID,
        FIELD_advertisingRouter,
        FIELD_lsSequenceNumber,
        FIELD_lsCrc,
        FIELD_lsCrcMode,
        FIELD_lsaLength,
    };
  public:
    Ospfv2LsaHeaderDescriptor();
    virtual ~Ospfv2LsaHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LsaHeaderDescriptor)

Ospfv2LsaHeaderDescriptor::Ospfv2LsaHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2LsaHeader)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ospfv2LsaHeaderDescriptor::~Ospfv2LsaHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LsaHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2LsaHeader *>(obj)!=nullptr;
}

const char **Ospfv2LsaHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LsaHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LsaHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ospfv2LsaHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lsAge
        FD_ISCOMPOUND,    // FIELD_lsOptions
        FD_ISEDITABLE,    // FIELD_lsType
        0,    // FIELD_linkStateID
        0,    // FIELD_advertisingRouter
        FD_ISEDITABLE,    // FIELD_lsSequenceNumber
        FD_ISEDITABLE,    // FIELD_lsCrc
        FD_ISEDITABLE,    // FIELD_lsCrcMode
        FD_ISEDITABLE,    // FIELD_lsaLength
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LsaHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsAge",
        "lsOptions",
        "lsType",
        "linkStateID",
        "advertisingRouter",
        "lsSequenceNumber",
        "lsCrc",
        "lsCrcMode",
        "lsaLength",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ospfv2LsaHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsAge") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsOptions") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsType") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkStateID") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertisingRouter") == 0) return base+4;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsSequenceNumber") == 0) return base+5;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsCrc") == 0) return base+6;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsCrcMode") == 0) return base+7;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaLength") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LsaHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_lsAge
        "inet::ospfv2::Ospfv2Options",    // FIELD_lsOptions
        "inet::ospfv2::Ospfv2LsaType",    // FIELD_lsType
        "inet::Ipv4Address",    // FIELD_linkStateID
        "inet::Ipv4Address",    // FIELD_advertisingRouter
        "int32_t",    // FIELD_lsSequenceNumber
        "uint16_t",    // FIELD_lsCrc
        "inet::CrcMode",    // FIELD_lsCrcMode
        "uint16_t",    // FIELD_lsaLength
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LsaHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_lsCrcMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ospfv2LsaHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsType:
            if (!strcmp(propertyname, "enum")) return "inet::ospfv2::Ospfv2LsaType";
            return nullptr;
        case FIELD_lsCrcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int Ospfv2LsaHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2LsaHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2LsaHeader'", field);
    }
}

const char *Ospfv2LsaHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LsaHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsAge: return ulong2string(pp->getLsAge());
        case FIELD_lsOptions: {std::stringstream out; out << pp->getLsOptions(); return out.str();}
        case FIELD_lsType: return enum2string(pp->getLsType(), "inet::ospfv2::Ospfv2LsaType");
        case FIELD_linkStateID: return pp->getLinkStateID().str();
        case FIELD_advertisingRouter: return pp->getAdvertisingRouter().str();
        case FIELD_lsSequenceNumber: return long2string(pp->getLsSequenceNumber());
        case FIELD_lsCrc: return ulong2string(pp->getLsCrc());
        case FIELD_lsCrcMode: return enum2string(pp->getLsCrcMode(), "inet::CrcMode");
        case FIELD_lsaLength: return ulong2string(pp->getLsaLength());
        default: return "";
    }
}

void Ospfv2LsaHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsAge: pp->setLsAge(string2ulong(value)); break;
        case FIELD_lsType: pp->setLsType((inet::ospfv2::Ospfv2LsaType)string2enum(value, "inet::ospfv2::Ospfv2LsaType")); break;
        case FIELD_lsSequenceNumber: pp->setLsSequenceNumber(string2long(value)); break;
        case FIELD_lsCrc: pp->setLsCrc(string2ulong(value)); break;
        case FIELD_lsCrcMode: pp->setLsCrcMode((inet::CrcMode)string2enum(value, "inet::CrcMode")); break;
        case FIELD_lsaLength: pp->setLsaLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LsaHeader'", field);
    }
}

const char *Ospfv2LsaHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsOptions: return omnetpp::opp_typename(typeid(Ospfv2Options));
        default: return nullptr;
    };
}

void *Ospfv2LsaHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsOptions: return toVoidPtr(&pp->getLsOptions()); break;
        case FIELD_linkStateID: return toVoidPtr(&pp->getLinkStateID()); break;
        case FIELD_advertisingRouter: return toVoidPtr(&pp->getAdvertisingRouter()); break;
        default: return nullptr;
    }
}

void Ospfv2LsaHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaHeader *pp = (Ospfv2LsaHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LsaHeader'", field);
    }
}

Register_Class(Ospfv2Lsa)

Ospfv2Lsa::Ospfv2Lsa() : ::omnetpp::cObject()
{
}

Ospfv2Lsa::Ospfv2Lsa(const Ospfv2Lsa& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ospfv2Lsa::~Ospfv2Lsa()
{
}

Ospfv2Lsa& Ospfv2Lsa::operator=(const Ospfv2Lsa& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2Lsa::copy(const Ospfv2Lsa& other)
{
    this->header = other.header;
}

void Ospfv2Lsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->header);
}

void Ospfv2Lsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->header);
}

const Ospfv2LsaHeader& Ospfv2Lsa::getHeader() const
{
    return this->header;
}

void Ospfv2Lsa::setHeader(const Ospfv2LsaHeader& header)
{
    this->header = header;
}

class Ospfv2LsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_header,
    };
  public:
    Ospfv2LsaDescriptor();
    virtual ~Ospfv2LsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LsaDescriptor)

Ospfv2LsaDescriptor::Ospfv2LsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2Lsa)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ospfv2LsaDescriptor::~Ospfv2LsaDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2Lsa *>(obj)!=nullptr;
}

const char **Ospfv2LsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ospfv2LsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_header
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ospfv2LsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "header") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospfv2::Ospfv2LsaHeader",    // FIELD_header
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2LsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2LsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2LsaDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2Lsa'", field);
    }
}

const char *Ospfv2LsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        case FIELD_header: {std::stringstream out; out << pp->getHeader(); return out.str();}
        default: return "";
    }
}

void Ospfv2LsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Lsa'", field);
    }
}

const char *Ospfv2LsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header: return omnetpp::opp_typename(typeid(Ospfv2LsaHeader));
        default: return nullptr;
    };
}

void *Ospfv2LsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        case FIELD_header: return toVoidPtr(&pp->getHeader()); break;
        default: return nullptr;
    }
}

void Ospfv2LsaDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Lsa *pp = (Ospfv2Lsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Lsa'", field);
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospfv2::LinkType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospfv2::LinkType"));
    e->insert(POINTTOPOINT_LINK, "POINTTOPOINT_LINK");
    e->insert(TRANSIT_LINK, "TRANSIT_LINK");
    e->insert(STUB_LINK, "STUB_LINK");
    e->insert(VIRTUAL_LINK, "VIRTUAL_LINK");
)

Ospfv2TosData::Ospfv2TosData()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Ospfv2TosData& a)
{
    doParsimPacking(b,a.tos);
    doParsimPacking(b,a.tosMetric);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ospfv2TosData& a)
{
    doParsimUnpacking(b,a.tos);
    doParsimUnpacking(b,a.tosMetric);
}

class Ospfv2TosDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tos,
        FIELD_tosMetric,
    };
  public:
    Ospfv2TosDataDescriptor();
    virtual ~Ospfv2TosDataDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2TosDataDescriptor)

Ospfv2TosDataDescriptor::Ospfv2TosDataDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2TosData)), "")
{
    propertynames = nullptr;
}

Ospfv2TosDataDescriptor::~Ospfv2TosDataDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2TosDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2TosData *>(obj)!=nullptr;
}

const char **Ospfv2TosDataDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2TosDataDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2TosDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ospfv2TosDataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tos
        FD_ISEDITABLE,    // FIELD_tosMetric
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2TosDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
        "tosMetric",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ospfv2TosDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tos") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosMetric") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2TosDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_tos
        "unsigned long",    // FIELD_tosMetric
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2TosDataDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2TosDataDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2TosDataDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2TosDataDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2TosData'", field);
    }
}

const char *Ospfv2TosDataDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2TosDataDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        case FIELD_tos: return ulong2string(pp->tos);
        case FIELD_tosMetric: return ulong2string(pp->tosMetric);
        default: return "";
    }
}

void Ospfv2TosDataDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        case FIELD_tos: pp->tos = string2ulong(value); break;
        case FIELD_tosMetric: pp->tosMetric = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2TosData'", field);
    }
}

const char *Ospfv2TosDataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2TosDataDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ospfv2TosDataDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2TosData *pp = (Ospfv2TosData *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2TosData'", field);
    }
}

Register_Class(Ospfv2Link)

Ospfv2Link::Ospfv2Link() : ::omnetpp::cObject()
{
}

Ospfv2Link::Ospfv2Link(const Ospfv2Link& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ospfv2Link::~Ospfv2Link()
{
    delete [] this->tosData;
}

Ospfv2Link& Ospfv2Link::operator=(const Ospfv2Link& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2Link::copy(const Ospfv2Link& other)
{
    this->linkID = other.linkID;
    this->linkData = other.linkData;
    this->type = other.type;
    this->numberOfTOS = other.numberOfTOS;
    this->linkCost = other.linkCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new Ospfv2TosData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (size_t i = 0; i < tosData_arraysize; i++) {
        this->tosData[i] = other.tosData[i];
    }
}

void Ospfv2Link::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->linkID);
    doParsimPacking(b,this->linkData);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->numberOfTOS);
    doParsimPacking(b,this->linkCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void Ospfv2Link::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->linkID);
    doParsimUnpacking(b,this->linkData);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->numberOfTOS);
    doParsimUnpacking(b,this->linkCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize == 0) {
        this->tosData = nullptr;
    } else {
        this->tosData = new Ospfv2TosData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

const Ipv4Address& Ospfv2Link::getLinkID() const
{
    return this->linkID;
}

void Ospfv2Link::setLinkID(const Ipv4Address& linkID)
{
    this->linkID = linkID;
}

unsigned long Ospfv2Link::getLinkData() const
{
    return this->linkData;
}

void Ospfv2Link::setLinkData(unsigned long linkData)
{
    this->linkData = linkData;
}

inet::ospfv2::LinkType Ospfv2Link::getType() const
{
    return this->type;
}

void Ospfv2Link::setType(inet::ospfv2::LinkType type)
{
    this->type = type;
}

unsigned char Ospfv2Link::getNumberOfTOS() const
{
    return this->numberOfTOS;
}

void Ospfv2Link::setNumberOfTOS(unsigned char numberOfTOS)
{
    this->numberOfTOS = numberOfTOS;
}

unsigned long Ospfv2Link::getLinkCost() const
{
    return this->linkCost;
}

void Ospfv2Link::setLinkCost(unsigned long linkCost)
{
    this->linkCost = linkCost;
}

size_t Ospfv2Link::getTosDataArraySize() const
{
    return tosData_arraysize;
}

const Ospfv2TosData& Ospfv2Link::getTosData(size_t k) const
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size tosData_arraysize indexed by %lu", (unsigned long)k);
    return this->tosData[k];
}

void Ospfv2Link::setTosDataArraySize(size_t newSize)
{
    Ospfv2TosData *tosData2 = (newSize==0) ? nullptr : new Ospfv2TosData[newSize];
    size_t minSize = tosData_arraysize < newSize ? tosData_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        tosData2[i] = this->tosData[i];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Ospfv2Link::setTosData(size_t k, const Ospfv2TosData& tosData)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->tosData[k] = tosData;
}

void Ospfv2Link::insertTosData(size_t k, const Ospfv2TosData& tosData)
{
    if (k > tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize + 1;
    Ospfv2TosData *tosData2 = new Ospfv2TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    tosData2[k] = tosData;
    for (i = k + 1; i < newSize; i++)
        tosData2[i] = this->tosData[i-1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Ospfv2Link::insertTosData(const Ospfv2TosData& tosData)
{
    insertTosData(tosData_arraysize, tosData);
}

void Ospfv2Link::eraseTosData(size_t k)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize - 1;
    Ospfv2TosData *tosData2 = (newSize == 0) ? nullptr : new Ospfv2TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    for (i = k; i < newSize; i++)
        tosData2[i] = this->tosData[i+1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

class Ospfv2LinkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_linkID,
        FIELD_linkData,
        FIELD_type,
        FIELD_numberOfTOS,
        FIELD_linkCost,
        FIELD_tosData,
    };
  public:
    Ospfv2LinkDescriptor();
    virtual ~Ospfv2LinkDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LinkDescriptor)

Ospfv2LinkDescriptor::Ospfv2LinkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2Link)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ospfv2LinkDescriptor::~Ospfv2LinkDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LinkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2Link *>(obj)!=nullptr;
}

const char **Ospfv2LinkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LinkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LinkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ospfv2LinkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_linkID
        FD_ISEDITABLE,    // FIELD_linkData
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_numberOfTOS
        FD_ISEDITABLE,    // FIELD_linkCost
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_tosData
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LinkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "linkID",
        "linkData",
        "type",
        "numberOfTOS",
        "linkCost",
        "tosData",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ospfv2LinkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkID") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkData") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfTOS") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkCost") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosData") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LinkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_linkID
        "unsigned long",    // FIELD_linkData
        "inet::ospfv2::LinkType",    // FIELD_type
        "unsigned char",    // FIELD_numberOfTOS
        "unsigned long",    // FIELD_linkCost
        "inet::ospfv2::Ospfv2TosData",    // FIELD_tosData
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LinkDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ospfv2LinkDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::ospfv2::LinkType";
            return nullptr;
        default: return nullptr;
    }
}

int Ospfv2LinkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: return pp->getTosDataArraySize();
        default: return 0;
    }
}

void Ospfv2LinkDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: pp->setTosDataArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2Link'", field);
    }
}

const char *Ospfv2LinkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LinkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkID: return pp->getLinkID().str();
        case FIELD_linkData: return ulong2string(pp->getLinkData());
        case FIELD_type: return enum2string(pp->getType(), "inet::ospfv2::LinkType");
        case FIELD_numberOfTOS: return ulong2string(pp->getNumberOfTOS());
        case FIELD_linkCost: return ulong2string(pp->getLinkCost());
        case FIELD_tosData: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

void Ospfv2LinkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkData: pp->setLinkData(string2ulong(value)); break;
        case FIELD_type: pp->setType((inet::ospfv2::LinkType)string2enum(value, "inet::ospfv2::LinkType")); break;
        case FIELD_numberOfTOS: pp->setNumberOfTOS(string2ulong(value)); break;
        case FIELD_linkCost: pp->setLinkCost(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Link'", field);
    }
}

const char *Ospfv2LinkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tosData: return omnetpp::opp_typename(typeid(Ospfv2TosData));
        default: return nullptr;
    };
}

void *Ospfv2LinkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkID: return toVoidPtr(&pp->getLinkID()); break;
        case FIELD_tosData: return toVoidPtr(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

void Ospfv2LinkDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2Link *pp = (Ospfv2Link *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2Link'", field);
    }
}

Register_Class(Ospfv2RouterLsa)

Ospfv2RouterLsa::Ospfv2RouterLsa() : ::inet::ospfv2::Ospfv2Lsa()
{
}

Ospfv2RouterLsa::Ospfv2RouterLsa(const Ospfv2RouterLsa& other) : ::inet::ospfv2::Ospfv2Lsa(other)
{
    copy(other);
}

Ospfv2RouterLsa::~Ospfv2RouterLsa()
{
    delete [] this->links;
}

Ospfv2RouterLsa& Ospfv2RouterLsa::operator=(const Ospfv2RouterLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Lsa::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2RouterLsa::copy(const Ospfv2RouterLsa& other)
{
    this->reserved1 = other.reserved1;
    this->V_VirtualLinkEndpoint = other.V_VirtualLinkEndpoint;
    this->E_ASBoundaryRouter = other.E_ASBoundaryRouter;
    this->B_AreaBorderRouter = other.B_AreaBorderRouter;
    this->reserved2 = other.reserved2;
    this->numberOfLinks = other.numberOfLinks;
    delete [] this->links;
    this->links = (other.links_arraysize==0) ? nullptr : new Ospfv2Link[other.links_arraysize];
    links_arraysize = other.links_arraysize;
    for (size_t i = 0; i < links_arraysize; i++) {
        this->links[i] = other.links[i];
    }
}

void Ospfv2RouterLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Lsa::parsimPack(b);
    doParsimPacking(b,this->reserved1);
    doParsimPacking(b,this->V_VirtualLinkEndpoint);
    doParsimPacking(b,this->E_ASBoundaryRouter);
    doParsimPacking(b,this->B_AreaBorderRouter);
    doParsimPacking(b,this->reserved2);
    doParsimPacking(b,this->numberOfLinks);
    b->pack(links_arraysize);
    doParsimArrayPacking(b,this->links,links_arraysize);
}

void Ospfv2RouterLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Lsa::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved1);
    doParsimUnpacking(b,this->V_VirtualLinkEndpoint);
    doParsimUnpacking(b,this->E_ASBoundaryRouter);
    doParsimUnpacking(b,this->B_AreaBorderRouter);
    doParsimUnpacking(b,this->reserved2);
    doParsimUnpacking(b,this->numberOfLinks);
    delete [] this->links;
    b->unpack(links_arraysize);
    if (links_arraysize == 0) {
        this->links = nullptr;
    } else {
        this->links = new Ospfv2Link[links_arraysize];
        doParsimArrayUnpacking(b,this->links,links_arraysize);
    }
}

unsigned short Ospfv2RouterLsa::getReserved1() const
{
    return this->reserved1;
}

void Ospfv2RouterLsa::setReserved1(unsigned short reserved1)
{
    this->reserved1 = reserved1;
}

bool Ospfv2RouterLsa::getV_VirtualLinkEndpoint() const
{
    return this->V_VirtualLinkEndpoint;
}

void Ospfv2RouterLsa::setV_VirtualLinkEndpoint(bool V_VirtualLinkEndpoint)
{
    this->V_VirtualLinkEndpoint = V_VirtualLinkEndpoint;
}

bool Ospfv2RouterLsa::getE_ASBoundaryRouter() const
{
    return this->E_ASBoundaryRouter;
}

void Ospfv2RouterLsa::setE_ASBoundaryRouter(bool E_ASBoundaryRouter)
{
    this->E_ASBoundaryRouter = E_ASBoundaryRouter;
}

bool Ospfv2RouterLsa::getB_AreaBorderRouter() const
{
    return this->B_AreaBorderRouter;
}

void Ospfv2RouterLsa::setB_AreaBorderRouter(bool B_AreaBorderRouter)
{
    this->B_AreaBorderRouter = B_AreaBorderRouter;
}

unsigned short Ospfv2RouterLsa::getReserved2() const
{
    return this->reserved2;
}

void Ospfv2RouterLsa::setReserved2(unsigned short reserved2)
{
    this->reserved2 = reserved2;
}

unsigned short Ospfv2RouterLsa::getNumberOfLinks() const
{
    return this->numberOfLinks;
}

void Ospfv2RouterLsa::setNumberOfLinks(unsigned short numberOfLinks)
{
    this->numberOfLinks = numberOfLinks;
}

size_t Ospfv2RouterLsa::getLinksArraySize() const
{
    return links_arraysize;
}

const Ospfv2Link& Ospfv2RouterLsa::getLinks(size_t k) const
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size links_arraysize indexed by %lu", (unsigned long)k);
    return this->links[k];
}

void Ospfv2RouterLsa::setLinksArraySize(size_t newSize)
{
    Ospfv2Link *links2 = (newSize==0) ? nullptr : new Ospfv2Link[newSize];
    size_t minSize = links_arraysize < newSize ? links_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        links2[i] = this->links[i];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

void Ospfv2RouterLsa::setLinks(size_t k, const Ospfv2Link& links)
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->links[k] = links;
}

void Ospfv2RouterLsa::insertLinks(size_t k, const Ospfv2Link& links)
{
    if (k > links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = links_arraysize + 1;
    Ospfv2Link *links2 = new Ospfv2Link[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        links2[i] = this->links[i];
    links2[k] = links;
    for (i = k + 1; i < newSize; i++)
        links2[i] = this->links[i-1];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

void Ospfv2RouterLsa::insertLinks(const Ospfv2Link& links)
{
    insertLinks(links_arraysize, links);
}

void Ospfv2RouterLsa::eraseLinks(size_t k)
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = links_arraysize - 1;
    Ospfv2Link *links2 = (newSize == 0) ? nullptr : new Ospfv2Link[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        links2[i] = this->links[i];
    for (i = k; i < newSize; i++)
        links2[i] = this->links[i+1];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

class Ospfv2RouterLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved1,
        FIELD_V_VirtualLinkEndpoint,
        FIELD_E_ASBoundaryRouter,
        FIELD_B_AreaBorderRouter,
        FIELD_reserved2,
        FIELD_numberOfLinks,
        FIELD_links,
    };
  public:
    Ospfv2RouterLsaDescriptor();
    virtual ~Ospfv2RouterLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2RouterLsaDescriptor)

Ospfv2RouterLsaDescriptor::Ospfv2RouterLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2RouterLsa)), "inet::ospfv2::Ospfv2Lsa")
{
    propertynames = nullptr;
}

Ospfv2RouterLsaDescriptor::~Ospfv2RouterLsaDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2RouterLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2RouterLsa *>(obj)!=nullptr;
}

const char **Ospfv2RouterLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2RouterLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2RouterLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int Ospfv2RouterLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved1
        FD_ISEDITABLE,    // FIELD_V_VirtualLinkEndpoint
        FD_ISEDITABLE,    // FIELD_E_ASBoundaryRouter
        FD_ISEDITABLE,    // FIELD_B_AreaBorderRouter
        FD_ISEDITABLE,    // FIELD_reserved2
        FD_ISEDITABLE,    // FIELD_numberOfLinks
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISRESIZABLE,    // FIELD_links
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2RouterLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved1",
        "V_VirtualLinkEndpoint",
        "E_ASBoundaryRouter",
        "B_AreaBorderRouter",
        "reserved2",
        "numberOfLinks",
        "links",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int Ospfv2RouterLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved1") == 0) return base+0;
    if (fieldName[0] == 'V' && strcmp(fieldName, "V_VirtualLinkEndpoint") == 0) return base+1;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ASBoundaryRouter") == 0) return base+2;
    if (fieldName[0] == 'B' && strcmp(fieldName, "B_AreaBorderRouter") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved2") == 0) return base+4;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfLinks") == 0) return base+5;
    if (fieldName[0] == 'l' && strcmp(fieldName, "links") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2RouterLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_reserved1
        "bool",    // FIELD_V_VirtualLinkEndpoint
        "bool",    // FIELD_E_ASBoundaryRouter
        "bool",    // FIELD_B_AreaBorderRouter
        "unsigned short",    // FIELD_reserved2
        "unsigned short",    // FIELD_numberOfLinks
        "inet::ospfv2::Ospfv2Link",    // FIELD_links
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2RouterLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2RouterLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2RouterLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_links: return pp->getLinksArraySize();
        default: return 0;
    }
}

void Ospfv2RouterLsaDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_links: pp->setLinksArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2RouterLsa'", field);
    }
}

const char *Ospfv2RouterLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2RouterLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_reserved1: return ulong2string(pp->getReserved1());
        case FIELD_V_VirtualLinkEndpoint: return bool2string(pp->getV_VirtualLinkEndpoint());
        case FIELD_E_ASBoundaryRouter: return bool2string(pp->getE_ASBoundaryRouter());
        case FIELD_B_AreaBorderRouter: return bool2string(pp->getB_AreaBorderRouter());
        case FIELD_reserved2: return ulong2string(pp->getReserved2());
        case FIELD_numberOfLinks: return ulong2string(pp->getNumberOfLinks());
        case FIELD_links: {std::stringstream out; out << pp->getLinks(i); return out.str();}
        default: return "";
    }
}

void Ospfv2RouterLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_reserved1: pp->setReserved1(string2ulong(value)); break;
        case FIELD_V_VirtualLinkEndpoint: pp->setV_VirtualLinkEndpoint(string2bool(value)); break;
        case FIELD_E_ASBoundaryRouter: pp->setE_ASBoundaryRouter(string2bool(value)); break;
        case FIELD_B_AreaBorderRouter: pp->setB_AreaBorderRouter(string2bool(value)); break;
        case FIELD_reserved2: pp->setReserved2(string2ulong(value)); break;
        case FIELD_numberOfLinks: pp->setNumberOfLinks(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2RouterLsa'", field);
    }
}

const char *Ospfv2RouterLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_links: return omnetpp::opp_typename(typeid(Ospfv2Link));
        default: return nullptr;
    };
}

void *Ospfv2RouterLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_links: return toVoidPtr(&pp->getLinks(i)); break;
        default: return nullptr;
    }
}

void Ospfv2RouterLsaDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2RouterLsa *pp = (Ospfv2RouterLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2RouterLsa'", field);
    }
}

Register_Class(Ospfv2NetworkLsa)

Ospfv2NetworkLsa::Ospfv2NetworkLsa() : ::inet::ospfv2::Ospfv2Lsa()
{
}

Ospfv2NetworkLsa::Ospfv2NetworkLsa(const Ospfv2NetworkLsa& other) : ::inet::ospfv2::Ospfv2Lsa(other)
{
    copy(other);
}

Ospfv2NetworkLsa::~Ospfv2NetworkLsa()
{
    delete [] this->attachedRouters;
}

Ospfv2NetworkLsa& Ospfv2NetworkLsa::operator=(const Ospfv2NetworkLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Lsa::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2NetworkLsa::copy(const Ospfv2NetworkLsa& other)
{
    this->networkMask = other.networkMask;
    delete [] this->attachedRouters;
    this->attachedRouters = (other.attachedRouters_arraysize==0) ? nullptr : new Ipv4Address[other.attachedRouters_arraysize];
    attachedRouters_arraysize = other.attachedRouters_arraysize;
    for (size_t i = 0; i < attachedRouters_arraysize; i++) {
        this->attachedRouters[i] = other.attachedRouters[i];
    }
}

void Ospfv2NetworkLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Lsa::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    b->pack(attachedRouters_arraysize);
    doParsimArrayPacking(b,this->attachedRouters,attachedRouters_arraysize);
}

void Ospfv2NetworkLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Lsa::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    delete [] this->attachedRouters;
    b->unpack(attachedRouters_arraysize);
    if (attachedRouters_arraysize == 0) {
        this->attachedRouters = nullptr;
    } else {
        this->attachedRouters = new Ipv4Address[attachedRouters_arraysize];
        doParsimArrayUnpacking(b,this->attachedRouters,attachedRouters_arraysize);
    }
}

const Ipv4Address& Ospfv2NetworkLsa::getNetworkMask() const
{
    return this->networkMask;
}

void Ospfv2NetworkLsa::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

size_t Ospfv2NetworkLsa::getAttachedRoutersArraySize() const
{
    return attachedRouters_arraysize;
}

const Ipv4Address& Ospfv2NetworkLsa::getAttachedRouters(size_t k) const
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size attachedRouters_arraysize indexed by %lu", (unsigned long)k);
    return this->attachedRouters[k];
}

void Ospfv2NetworkLsa::setAttachedRoutersArraySize(size_t newSize)
{
    Ipv4Address *attachedRouters2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = attachedRouters_arraysize < newSize ? attachedRouters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

void Ospfv2NetworkLsa::setAttachedRouters(size_t k, const Ipv4Address& attachedRouters)
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->attachedRouters[k] = attachedRouters;
}

void Ospfv2NetworkLsa::insertAttachedRouters(size_t k, const Ipv4Address& attachedRouters)
{
    if (k > attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = attachedRouters_arraysize + 1;
    Ipv4Address *attachedRouters2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    attachedRouters2[k] = attachedRouters;
    for (i = k + 1; i < newSize; i++)
        attachedRouters2[i] = this->attachedRouters[i-1];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

void Ospfv2NetworkLsa::insertAttachedRouters(const Ipv4Address& attachedRouters)
{
    insertAttachedRouters(attachedRouters_arraysize, attachedRouters);
}

void Ospfv2NetworkLsa::eraseAttachedRouters(size_t k)
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = attachedRouters_arraysize - 1;
    Ipv4Address *attachedRouters2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    for (i = k; i < newSize; i++)
        attachedRouters2[i] = this->attachedRouters[i+1];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

class Ospfv2NetworkLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_attachedRouters,
    };
  public:
    Ospfv2NetworkLsaDescriptor();
    virtual ~Ospfv2NetworkLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2NetworkLsaDescriptor)

Ospfv2NetworkLsaDescriptor::Ospfv2NetworkLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2NetworkLsa)), "inet::ospfv2::Ospfv2Lsa")
{
    propertynames = nullptr;
}

Ospfv2NetworkLsaDescriptor::~Ospfv2NetworkLsaDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2NetworkLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2NetworkLsa *>(obj)!=nullptr;
}

const char **Ospfv2NetworkLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2NetworkLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2NetworkLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ospfv2NetworkLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISARRAY | FD_ISRESIZABLE,    // FIELD_attachedRouters
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2NetworkLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "attachedRouters",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ospfv2NetworkLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "attachedRouters") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2NetworkLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "inet::Ipv4Address",    // FIELD_attachedRouters
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2NetworkLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2NetworkLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2NetworkLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_attachedRouters: return pp->getAttachedRoutersArraySize();
        default: return 0;
    }
}

void Ospfv2NetworkLsaDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_attachedRouters: pp->setAttachedRoutersArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2NetworkLsa'", field);
    }
}

const char *Ospfv2NetworkLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2NetworkLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_attachedRouters: return pp->getAttachedRouters(i).str();
        default: return "";
    }
}

void Ospfv2NetworkLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2NetworkLsa'", field);
    }
}

const char *Ospfv2NetworkLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2NetworkLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_attachedRouters: return toVoidPtr(&pp->getAttachedRouters(i)); break;
        default: return nullptr;
    }
}

void Ospfv2NetworkLsaDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2NetworkLsa *pp = (Ospfv2NetworkLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2NetworkLsa'", field);
    }
}

Register_Class(Ospfv2SummaryLsa)

Ospfv2SummaryLsa::Ospfv2SummaryLsa() : ::inet::ospfv2::Ospfv2Lsa()
{
}

Ospfv2SummaryLsa::Ospfv2SummaryLsa(const Ospfv2SummaryLsa& other) : ::inet::ospfv2::Ospfv2Lsa(other)
{
    copy(other);
}

Ospfv2SummaryLsa::~Ospfv2SummaryLsa()
{
    delete [] this->tosData;
}

Ospfv2SummaryLsa& Ospfv2SummaryLsa::operator=(const Ospfv2SummaryLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Lsa::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2SummaryLsa::copy(const Ospfv2SummaryLsa& other)
{
    this->networkMask = other.networkMask;
    this->routeCost = other.routeCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new Ospfv2TosData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (size_t i = 0; i < tosData_arraysize; i++) {
        this->tosData[i] = other.tosData[i];
    }
}

void Ospfv2SummaryLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Lsa::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->routeCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void Ospfv2SummaryLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Lsa::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->routeCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize == 0) {
        this->tosData = nullptr;
    } else {
        this->tosData = new Ospfv2TosData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

const Ipv4Address& Ospfv2SummaryLsa::getNetworkMask() const
{
    return this->networkMask;
}

void Ospfv2SummaryLsa::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

unsigned long Ospfv2SummaryLsa::getRouteCost() const
{
    return this->routeCost;
}

void Ospfv2SummaryLsa::setRouteCost(unsigned long routeCost)
{
    this->routeCost = routeCost;
}

size_t Ospfv2SummaryLsa::getTosDataArraySize() const
{
    return tosData_arraysize;
}

const Ospfv2TosData& Ospfv2SummaryLsa::getTosData(size_t k) const
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size tosData_arraysize indexed by %lu", (unsigned long)k);
    return this->tosData[k];
}

void Ospfv2SummaryLsa::setTosDataArraySize(size_t newSize)
{
    Ospfv2TosData *tosData2 = (newSize==0) ? nullptr : new Ospfv2TosData[newSize];
    size_t minSize = tosData_arraysize < newSize ? tosData_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        tosData2[i] = this->tosData[i];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Ospfv2SummaryLsa::setTosData(size_t k, const Ospfv2TosData& tosData)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->tosData[k] = tosData;
}

void Ospfv2SummaryLsa::insertTosData(size_t k, const Ospfv2TosData& tosData)
{
    if (k > tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize + 1;
    Ospfv2TosData *tosData2 = new Ospfv2TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    tosData2[k] = tosData;
    for (i = k + 1; i < newSize; i++)
        tosData2[i] = this->tosData[i-1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Ospfv2SummaryLsa::insertTosData(const Ospfv2TosData& tosData)
{
    insertTosData(tosData_arraysize, tosData);
}

void Ospfv2SummaryLsa::eraseTosData(size_t k)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize - 1;
    Ospfv2TosData *tosData2 = (newSize == 0) ? nullptr : new Ospfv2TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    for (i = k; i < newSize; i++)
        tosData2[i] = this->tosData[i+1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

class Ospfv2SummaryLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_routeCost,
        FIELD_tosData,
    };
  public:
    Ospfv2SummaryLsaDescriptor();
    virtual ~Ospfv2SummaryLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2SummaryLsaDescriptor)

Ospfv2SummaryLsaDescriptor::Ospfv2SummaryLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2SummaryLsa)), "inet::ospfv2::Ospfv2Lsa")
{
    propertynames = nullptr;
}

Ospfv2SummaryLsaDescriptor::~Ospfv2SummaryLsaDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2SummaryLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2SummaryLsa *>(obj)!=nullptr;
}

const char **Ospfv2SummaryLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2SummaryLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2SummaryLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ospfv2SummaryLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISEDITABLE,    // FIELD_routeCost
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_tosData
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2SummaryLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "routeCost",
        "tosData",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ospfv2SummaryLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routeCost") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosData") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2SummaryLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "unsigned long",    // FIELD_routeCost
        "inet::ospfv2::Ospfv2TosData",    // FIELD_tosData
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2SummaryLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2SummaryLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2SummaryLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: return pp->getTosDataArraySize();
        default: return 0;
    }
}

void Ospfv2SummaryLsaDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: pp->setTosDataArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2SummaryLsa'", field);
    }
}

const char *Ospfv2SummaryLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2SummaryLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_routeCost: return ulong2string(pp->getRouteCost());
        case FIELD_tosData: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

void Ospfv2SummaryLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_routeCost: pp->setRouteCost(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2SummaryLsa'", field);
    }
}

const char *Ospfv2SummaryLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tosData: return omnetpp::opp_typename(typeid(Ospfv2TosData));
        default: return nullptr;
    };
}

void *Ospfv2SummaryLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_tosData: return toVoidPtr(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

void Ospfv2SummaryLsaDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2SummaryLsa *pp = (Ospfv2SummaryLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2SummaryLsa'", field);
    }
}

Ospfv2ExternalTosInfo::Ospfv2ExternalTosInfo()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Ospfv2ExternalTosInfo& a)
{
    doParsimPacking(b,a.tos);
    doParsimPacking(b,a.E_ExternalMetricType);
    doParsimPacking(b,a.routeCost);
    doParsimPacking(b,a.forwardingAddress);
    doParsimPacking(b,a.externalRouteTag);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ospfv2ExternalTosInfo& a)
{
    doParsimUnpacking(b,a.tos);
    doParsimUnpacking(b,a.E_ExternalMetricType);
    doParsimUnpacking(b,a.routeCost);
    doParsimUnpacking(b,a.forwardingAddress);
    doParsimUnpacking(b,a.externalRouteTag);
}

class Ospfv2ExternalTosInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tos,
        FIELD_E_ExternalMetricType,
        FIELD_routeCost,
        FIELD_forwardingAddress,
        FIELD_externalRouteTag,
    };
  public:
    Ospfv2ExternalTosInfoDescriptor();
    virtual ~Ospfv2ExternalTosInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2ExternalTosInfoDescriptor)

Ospfv2ExternalTosInfoDescriptor::Ospfv2ExternalTosInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2ExternalTosInfo)), "")
{
    propertynames = nullptr;
}

Ospfv2ExternalTosInfoDescriptor::~Ospfv2ExternalTosInfoDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2ExternalTosInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2ExternalTosInfo *>(obj)!=nullptr;
}

const char **Ospfv2ExternalTosInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2ExternalTosInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2ExternalTosInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ospfv2ExternalTosInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tos
        FD_ISEDITABLE,    // FIELD_E_ExternalMetricType
        FD_ISEDITABLE,    // FIELD_routeCost
        0,    // FIELD_forwardingAddress
        FD_ISEDITABLE,    // FIELD_externalRouteTag
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2ExternalTosInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
        "E_ExternalMetricType",
        "routeCost",
        "forwardingAddress",
        "externalRouteTag",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ospfv2ExternalTosInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tos") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ExternalMetricType") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routeCost") == 0) return base+2;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardingAddress") == 0) return base+3;
    if (fieldName[0] == 'e' && strcmp(fieldName, "externalRouteTag") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2ExternalTosInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_tos
        "bool",    // FIELD_E_ExternalMetricType
        "unsigned long",    // FIELD_routeCost
        "inet::Ipv4Address",    // FIELD_forwardingAddress
        "long",    // FIELD_externalRouteTag
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2ExternalTosInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2ExternalTosInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2ExternalTosInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2ExternalTosInfoDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2ExternalTosInfo'", field);
    }
}

const char *Ospfv2ExternalTosInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2ExternalTosInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_tos: return ulong2string(pp->tos);
        case FIELD_E_ExternalMetricType: return bool2string(pp->E_ExternalMetricType);
        case FIELD_routeCost: return ulong2string(pp->routeCost);
        case FIELD_forwardingAddress: return pp->forwardingAddress.str();
        case FIELD_externalRouteTag: return long2string(pp->externalRouteTag);
        default: return "";
    }
}

void Ospfv2ExternalTosInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_tos: pp->tos = string2ulong(value); break;
        case FIELD_E_ExternalMetricType: pp->E_ExternalMetricType = string2bool(value); break;
        case FIELD_routeCost: pp->routeCost = string2ulong(value); break;
        case FIELD_externalRouteTag: pp->externalRouteTag = string2long(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2ExternalTosInfo'", field);
    }
}

const char *Ospfv2ExternalTosInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2ExternalTosInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_forwardingAddress: return toVoidPtr(&pp->forwardingAddress); break;
        default: return nullptr;
    }
}

void Ospfv2ExternalTosInfoDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2ExternalTosInfo *pp = (Ospfv2ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2ExternalTosInfo'", field);
    }
}

Register_Class(Ospfv2AsExternalLsaContents)

Ospfv2AsExternalLsaContents::Ospfv2AsExternalLsaContents() : ::omnetpp::cObject()
{
}

Ospfv2AsExternalLsaContents::Ospfv2AsExternalLsaContents(const Ospfv2AsExternalLsaContents& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ospfv2AsExternalLsaContents::~Ospfv2AsExternalLsaContents()
{
    delete [] this->externalTOSInfo;
}

Ospfv2AsExternalLsaContents& Ospfv2AsExternalLsaContents::operator=(const Ospfv2AsExternalLsaContents& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2AsExternalLsaContents::copy(const Ospfv2AsExternalLsaContents& other)
{
    this->networkMask = other.networkMask;
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = (other.externalTOSInfo_arraysize==0) ? nullptr : new Ospfv2ExternalTosInfo[other.externalTOSInfo_arraysize];
    externalTOSInfo_arraysize = other.externalTOSInfo_arraysize;
    for (size_t i = 0; i < externalTOSInfo_arraysize; i++) {
        this->externalTOSInfo[i] = other.externalTOSInfo[i];
    }
}

void Ospfv2AsExternalLsaContents::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->networkMask);
    b->pack(externalTOSInfo_arraysize);
    doParsimArrayPacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
}

void Ospfv2AsExternalLsaContents::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->networkMask);
    delete [] this->externalTOSInfo;
    b->unpack(externalTOSInfo_arraysize);
    if (externalTOSInfo_arraysize == 0) {
        this->externalTOSInfo = nullptr;
    } else {
        this->externalTOSInfo = new Ospfv2ExternalTosInfo[externalTOSInfo_arraysize];
        doParsimArrayUnpacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
    }
}

const Ipv4Address& Ospfv2AsExternalLsaContents::getNetworkMask() const
{
    return this->networkMask;
}

void Ospfv2AsExternalLsaContents::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

size_t Ospfv2AsExternalLsaContents::getExternalTOSInfoArraySize() const
{
    return externalTOSInfo_arraysize;
}

const Ospfv2ExternalTosInfo& Ospfv2AsExternalLsaContents::getExternalTOSInfo(size_t k) const
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size externalTOSInfo_arraysize indexed by %lu", (unsigned long)k);
    return this->externalTOSInfo[k];
}

void Ospfv2AsExternalLsaContents::setExternalTOSInfoArraySize(size_t newSize)
{
    Ospfv2ExternalTosInfo *externalTOSInfo2 = (newSize==0) ? nullptr : new Ospfv2ExternalTosInfo[newSize];
    size_t minSize = externalTOSInfo_arraysize < newSize ? externalTOSInfo_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

void Ospfv2AsExternalLsaContents::setExternalTOSInfo(size_t k, const Ospfv2ExternalTosInfo& externalTOSInfo)
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->externalTOSInfo[k] = externalTOSInfo;
}

void Ospfv2AsExternalLsaContents::insertExternalTOSInfo(size_t k, const Ospfv2ExternalTosInfo& externalTOSInfo)
{
    if (k > externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = externalTOSInfo_arraysize + 1;
    Ospfv2ExternalTosInfo *externalTOSInfo2 = new Ospfv2ExternalTosInfo[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    externalTOSInfo2[k] = externalTOSInfo;
    for (i = k + 1; i < newSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i-1];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

void Ospfv2AsExternalLsaContents::insertExternalTOSInfo(const Ospfv2ExternalTosInfo& externalTOSInfo)
{
    insertExternalTOSInfo(externalTOSInfo_arraysize, externalTOSInfo);
}

void Ospfv2AsExternalLsaContents::eraseExternalTOSInfo(size_t k)
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = externalTOSInfo_arraysize - 1;
    Ospfv2ExternalTosInfo *externalTOSInfo2 = (newSize == 0) ? nullptr : new Ospfv2ExternalTosInfo[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    for (i = k; i < newSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i+1];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

class Ospfv2AsExternalLsaContentsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_externalTOSInfo,
    };
  public:
    Ospfv2AsExternalLsaContentsDescriptor();
    virtual ~Ospfv2AsExternalLsaContentsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2AsExternalLsaContentsDescriptor)

Ospfv2AsExternalLsaContentsDescriptor::Ospfv2AsExternalLsaContentsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2AsExternalLsaContents)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ospfv2AsExternalLsaContentsDescriptor::~Ospfv2AsExternalLsaContentsDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2AsExternalLsaContentsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2AsExternalLsaContents *>(obj)!=nullptr;
}

const char **Ospfv2AsExternalLsaContentsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2AsExternalLsaContentsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ospfv2AsExternalLsaContentsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_externalTOSInfo
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "externalTOSInfo",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ospfv2AsExternalLsaContentsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "externalTOSInfo") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "inet::ospfv2::Ospfv2ExternalTosInfo",    // FIELD_externalTOSInfo
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2AsExternalLsaContentsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2AsExternalLsaContentsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_externalTOSInfo: return pp->getExternalTOSInfoArraySize();
        default: return 0;
    }
}

void Ospfv2AsExternalLsaContentsDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_externalTOSInfo: pp->setExternalTOSInfoArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2AsExternalLsaContents'", field);
    }
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2AsExternalLsaContentsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_externalTOSInfo: {std::stringstream out; out << pp->getExternalTOSInfo(i); return out.str();}
        default: return "";
    }
}

void Ospfv2AsExternalLsaContentsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2AsExternalLsaContents'", field);
    }
}

const char *Ospfv2AsExternalLsaContentsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_externalTOSInfo: return omnetpp::opp_typename(typeid(Ospfv2ExternalTosInfo));
        default: return nullptr;
    };
}

void *Ospfv2AsExternalLsaContentsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_externalTOSInfo: return toVoidPtr(&pp->getExternalTOSInfo(i)); break;
        default: return nullptr;
    }
}

void Ospfv2AsExternalLsaContentsDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsaContents *pp = (Ospfv2AsExternalLsaContents *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2AsExternalLsaContents'", field);
    }
}

Register_Class(Ospfv2AsExternalLsa)

Ospfv2AsExternalLsa::Ospfv2AsExternalLsa() : ::inet::ospfv2::Ospfv2Lsa()
{
}

Ospfv2AsExternalLsa::Ospfv2AsExternalLsa(const Ospfv2AsExternalLsa& other) : ::inet::ospfv2::Ospfv2Lsa(other)
{
    copy(other);
}

Ospfv2AsExternalLsa::~Ospfv2AsExternalLsa()
{
}

Ospfv2AsExternalLsa& Ospfv2AsExternalLsa::operator=(const Ospfv2AsExternalLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Lsa::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2AsExternalLsa::copy(const Ospfv2AsExternalLsa& other)
{
    this->contents = other.contents;
}

void Ospfv2AsExternalLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Lsa::parsimPack(b);
    doParsimPacking(b,this->contents);
}

void Ospfv2AsExternalLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Lsa::parsimUnpack(b);
    doParsimUnpacking(b,this->contents);
}

const Ospfv2AsExternalLsaContents& Ospfv2AsExternalLsa::getContents() const
{
    return this->contents;
}

void Ospfv2AsExternalLsa::setContents(const Ospfv2AsExternalLsaContents& contents)
{
    this->contents = contents;
}

class Ospfv2AsExternalLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_contents,
    };
  public:
    Ospfv2AsExternalLsaDescriptor();
    virtual ~Ospfv2AsExternalLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2AsExternalLsaDescriptor)

Ospfv2AsExternalLsaDescriptor::Ospfv2AsExternalLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2AsExternalLsa)), "inet::ospfv2::Ospfv2Lsa")
{
    propertynames = nullptr;
}

Ospfv2AsExternalLsaDescriptor::~Ospfv2AsExternalLsaDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2AsExternalLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2AsExternalLsa *>(obj)!=nullptr;
}

const char **Ospfv2AsExternalLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2AsExternalLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2AsExternalLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ospfv2AsExternalLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_contents
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2AsExternalLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ospfv2AsExternalLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "contents") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2AsExternalLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospfv2::Ospfv2AsExternalLsaContents",    // FIELD_contents
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2AsExternalLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2AsExternalLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2AsExternalLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2AsExternalLsaDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2AsExternalLsa'", field);
    }
}

const char *Ospfv2AsExternalLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2AsExternalLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        case FIELD_contents: {std::stringstream out; out << pp->getContents(); return out.str();}
        default: return "";
    }
}

void Ospfv2AsExternalLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2AsExternalLsa'", field);
    }
}

const char *Ospfv2AsExternalLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_contents: return omnetpp::opp_typename(typeid(Ospfv2AsExternalLsaContents));
        default: return nullptr;
    };
}

void *Ospfv2AsExternalLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        case FIELD_contents: return toVoidPtr(&pp->getContents()); break;
        default: return nullptr;
    }
}

void Ospfv2AsExternalLsaDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2AsExternalLsa *pp = (Ospfv2AsExternalLsa *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2AsExternalLsa'", field);
    }
}

Ospfv2DdOptions::Ospfv2DdOptions()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Ospfv2DdOptions& a)
{
    doParsimPacking(b,a.unused);
    doParsimPacking(b,a.I_Init);
    doParsimPacking(b,a.M_More);
    doParsimPacking(b,a.MS_MasterSlave);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ospfv2DdOptions& a)
{
    doParsimUnpacking(b,a.unused);
    doParsimUnpacking(b,a.I_Init);
    doParsimUnpacking(b,a.M_More);
    doParsimUnpacking(b,a.MS_MasterSlave);
}

class Ospfv2DdOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_unused,
        FIELD_I_Init,
        FIELD_M_More,
        FIELD_MS_MasterSlave,
    };
  public:
    Ospfv2DdOptionsDescriptor();
    virtual ~Ospfv2DdOptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2DdOptionsDescriptor)

Ospfv2DdOptionsDescriptor::Ospfv2DdOptionsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2DdOptions)), "")
{
    propertynames = nullptr;
}

Ospfv2DdOptionsDescriptor::~Ospfv2DdOptionsDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2DdOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2DdOptions *>(obj)!=nullptr;
}

const char **Ospfv2DdOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2DdOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2DdOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ospfv2DdOptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_unused
        FD_ISEDITABLE,    // FIELD_I_Init
        FD_ISEDITABLE,    // FIELD_M_More
        FD_ISEDITABLE,    // FIELD_MS_MasterSlave
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2DdOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused",
        "I_Init",
        "M_More",
        "MS_MasterSlave",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ospfv2DdOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused") == 0) return base+0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "I_Init") == 0) return base+1;
    if (fieldName[0] == 'M' && strcmp(fieldName, "M_More") == 0) return base+2;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MS_MasterSlave") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2DdOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_unused
        "bool",    // FIELD_I_Init
        "bool",    // FIELD_M_More
        "bool",    // FIELD_MS_MasterSlave
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2DdOptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2DdOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2DdOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2DdOptionsDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2DdOptions'", field);
    }
}

const char *Ospfv2DdOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2DdOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused: return ulong2string(pp->unused);
        case FIELD_I_Init: return bool2string(pp->I_Init);
        case FIELD_M_More: return bool2string(pp->M_More);
        case FIELD_MS_MasterSlave: return bool2string(pp->MS_MasterSlave);
        default: return "";
    }
}

void Ospfv2DdOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused: pp->unused = string2ulong(value); break;
        case FIELD_I_Init: pp->I_Init = string2bool(value); break;
        case FIELD_M_More: pp->M_More = string2bool(value); break;
        case FIELD_MS_MasterSlave: pp->MS_MasterSlave = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2DdOptions'", field);
    }
}

const char *Ospfv2DdOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2DdOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ospfv2DdOptionsDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DdOptions *pp = (Ospfv2DdOptions *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2DdOptions'", field);
    }
}

Register_Class(Ospfv2DatabaseDescriptionPacket)

Ospfv2DatabaseDescriptionPacket::Ospfv2DatabaseDescriptionPacket() : ::inet::ospfv2::Ospfv2Packet()
{
}

Ospfv2DatabaseDescriptionPacket::Ospfv2DatabaseDescriptionPacket(const Ospfv2DatabaseDescriptionPacket& other) : ::inet::ospfv2::Ospfv2Packet(other)
{
    copy(other);
}

Ospfv2DatabaseDescriptionPacket::~Ospfv2DatabaseDescriptionPacket()
{
    delete [] this->lsaHeaders;
}

Ospfv2DatabaseDescriptionPacket& Ospfv2DatabaseDescriptionPacket::operator=(const Ospfv2DatabaseDescriptionPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Packet::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2DatabaseDescriptionPacket::copy(const Ospfv2DatabaseDescriptionPacket& other)
{
    this->interfaceMTU = other.interfaceMTU;
    this->options = other.options;
    this->ddOptions = other.ddOptions;
    this->ddSequenceNumber = other.ddSequenceNumber;
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new Ospfv2LsaHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (size_t i = 0; i < lsaHeaders_arraysize; i++) {
        this->lsaHeaders[i] = other.lsaHeaders[i];
    }
}

void Ospfv2DatabaseDescriptionPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Packet::parsimPack(b);
    doParsimPacking(b,this->interfaceMTU);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->ddOptions);
    doParsimPacking(b,this->ddSequenceNumber);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void Ospfv2DatabaseDescriptionPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceMTU);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->ddOptions);
    doParsimUnpacking(b,this->ddSequenceNumber);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize == 0) {
        this->lsaHeaders = nullptr;
    } else {
        this->lsaHeaders = new Ospfv2LsaHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

unsigned short Ospfv2DatabaseDescriptionPacket::getInterfaceMTU() const
{
    return this->interfaceMTU;
}

void Ospfv2DatabaseDescriptionPacket::setInterfaceMTU(unsigned short interfaceMTU)
{
    handleChange();
    this->interfaceMTU = interfaceMTU;
}

const Ospfv2Options& Ospfv2DatabaseDescriptionPacket::getOptions() const
{
    return this->options;
}

void Ospfv2DatabaseDescriptionPacket::setOptions(const Ospfv2Options& options)
{
    handleChange();
    this->options = options;
}

const Ospfv2DdOptions& Ospfv2DatabaseDescriptionPacket::getDdOptions() const
{
    return this->ddOptions;
}

void Ospfv2DatabaseDescriptionPacket::setDdOptions(const Ospfv2DdOptions& ddOptions)
{
    handleChange();
    this->ddOptions = ddOptions;
}

unsigned long Ospfv2DatabaseDescriptionPacket::getDdSequenceNumber() const
{
    return this->ddSequenceNumber;
}

void Ospfv2DatabaseDescriptionPacket::setDdSequenceNumber(unsigned long ddSequenceNumber)
{
    handleChange();
    this->ddSequenceNumber = ddSequenceNumber;
}

size_t Ospfv2DatabaseDescriptionPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

const Ospfv2LsaHeader& Ospfv2DatabaseDescriptionPacket::getLsaHeaders(size_t k) const
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size lsaHeaders_arraysize indexed by %lu", (unsigned long)k);
    return this->lsaHeaders[k];
}

void Ospfv2DatabaseDescriptionPacket::setLsaHeadersArraySize(size_t newSize)
{
    handleChange();
    Ospfv2LsaHeader *lsaHeaders2 = (newSize==0) ? nullptr : new Ospfv2LsaHeader[newSize];
    size_t minSize = lsaHeaders_arraysize < newSize ? lsaHeaders_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void Ospfv2DatabaseDescriptionPacket::setLsaHeaders(size_t k, const Ospfv2LsaHeader& lsaHeaders)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->lsaHeaders[k] = lsaHeaders;
}

void Ospfv2DatabaseDescriptionPacket::insertLsaHeaders(size_t k, const Ospfv2LsaHeader& lsaHeaders)
{
    if (k > lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize + 1;
    Ospfv2LsaHeader *lsaHeaders2 = new Ospfv2LsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders2[k] = lsaHeaders;
    for (i = k + 1; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i-1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void Ospfv2DatabaseDescriptionPacket::insertLsaHeaders(const Ospfv2LsaHeader& lsaHeaders)
{
    insertLsaHeaders(lsaHeaders_arraysize, lsaHeaders);
}

void Ospfv2DatabaseDescriptionPacket::eraseLsaHeaders(size_t k)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize - 1;
    Ospfv2LsaHeader *lsaHeaders2 = (newSize == 0) ? nullptr : new Ospfv2LsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    for (i = k; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i+1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

class Ospfv2DatabaseDescriptionPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceMTU,
        FIELD_options,
        FIELD_ddOptions,
        FIELD_ddSequenceNumber,
        FIELD_lsaHeaders,
    };
  public:
    Ospfv2DatabaseDescriptionPacketDescriptor();
    virtual ~Ospfv2DatabaseDescriptionPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2DatabaseDescriptionPacketDescriptor)

Ospfv2DatabaseDescriptionPacketDescriptor::Ospfv2DatabaseDescriptionPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2DatabaseDescriptionPacket)), "inet::ospfv2::Ospfv2Packet")
{
    propertynames = nullptr;
}

Ospfv2DatabaseDescriptionPacketDescriptor::~Ospfv2DatabaseDescriptionPacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2DatabaseDescriptionPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2DatabaseDescriptionPacket *>(obj)!=nullptr;
}

const char **Ospfv2DatabaseDescriptionPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2DatabaseDescriptionPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ospfv2DatabaseDescriptionPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceMTU
        FD_ISCOMPOUND,    // FIELD_options
        FD_ISCOMPOUND,    // FIELD_ddOptions
        FD_ISEDITABLE,    // FIELD_ddSequenceNumber
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISRESIZABLE,    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceMTU",
        "options",
        "ddOptions",
        "ddSequenceNumber",
        "lsaHeaders",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ospfv2DatabaseDescriptionPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceMTU") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "ddOptions") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "ddSequenceNumber") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaHeaders") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_interfaceMTU
        "inet::ospfv2::Ospfv2Options",    // FIELD_options
        "inet::ospfv2::Ospfv2DdOptions",    // FIELD_ddOptions
        "unsigned long",    // FIELD_ddSequenceNumber
        "inet::ospfv2::Ospfv2LsaHeader",    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2DatabaseDescriptionPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2DatabaseDescriptionPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

void Ospfv2DatabaseDescriptionPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: pp->setLsaHeadersArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2DatabaseDescriptionPacket'", field);
    }
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2DatabaseDescriptionPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceMTU: return ulong2string(pp->getInterfaceMTU());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case FIELD_ddOptions: {std::stringstream out; out << pp->getDdOptions(); return out.str();}
        case FIELD_ddSequenceNumber: return ulong2string(pp->getDdSequenceNumber());
        case FIELD_lsaHeaders: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

void Ospfv2DatabaseDescriptionPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceMTU: pp->setInterfaceMTU(string2ulong(value)); break;
        case FIELD_ddSequenceNumber: pp->setDdSequenceNumber(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2DatabaseDescriptionPacket'", field);
    }
}

const char *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(Ospfv2Options));
        case FIELD_ddOptions: return omnetpp::opp_typename(typeid(Ospfv2DdOptions));
        case FIELD_lsaHeaders: return omnetpp::opp_typename(typeid(Ospfv2LsaHeader));
        default: return nullptr;
    };
}

void *Ospfv2DatabaseDescriptionPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        case FIELD_ddOptions: return toVoidPtr(&pp->getDdOptions()); break;
        case FIELD_lsaHeaders: return toVoidPtr(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

void Ospfv2DatabaseDescriptionPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2DatabaseDescriptionPacket *pp = (Ospfv2DatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2DatabaseDescriptionPacket'", field);
    }
}

Ospfv2LsaRequest::Ospfv2LsaRequest()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Ospfv2LsaRequest& a)
{
    doParsimPacking(b,a.lsType);
    doParsimPacking(b,a.linkStateID);
    doParsimPacking(b,a.advertisingRouter);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ospfv2LsaRequest& a)
{
    doParsimUnpacking(b,a.lsType);
    doParsimUnpacking(b,a.linkStateID);
    doParsimUnpacking(b,a.advertisingRouter);
}

class Ospfv2LsaRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsType,
        FIELD_linkStateID,
        FIELD_advertisingRouter,
    };
  public:
    Ospfv2LsaRequestDescriptor();
    virtual ~Ospfv2LsaRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LsaRequestDescriptor)

Ospfv2LsaRequestDescriptor::Ospfv2LsaRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2LsaRequest)), "")
{
    propertynames = nullptr;
}

Ospfv2LsaRequestDescriptor::~Ospfv2LsaRequestDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LsaRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2LsaRequest *>(obj)!=nullptr;
}

const char **Ospfv2LsaRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LsaRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LsaRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ospfv2LsaRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lsType
        0,    // FIELD_linkStateID
        0,    // FIELD_advertisingRouter
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LsaRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsType",
        "linkStateID",
        "advertisingRouter",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ospfv2LsaRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsType") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkStateID") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertisingRouter") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LsaRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",    // FIELD_lsType
        "inet::Ipv4Address",    // FIELD_linkStateID
        "inet::Ipv4Address",    // FIELD_advertisingRouter
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LsaRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2LsaRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2LsaRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ospfv2LsaRequestDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2LsaRequest'", field);
    }
}

const char *Ospfv2LsaRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LsaRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_lsType: return ulong2string(pp->lsType);
        case FIELD_linkStateID: return pp->linkStateID.str();
        case FIELD_advertisingRouter: return pp->advertisingRouter.str();
        default: return "";
    }
}

void Ospfv2LsaRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_lsType: pp->lsType = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LsaRequest'", field);
    }
}

const char *Ospfv2LsaRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ospfv2LsaRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_linkStateID: return toVoidPtr(&pp->linkStateID); break;
        case FIELD_advertisingRouter: return toVoidPtr(&pp->advertisingRouter); break;
        default: return nullptr;
    }
}

void Ospfv2LsaRequestDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LsaRequest *pp = (Ospfv2LsaRequest *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LsaRequest'", field);
    }
}

Register_Class(Ospfv2LinkStateRequestPacket)

Ospfv2LinkStateRequestPacket::Ospfv2LinkStateRequestPacket() : ::inet::ospfv2::Ospfv2Packet()
{
}

Ospfv2LinkStateRequestPacket::Ospfv2LinkStateRequestPacket(const Ospfv2LinkStateRequestPacket& other) : ::inet::ospfv2::Ospfv2Packet(other)
{
    copy(other);
}

Ospfv2LinkStateRequestPacket::~Ospfv2LinkStateRequestPacket()
{
    delete [] this->requests;
}

Ospfv2LinkStateRequestPacket& Ospfv2LinkStateRequestPacket::operator=(const Ospfv2LinkStateRequestPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Packet::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2LinkStateRequestPacket::copy(const Ospfv2LinkStateRequestPacket& other)
{
    delete [] this->requests;
    this->requests = (other.requests_arraysize==0) ? nullptr : new Ospfv2LsaRequest[other.requests_arraysize];
    requests_arraysize = other.requests_arraysize;
    for (size_t i = 0; i < requests_arraysize; i++) {
        this->requests[i] = other.requests[i];
    }
}

void Ospfv2LinkStateRequestPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Packet::parsimPack(b);
    b->pack(requests_arraysize);
    doParsimArrayPacking(b,this->requests,requests_arraysize);
}

void Ospfv2LinkStateRequestPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Packet::parsimUnpack(b);
    delete [] this->requests;
    b->unpack(requests_arraysize);
    if (requests_arraysize == 0) {
        this->requests = nullptr;
    } else {
        this->requests = new Ospfv2LsaRequest[requests_arraysize];
        doParsimArrayUnpacking(b,this->requests,requests_arraysize);
    }
}

size_t Ospfv2LinkStateRequestPacket::getRequestsArraySize() const
{
    return requests_arraysize;
}

const Ospfv2LsaRequest& Ospfv2LinkStateRequestPacket::getRequests(size_t k) const
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size requests_arraysize indexed by %lu", (unsigned long)k);
    return this->requests[k];
}

void Ospfv2LinkStateRequestPacket::setRequestsArraySize(size_t newSize)
{
    handleChange();
    Ospfv2LsaRequest *requests2 = (newSize==0) ? nullptr : new Ospfv2LsaRequest[newSize];
    size_t minSize = requests_arraysize < newSize ? requests_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        requests2[i] = this->requests[i];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

void Ospfv2LinkStateRequestPacket::setRequests(size_t k, const Ospfv2LsaRequest& requests)
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->requests[k] = requests;
}

void Ospfv2LinkStateRequestPacket::insertRequests(size_t k, const Ospfv2LsaRequest& requests)
{
    if (k > requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = requests_arraysize + 1;
    Ospfv2LsaRequest *requests2 = new Ospfv2LsaRequest[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        requests2[i] = this->requests[i];
    requests2[k] = requests;
    for (i = k + 1; i < newSize; i++)
        requests2[i] = this->requests[i-1];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

void Ospfv2LinkStateRequestPacket::insertRequests(const Ospfv2LsaRequest& requests)
{
    insertRequests(requests_arraysize, requests);
}

void Ospfv2LinkStateRequestPacket::eraseRequests(size_t k)
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = requests_arraysize - 1;
    Ospfv2LsaRequest *requests2 = (newSize == 0) ? nullptr : new Ospfv2LsaRequest[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        requests2[i] = this->requests[i];
    for (i = k; i < newSize; i++)
        requests2[i] = this->requests[i+1];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

class Ospfv2LinkStateRequestPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requests,
    };
  public:
    Ospfv2LinkStateRequestPacketDescriptor();
    virtual ~Ospfv2LinkStateRequestPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LinkStateRequestPacketDescriptor)

Ospfv2LinkStateRequestPacketDescriptor::Ospfv2LinkStateRequestPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2LinkStateRequestPacket)), "inet::ospfv2::Ospfv2Packet")
{
    propertynames = nullptr;
}

Ospfv2LinkStateRequestPacketDescriptor::~Ospfv2LinkStateRequestPacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LinkStateRequestPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2LinkStateRequestPacket *>(obj)!=nullptr;
}

const char **Ospfv2LinkStateRequestPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LinkStateRequestPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ospfv2LinkStateRequestPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_requests
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requests",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ospfv2LinkStateRequestPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requests") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospfv2::Ospfv2LsaRequest",    // FIELD_requests
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LinkStateRequestPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2LinkStateRequestPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: return pp->getRequestsArraySize();
        default: return 0;
    }
}

void Ospfv2LinkStateRequestPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: pp->setRequestsArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2LinkStateRequestPacket'", field);
    }
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LinkStateRequestPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: {std::stringstream out; out << pp->getRequests(i); return out.str();}
        default: return "";
    }
}

void Ospfv2LinkStateRequestPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateRequestPacket'", field);
    }
}

const char *Ospfv2LinkStateRequestPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_requests: return omnetpp::opp_typename(typeid(Ospfv2LsaRequest));
        default: return nullptr;
    };
}

void *Ospfv2LinkStateRequestPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: return toVoidPtr(&pp->getRequests(i)); break;
        default: return nullptr;
    }
}

void Ospfv2LinkStateRequestPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateRequestPacket *pp = (Ospfv2LinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateRequestPacket'", field);
    }
}

Register_Class(Ospfv2LinkStateUpdatePacket)

Ospfv2LinkStateUpdatePacket::Ospfv2LinkStateUpdatePacket() : ::inet::ospfv2::Ospfv2Packet()
{
}

Ospfv2LinkStateUpdatePacket::Ospfv2LinkStateUpdatePacket(const Ospfv2LinkStateUpdatePacket& other) : ::inet::ospfv2::Ospfv2Packet(other)
{
    copy(other);
}

Ospfv2LinkStateUpdatePacket::~Ospfv2LinkStateUpdatePacket()
{
    for (size_t i = 0; i < ospfLSAs_arraysize; i++)
        delete this->ospfLSAs[i];
    delete [] this->ospfLSAs;
}

Ospfv2LinkStateUpdatePacket& Ospfv2LinkStateUpdatePacket::operator=(const Ospfv2LinkStateUpdatePacket& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Packet::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2LinkStateUpdatePacket::copy(const Ospfv2LinkStateUpdatePacket& other)
{
    for (size_t i = 0; i < ospfLSAs_arraysize; i++)
        delete this->ospfLSAs[i];
    delete [] this->ospfLSAs;
    this->ospfLSAs = (other.ospfLSAs_arraysize==0) ? nullptr : new Ospfv2Lsa *[other.ospfLSAs_arraysize];
    ospfLSAs_arraysize = other.ospfLSAs_arraysize;
    for (size_t i = 0; i < ospfLSAs_arraysize; i++) {
        this->ospfLSAs[i] = other.ospfLSAs[i];
        if (this->ospfLSAs[i] != nullptr) {
            this->ospfLSAs[i] = this->ospfLSAs[i]->dup();
        }
    }
}

void Ospfv2LinkStateUpdatePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Packet::parsimPack(b);
    b->pack(ospfLSAs_arraysize);
    doParsimArrayPacking(b,this->ospfLSAs,ospfLSAs_arraysize);
}

void Ospfv2LinkStateUpdatePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Packet::parsimUnpack(b);
    delete [] this->ospfLSAs;
    b->unpack(ospfLSAs_arraysize);
    if (ospfLSAs_arraysize == 0) {
        this->ospfLSAs = nullptr;
    } else {
        this->ospfLSAs = new Ospfv2Lsa *[ospfLSAs_arraysize];
        doParsimArrayUnpacking(b,this->ospfLSAs,ospfLSAs_arraysize);
    }
}

size_t Ospfv2LinkStateUpdatePacket::getOspfLSAsArraySize() const
{
    return ospfLSAs_arraysize;
}

const Ospfv2Lsa * Ospfv2LinkStateUpdatePacket::getOspfLSAs(size_t k) const
{
    if (k >= ospfLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size ospfLSAs_arraysize indexed by %lu", (unsigned long)k);
    return this->ospfLSAs[k];
}

void Ospfv2LinkStateUpdatePacket::setOspfLSAsArraySize(size_t newSize)
{
    handleChange();
    Ospfv2Lsa * *ospfLSAs2 = (newSize==0) ? nullptr : new Ospfv2Lsa *[newSize];
    size_t minSize = ospfLSAs_arraysize < newSize ? ospfLSAs_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        ospfLSAs2[i] = this->ospfLSAs[i];
    for (size_t i = minSize; i < newSize; i++)
        ospfLSAs2[i] = nullptr;
    for (size_t i = newSize; i < ospfLSAs_arraysize; i++)
        delete ospfLSAs[i];
    delete [] this->ospfLSAs;
    this->ospfLSAs = ospfLSAs2;
    ospfLSAs_arraysize = newSize;
}

void Ospfv2LinkStateUpdatePacket::setOspfLSAs(size_t k, Ospfv2Lsa * ospfLSAs)
{
    if (k >= ospfLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    delete this->ospfLSAs[k];
    this->ospfLSAs[k] = ospfLSAs;
}

Ospfv2Lsa * Ospfv2LinkStateUpdatePacket::dropOspfLSAs(size_t k)
{
    if (k >= ospfLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    Ospfv2Lsa * retval = this->ospfLSAs[k];
    this->ospfLSAs[k] = nullptr;
    return retval;
}

void Ospfv2LinkStateUpdatePacket::insertOspfLSAs(size_t k, Ospfv2Lsa * ospfLSAs)
{
    if (k > ospfLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = ospfLSAs_arraysize + 1;
    Ospfv2Lsa * *ospfLSAs2 = new Ospfv2Lsa *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ospfLSAs2[i] = this->ospfLSAs[i];
    ospfLSAs2[k] = ospfLSAs;
    for (i = k + 1; i < newSize; i++)
        ospfLSAs2[i] = this->ospfLSAs[i-1];
    delete [] this->ospfLSAs;
    this->ospfLSAs = ospfLSAs2;
    ospfLSAs_arraysize = newSize;
}

void Ospfv2LinkStateUpdatePacket::insertOspfLSAs(Ospfv2Lsa * ospfLSAs)
{
    insertOspfLSAs(ospfLSAs_arraysize, ospfLSAs);
}

void Ospfv2LinkStateUpdatePacket::eraseOspfLSAs(size_t k)
{
    if (k >= ospfLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = ospfLSAs_arraysize - 1;
    Ospfv2Lsa * *ospfLSAs2 = (newSize == 0) ? nullptr : new Ospfv2Lsa *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ospfLSAs2[i] = this->ospfLSAs[i];
    for (i = k; i < newSize; i++)
        ospfLSAs2[i] = this->ospfLSAs[i+1];
    delete this->ospfLSAs[k];
    delete [] this->ospfLSAs;
    this->ospfLSAs = ospfLSAs2;
    ospfLSAs_arraysize = newSize;
}

class Ospfv2LinkStateUpdatePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ospfLSAs,
    };
  public:
    Ospfv2LinkStateUpdatePacketDescriptor();
    virtual ~Ospfv2LinkStateUpdatePacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LinkStateUpdatePacketDescriptor)

Ospfv2LinkStateUpdatePacketDescriptor::Ospfv2LinkStateUpdatePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2LinkStateUpdatePacket)), "inet::ospfv2::Ospfv2Packet")
{
    propertynames = nullptr;
}

Ospfv2LinkStateUpdatePacketDescriptor::~Ospfv2LinkStateUpdatePacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LinkStateUpdatePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2LinkStateUpdatePacket *>(obj)!=nullptr;
}

const char **Ospfv2LinkStateUpdatePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LinkStateUpdatePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ospfv2LinkStateUpdatePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE | FD_ISRESIZABLE,    // FIELD_ospfLSAs
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ospfLSAs",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ospfv2LinkStateUpdatePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "ospfLSAs") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospfv2::Ospfv2Lsa",    // FIELD_ospfLSAs
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LinkStateUpdatePacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ospfLSAs: {
            static const char *names[] = { "owned", "allowReplace",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ospfLSAs:
            if (!strcmp(propertyname, "owned")) return "";
            if (!strcmp(propertyname, "allowReplace")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int Ospfv2LinkStateUpdatePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: return pp->getOspfLSAsArraySize();
        default: return 0;
    }
}

void Ospfv2LinkStateUpdatePacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: pp->setOspfLSAsArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2LinkStateUpdatePacket'", field);
    }
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: { const Ospfv2Lsa * value = pp->getOspfLSAs(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ospfv2LinkStateUpdatePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: {std::stringstream out; out << pp->getOspfLSAs(i); return out.str();}
        default: return "";
    }
}

void Ospfv2LinkStateUpdatePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateUpdatePacket'", field);
    }
}

const char *Ospfv2LinkStateUpdatePacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ospfLSAs: return omnetpp::opp_typename(typeid(Ospfv2Lsa));
        default: return nullptr;
    };
}

void *Ospfv2LinkStateUpdatePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: return toVoidPtr(pp->getOspfLSAs(i)); break;
        default: return nullptr;
    }
}

void Ospfv2LinkStateUpdatePacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateUpdatePacket *pp = (Ospfv2LinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ospfLSAs: pp->setOspfLSAs(i,(Ospfv2Lsa *)ptr); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateUpdatePacket'", field);
    }
}

Register_Class(Ospfv2LinkStateAcknowledgementPacket)

Ospfv2LinkStateAcknowledgementPacket::Ospfv2LinkStateAcknowledgementPacket() : ::inet::ospfv2::Ospfv2Packet()
{
}

Ospfv2LinkStateAcknowledgementPacket::Ospfv2LinkStateAcknowledgementPacket(const Ospfv2LinkStateAcknowledgementPacket& other) : ::inet::ospfv2::Ospfv2Packet(other)
{
    copy(other);
}

Ospfv2LinkStateAcknowledgementPacket::~Ospfv2LinkStateAcknowledgementPacket()
{
    delete [] this->lsaHeaders;
}

Ospfv2LinkStateAcknowledgementPacket& Ospfv2LinkStateAcknowledgementPacket::operator=(const Ospfv2LinkStateAcknowledgementPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospfv2::Ospfv2Packet::operator=(other);
    copy(other);
    return *this;
}

void Ospfv2LinkStateAcknowledgementPacket::copy(const Ospfv2LinkStateAcknowledgementPacket& other)
{
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new Ospfv2LsaHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (size_t i = 0; i < lsaHeaders_arraysize; i++) {
        this->lsaHeaders[i] = other.lsaHeaders[i];
    }
}

void Ospfv2LinkStateAcknowledgementPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospfv2::Ospfv2Packet::parsimPack(b);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void Ospfv2LinkStateAcknowledgementPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospfv2::Ospfv2Packet::parsimUnpack(b);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize == 0) {
        this->lsaHeaders = nullptr;
    } else {
        this->lsaHeaders = new Ospfv2LsaHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

size_t Ospfv2LinkStateAcknowledgementPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

const Ospfv2LsaHeader& Ospfv2LinkStateAcknowledgementPacket::getLsaHeaders(size_t k) const
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size lsaHeaders_arraysize indexed by %lu", (unsigned long)k);
    return this->lsaHeaders[k];
}

void Ospfv2LinkStateAcknowledgementPacket::setLsaHeadersArraySize(size_t newSize)
{
    handleChange();
    Ospfv2LsaHeader *lsaHeaders2 = (newSize==0) ? nullptr : new Ospfv2LsaHeader[newSize];
    size_t minSize = lsaHeaders_arraysize < newSize ? lsaHeaders_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void Ospfv2LinkStateAcknowledgementPacket::setLsaHeaders(size_t k, const Ospfv2LsaHeader& lsaHeaders)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->lsaHeaders[k] = lsaHeaders;
}

void Ospfv2LinkStateAcknowledgementPacket::insertLsaHeaders(size_t k, const Ospfv2LsaHeader& lsaHeaders)
{
    if (k > lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize + 1;
    Ospfv2LsaHeader *lsaHeaders2 = new Ospfv2LsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders2[k] = lsaHeaders;
    for (i = k + 1; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i-1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void Ospfv2LinkStateAcknowledgementPacket::insertLsaHeaders(const Ospfv2LsaHeader& lsaHeaders)
{
    insertLsaHeaders(lsaHeaders_arraysize, lsaHeaders);
}

void Ospfv2LinkStateAcknowledgementPacket::eraseLsaHeaders(size_t k)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize - 1;
    Ospfv2LsaHeader *lsaHeaders2 = (newSize == 0) ? nullptr : new Ospfv2LsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    for (i = k; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i+1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

class Ospfv2LinkStateAcknowledgementPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsaHeaders,
    };
  public:
    Ospfv2LinkStateAcknowledgementPacketDescriptor();
    virtual ~Ospfv2LinkStateAcknowledgementPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(Ospfv2LinkStateAcknowledgementPacketDescriptor)

Ospfv2LinkStateAcknowledgementPacketDescriptor::Ospfv2LinkStateAcknowledgementPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospfv2::Ospfv2LinkStateAcknowledgementPacket)), "inet::ospfv2::Ospfv2Packet")
{
    propertynames = nullptr;
}

Ospfv2LinkStateAcknowledgementPacketDescriptor::~Ospfv2LinkStateAcknowledgementPacketDescriptor()
{
    delete[] propertynames;
}

bool Ospfv2LinkStateAcknowledgementPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ospfv2LinkStateAcknowledgementPacket *>(obj)!=nullptr;
}

const char **Ospfv2LinkStateAcknowledgementPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISRESIZABLE,    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaHeaders",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ospfv2LinkStateAcknowledgementPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaHeaders") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospfv2::Ospfv2LsaHeader",    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

void Ospfv2LinkStateAcknowledgementPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: pp->setLsaHeadersArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ospfv2LinkStateAcknowledgementPacket'", field);
    }
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

void Ospfv2LinkStateAcknowledgementPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateAcknowledgementPacket'", field);
    }
}

const char *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsaHeaders: return omnetpp::opp_typename(typeid(Ospfv2LsaHeader));
        default: return nullptr;
    };
}

void *Ospfv2LinkStateAcknowledgementPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return toVoidPtr(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

void Ospfv2LinkStateAcknowledgementPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ospfv2LinkStateAcknowledgementPacket *pp = (Ospfv2LinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ospfv2LinkStateAcknowledgementPacket'", field);
    }
}

} // namespace ospfv2
} // namespace inet

