//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg.
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
#include "Ieee8021dBpdu_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::BpduProtocolIdentifier");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::BpduProtocolIdentifier"));
    e->insert(SPANNING_TREE_PROTOCOL, "SPANNING_TREE_PROTOCOL");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::BpduProtocolVersionIdentifier");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::BpduProtocolVersionIdentifier"));
    e->insert(SPANNING_TREE, "SPANNING_TREE");
    e->insert(RAPID_SPANNING_TREE, "RAPID_SPANNING_TREE");
    e->insert(MULTIPLE_SPANNING_TREE, "MULTIPLE_SPANNING_TREE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::BpduType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::BpduType"));
    e->insert(BPDU_CFG, "BPDU_CFG");
    e->insert(BPDU_TCN, "BPDU_TCN");
    e->insert(BPDU_RAPID_OR_MULTIPLE_SPANNING_TREE, "BPDU_RAPID_OR_MULTIPLE_SPANNING_TREE");
)

Register_Class(BpduBase)

BpduBase::BpduBase() : ::inet::FieldsChunk()
{
}

BpduBase::BpduBase(const BpduBase& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

BpduBase::~BpduBase()
{
}

BpduBase& BpduBase::operator=(const BpduBase& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void BpduBase::copy(const BpduBase& other)
{
    this->protocolIdentifier = other.protocolIdentifier;
    this->protocolVersionIdentifier = other.protocolVersionIdentifier;
    this->bpduType = other.bpduType;
}

void BpduBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->protocolIdentifier);
    doParsimPacking(b,this->protocolVersionIdentifier);
    doParsimPacking(b,this->bpduType);
}

void BpduBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->protocolIdentifier);
    doParsimUnpacking(b,this->protocolVersionIdentifier);
    doParsimUnpacking(b,this->bpduType);
}

inet::BpduProtocolIdentifier BpduBase::getProtocolIdentifier() const
{
    return this->protocolIdentifier;
}

void BpduBase::setProtocolIdentifier(inet::BpduProtocolIdentifier protocolIdentifier)
{
    handleChange();
    this->protocolIdentifier = protocolIdentifier;
}

inet::BpduProtocolVersionIdentifier BpduBase::getProtocolVersionIdentifier() const
{
    return this->protocolVersionIdentifier;
}

void BpduBase::setProtocolVersionIdentifier(inet::BpduProtocolVersionIdentifier protocolVersionIdentifier)
{
    handleChange();
    this->protocolVersionIdentifier = protocolVersionIdentifier;
}

inet::BpduType BpduBase::getBpduType() const
{
    return this->bpduType;
}

void BpduBase::setBpduType(inet::BpduType bpduType)
{
    handleChange();
    this->bpduType = bpduType;
}

class BpduBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_protocolIdentifier,
        FIELD_protocolVersionIdentifier,
        FIELD_bpduType,
    };
  public:
    BpduBaseDescriptor();
    virtual ~BpduBaseDescriptor();

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

Register_ClassDescriptor(BpduBaseDescriptor)

BpduBaseDescriptor::BpduBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BpduBase)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

BpduBaseDescriptor::~BpduBaseDescriptor()
{
    delete[] propertynames;
}

bool BpduBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BpduBase *>(obj)!=nullptr;
}

const char **BpduBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BpduBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BpduBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BpduBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_protocolIdentifier
        FD_ISEDITABLE,    // FIELD_protocolVersionIdentifier
        FD_ISEDITABLE,    // FIELD_bpduType
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BpduBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocolIdentifier",
        "protocolVersionIdentifier",
        "bpduType",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BpduBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolIdentifier") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolVersionIdentifier") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bpduType") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BpduBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::BpduProtocolIdentifier",    // FIELD_protocolIdentifier
        "inet::BpduProtocolVersionIdentifier",    // FIELD_protocolVersionIdentifier
        "inet::BpduType",    // FIELD_bpduType
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BpduBaseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolIdentifier: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_protocolVersionIdentifier: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_bpduType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BpduBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolIdentifier:
            if (!strcmp(propertyname, "enum")) return "inet::BpduProtocolIdentifier";
            return nullptr;
        case FIELD_protocolVersionIdentifier:
            if (!strcmp(propertyname, "enum")) return "inet::BpduProtocolVersionIdentifier";
            return nullptr;
        case FIELD_bpduType:
            if (!strcmp(propertyname, "enum")) return "inet::BpduType";
            return nullptr;
        default: return nullptr;
    }
}

int BpduBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BpduBaseDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BpduBase'", field);
    }
}

const char *BpduBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BpduBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        case FIELD_protocolIdentifier: return enum2string(pp->getProtocolIdentifier(), "inet::BpduProtocolIdentifier");
        case FIELD_protocolVersionIdentifier: return enum2string(pp->getProtocolVersionIdentifier(), "inet::BpduProtocolVersionIdentifier");
        case FIELD_bpduType: return enum2string(pp->getBpduType(), "inet::BpduType");
        default: return "";
    }
}

void BpduBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        case FIELD_protocolIdentifier: pp->setProtocolIdentifier((inet::BpduProtocolIdentifier)string2enum(value, "inet::BpduProtocolIdentifier")); break;
        case FIELD_protocolVersionIdentifier: pp->setProtocolVersionIdentifier((inet::BpduProtocolVersionIdentifier)string2enum(value, "inet::BpduProtocolVersionIdentifier")); break;
        case FIELD_bpduType: pp->setBpduType((inet::BpduType)string2enum(value, "inet::BpduType")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduBase'", field);
    }
}

const char *BpduBaseDescriptor::getFieldStructName(int field) const
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

void *BpduBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BpduBaseDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduBase *pp = (BpduBase *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduBase'", field);
    }
}

Register_Class(BpduTcn)

BpduTcn::BpduTcn() : ::inet::BpduBase()
{
    this->setChunkLength(B(4));
    this->setProtocolIdentifier(SPANNING_TREE_PROTOCOL);
    this->setProtocolVersionIdentifier(SPANNING_TREE);
    this->setBpduType(BPDU_TCN);
}

BpduTcn::BpduTcn(const BpduTcn& other) : ::inet::BpduBase(other)
{
    copy(other);
}

BpduTcn::~BpduTcn()
{
}

BpduTcn& BpduTcn::operator=(const BpduTcn& other)
{
    if (this == &other) return *this;
    ::inet::BpduBase::operator=(other);
    copy(other);
    return *this;
}

void BpduTcn::copy(const BpduTcn& other)
{
}

void BpduTcn::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::BpduBase::parsimPack(b);
}

void BpduTcn::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::BpduBase::parsimUnpack(b);
}

class BpduTcnDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    BpduTcnDescriptor();
    virtual ~BpduTcnDescriptor();

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

Register_ClassDescriptor(BpduTcnDescriptor)

BpduTcnDescriptor::BpduTcnDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BpduTcn)), "inet::BpduBase")
{
    propertynames = nullptr;
}

BpduTcnDescriptor::~BpduTcnDescriptor()
{
    delete[] propertynames;
}

bool BpduTcnDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BpduTcn *>(obj)!=nullptr;
}

const char **BpduTcnDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BpduTcnDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BpduTcnDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BpduTcnDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BpduTcnDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BpduTcnDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BpduTcnDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BpduTcnDescriptor::getFieldPropertyNames(int field) const
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

const char *BpduTcnDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BpduTcnDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BpduTcnDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BpduTcn'", field);
    }
}

const char *BpduTcnDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BpduTcnDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void BpduTcnDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduTcn'", field);
    }
}

const char *BpduTcnDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BpduTcnDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void BpduTcnDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduTcn *pp = (BpduTcn *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduTcn'", field);
    }
}

Register_Class(BpduCfg)

BpduCfg::BpduCfg() : ::inet::BpduBase()
{
    this->setChunkLength(B(35));
    this->setProtocolIdentifier(SPANNING_TREE_PROTOCOL);
    this->setProtocolVersionIdentifier(SPANNING_TREE);
    this->setBpduType(BPDU_CFG);

}

BpduCfg::BpduCfg(const BpduCfg& other) : ::inet::BpduBase(other)
{
    copy(other);
}

BpduCfg::~BpduCfg()
{
}

BpduCfg& BpduCfg::operator=(const BpduCfg& other)
{
    if (this == &other) return *this;
    ::inet::BpduBase::operator=(other);
    copy(other);
    return *this;
}

void BpduCfg::copy(const BpduCfg& other)
{
    this->tcaFlag = other.tcaFlag;
    this->reserved = other.reserved;
    this->tcFlag = other.tcFlag;
    this->rootPriority = other.rootPriority;
    this->rootAddress = other.rootAddress;
    this->rootPathCost = other.rootPathCost;
    this->bridgePriority = other.bridgePriority;
    this->bridgeAddress = other.bridgeAddress;
    this->portPriority = other.portPriority;
    this->portNum = other.portNum;
    this->messageAge = other.messageAge;
    this->maxAge = other.maxAge;
    this->helloTime = other.helloTime;
    this->forwardDelay = other.forwardDelay;
}

void BpduCfg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::BpduBase::parsimPack(b);
    doParsimPacking(b,this->tcaFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->tcFlag);
    doParsimPacking(b,this->rootPriority);
    doParsimPacking(b,this->rootAddress);
    doParsimPacking(b,this->rootPathCost);
    doParsimPacking(b,this->bridgePriority);
    doParsimPacking(b,this->bridgeAddress);
    doParsimPacking(b,this->portPriority);
    doParsimPacking(b,this->portNum);
    doParsimPacking(b,this->messageAge);
    doParsimPacking(b,this->maxAge);
    doParsimPacking(b,this->helloTime);
    doParsimPacking(b,this->forwardDelay);
}

void BpduCfg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::BpduBase::parsimUnpack(b);
    doParsimUnpacking(b,this->tcaFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->tcFlag);
    doParsimUnpacking(b,this->rootPriority);
    doParsimUnpacking(b,this->rootAddress);
    doParsimUnpacking(b,this->rootPathCost);
    doParsimUnpacking(b,this->bridgePriority);
    doParsimUnpacking(b,this->bridgeAddress);
    doParsimUnpacking(b,this->portPriority);
    doParsimUnpacking(b,this->portNum);
    doParsimUnpacking(b,this->messageAge);
    doParsimUnpacking(b,this->maxAge);
    doParsimUnpacking(b,this->helloTime);
    doParsimUnpacking(b,this->forwardDelay);
}

bool BpduCfg::getTcaFlag() const
{
    return this->tcaFlag;
}

void BpduCfg::setTcaFlag(bool tcaFlag)
{
    handleChange();
    this->tcaFlag = tcaFlag;
}

uint8_t BpduCfg::getReserved() const
{
    return this->reserved;
}

void BpduCfg::setReserved(uint8_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

bool BpduCfg::getTcFlag() const
{
    return this->tcFlag;
}

void BpduCfg::setTcFlag(bool tcFlag)
{
    handleChange();
    this->tcFlag = tcFlag;
}

uint16_t BpduCfg::getRootPriority() const
{
    return this->rootPriority;
}

void BpduCfg::setRootPriority(uint16_t rootPriority)
{
    handleChange();
    this->rootPriority = rootPriority;
}

const MacAddress& BpduCfg::getRootAddress() const
{
    return this->rootAddress;
}

void BpduCfg::setRootAddress(const MacAddress& rootAddress)
{
    handleChange();
    this->rootAddress = rootAddress;
}

uint32_t BpduCfg::getRootPathCost() const
{
    return this->rootPathCost;
}

void BpduCfg::setRootPathCost(uint32_t rootPathCost)
{
    handleChange();
    this->rootPathCost = rootPathCost;
}

uint16_t BpduCfg::getBridgePriority() const
{
    return this->bridgePriority;
}

void BpduCfg::setBridgePriority(uint16_t bridgePriority)
{
    handleChange();
    this->bridgePriority = bridgePriority;
}

const MacAddress& BpduCfg::getBridgeAddress() const
{
    return this->bridgeAddress;
}

void BpduCfg::setBridgeAddress(const MacAddress& bridgeAddress)
{
    handleChange();
    this->bridgeAddress = bridgeAddress;
}

unsigned int BpduCfg::getPortPriority() const
{
    return this->portPriority;
}

void BpduCfg::setPortPriority(unsigned int portPriority)
{
    handleChange();
    this->portPriority = portPriority;
}

unsigned int BpduCfg::getPortNum() const
{
    return this->portNum;
}

void BpduCfg::setPortNum(unsigned int portNum)
{
    handleChange();
    this->portNum = portNum;
}

omnetpp::simtime_t BpduCfg::getMessageAge() const
{
    return this->messageAge;
}

void BpduCfg::setMessageAge(omnetpp::simtime_t messageAge)
{
    handleChange();
    this->messageAge = messageAge;
}

omnetpp::simtime_t BpduCfg::getMaxAge() const
{
    return this->maxAge;
}

void BpduCfg::setMaxAge(omnetpp::simtime_t maxAge)
{
    handleChange();
    this->maxAge = maxAge;
}

omnetpp::simtime_t BpduCfg::getHelloTime() const
{
    return this->helloTime;
}

void BpduCfg::setHelloTime(omnetpp::simtime_t helloTime)
{
    handleChange();
    this->helloTime = helloTime;
}

omnetpp::simtime_t BpduCfg::getForwardDelay() const
{
    return this->forwardDelay;
}

void BpduCfg::setForwardDelay(omnetpp::simtime_t forwardDelay)
{
    handleChange();
    this->forwardDelay = forwardDelay;
}

class BpduCfgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tcaFlag,
        FIELD_reserved,
        FIELD_tcFlag,
        FIELD_rootPriority,
        FIELD_rootAddress,
        FIELD_rootPathCost,
        FIELD_bridgePriority,
        FIELD_bridgeAddress,
        FIELD_portPriority,
        FIELD_portNum,
        FIELD_messageAge,
        FIELD_maxAge,
        FIELD_helloTime,
        FIELD_forwardDelay,
    };
  public:
    BpduCfgDescriptor();
    virtual ~BpduCfgDescriptor();

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

Register_ClassDescriptor(BpduCfgDescriptor)

BpduCfgDescriptor::BpduCfgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BpduCfg)), "inet::BpduBase")
{
    propertynames = nullptr;
}

BpduCfgDescriptor::~BpduCfgDescriptor()
{
    delete[] propertynames;
}

bool BpduCfgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BpduCfg *>(obj)!=nullptr;
}

const char **BpduCfgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BpduCfgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BpduCfgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount() : 14;
}

unsigned int BpduCfgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tcaFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_tcFlag
        FD_ISEDITABLE,    // FIELD_rootPriority
        0,    // FIELD_rootAddress
        FD_ISEDITABLE,    // FIELD_rootPathCost
        FD_ISEDITABLE,    // FIELD_bridgePriority
        0,    // FIELD_bridgeAddress
        FD_ISEDITABLE,    // FIELD_portPriority
        FD_ISEDITABLE,    // FIELD_portNum
        0,    // FIELD_messageAge
        0,    // FIELD_maxAge
        0,    // FIELD_helloTime
        0,    // FIELD_forwardDelay
    };
    return (field >= 0 && field < 14) ? fieldTypeFlags[field] : 0;
}

const char *BpduCfgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tcaFlag",
        "reserved",
        "tcFlag",
        "rootPriority",
        "rootAddress",
        "rootPathCost",
        "bridgePriority",
        "bridgeAddress",
        "portPriority",
        "portNum",
        "messageAge",
        "maxAge",
        "helloTime",
        "forwardDelay",
    };
    return (field >= 0 && field < 14) ? fieldNames[field] : nullptr;
}

int BpduCfgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcaFlag") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcFlag") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootPriority") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootAddress") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootPathCost") == 0) return base+5;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bridgePriority") == 0) return base+6;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bridgeAddress") == 0) return base+7;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portPriority") == 0) return base+8;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portNum") == 0) return base+9;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messageAge") == 0) return base+10;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxAge") == 0) return base+11;
    if (fieldName[0] == 'h' && strcmp(fieldName, "helloTime") == 0) return base+12;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardDelay") == 0) return base+13;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BpduCfgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_tcaFlag
        "uint8_t",    // FIELD_reserved
        "bool",    // FIELD_tcFlag
        "uint16_t",    // FIELD_rootPriority
        "inet::MacAddress",    // FIELD_rootAddress
        "uint32_t",    // FIELD_rootPathCost
        "uint16_t",    // FIELD_bridgePriority
        "inet::MacAddress",    // FIELD_bridgeAddress
        "unsigned int",    // FIELD_portPriority
        "unsigned int",    // FIELD_portNum
        "omnetpp::simtime_t",    // FIELD_messageAge
        "omnetpp::simtime_t",    // FIELD_maxAge
        "omnetpp::simtime_t",    // FIELD_helloTime
        "omnetpp::simtime_t",    // FIELD_forwardDelay
    };
    return (field >= 0 && field < 14) ? fieldTypeStrings[field] : nullptr;
}

const char **BpduCfgDescriptor::getFieldPropertyNames(int field) const
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

const char *BpduCfgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BpduCfgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BpduCfgDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BpduCfg'", field);
    }
}

const char *BpduCfgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BpduCfgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        case FIELD_tcaFlag: return bool2string(pp->getTcaFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_tcFlag: return bool2string(pp->getTcFlag());
        case FIELD_rootPriority: return ulong2string(pp->getRootPriority());
        case FIELD_rootAddress: return pp->getRootAddress().str();
        case FIELD_rootPathCost: return ulong2string(pp->getRootPathCost());
        case FIELD_bridgePriority: return ulong2string(pp->getBridgePriority());
        case FIELD_bridgeAddress: return pp->getBridgeAddress().str();
        case FIELD_portPriority: return ulong2string(pp->getPortPriority());
        case FIELD_portNum: return ulong2string(pp->getPortNum());
        case FIELD_messageAge: return simtime2string(pp->getMessageAge());
        case FIELD_maxAge: return simtime2string(pp->getMaxAge());
        case FIELD_helloTime: return simtime2string(pp->getHelloTime());
        case FIELD_forwardDelay: return simtime2string(pp->getForwardDelay());
        default: return "";
    }
}

void BpduCfgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        case FIELD_tcaFlag: pp->setTcaFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_tcFlag: pp->setTcFlag(string2bool(value)); break;
        case FIELD_rootPriority: pp->setRootPriority(string2ulong(value)); break;
        case FIELD_rootPathCost: pp->setRootPathCost(string2ulong(value)); break;
        case FIELD_bridgePriority: pp->setBridgePriority(string2ulong(value)); break;
        case FIELD_portPriority: pp->setPortPriority(string2ulong(value)); break;
        case FIELD_portNum: pp->setPortNum(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduCfg'", field);
    }
}

const char *BpduCfgDescriptor::getFieldStructName(int field) const
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

void *BpduCfgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        case FIELD_rootAddress: return toVoidPtr(&pp->getRootAddress()); break;
        case FIELD_bridgeAddress: return toVoidPtr(&pp->getBridgeAddress()); break;
        default: return nullptr;
    }
}

void BpduCfgDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    BpduCfg *pp = (BpduCfg *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BpduCfg'", field);
    }
}

} // namespace inet

