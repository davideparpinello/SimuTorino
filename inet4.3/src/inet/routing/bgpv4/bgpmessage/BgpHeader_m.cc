//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/bgpv4/bgpmessage/BgpHeader.msg.
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
#include "BgpHeader_m.h"

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
namespace bgp {

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

Register_Class(BgpAsPathSegment)

BgpAsPathSegment::BgpAsPathSegment() : ::omnetpp::cObject()
{
}

BgpAsPathSegment::BgpAsPathSegment(const BgpAsPathSegment& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BgpAsPathSegment::~BgpAsPathSegment()
{
    delete [] this->asValue;
}

BgpAsPathSegment& BgpAsPathSegment::operator=(const BgpAsPathSegment& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BgpAsPathSegment::copy(const BgpAsPathSegment& other)
{
    this->type = other.type;
    this->length = other.length;
    delete [] this->asValue;
    this->asValue = (other.asValue_arraysize==0) ? nullptr : new uint16_t[other.asValue_arraysize];
    asValue_arraysize = other.asValue_arraysize;
    for (size_t i = 0; i < asValue_arraysize; i++) {
        this->asValue[i] = other.asValue[i];
    }
}

void BgpAsPathSegment::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
    b->pack(asValue_arraysize);
    doParsimArrayPacking(b,this->asValue,asValue_arraysize);
}

void BgpAsPathSegment::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
    delete [] this->asValue;
    b->unpack(asValue_arraysize);
    if (asValue_arraysize == 0) {
        this->asValue = nullptr;
    } else {
        this->asValue = new uint16_t[asValue_arraysize];
        doParsimArrayUnpacking(b,this->asValue,asValue_arraysize);
    }
}

inet::bgp::BgpPathSegmentType BgpAsPathSegment::getType() const
{
    return this->type;
}

void BgpAsPathSegment::setType(inet::bgp::BgpPathSegmentType type)
{
    this->type = type;
}

uint8_t BgpAsPathSegment::getLength() const
{
    return this->length;
}

void BgpAsPathSegment::setLength(uint8_t length)
{
    this->length = length;
}

size_t BgpAsPathSegment::getAsValueArraySize() const
{
    return asValue_arraysize;
}

uint16_t BgpAsPathSegment::getAsValue(size_t k) const
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size asValue_arraysize indexed by %lu", (unsigned long)k);
    return this->asValue[k];
}

void BgpAsPathSegment::setAsValueArraySize(size_t newSize)
{
    uint16_t *asValue2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = asValue_arraysize < newSize ? asValue_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        asValue2[i] = this->asValue[i];
    for (size_t i = minSize; i < newSize; i++)
        asValue2[i] = 0;
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

void BgpAsPathSegment::setAsValue(size_t k, uint16_t asValue)
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->asValue[k] = asValue;
}

void BgpAsPathSegment::insertAsValue(size_t k, uint16_t asValue)
{
    if (k > asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asValue_arraysize + 1;
    uint16_t *asValue2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asValue2[i] = this->asValue[i];
    asValue2[k] = asValue;
    for (i = k + 1; i < newSize; i++)
        asValue2[i] = this->asValue[i-1];
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

void BgpAsPathSegment::insertAsValue(uint16_t asValue)
{
    insertAsValue(asValue_arraysize, asValue);
}

void BgpAsPathSegment::eraseAsValue(size_t k)
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asValue_arraysize - 1;
    uint16_t *asValue2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asValue2[i] = this->asValue[i];
    for (i = k; i < newSize; i++)
        asValue2[i] = this->asValue[i+1];
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

class BgpAsPathSegmentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_length,
        FIELD_asValue,
    };
  public:
    BgpAsPathSegmentDescriptor();
    virtual ~BgpAsPathSegmentDescriptor();

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

Register_ClassDescriptor(BgpAsPathSegmentDescriptor)

BgpAsPathSegmentDescriptor::BgpAsPathSegmentDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpAsPathSegment)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

BgpAsPathSegmentDescriptor::~BgpAsPathSegmentDescriptor()
{
    delete[] propertynames;
}

bool BgpAsPathSegmentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpAsPathSegment *>(obj)!=nullptr;
}

const char **BgpAsPathSegmentDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpAsPathSegmentDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpAsPathSegmentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BgpAsPathSegmentDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_asValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BgpAsPathSegmentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "length",
        "asValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BgpAsPathSegmentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asValue") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpAsPathSegmentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpPathSegmentType",    // FIELD_type
        "uint8_t",    // FIELD_length
        "uint16_t",    // FIELD_asValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpAsPathSegmentDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpAsPathSegmentDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpPathSegmentType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpAsPathSegmentDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_asValue: return pp->getAsValueArraySize();
        default: return 0;
    }
}

void BgpAsPathSegmentDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_asValue: pp->setAsValueArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpAsPathSegment'", field);
    }
}

const char *BgpAsPathSegmentDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpAsPathSegmentDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::bgp::BgpPathSegmentType");
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_asValue: return ulong2string(pp->getAsValue(i));
        default: return "";
    }
}

void BgpAsPathSegmentDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::bgp::BgpPathSegmentType)string2enum(value, "inet::bgp::BgpPathSegmentType")); break;
        case FIELD_length: pp->setLength(string2ulong(value)); break;
        case FIELD_asValue: pp->setAsValue(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpAsPathSegment'", field);
    }
}

const char *BgpAsPathSegmentDescriptor::getFieldStructName(int field) const
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

void *BgpAsPathSegmentDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpAsPathSegmentDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpAsPathSegment'", field);
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BgpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BgpType"));
    e->insert(BGP_OPEN, "BGP_OPEN");
    e->insert(BGP_UPDATE, "BGP_UPDATE");
    e->insert(BGP_NOTIFICATION, "BGP_NOTIFICATION");
    e->insert(BGP_KEEPALIVE, "BGP_KEEPALIVE");
)

Register_Class(BgpHeader)

BgpHeader::BgpHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(BGP_HEADER_OCTETS);

    std::fill(this->marker, this->marker + 16, 0xFF);
}

BgpHeader::BgpHeader(const BgpHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

BgpHeader::~BgpHeader()
{
}

BgpHeader& BgpHeader::operator=(const BgpHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void BgpHeader::copy(const BgpHeader& other)
{
    for (size_t i = 0; i < 16; i++) {
        this->marker[i] = other.marker[i];
    }
    this->totalLength = other.totalLength;
    this->type = other.type;
}

void BgpHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimArrayPacking(b,this->marker,16);
    doParsimPacking(b,this->totalLength);
    doParsimPacking(b,this->type);
}

void BgpHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->marker,16);
    doParsimUnpacking(b,this->totalLength);
    doParsimUnpacking(b,this->type);
}

size_t BgpHeader::getMarkerArraySize() const
{
    return 16;
}

uint8_t BgpHeader::getMarker(size_t k) const
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size 16 indexed by %lu", (unsigned long)k);
    return this->marker[k];
}

void BgpHeader::setMarker(size_t k, uint8_t marker)
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size 16 indexed by %lu", (unsigned long)k);
    handleChange();
    this->marker[k] = marker;
}

uint16_t BgpHeader::getTotalLength() const
{
    return this->totalLength;
}

void BgpHeader::setTotalLength(uint16_t totalLength)
{
    handleChange();
    this->totalLength = totalLength;
}

inet::bgp::BgpType BgpHeader::getType() const
{
    return this->type;
}

void BgpHeader::setType(inet::bgp::BgpType type)
{
    handleChange();
    this->type = type;
}

class BgpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_marker,
        FIELD_totalLength,
        FIELD_type,
    };
  public:
    BgpHeaderDescriptor();
    virtual ~BgpHeaderDescriptor();

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

Register_ClassDescriptor(BgpHeaderDescriptor)

BgpHeaderDescriptor::BgpHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

BgpHeaderDescriptor::~BgpHeaderDescriptor()
{
    delete[] propertynames;
}

bool BgpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpHeader *>(obj)!=nullptr;
}

const char **BgpHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BgpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_marker
        FD_ISEDITABLE,    // FIELD_totalLength
        FD_ISEDITABLE,    // FIELD_type
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BgpHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "marker",
        "totalLength",
        "type",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BgpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "marker") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalLength") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_marker
        "uint16_t",    // FIELD_totalLength
        "inet::bgp::BgpType",    // FIELD_type
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_marker: return 16;
        default: return 0;
    }
}

void BgpHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpHeader'", field);
    }
}

const char *BgpHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_marker: return ulong2string(pp->getMarker(i));
        case FIELD_totalLength: return ulong2string(pp->getTotalLength());
        case FIELD_type: return enum2string(pp->getType(), "inet::bgp::BgpType");
        default: return "";
    }
}

void BgpHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_marker: pp->setMarker(i,string2ulong(value)); break;
        case FIELD_totalLength: pp->setTotalLength(string2ulong(value)); break;
        case FIELD_type: pp->setType((inet::bgp::BgpType)string2enum(value, "inet::bgp::BgpType")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpHeader'", field);
    }
}

const char *BgpHeaderDescriptor::getFieldStructName(int field) const
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

void *BgpHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpHeader'", field);
    }
}

Register_Class(BgpKeepAliveMessage)

BgpKeepAliveMessage::BgpKeepAliveMessage() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_KEEPALIVE);
}

BgpKeepAliveMessage::BgpKeepAliveMessage(const BgpKeepAliveMessage& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpKeepAliveMessage::~BgpKeepAliveMessage()
{
}

BgpKeepAliveMessage& BgpKeepAliveMessage::operator=(const BgpKeepAliveMessage& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpKeepAliveMessage::copy(const BgpKeepAliveMessage& other)
{
}

void BgpKeepAliveMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
}

void BgpKeepAliveMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
}

class BgpKeepAliveMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    BgpKeepAliveMessageDescriptor();
    virtual ~BgpKeepAliveMessageDescriptor();

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

Register_ClassDescriptor(BgpKeepAliveMessageDescriptor)

BgpKeepAliveMessageDescriptor::BgpKeepAliveMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpKeepAliveMessage)), "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpKeepAliveMessageDescriptor::~BgpKeepAliveMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpKeepAliveMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpKeepAliveMessage *>(obj)!=nullptr;
}

const char **BgpKeepAliveMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpKeepAliveMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpKeepAliveMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BgpKeepAliveMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BgpKeepAliveMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BgpKeepAliveMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpKeepAliveMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BgpKeepAliveMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpKeepAliveMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpKeepAliveMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpKeepAliveMessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpKeepAliveMessage'", field);
    }
}

const char *BgpKeepAliveMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpKeepAliveMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void BgpKeepAliveMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpKeepAliveMessage'", field);
    }
}

const char *BgpKeepAliveMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BgpKeepAliveMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpKeepAliveMessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpKeepAliveMessage'", field);
    }
}

BgpOptionalParameterBase::BgpOptionalParameterBase()
{
}

BgpOptionalParameterBase::BgpOptionalParameterBase(const BgpOptionalParameterBase& other)
{
    copy(other);
}

BgpOptionalParameterBase::~BgpOptionalParameterBase()
{
}

BgpOptionalParameterBase& BgpOptionalParameterBase::operator=(const BgpOptionalParameterBase& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void BgpOptionalParameterBase::copy(const BgpOptionalParameterBase& other)
{
    this->parameterType = other.parameterType;
    this->parameterValueLength = other.parameterValueLength;
}

void BgpOptionalParameterBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->parameterType);
    doParsimPacking(b,this->parameterValueLength);
}

void BgpOptionalParameterBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->parameterType);
    doParsimUnpacking(b,this->parameterValueLength);
}

short BgpOptionalParameterBase::getParameterType() const
{
    return this->parameterType;
}

void BgpOptionalParameterBase::setParameterType(short parameterType)
{
    this->parameterType = parameterType;
}

unsigned short BgpOptionalParameterBase::getParameterValueLength() const
{
    return this->parameterValueLength;
}

void BgpOptionalParameterBase::setParameterValueLength(unsigned short parameterValueLength)
{
    this->parameterValueLength = parameterValueLength;
}

class BgpOptionalParameterBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameterType,
        FIELD_parameterValueLength,
    };
  public:
    BgpOptionalParameterBaseDescriptor();
    virtual ~BgpOptionalParameterBaseDescriptor();

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

Register_ClassDescriptor(BgpOptionalParameterBaseDescriptor)

BgpOptionalParameterBaseDescriptor::BgpOptionalParameterBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpOptionalParameterBase)), "")
{
    propertynames = nullptr;
}

BgpOptionalParameterBaseDescriptor::~BgpOptionalParameterBaseDescriptor()
{
    delete[] propertynames;
}

bool BgpOptionalParameterBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpOptionalParameterBase *>(obj)!=nullptr;
}

const char **BgpOptionalParameterBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "packetData",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpOptionalParameterBaseDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "packetData")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpOptionalParameterBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpOptionalParameterBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_parameterType
        FD_ISEDITABLE,    // FIELD_parameterValueLength
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpOptionalParameterBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterType",
        "parameterValueLength",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpOptionalParameterBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterType") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterValueLength") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpOptionalParameterBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_parameterType
        "unsigned short",    // FIELD_parameterValueLength
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpOptionalParameterBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpOptionalParameterBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpOptionalParameterBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpOptionalParameterBaseDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpOptionalParameterBase'", field);
    }
}

const char *BgpOptionalParameterBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpOptionalParameterBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: return long2string(pp->getParameterType());
        case FIELD_parameterValueLength: return ulong2string(pp->getParameterValueLength());
        default: return "";
    }
}

void BgpOptionalParameterBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: pp->setParameterType(string2long(value)); break;
        case FIELD_parameterValueLength: pp->setParameterValueLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOptionalParameterBase'", field);
    }
}

const char *BgpOptionalParameterBaseDescriptor::getFieldStructName(int field) const
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

void *BgpOptionalParameterBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpOptionalParameterBaseDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterBase *pp = (BgpOptionalParameterBase *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOptionalParameterBase'", field);
    }
}

BgpOptionalParameterRaw::BgpOptionalParameterRaw() : ::inet::bgp::BgpOptionalParameterBase()
{
}

BgpOptionalParameterRaw::BgpOptionalParameterRaw(const BgpOptionalParameterRaw& other) : ::inet::bgp::BgpOptionalParameterBase(other)
{
    copy(other);
}

BgpOptionalParameterRaw::~BgpOptionalParameterRaw()
{
    delete [] this->value;
}

BgpOptionalParameterRaw& BgpOptionalParameterRaw::operator=(const BgpOptionalParameterRaw& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpOptionalParameterBase::operator=(other);
    copy(other);
    return *this;
}

void BgpOptionalParameterRaw::copy(const BgpOptionalParameterRaw& other)
{
    delete [] this->value;
    this->value = (other.value_arraysize==0) ? nullptr : new char[other.value_arraysize];
    value_arraysize = other.value_arraysize;
    for (size_t i = 0; i < value_arraysize; i++) {
        this->value[i] = other.value[i];
    }
}

void BgpOptionalParameterRaw::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::bgp::BgpOptionalParameterBase&)*this);
    b->pack(value_arraysize);
    doParsimArrayPacking(b,this->value,value_arraysize);
}

void BgpOptionalParameterRaw::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::bgp::BgpOptionalParameterBase&)*this);
    delete [] this->value;
    b->unpack(value_arraysize);
    if (value_arraysize == 0) {
        this->value = nullptr;
    } else {
        this->value = new char[value_arraysize];
        doParsimArrayUnpacking(b,this->value,value_arraysize);
    }
}

size_t BgpOptionalParameterRaw::getValueArraySize() const
{
    return value_arraysize;
}

char BgpOptionalParameterRaw::getValue(size_t k) const
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size value_arraysize indexed by %lu", (unsigned long)k);
    return this->value[k];
}

void BgpOptionalParameterRaw::setValueArraySize(size_t newSize)
{
    char *value2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = value_arraysize < newSize ? value_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        value2[i] = this->value[i];
    for (size_t i = minSize; i < newSize; i++)
        value2[i] = 0;
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpOptionalParameterRaw::setValue(size_t k, char value)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->value[k] = value;
}

void BgpOptionalParameterRaw::insertValue(size_t k, char value)
{
    if (k > value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize + 1;
    char *value2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    value2[k] = value;
    for (i = k + 1; i < newSize; i++)
        value2[i] = this->value[i-1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpOptionalParameterRaw::insertValue(char value)
{
    insertValue(value_arraysize, value);
}

void BgpOptionalParameterRaw::eraseValue(size_t k)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize - 1;
    char *value2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    for (i = k; i < newSize; i++)
        value2[i] = this->value[i+1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

class BgpOptionalParameterRawDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpOptionalParameterRawDescriptor();
    virtual ~BgpOptionalParameterRawDescriptor();

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

Register_ClassDescriptor(BgpOptionalParameterRawDescriptor)

BgpOptionalParameterRawDescriptor::BgpOptionalParameterRawDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpOptionalParameterRaw)), "inet::bgp::BgpOptionalParameterBase")
{
    propertynames = nullptr;
}

BgpOptionalParameterRawDescriptor::~BgpOptionalParameterRawDescriptor()
{
    delete[] propertynames;
}

bool BgpOptionalParameterRawDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpOptionalParameterRaw *>(obj)!=nullptr;
}

const char **BgpOptionalParameterRawDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpOptionalParameterRawDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpOptionalParameterRawDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpOptionalParameterRawDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpOptionalParameterRawDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpOptionalParameterRawDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpOptionalParameterRawDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpOptionalParameterRawDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpOptionalParameterRawDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpOptionalParameterRawDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        case FIELD_value: return pp->getValueArraySize();
        default: return 0;
    }
}

void BgpOptionalParameterRawDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValueArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpOptionalParameterRaw'", field);
    }
}

const char *BgpOptionalParameterRawDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpOptionalParameterRawDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        case FIELD_value: return long2string(pp->getValue(i));
        default: return "";
    }
}

void BgpOptionalParameterRawDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOptionalParameterRaw'", field);
    }
}

const char *BgpOptionalParameterRawDescriptor::getFieldStructName(int field) const
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

void *BgpOptionalParameterRawDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpOptionalParameterRawDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameterRaw *pp = (BgpOptionalParameterRaw *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOptionalParameterRaw'", field);
    }
}

Register_Class(BgpOpenMessage)

BgpOpenMessage::BgpOpenMessage() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_OPEN);
    this->setChunkLength(BGP_HEADER_OCTETS + BGP_OPEN_OCTETS);
    this->setTotalLength(B(BGP_HEADER_OCTETS + BGP_OPEN_OCTETS).get());

}

BgpOpenMessage::BgpOpenMessage(const BgpOpenMessage& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpOpenMessage::~BgpOpenMessage()
{
    for (size_t i = 0; i < optionalParameter_arraysize; i++)
        delete this->optionalParameter[i];
    delete [] this->optionalParameter;
}

BgpOpenMessage& BgpOpenMessage::operator=(const BgpOpenMessage& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpOpenMessage::copy(const BgpOpenMessage& other)
{
    this->version = other.version;
    this->myAS = other.myAS;
    this->holdTime = other.holdTime;
    this->BGPIdentifier = other.BGPIdentifier;
    this->optionalParametersLength = other.optionalParametersLength;
    for (size_t i = 0; i < optionalParameter_arraysize; i++)
        delete this->optionalParameter[i];
    delete [] this->optionalParameter;
    this->optionalParameter = (other.optionalParameter_arraysize==0) ? nullptr : new BgpOptionalParameterBase *[other.optionalParameter_arraysize];
    optionalParameter_arraysize = other.optionalParameter_arraysize;
    for (size_t i = 0; i < optionalParameter_arraysize; i++) {
        this->optionalParameter[i] = other.optionalParameter[i];
        if (this->optionalParameter[i] != nullptr) {
            this->optionalParameter[i] = new BgpOptionalParameterBase(*this->optionalParameter[i]);
        }
    }
}

void BgpOpenMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->myAS);
    doParsimPacking(b,this->holdTime);
    doParsimPacking(b,this->BGPIdentifier);
    doParsimPacking(b,this->optionalParametersLength);
    b->pack(optionalParameter_arraysize);
    doParsimArrayPacking(b,this->optionalParameter,optionalParameter_arraysize);
}

void BgpOpenMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->myAS);
    doParsimUnpacking(b,this->holdTime);
    doParsimUnpacking(b,this->BGPIdentifier);
    doParsimUnpacking(b,this->optionalParametersLength);
    delete [] this->optionalParameter;
    b->unpack(optionalParameter_arraysize);
    if (optionalParameter_arraysize == 0) {
        this->optionalParameter = nullptr;
    } else {
        this->optionalParameter = new BgpOptionalParameterBase *[optionalParameter_arraysize];
        doParsimArrayUnpacking(b,this->optionalParameter,optionalParameter_arraysize);
    }
}

uint8_t BgpOpenMessage::getVersion() const
{
    return this->version;
}

void BgpOpenMessage::setVersion(uint8_t version)
{
    handleChange();
    this->version = version;
}

uint16_t BgpOpenMessage::getMyAS() const
{
    return this->myAS;
}

void BgpOpenMessage::setMyAS(uint16_t myAS)
{
    handleChange();
    this->myAS = myAS;
}

omnetpp::simtime_t BgpOpenMessage::getHoldTime() const
{
    return this->holdTime;
}

void BgpOpenMessage::setHoldTime(omnetpp::simtime_t holdTime)
{
    handleChange();
    this->holdTime = holdTime;
}

const Ipv4Address& BgpOpenMessage::getBGPIdentifier() const
{
    return this->BGPIdentifier;
}

void BgpOpenMessage::setBGPIdentifier(const Ipv4Address& BGPIdentifier)
{
    handleChange();
    this->BGPIdentifier = BGPIdentifier;
}

unsigned short BgpOpenMessage::getOptionalParametersLength() const
{
    return this->optionalParametersLength;
}

void BgpOpenMessage::setOptionalParametersLength(unsigned short optionalParametersLength)
{
    handleChange();
    this->optionalParametersLength = optionalParametersLength;
}

size_t BgpOpenMessage::getOptionalParameterArraySize() const
{
    return optionalParameter_arraysize;
}

const BgpOptionalParameterBase * BgpOpenMessage::getOptionalParameter(size_t k) const
{
    if (k >= optionalParameter_arraysize) throw omnetpp::cRuntimeError("Array of size optionalParameter_arraysize indexed by %lu", (unsigned long)k);
    return this->optionalParameter[k];
}

void BgpOpenMessage::setOptionalParameterArraySize(size_t newSize)
{
    handleChange();
    BgpOptionalParameterBase * *optionalParameter2 = (newSize==0) ? nullptr : new BgpOptionalParameterBase *[newSize];
    size_t minSize = optionalParameter_arraysize < newSize ? optionalParameter_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        optionalParameter2[i] = this->optionalParameter[i];
    for (size_t i = minSize; i < newSize; i++)
        optionalParameter2[i] = nullptr;
    for (size_t i = newSize; i < optionalParameter_arraysize; i++)
        delete optionalParameter[i];
    delete [] this->optionalParameter;
    this->optionalParameter = optionalParameter2;
    optionalParameter_arraysize = newSize;
}

void BgpOpenMessage::setOptionalParameter(size_t k, BgpOptionalParameterBase * optionalParameter)
{
    if (k >= optionalParameter_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    if (this->optionalParameter[k] != nullptr) throw omnetpp::cRuntimeError("setOptionalParameter(): a value is already set, remove it first with dropOptionalParameter()");
    this->optionalParameter[k] = optionalParameter;
}

BgpOptionalParameterBase * BgpOpenMessage::dropOptionalParameter(size_t k)
{
    if (k >= optionalParameter_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    BgpOptionalParameterBase * retval = this->optionalParameter[k];
    this->optionalParameter[k] = nullptr;
    return retval;
}

void BgpOpenMessage::insertOptionalParameter(size_t k, BgpOptionalParameterBase * optionalParameter)
{
    if (k > optionalParameter_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = optionalParameter_arraysize + 1;
    BgpOptionalParameterBase * *optionalParameter2 = new BgpOptionalParameterBase *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        optionalParameter2[i] = this->optionalParameter[i];
    optionalParameter2[k] = optionalParameter;
    for (i = k + 1; i < newSize; i++)
        optionalParameter2[i] = this->optionalParameter[i-1];
    delete [] this->optionalParameter;
    this->optionalParameter = optionalParameter2;
    optionalParameter_arraysize = newSize;
}

void BgpOpenMessage::insertOptionalParameter(BgpOptionalParameterBase * optionalParameter)
{
    insertOptionalParameter(optionalParameter_arraysize, optionalParameter);
}

void BgpOpenMessage::eraseOptionalParameter(size_t k)
{
    if (k >= optionalParameter_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = optionalParameter_arraysize - 1;
    BgpOptionalParameterBase * *optionalParameter2 = (newSize == 0) ? nullptr : new BgpOptionalParameterBase *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        optionalParameter2[i] = this->optionalParameter[i];
    for (i = k; i < newSize; i++)
        optionalParameter2[i] = this->optionalParameter[i+1];
    delete this->optionalParameter[k];
    delete [] this->optionalParameter;
    this->optionalParameter = optionalParameter2;
    optionalParameter_arraysize = newSize;
}

class BgpOpenMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_myAS,
        FIELD_holdTime,
        FIELD_BGPIdentifier,
        FIELD_optionalParametersLength,
        FIELD_optionalParameter,
    };
  public:
    BgpOpenMessageDescriptor();
    virtual ~BgpOpenMessageDescriptor();

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

Register_ClassDescriptor(BgpOpenMessageDescriptor)

BgpOpenMessageDescriptor::BgpOpenMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpOpenMessage)), "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpOpenMessageDescriptor::~BgpOpenMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpOpenMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpOpenMessage *>(obj)!=nullptr;
}

const char **BgpOpenMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpOpenMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpOpenMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int BgpOpenMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_myAS
        0,    // FIELD_holdTime
        0,    // FIELD_BGPIdentifier
        FD_ISEDITABLE,    // FIELD_optionalParametersLength
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISREPLACEABLE | FD_ISRESIZABLE,    // FIELD_optionalParameter
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *BgpOpenMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "myAS",
        "holdTime",
        "BGPIdentifier",
        "optionalParametersLength",
        "optionalParameter",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int BgpOpenMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "myAS") == 0) return base+1;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTime") == 0) return base+2;
    if (fieldName[0] == 'B' && strcmp(fieldName, "BGPIdentifier") == 0) return base+3;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionalParametersLength") == 0) return base+4;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionalParameter") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpOpenMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_version
        "uint16_t",    // FIELD_myAS
        "omnetpp::simtime_t",    // FIELD_holdTime
        "inet::Ipv4Address",    // FIELD_BGPIdentifier
        "unsigned short",    // FIELD_optionalParametersLength
        "inet::bgp::BgpOptionalParameterBase",    // FIELD_optionalParameter
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpOpenMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_optionalParameter: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpOpenMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_optionalParameter:
            if (!strcmp(propertyname, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int BgpOpenMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_optionalParameter: return pp->getOptionalParameterArraySize();
        default: return 0;
    }
}

void BgpOpenMessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_optionalParameter: pp->setOptionalParameterArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpOpenMessage'", field);
    }
}

const char *BgpOpenMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_optionalParameter: { const BgpOptionalParameterBase * value = pp->getOptionalParameter(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string BgpOpenMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: return ulong2string(pp->getVersion());
        case FIELD_myAS: return ulong2string(pp->getMyAS());
        case FIELD_holdTime: return simtime2string(pp->getHoldTime());
        case FIELD_BGPIdentifier: return pp->getBGPIdentifier().str();
        case FIELD_optionalParametersLength: return ulong2string(pp->getOptionalParametersLength());
        case FIELD_optionalParameter: {std::stringstream out; out << pp->getOptionalParameter(i); return out.str();}
        default: return "";
    }
}

void BgpOpenMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2ulong(value)); break;
        case FIELD_myAS: pp->setMyAS(string2ulong(value)); break;
        case FIELD_optionalParametersLength: pp->setOptionalParametersLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOpenMessage'", field);
    }
}

const char *BgpOpenMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_optionalParameter: return omnetpp::opp_typename(typeid(BgpOptionalParameterBase));
        default: return nullptr;
    };
}

void *BgpOpenMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_BGPIdentifier: return toVoidPtr(&pp->getBGPIdentifier()); break;
        case FIELD_optionalParameter: return toVoidPtr(pp->getOptionalParameter(i)); break;
        default: return nullptr;
    }
}

void BgpOpenMessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_optionalParameter: pp->setOptionalParameter(i,(BgpOptionalParameterBase *)ptr); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpOpenMessage'", field);
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BgpUpdateAttributeTypeCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BgpUpdateAttributeTypeCode"));
    e->insert(ORIGIN, "ORIGIN");
    e->insert(AS_PATH, "AS_PATH");
    e->insert(NEXT_HOP, "NEXT_HOP");
    e->insert(MULTI_EXIT_DISC, "MULTI_EXIT_DISC");
    e->insert(LOCAL_PREF, "LOCAL_PREF");
    e->insert(ATOMIC_AGGREGATE, "ATOMIC_AGGREGATE");
    e->insert(AGGREGATOR, "AGGREGATOR");
)

Register_Class(BgpUpdatePathAttributes)

BgpUpdatePathAttributes::BgpUpdatePathAttributes() : ::omnetpp::cObject()
{
}

BgpUpdatePathAttributes::BgpUpdatePathAttributes(const BgpUpdatePathAttributes& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BgpUpdatePathAttributes::~BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributes& BgpUpdatePathAttributes::operator=(const BgpUpdatePathAttributes& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributes::copy(const BgpUpdatePathAttributes& other)
{
    this->optionalBit = other.optionalBit;
    this->transitiveBit = other.transitiveBit;
    this->partialBit = other.partialBit;
    this->extendedLengthBit = other.extendedLengthBit;
    this->reserved = other.reserved;
    this->typeCode = other.typeCode;
    this->length = other.length;
}

void BgpUpdatePathAttributes::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->optionalBit);
    doParsimPacking(b,this->transitiveBit);
    doParsimPacking(b,this->partialBit);
    doParsimPacking(b,this->extendedLengthBit);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->typeCode);
    doParsimPacking(b,this->length);
}

void BgpUpdatePathAttributes::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->optionalBit);
    doParsimUnpacking(b,this->transitiveBit);
    doParsimUnpacking(b,this->partialBit);
    doParsimUnpacking(b,this->extendedLengthBit);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->typeCode);
    doParsimUnpacking(b,this->length);
}

bool BgpUpdatePathAttributes::getOptionalBit() const
{
    return this->optionalBit;
}

void BgpUpdatePathAttributes::setOptionalBit(bool optionalBit)
{
    this->optionalBit = optionalBit;
}

bool BgpUpdatePathAttributes::getTransitiveBit() const
{
    return this->transitiveBit;
}

void BgpUpdatePathAttributes::setTransitiveBit(bool transitiveBit)
{
    this->transitiveBit = transitiveBit;
}

bool BgpUpdatePathAttributes::getPartialBit() const
{
    return this->partialBit;
}

void BgpUpdatePathAttributes::setPartialBit(bool partialBit)
{
    this->partialBit = partialBit;
}

bool BgpUpdatePathAttributes::getExtendedLengthBit() const
{
    return this->extendedLengthBit;
}

void BgpUpdatePathAttributes::setExtendedLengthBit(bool extendedLengthBit)
{
    this->extendedLengthBit = extendedLengthBit;
}

unsigned short BgpUpdatePathAttributes::getReserved() const
{
    return this->reserved;
}

void BgpUpdatePathAttributes::setReserved(unsigned short reserved)
{
    this->reserved = reserved;
}

inet::bgp::BgpUpdateAttributeTypeCode BgpUpdatePathAttributes::getTypeCode() const
{
    return this->typeCode;
}

void BgpUpdatePathAttributes::setTypeCode(inet::bgp::BgpUpdateAttributeTypeCode typeCode)
{
    this->typeCode = typeCode;
}

unsigned short BgpUpdatePathAttributes::getLength() const
{
    return this->length;
}

void BgpUpdatePathAttributes::setLength(unsigned short length)
{
    this->length = length;
}

class BgpUpdatePathAttributesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_optionalBit,
        FIELD_transitiveBit,
        FIELD_partialBit,
        FIELD_extendedLengthBit,
        FIELD_reserved,
        FIELD_typeCode,
        FIELD_length,
    };
  public:
    BgpUpdatePathAttributesDescriptor();
    virtual ~BgpUpdatePathAttributesDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesDescriptor)

BgpUpdatePathAttributesDescriptor::BgpUpdatePathAttributesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributes)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesDescriptor::~BgpUpdatePathAttributesDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributes *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int BgpUpdatePathAttributesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_optionalBit
        FD_ISEDITABLE,    // FIELD_transitiveBit
        FD_ISEDITABLE,    // FIELD_partialBit
        FD_ISEDITABLE,    // FIELD_extendedLengthBit
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_typeCode
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "optionalBit",
        "transitiveBit",
        "partialBit",
        "extendedLengthBit",
        "reserved",
        "typeCode",
        "length",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionalBit") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "transitiveBit") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "partialBit") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "extendedLengthBit") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeCode") == 0) return base+5;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_optionalBit
        "bool",    // FIELD_transitiveBit
        "bool",    // FIELD_partialBit
        "bool",    // FIELD_extendedLengthBit
        "unsigned short",    // FIELD_reserved
        "inet::bgp::BgpUpdateAttributeTypeCode",    // FIELD_typeCode
        "unsigned short",    // FIELD_length
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_typeCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdatePathAttributesDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_typeCode:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpUpdateAttributeTypeCode";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdatePathAttributesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributes'", field);
    }
}

const char *BgpUpdatePathAttributesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case FIELD_optionalBit: return bool2string(pp->getOptionalBit());
        case FIELD_transitiveBit: return bool2string(pp->getTransitiveBit());
        case FIELD_partialBit: return bool2string(pp->getPartialBit());
        case FIELD_extendedLengthBit: return bool2string(pp->getExtendedLengthBit());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_typeCode: return enum2string(pp->getTypeCode(), "inet::bgp::BgpUpdateAttributeTypeCode");
        case FIELD_length: return ulong2string(pp->getLength());
        default: return "";
    }
}

void BgpUpdatePathAttributesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case FIELD_optionalBit: pp->setOptionalBit(string2bool(value)); break;
        case FIELD_transitiveBit: pp->setTransitiveBit(string2bool(value)); break;
        case FIELD_partialBit: pp->setPartialBit(string2bool(value)); break;
        case FIELD_extendedLengthBit: pp->setExtendedLengthBit(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_typeCode: pp->setTypeCode((inet::bgp::BgpUpdateAttributeTypeCode)string2enum(value, "inet::bgp::BgpUpdateAttributeTypeCode")); break;
        case FIELD_length: pp->setLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributes'", field);
    }
}

const char *BgpUpdatePathAttributesDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributes'", field);
    }
}

Register_Class(BgpUpdatePathAttributesOrigin)

BgpUpdatePathAttributesOrigin::BgpUpdatePathAttributesOrigin() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(ORIGIN);
    this->setOptionalBit(false);
    this->setTransitiveBit(true);
    this->setLength(1);

}

BgpUpdatePathAttributesOrigin::BgpUpdatePathAttributesOrigin(const BgpUpdatePathAttributesOrigin& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesOrigin::~BgpUpdatePathAttributesOrigin()
{
}

BgpUpdatePathAttributesOrigin& BgpUpdatePathAttributesOrigin::operator=(const BgpUpdatePathAttributesOrigin& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesOrigin::copy(const BgpUpdatePathAttributesOrigin& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesOrigin::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesOrigin::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

inet::bgp::BgpSessionType BgpUpdatePathAttributesOrigin::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesOrigin::setValue(inet::bgp::BgpSessionType value)
{
    this->value = value;
}

class BgpUpdatePathAttributesOriginDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesOriginDescriptor();
    virtual ~BgpUpdatePathAttributesOriginDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesOriginDescriptor)

BgpUpdatePathAttributesOriginDescriptor::BgpUpdatePathAttributesOriginDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesOrigin)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesOriginDescriptor::~BgpUpdatePathAttributesOriginDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesOriginDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesOrigin *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesOriginDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesOriginDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesOriginDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesOriginDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpSessionType",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesOriginDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpSessionType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdatePathAttributesOriginDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesOriginDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesOrigin'", field);
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesOriginDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        case FIELD_value: return enum2string(pp->getValue(), "inet::bgp::BgpSessionType");
        default: return "";
    }
}

void BgpUpdatePathAttributesOriginDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue((inet::bgp::BgpSessionType)string2enum(value, "inet::bgp::BgpSessionType")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesOrigin'", field);
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesOriginDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesOriginDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesOrigin'", field);
    }
}

Register_Class(BgpUpdatePathAttributesAsPath)

BgpUpdatePathAttributesAsPath::BgpUpdatePathAttributesAsPath() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(AS_PATH);
    this->setOptionalBit(false);
    this->setTransitiveBit(true);
    this->setLength(0);

}

BgpUpdatePathAttributesAsPath::BgpUpdatePathAttributesAsPath(const BgpUpdatePathAttributesAsPath& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesAsPath::~BgpUpdatePathAttributesAsPath()
{
    delete [] this->value;
}

BgpUpdatePathAttributesAsPath& BgpUpdatePathAttributesAsPath::operator=(const BgpUpdatePathAttributesAsPath& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesAsPath::copy(const BgpUpdatePathAttributesAsPath& other)
{
    delete [] this->value;
    this->value = (other.value_arraysize==0) ? nullptr : new BgpAsPathSegment[other.value_arraysize];
    value_arraysize = other.value_arraysize;
    for (size_t i = 0; i < value_arraysize; i++) {
        this->value[i] = other.value[i];
    }
}

void BgpUpdatePathAttributesAsPath::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    b->pack(value_arraysize);
    doParsimArrayPacking(b,this->value,value_arraysize);
}

void BgpUpdatePathAttributesAsPath::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    delete [] this->value;
    b->unpack(value_arraysize);
    if (value_arraysize == 0) {
        this->value = nullptr;
    } else {
        this->value = new BgpAsPathSegment[value_arraysize];
        doParsimArrayUnpacking(b,this->value,value_arraysize);
    }
}

size_t BgpUpdatePathAttributesAsPath::getValueArraySize() const
{
    return value_arraysize;
}

const BgpAsPathSegment& BgpUpdatePathAttributesAsPath::getValue(size_t k) const
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size value_arraysize indexed by %lu", (unsigned long)k);
    return this->value[k];
}

void BgpUpdatePathAttributesAsPath::setValueArraySize(size_t newSize)
{
    BgpAsPathSegment *value2 = (newSize==0) ? nullptr : new BgpAsPathSegment[newSize];
    size_t minSize = value_arraysize < newSize ? value_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        value2[i] = this->value[i];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpUpdatePathAttributesAsPath::setValue(size_t k, const BgpAsPathSegment& value)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->value[k] = value;
}

void BgpUpdatePathAttributesAsPath::insertValue(size_t k, const BgpAsPathSegment& value)
{
    if (k > value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize + 1;
    BgpAsPathSegment *value2 = new BgpAsPathSegment[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    value2[k] = value;
    for (i = k + 1; i < newSize; i++)
        value2[i] = this->value[i-1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpUpdatePathAttributesAsPath::insertValue(const BgpAsPathSegment& value)
{
    insertValue(value_arraysize, value);
}

void BgpUpdatePathAttributesAsPath::eraseValue(size_t k)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize - 1;
    BgpAsPathSegment *value2 = (newSize == 0) ? nullptr : new BgpAsPathSegment[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    for (i = k; i < newSize; i++)
        value2[i] = this->value[i+1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

class BgpUpdatePathAttributesAsPathDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesAsPathDescriptor();
    virtual ~BgpUpdatePathAttributesAsPathDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesAsPathDescriptor)

BgpUpdatePathAttributesAsPathDescriptor::BgpUpdatePathAttributesAsPathDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesAsPath)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesAsPathDescriptor::~BgpUpdatePathAttributesAsPathDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesAsPathDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesAsPath *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesAsPathDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesAsPathDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesAsPathDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISRESIZABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesAsPathDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpAsPathSegment",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesAsPathDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesAsPathDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: return pp->getValueArraySize();
        default: return 0;
    }
}

void BgpUpdatePathAttributesAsPathDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValueArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesAsPath'", field);
    }
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesAsPathDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: {std::stringstream out; out << pp->getValue(i); return out.str();}
        default: return "";
    }
}

void BgpUpdatePathAttributesAsPathDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAsPath'", field);
    }
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value: return omnetpp::opp_typename(typeid(BgpAsPathSegment));
        default: return nullptr;
    };
}

void *BgpUpdatePathAttributesAsPathDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: return toVoidPtr(&pp->getValue(i)); break;
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesAsPathDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAsPath'", field);
    }
}

Register_Class(BgpUpdatePathAttributesNextHop)

BgpUpdatePathAttributesNextHop::BgpUpdatePathAttributesNextHop() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(NEXT_HOP);
    this->setOptionalBit(false);
    this->setTransitiveBit(true);
    this->setLength(4);

}

BgpUpdatePathAttributesNextHop::BgpUpdatePathAttributesNextHop(const BgpUpdatePathAttributesNextHop& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesNextHop::~BgpUpdatePathAttributesNextHop()
{
}

BgpUpdatePathAttributesNextHop& BgpUpdatePathAttributesNextHop::operator=(const BgpUpdatePathAttributesNextHop& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesNextHop::copy(const BgpUpdatePathAttributesNextHop& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesNextHop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesNextHop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

const Ipv4Address& BgpUpdatePathAttributesNextHop::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesNextHop::setValue(const Ipv4Address& value)
{
    this->value = value;
}

class BgpUpdatePathAttributesNextHopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesNextHopDescriptor();
    virtual ~BgpUpdatePathAttributesNextHopDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesNextHopDescriptor)

BgpUpdatePathAttributesNextHopDescriptor::BgpUpdatePathAttributesNextHopDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesNextHop)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesNextHopDescriptor::~BgpUpdatePathAttributesNextHopDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesNextHopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesNextHop *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesNextHopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesNextHopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesNextHopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesNextHopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesNextHopDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesNextHopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesNextHopDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesNextHop'", field);
    }
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesNextHopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case FIELD_value: return pp->getValue().str();
        default: return "";
    }
}

void BgpUpdatePathAttributesNextHopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesNextHop'", field);
    }
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesNextHopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case FIELD_value: return toVoidPtr(&pp->getValue()); break;
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesNextHopDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesNextHop'", field);
    }
}

Register_Class(BgpUpdatePathAttributesMultiExitDisc)

BgpUpdatePathAttributesMultiExitDisc::BgpUpdatePathAttributesMultiExitDisc() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(MULTI_EXIT_DISC);
    this->setOptionalBit(true);
    this->setTransitiveBit(false);
    this->setLength(4);

}

BgpUpdatePathAttributesMultiExitDisc::BgpUpdatePathAttributesMultiExitDisc(const BgpUpdatePathAttributesMultiExitDisc& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesMultiExitDisc::~BgpUpdatePathAttributesMultiExitDisc()
{
}

BgpUpdatePathAttributesMultiExitDisc& BgpUpdatePathAttributesMultiExitDisc::operator=(const BgpUpdatePathAttributesMultiExitDisc& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesMultiExitDisc::copy(const BgpUpdatePathAttributesMultiExitDisc& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesMultiExitDisc::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesMultiExitDisc::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

uint32_t BgpUpdatePathAttributesMultiExitDisc::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesMultiExitDisc::setValue(uint32_t value)
{
    this->value = value;
}

class BgpUpdatePathAttributesMultiExitDiscDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesMultiExitDiscDescriptor();
    virtual ~BgpUpdatePathAttributesMultiExitDiscDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesMultiExitDiscDescriptor)

BgpUpdatePathAttributesMultiExitDiscDescriptor::BgpUpdatePathAttributesMultiExitDiscDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesMultiExitDisc)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesMultiExitDiscDescriptor::~BgpUpdatePathAttributesMultiExitDiscDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesMultiExitDiscDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesMultiExitDisc *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesMultiExitDiscDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesMultiExitDiscDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesMultiExitDiscDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesMultiExitDisc'", field);
    }
}

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        case FIELD_value: return ulong2string(pp->getValue());
        default: return "";
    }
}

void BgpUpdatePathAttributesMultiExitDiscDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesMultiExitDisc'", field);
    }
}

const char *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesMultiExitDiscDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesMultiExitDiscDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesMultiExitDisc *pp = (BgpUpdatePathAttributesMultiExitDisc *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesMultiExitDisc'", field);
    }
}

Register_Class(BgpUpdatePathAttributesLocalPref)

BgpUpdatePathAttributesLocalPref::BgpUpdatePathAttributesLocalPref() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(LOCAL_PREF);
    this->setOptionalBit(false);
    this->setTransitiveBit(true);
    this->setLength(4);

}

BgpUpdatePathAttributesLocalPref::BgpUpdatePathAttributesLocalPref(const BgpUpdatePathAttributesLocalPref& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesLocalPref::~BgpUpdatePathAttributesLocalPref()
{
}

BgpUpdatePathAttributesLocalPref& BgpUpdatePathAttributesLocalPref::operator=(const BgpUpdatePathAttributesLocalPref& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesLocalPref::copy(const BgpUpdatePathAttributesLocalPref& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesLocalPref::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesLocalPref::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

uint32_t BgpUpdatePathAttributesLocalPref::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesLocalPref::setValue(uint32_t value)
{
    this->value = value;
}

class BgpUpdatePathAttributesLocalPrefDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesLocalPrefDescriptor();
    virtual ~BgpUpdatePathAttributesLocalPrefDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesLocalPrefDescriptor)

BgpUpdatePathAttributesLocalPrefDescriptor::BgpUpdatePathAttributesLocalPrefDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesLocalPref)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesLocalPrefDescriptor::~BgpUpdatePathAttributesLocalPrefDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesLocalPrefDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesLocalPref *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesLocalPrefDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesLocalPrefDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesLocalPrefDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesLocalPrefDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesLocalPref'", field);
    }
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesLocalPrefDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case FIELD_value: return ulong2string(pp->getValue());
        default: return "";
    }
}

void BgpUpdatePathAttributesLocalPrefDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesLocalPref'", field);
    }
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesLocalPrefDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesLocalPref'", field);
    }
}

Register_Class(BgpUpdatePathAttributesAtomicAggregate)

BgpUpdatePathAttributesAtomicAggregate::BgpUpdatePathAttributesAtomicAggregate() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(ATOMIC_AGGREGATE);
    this->setOptionalBit(false);
    this->setTransitiveBit(true);
    this->setLength(0);
}

BgpUpdatePathAttributesAtomicAggregate::BgpUpdatePathAttributesAtomicAggregate(const BgpUpdatePathAttributesAtomicAggregate& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesAtomicAggregate::~BgpUpdatePathAttributesAtomicAggregate()
{
}

BgpUpdatePathAttributesAtomicAggregate& BgpUpdatePathAttributesAtomicAggregate::operator=(const BgpUpdatePathAttributesAtomicAggregate& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesAtomicAggregate::copy(const BgpUpdatePathAttributesAtomicAggregate& other)
{
}

void BgpUpdatePathAttributesAtomicAggregate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
}

void BgpUpdatePathAttributesAtomicAggregate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
}

class BgpUpdatePathAttributesAtomicAggregateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    BgpUpdatePathAttributesAtomicAggregateDescriptor();
    virtual ~BgpUpdatePathAttributesAtomicAggregateDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesAtomicAggregateDescriptor)

BgpUpdatePathAttributesAtomicAggregateDescriptor::BgpUpdatePathAttributesAtomicAggregateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesAtomicAggregate)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesAtomicAggregateDescriptor::~BgpUpdatePathAttributesAtomicAggregateDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesAtomicAggregateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesAtomicAggregate *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesAtomicAggregateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BgpUpdatePathAttributesAtomicAggregateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesAtomicAggregateDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesAtomicAggregate'", field);
    }
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void BgpUpdatePathAttributesAtomicAggregateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAtomicAggregate'", field);
    }
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesAtomicAggregateDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAtomicAggregate'", field);
    }
}

Register_Class(BgpUpdatePathAttributesAggregator)

BgpUpdatePathAttributesAggregator::BgpUpdatePathAttributesAggregator() : ::inet::bgp::BgpUpdatePathAttributes()
{
    this->setTypeCode(AGGREGATOR);
    this->setOptionalBit(true);
    this->setTransitiveBit(true);
    this->setLength(6);

}

BgpUpdatePathAttributesAggregator::BgpUpdatePathAttributesAggregator(const BgpUpdatePathAttributesAggregator& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesAggregator::~BgpUpdatePathAttributesAggregator()
{
}

BgpUpdatePathAttributesAggregator& BgpUpdatePathAttributesAggregator::operator=(const BgpUpdatePathAttributesAggregator& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesAggregator::copy(const BgpUpdatePathAttributesAggregator& other)
{
    this->asNumber = other.asNumber;
    this->bgpSpeaker = other.bgpSpeaker;
}

void BgpUpdatePathAttributesAggregator::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->asNumber);
    doParsimPacking(b,this->bgpSpeaker);
}

void BgpUpdatePathAttributesAggregator::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->asNumber);
    doParsimUnpacking(b,this->bgpSpeaker);
}

uint16_t BgpUpdatePathAttributesAggregator::getAsNumber() const
{
    return this->asNumber;
}

void BgpUpdatePathAttributesAggregator::setAsNumber(uint16_t asNumber)
{
    this->asNumber = asNumber;
}

const Ipv4Address& BgpUpdatePathAttributesAggregator::getBgpSpeaker() const
{
    return this->bgpSpeaker;
}

void BgpUpdatePathAttributesAggregator::setBgpSpeaker(const Ipv4Address& bgpSpeaker)
{
    this->bgpSpeaker = bgpSpeaker;
}

class BgpUpdatePathAttributesAggregatorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_asNumber,
        FIELD_bgpSpeaker,
    };
  public:
    BgpUpdatePathAttributesAggregatorDescriptor();
    virtual ~BgpUpdatePathAttributesAggregatorDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesAggregatorDescriptor)

BgpUpdatePathAttributesAggregatorDescriptor::BgpUpdatePathAttributesAggregatorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesAggregator)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesAggregatorDescriptor::~BgpUpdatePathAttributesAggregatorDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesAggregatorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesAggregator *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesAggregatorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesAggregatorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesAggregatorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdatePathAttributesAggregatorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_asNumber
        0,    // FIELD_bgpSpeaker
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesAggregatorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "asNumber",
        "bgpSpeaker",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesAggregatorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asNumber") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bgpSpeaker") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesAggregatorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_asNumber
        "inet::Ipv4Address",    // FIELD_bgpSpeaker
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesAggregatorDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesAggregatorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesAggregatorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdatePathAttributesAggregatorDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdatePathAttributesAggregator'", field);
    }
}

const char *BgpUpdatePathAttributesAggregatorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesAggregatorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        case FIELD_asNumber: return ulong2string(pp->getAsNumber());
        case FIELD_bgpSpeaker: return pp->getBgpSpeaker().str();
        default: return "";
    }
}

void BgpUpdatePathAttributesAggregatorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        case FIELD_asNumber: pp->setAsNumber(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAggregator'", field);
    }
}

const char *BgpUpdatePathAttributesAggregatorDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesAggregatorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        case FIELD_bgpSpeaker: return toVoidPtr(&pp->getBgpSpeaker()); break;
        default: return nullptr;
    }
}

void BgpUpdatePathAttributesAggregatorDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAggregator *pp = (BgpUpdatePathAttributesAggregator *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdatePathAttributesAggregator'", field);
    }
}

BgpUpdateWithdrawnRoutes::BgpUpdateWithdrawnRoutes()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateWithdrawnRoutes& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateWithdrawnRoutes& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BgpUpdateWithdrawnRoutesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_prefix,
    };
  public:
    BgpUpdateWithdrawnRoutesDescriptor();
    virtual ~BgpUpdateWithdrawnRoutesDescriptor();

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

Register_ClassDescriptor(BgpUpdateWithdrawnRoutesDescriptor)

BgpUpdateWithdrawnRoutesDescriptor::BgpUpdateWithdrawnRoutesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateWithdrawnRoutes)), "")
{
    propertynames = nullptr;
}

BgpUpdateWithdrawnRoutesDescriptor::~BgpUpdateWithdrawnRoutesDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateWithdrawnRoutesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateWithdrawnRoutes *>(obj)!=nullptr;
}

const char **BgpUpdateWithdrawnRoutesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateWithdrawnRoutesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdateWithdrawnRoutesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        0,    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdateWithdrawnRoutesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefix") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_length
        "inet::Ipv4Address",    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateWithdrawnRoutesDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateWithdrawnRoutesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdateWithdrawnRoutesDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdateWithdrawnRoutes'", field);
    }
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateWithdrawnRoutesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->length);
        case FIELD_prefix: return pp->prefix.str();
        default: return "";
    }
}

void BgpUpdateWithdrawnRoutesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->length = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateWithdrawnRoutes'", field);
    }
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldStructName(int field) const
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

void *BgpUpdateWithdrawnRoutesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_prefix: return toVoidPtr(&pp->prefix); break;
        default: return nullptr;
    }
}

void BgpUpdateWithdrawnRoutesDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateWithdrawnRoutes'", field);
    }
}

BgpUpdateNlri::BgpUpdateNlri()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateNlri& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateNlri& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BgpUpdateNlriDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_prefix,
    };
  public:
    BgpUpdateNlriDescriptor();
    virtual ~BgpUpdateNlriDescriptor();

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

Register_ClassDescriptor(BgpUpdateNlriDescriptor)

BgpUpdateNlriDescriptor::BgpUpdateNlriDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateNlri)), "")
{
    propertynames = nullptr;
}

BgpUpdateNlriDescriptor::~BgpUpdateNlriDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateNlriDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateNlri *>(obj)!=nullptr;
}

const char **BgpUpdateNlriDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateNlriDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateNlriDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdateNlriDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        0,    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateNlriDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdateNlriDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefix") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateNlriDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_length
        "inet::Ipv4Address",    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateNlriDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateNlriDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateNlriDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BgpUpdateNlriDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdateNlri'", field);
    }
}

const char *BgpUpdateNlriDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateNlriDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->length);
        case FIELD_prefix: return pp->prefix.str();
        default: return "";
    }
}

void BgpUpdateNlriDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->length = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateNlri'", field);
    }
}

const char *BgpUpdateNlriDescriptor::getFieldStructName(int field) const
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

void *BgpUpdateNlriDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_prefix: return toVoidPtr(&pp->prefix); break;
        default: return nullptr;
    }
}

void BgpUpdateNlriDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateNlri'", field);
    }
}

Register_Class(BgpUpdateMessage)

BgpUpdateMessage::BgpUpdateMessage() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_UPDATE);
    this->setChunkLength(BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS);
    this->setTotalLength(B(BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS).get());

}

BgpUpdateMessage::BgpUpdateMessage(const BgpUpdateMessage& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpUpdateMessage::~BgpUpdateMessage()
{
    delete [] this->withdrawnRoutes;
    for (size_t i = 0; i < pathAttributes_arraysize; i++)
        delete this->pathAttributes[i];
    delete [] this->pathAttributes;
    delete [] this->NLRI;
}

BgpUpdateMessage& BgpUpdateMessage::operator=(const BgpUpdateMessage& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdateMessage::copy(const BgpUpdateMessage& other)
{
    this->withDrawnRoutesLength = other.withDrawnRoutesLength;
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = (other.withdrawnRoutes_arraysize==0) ? nullptr : new BgpUpdateWithdrawnRoutes[other.withdrawnRoutes_arraysize];
    withdrawnRoutes_arraysize = other.withdrawnRoutes_arraysize;
    for (size_t i = 0; i < withdrawnRoutes_arraysize; i++) {
        this->withdrawnRoutes[i] = other.withdrawnRoutes[i];
    }
    this->totalPathAttributeLength = other.totalPathAttributeLength;
    for (size_t i = 0; i < pathAttributes_arraysize; i++)
        delete this->pathAttributes[i];
    delete [] this->pathAttributes;
    this->pathAttributes = (other.pathAttributes_arraysize==0) ? nullptr : new BgpUpdatePathAttributes *[other.pathAttributes_arraysize];
    pathAttributes_arraysize = other.pathAttributes_arraysize;
    for (size_t i = 0; i < pathAttributes_arraysize; i++) {
        this->pathAttributes[i] = other.pathAttributes[i];
        if (this->pathAttributes[i] != nullptr) {
            this->pathAttributes[i] = this->pathAttributes[i]->dup();
        }
    }
    delete [] this->NLRI;
    this->NLRI = (other.NLRI_arraysize==0) ? nullptr : new BgpUpdateNlri[other.NLRI_arraysize];
    NLRI_arraysize = other.NLRI_arraysize;
    for (size_t i = 0; i < NLRI_arraysize; i++) {
        this->NLRI[i] = other.NLRI[i];
    }
}

void BgpUpdateMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
    doParsimPacking(b,this->withDrawnRoutesLength);
    b->pack(withdrawnRoutes_arraysize);
    doParsimArrayPacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    doParsimPacking(b,this->totalPathAttributeLength);
    b->pack(pathAttributes_arraysize);
    doParsimArrayPacking(b,this->pathAttributes,pathAttributes_arraysize);
    b->pack(NLRI_arraysize);
    doParsimArrayPacking(b,this->NLRI,NLRI_arraysize);
}

void BgpUpdateMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->withDrawnRoutesLength);
    delete [] this->withdrawnRoutes;
    b->unpack(withdrawnRoutes_arraysize);
    if (withdrawnRoutes_arraysize == 0) {
        this->withdrawnRoutes = nullptr;
    } else {
        this->withdrawnRoutes = new BgpUpdateWithdrawnRoutes[withdrawnRoutes_arraysize];
        doParsimArrayUnpacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    }
    doParsimUnpacking(b,this->totalPathAttributeLength);
    delete [] this->pathAttributes;
    b->unpack(pathAttributes_arraysize);
    if (pathAttributes_arraysize == 0) {
        this->pathAttributes = nullptr;
    } else {
        this->pathAttributes = new BgpUpdatePathAttributes *[pathAttributes_arraysize];
        doParsimArrayUnpacking(b,this->pathAttributes,pathAttributes_arraysize);
    }
    delete [] this->NLRI;
    b->unpack(NLRI_arraysize);
    if (NLRI_arraysize == 0) {
        this->NLRI = nullptr;
    } else {
        this->NLRI = new BgpUpdateNlri[NLRI_arraysize];
        doParsimArrayUnpacking(b,this->NLRI,NLRI_arraysize);
    }
}

uint16_t BgpUpdateMessage::getWithDrawnRoutesLength() const
{
    return this->withDrawnRoutesLength;
}

void BgpUpdateMessage::setWithDrawnRoutesLength(uint16_t withDrawnRoutesLength)
{
    handleChange();
    this->withDrawnRoutesLength = withDrawnRoutesLength;
}

size_t BgpUpdateMessage::getWithdrawnRoutesArraySize() const
{
    return withdrawnRoutes_arraysize;
}

const BgpUpdateWithdrawnRoutes& BgpUpdateMessage::getWithdrawnRoutes(size_t k) const
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size withdrawnRoutes_arraysize indexed by %lu", (unsigned long)k);
    return this->withdrawnRoutes[k];
}

void BgpUpdateMessage::setWithdrawnRoutesArraySize(size_t newSize)
{
    handleChange();
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = (newSize==0) ? nullptr : new BgpUpdateWithdrawnRoutes[newSize];
    size_t minSize = withdrawnRoutes_arraysize < newSize ? withdrawnRoutes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

void BgpUpdateMessage::setWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->withdrawnRoutes[k] = withdrawnRoutes;
}

void BgpUpdateMessage::insertWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    if (k > withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = withdrawnRoutes_arraysize + 1;
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = new BgpUpdateWithdrawnRoutes[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    withdrawnRoutes2[k] = withdrawnRoutes;
    for (i = k + 1; i < newSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i-1];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

void BgpUpdateMessage::insertWithdrawnRoutes(const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    insertWithdrawnRoutes(withdrawnRoutes_arraysize, withdrawnRoutes);
}

void BgpUpdateMessage::eraseWithdrawnRoutes(size_t k)
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = withdrawnRoutes_arraysize - 1;
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = (newSize == 0) ? nullptr : new BgpUpdateWithdrawnRoutes[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    for (i = k; i < newSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i+1];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

uint16_t BgpUpdateMessage::getTotalPathAttributeLength() const
{
    return this->totalPathAttributeLength;
}

void BgpUpdateMessage::setTotalPathAttributeLength(uint16_t totalPathAttributeLength)
{
    handleChange();
    this->totalPathAttributeLength = totalPathAttributeLength;
}

size_t BgpUpdateMessage::getPathAttributesArraySize() const
{
    return pathAttributes_arraysize;
}

const BgpUpdatePathAttributes * BgpUpdateMessage::getPathAttributes(size_t k) const
{
    if (k >= pathAttributes_arraysize) throw omnetpp::cRuntimeError("Array of size pathAttributes_arraysize indexed by %lu", (unsigned long)k);
    return this->pathAttributes[k];
}

void BgpUpdateMessage::setPathAttributesArraySize(size_t newSize)
{
    handleChange();
    BgpUpdatePathAttributes * *pathAttributes2 = (newSize==0) ? nullptr : new BgpUpdatePathAttributes *[newSize];
    size_t minSize = pathAttributes_arraysize < newSize ? pathAttributes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        pathAttributes2[i] = this->pathAttributes[i];
    for (size_t i = minSize; i < newSize; i++)
        pathAttributes2[i] = nullptr;
    for (size_t i = newSize; i < pathAttributes_arraysize; i++)
        delete pathAttributes[i];
    delete [] this->pathAttributes;
    this->pathAttributes = pathAttributes2;
    pathAttributes_arraysize = newSize;
}

void BgpUpdateMessage::setPathAttributes(size_t k, BgpUpdatePathAttributes * pathAttributes)
{
    if (k >= pathAttributes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    delete this->pathAttributes[k];
    this->pathAttributes[k] = pathAttributes;
}

BgpUpdatePathAttributes * BgpUpdateMessage::dropPathAttributes(size_t k)
{
    if (k >= pathAttributes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    BgpUpdatePathAttributes * retval = this->pathAttributes[k];
    this->pathAttributes[k] = nullptr;
    return retval;
}

void BgpUpdateMessage::insertPathAttributes(size_t k, BgpUpdatePathAttributes * pathAttributes)
{
    if (k > pathAttributes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = pathAttributes_arraysize + 1;
    BgpUpdatePathAttributes * *pathAttributes2 = new BgpUpdatePathAttributes *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        pathAttributes2[i] = this->pathAttributes[i];
    pathAttributes2[k] = pathAttributes;
    for (i = k + 1; i < newSize; i++)
        pathAttributes2[i] = this->pathAttributes[i-1];
    delete [] this->pathAttributes;
    this->pathAttributes = pathAttributes2;
    pathAttributes_arraysize = newSize;
}

void BgpUpdateMessage::insertPathAttributes(BgpUpdatePathAttributes * pathAttributes)
{
    insertPathAttributes(pathAttributes_arraysize, pathAttributes);
}

void BgpUpdateMessage::erasePathAttributes(size_t k)
{
    if (k >= pathAttributes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = pathAttributes_arraysize - 1;
    BgpUpdatePathAttributes * *pathAttributes2 = (newSize == 0) ? nullptr : new BgpUpdatePathAttributes *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        pathAttributes2[i] = this->pathAttributes[i];
    for (i = k; i < newSize; i++)
        pathAttributes2[i] = this->pathAttributes[i+1];
    delete this->pathAttributes[k];
    delete [] this->pathAttributes;
    this->pathAttributes = pathAttributes2;
    pathAttributes_arraysize = newSize;
}

size_t BgpUpdateMessage::getNLRIArraySize() const
{
    return NLRI_arraysize;
}

const BgpUpdateNlri& BgpUpdateMessage::getNLRI(size_t k) const
{
    if (k >= NLRI_arraysize) throw omnetpp::cRuntimeError("Array of size NLRI_arraysize indexed by %lu", (unsigned long)k);
    return this->NLRI[k];
}

void BgpUpdateMessage::setNLRIArraySize(size_t newSize)
{
    handleChange();
    BgpUpdateNlri *NLRI2 = (newSize==0) ? nullptr : new BgpUpdateNlri[newSize];
    size_t minSize = NLRI_arraysize < newSize ? NLRI_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        NLRI2[i] = this->NLRI[i];
    delete [] this->NLRI;
    this->NLRI = NLRI2;
    NLRI_arraysize = newSize;
}

void BgpUpdateMessage::setNLRI(size_t k, const BgpUpdateNlri& NLRI)
{
    if (k >= NLRI_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->NLRI[k] = NLRI;
}

void BgpUpdateMessage::insertNLRI(size_t k, const BgpUpdateNlri& NLRI)
{
    if (k > NLRI_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = NLRI_arraysize + 1;
    BgpUpdateNlri *NLRI2 = new BgpUpdateNlri[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        NLRI2[i] = this->NLRI[i];
    NLRI2[k] = NLRI;
    for (i = k + 1; i < newSize; i++)
        NLRI2[i] = this->NLRI[i-1];
    delete [] this->NLRI;
    this->NLRI = NLRI2;
    NLRI_arraysize = newSize;
}

void BgpUpdateMessage::insertNLRI(const BgpUpdateNlri& NLRI)
{
    insertNLRI(NLRI_arraysize, NLRI);
}

void BgpUpdateMessage::eraseNLRI(size_t k)
{
    if (k >= NLRI_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = NLRI_arraysize - 1;
    BgpUpdateNlri *NLRI2 = (newSize == 0) ? nullptr : new BgpUpdateNlri[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        NLRI2[i] = this->NLRI[i];
    for (i = k; i < newSize; i++)
        NLRI2[i] = this->NLRI[i+1];
    delete [] this->NLRI;
    this->NLRI = NLRI2;
    NLRI_arraysize = newSize;
}

class BgpUpdateMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_withDrawnRoutesLength,
        FIELD_withdrawnRoutes,
        FIELD_totalPathAttributeLength,
        FIELD_pathAttributes,
        FIELD_NLRI,
    };
  public:
    BgpUpdateMessageDescriptor();
    virtual ~BgpUpdateMessageDescriptor();

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

Register_ClassDescriptor(BgpUpdateMessageDescriptor)

BgpUpdateMessageDescriptor::BgpUpdateMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateMessage)), "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpUpdateMessageDescriptor::~BgpUpdateMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateMessage *>(obj)!=nullptr;
}

const char **BgpUpdateMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BgpUpdateMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_withDrawnRoutesLength
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_withdrawnRoutes
        FD_ISEDITABLE,    // FIELD_totalPathAttributeLength
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE | FD_ISRESIZABLE,    // FIELD_pathAttributes
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_NLRI
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "withDrawnRoutesLength",
        "withdrawnRoutes",
        "totalPathAttributeLength",
        "pathAttributes",
        "NLRI",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int BgpUpdateMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'w' && strcmp(fieldName, "withDrawnRoutesLength") == 0) return base+0;
    if (fieldName[0] == 'w' && strcmp(fieldName, "withdrawnRoutes") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalPathAttributeLength") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pathAttributes") == 0) return base+3;
    if (fieldName[0] == 'N' && strcmp(fieldName, "NLRI") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_withDrawnRoutesLength
        "inet::bgp::BgpUpdateWithdrawnRoutes",    // FIELD_withdrawnRoutes
        "uint16_t",    // FIELD_totalPathAttributeLength
        "inet::bgp::BgpUpdatePathAttributes",    // FIELD_pathAttributes
        "inet::bgp::BgpUpdateNlri",    // FIELD_NLRI
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_pathAttributes: {
            static const char *names[] = { "owned", "allowReplace",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdateMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_pathAttributes:
            if (!strcmp(propertyname, "owned")) return "";
            if (!strcmp(propertyname, "allowReplace")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdateMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: return pp->getWithdrawnRoutesArraySize();
        case FIELD_pathAttributes: return pp->getPathAttributesArraySize();
        case FIELD_NLRI: return pp->getNLRIArraySize();
        default: return 0;
    }
}

void BgpUpdateMessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: pp->setWithdrawnRoutesArraySize(size); break;
        case FIELD_pathAttributes: pp->setPathAttributesArraySize(size); break;
        case FIELD_NLRI: pp->setNLRIArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BgpUpdateMessage'", field);
    }
}

const char *BgpUpdateMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_pathAttributes: { const BgpUpdatePathAttributes * value = pp->getPathAttributes(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string BgpUpdateMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_withDrawnRoutesLength: return ulong2string(pp->getWithDrawnRoutesLength());
        case FIELD_withdrawnRoutes: {std::stringstream out; out << pp->getWithdrawnRoutes(i); return out.str();}
        case FIELD_totalPathAttributeLength: return ulong2string(pp->getTotalPathAttributeLength());
        case FIELD_pathAttributes: {std::stringstream out; out << pp->getPathAttributes(i); return out.str();}
        case FIELD_NLRI: {std::stringstream out; out << pp->getNLRI(i); return out.str();}
        default: return "";
    }
}

void BgpUpdateMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_withDrawnRoutesLength: pp->setWithDrawnRoutesLength(string2ulong(value)); break;
        case FIELD_totalPathAttributeLength: pp->setTotalPathAttributeLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateMessage'", field);
    }
}

const char *BgpUpdateMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_withdrawnRoutes: return omnetpp::opp_typename(typeid(BgpUpdateWithdrawnRoutes));
        case FIELD_pathAttributes: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributes));
        case FIELD_NLRI: return omnetpp::opp_typename(typeid(BgpUpdateNlri));
        default: return nullptr;
    };
}

void *BgpUpdateMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: return toVoidPtr(&pp->getWithdrawnRoutes(i)); break;
        case FIELD_pathAttributes: return toVoidPtr(pp->getPathAttributes(i)); break;
        case FIELD_NLRI: return toVoidPtr(&pp->getNLRI(i)); break;
        default: return nullptr;
    }
}

void BgpUpdateMessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage *pp = (BgpUpdateMessage *)object; (void)pp;
    switch (field) {
        case FIELD_pathAttributes: pp->setPathAttributes(i,(BgpUpdatePathAttributes *)ptr); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BgpUpdateMessage'", field);
    }
}

} // namespace bgp
} // namespace inet

