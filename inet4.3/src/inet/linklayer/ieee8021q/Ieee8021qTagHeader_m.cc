//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ieee8021q/Ieee8021qTagHeader.msg.
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
#include "Ieee8021qTagHeader_m.h"

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

Register_Class(Ieee8021qTagTpidHeader)

Ieee8021qTagTpidHeader::Ieee8021qTagTpidHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ieee8021qTagTpidHeader::Ieee8021qTagTpidHeader(const Ieee8021qTagTpidHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee8021qTagTpidHeader::~Ieee8021qTagTpidHeader()
{
}

Ieee8021qTagTpidHeader& Ieee8021qTagTpidHeader::operator=(const Ieee8021qTagTpidHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee8021qTagTpidHeader::copy(const Ieee8021qTagTpidHeader& other)
{
    this->tpid = other.tpid;
    this->pcp = other.pcp;
    this->dei = other.dei;
    this->vid = other.vid;
}

void Ieee8021qTagTpidHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->tpid);
    doParsimPacking(b,this->pcp);
    doParsimPacking(b,this->dei);
    doParsimPacking(b,this->vid);
}

void Ieee8021qTagTpidHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->tpid);
    doParsimUnpacking(b,this->pcp);
    doParsimUnpacking(b,this->dei);
    doParsimUnpacking(b,this->vid);
}

uint16_t Ieee8021qTagTpidHeader::getTpid() const
{
    return this->tpid;
}

void Ieee8021qTagTpidHeader::setTpid(uint16_t tpid)
{
    handleChange();
    this->tpid = tpid;
}

uint8_t Ieee8021qTagTpidHeader::getPcp() const
{
    return this->pcp;
}

void Ieee8021qTagTpidHeader::setPcp(uint8_t pcp)
{
    handleChange();
    this->pcp = pcp;
}

bool Ieee8021qTagTpidHeader::getDei() const
{
    return this->dei;
}

void Ieee8021qTagTpidHeader::setDei(bool dei)
{
    handleChange();
    this->dei = dei;
}

uint16_t Ieee8021qTagTpidHeader::getVid() const
{
    return this->vid;
}

void Ieee8021qTagTpidHeader::setVid(uint16_t vid)
{
    handleChange();
    this->vid = vid;
}

class Ieee8021qTagTpidHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tpid,
        FIELD_pcp,
        FIELD_dei,
        FIELD_vid,
    };
  public:
    Ieee8021qTagTpidHeaderDescriptor();
    virtual ~Ieee8021qTagTpidHeaderDescriptor();

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

Register_ClassDescriptor(Ieee8021qTagTpidHeaderDescriptor)

Ieee8021qTagTpidHeaderDescriptor::Ieee8021qTagTpidHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ieee8021qTagTpidHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee8021qTagTpidHeaderDescriptor::~Ieee8021qTagTpidHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee8021qTagTpidHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee8021qTagTpidHeader *>(obj)!=nullptr;
}

const char **Ieee8021qTagTpidHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee8021qTagTpidHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee8021qTagTpidHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee8021qTagTpidHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tpid
        FD_ISEDITABLE,    // FIELD_pcp
        FD_ISEDITABLE,    // FIELD_dei
        FD_ISEDITABLE,    // FIELD_vid
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee8021qTagTpidHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tpid",
        "pcp",
        "dei",
        "vid",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee8021qTagTpidHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tpid") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pcp") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dei") == 0) return base+2;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vid") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee8021qTagTpidHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_tpid
        "uint8_t",    // FIELD_pcp
        "bool",    // FIELD_dei
        "uint16_t",    // FIELD_vid
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee8021qTagTpidHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee8021qTagTpidHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee8021qTagTpidHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ieee8021qTagTpidHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ieee8021qTagTpidHeader'", field);
    }
}

const char *Ieee8021qTagTpidHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee8021qTagTpidHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tpid: return ulong2string(pp->getTpid());
        case FIELD_pcp: return ulong2string(pp->getPcp());
        case FIELD_dei: return bool2string(pp->getDei());
        case FIELD_vid: return ulong2string(pp->getVid());
        default: return "";
    }
}

void Ieee8021qTagTpidHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tpid: pp->setTpid(string2ulong(value)); break;
        case FIELD_pcp: pp->setPcp(string2ulong(value)); break;
        case FIELD_dei: pp->setDei(string2bool(value)); break;
        case FIELD_vid: pp->setVid(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021qTagTpidHeader'", field);
    }
}

const char *Ieee8021qTagTpidHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee8021qTagTpidHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ieee8021qTagTpidHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagTpidHeader *pp = (Ieee8021qTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021qTagTpidHeader'", field);
    }
}

Register_Class(Ieee8021qTagEpdHeader)

Ieee8021qTagEpdHeader::Ieee8021qTagEpdHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ieee8021qTagEpdHeader::Ieee8021qTagEpdHeader(const Ieee8021qTagEpdHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee8021qTagEpdHeader::~Ieee8021qTagEpdHeader()
{
}

Ieee8021qTagEpdHeader& Ieee8021qTagEpdHeader::operator=(const Ieee8021qTagEpdHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee8021qTagEpdHeader::copy(const Ieee8021qTagEpdHeader& other)
{
    this->pcp = other.pcp;
    this->dei = other.dei;
    this->vid = other.vid;
    this->typeOrLength = other.typeOrLength;
}

void Ieee8021qTagEpdHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->pcp);
    doParsimPacking(b,this->dei);
    doParsimPacking(b,this->vid);
    doParsimPacking(b,this->typeOrLength);
}

void Ieee8021qTagEpdHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->pcp);
    doParsimUnpacking(b,this->dei);
    doParsimUnpacking(b,this->vid);
    doParsimUnpacking(b,this->typeOrLength);
}

uint8_t Ieee8021qTagEpdHeader::getPcp() const
{
    return this->pcp;
}

void Ieee8021qTagEpdHeader::setPcp(uint8_t pcp)
{
    handleChange();
    this->pcp = pcp;
}

bool Ieee8021qTagEpdHeader::getDei() const
{
    return this->dei;
}

void Ieee8021qTagEpdHeader::setDei(bool dei)
{
    handleChange();
    this->dei = dei;
}

uint16_t Ieee8021qTagEpdHeader::getVid() const
{
    return this->vid;
}

void Ieee8021qTagEpdHeader::setVid(uint16_t vid)
{
    handleChange();
    this->vid = vid;
}

uint16_t Ieee8021qTagEpdHeader::getTypeOrLength() const
{
    return this->typeOrLength;
}

void Ieee8021qTagEpdHeader::setTypeOrLength(uint16_t typeOrLength)
{
    handleChange();
    this->typeOrLength = typeOrLength;
}

class Ieee8021qTagEpdHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_pcp,
        FIELD_dei,
        FIELD_vid,
        FIELD_typeOrLength,
    };
  public:
    Ieee8021qTagEpdHeaderDescriptor();
    virtual ~Ieee8021qTagEpdHeaderDescriptor();

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

Register_ClassDescriptor(Ieee8021qTagEpdHeaderDescriptor)

Ieee8021qTagEpdHeaderDescriptor::Ieee8021qTagEpdHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ieee8021qTagEpdHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee8021qTagEpdHeaderDescriptor::~Ieee8021qTagEpdHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee8021qTagEpdHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee8021qTagEpdHeader *>(obj)!=nullptr;
}

const char **Ieee8021qTagEpdHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee8021qTagEpdHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee8021qTagEpdHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee8021qTagEpdHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_pcp
        FD_ISEDITABLE,    // FIELD_dei
        FD_ISEDITABLE,    // FIELD_vid
        FD_ISEDITABLE,    // FIELD_typeOrLength
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee8021qTagEpdHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pcp",
        "dei",
        "vid",
        "typeOrLength",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee8021qTagEpdHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pcp") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dei") == 0) return base+1;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vid") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeOrLength") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee8021qTagEpdHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_pcp
        "bool",    // FIELD_dei
        "uint16_t",    // FIELD_vid
        "uint16_t",    // FIELD_typeOrLength
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee8021qTagEpdHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee8021qTagEpdHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee8021qTagEpdHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ieee8021qTagEpdHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ieee8021qTagEpdHeader'", field);
    }
}

const char *Ieee8021qTagEpdHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee8021qTagEpdHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        case FIELD_pcp: return ulong2string(pp->getPcp());
        case FIELD_dei: return bool2string(pp->getDei());
        case FIELD_vid: return ulong2string(pp->getVid());
        case FIELD_typeOrLength: return ulong2string(pp->getTypeOrLength());
        default: return "";
    }
}

void Ieee8021qTagEpdHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        case FIELD_pcp: pp->setPcp(string2ulong(value)); break;
        case FIELD_dei: pp->setDei(string2bool(value)); break;
        case FIELD_vid: pp->setVid(string2ulong(value)); break;
        case FIELD_typeOrLength: pp->setTypeOrLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021qTagEpdHeader'", field);
    }
}

const char *Ieee8021qTagEpdHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee8021qTagEpdHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ieee8021qTagEpdHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021qTagEpdHeader *pp = (Ieee8021qTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021qTagEpdHeader'", field);
    }
}

} // namespace inet

