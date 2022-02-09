//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/eigrp/messages/EigrpMessage.msg.
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
#include "EigrpMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::HeaderOpcode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::HeaderOpcode"));
    e->insert(EIGRP_UPDATE_MSG, "EIGRP_UPDATE_MSG");
    e->insert(EIGRP_REQUEST_MSG, "EIGRP_REQUEST_MSG");
    e->insert(EIGRP_QUERY_MSG, "EIGRP_QUERY_MSG");
    e->insert(EIGRP_REPLY_MSG, "EIGRP_REPLY_MSG");
    e->insert(EIGRP_HELLO_MSG, "EIGRP_HELLO_MSG");
    e->insert(EIGRP_SIAQUERY_MSG, "EIGRP_SIAQUERY_MSG");
    e->insert(EIGRP_SIAREPLY_MSG, "EIGRP_SIAREPLY_MSG");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::EigrpTlvTypeLow");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::EigrpTlvTypeLow"));
    e->insert(EIGRP_TLV_PARAM, "EIGRP_TLV_PARAM");
    e->insert(EIGRP_TLV_ROUTE, "EIGRP_TLV_ROUTE");
    e->insert(EIGRP_TLV_STUB, "EIGRP_TLV_STUB");
)

EigrpKValues::EigrpKValues()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpKValues& a)
{
    doParsimPacking(b,a.K1);
    doParsimPacking(b,a.K2);
    doParsimPacking(b,a.K3);
    doParsimPacking(b,a.K4);
    doParsimPacking(b,a.K5);
    doParsimPacking(b,a.K6);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpKValues& a)
{
    doParsimUnpacking(b,a.K1);
    doParsimUnpacking(b,a.K2);
    doParsimUnpacking(b,a.K3);
    doParsimUnpacking(b,a.K4);
    doParsimUnpacking(b,a.K5);
    doParsimUnpacking(b,a.K6);
}

class EigrpKValuesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_K1,
        FIELD_K2,
        FIELD_K3,
        FIELD_K4,
        FIELD_K5,
        FIELD_K6,
    };
  public:
    EigrpKValuesDescriptor();
    virtual ~EigrpKValuesDescriptor();

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

Register_ClassDescriptor(EigrpKValuesDescriptor)

EigrpKValuesDescriptor::EigrpKValuesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpKValues)), "")
{
    propertynames = nullptr;
}

EigrpKValuesDescriptor::~EigrpKValuesDescriptor()
{
    delete[] propertynames;
}

bool EigrpKValuesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpKValues *>(obj)!=nullptr;
}

const char **EigrpKValuesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpKValuesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpKValuesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int EigrpKValuesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_K1
        FD_ISEDITABLE,    // FIELD_K2
        FD_ISEDITABLE,    // FIELD_K3
        FD_ISEDITABLE,    // FIELD_K4
        FD_ISEDITABLE,    // FIELD_K5
        FD_ISEDITABLE,    // FIELD_K6
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *EigrpKValuesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "K1",
        "K2",
        "K3",
        "K4",
        "K5",
        "K6",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int EigrpKValuesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K1") == 0) return base+0;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K2") == 0) return base+1;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K3") == 0) return base+2;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K4") == 0) return base+3;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K5") == 0) return base+4;
    if (fieldName[0] == 'K' && strcmp(fieldName, "K6") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpKValuesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_K1
        "uint16_t",    // FIELD_K2
        "uint16_t",    // FIELD_K3
        "uint16_t",    // FIELD_K4
        "uint16_t",    // FIELD_K5
        "uint16_t",    // FIELD_K6
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpKValuesDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpKValuesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpKValuesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpKValuesDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpKValues'", field);
    }
}

const char *EigrpKValuesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpKValuesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        case FIELD_K1: return ulong2string(pp->K1);
        case FIELD_K2: return ulong2string(pp->K2);
        case FIELD_K3: return ulong2string(pp->K3);
        case FIELD_K4: return ulong2string(pp->K4);
        case FIELD_K5: return ulong2string(pp->K5);
        case FIELD_K6: return ulong2string(pp->K6);
        default: return "";
    }
}

void EigrpKValuesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        case FIELD_K1: pp->K1 = string2ulong(value); break;
        case FIELD_K2: pp->K2 = string2ulong(value); break;
        case FIELD_K3: pp->K3 = string2ulong(value); break;
        case FIELD_K4: pp->K4 = string2ulong(value); break;
        case FIELD_K5: pp->K5 = string2ulong(value); break;
        case FIELD_K6: pp->K6 = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpKValues'", field);
    }
}

const char *EigrpKValuesDescriptor::getFieldStructName(int field) const
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

void *EigrpKValuesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpKValuesDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpKValues *pp = (EigrpKValues *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpKValues'", field);
    }
}

EigrpRouteFlags::EigrpRouteFlags()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpRouteFlags& a)
{
    doParsimPacking(b,a.SW);
    doParsimPacking(b,a.CD);
    doParsimPacking(b,a.active);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpRouteFlags& a)
{
    doParsimUnpacking(b,a.SW);
    doParsimUnpacking(b,a.CD);
    doParsimUnpacking(b,a.active);
}

class EigrpRouteFlagsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_SW,
        FIELD_CD,
        FIELD_active,
    };
  public:
    EigrpRouteFlagsDescriptor();
    virtual ~EigrpRouteFlagsDescriptor();

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

Register_ClassDescriptor(EigrpRouteFlagsDescriptor)

EigrpRouteFlagsDescriptor::EigrpRouteFlagsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpRouteFlags)), "")
{
    propertynames = nullptr;
}

EigrpRouteFlagsDescriptor::~EigrpRouteFlagsDescriptor()
{
    delete[] propertynames;
}

bool EigrpRouteFlagsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpRouteFlags *>(obj)!=nullptr;
}

const char **EigrpRouteFlagsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpRouteFlagsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpRouteFlagsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int EigrpRouteFlagsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SW
        FD_ISEDITABLE,    // FIELD_CD
        FD_ISEDITABLE,    // FIELD_active
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *EigrpRouteFlagsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SW",
        "CD",
        "active",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int EigrpRouteFlagsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SW") == 0) return base+0;
    if (fieldName[0] == 'C' && strcmp(fieldName, "CD") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "active") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpRouteFlagsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_SW
        "bool",    // FIELD_CD
        "bool",    // FIELD_active
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpRouteFlagsDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpRouteFlagsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpRouteFlagsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpRouteFlagsDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpRouteFlags'", field);
    }
}

const char *EigrpRouteFlagsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpRouteFlagsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        case FIELD_SW: return bool2string(pp->SW);
        case FIELD_CD: return bool2string(pp->CD);
        case FIELD_active: return bool2string(pp->active);
        default: return "";
    }
}

void EigrpRouteFlagsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        case FIELD_SW: pp->SW = string2bool(value); break;
        case FIELD_CD: pp->CD = string2bool(value); break;
        case FIELD_active: pp->active = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpRouteFlags'", field);
    }
}

const char *EigrpRouteFlagsDescriptor::getFieldStructName(int field) const
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

void *EigrpRouteFlagsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpRouteFlagsDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpRouteFlags *pp = (EigrpRouteFlags *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpRouteFlags'", field);
    }
}

EigrpWideMetricPar::EigrpWideMetricPar()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpWideMetricPar& a)
{
    doParsimPacking(b,a.offset);
    doParsimPacking(b,a.priority);
    doParsimPacking(b,a.reliability);
    doParsimPacking(b,a.load);
    doParsimPacking(b,a.mtu);
    doParsimPacking(b,a.hopCount);
    doParsimPacking(b,a.delay);
    doParsimPacking(b,a.bandwidth);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpWideMetricPar& a)
{
    doParsimUnpacking(b,a.offset);
    doParsimUnpacking(b,a.priority);
    doParsimUnpacking(b,a.reliability);
    doParsimUnpacking(b,a.load);
    doParsimUnpacking(b,a.mtu);
    doParsimUnpacking(b,a.hopCount);
    doParsimUnpacking(b,a.delay);
    doParsimUnpacking(b,a.bandwidth);
}

class EigrpWideMetricParDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_offset,
        FIELD_priority,
        FIELD_reliability,
        FIELD_load,
        FIELD_mtu,
        FIELD_hopCount,
        FIELD_delay,
        FIELD_bandwidth,
    };
  public:
    EigrpWideMetricParDescriptor();
    virtual ~EigrpWideMetricParDescriptor();

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

Register_ClassDescriptor(EigrpWideMetricParDescriptor)

EigrpWideMetricParDescriptor::EigrpWideMetricParDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpWideMetricPar)), "")
{
    propertynames = nullptr;
}

EigrpWideMetricParDescriptor::~EigrpWideMetricParDescriptor()
{
    delete[] propertynames;
}

bool EigrpWideMetricParDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpWideMetricPar *>(obj)!=nullptr;
}

const char **EigrpWideMetricParDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpWideMetricParDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpWideMetricParDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int EigrpWideMetricParDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_offset
        FD_ISEDITABLE,    // FIELD_priority
        FD_ISEDITABLE,    // FIELD_reliability
        FD_ISEDITABLE,    // FIELD_load
        FD_ISEDITABLE,    // FIELD_mtu
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISEDITABLE,    // FIELD_delay
        FD_ISEDITABLE,    // FIELD_bandwidth
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *EigrpWideMetricParDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "offset",
        "priority",
        "reliability",
        "load",
        "mtu",
        "hopCount",
        "delay",
        "bandwidth",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int EigrpWideMetricParDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "offset") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "priority") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reliability") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "load") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mtu") == 0) return base+4;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopCount") == 0) return base+5;
    if (fieldName[0] == 'd' && strcmp(fieldName, "delay") == 0) return base+6;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpWideMetricParDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_offset
        "uint8_t",    // FIELD_priority
        "uint8_t",    // FIELD_reliability
        "uint8_t",    // FIELD_load
        "uint32_t",    // FIELD_mtu
        "uint8_t",    // FIELD_hopCount
        "uint64_t",    // FIELD_delay
        "uint64_t",    // FIELD_bandwidth
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpWideMetricParDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpWideMetricParDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpWideMetricParDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpWideMetricParDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpWideMetricPar'", field);
    }
}

const char *EigrpWideMetricParDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpWideMetricParDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        case FIELD_offset: return ulong2string(pp->offset);
        case FIELD_priority: return ulong2string(pp->priority);
        case FIELD_reliability: return ulong2string(pp->reliability);
        case FIELD_load: return ulong2string(pp->load);
        case FIELD_mtu: return ulong2string(pp->mtu);
        case FIELD_hopCount: return ulong2string(pp->hopCount);
        case FIELD_delay: return uint642string(pp->delay);
        case FIELD_bandwidth: return uint642string(pp->bandwidth);
        default: return "";
    }
}

void EigrpWideMetricParDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        case FIELD_offset: pp->offset = string2ulong(value); break;
        case FIELD_priority: pp->priority = string2ulong(value); break;
        case FIELD_reliability: pp->reliability = string2ulong(value); break;
        case FIELD_load: pp->load = string2ulong(value); break;
        case FIELD_mtu: pp->mtu = string2ulong(value); break;
        case FIELD_hopCount: pp->hopCount = string2ulong(value); break;
        case FIELD_delay: pp->delay = string2uint64(value); break;
        case FIELD_bandwidth: pp->bandwidth = string2uint64(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpWideMetricPar'", field);
    }
}

const char *EigrpWideMetricParDescriptor::getFieldStructName(int field) const
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

void *EigrpWideMetricParDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpWideMetricParDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpWideMetricPar *pp = (EigrpWideMetricPar *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpWideMetricPar'", field);
    }
}

EigrpStub::EigrpStub()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpStub& a)
{
    doParsimPacking(b,a.connectedRt);
    doParsimPacking(b,a.staticRt);
    doParsimPacking(b,a.summaryRt);
    doParsimPacking(b,a.redistributedRt);
    doParsimPacking(b,a.leakMapRt);
    doParsimPacking(b,a.recvOnlyRt);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpStub& a)
{
    doParsimUnpacking(b,a.connectedRt);
    doParsimUnpacking(b,a.staticRt);
    doParsimUnpacking(b,a.summaryRt);
    doParsimUnpacking(b,a.redistributedRt);
    doParsimUnpacking(b,a.leakMapRt);
    doParsimUnpacking(b,a.recvOnlyRt);
}

class EigrpStubDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_connectedRt,
        FIELD_staticRt,
        FIELD_summaryRt,
        FIELD_redistributedRt,
        FIELD_leakMapRt,
        FIELD_recvOnlyRt,
    };
  public:
    EigrpStubDescriptor();
    virtual ~EigrpStubDescriptor();

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

Register_ClassDescriptor(EigrpStubDescriptor)

EigrpStubDescriptor::EigrpStubDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpStub)), "")
{
    propertynames = nullptr;
}

EigrpStubDescriptor::~EigrpStubDescriptor()
{
    delete[] propertynames;
}

bool EigrpStubDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpStub *>(obj)!=nullptr;
}

const char **EigrpStubDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpStubDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpStubDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int EigrpStubDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_connectedRt
        FD_ISEDITABLE,    // FIELD_staticRt
        FD_ISEDITABLE,    // FIELD_summaryRt
        FD_ISEDITABLE,    // FIELD_redistributedRt
        FD_ISEDITABLE,    // FIELD_leakMapRt
        FD_ISEDITABLE,    // FIELD_recvOnlyRt
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *EigrpStubDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "connectedRt",
        "staticRt",
        "summaryRt",
        "redistributedRt",
        "leakMapRt",
        "recvOnlyRt",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int EigrpStubDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "connectedRt") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "staticRt") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "summaryRt") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "redistributedRt") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "leakMapRt") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recvOnlyRt") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpStubDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_connectedRt
        "bool",    // FIELD_staticRt
        "bool",    // FIELD_summaryRt
        "bool",    // FIELD_redistributedRt
        "bool",    // FIELD_leakMapRt
        "bool",    // FIELD_recvOnlyRt
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpStubDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpStubDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpStubDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpStubDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpStub'", field);
    }
}

const char *EigrpStubDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpStubDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        case FIELD_connectedRt: return bool2string(pp->connectedRt);
        case FIELD_staticRt: return bool2string(pp->staticRt);
        case FIELD_summaryRt: return bool2string(pp->summaryRt);
        case FIELD_redistributedRt: return bool2string(pp->redistributedRt);
        case FIELD_leakMapRt: return bool2string(pp->leakMapRt);
        case FIELD_recvOnlyRt: return bool2string(pp->recvOnlyRt);
        default: return "";
    }
}

void EigrpStubDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        case FIELD_connectedRt: pp->connectedRt = string2bool(value); break;
        case FIELD_staticRt: pp->staticRt = string2bool(value); break;
        case FIELD_summaryRt: pp->summaryRt = string2bool(value); break;
        case FIELD_redistributedRt: pp->redistributedRt = string2bool(value); break;
        case FIELD_leakMapRt: pp->leakMapRt = string2bool(value); break;
        case FIELD_recvOnlyRt: pp->recvOnlyRt = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpStub'", field);
    }
}

const char *EigrpStubDescriptor::getFieldStructName(int field) const
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

void *EigrpStubDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpStubDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpStub *pp = (EigrpStub *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpStub'", field);
    }
}

EigrpTlvStub::EigrpTlvStub()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpTlvStub& a)
{
    doParsimPacking(b,a.typeHigh);
    doParsimPacking(b,a.typeLow);
    doParsimPacking(b,a.stub);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpTlvStub& a)
{
    doParsimUnpacking(b,a.typeHigh);
    doParsimUnpacking(b,a.typeLow);
    doParsimUnpacking(b,a.stub);
}

class EigrpTlvStubDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_typeHigh,
        FIELD_typeLow,
        FIELD_stub,
    };
  public:
    EigrpTlvStubDescriptor();
    virtual ~EigrpTlvStubDescriptor();

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

Register_ClassDescriptor(EigrpTlvStubDescriptor)

EigrpTlvStubDescriptor::EigrpTlvStubDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpTlvStub)), "")
{
    propertynames = nullptr;
}

EigrpTlvStubDescriptor::~EigrpTlvStubDescriptor()
{
    delete[] propertynames;
}

bool EigrpTlvStubDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpTlvStub *>(obj)!=nullptr;
}

const char **EigrpTlvStubDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpTlvStubDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpTlvStubDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int EigrpTlvStubDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_typeHigh
        FD_ISEDITABLE,    // FIELD_typeLow
        FD_ISCOMPOUND,    // FIELD_stub
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *EigrpTlvStubDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "typeHigh",
        "typeLow",
        "stub",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int EigrpTlvStubDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeHigh") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeLow") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "stub") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpTlvStubDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_typeHigh
        "char",    // FIELD_typeLow
        "inet::EigrpStub",    // FIELD_stub
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpTlvStubDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpTlvStubDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpTlvStubDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpTlvStubDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpTlvStub'", field);
    }
}

const char *EigrpTlvStubDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpTlvStubDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: return long2string(pp->typeHigh);
        case FIELD_typeLow: return long2string(pp->typeLow);
        case FIELD_stub: {std::stringstream out; out << pp->stub; return out.str();}
        default: return "";
    }
}

void EigrpTlvStubDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: pp->typeHigh = string2long(value); break;
        case FIELD_typeLow: pp->typeLow = string2long(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpTlvStub'", field);
    }
}

const char *EigrpTlvStubDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_stub: return omnetpp::opp_typename(typeid(EigrpStub));
        default: return nullptr;
    };
}

void *EigrpTlvStubDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        case FIELD_stub: return toVoidPtr(&pp->stub); break;
        default: return nullptr;
    }
}

void EigrpTlvStubDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvStub *pp = (EigrpTlvStub *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpTlvStub'", field);
    }
}

EigrpTlvParameter::EigrpTlvParameter()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpTlvParameter& a)
{
    doParsimPacking(b,a.typeHigh);
    doParsimPacking(b,a.typeLow);
    doParsimPacking(b,a.kValues);
    doParsimPacking(b,a.holdTimer);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpTlvParameter& a)
{
    doParsimUnpacking(b,a.typeHigh);
    doParsimUnpacking(b,a.typeLow);
    doParsimUnpacking(b,a.kValues);
    doParsimUnpacking(b,a.holdTimer);
}

class EigrpTlvParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_typeHigh,
        FIELD_typeLow,
        FIELD_kValues,
        FIELD_holdTimer,
    };
  public:
    EigrpTlvParameterDescriptor();
    virtual ~EigrpTlvParameterDescriptor();

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

Register_ClassDescriptor(EigrpTlvParameterDescriptor)

EigrpTlvParameterDescriptor::EigrpTlvParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpTlvParameter)), "")
{
    propertynames = nullptr;
}

EigrpTlvParameterDescriptor::~EigrpTlvParameterDescriptor()
{
    delete[] propertynames;
}

bool EigrpTlvParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpTlvParameter *>(obj)!=nullptr;
}

const char **EigrpTlvParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpTlvParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpTlvParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EigrpTlvParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_typeHigh
        FD_ISEDITABLE,    // FIELD_typeLow
        FD_ISCOMPOUND,    // FIELD_kValues
        FD_ISEDITABLE,    // FIELD_holdTimer
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *EigrpTlvParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "typeHigh",
        "typeLow",
        "kValues",
        "holdTimer",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int EigrpTlvParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeHigh") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeLow") == 0) return base+1;
    if (fieldName[0] == 'k' && strcmp(fieldName, "kValues") == 0) return base+2;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTimer") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpTlvParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_typeHigh
        "char",    // FIELD_typeLow
        "inet::EigrpKValues",    // FIELD_kValues
        "uint16_t",    // FIELD_holdTimer
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpTlvParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpTlvParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpTlvParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpTlvParameterDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpTlvParameter'", field);
    }
}

const char *EigrpTlvParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpTlvParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: return long2string(pp->typeHigh);
        case FIELD_typeLow: return long2string(pp->typeLow);
        case FIELD_kValues: {std::stringstream out; out << pp->kValues; return out.str();}
        case FIELD_holdTimer: return ulong2string(pp->holdTimer);
        default: return "";
    }
}

void EigrpTlvParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: pp->typeHigh = string2long(value); break;
        case FIELD_typeLow: pp->typeLow = string2long(value); break;
        case FIELD_holdTimer: pp->holdTimer = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpTlvParameter'", field);
    }
}

const char *EigrpTlvParameterDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_kValues: return omnetpp::opp_typename(typeid(EigrpKValues));
        default: return nullptr;
    };
}

void *EigrpTlvParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        case FIELD_kValues: return toVoidPtr(&pp->kValues); break;
        default: return nullptr;
    }
}

void EigrpTlvParameterDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpTlvParameter *pp = (EigrpTlvParameter *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpTlvParameter'", field);
    }
}

EigrpMpIpv4Internal::EigrpMpIpv4Internal()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpMpIpv4Internal& a)
{
    doParsimPacking(b,a.typeHigh);
    doParsimPacking(b,a.typeLow);
    doParsimPacking(b,a.afi);
    doParsimPacking(b,a.tid);
    doParsimPacking(b,a.routerID);
    doParsimPacking(b,a.metric);
    doParsimPacking(b,a.flags);
    doParsimPacking(b,a.nextHop);
    doParsimPacking(b,a.destMask);
    doParsimPacking(b,a.destAddress);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpMpIpv4Internal& a)
{
    doParsimUnpacking(b,a.typeHigh);
    doParsimUnpacking(b,a.typeLow);
    doParsimUnpacking(b,a.afi);
    doParsimUnpacking(b,a.tid);
    doParsimUnpacking(b,a.routerID);
    doParsimUnpacking(b,a.metric);
    doParsimUnpacking(b,a.flags);
    doParsimUnpacking(b,a.nextHop);
    doParsimUnpacking(b,a.destMask);
    doParsimUnpacking(b,a.destAddress);
}

class EigrpMpIpv4InternalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_typeHigh,
        FIELD_typeLow,
        FIELD_afi,
        FIELD_tid,
        FIELD_routerID,
        FIELD_metric,
        FIELD_flags,
        FIELD_nextHop,
        FIELD_destMask,
        FIELD_destAddress,
    };
  public:
    EigrpMpIpv4InternalDescriptor();
    virtual ~EigrpMpIpv4InternalDescriptor();

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

Register_ClassDescriptor(EigrpMpIpv4InternalDescriptor)

EigrpMpIpv4InternalDescriptor::EigrpMpIpv4InternalDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpMpIpv4Internal)), "")
{
    propertynames = nullptr;
}

EigrpMpIpv4InternalDescriptor::~EigrpMpIpv4InternalDescriptor()
{
    delete[] propertynames;
}

bool EigrpMpIpv4InternalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpMpIpv4Internal *>(obj)!=nullptr;
}

const char **EigrpMpIpv4InternalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpMpIpv4InternalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpMpIpv4InternalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int EigrpMpIpv4InternalDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_typeHigh
        FD_ISEDITABLE,    // FIELD_typeLow
        FD_ISEDITABLE,    // FIELD_afi
        FD_ISEDITABLE,    // FIELD_tid
        0,    // FIELD_routerID
        FD_ISCOMPOUND,    // FIELD_metric
        FD_ISCOMPOUND,    // FIELD_flags
        0,    // FIELD_nextHop
        0,    // FIELD_destMask
        0,    // FIELD_destAddress
    };
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *EigrpMpIpv4InternalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "typeHigh",
        "typeLow",
        "afi",
        "tid",
        "routerID",
        "metric",
        "flags",
        "nextHop",
        "destMask",
        "destAddress",
    };
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int EigrpMpIpv4InternalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeHigh") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeLow") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "afi") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerID") == 0) return base+4;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metric") == 0) return base+5;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flags") == 0) return base+6;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextHop") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destMask") == 0) return base+8;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddress") == 0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpMpIpv4InternalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_typeHigh
        "char",    // FIELD_typeLow
        "uint16_t",    // FIELD_afi
        "uint16_t",    // FIELD_tid
        "inet::Ipv4Address",    // FIELD_routerID
        "inet::EigrpWideMetricPar",    // FIELD_metric
        "inet::EigrpRouteFlags",    // FIELD_flags
        "inet::Ipv4Address",    // FIELD_nextHop
        "inet::Ipv4Address",    // FIELD_destMask
        "inet::Ipv4Address",    // FIELD_destAddress
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpMpIpv4InternalDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpMpIpv4InternalDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpMpIpv4InternalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpMpIpv4InternalDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpMpIpv4Internal'", field);
    }
}

const char *EigrpMpIpv4InternalDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpMpIpv4InternalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: return long2string(pp->typeHigh);
        case FIELD_typeLow: return long2string(pp->typeLow);
        case FIELD_afi: return ulong2string(pp->afi);
        case FIELD_tid: return ulong2string(pp->tid);
        case FIELD_routerID: return pp->routerID.str();
        case FIELD_metric: {std::stringstream out; out << pp->metric; return out.str();}
        case FIELD_flags: {std::stringstream out; out << pp->flags; return out.str();}
        case FIELD_nextHop: return pp->nextHop.str();
        case FIELD_destMask: return pp->destMask.str();
        case FIELD_destAddress: return pp->destAddress.str();
        default: return "";
    }
}

void EigrpMpIpv4InternalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: pp->typeHigh = string2long(value); break;
        case FIELD_typeLow: pp->typeLow = string2long(value); break;
        case FIELD_afi: pp->afi = string2ulong(value); break;
        case FIELD_tid: pp->tid = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMpIpv4Internal'", field);
    }
}

const char *EigrpMpIpv4InternalDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_metric: return omnetpp::opp_typename(typeid(EigrpWideMetricPar));
        case FIELD_flags: return omnetpp::opp_typename(typeid(EigrpRouteFlags));
        default: return nullptr;
    };
}

void *EigrpMpIpv4InternalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        case FIELD_routerID: return toVoidPtr(&pp->routerID); break;
        case FIELD_metric: return toVoidPtr(&pp->metric); break;
        case FIELD_flags: return toVoidPtr(&pp->flags); break;
        case FIELD_nextHop: return toVoidPtr(&pp->nextHop); break;
        case FIELD_destMask: return toVoidPtr(&pp->destMask); break;
        case FIELD_destAddress: return toVoidPtr(&pp->destAddress); break;
        default: return nullptr;
    }
}

void EigrpMpIpv4InternalDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv4Internal *pp = (EigrpMpIpv4Internal *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMpIpv4Internal'", field);
    }
}

EigrpMpIpv6Internal::EigrpMpIpv6Internal()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpMpIpv6Internal& a)
{
    doParsimPacking(b,a.typeHigh);
    doParsimPacking(b,a.typeLow);
    doParsimPacking(b,a.afi);
    doParsimPacking(b,a.tid);
    doParsimPacking(b,a.routerID);
    doParsimPacking(b,a.metric);
    doParsimPacking(b,a.flags);
    doParsimPacking(b,a.nextHop);
    doParsimPacking(b,a.destMask);
    doParsimPacking(b,a.destAddress);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpMpIpv6Internal& a)
{
    doParsimUnpacking(b,a.typeHigh);
    doParsimUnpacking(b,a.typeLow);
    doParsimUnpacking(b,a.afi);
    doParsimUnpacking(b,a.tid);
    doParsimUnpacking(b,a.routerID);
    doParsimUnpacking(b,a.metric);
    doParsimUnpacking(b,a.flags);
    doParsimUnpacking(b,a.nextHop);
    doParsimUnpacking(b,a.destMask);
    doParsimUnpacking(b,a.destAddress);
}

class EigrpMpIpv6InternalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_typeHigh,
        FIELD_typeLow,
        FIELD_afi,
        FIELD_tid,
        FIELD_routerID,
        FIELD_metric,
        FIELD_flags,
        FIELD_nextHop,
        FIELD_destMask,
        FIELD_destAddress,
    };
  public:
    EigrpMpIpv6InternalDescriptor();
    virtual ~EigrpMpIpv6InternalDescriptor();

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

Register_ClassDescriptor(EigrpMpIpv6InternalDescriptor)

EigrpMpIpv6InternalDescriptor::EigrpMpIpv6InternalDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpMpIpv6Internal)), "")
{
    propertynames = nullptr;
}

EigrpMpIpv6InternalDescriptor::~EigrpMpIpv6InternalDescriptor()
{
    delete[] propertynames;
}

bool EigrpMpIpv6InternalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpMpIpv6Internal *>(obj)!=nullptr;
}

const char **EigrpMpIpv6InternalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpMpIpv6InternalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpMpIpv6InternalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int EigrpMpIpv6InternalDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_typeHigh
        FD_ISEDITABLE,    // FIELD_typeLow
        FD_ISEDITABLE,    // FIELD_afi
        FD_ISEDITABLE,    // FIELD_tid
        0,    // FIELD_routerID
        FD_ISCOMPOUND,    // FIELD_metric
        FD_ISCOMPOUND,    // FIELD_flags
        0,    // FIELD_nextHop
        0,    // FIELD_destMask
        0,    // FIELD_destAddress
    };
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *EigrpMpIpv6InternalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "typeHigh",
        "typeLow",
        "afi",
        "tid",
        "routerID",
        "metric",
        "flags",
        "nextHop",
        "destMask",
        "destAddress",
    };
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int EigrpMpIpv6InternalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeHigh") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeLow") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "afi") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerID") == 0) return base+4;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metric") == 0) return base+5;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flags") == 0) return base+6;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextHop") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destMask") == 0) return base+8;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddress") == 0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpMpIpv6InternalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_typeHigh
        "char",    // FIELD_typeLow
        "uint16_t",    // FIELD_afi
        "uint16_t",    // FIELD_tid
        "inet::Ipv4Address",    // FIELD_routerID
        "inet::EigrpWideMetricPar",    // FIELD_metric
        "inet::EigrpRouteFlags",    // FIELD_flags
        "inet::Ipv6Address",    // FIELD_nextHop
        "inet::Ipv6Address",    // FIELD_destMask
        "inet::Ipv6Address",    // FIELD_destAddress
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpMpIpv6InternalDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpMpIpv6InternalDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpMpIpv6InternalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpMpIpv6InternalDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpMpIpv6Internal'", field);
    }
}

const char *EigrpMpIpv6InternalDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpMpIpv6InternalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: return long2string(pp->typeHigh);
        case FIELD_typeLow: return long2string(pp->typeLow);
        case FIELD_afi: return ulong2string(pp->afi);
        case FIELD_tid: return ulong2string(pp->tid);
        case FIELD_routerID: return pp->routerID.str();
        case FIELD_metric: {std::stringstream out; out << pp->metric; return out.str();}
        case FIELD_flags: {std::stringstream out; out << pp->flags; return out.str();}
        case FIELD_nextHop: return pp->nextHop.str();
        case FIELD_destMask: return pp->destMask.str();
        case FIELD_destAddress: return pp->destAddress.str();
        default: return "";
    }
}

void EigrpMpIpv6InternalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        case FIELD_typeHigh: pp->typeHigh = string2long(value); break;
        case FIELD_typeLow: pp->typeLow = string2long(value); break;
        case FIELD_afi: pp->afi = string2ulong(value); break;
        case FIELD_tid: pp->tid = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMpIpv6Internal'", field);
    }
}

const char *EigrpMpIpv6InternalDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_metric: return omnetpp::opp_typename(typeid(EigrpWideMetricPar));
        case FIELD_flags: return omnetpp::opp_typename(typeid(EigrpRouteFlags));
        default: return nullptr;
    };
}

void *EigrpMpIpv6InternalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        case FIELD_routerID: return toVoidPtr(&pp->routerID); break;
        case FIELD_metric: return toVoidPtr(&pp->metric); break;
        case FIELD_flags: return toVoidPtr(&pp->flags); break;
        case FIELD_nextHop: return toVoidPtr(&pp->nextHop); break;
        case FIELD_destMask: return toVoidPtr(&pp->destMask); break;
        case FIELD_destAddress: return toVoidPtr(&pp->destAddress); break;
        default: return nullptr;
    }
}

void EigrpMpIpv6InternalDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMpIpv6Internal *pp = (EigrpMpIpv6Internal *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMpIpv6Internal'", field);
    }
}

Register_Class(EigrpMessage)

EigrpMessage::EigrpMessage() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

EigrpMessage::EigrpMessage(const EigrpMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EigrpMessage::~EigrpMessage()
{
}

EigrpMessage& EigrpMessage::operator=(const EigrpMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EigrpMessage::copy(const EigrpMessage& other)
{
    this->version = other.version;
    this->opcode = other.opcode;
    this->init = other.init;
    this->cr = other.cr;
    this->rs = other.rs;
    this->eot = other.eot;
    this->seqNum = other.seqNum;
    this->ackNum = other.ackNum;
    this->vrid = other.vrid;
    this->asNum = other.asNum;
}

void EigrpMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->opcode);
    doParsimPacking(b,this->init);
    doParsimPacking(b,this->cr);
    doParsimPacking(b,this->rs);
    doParsimPacking(b,this->eot);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->ackNum);
    doParsimPacking(b,this->vrid);
    doParsimPacking(b,this->asNum);
}

void EigrpMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->opcode);
    doParsimUnpacking(b,this->init);
    doParsimUnpacking(b,this->cr);
    doParsimUnpacking(b,this->rs);
    doParsimUnpacking(b,this->eot);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->ackNum);
    doParsimUnpacking(b,this->vrid);
    doParsimUnpacking(b,this->asNum);
}

char EigrpMessage::getVersion() const
{
    return this->version;
}

void EigrpMessage::setVersion(char version)
{
    handleChange();
    this->version = version;
}

int8_t EigrpMessage::getOpcode() const
{
    return this->opcode;
}

void EigrpMessage::setOpcode(int8_t opcode)
{
    handleChange();
    this->opcode = opcode;
}

bool EigrpMessage::getInit() const
{
    return this->init;
}

void EigrpMessage::setInit(bool init)
{
    handleChange();
    this->init = init;
}

bool EigrpMessage::getCr() const
{
    return this->cr;
}

void EigrpMessage::setCr(bool cr)
{
    handleChange();
    this->cr = cr;
}

bool EigrpMessage::getRs() const
{
    return this->rs;
}

void EigrpMessage::setRs(bool rs)
{
    handleChange();
    this->rs = rs;
}

bool EigrpMessage::getEot() const
{
    return this->eot;
}

void EigrpMessage::setEot(bool eot)
{
    handleChange();
    this->eot = eot;
}

int EigrpMessage::getSeqNum() const
{
    return this->seqNum;
}

void EigrpMessage::setSeqNum(int seqNum)
{
    handleChange();
    this->seqNum = seqNum;
}

int EigrpMessage::getAckNum() const
{
    return this->ackNum;
}

void EigrpMessage::setAckNum(int ackNum)
{
    handleChange();
    this->ackNum = ackNum;
}

uint16_t EigrpMessage::getVrid() const
{
    return this->vrid;
}

void EigrpMessage::setVrid(uint16_t vrid)
{
    handleChange();
    this->vrid = vrid;
}

uint16_t EigrpMessage::getAsNum() const
{
    return this->asNum;
}

void EigrpMessage::setAsNum(uint16_t asNum)
{
    handleChange();
    this->asNum = asNum;
}

class EigrpMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_opcode,
        FIELD_init,
        FIELD_cr,
        FIELD_rs,
        FIELD_eot,
        FIELD_seqNum,
        FIELD_ackNum,
        FIELD_vrid,
        FIELD_asNum,
    };
  public:
    EigrpMessageDescriptor();
    virtual ~EigrpMessageDescriptor();

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

Register_ClassDescriptor(EigrpMessageDescriptor)

EigrpMessageDescriptor::EigrpMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpMessage)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

EigrpMessageDescriptor::~EigrpMessageDescriptor()
{
    delete[] propertynames;
}

bool EigrpMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpMessage *>(obj)!=nullptr;
}

const char **EigrpMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int EigrpMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_opcode
        FD_ISEDITABLE,    // FIELD_init
        FD_ISEDITABLE,    // FIELD_cr
        FD_ISEDITABLE,    // FIELD_rs
        FD_ISEDITABLE,    // FIELD_eot
        FD_ISEDITABLE,    // FIELD_seqNum
        FD_ISEDITABLE,    // FIELD_ackNum
        FD_ISEDITABLE,    // FIELD_vrid
        FD_ISEDITABLE,    // FIELD_asNum
    };
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *EigrpMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "opcode",
        "init",
        "cr",
        "rs",
        "eot",
        "seqNum",
        "ackNum",
        "vrid",
        "asNum",
    };
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int EigrpMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "opcode") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "init") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cr") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rs") == 0) return base+4;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eot") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNum") == 0) return base+6;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackNum") == 0) return base+7;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vrid") == 0) return base+8;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asNum") == 0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_version
        "int8_t",    // FIELD_opcode
        "bool",    // FIELD_init
        "bool",    // FIELD_cr
        "bool",    // FIELD_rs
        "bool",    // FIELD_eot
        "int",    // FIELD_seqNum
        "int",    // FIELD_ackNum
        "uint16_t",    // FIELD_vrid
        "uint16_t",    // FIELD_asNum
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpMessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpMessage'", field);
    }
}

const char *EigrpMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_opcode: return long2string(pp->getOpcode());
        case FIELD_init: return bool2string(pp->getInit());
        case FIELD_cr: return bool2string(pp->getCr());
        case FIELD_rs: return bool2string(pp->getRs());
        case FIELD_eot: return bool2string(pp->getEot());
        case FIELD_seqNum: return long2string(pp->getSeqNum());
        case FIELD_ackNum: return long2string(pp->getAckNum());
        case FIELD_vrid: return ulong2string(pp->getVrid());
        case FIELD_asNum: return ulong2string(pp->getAsNum());
        default: return "";
    }
}

void EigrpMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); break;
        case FIELD_opcode: pp->setOpcode(string2long(value)); break;
        case FIELD_init: pp->setInit(string2bool(value)); break;
        case FIELD_cr: pp->setCr(string2bool(value)); break;
        case FIELD_rs: pp->setRs(string2bool(value)); break;
        case FIELD_eot: pp->setEot(string2bool(value)); break;
        case FIELD_seqNum: pp->setSeqNum(string2long(value)); break;
        case FIELD_ackNum: pp->setAckNum(string2long(value)); break;
        case FIELD_vrid: pp->setVrid(string2ulong(value)); break;
        case FIELD_asNum: pp->setAsNum(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMessage'", field);
    }
}

const char *EigrpMessageDescriptor::getFieldStructName(int field) const
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

void *EigrpMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpMessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMessage *pp = (EigrpMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMessage'", field);
    }
}

Register_Class(EigrpIpv4Hello)

EigrpIpv4Hello::EigrpIpv4Hello() : ::inet::EigrpMessage()
{
}

EigrpIpv4Hello::EigrpIpv4Hello(const EigrpIpv4Hello& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv4Hello::~EigrpIpv4Hello()
{
}

EigrpIpv4Hello& EigrpIpv4Hello::operator=(const EigrpIpv4Hello& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Hello::copy(const EigrpIpv4Hello& other)
{
    this->parameterTlv = other.parameterTlv;
    this->stubTlv = other.stubTlv;
}

void EigrpIpv4Hello::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
    doParsimPacking(b,this->parameterTlv);
    doParsimPacking(b,this->stubTlv);
}

void EigrpIpv4Hello::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->parameterTlv);
    doParsimUnpacking(b,this->stubTlv);
}

const EigrpTlvParameter& EigrpIpv4Hello::getParameterTlv() const
{
    return this->parameterTlv;
}

void EigrpIpv4Hello::setParameterTlv(const EigrpTlvParameter& parameterTlv)
{
    handleChange();
    this->parameterTlv = parameterTlv;
}

const EigrpTlvStub& EigrpIpv4Hello::getStubTlv() const
{
    return this->stubTlv;
}

void EigrpIpv4Hello::setStubTlv(const EigrpTlvStub& stubTlv)
{
    handleChange();
    this->stubTlv = stubTlv;
}

class EigrpIpv4HelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameterTlv,
        FIELD_stubTlv,
    };
  public:
    EigrpIpv4HelloDescriptor();
    virtual ~EigrpIpv4HelloDescriptor();

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

Register_ClassDescriptor(EigrpIpv4HelloDescriptor)

EigrpIpv4HelloDescriptor::EigrpIpv4HelloDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Hello)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv4HelloDescriptor::~EigrpIpv4HelloDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4HelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Hello *>(obj)!=nullptr;
}

const char **EigrpIpv4HelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4HelloDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4HelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int EigrpIpv4HelloDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_parameterTlv
        FD_ISCOMPOUND,    // FIELD_stubTlv
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *EigrpIpv4HelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterTlv",
        "stubTlv",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int EigrpIpv4HelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterTlv") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "stubTlv") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4HelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::EigrpTlvParameter",    // FIELD_parameterTlv
        "inet::EigrpTlvStub",    // FIELD_stubTlv
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpIpv4HelloDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4HelloDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4HelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv4HelloDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Hello'", field);
    }
}

const char *EigrpIpv4HelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4HelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        case FIELD_parameterTlv: {std::stringstream out; out << pp->getParameterTlv(); return out.str();}
        case FIELD_stubTlv: {std::stringstream out; out << pp->getStubTlv(); return out.str();}
        default: return "";
    }
}

void EigrpIpv4HelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Hello'", field);
    }
}

const char *EigrpIpv4HelloDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_parameterTlv: return omnetpp::opp_typename(typeid(EigrpTlvParameter));
        case FIELD_stubTlv: return omnetpp::opp_typename(typeid(EigrpTlvStub));
        default: return nullptr;
    };
}

void *EigrpIpv4HelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        case FIELD_parameterTlv: return toVoidPtr(&pp->getParameterTlv()); break;
        case FIELD_stubTlv: return toVoidPtr(&pp->getStubTlv()); break;
        default: return nullptr;
    }
}

void EigrpIpv4HelloDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Hello *pp = (EigrpIpv4Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Hello'", field);
    }
}

Register_Class(EigrpIpv6Hello)

EigrpIpv6Hello::EigrpIpv6Hello() : ::inet::EigrpMessage()
{
}

EigrpIpv6Hello::EigrpIpv6Hello(const EigrpIpv6Hello& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv6Hello::~EigrpIpv6Hello()
{
}

EigrpIpv6Hello& EigrpIpv6Hello::operator=(const EigrpIpv6Hello& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Hello::copy(const EigrpIpv6Hello& other)
{
    this->parameterTlv = other.parameterTlv;
    this->stubTlv = other.stubTlv;
}

void EigrpIpv6Hello::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
    doParsimPacking(b,this->parameterTlv);
    doParsimPacking(b,this->stubTlv);
}

void EigrpIpv6Hello::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->parameterTlv);
    doParsimUnpacking(b,this->stubTlv);
}

const EigrpTlvParameter& EigrpIpv6Hello::getParameterTlv() const
{
    return this->parameterTlv;
}

void EigrpIpv6Hello::setParameterTlv(const EigrpTlvParameter& parameterTlv)
{
    handleChange();
    this->parameterTlv = parameterTlv;
}

const EigrpTlvStub& EigrpIpv6Hello::getStubTlv() const
{
    return this->stubTlv;
}

void EigrpIpv6Hello::setStubTlv(const EigrpTlvStub& stubTlv)
{
    handleChange();
    this->stubTlv = stubTlv;
}

class EigrpIpv6HelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameterTlv,
        FIELD_stubTlv,
    };
  public:
    EigrpIpv6HelloDescriptor();
    virtual ~EigrpIpv6HelloDescriptor();

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

Register_ClassDescriptor(EigrpIpv6HelloDescriptor)

EigrpIpv6HelloDescriptor::EigrpIpv6HelloDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Hello)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv6HelloDescriptor::~EigrpIpv6HelloDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6HelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Hello *>(obj)!=nullptr;
}

const char **EigrpIpv6HelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6HelloDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6HelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int EigrpIpv6HelloDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_parameterTlv
        FD_ISCOMPOUND,    // FIELD_stubTlv
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *EigrpIpv6HelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterTlv",
        "stubTlv",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int EigrpIpv6HelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterTlv") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "stubTlv") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6HelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::EigrpTlvParameter",    // FIELD_parameterTlv
        "inet::EigrpTlvStub",    // FIELD_stubTlv
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpIpv6HelloDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6HelloDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6HelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv6HelloDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Hello'", field);
    }
}

const char *EigrpIpv6HelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6HelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        case FIELD_parameterTlv: {std::stringstream out; out << pp->getParameterTlv(); return out.str();}
        case FIELD_stubTlv: {std::stringstream out; out << pp->getStubTlv(); return out.str();}
        default: return "";
    }
}

void EigrpIpv6HelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Hello'", field);
    }
}

const char *EigrpIpv6HelloDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_parameterTlv: return omnetpp::opp_typename(typeid(EigrpTlvParameter));
        case FIELD_stubTlv: return omnetpp::opp_typename(typeid(EigrpTlvStub));
        default: return nullptr;
    };
}

void *EigrpIpv6HelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        case FIELD_parameterTlv: return toVoidPtr(&pp->getParameterTlv()); break;
        case FIELD_stubTlv: return toVoidPtr(&pp->getStubTlv()); break;
        default: return nullptr;
    }
}

void EigrpIpv6HelloDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Hello *pp = (EigrpIpv6Hello *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Hello'", field);
    }
}

Register_Class(EigrpIpv4Ack)

EigrpIpv4Ack::EigrpIpv4Ack() : ::inet::EigrpMessage()
{
}

EigrpIpv4Ack::EigrpIpv4Ack(const EigrpIpv4Ack& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv4Ack::~EigrpIpv4Ack()
{
}

EigrpIpv4Ack& EigrpIpv4Ack::operator=(const EigrpIpv4Ack& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Ack::copy(const EigrpIpv4Ack& other)
{
}

void EigrpIpv4Ack::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
}

void EigrpIpv4Ack::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
}

class EigrpIpv4AckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv4AckDescriptor();
    virtual ~EigrpIpv4AckDescriptor();

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

Register_ClassDescriptor(EigrpIpv4AckDescriptor)

EigrpIpv4AckDescriptor::EigrpIpv4AckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Ack)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv4AckDescriptor::~EigrpIpv4AckDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4AckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Ack *>(obj)!=nullptr;
}

const char **EigrpIpv4AckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4AckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4AckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv4AckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv4AckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv4AckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4AckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv4AckDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4AckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4AckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv4AckDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Ack'", field);
    }
}

const char *EigrpIpv4AckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4AckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv4AckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Ack'", field);
    }
}

const char *EigrpIpv4AckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv4AckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv4AckDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Ack *pp = (EigrpIpv4Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Ack'", field);
    }
}

Register_Class(EigrpIpv6Ack)

EigrpIpv6Ack::EigrpIpv6Ack() : ::inet::EigrpMessage()
{
}

EigrpIpv6Ack::EigrpIpv6Ack(const EigrpIpv6Ack& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv6Ack::~EigrpIpv6Ack()
{
}

EigrpIpv6Ack& EigrpIpv6Ack::operator=(const EigrpIpv6Ack& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Ack::copy(const EigrpIpv6Ack& other)
{
}

void EigrpIpv6Ack::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
}

void EigrpIpv6Ack::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
}

class EigrpIpv6AckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv6AckDescriptor();
    virtual ~EigrpIpv6AckDescriptor();

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

Register_ClassDescriptor(EigrpIpv6AckDescriptor)

EigrpIpv6AckDescriptor::EigrpIpv6AckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Ack)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv6AckDescriptor::~EigrpIpv6AckDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6AckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Ack *>(obj)!=nullptr;
}

const char **EigrpIpv6AckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6AckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6AckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv6AckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv6AckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv6AckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6AckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv6AckDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6AckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6AckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv6AckDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Ack'", field);
    }
}

const char *EigrpIpv6AckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6AckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv6AckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Ack'", field);
    }
}

const char *EigrpIpv6AckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv6AckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv6AckDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Ack *pp = (EigrpIpv6Ack *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Ack'", field);
    }
}

Register_Class(EigrpIpv4Message)

EigrpIpv4Message::EigrpIpv4Message() : ::inet::EigrpMessage()
{
}

EigrpIpv4Message::EigrpIpv4Message(const EigrpIpv4Message& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv4Message::~EigrpIpv4Message()
{
    delete [] this->interRoutes;
}

EigrpIpv4Message& EigrpIpv4Message::operator=(const EigrpIpv4Message& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Message::copy(const EigrpIpv4Message& other)
{
    delete [] this->interRoutes;
    this->interRoutes = (other.interRoutes_arraysize==0) ? nullptr : new EigrpMpIpv4Internal[other.interRoutes_arraysize];
    interRoutes_arraysize = other.interRoutes_arraysize;
    for (size_t i = 0; i < interRoutes_arraysize; i++) {
        this->interRoutes[i] = other.interRoutes[i];
    }
}

void EigrpIpv4Message::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
    b->pack(interRoutes_arraysize);
    doParsimArrayPacking(b,this->interRoutes,interRoutes_arraysize);
}

void EigrpIpv4Message::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
    delete [] this->interRoutes;
    b->unpack(interRoutes_arraysize);
    if (interRoutes_arraysize == 0) {
        this->interRoutes = nullptr;
    } else {
        this->interRoutes = new EigrpMpIpv4Internal[interRoutes_arraysize];
        doParsimArrayUnpacking(b,this->interRoutes,interRoutes_arraysize);
    }
}

size_t EigrpIpv4Message::getInterRoutesArraySize() const
{
    return interRoutes_arraysize;
}

const EigrpMpIpv4Internal& EigrpIpv4Message::getInterRoutes(size_t k) const
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size interRoutes_arraysize indexed by %lu", (unsigned long)k);
    return this->interRoutes[k];
}

void EigrpIpv4Message::setInterRoutesArraySize(size_t newSize)
{
    handleChange();
    EigrpMpIpv4Internal *interRoutes2 = (newSize==0) ? nullptr : new EigrpMpIpv4Internal[newSize];
    size_t minSize = interRoutes_arraysize < newSize ? interRoutes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        interRoutes2[i] = this->interRoutes[i];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

void EigrpIpv4Message::setInterRoutes(size_t k, const EigrpMpIpv4Internal& interRoutes)
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->interRoutes[k] = interRoutes;
}

void EigrpIpv4Message::insertInterRoutes(size_t k, const EigrpMpIpv4Internal& interRoutes)
{
    if (k > interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = interRoutes_arraysize + 1;
    EigrpMpIpv4Internal *interRoutes2 = new EigrpMpIpv4Internal[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interRoutes2[i] = this->interRoutes[i];
    interRoutes2[k] = interRoutes;
    for (i = k + 1; i < newSize; i++)
        interRoutes2[i] = this->interRoutes[i-1];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

void EigrpIpv4Message::insertInterRoutes(const EigrpMpIpv4Internal& interRoutes)
{
    insertInterRoutes(interRoutes_arraysize, interRoutes);
}

void EigrpIpv4Message::eraseInterRoutes(size_t k)
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = interRoutes_arraysize - 1;
    EigrpMpIpv4Internal *interRoutes2 = (newSize == 0) ? nullptr : new EigrpMpIpv4Internal[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interRoutes2[i] = this->interRoutes[i];
    for (i = k; i < newSize; i++)
        interRoutes2[i] = this->interRoutes[i+1];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

class EigrpIpv4MessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interRoutes,
    };
  public:
    EigrpIpv4MessageDescriptor();
    virtual ~EigrpIpv4MessageDescriptor();

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

Register_ClassDescriptor(EigrpIpv4MessageDescriptor)

EigrpIpv4MessageDescriptor::EigrpIpv4MessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Message)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv4MessageDescriptor::~EigrpIpv4MessageDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4MessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Message *>(obj)!=nullptr;
}

const char **EigrpIpv4MessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4MessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4MessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int EigrpIpv4MessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_interRoutes
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *EigrpIpv4MessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interRoutes",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int EigrpIpv4MessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interRoutes") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4MessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::EigrpMpIpv4Internal",    // FIELD_interRoutes
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpIpv4MessageDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4MessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4MessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: return pp->getInterRoutesArraySize();
        default: return 0;
    }
}

void EigrpIpv4MessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: pp->setInterRoutesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Message'", field);
    }
}

const char *EigrpIpv4MessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4MessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: {std::stringstream out; out << pp->getInterRoutes(i); return out.str();}
        default: return "";
    }
}

void EigrpIpv4MessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Message'", field);
    }
}

const char *EigrpIpv4MessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_interRoutes: return omnetpp::opp_typename(typeid(EigrpMpIpv4Internal));
        default: return nullptr;
    };
}

void *EigrpIpv4MessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: return toVoidPtr(&pp->getInterRoutes(i)); break;
        default: return nullptr;
    }
}

void EigrpIpv4MessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Message *pp = (EigrpIpv4Message *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Message'", field);
    }
}

Register_Class(EigrpIpv6Message)

EigrpIpv6Message::EigrpIpv6Message() : ::inet::EigrpMessage()
{
}

EigrpIpv6Message::EigrpIpv6Message(const EigrpIpv6Message& other) : ::inet::EigrpMessage(other)
{
    copy(other);
}

EigrpIpv6Message::~EigrpIpv6Message()
{
    delete [] this->interRoutes;
}

EigrpIpv6Message& EigrpIpv6Message::operator=(const EigrpIpv6Message& other)
{
    if (this == &other) return *this;
    ::inet::EigrpMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Message::copy(const EigrpIpv6Message& other)
{
    delete [] this->interRoutes;
    this->interRoutes = (other.interRoutes_arraysize==0) ? nullptr : new EigrpMpIpv6Internal[other.interRoutes_arraysize];
    interRoutes_arraysize = other.interRoutes_arraysize;
    for (size_t i = 0; i < interRoutes_arraysize; i++) {
        this->interRoutes[i] = other.interRoutes[i];
    }
}

void EigrpIpv6Message::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpMessage::parsimPack(b);
    b->pack(interRoutes_arraysize);
    doParsimArrayPacking(b,this->interRoutes,interRoutes_arraysize);
}

void EigrpIpv6Message::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpMessage::parsimUnpack(b);
    delete [] this->interRoutes;
    b->unpack(interRoutes_arraysize);
    if (interRoutes_arraysize == 0) {
        this->interRoutes = nullptr;
    } else {
        this->interRoutes = new EigrpMpIpv6Internal[interRoutes_arraysize];
        doParsimArrayUnpacking(b,this->interRoutes,interRoutes_arraysize);
    }
}

size_t EigrpIpv6Message::getInterRoutesArraySize() const
{
    return interRoutes_arraysize;
}

const EigrpMpIpv6Internal& EigrpIpv6Message::getInterRoutes(size_t k) const
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size interRoutes_arraysize indexed by %lu", (unsigned long)k);
    return this->interRoutes[k];
}

void EigrpIpv6Message::setInterRoutesArraySize(size_t newSize)
{
    handleChange();
    EigrpMpIpv6Internal *interRoutes2 = (newSize==0) ? nullptr : new EigrpMpIpv6Internal[newSize];
    size_t minSize = interRoutes_arraysize < newSize ? interRoutes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        interRoutes2[i] = this->interRoutes[i];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

void EigrpIpv6Message::setInterRoutes(size_t k, const EigrpMpIpv6Internal& interRoutes)
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->interRoutes[k] = interRoutes;
}

void EigrpIpv6Message::insertInterRoutes(size_t k, const EigrpMpIpv6Internal& interRoutes)
{
    if (k > interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = interRoutes_arraysize + 1;
    EigrpMpIpv6Internal *interRoutes2 = new EigrpMpIpv6Internal[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interRoutes2[i] = this->interRoutes[i];
    interRoutes2[k] = interRoutes;
    for (i = k + 1; i < newSize; i++)
        interRoutes2[i] = this->interRoutes[i-1];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

void EigrpIpv6Message::insertInterRoutes(const EigrpMpIpv6Internal& interRoutes)
{
    insertInterRoutes(interRoutes_arraysize, interRoutes);
}

void EigrpIpv6Message::eraseInterRoutes(size_t k)
{
    if (k >= interRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = interRoutes_arraysize - 1;
    EigrpMpIpv6Internal *interRoutes2 = (newSize == 0) ? nullptr : new EigrpMpIpv6Internal[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interRoutes2[i] = this->interRoutes[i];
    for (i = k; i < newSize; i++)
        interRoutes2[i] = this->interRoutes[i+1];
    delete [] this->interRoutes;
    this->interRoutes = interRoutes2;
    interRoutes_arraysize = newSize;
}

class EigrpIpv6MessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interRoutes,
    };
  public:
    EigrpIpv6MessageDescriptor();
    virtual ~EigrpIpv6MessageDescriptor();

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

Register_ClassDescriptor(EigrpIpv6MessageDescriptor)

EigrpIpv6MessageDescriptor::EigrpIpv6MessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Message)), "inet::EigrpMessage")
{
    propertynames = nullptr;
}

EigrpIpv6MessageDescriptor::~EigrpIpv6MessageDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6MessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Message *>(obj)!=nullptr;
}

const char **EigrpIpv6MessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6MessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6MessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int EigrpIpv6MessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_interRoutes
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *EigrpIpv6MessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interRoutes",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int EigrpIpv6MessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interRoutes") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6MessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::EigrpMpIpv6Internal",    // FIELD_interRoutes
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpIpv6MessageDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6MessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6MessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: return pp->getInterRoutesArraySize();
        default: return 0;
    }
}

void EigrpIpv6MessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: pp->setInterRoutesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Message'", field);
    }
}

const char *EigrpIpv6MessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6MessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: {std::stringstream out; out << pp->getInterRoutes(i); return out.str();}
        default: return "";
    }
}

void EigrpIpv6MessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Message'", field);
    }
}

const char *EigrpIpv6MessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_interRoutes: return omnetpp::opp_typename(typeid(EigrpMpIpv6Internal));
        default: return nullptr;
    };
}

void *EigrpIpv6MessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        case FIELD_interRoutes: return toVoidPtr(&pp->getInterRoutes(i)); break;
        default: return nullptr;
    }
}

void EigrpIpv6MessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Message *pp = (EigrpIpv6Message *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Message'", field);
    }
}

Register_Class(EigrpIpv4Update)

EigrpIpv4Update::EigrpIpv4Update() : ::inet::EigrpIpv4Message()
{
}

EigrpIpv4Update::EigrpIpv4Update(const EigrpIpv4Update& other) : ::inet::EigrpIpv4Message(other)
{
    copy(other);
}

EigrpIpv4Update::~EigrpIpv4Update()
{
}

EigrpIpv4Update& EigrpIpv4Update::operator=(const EigrpIpv4Update& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv4Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Update::copy(const EigrpIpv4Update& other)
{
}

void EigrpIpv4Update::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv4Message::parsimPack(b);
}

void EigrpIpv4Update::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv4Message::parsimUnpack(b);
}

class EigrpIpv4UpdateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv4UpdateDescriptor();
    virtual ~EigrpIpv4UpdateDescriptor();

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

Register_ClassDescriptor(EigrpIpv4UpdateDescriptor)

EigrpIpv4UpdateDescriptor::EigrpIpv4UpdateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Update)), "inet::EigrpIpv4Message")
{
    propertynames = nullptr;
}

EigrpIpv4UpdateDescriptor::~EigrpIpv4UpdateDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4UpdateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Update *>(obj)!=nullptr;
}

const char **EigrpIpv4UpdateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4UpdateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4UpdateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv4UpdateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv4UpdateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv4UpdateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4UpdateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv4UpdateDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4UpdateDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4UpdateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv4UpdateDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Update'", field);
    }
}

const char *EigrpIpv4UpdateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4UpdateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv4UpdateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Update'", field);
    }
}

const char *EigrpIpv4UpdateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv4UpdateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv4UpdateDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Update *pp = (EigrpIpv4Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Update'", field);
    }
}

Register_Class(EigrpIpv6Update)

EigrpIpv6Update::EigrpIpv6Update() : ::inet::EigrpIpv6Message()
{
}

EigrpIpv6Update::EigrpIpv6Update(const EigrpIpv6Update& other) : ::inet::EigrpIpv6Message(other)
{
    copy(other);
}

EigrpIpv6Update::~EigrpIpv6Update()
{
}

EigrpIpv6Update& EigrpIpv6Update::operator=(const EigrpIpv6Update& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv6Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Update::copy(const EigrpIpv6Update& other)
{
}

void EigrpIpv6Update::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv6Message::parsimPack(b);
}

void EigrpIpv6Update::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv6Message::parsimUnpack(b);
}

class EigrpIpv6UpdateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv6UpdateDescriptor();
    virtual ~EigrpIpv6UpdateDescriptor();

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

Register_ClassDescriptor(EigrpIpv6UpdateDescriptor)

EigrpIpv6UpdateDescriptor::EigrpIpv6UpdateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Update)), "inet::EigrpIpv6Message")
{
    propertynames = nullptr;
}

EigrpIpv6UpdateDescriptor::~EigrpIpv6UpdateDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6UpdateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Update *>(obj)!=nullptr;
}

const char **EigrpIpv6UpdateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6UpdateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6UpdateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv6UpdateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv6UpdateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv6UpdateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6UpdateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv6UpdateDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6UpdateDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6UpdateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv6UpdateDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Update'", field);
    }
}

const char *EigrpIpv6UpdateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6UpdateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv6UpdateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Update'", field);
    }
}

const char *EigrpIpv6UpdateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv6UpdateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv6UpdateDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Update *pp = (EigrpIpv6Update *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Update'", field);
    }
}

Register_Class(EigrpIpv4Query)

EigrpIpv4Query::EigrpIpv4Query() : ::inet::EigrpIpv4Message()
{
}

EigrpIpv4Query::EigrpIpv4Query(const EigrpIpv4Query& other) : ::inet::EigrpIpv4Message(other)
{
    copy(other);
}

EigrpIpv4Query::~EigrpIpv4Query()
{
}

EigrpIpv4Query& EigrpIpv4Query::operator=(const EigrpIpv4Query& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv4Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Query::copy(const EigrpIpv4Query& other)
{
}

void EigrpIpv4Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv4Message::parsimPack(b);
}

void EigrpIpv4Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv4Message::parsimUnpack(b);
}

class EigrpIpv4QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv4QueryDescriptor();
    virtual ~EigrpIpv4QueryDescriptor();

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

Register_ClassDescriptor(EigrpIpv4QueryDescriptor)

EigrpIpv4QueryDescriptor::EigrpIpv4QueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Query)), "inet::EigrpIpv4Message")
{
    propertynames = nullptr;
}

EigrpIpv4QueryDescriptor::~EigrpIpv4QueryDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Query *>(obj)!=nullptr;
}

const char **EigrpIpv4QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv4QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv4QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv4QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv4QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv4QueryDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Query'", field);
    }
}

const char *EigrpIpv4QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv4QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Query'", field);
    }
}

const char *EigrpIpv4QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv4QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv4QueryDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Query *pp = (EigrpIpv4Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Query'", field);
    }
}

Register_Class(EigrpIpv6Query)

EigrpIpv6Query::EigrpIpv6Query() : ::inet::EigrpIpv6Message()
{
}

EigrpIpv6Query::EigrpIpv6Query(const EigrpIpv6Query& other) : ::inet::EigrpIpv6Message(other)
{
    copy(other);
}

EigrpIpv6Query::~EigrpIpv6Query()
{
}

EigrpIpv6Query& EigrpIpv6Query::operator=(const EigrpIpv6Query& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv6Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Query::copy(const EigrpIpv6Query& other)
{
}

void EigrpIpv6Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv6Message::parsimPack(b);
}

void EigrpIpv6Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv6Message::parsimUnpack(b);
}

class EigrpIpv6QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv6QueryDescriptor();
    virtual ~EigrpIpv6QueryDescriptor();

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

Register_ClassDescriptor(EigrpIpv6QueryDescriptor)

EigrpIpv6QueryDescriptor::EigrpIpv6QueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Query)), "inet::EigrpIpv6Message")
{
    propertynames = nullptr;
}

EigrpIpv6QueryDescriptor::~EigrpIpv6QueryDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Query *>(obj)!=nullptr;
}

const char **EigrpIpv6QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv6QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv6QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv6QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv6QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv6QueryDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Query'", field);
    }
}

const char *EigrpIpv6QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv6QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Query'", field);
    }
}

const char *EigrpIpv6QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv6QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv6QueryDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Query *pp = (EigrpIpv6Query *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Query'", field);
    }
}

Register_Class(EigrpIpv4Reply)

EigrpIpv4Reply::EigrpIpv4Reply() : ::inet::EigrpIpv4Message()
{
}

EigrpIpv4Reply::EigrpIpv4Reply(const EigrpIpv4Reply& other) : ::inet::EigrpIpv4Message(other)
{
    copy(other);
}

EigrpIpv4Reply::~EigrpIpv4Reply()
{
}

EigrpIpv4Reply& EigrpIpv4Reply::operator=(const EigrpIpv4Reply& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv4Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv4Reply::copy(const EigrpIpv4Reply& other)
{
}

void EigrpIpv4Reply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv4Message::parsimPack(b);
}

void EigrpIpv4Reply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv4Message::parsimUnpack(b);
}

class EigrpIpv4ReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv4ReplyDescriptor();
    virtual ~EigrpIpv4ReplyDescriptor();

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

Register_ClassDescriptor(EigrpIpv4ReplyDescriptor)

EigrpIpv4ReplyDescriptor::EigrpIpv4ReplyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv4Reply)), "inet::EigrpIpv4Message")
{
    propertynames = nullptr;
}

EigrpIpv4ReplyDescriptor::~EigrpIpv4ReplyDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv4ReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv4Reply *>(obj)!=nullptr;
}

const char **EigrpIpv4ReplyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv4ReplyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv4ReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv4ReplyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv4ReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv4ReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv4ReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv4ReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv4ReplyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv4ReplyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv4ReplyDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv4Reply'", field);
    }
}

const char *EigrpIpv4ReplyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv4ReplyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv4ReplyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Reply'", field);
    }
}

const char *EigrpIpv4ReplyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv4ReplyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv4ReplyDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv4Reply *pp = (EigrpIpv4Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv4Reply'", field);
    }
}

Register_Class(EigrpIpv6Reply)

EigrpIpv6Reply::EigrpIpv6Reply() : ::inet::EigrpIpv6Message()
{
}

EigrpIpv6Reply::EigrpIpv6Reply(const EigrpIpv6Reply& other) : ::inet::EigrpIpv6Message(other)
{
    copy(other);
}

EigrpIpv6Reply::~EigrpIpv6Reply()
{
}

EigrpIpv6Reply& EigrpIpv6Reply::operator=(const EigrpIpv6Reply& other)
{
    if (this == &other) return *this;
    ::inet::EigrpIpv6Message::operator=(other);
    copy(other);
    return *this;
}

void EigrpIpv6Reply::copy(const EigrpIpv6Reply& other)
{
}

void EigrpIpv6Reply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EigrpIpv6Message::parsimPack(b);
}

void EigrpIpv6Reply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EigrpIpv6Message::parsimUnpack(b);
}

class EigrpIpv6ReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    EigrpIpv6ReplyDescriptor();
    virtual ~EigrpIpv6ReplyDescriptor();

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

Register_ClassDescriptor(EigrpIpv6ReplyDescriptor)

EigrpIpv6ReplyDescriptor::EigrpIpv6ReplyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpIpv6Reply)), "inet::EigrpIpv6Message")
{
    propertynames = nullptr;
}

EigrpIpv6ReplyDescriptor::~EigrpIpv6ReplyDescriptor()
{
    delete[] propertynames;
}

bool EigrpIpv6ReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpIpv6Reply *>(obj)!=nullptr;
}

const char **EigrpIpv6ReplyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpIpv6ReplyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpIpv6ReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EigrpIpv6ReplyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EigrpIpv6ReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EigrpIpv6ReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpIpv6ReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EigrpIpv6ReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpIpv6ReplyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpIpv6ReplyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpIpv6ReplyDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpIpv6Reply'", field);
    }
}

const char *EigrpIpv6ReplyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpIpv6ReplyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void EigrpIpv6ReplyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Reply'", field);
    }
}

const char *EigrpIpv6ReplyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EigrpIpv6ReplyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void EigrpIpv6ReplyDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpIpv6Reply *pp = (EigrpIpv6Reply *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpIpv6Reply'", field);
    }
}

EigrpMsgRoute::EigrpMsgRoute()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const EigrpMsgRoute& a)
{
    doParsimPacking(b,a.sourceId);
    doParsimPacking(b,a.routeId);
    doParsimPacking(b,a.unreachable);
    doParsimPacking(b,a.invalid);
    doParsimPacking(b,a.originator);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EigrpMsgRoute& a)
{
    doParsimUnpacking(b,a.sourceId);
    doParsimUnpacking(b,a.routeId);
    doParsimUnpacking(b,a.unreachable);
    doParsimUnpacking(b,a.invalid);
    doParsimUnpacking(b,a.originator);
}

class EigrpMsgRouteDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sourceId,
        FIELD_routeId,
        FIELD_unreachable,
        FIELD_invalid,
        FIELD_originator,
    };
  public:
    EigrpMsgRouteDescriptor();
    virtual ~EigrpMsgRouteDescriptor();

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

Register_ClassDescriptor(EigrpMsgRouteDescriptor)

EigrpMsgRouteDescriptor::EigrpMsgRouteDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EigrpMsgRoute)), "")
{
    propertynames = nullptr;
}

EigrpMsgRouteDescriptor::~EigrpMsgRouteDescriptor()
{
    delete[] propertynames;
}

bool EigrpMsgRouteDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpMsgRoute *>(obj)!=nullptr;
}

const char **EigrpMsgRouteDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpMsgRouteDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpMsgRouteDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int EigrpMsgRouteDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sourceId
        FD_ISEDITABLE,    // FIELD_routeId
        FD_ISEDITABLE,    // FIELD_unreachable
        FD_ISEDITABLE,    // FIELD_invalid
        0,    // FIELD_originator
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *EigrpMsgRouteDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceId",
        "routeId",
        "unreachable",
        "invalid",
        "originator",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int EigrpMsgRouteDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceId") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routeId") == 0) return base+1;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unreachable") == 0) return base+2;
    if (fieldName[0] == 'i' && strcmp(fieldName, "invalid") == 0) return base+3;
    if (fieldName[0] == 'o' && strcmp(fieldName, "originator") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpMsgRouteDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sourceId
        "int",    // FIELD_routeId
        "bool",    // FIELD_unreachable
        "bool",    // FIELD_invalid
        "inet::Ipv4Address",    // FIELD_originator
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpMsgRouteDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpMsgRouteDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpMsgRouteDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EigrpMsgRouteDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpMsgRoute'", field);
    }
}

const char *EigrpMsgRouteDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpMsgRouteDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        case FIELD_sourceId: return long2string(pp->sourceId);
        case FIELD_routeId: return long2string(pp->routeId);
        case FIELD_unreachable: return bool2string(pp->unreachable);
        case FIELD_invalid: return bool2string(pp->invalid);
        case FIELD_originator: return pp->originator.str();
        default: return "";
    }
}

void EigrpMsgRouteDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        case FIELD_sourceId: pp->sourceId = string2long(value); break;
        case FIELD_routeId: pp->routeId = string2long(value); break;
        case FIELD_unreachable: pp->unreachable = string2bool(value); break;
        case FIELD_invalid: pp->invalid = string2bool(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMsgRoute'", field);
    }
}

const char *EigrpMsgRouteDescriptor::getFieldStructName(int field) const
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

void *EigrpMsgRouteDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        case FIELD_originator: return toVoidPtr(&pp->originator); break;
        default: return nullptr;
    }
}

void EigrpMsgRouteDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgRoute *pp = (EigrpMsgRoute *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMsgRoute'", field);
    }
}

EigrpMsgReq_Base::EigrpMsgReq_Base(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

EigrpMsgReq_Base::EigrpMsgReq_Base(const EigrpMsgReq_Base& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

EigrpMsgReq_Base::~EigrpMsgReq_Base()
{
    delete [] this->routes;
}

EigrpMsgReq_Base& EigrpMsgReq_Base::operator=(const EigrpMsgReq_Base& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void EigrpMsgReq_Base::copy(const EigrpMsgReq_Base& other)
{
    this->opcode = other.opcode;
    this->goodbyeMsg = other.goodbyeMsg;
    this->init = other.init;
    this->cr = other.cr;
    this->rs = other.rs;
    this->eot = other.eot;
    this->destNeighbor = other.destNeighbor;
    this->destInterface = other.destInterface;
    this->seqNumber = other.seqNumber;
    this->ackNumber = other.ackNumber;
    this->numOfAck = other.numOfAck;
    delete [] this->routes;
    this->routes = (other.routes_arraysize==0) ? nullptr : new EigrpMsgRoute[other.routes_arraysize];
    routes_arraysize = other.routes_arraysize;
    for (size_t i = 0; i < routes_arraysize; i++) {
        this->routes[i] = other.routes[i];
    }
}

void EigrpMsgReq_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->opcode);
    doParsimPacking(b,this->goodbyeMsg);
    doParsimPacking(b,this->init);
    doParsimPacking(b,this->cr);
    doParsimPacking(b,this->rs);
    doParsimPacking(b,this->eot);
    doParsimPacking(b,this->destNeighbor);
    doParsimPacking(b,this->destInterface);
    doParsimPacking(b,this->seqNumber);
    doParsimPacking(b,this->ackNumber);
    doParsimPacking(b,this->numOfAck);
    b->pack(routes_arraysize);
    doParsimArrayPacking(b,this->routes,routes_arraysize);
}

void EigrpMsgReq_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->opcode);
    doParsimUnpacking(b,this->goodbyeMsg);
    doParsimUnpacking(b,this->init);
    doParsimUnpacking(b,this->cr);
    doParsimUnpacking(b,this->rs);
    doParsimUnpacking(b,this->eot);
    doParsimUnpacking(b,this->destNeighbor);
    doParsimUnpacking(b,this->destInterface);
    doParsimUnpacking(b,this->seqNumber);
    doParsimUnpacking(b,this->ackNumber);
    doParsimUnpacking(b,this->numOfAck);
    delete [] this->routes;
    b->unpack(routes_arraysize);
    if (routes_arraysize == 0) {
        this->routes = nullptr;
    } else {
        this->routes = new EigrpMsgRoute[routes_arraysize];
        doParsimArrayUnpacking(b,this->routes,routes_arraysize);
    }
}

int8_t EigrpMsgReq_Base::getOpcode() const
{
    return this->opcode;
}

void EigrpMsgReq_Base::setOpcode(int8_t opcode)
{
    this->opcode = opcode;
}

bool EigrpMsgReq_Base::getGoodbyeMsg() const
{
    return this->goodbyeMsg;
}

void EigrpMsgReq_Base::setGoodbyeMsg(bool goodbyeMsg)
{
    this->goodbyeMsg = goodbyeMsg;
}

bool EigrpMsgReq_Base::getInit() const
{
    return this->init;
}

void EigrpMsgReq_Base::setInit(bool init)
{
    this->init = init;
}

bool EigrpMsgReq_Base::getCr() const
{
    return this->cr;
}

void EigrpMsgReq_Base::setCr(bool cr)
{
    this->cr = cr;
}

bool EigrpMsgReq_Base::getRs() const
{
    return this->rs;
}

void EigrpMsgReq_Base::setRs(bool rs)
{
    this->rs = rs;
}

bool EigrpMsgReq_Base::getEot() const
{
    return this->eot;
}

void EigrpMsgReq_Base::setEot(bool eot)
{
    this->eot = eot;
}

int EigrpMsgReq_Base::getDestNeighbor() const
{
    return this->destNeighbor;
}

void EigrpMsgReq_Base::setDestNeighbor(int destNeighbor)
{
    this->destNeighbor = destNeighbor;
}

int EigrpMsgReq_Base::getDestInterface() const
{
    return this->destInterface;
}

void EigrpMsgReq_Base::setDestInterface(int destInterface)
{
    this->destInterface = destInterface;
}

uint32_t EigrpMsgReq_Base::getSeqNumber() const
{
    return this->seqNumber;
}

void EigrpMsgReq_Base::setSeqNumber(uint32_t seqNumber)
{
    this->seqNumber = seqNumber;
}

uint32_t EigrpMsgReq_Base::getAckNumber() const
{
    return this->ackNumber;
}

void EigrpMsgReq_Base::setAckNumber(uint32_t ackNumber)
{
    this->ackNumber = ackNumber;
}

int EigrpMsgReq_Base::getNumOfAck() const
{
    return this->numOfAck;
}

void EigrpMsgReq_Base::setNumOfAck(int numOfAck)
{
    this->numOfAck = numOfAck;
}

size_t EigrpMsgReq_Base::getRoutesArraySize() const
{
    return routes_arraysize;
}

const EigrpMsgRoute& EigrpMsgReq_Base::getRoutes(size_t k) const
{
    if (k >= routes_arraysize) throw omnetpp::cRuntimeError("Array of size routes_arraysize indexed by %lu", (unsigned long)k);
    return this->routes[k];
}

void EigrpMsgReq_Base::setRoutesArraySize(size_t newSize)
{
    EigrpMsgRoute *routes2 = (newSize==0) ? nullptr : new EigrpMsgRoute[newSize];
    size_t minSize = routes_arraysize < newSize ? routes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        routes2[i] = this->routes[i];
    delete [] this->routes;
    this->routes = routes2;
    routes_arraysize = newSize;
}

void EigrpMsgReq_Base::setRoutes(size_t k, const EigrpMsgRoute& routes)
{
    if (k >= routes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->routes[k] = routes;
}

void EigrpMsgReq_Base::insertRoutes(size_t k, const EigrpMsgRoute& routes)
{
    if (k > routes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = routes_arraysize + 1;
    EigrpMsgRoute *routes2 = new EigrpMsgRoute[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        routes2[i] = this->routes[i];
    routes2[k] = routes;
    for (i = k + 1; i < newSize; i++)
        routes2[i] = this->routes[i-1];
    delete [] this->routes;
    this->routes = routes2;
    routes_arraysize = newSize;
}

void EigrpMsgReq_Base::insertRoutes(const EigrpMsgRoute& routes)
{
    insertRoutes(routes_arraysize, routes);
}

void EigrpMsgReq_Base::eraseRoutes(size_t k)
{
    if (k >= routes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = routes_arraysize - 1;
    EigrpMsgRoute *routes2 = (newSize == 0) ? nullptr : new EigrpMsgRoute[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        routes2[i] = this->routes[i];
    for (i = k; i < newSize; i++)
        routes2[i] = this->routes[i+1];
    delete [] this->routes;
    this->routes = routes2;
    routes_arraysize = newSize;
}

class EigrpMsgReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_opcode,
        FIELD_goodbyeMsg,
        FIELD_init,
        FIELD_cr,
        FIELD_rs,
        FIELD_eot,
        FIELD_destNeighbor,
        FIELD_destInterface,
        FIELD_seqNumber,
        FIELD_ackNumber,
        FIELD_numOfAck,
        FIELD_routes,
    };
  public:
    EigrpMsgReqDescriptor();
    virtual ~EigrpMsgReqDescriptor();

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

Register_ClassDescriptor(EigrpMsgReqDescriptor)

EigrpMsgReqDescriptor::EigrpMsgReqDescriptor() : omnetpp::cClassDescriptor("inet::EigrpMsgReq", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

EigrpMsgReqDescriptor::~EigrpMsgReqDescriptor()
{
    delete[] propertynames;
}

bool EigrpMsgReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EigrpMsgReq_Base *>(obj)!=nullptr;
}

const char **EigrpMsgReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EigrpMsgReqDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EigrpMsgReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int EigrpMsgReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_opcode
        FD_ISEDITABLE,    // FIELD_goodbyeMsg
        FD_ISEDITABLE,    // FIELD_init
        FD_ISEDITABLE,    // FIELD_cr
        FD_ISEDITABLE,    // FIELD_rs
        FD_ISEDITABLE,    // FIELD_eot
        FD_ISEDITABLE,    // FIELD_destNeighbor
        FD_ISEDITABLE,    // FIELD_destInterface
        FD_ISEDITABLE,    // FIELD_seqNumber
        FD_ISEDITABLE,    // FIELD_ackNumber
        FD_ISEDITABLE,    // FIELD_numOfAck
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_routes
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *EigrpMsgReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "opcode",
        "goodbyeMsg",
        "init",
        "cr",
        "rs",
        "eot",
        "destNeighbor",
        "destInterface",
        "seqNumber",
        "ackNumber",
        "numOfAck",
        "routes",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int EigrpMsgReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "opcode") == 0) return base+0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "goodbyeMsg") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "init") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cr") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rs") == 0) return base+4;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eot") == 0) return base+5;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destNeighbor") == 0) return base+6;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destInterface") == 0) return base+7;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNumber") == 0) return base+8;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackNumber") == 0) return base+9;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numOfAck") == 0) return base+10;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routes") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EigrpMsgReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int8_t",    // FIELD_opcode
        "bool",    // FIELD_goodbyeMsg
        "bool",    // FIELD_init
        "bool",    // FIELD_cr
        "bool",    // FIELD_rs
        "bool",    // FIELD_eot
        "int",    // FIELD_destNeighbor
        "int",    // FIELD_destInterface
        "uint32_t",    // FIELD_seqNumber
        "uint32_t",    // FIELD_ackNumber
        "int",    // FIELD_numOfAck
        "inet::EigrpMsgRoute",    // FIELD_routes
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **EigrpMsgReqDescriptor::getFieldPropertyNames(int field) const
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

const char *EigrpMsgReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EigrpMsgReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        case FIELD_routes: return pp->getRoutesArraySize();
        default: return 0;
    }
}

void EigrpMsgReqDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        case FIELD_routes: pp->setRoutesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EigrpMsgReq_Base'", field);
    }
}

const char *EigrpMsgReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EigrpMsgReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        case FIELD_opcode: return long2string(pp->getOpcode());
        case FIELD_goodbyeMsg: return bool2string(pp->getGoodbyeMsg());
        case FIELD_init: return bool2string(pp->getInit());
        case FIELD_cr: return bool2string(pp->getCr());
        case FIELD_rs: return bool2string(pp->getRs());
        case FIELD_eot: return bool2string(pp->getEot());
        case FIELD_destNeighbor: return long2string(pp->getDestNeighbor());
        case FIELD_destInterface: return long2string(pp->getDestInterface());
        case FIELD_seqNumber: return ulong2string(pp->getSeqNumber());
        case FIELD_ackNumber: return ulong2string(pp->getAckNumber());
        case FIELD_numOfAck: return long2string(pp->getNumOfAck());
        case FIELD_routes: {std::stringstream out; out << pp->getRoutes(i); return out.str();}
        default: return "";
    }
}

void EigrpMsgReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        case FIELD_opcode: pp->setOpcode(string2long(value)); break;
        case FIELD_goodbyeMsg: pp->setGoodbyeMsg(string2bool(value)); break;
        case FIELD_init: pp->setInit(string2bool(value)); break;
        case FIELD_cr: pp->setCr(string2bool(value)); break;
        case FIELD_rs: pp->setRs(string2bool(value)); break;
        case FIELD_eot: pp->setEot(string2bool(value)); break;
        case FIELD_destNeighbor: pp->setDestNeighbor(string2long(value)); break;
        case FIELD_destInterface: pp->setDestInterface(string2long(value)); break;
        case FIELD_seqNumber: pp->setSeqNumber(string2ulong(value)); break;
        case FIELD_ackNumber: pp->setAckNumber(string2ulong(value)); break;
        case FIELD_numOfAck: pp->setNumOfAck(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMsgReq_Base'", field);
    }
}

const char *EigrpMsgReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_routes: return omnetpp::opp_typename(typeid(EigrpMsgRoute));
        default: return nullptr;
    };
}

void *EigrpMsgReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        case FIELD_routes: return toVoidPtr(&pp->getRoutes(i)); break;
        default: return nullptr;
    }
}

void EigrpMsgReqDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    EigrpMsgReq_Base *pp = (EigrpMsgReq_Base *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EigrpMsgReq_Base'", field);
    }
}

} // namespace inet

