//
// Generated file, do not edit! Created by nedtool 6.0 from inet/common/packet/Packet.msg.
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
#include "Packet_m.h"

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

class PacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_dataLength,
        FIELD_totalLength,
        FIELD_data,
        FIELD_dissection,
        FIELD_content,
        FIELD_tags,
        FIELD_regionTags,
        FIELD_frontOffset,
        FIELD_backOffset,
        FIELD_front,
        FIELD_back,
    };
  public:
    PacketDescriptor();
    virtual ~PacketDescriptor();

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

Register_ClassDescriptor(PacketDescriptor)

PacketDescriptor::PacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Packet)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

PacketDescriptor::~PacketDescriptor()
{
    delete[] propertynames;
}

bool PacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Packet *>(obj)!=nullptr;
}

const char **PacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int PacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_dataLength
        0,    // FIELD_totalLength
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_data
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_dissection
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_content
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_tags
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_regionTags
        0,    // FIELD_frontOffset
        0,    // FIELD_backOffset
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_front
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_back
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *PacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dataLength",
        "totalLength",
        "data",
        "dissection",
        "content",
        "tags",
        "regionTags",
        "frontOffset",
        "backOffset",
        "front",
        "back",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int PacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataLength") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalLength") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dissection") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "content") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "tags") == 0) return base+5;
    if (fieldName[0] == 'r' && strcmp(fieldName, "regionTags") == 0) return base+6;
    if (fieldName[0] == 'f' && strcmp(fieldName, "frontOffset") == 0) return base+7;
    if (fieldName[0] == 'b' && strcmp(fieldName, "backOffset") == 0) return base+8;
    if (fieldName[0] == 'f' && strcmp(fieldName, "front") == 0) return base+9;
    if (fieldName[0] == 'b' && strcmp(fieldName, "back") == 0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::b",    // FIELD_dataLength
        "inet::b",    // FIELD_totalLength
        "inet::ChunkTemporarySharedPtr",    // FIELD_data
        "inet::ChunkTemporarySharedPtr",    // FIELD_dissection
        "inet::Chunk",    // FIELD_content
        "omnetpp::cObject",    // FIELD_tags
        "inet::SharingRegionTagSet::TagBaseRegionTag",    // FIELD_regionTags
        "inet::b",    // FIELD_frontOffset
        "inet::b",    // FIELD_backOffset
        "inet::ChunkTemporarySharedPtr",    // FIELD_front
        "inet::ChunkTemporarySharedPtr",    // FIELD_back
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: {
            static const char *names[] = { "packetData", "getter",  nullptr };
            return names;
        }
        case FIELD_dissection: {
            static const char *names[] = { "packetData", "getter",  nullptr };
            return names;
        }
        case FIELD_content: {
            static const char *names[] = { "packetData", "getter",  nullptr };
            return names;
        }
        case FIELD_tags: {
            static const char *names[] = { "getter", "sizeGetter",  nullptr };
            return names;
        }
        case FIELD_regionTags: {
            static const char *names[] = { "getter", "sizeGetter",  nullptr };
            return names;
        }
        case FIELD_front: {
            static const char *names[] = { "packetData", "getter",  nullptr };
            return names;
        }
        case FIELD_back: {
            static const char *names[] = { "packetData", "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data:
            if (!strcmp(propertyname, "packetData")) return "";
            if (!strcmp(propertyname, "getter")) return "getData";
            return nullptr;
        case FIELD_dissection:
            if (!strcmp(propertyname, "packetData")) return "";
            if (!strcmp(propertyname, "getter")) return "getDissection";
            return nullptr;
        case FIELD_content:
            if (!strcmp(propertyname, "packetData")) return "";
            if (!strcmp(propertyname, "getter")) return "getContent";
            return nullptr;
        case FIELD_tags:
            if (!strcmp(propertyname, "getter")) return "_getTag";
            if (!strcmp(propertyname, "sizeGetter")) return "getNumTags";
            return nullptr;
        case FIELD_regionTags:
            if (!strcmp(propertyname, "getter")) return "_getRegionTag";
            if (!strcmp(propertyname, "sizeGetter")) return "getNumRegionTags";
            return nullptr;
        case FIELD_front:
            if (!strcmp(propertyname, "packetData")) return "";
            if (!strcmp(propertyname, "getter")) return "getFront";
            return nullptr;
        case FIELD_back:
            if (!strcmp(propertyname, "packetData")) return "";
            if (!strcmp(propertyname, "getter")) return "getBack";
            return nullptr;
        default: return nullptr;
    }
}

int PacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case FIELD_tags: return pp->getNumTags();
        case FIELD_regionTags: return pp->getNumRegionTags();
        default: return 0;
    }
}

void PacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Packet'", field);
    }
}

const char *PacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case FIELD_data: { const ChunkTemporarySharedPtr * value = pp->getData(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_dissection: { const ChunkTemporarySharedPtr * value = pp->getDissection(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_content: { const Chunk * value = pp->getContent(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_tags: { const cObject * value = pp->_getTag(i); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_front: { const ChunkTemporarySharedPtr * value = pp->getFront(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_back: { const ChunkTemporarySharedPtr * value = pp->getBack(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string PacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case FIELD_dataLength: return unit2string(pp->getDataLength());
        case FIELD_totalLength: return unit2string(pp->getTotalLength());
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        case FIELD_dissection: {std::stringstream out; out << pp->getDissection(); return out.str();}
        case FIELD_content: {std::stringstream out; out << pp->getContent(); return out.str();}
        case FIELD_tags: {std::stringstream out; out << pp->_getTag(i); return out.str();}
        case FIELD_regionTags: {std::stringstream out; out << pp->_getRegionTag(i); return out.str();}
        case FIELD_frontOffset: return unit2string(pp->getFrontOffset());
        case FIELD_backOffset: return unit2string(pp->getBackOffset());
        case FIELD_front: {std::stringstream out; out << pp->getFront(); return out.str();}
        case FIELD_back: {std::stringstream out; out << pp->getBack(); return out.str();}
        default: return "";
    }
}

void PacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Packet'", field);
    }
}

const char *PacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(ChunkTemporarySharedPtr));
        case FIELD_dissection: return omnetpp::opp_typename(typeid(ChunkTemporarySharedPtr));
        case FIELD_content: return omnetpp::opp_typename(typeid(Chunk));
        case FIELD_tags: return omnetpp::opp_typename(typeid(cObject));
        case FIELD_regionTags: return omnetpp::opp_typename(typeid(SharingRegionTagSet::TagBaseRegionTag));
        case FIELD_front: return omnetpp::opp_typename(typeid(ChunkTemporarySharedPtr));
        case FIELD_back: return omnetpp::opp_typename(typeid(ChunkTemporarySharedPtr));
        default: return nullptr;
    };
}

void *PacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(pp->getData()); break;
        case FIELD_dissection: return toVoidPtr(pp->getDissection()); break;
        case FIELD_content: return toVoidPtr(pp->getContent()); break;
        case FIELD_tags: return toVoidPtr(pp->_getTag(i)); break;
        case FIELD_regionTags: return toVoidPtr(&pp->_getRegionTag(i)); break;
        case FIELD_front: return toVoidPtr(pp->getFront()); break;
        case FIELD_back: return toVoidPtr(pp->getBack()); break;
        default: return nullptr;
    }
}

void PacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Packet'", field);
    }
}

} // namespace inet

