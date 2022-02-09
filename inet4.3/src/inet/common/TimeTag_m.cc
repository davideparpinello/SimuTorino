//
// Generated file, do not edit! Created by nedtool 6.0 from inet/common/TimeTag.msg.
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
#include "TimeTag_m.h"

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

Register_Class(CreationTimeTag)

CreationTimeTag::CreationTimeTag() : ::inet::TagBase()
{
}

CreationTimeTag::CreationTimeTag(const CreationTimeTag& other) : ::inet::TagBase(other)
{
    copy(other);
}

CreationTimeTag::~CreationTimeTag()
{
}

CreationTimeTag& CreationTimeTag::operator=(const CreationTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void CreationTimeTag::copy(const CreationTimeTag& other)
{
    this->creationTime = other.creationTime;
}

void CreationTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->creationTime);
}

void CreationTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->creationTime);
}

omnetpp::simtime_t CreationTimeTag::getCreationTime() const
{
    return this->creationTime;
}

void CreationTimeTag::setCreationTime(omnetpp::simtime_t creationTime)
{
    this->creationTime = creationTime;
}

class CreationTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_creationTime,
    };
  public:
    CreationTimeTagDescriptor();
    virtual ~CreationTimeTagDescriptor();

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

Register_ClassDescriptor(CreationTimeTagDescriptor)

CreationTimeTagDescriptor::CreationTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CreationTimeTag)), "inet::TagBase")
{
    propertynames = nullptr;
}

CreationTimeTagDescriptor::~CreationTimeTagDescriptor()
{
    delete[] propertynames;
}

bool CreationTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CreationTimeTag *>(obj)!=nullptr;
}

const char **CreationTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CreationTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CreationTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CreationTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_creationTime
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *CreationTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "creationTime",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int CreationTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "creationTime") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CreationTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_creationTime
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **CreationTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *CreationTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int CreationTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CreationTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CreationTimeTag'", field);
    }
}

const char *CreationTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CreationTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        case FIELD_creationTime: return simtime2string(pp->getCreationTime());
        default: return "";
    }
}

void CreationTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreationTimeTag'", field);
    }
}

const char *CreationTimeTagDescriptor::getFieldStructName(int field) const
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

void *CreationTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void CreationTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    CreationTimeTag *pp = (CreationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreationTimeTag'", field);
    }
}

Register_Class(TimeTagBase)

TimeTagBase::TimeTagBase() : ::inet::TagBase()
{
}

TimeTagBase::TimeTagBase(const TimeTagBase& other) : ::inet::TagBase(other)
{
    copy(other);
}

TimeTagBase::~TimeTagBase()
{
    delete [] this->flowNames;
    delete [] this->totalTimes;
}

TimeTagBase& TimeTagBase::operator=(const TimeTagBase& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void TimeTagBase::copy(const TimeTagBase& other)
{
    delete [] this->flowNames;
    this->flowNames = (other.flowNames_arraysize==0) ? nullptr : new omnetpp::opp_string[other.flowNames_arraysize];
    flowNames_arraysize = other.flowNames_arraysize;
    for (size_t i = 0; i < flowNames_arraysize; i++) {
        this->flowNames[i] = other.flowNames[i];
    }
    delete [] this->totalTimes;
    this->totalTimes = (other.totalTimes_arraysize==0) ? nullptr : new omnetpp::simtime_t[other.totalTimes_arraysize];
    totalTimes_arraysize = other.totalTimes_arraysize;
    for (size_t i = 0; i < totalTimes_arraysize; i++) {
        this->totalTimes[i] = other.totalTimes[i];
    }
}

void TimeTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    b->pack(flowNames_arraysize);
    doParsimArrayPacking(b,this->flowNames,flowNames_arraysize);
    b->pack(totalTimes_arraysize);
    doParsimArrayPacking(b,this->totalTimes,totalTimes_arraysize);
}

void TimeTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    delete [] this->flowNames;
    b->unpack(flowNames_arraysize);
    if (flowNames_arraysize == 0) {
        this->flowNames = nullptr;
    } else {
        this->flowNames = new omnetpp::opp_string[flowNames_arraysize];
        doParsimArrayUnpacking(b,this->flowNames,flowNames_arraysize);
    }
    delete [] this->totalTimes;
    b->unpack(totalTimes_arraysize);
    if (totalTimes_arraysize == 0) {
        this->totalTimes = nullptr;
    } else {
        this->totalTimes = new omnetpp::simtime_t[totalTimes_arraysize];
        doParsimArrayUnpacking(b,this->totalTimes,totalTimes_arraysize);
    }
}

size_t TimeTagBase::getFlowNamesArraySize() const
{
    return flowNames_arraysize;
}

const char * TimeTagBase::getFlowNames(size_t k) const
{
    if (k >= flowNames_arraysize) throw omnetpp::cRuntimeError("Array of size flowNames_arraysize indexed by %lu", (unsigned long)k);
    return this->flowNames[k].c_str();
}

void TimeTagBase::setFlowNamesArraySize(size_t newSize)
{
    omnetpp::opp_string *flowNames2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = flowNames_arraysize < newSize ? flowNames_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        flowNames2[i] = this->flowNames[i];
    delete [] this->flowNames;
    this->flowNames = flowNames2;
    flowNames_arraysize = newSize;
}

void TimeTagBase::setFlowNames(size_t k, const char * flowNames)
{
    if (k >= flowNames_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->flowNames[k] = flowNames;
}

void TimeTagBase::insertFlowNames(size_t k, const char * flowNames)
{
    if (k > flowNames_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = flowNames_arraysize + 1;
    omnetpp::opp_string *flowNames2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        flowNames2[i] = this->flowNames[i];
    flowNames2[k] = flowNames;
    for (i = k + 1; i < newSize; i++)
        flowNames2[i] = this->flowNames[i-1];
    delete [] this->flowNames;
    this->flowNames = flowNames2;
    flowNames_arraysize = newSize;
}

void TimeTagBase::insertFlowNames(const char * flowNames)
{
    insertFlowNames(flowNames_arraysize, flowNames);
}

void TimeTagBase::eraseFlowNames(size_t k)
{
    if (k >= flowNames_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = flowNames_arraysize - 1;
    omnetpp::opp_string *flowNames2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        flowNames2[i] = this->flowNames[i];
    for (i = k; i < newSize; i++)
        flowNames2[i] = this->flowNames[i+1];
    delete [] this->flowNames;
    this->flowNames = flowNames2;
    flowNames_arraysize = newSize;
}

size_t TimeTagBase::getTotalTimesArraySize() const
{
    return totalTimes_arraysize;
}

omnetpp::simtime_t TimeTagBase::getTotalTimes(size_t k) const
{
    if (k >= totalTimes_arraysize) throw omnetpp::cRuntimeError("Array of size totalTimes_arraysize indexed by %lu", (unsigned long)k);
    return this->totalTimes[k];
}

void TimeTagBase::setTotalTimesArraySize(size_t newSize)
{
    omnetpp::simtime_t *totalTimes2 = (newSize==0) ? nullptr : new omnetpp::simtime_t[newSize];
    size_t minSize = totalTimes_arraysize < newSize ? totalTimes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        totalTimes2[i] = this->totalTimes[i];
    for (size_t i = minSize; i < newSize; i++)
        totalTimes2[i] = SIMTIME_ZERO;
    delete [] this->totalTimes;
    this->totalTimes = totalTimes2;
    totalTimes_arraysize = newSize;
}

void TimeTagBase::setTotalTimes(size_t k, omnetpp::simtime_t totalTimes)
{
    if (k >= totalTimes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->totalTimes[k] = totalTimes;
}

void TimeTagBase::insertTotalTimes(size_t k, omnetpp::simtime_t totalTimes)
{
    if (k > totalTimes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = totalTimes_arraysize + 1;
    omnetpp::simtime_t *totalTimes2 = new omnetpp::simtime_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        totalTimes2[i] = this->totalTimes[i];
    totalTimes2[k] = totalTimes;
    for (i = k + 1; i < newSize; i++)
        totalTimes2[i] = this->totalTimes[i-1];
    delete [] this->totalTimes;
    this->totalTimes = totalTimes2;
    totalTimes_arraysize = newSize;
}

void TimeTagBase::insertTotalTimes(omnetpp::simtime_t totalTimes)
{
    insertTotalTimes(totalTimes_arraysize, totalTimes);
}

void TimeTagBase::eraseTotalTimes(size_t k)
{
    if (k >= totalTimes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = totalTimes_arraysize - 1;
    omnetpp::simtime_t *totalTimes2 = (newSize == 0) ? nullptr : new omnetpp::simtime_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        totalTimes2[i] = this->totalTimes[i];
    for (i = k; i < newSize; i++)
        totalTimes2[i] = this->totalTimes[i+1];
    delete [] this->totalTimes;
    this->totalTimes = totalTimes2;
    totalTimes_arraysize = newSize;
}

class TimeTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_flowNames,
        FIELD_totalTimes,
    };
  public:
    TimeTagBaseDescriptor();
    virtual ~TimeTagBaseDescriptor();

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

Register_ClassDescriptor(TimeTagBaseDescriptor)

TimeTagBaseDescriptor::TimeTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TimeTagBase)), "inet::TagBase")
{
    propertynames = nullptr;
}

TimeTagBaseDescriptor::~TimeTagBaseDescriptor()
{
    delete[] propertynames;
}

bool TimeTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TimeTagBase *>(obj)!=nullptr;
}

const char **TimeTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TimeTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TimeTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TimeTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_flowNames
        FD_ISARRAY | FD_ISRESIZABLE,    // FIELD_totalTimes
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *TimeTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flowNames",
        "totalTimes",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int TimeTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flowNames") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalTimes") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TimeTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_flowNames
        "omnetpp::simtime_t",    // FIELD_totalTimes
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **TimeTagBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *TimeTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TimeTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_flowNames: return pp->getFlowNamesArraySize();
        case FIELD_totalTimes: return pp->getTotalTimesArraySize();
        default: return 0;
    }
}

void TimeTagBaseDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_flowNames: pp->setFlowNamesArraySize(size); break;
        case FIELD_totalTimes: pp->setTotalTimesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TimeTagBase'", field);
    }
}

const char *TimeTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TimeTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_flowNames: return oppstring2string(pp->getFlowNames(i));
        case FIELD_totalTimes: return simtime2string(pp->getTotalTimes(i));
        default: return "";
    }
}

void TimeTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_flowNames: pp->setFlowNames(i,(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TimeTagBase'", field);
    }
}

const char *TimeTagBaseDescriptor::getFieldStructName(int field) const
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

void *TimeTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void TimeTagBaseDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TimeTagBase *pp = (TimeTagBase *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TimeTagBase'", field);
    }
}

Register_Class(ElapsedTimeTag)

ElapsedTimeTag::ElapsedTimeTag() : ::inet::TimeTagBase()
{
}

ElapsedTimeTag::ElapsedTimeTag(const ElapsedTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

ElapsedTimeTag::~ElapsedTimeTag()
{
}

ElapsedTimeTag& ElapsedTimeTag::operator=(const ElapsedTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void ElapsedTimeTag::copy(const ElapsedTimeTag& other)
{
}

void ElapsedTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void ElapsedTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class ElapsedTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    ElapsedTimeTagDescriptor();
    virtual ~ElapsedTimeTagDescriptor();

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

Register_ClassDescriptor(ElapsedTimeTagDescriptor)

ElapsedTimeTagDescriptor::ElapsedTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ElapsedTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

ElapsedTimeTagDescriptor::~ElapsedTimeTagDescriptor()
{
    delete[] propertynames;
}

bool ElapsedTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ElapsedTimeTag *>(obj)!=nullptr;
}

const char **ElapsedTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ElapsedTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ElapsedTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int ElapsedTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *ElapsedTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int ElapsedTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ElapsedTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **ElapsedTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *ElapsedTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ElapsedTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ElapsedTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ElapsedTimeTag'", field);
    }
}

const char *ElapsedTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ElapsedTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void ElapsedTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ElapsedTimeTag'", field);
    }
}

const char *ElapsedTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *ElapsedTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void ElapsedTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ElapsedTimeTag *pp = (ElapsedTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ElapsedTimeTag'", field);
    }
}

Register_Class(DelayingTimeTag)

DelayingTimeTag::DelayingTimeTag() : ::inet::TimeTagBase()
{
}

DelayingTimeTag::DelayingTimeTag(const DelayingTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

DelayingTimeTag::~DelayingTimeTag()
{
}

DelayingTimeTag& DelayingTimeTag::operator=(const DelayingTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void DelayingTimeTag::copy(const DelayingTimeTag& other)
{
}

void DelayingTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void DelayingTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class DelayingTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    DelayingTimeTagDescriptor();
    virtual ~DelayingTimeTagDescriptor();

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

Register_ClassDescriptor(DelayingTimeTagDescriptor)

DelayingTimeTagDescriptor::DelayingTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DelayingTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

DelayingTimeTagDescriptor::~DelayingTimeTagDescriptor()
{
    delete[] propertynames;
}

bool DelayingTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DelayingTimeTag *>(obj)!=nullptr;
}

const char **DelayingTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DelayingTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DelayingTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int DelayingTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *DelayingTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int DelayingTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DelayingTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **DelayingTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *DelayingTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int DelayingTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DelayingTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DelayingTimeTag'", field);
    }
}

const char *DelayingTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DelayingTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void DelayingTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DelayingTimeTag'", field);
    }
}

const char *DelayingTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *DelayingTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void DelayingTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    DelayingTimeTag *pp = (DelayingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DelayingTimeTag'", field);
    }
}

Register_Class(QueueingTimeTag)

QueueingTimeTag::QueueingTimeTag() : ::inet::TimeTagBase()
{
}

QueueingTimeTag::QueueingTimeTag(const QueueingTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

QueueingTimeTag::~QueueingTimeTag()
{
}

QueueingTimeTag& QueueingTimeTag::operator=(const QueueingTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void QueueingTimeTag::copy(const QueueingTimeTag& other)
{
}

void QueueingTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void QueueingTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class QueueingTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    QueueingTimeTagDescriptor();
    virtual ~QueueingTimeTagDescriptor();

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

Register_ClassDescriptor(QueueingTimeTagDescriptor)

QueueingTimeTagDescriptor::QueueingTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::QueueingTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

QueueingTimeTagDescriptor::~QueueingTimeTagDescriptor()
{
    delete[] propertynames;
}

bool QueueingTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<QueueingTimeTag *>(obj)!=nullptr;
}

const char **QueueingTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *QueueingTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int QueueingTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int QueueingTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *QueueingTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int QueueingTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *QueueingTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **QueueingTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *QueueingTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int QueueingTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void QueueingTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'QueueingTimeTag'", field);
    }
}

const char *QueueingTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string QueueingTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void QueueingTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueueingTimeTag'", field);
    }
}

const char *QueueingTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *QueueingTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void QueueingTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    QueueingTimeTag *pp = (QueueingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueueingTimeTag'", field);
    }
}

Register_Class(ProcessingTimeTag)

ProcessingTimeTag::ProcessingTimeTag() : ::inet::TimeTagBase()
{
}

ProcessingTimeTag::ProcessingTimeTag(const ProcessingTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

ProcessingTimeTag::~ProcessingTimeTag()
{
}

ProcessingTimeTag& ProcessingTimeTag::operator=(const ProcessingTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void ProcessingTimeTag::copy(const ProcessingTimeTag& other)
{
}

void ProcessingTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void ProcessingTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class ProcessingTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    ProcessingTimeTagDescriptor();
    virtual ~ProcessingTimeTagDescriptor();

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

Register_ClassDescriptor(ProcessingTimeTagDescriptor)

ProcessingTimeTagDescriptor::ProcessingTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ProcessingTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

ProcessingTimeTagDescriptor::~ProcessingTimeTagDescriptor()
{
    delete[] propertynames;
}

bool ProcessingTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ProcessingTimeTag *>(obj)!=nullptr;
}

const char **ProcessingTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ProcessingTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ProcessingTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int ProcessingTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *ProcessingTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int ProcessingTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ProcessingTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **ProcessingTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *ProcessingTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ProcessingTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ProcessingTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ProcessingTimeTag'", field);
    }
}

const char *ProcessingTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ProcessingTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void ProcessingTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ProcessingTimeTag'", field);
    }
}

const char *ProcessingTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *ProcessingTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void ProcessingTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    ProcessingTimeTag *pp = (ProcessingTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ProcessingTimeTag'", field);
    }
}

Register_Class(TransmissionTimeTag)

TransmissionTimeTag::TransmissionTimeTag() : ::inet::TimeTagBase()
{
}

TransmissionTimeTag::TransmissionTimeTag(const TransmissionTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

TransmissionTimeTag::~TransmissionTimeTag()
{
}

TransmissionTimeTag& TransmissionTimeTag::operator=(const TransmissionTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void TransmissionTimeTag::copy(const TransmissionTimeTag& other)
{
}

void TransmissionTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void TransmissionTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class TransmissionTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    TransmissionTimeTagDescriptor();
    virtual ~TransmissionTimeTagDescriptor();

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

Register_ClassDescriptor(TransmissionTimeTagDescriptor)

TransmissionTimeTagDescriptor::TransmissionTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TransmissionTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

TransmissionTimeTagDescriptor::~TransmissionTimeTagDescriptor()
{
    delete[] propertynames;
}

bool TransmissionTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransmissionTimeTag *>(obj)!=nullptr;
}

const char **TransmissionTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TransmissionTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TransmissionTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TransmissionTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TransmissionTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TransmissionTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TransmissionTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TransmissionTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *TransmissionTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TransmissionTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TransmissionTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TransmissionTimeTag'", field);
    }
}

const char *TransmissionTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransmissionTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void TransmissionTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransmissionTimeTag'", field);
    }
}

const char *TransmissionTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TransmissionTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void TransmissionTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    TransmissionTimeTag *pp = (TransmissionTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransmissionTimeTag'", field);
    }
}

Register_Class(PropagationTimeTag)

PropagationTimeTag::PropagationTimeTag() : ::inet::TimeTagBase()
{
}

PropagationTimeTag::PropagationTimeTag(const PropagationTimeTag& other) : ::inet::TimeTagBase(other)
{
    copy(other);
}

PropagationTimeTag::~PropagationTimeTag()
{
}

PropagationTimeTag& PropagationTimeTag::operator=(const PropagationTimeTag& other)
{
    if (this == &other) return *this;
    ::inet::TimeTagBase::operator=(other);
    copy(other);
    return *this;
}

void PropagationTimeTag::copy(const PropagationTimeTag& other)
{
}

void PropagationTimeTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TimeTagBase::parsimPack(b);
}

void PropagationTimeTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TimeTagBase::parsimUnpack(b);
}

class PropagationTimeTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    PropagationTimeTagDescriptor();
    virtual ~PropagationTimeTagDescriptor();

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

Register_ClassDescriptor(PropagationTimeTagDescriptor)

PropagationTimeTagDescriptor::PropagationTimeTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PropagationTimeTag)), "inet::TimeTagBase")
{
    propertynames = nullptr;
}

PropagationTimeTagDescriptor::~PropagationTimeTagDescriptor()
{
    delete[] propertynames;
}

bool PropagationTimeTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PropagationTimeTag *>(obj)!=nullptr;
}

const char **PropagationTimeTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PropagationTimeTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PropagationTimeTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int PropagationTimeTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *PropagationTimeTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int PropagationTimeTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PropagationTimeTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **PropagationTimeTagDescriptor::getFieldPropertyNames(int field) const
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

const char *PropagationTimeTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PropagationTimeTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PropagationTimeTagDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PropagationTimeTag'", field);
    }
}

const char *PropagationTimeTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PropagationTimeTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

void PropagationTimeTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PropagationTimeTag'", field);
    }
}

const char *PropagationTimeTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *PropagationTimeTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void PropagationTimeTagDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PropagationTimeTag *pp = (PropagationTimeTag *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PropagationTimeTag'", field);
    }
}

} // namespace inet

