//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ieee8021ae/Ieee8021aeTagHeader.msg.
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
#include "Ieee8021aeTagHeader_m.h"

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

Register_Class(Ieee8021aeTagTpidHeader)

Ieee8021aeTagTpidHeader::Ieee8021aeTagTpidHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(8));

}

Ieee8021aeTagTpidHeader::Ieee8021aeTagTpidHeader(const Ieee8021aeTagTpidHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee8021aeTagTpidHeader::~Ieee8021aeTagTpidHeader()
{
}

Ieee8021aeTagTpidHeader& Ieee8021aeTagTpidHeader::operator=(const Ieee8021aeTagTpidHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee8021aeTagTpidHeader::copy(const Ieee8021aeTagTpidHeader& other)
{
    this->tpid = other.tpid;
    this->tciAn = other.tciAn;
    this->sl = other.sl;
    this->pn = other.pn;
    this->sci = other.sci;
}

void Ieee8021aeTagTpidHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->tpid);
    doParsimPacking(b,this->tciAn);
    doParsimPacking(b,this->sl);
    doParsimPacking(b,this->pn);
    doParsimPacking(b,this->sci);
}

void Ieee8021aeTagTpidHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->tpid);
    doParsimUnpacking(b,this->tciAn);
    doParsimUnpacking(b,this->sl);
    doParsimUnpacking(b,this->pn);
    doParsimUnpacking(b,this->sci);
}

uint16_t Ieee8021aeTagTpidHeader::getTpid() const
{
    return this->tpid;
}

void Ieee8021aeTagTpidHeader::setTpid(uint16_t tpid)
{
    handleChange();
    this->tpid = tpid;
}

uint8_t Ieee8021aeTagTpidHeader::getTciAn() const
{
    return this->tciAn;
}

void Ieee8021aeTagTpidHeader::setTciAn(uint8_t tciAn)
{
    handleChange();
    this->tciAn = tciAn;
}

uint8_t Ieee8021aeTagTpidHeader::getSl() const
{
    return this->sl;
}

void Ieee8021aeTagTpidHeader::setSl(uint8_t sl)
{
    handleChange();
    this->sl = sl;
}

uint32_t Ieee8021aeTagTpidHeader::getPn() const
{
    return this->pn;
}

void Ieee8021aeTagTpidHeader::setPn(uint32_t pn)
{
    handleChange();
    this->pn = pn;
}

uint64_t Ieee8021aeTagTpidHeader::getSci() const
{
    return this->sci;
}

void Ieee8021aeTagTpidHeader::setSci(uint64_t sci)
{
    handleChange();
    this->sci = sci;
}

class Ieee8021aeTagTpidHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tpid,
        FIELD_tciAn,
        FIELD_sl,
        FIELD_pn,
        FIELD_sci,
    };
  public:
    Ieee8021aeTagTpidHeaderDescriptor();
    virtual ~Ieee8021aeTagTpidHeaderDescriptor();

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

Register_ClassDescriptor(Ieee8021aeTagTpidHeaderDescriptor)

Ieee8021aeTagTpidHeaderDescriptor::Ieee8021aeTagTpidHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ieee8021aeTagTpidHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee8021aeTagTpidHeaderDescriptor::~Ieee8021aeTagTpidHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee8021aeTagTpidHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee8021aeTagTpidHeader *>(obj)!=nullptr;
}

const char **Ieee8021aeTagTpidHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee8021aeTagTpidHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee8021aeTagTpidHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ieee8021aeTagTpidHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tpid
        FD_ISEDITABLE,    // FIELD_tciAn
        FD_ISEDITABLE,    // FIELD_sl
        FD_ISEDITABLE,    // FIELD_pn
        FD_ISEDITABLE,    // FIELD_sci
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ieee8021aeTagTpidHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tpid",
        "tciAn",
        "sl",
        "pn",
        "sci",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ieee8021aeTagTpidHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tpid") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tciAn") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sl") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pn") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sci") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee8021aeTagTpidHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_tpid
        "uint8_t",    // FIELD_tciAn
        "uint8_t",    // FIELD_sl
        "uint32_t",    // FIELD_pn
        "uint64_t",    // FIELD_sci
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee8021aeTagTpidHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee8021aeTagTpidHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee8021aeTagTpidHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ieee8021aeTagTpidHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ieee8021aeTagTpidHeader'", field);
    }
}

const char *Ieee8021aeTagTpidHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee8021aeTagTpidHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tpid: return ulong2string(pp->getTpid());
        case FIELD_tciAn: return ulong2string(pp->getTciAn());
        case FIELD_sl: return ulong2string(pp->getSl());
        case FIELD_pn: return ulong2string(pp->getPn());
        case FIELD_sci: return uint642string(pp->getSci());
        default: return "";
    }
}

void Ieee8021aeTagTpidHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tpid: pp->setTpid(string2ulong(value)); break;
        case FIELD_tciAn: pp->setTciAn(string2ulong(value)); break;
        case FIELD_sl: pp->setSl(string2ulong(value)); break;
        case FIELD_pn: pp->setPn(string2ulong(value)); break;
        case FIELD_sci: pp->setSci(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021aeTagTpidHeader'", field);
    }
}

const char *Ieee8021aeTagTpidHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee8021aeTagTpidHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ieee8021aeTagTpidHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagTpidHeader *pp = (Ieee8021aeTagTpidHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021aeTagTpidHeader'", field);
    }
}

Register_Class(Ieee8021aeTagEpdHeader)

Ieee8021aeTagEpdHeader::Ieee8021aeTagEpdHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(8));

}

Ieee8021aeTagEpdHeader::Ieee8021aeTagEpdHeader(const Ieee8021aeTagEpdHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee8021aeTagEpdHeader::~Ieee8021aeTagEpdHeader()
{
}

Ieee8021aeTagEpdHeader& Ieee8021aeTagEpdHeader::operator=(const Ieee8021aeTagEpdHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee8021aeTagEpdHeader::copy(const Ieee8021aeTagEpdHeader& other)
{
    this->tciAn = other.tciAn;
    this->sl = other.sl;
    this->pn = other.pn;
    this->sci = other.sci;
    this->typeOrLength = other.typeOrLength;
}

void Ieee8021aeTagEpdHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->tciAn);
    doParsimPacking(b,this->sl);
    doParsimPacking(b,this->pn);
    doParsimPacking(b,this->sci);
    doParsimPacking(b,this->typeOrLength);
}

void Ieee8021aeTagEpdHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->tciAn);
    doParsimUnpacking(b,this->sl);
    doParsimUnpacking(b,this->pn);
    doParsimUnpacking(b,this->sci);
    doParsimUnpacking(b,this->typeOrLength);
}

uint8_t Ieee8021aeTagEpdHeader::getTciAn() const
{
    return this->tciAn;
}

void Ieee8021aeTagEpdHeader::setTciAn(uint8_t tciAn)
{
    handleChange();
    this->tciAn = tciAn;
}

uint8_t Ieee8021aeTagEpdHeader::getSl() const
{
    return this->sl;
}

void Ieee8021aeTagEpdHeader::setSl(uint8_t sl)
{
    handleChange();
    this->sl = sl;
}

uint32_t Ieee8021aeTagEpdHeader::getPn() const
{
    return this->pn;
}

void Ieee8021aeTagEpdHeader::setPn(uint32_t pn)
{
    handleChange();
    this->pn = pn;
}

uint64_t Ieee8021aeTagEpdHeader::getSci() const
{
    return this->sci;
}

void Ieee8021aeTagEpdHeader::setSci(uint64_t sci)
{
    handleChange();
    this->sci = sci;
}

uint16_t Ieee8021aeTagEpdHeader::getTypeOrLength() const
{
    return this->typeOrLength;
}

void Ieee8021aeTagEpdHeader::setTypeOrLength(uint16_t typeOrLength)
{
    handleChange();
    this->typeOrLength = typeOrLength;
}

class Ieee8021aeTagEpdHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tciAn,
        FIELD_sl,
        FIELD_pn,
        FIELD_sci,
        FIELD_typeOrLength,
    };
  public:
    Ieee8021aeTagEpdHeaderDescriptor();
    virtual ~Ieee8021aeTagEpdHeaderDescriptor();

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

Register_ClassDescriptor(Ieee8021aeTagEpdHeaderDescriptor)

Ieee8021aeTagEpdHeaderDescriptor::Ieee8021aeTagEpdHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ieee8021aeTagEpdHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee8021aeTagEpdHeaderDescriptor::~Ieee8021aeTagEpdHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee8021aeTagEpdHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee8021aeTagEpdHeader *>(obj)!=nullptr;
}

const char **Ieee8021aeTagEpdHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee8021aeTagEpdHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee8021aeTagEpdHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ieee8021aeTagEpdHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tciAn
        FD_ISEDITABLE,    // FIELD_sl
        FD_ISEDITABLE,    // FIELD_pn
        FD_ISEDITABLE,    // FIELD_sci
        FD_ISEDITABLE,    // FIELD_typeOrLength
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ieee8021aeTagEpdHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tciAn",
        "sl",
        "pn",
        "sci",
        "typeOrLength",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ieee8021aeTagEpdHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tciAn") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sl") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pn") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sci") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeOrLength") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee8021aeTagEpdHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_tciAn
        "uint8_t",    // FIELD_sl
        "uint32_t",    // FIELD_pn
        "uint64_t",    // FIELD_sci
        "uint16_t",    // FIELD_typeOrLength
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee8021aeTagEpdHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee8021aeTagEpdHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee8021aeTagEpdHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void Ieee8021aeTagEpdHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ieee8021aeTagEpdHeader'", field);
    }
}

const char *Ieee8021aeTagEpdHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee8021aeTagEpdHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tciAn: return ulong2string(pp->getTciAn());
        case FIELD_sl: return ulong2string(pp->getSl());
        case FIELD_pn: return ulong2string(pp->getPn());
        case FIELD_sci: return uint642string(pp->getSci());
        case FIELD_typeOrLength: return ulong2string(pp->getTypeOrLength());
        default: return "";
    }
}

void Ieee8021aeTagEpdHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tciAn: pp->setTciAn(string2ulong(value)); break;
        case FIELD_sl: pp->setSl(string2ulong(value)); break;
        case FIELD_pn: pp->setPn(string2ulong(value)); break;
        case FIELD_sci: pp->setSci(string2uint64(value)); break;
        case FIELD_typeOrLength: pp->setTypeOrLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021aeTagEpdHeader'", field);
    }
}

const char *Ieee8021aeTagEpdHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee8021aeTagEpdHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void Ieee8021aeTagEpdHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Ieee8021aeTagEpdHeader *pp = (Ieee8021aeTagEpdHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ieee8021aeTagEpdHeader'", field);
    }
}

} // namespace inet

