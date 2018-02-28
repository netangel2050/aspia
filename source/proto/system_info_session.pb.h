// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: system_info_session.proto

#ifndef PROTOBUF_system_5finfo_5fsession_2eproto__INCLUDED
#define PROTOBUF_system_5finfo_5fsession_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)

namespace protobuf_system_5finfo_5fsession_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsHostToClientImpl();
void InitDefaultsHostToClient();
void InitDefaultsClientToHostImpl();
void InitDefaultsClientToHost();
inline void InitDefaults() {
  InitDefaultsHostToClient();
  InitDefaultsClientToHost();
}
}  // namespace protobuf_system_5finfo_5fsession_2eproto
namespace proto {
namespace system_info {
class ClientToHost;
class ClientToHostDefaultTypeInternal;
extern ClientToHostDefaultTypeInternal _ClientToHost_default_instance_;
class HostToClient;
class HostToClientDefaultTypeInternal;
extern HostToClientDefaultTypeInternal _HostToClient_default_instance_;
}  // namespace system_info
}  // namespace proto
namespace proto {
namespace system_info {

enum HostToClient_Compressor {
  HostToClient_Compressor_COMPRESSOR_RAW = 0,
  HostToClient_Compressor_COMPRESSOR_ZLIB = 1,
  HostToClient_Compressor_HostToClient_Compressor_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  HostToClient_Compressor_HostToClient_Compressor_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool HostToClient_Compressor_IsValid(int value);
const HostToClient_Compressor HostToClient_Compressor_Compressor_MIN = HostToClient_Compressor_COMPRESSOR_RAW;
const HostToClient_Compressor HostToClient_Compressor_Compressor_MAX = HostToClient_Compressor_COMPRESSOR_ZLIB;
const int HostToClient_Compressor_Compressor_ARRAYSIZE = HostToClient_Compressor_Compressor_MAX + 1;

// ===================================================================

class HostToClient : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.system_info.HostToClient) */ {
 public:
  HostToClient();
  virtual ~HostToClient();

  HostToClient(const HostToClient& from);

  inline HostToClient& operator=(const HostToClient& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HostToClient(HostToClient&& from) noexcept
    : HostToClient() {
    *this = ::std::move(from);
  }

  inline HostToClient& operator=(HostToClient&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const HostToClient& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HostToClient* internal_default_instance() {
    return reinterpret_cast<const HostToClient*>(
               &_HostToClient_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(HostToClient* other);
  friend void swap(HostToClient& a, HostToClient& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HostToClient* New() const PROTOBUF_FINAL { return New(NULL); }

  HostToClient* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const HostToClient& from);
  void MergeFrom(const HostToClient& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HostToClient* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef HostToClient_Compressor Compressor;
  static const Compressor COMPRESSOR_RAW =
    HostToClient_Compressor_COMPRESSOR_RAW;
  static const Compressor COMPRESSOR_ZLIB =
    HostToClient_Compressor_COMPRESSOR_ZLIB;
  static inline bool Compressor_IsValid(int value) {
    return HostToClient_Compressor_IsValid(value);
  }
  static const Compressor Compressor_MIN =
    HostToClient_Compressor_Compressor_MIN;
  static const Compressor Compressor_MAX =
    HostToClient_Compressor_Compressor_MAX;
  static const int Compressor_ARRAYSIZE =
    HostToClient_Compressor_Compressor_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // string guid = 1;
  void clear_guid();
  static const int kGuidFieldNumber = 1;
  const ::std::string& guid() const;
  void set_guid(const ::std::string& value);
  #if LANG_CXX11
  void set_guid(::std::string&& value);
  #endif
  void set_guid(const char* value);
  void set_guid(const char* value, size_t size);
  ::std::string* mutable_guid();
  ::std::string* release_guid();
  void set_allocated_guid(::std::string* guid);

  // bytes data = 3;
  void clear_data();
  static const int kDataFieldNumber = 3;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // .proto.system_info.HostToClient.Compressor compressor = 2;
  void clear_compressor();
  static const int kCompressorFieldNumber = 2;
  ::proto::system_info::HostToClient_Compressor compressor() const;
  void set_compressor(::proto::system_info::HostToClient_Compressor value);

  // @@protoc_insertion_point(class_scope:proto.system_info.HostToClient)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr guid_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  int compressor_;
  mutable int _cached_size_;
  friend struct ::protobuf_system_5finfo_5fsession_2eproto::TableStruct;
  friend void ::protobuf_system_5finfo_5fsession_2eproto::InitDefaultsHostToClientImpl();
};
// -------------------------------------------------------------------

class ClientToHost : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.system_info.ClientToHost) */ {
 public:
  ClientToHost();
  virtual ~ClientToHost();

  ClientToHost(const ClientToHost& from);

  inline ClientToHost& operator=(const ClientToHost& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ClientToHost(ClientToHost&& from) noexcept
    : ClientToHost() {
    *this = ::std::move(from);
  }

  inline ClientToHost& operator=(ClientToHost&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ClientToHost& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClientToHost* internal_default_instance() {
    return reinterpret_cast<const ClientToHost*>(
               &_ClientToHost_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ClientToHost* other);
  friend void swap(ClientToHost& a, ClientToHost& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ClientToHost* New() const PROTOBUF_FINAL { return New(NULL); }

  ClientToHost* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const ClientToHost& from);
  void MergeFrom(const ClientToHost& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ClientToHost* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string guid = 1;
  void clear_guid();
  static const int kGuidFieldNumber = 1;
  const ::std::string& guid() const;
  void set_guid(const ::std::string& value);
  #if LANG_CXX11
  void set_guid(::std::string&& value);
  #endif
  void set_guid(const char* value);
  void set_guid(const char* value, size_t size);
  ::std::string* mutable_guid();
  ::std::string* release_guid();
  void set_allocated_guid(::std::string* guid);

  // @@protoc_insertion_point(class_scope:proto.system_info.ClientToHost)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr guid_;
  mutable int _cached_size_;
  friend struct ::protobuf_system_5finfo_5fsession_2eproto::TableStruct;
  friend void ::protobuf_system_5finfo_5fsession_2eproto::InitDefaultsClientToHostImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HostToClient

// string guid = 1;
inline void HostToClient::clear_guid() {
  guid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HostToClient::guid() const {
  // @@protoc_insertion_point(field_get:proto.system_info.HostToClient.guid)
  return guid_.GetNoArena();
}
inline void HostToClient::set_guid(const ::std::string& value) {
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.system_info.HostToClient.guid)
}
#if LANG_CXX11
inline void HostToClient::set_guid(::std::string&& value) {
  
  guid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.system_info.HostToClient.guid)
}
#endif
inline void HostToClient::set_guid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.system_info.HostToClient.guid)
}
inline void HostToClient::set_guid(const char* value, size_t size) {
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.system_info.HostToClient.guid)
}
inline ::std::string* HostToClient::mutable_guid() {
  
  // @@protoc_insertion_point(field_mutable:proto.system_info.HostToClient.guid)
  return guid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HostToClient::release_guid() {
  // @@protoc_insertion_point(field_release:proto.system_info.HostToClient.guid)
  
  return guid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostToClient::set_allocated_guid(::std::string* guid) {
  if (guid != NULL) {
    
  } else {
    
  }
  guid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), guid);
  // @@protoc_insertion_point(field_set_allocated:proto.system_info.HostToClient.guid)
}

// .proto.system_info.HostToClient.Compressor compressor = 2;
inline void HostToClient::clear_compressor() {
  compressor_ = 0;
}
inline ::proto::system_info::HostToClient_Compressor HostToClient::compressor() const {
  // @@protoc_insertion_point(field_get:proto.system_info.HostToClient.compressor)
  return static_cast< ::proto::system_info::HostToClient_Compressor >(compressor_);
}
inline void HostToClient::set_compressor(::proto::system_info::HostToClient_Compressor value) {
  
  compressor_ = value;
  // @@protoc_insertion_point(field_set:proto.system_info.HostToClient.compressor)
}

// bytes data = 3;
inline void HostToClient::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HostToClient::data() const {
  // @@protoc_insertion_point(field_get:proto.system_info.HostToClient.data)
  return data_.GetNoArena();
}
inline void HostToClient::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.system_info.HostToClient.data)
}
#if LANG_CXX11
inline void HostToClient::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.system_info.HostToClient.data)
}
#endif
inline void HostToClient::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.system_info.HostToClient.data)
}
inline void HostToClient::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.system_info.HostToClient.data)
}
inline ::std::string* HostToClient::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:proto.system_info.HostToClient.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HostToClient::release_data() {
  // @@protoc_insertion_point(field_release:proto.system_info.HostToClient.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostToClient::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:proto.system_info.HostToClient.data)
}

// -------------------------------------------------------------------

// ClientToHost

// string guid = 1;
inline void ClientToHost::clear_guid() {
  guid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ClientToHost::guid() const {
  // @@protoc_insertion_point(field_get:proto.system_info.ClientToHost.guid)
  return guid_.GetNoArena();
}
inline void ClientToHost::set_guid(const ::std::string& value) {
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.system_info.ClientToHost.guid)
}
#if LANG_CXX11
inline void ClientToHost::set_guid(::std::string&& value) {
  
  guid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.system_info.ClientToHost.guid)
}
#endif
inline void ClientToHost::set_guid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.system_info.ClientToHost.guid)
}
inline void ClientToHost::set_guid(const char* value, size_t size) {
  
  guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.system_info.ClientToHost.guid)
}
inline ::std::string* ClientToHost::mutable_guid() {
  
  // @@protoc_insertion_point(field_mutable:proto.system_info.ClientToHost.guid)
  return guid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ClientToHost::release_guid() {
  // @@protoc_insertion_point(field_release:proto.system_info.ClientToHost.guid)
  
  return guid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ClientToHost::set_allocated_guid(::std::string* guid) {
  if (guid != NULL) {
    
  } else {
    
  }
  guid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), guid);
  // @@protoc_insertion_point(field_set_allocated:proto.system_info.ClientToHost.guid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace system_info
}  // namespace proto

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::proto::system_info::HostToClient_Compressor> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_system_5finfo_5fsession_2eproto__INCLUDED
