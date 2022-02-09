//
// Generated file, do not edit! Created by nedtool 6.0 from inet/common/PacketEventTag.msg.
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
#include "PacketEventTag_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PacketEventKind");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PacketEventKind"));
    e->insert(PEK_UNDEFINED, "PEK_UNDEFINED");
    e->insert(PEK_DELAYED, "PEK_DELAYED");
    e->insert(PEK_QUEUED, "PEK_QUEUED");
    e->insert(PEK_PROCESSED, "PEK_PROCESSED");
    e->insert(PEK_TRANSMITTED, "PEK_TRANSMITTED");
    e->insert(PEK_PROPAGATED, "PEK_PROPAGATED");
)

Register_Class(PacketEvent)

PacketEvent::PacketEvent() : ::omnetpp::cObject()
{
}

PacketEvent::PacketEvent(const PacketEvent& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

PacketEvent::~PacketEvent()
{
}

PacketEvent& PacketEvent::operator=(const PacketEvent& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void PacketEvent::copy(const PacketEvent& other)
{
    this->kind = other.kind;
    this->modulePath = other.modulePath;
    this->eventNumber = other.eventNumber;
    this->simulationTime = other.simulationTime;
    this->duration = other.duration;
    this->packetLength = other.packetLength;
}

std::string PacketEvent::str() const
{
    return getClassName();
}

void PacketEvent::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->kind);
    doParsimPacking(b,this->modulePath);
    doParsimPacking(b,this->eventNumber);
    doParsimPacking(b,this->simulationTime);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->packetLength);
}

void PacketEvent::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->kind);
    doParsimUnpacking(b,this->modulePath);
    doParsimUnpacking(b,this->eventNumber);
    doParsimUnpacking(b,this->simulationTime);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->packetLength);
}

int PacketEvent::getKind() const
{
    return this->kind;
}

void PacketEvent::setKind(int kind)
{
    this->kind = kind;
}

const char * PacketEvent::getModulePath() const
{
    return this->modulePath.c_str();
}

void PacketEvent::setModulePath(const char * modulePath)
{
    this->modulePath = modulePath;
}

int64_t PacketEvent::getEventNumber() const
{
    return this->eventNumber;
}

void PacketEvent::setEventNumber(int64_t eventNumber)
{
    this->eventNumber = eventNumber;
}

omnetpp::simtime_t PacketEvent::getSimulationTime() const
{
    return this->simulationTime;
}

void PacketEvent::setSimulationTime(omnetpp::simtime_t simulationTime)
{
    this->simulationTime = simulationTime;
}

omnetpp::simtime_t PacketEvent::getDuration() const
{
    return this->duration;
}

void PacketEvent::setDuration(omnetpp::simtime_t duration)
{
    this->duration = duration;
}

b PacketEvent::getPacketLength() const
{
    return this->packetLength;
}

void PacketEvent::setPacketLength(b packetLength)
{
    this->packetLength = packetLength;
}

class PacketEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_kind,
        FIELD_modulePath,
        FIELD_eventNumber,
        FIELD_simulationTime,
        FIELD_duration,
        FIELD_packetLength,
    };
  public:
    PacketEventDescriptor();
    virtual ~PacketEventDescriptor();

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

Register_ClassDescriptor(PacketEventDescriptor)

PacketEventDescriptor::PacketEventDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketEvent)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

PacketEventDescriptor::~PacketEventDescriptor()
{
    delete[] propertynames;
}

bool PacketEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketEvent *>(obj)!=nullptr;
}

const char **PacketEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "str",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketEventDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "str")) return "getClassName()";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int PacketEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_kind
        FD_ISEDITABLE,    // FIELD_modulePath
        FD_ISEDITABLE,    // FIELD_eventNumber
        0,    // FIELD_simulationTime
        0,    // FIELD_duration
        FD_ISEDITABLE,    // FIELD_packetLength
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *PacketEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "kind",
        "modulePath",
        "eventNumber",
        "simulationTime",
        "duration",
        "packetLength",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int PacketEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'k' && strcmp(fieldName, "kind") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "modulePath") == 0) return base+1;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eventNumber") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "simulationTime") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+4;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetLength") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_kind
        "string",    // FIELD_modulePath
        "int64_t",    // FIELD_eventNumber
        "omnetpp::simtime_t",    // FIELD_simulationTime
        "omnetpp::simtime_t",    // FIELD_duration
        "inet::b",    // FIELD_packetLength
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketEventDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_kind: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PacketEventDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_kind:
            if (!strcmp(propertyname, "enum")) return "PacketEventKind";
            if (!strcmp(propertyname, "enum")) return "inet::PacketEventKind";
            return nullptr;
        default: return nullptr;
    }
}

int PacketEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketEventDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketEvent'", field);
    }
}

const char *PacketEventDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacketEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        case FIELD_kind: return enum2string(pp->getKind(), "inet::PacketEventKind");
        case FIELD_modulePath: return oppstring2string(pp->getModulePath());
        case FIELD_eventNumber: return int642string(pp->getEventNumber());
        case FIELD_simulationTime: return simtime2string(pp->getSimulationTime());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_packetLength: return unit2string(pp->getPacketLength());
        default: return "";
    }
}

void PacketEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        case FIELD_kind: pp->setKind((inet::PacketEventKind)string2enum(value, "inet::PacketEventKind")); break;
        case FIELD_modulePath: pp->setModulePath((value)); break;
        case FIELD_eventNumber: pp->setEventNumber(string2int64(value)); break;
        case FIELD_packetLength: pp->setPacketLength(b(string2long(value))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketEvent'", field);
    }
}

const char *PacketEventDescriptor::getFieldStructName(int field) const
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

void *PacketEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void PacketEventDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEvent *pp = (PacketEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketEvent'", field);
    }
}

Register_Class(PacketQueuedEvent)

PacketQueuedEvent::PacketQueuedEvent() : ::inet::PacketEvent()
{
}

PacketQueuedEvent::PacketQueuedEvent(const PacketQueuedEvent& other) : ::inet::PacketEvent(other)
{
    copy(other);
}

PacketQueuedEvent::~PacketQueuedEvent()
{
}

PacketQueuedEvent& PacketQueuedEvent::operator=(const PacketQueuedEvent& other)
{
    if (this == &other) return *this;
    ::inet::PacketEvent::operator=(other);
    copy(other);
    return *this;
}

void PacketQueuedEvent::copy(const PacketQueuedEvent& other)
{
    this->queuePacketLength = other.queuePacketLength;
    this->queueDataLength = other.queueDataLength;
}

void PacketQueuedEvent::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PacketEvent::parsimPack(b);
    doParsimPacking(b,this->queuePacketLength);
    doParsimPacking(b,this->queueDataLength);
}

void PacketQueuedEvent::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PacketEvent::parsimUnpack(b);
    doParsimUnpacking(b,this->queuePacketLength);
    doParsimUnpacking(b,this->queueDataLength);
}

int PacketQueuedEvent::getQueuePacketLength() const
{
    return this->queuePacketLength;
}

void PacketQueuedEvent::setQueuePacketLength(int queuePacketLength)
{
    this->queuePacketLength = queuePacketLength;
}

b PacketQueuedEvent::getQueueDataLength() const
{
    return this->queueDataLength;
}

void PacketQueuedEvent::setQueueDataLength(b queueDataLength)
{
    this->queueDataLength = queueDataLength;
}

class PacketQueuedEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_queuePacketLength,
        FIELD_queueDataLength,
    };
  public:
    PacketQueuedEventDescriptor();
    virtual ~PacketQueuedEventDescriptor();

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

Register_ClassDescriptor(PacketQueuedEventDescriptor)

PacketQueuedEventDescriptor::PacketQueuedEventDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketQueuedEvent)), "inet::PacketEvent")
{
    propertynames = nullptr;
}

PacketQueuedEventDescriptor::~PacketQueuedEventDescriptor()
{
    delete[] propertynames;
}

bool PacketQueuedEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketQueuedEvent *>(obj)!=nullptr;
}

const char **PacketQueuedEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketQueuedEventDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketQueuedEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PacketQueuedEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_queuePacketLength
        FD_ISEDITABLE,    // FIELD_queueDataLength
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PacketQueuedEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "queuePacketLength",
        "queueDataLength",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PacketQueuedEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queuePacketLength") == 0) return base+0;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queueDataLength") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketQueuedEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_queuePacketLength
        "inet::b",    // FIELD_queueDataLength
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketQueuedEventDescriptor::getFieldPropertyNames(int field) const
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

const char *PacketQueuedEventDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PacketQueuedEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketQueuedEventDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketQueuedEvent'", field);
    }
}

const char *PacketQueuedEventDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacketQueuedEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        case FIELD_queuePacketLength: return long2string(pp->getQueuePacketLength());
        case FIELD_queueDataLength: return unit2string(pp->getQueueDataLength());
        default: return "";
    }
}

void PacketQueuedEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        case FIELD_queuePacketLength: pp->setQueuePacketLength(string2long(value)); break;
        case FIELD_queueDataLength: pp->setQueueDataLength(b(string2long(value))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketQueuedEvent'", field);
    }
}

const char *PacketQueuedEventDescriptor::getFieldStructName(int field) const
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

void *PacketQueuedEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void PacketQueuedEventDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketQueuedEvent *pp = (PacketQueuedEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketQueuedEvent'", field);
    }
}

Register_Class(PacketTransmittedEvent)

PacketTransmittedEvent::PacketTransmittedEvent() : ::inet::PacketEvent()
{
}

PacketTransmittedEvent::PacketTransmittedEvent(const PacketTransmittedEvent& other) : ::inet::PacketEvent(other)
{
    copy(other);
}

PacketTransmittedEvent::~PacketTransmittedEvent()
{
}

PacketTransmittedEvent& PacketTransmittedEvent::operator=(const PacketTransmittedEvent& other)
{
    if (this == &other) return *this;
    ::inet::PacketEvent::operator=(other);
    copy(other);
    return *this;
}

void PacketTransmittedEvent::copy(const PacketTransmittedEvent& other)
{
    this->datarate = other.datarate;
}

void PacketTransmittedEvent::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PacketEvent::parsimPack(b);
    doParsimPacking(b,this->datarate);
}

void PacketTransmittedEvent::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PacketEvent::parsimUnpack(b);
    doParsimUnpacking(b,this->datarate);
}

bps PacketTransmittedEvent::getDatarate() const
{
    return this->datarate;
}

void PacketTransmittedEvent::setDatarate(bps datarate)
{
    this->datarate = datarate;
}

class PacketTransmittedEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_datarate,
    };
  public:
    PacketTransmittedEventDescriptor();
    virtual ~PacketTransmittedEventDescriptor();

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

Register_ClassDescriptor(PacketTransmittedEventDescriptor)

PacketTransmittedEventDescriptor::PacketTransmittedEventDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketTransmittedEvent)), "inet::PacketEvent")
{
    propertynames = nullptr;
}

PacketTransmittedEventDescriptor::~PacketTransmittedEventDescriptor()
{
    delete[] propertynames;
}

bool PacketTransmittedEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketTransmittedEvent *>(obj)!=nullptr;
}

const char **PacketTransmittedEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketTransmittedEventDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketTransmittedEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PacketTransmittedEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_datarate
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PacketTransmittedEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "datarate",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PacketTransmittedEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "datarate") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketTransmittedEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bps",    // FIELD_datarate
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketTransmittedEventDescriptor::getFieldPropertyNames(int field) const
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

const char *PacketTransmittedEventDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PacketTransmittedEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketTransmittedEventDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketTransmittedEvent'", field);
    }
}

const char *PacketTransmittedEventDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacketTransmittedEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        case FIELD_datarate: return unit2string(pp->getDatarate());
        default: return "";
    }
}

void PacketTransmittedEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        case FIELD_datarate: pp->setDatarate(bps(string2double(value))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketTransmittedEvent'", field);
    }
}

const char *PacketTransmittedEventDescriptor::getFieldStructName(int field) const
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

void *PacketTransmittedEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void PacketTransmittedEventDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketTransmittedEvent *pp = (PacketTransmittedEvent *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketTransmittedEvent'", field);
    }
}

Register_Class(PacketEventTag)

PacketEventTag::PacketEventTag() : ::inet::TagBase()
{
}

PacketEventTag::PacketEventTag(const PacketEventTag& other) : ::inet::TagBase(other)
{
    copy(other);
}

PacketEventTag::~PacketEventTag()
{
    delete [] this->packetEvents;
}

PacketEventTag& PacketEventTag::operator=(const PacketEventTag& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void PacketEventTag::copy(const PacketEventTag& other)
{
    delete [] this->packetEvents;
    this->packetEvents = (other.packetEvents_arraysize==0) ? nullptr : new PacketEvent *[other.packetEvents_arraysize];
    packetEvents_arraysize = other.packetEvents_arraysize;
    for (size_t i = 0; i < packetEvents_arraysize; i++) {
        this->packetEvents[i] = other.packetEvents[i];
    }
}

void PacketEventTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    b->pack(packetEvents_arraysize);
    doParsimArrayPacking(b,this->packetEvents,packetEvents_arraysize);
}

void PacketEventTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    delete [] this->packetEvents;
    b->unpack(packetEvents_arraysize);
    if (packetEvents_arraysize == 0) {
        this->packetEvents = nullptr;
    } else {
        this->packetEvents = new PacketEvent *[packetEvents_arraysize];
        doParsimArrayUnpacking(b,this->packetEvents,packetEvents_arraysize);
    }
}

size_t PacketEventTag::getPacketEventsArraySize() const
{
    return packetEvents_arraysize;
}

const PacketEvent * PacketEventTag::getPacketEvents(size_t k) const
{
    if (k >= packetEvents_arraysize) throw omnetpp::cRuntimeError("Array of size packetEvents_arraysize indexed by %lu", (unsigned long)k);
    return this->packetEvents[k];
}

void PacketEventTag::setPacketEventsArraySize(size_t newSize)
{
    PacketEvent * *packetEvents2 = (newSize==0) ? nullptr : new PacketEvent *[newSize];
    size_t minSize = packetEvents_arraysize < newSize ? packetEvents_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        packetEvents2[i] = this->packetEvents[i];
    for (size_t i = minSize; i < newSize; i++)
        packetEvents2[i] = nullptr;
    delete [] this->packetEvents;
    this->packetEvents = packetEvents2;
    packetEvents_arraysize = newSize;
}

void PacketEventTag::setPacketEvents(size_t k, PacketEvent * packetEvents)
{
    if (k >= packetEvents_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->packetEvents[k] = packetEvents;
}

void PacketEventTag::insertPacketEvents(size_t k, PacketEvent * packetEvents)
{
    if (k > packetEvents_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = packetEvents_arraysize + 1;
    PacketEvent * *packetEvents2 = new PacketEvent *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        packetEvents2[i] = this->packetEvents[i];
    packetEvents2[k] = packetEvents;
    for (i = k + 1; i < newSize; i++)
        packetEvents2[i] = this->packetEvents[i-1];
    delete [] this->packetEvents;
    this->packetEvents = packetEvents2;
    packetEvents_arraysize = newSize;
}

void PacketEventTag::insertPacketEvents(PacketEvent * packetEvents)
{
    insertPacketEvents(packetEvents_arraysize, packetEvents);
}

void PacketEventTag::erasePacketEvents(size_t k)
{
    if (k >= packetEvents_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = packetEvents_arraysize - 1;
    PacketEvent * *packetEvents2 = (newSize == 0) ? nullptr : new PacketEvent *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        packetEvents2[i] = this->packetEvents[i];
    for (i = k; i < newSize; i++)
        packetEvents2[i] = this->packetEvents[i+1];
    delete [] this->packetEvents;
    this->packetEvents = packetEvents2;
    packetEvents_arraysize = newSize;
}

class PacketEventTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_packetEvents,
    };
  public:
    PacketEventTagDescriptor();
    virtual ~PacketEventTagDescriptor();

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

Register_ClassDescriptor(PacketEventTagDescriptor)

PacketEventTagDescriptor::PacketEventTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketEventTag)), "inet::TagBase")
{
    propertynames = nullptr;
}

PacketEventTagDescriptor::~PacketEventTagDescriptor()
{
    delete[] propertynames;
}

bool PacketEventTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketEventTag *>(obj)!=nullptr;
}

const char **PacketEventTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketEventTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketEventTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PacketEventTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE | FD_ISRESIZABLE,    // FIELD_packetEvents
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PacketEventTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetEvents",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PacketEventTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetEvents") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketEventTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::PacketEvent",    // FIELD_packetEvents
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketEventTagDescriptor::getFieldPropertyNames(int field) const
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

const char *PacketEventTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PacketEventTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: return pp->getPacketEventsArraySize();
        default: return 0;
    }
}

void PacketEventTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: pp->setPacketEventsArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketEventTag'", field);
    }
}

const char *PacketEventTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: { const PacketEvent * value = pp->getPacketEvents(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string PacketEventTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: {std::stringstream out; out << pp->getPacketEvents(i); return out.str();}
        default: return "";
    }
}

void PacketEventTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketEventTag'", field);
    }
}

const char *PacketEventTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_packetEvents: return omnetpp::opp_typename(typeid(PacketEvent));
        default: return nullptr;
    };
}

void *PacketEventTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: return toVoidPtr(pp->getPacketEvents(i)); break;
        default: return nullptr;
    }
}

void PacketEventTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketEventTag *pp = (PacketEventTag *)object; (void)pp;
    switch (field) {
        case FIELD_packetEvents: pp->setPacketEvents(i,(PacketEvent *)ptr); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketEventTag'", field);
    }
}

} // namespace inet

