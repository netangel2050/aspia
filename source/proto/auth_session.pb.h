// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: auth_session.proto

#ifndef PROTOBUF_auth_5fsession_2eproto__INCLUDED
#define PROTOBUF_auth_5fsession_2eproto__INCLUDED

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

namespace protobuf_auth_5fsession_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsAllowMethodsImpl();
void InitDefaultsAllowMethods();
void InitDefaultsSelectMethodImpl();
void InitDefaultsSelectMethod();
void InitDefaultsBasicRequestImpl();
void InitDefaultsBasicRequest();
void InitDefaultsBasicResponseImpl();
void InitDefaultsBasicResponse();
void InitDefaultsBasicResultImpl();
void InitDefaultsBasicResult();
inline void InitDefaults() {
  InitDefaultsAllowMethods();
  InitDefaultsSelectMethod();
  InitDefaultsBasicRequest();
  InitDefaultsBasicResponse();
  InitDefaultsBasicResult();
}
}  // namespace protobuf_auth_5fsession_2eproto
namespace proto {
namespace auth {
class AllowMethods;
class AllowMethodsDefaultTypeInternal;
extern AllowMethodsDefaultTypeInternal _AllowMethods_default_instance_;
class BasicRequest;
class BasicRequestDefaultTypeInternal;
extern BasicRequestDefaultTypeInternal _BasicRequest_default_instance_;
class BasicResponse;
class BasicResponseDefaultTypeInternal;
extern BasicResponseDefaultTypeInternal _BasicResponse_default_instance_;
class BasicResult;
class BasicResultDefaultTypeInternal;
extern BasicResultDefaultTypeInternal _BasicResult_default_instance_;
class SelectMethod;
class SelectMethodDefaultTypeInternal;
extern SelectMethodDefaultTypeInternal _SelectMethod_default_instance_;
}  // namespace auth
}  // namespace proto
namespace proto {
namespace auth {

enum Method {
  METHOD_UNKNOWN = 0,
  METHOD_BASIC = 1,
  Method_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Method_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Method_IsValid(int value);
const Method Method_MIN = METHOD_UNKNOWN;
const Method Method_MAX = METHOD_BASIC;
const int Method_ARRAYSIZE = Method_MAX + 1;

enum SessionType {
  SESSION_TYPE_UNKNOWN = 0,
  SESSION_TYPE_DESKTOP_MANAGE = 1,
  SESSION_TYPE_DESKTOP_VIEW = 2,
  SESSION_TYPE_FILE_TRANSFER = 4,
  SESSION_TYPE_SYSTEM_INFO = 8,
  SessionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SessionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SessionType_IsValid(int value);
const SessionType SessionType_MIN = SESSION_TYPE_UNKNOWN;
const SessionType SessionType_MAX = SESSION_TYPE_SYSTEM_INFO;
const int SessionType_ARRAYSIZE = SessionType_MAX + 1;

enum Status {
  STATUS_UNKNOWN = 0,
  STATUS_SUCCESS = 1,
  STATUS_ACCESS_DENIED = 2,
  Status_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Status_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Status_IsValid(int value);
const Status Status_MIN = STATUS_UNKNOWN;
const Status Status_MAX = STATUS_ACCESS_DENIED;
const int Status_ARRAYSIZE = Status_MAX + 1;

// ===================================================================

class AllowMethods : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.auth.AllowMethods) */ {
 public:
  AllowMethods();
  virtual ~AllowMethods();

  AllowMethods(const AllowMethods& from);

  inline AllowMethods& operator=(const AllowMethods& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AllowMethods(AllowMethods&& from) noexcept
    : AllowMethods() {
    *this = ::std::move(from);
  }

  inline AllowMethods& operator=(AllowMethods&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const AllowMethods& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AllowMethods* internal_default_instance() {
    return reinterpret_cast<const AllowMethods*>(
               &_AllowMethods_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(AllowMethods* other);
  friend void swap(AllowMethods& a, AllowMethods& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AllowMethods* New() const PROTOBUF_FINAL { return New(NULL); }

  AllowMethods* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const AllowMethods& from);
  void MergeFrom(const AllowMethods& from);
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
  void InternalSwap(AllowMethods* other);
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

  // uint32 methods = 1;
  void clear_methods();
  static const int kMethodsFieldNumber = 1;
  ::google::protobuf::uint32 methods() const;
  void set_methods(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto.auth.AllowMethods)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::uint32 methods_;
  mutable int _cached_size_;
  friend struct ::protobuf_auth_5fsession_2eproto::TableStruct;
  friend void ::protobuf_auth_5fsession_2eproto::InitDefaultsAllowMethodsImpl();
};
// -------------------------------------------------------------------

class SelectMethod : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.auth.SelectMethod) */ {
 public:
  SelectMethod();
  virtual ~SelectMethod();

  SelectMethod(const SelectMethod& from);

  inline SelectMethod& operator=(const SelectMethod& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SelectMethod(SelectMethod&& from) noexcept
    : SelectMethod() {
    *this = ::std::move(from);
  }

  inline SelectMethod& operator=(SelectMethod&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const SelectMethod& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SelectMethod* internal_default_instance() {
    return reinterpret_cast<const SelectMethod*>(
               &_SelectMethod_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(SelectMethod* other);
  friend void swap(SelectMethod& a, SelectMethod& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SelectMethod* New() const PROTOBUF_FINAL { return New(NULL); }

  SelectMethod* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const SelectMethod& from);
  void MergeFrom(const SelectMethod& from);
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
  void InternalSwap(SelectMethod* other);
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

  // .proto.auth.Method method = 1;
  void clear_method();
  static const int kMethodFieldNumber = 1;
  ::proto::auth::Method method() const;
  void set_method(::proto::auth::Method value);

  // @@protoc_insertion_point(class_scope:proto.auth.SelectMethod)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  int method_;
  mutable int _cached_size_;
  friend struct ::protobuf_auth_5fsession_2eproto::TableStruct;
  friend void ::protobuf_auth_5fsession_2eproto::InitDefaultsSelectMethodImpl();
};
// -------------------------------------------------------------------

class BasicRequest : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.auth.BasicRequest) */ {
 public:
  BasicRequest();
  virtual ~BasicRequest();

  BasicRequest(const BasicRequest& from);

  inline BasicRequest& operator=(const BasicRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BasicRequest(BasicRequest&& from) noexcept
    : BasicRequest() {
    *this = ::std::move(from);
  }

  inline BasicRequest& operator=(BasicRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BasicRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BasicRequest* internal_default_instance() {
    return reinterpret_cast<const BasicRequest*>(
               &_BasicRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(BasicRequest* other);
  friend void swap(BasicRequest& a, BasicRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BasicRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  BasicRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const BasicRequest& from);
  void MergeFrom(const BasicRequest& from);
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
  void InternalSwap(BasicRequest* other);
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

  // bytes nonce = 1;
  void clear_nonce();
  static const int kNonceFieldNumber = 1;
  const ::std::string& nonce() const;
  void set_nonce(const ::std::string& value);
  #if LANG_CXX11
  void set_nonce(::std::string&& value);
  #endif
  void set_nonce(const char* value);
  void set_nonce(const void* value, size_t size);
  ::std::string* mutable_nonce();
  ::std::string* release_nonce();
  void set_allocated_nonce(::std::string* nonce);

  // @@protoc_insertion_point(class_scope:proto.auth.BasicRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr nonce_;
  mutable int _cached_size_;
  friend struct ::protobuf_auth_5fsession_2eproto::TableStruct;
  friend void ::protobuf_auth_5fsession_2eproto::InitDefaultsBasicRequestImpl();
};
// -------------------------------------------------------------------

class BasicResponse : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.auth.BasicResponse) */ {
 public:
  BasicResponse();
  virtual ~BasicResponse();

  BasicResponse(const BasicResponse& from);

  inline BasicResponse& operator=(const BasicResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BasicResponse(BasicResponse&& from) noexcept
    : BasicResponse() {
    *this = ::std::move(from);
  }

  inline BasicResponse& operator=(BasicResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BasicResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BasicResponse* internal_default_instance() {
    return reinterpret_cast<const BasicResponse*>(
               &_BasicResponse_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(BasicResponse* other);
  friend void swap(BasicResponse& a, BasicResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BasicResponse* New() const PROTOBUF_FINAL { return New(NULL); }

  BasicResponse* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const BasicResponse& from);
  void MergeFrom(const BasicResponse& from);
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
  void InternalSwap(BasicResponse* other);
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

  // string username = 2;
  void clear_username();
  static const int kUsernameFieldNumber = 2;
  const ::std::string& username() const;
  void set_username(const ::std::string& value);
  #if LANG_CXX11
  void set_username(::std::string&& value);
  #endif
  void set_username(const char* value);
  void set_username(const char* value, size_t size);
  ::std::string* mutable_username();
  ::std::string* release_username();
  void set_allocated_username(::std::string* username);

  // bytes key = 3;
  void clear_key();
  static const int kKeyFieldNumber = 3;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  #if LANG_CXX11
  void set_key(::std::string&& value);
  #endif
  void set_key(const char* value);
  void set_key(const void* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // .proto.auth.SessionType session_type = 1;
  void clear_session_type();
  static const int kSessionTypeFieldNumber = 1;
  ::proto::auth::SessionType session_type() const;
  void set_session_type(::proto::auth::SessionType value);

  // @@protoc_insertion_point(class_scope:proto.auth.BasicResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  int session_type_;
  mutable int _cached_size_;
  friend struct ::protobuf_auth_5fsession_2eproto::TableStruct;
  friend void ::protobuf_auth_5fsession_2eproto::InitDefaultsBasicResponseImpl();
};
// -------------------------------------------------------------------

class BasicResult : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:proto.auth.BasicResult) */ {
 public:
  BasicResult();
  virtual ~BasicResult();

  BasicResult(const BasicResult& from);

  inline BasicResult& operator=(const BasicResult& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BasicResult(BasicResult&& from) noexcept
    : BasicResult() {
    *this = ::std::move(from);
  }

  inline BasicResult& operator=(BasicResult&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BasicResult& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BasicResult* internal_default_instance() {
    return reinterpret_cast<const BasicResult*>(
               &_BasicResult_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(BasicResult* other);
  friend void swap(BasicResult& a, BasicResult& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BasicResult* New() const PROTOBUF_FINAL { return New(NULL); }

  BasicResult* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const BasicResult& from);
  void MergeFrom(const BasicResult& from);
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
  void InternalSwap(BasicResult* other);
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

  // .proto.auth.Status status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::proto::auth::Status status() const;
  void set_status(::proto::auth::Status value);

  // @@protoc_insertion_point(class_scope:proto.auth.BasicResult)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  int status_;
  mutable int _cached_size_;
  friend struct ::protobuf_auth_5fsession_2eproto::TableStruct;
  friend void ::protobuf_auth_5fsession_2eproto::InitDefaultsBasicResultImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AllowMethods

// uint32 methods = 1;
inline void AllowMethods::clear_methods() {
  methods_ = 0u;
}
inline ::google::protobuf::uint32 AllowMethods::methods() const {
  // @@protoc_insertion_point(field_get:proto.auth.AllowMethods.methods)
  return methods_;
}
inline void AllowMethods::set_methods(::google::protobuf::uint32 value) {
  
  methods_ = value;
  // @@protoc_insertion_point(field_set:proto.auth.AllowMethods.methods)
}

// -------------------------------------------------------------------

// SelectMethod

// .proto.auth.Method method = 1;
inline void SelectMethod::clear_method() {
  method_ = 0;
}
inline ::proto::auth::Method SelectMethod::method() const {
  // @@protoc_insertion_point(field_get:proto.auth.SelectMethod.method)
  return static_cast< ::proto::auth::Method >(method_);
}
inline void SelectMethod::set_method(::proto::auth::Method value) {
  
  method_ = value;
  // @@protoc_insertion_point(field_set:proto.auth.SelectMethod.method)
}

// -------------------------------------------------------------------

// BasicRequest

// bytes nonce = 1;
inline void BasicRequest::clear_nonce() {
  nonce_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BasicRequest::nonce() const {
  // @@protoc_insertion_point(field_get:proto.auth.BasicRequest.nonce)
  return nonce_.GetNoArena();
}
inline void BasicRequest::set_nonce(const ::std::string& value) {
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.auth.BasicRequest.nonce)
}
#if LANG_CXX11
inline void BasicRequest::set_nonce(::std::string&& value) {
  
  nonce_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.auth.BasicRequest.nonce)
}
#endif
inline void BasicRequest::set_nonce(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.auth.BasicRequest.nonce)
}
inline void BasicRequest::set_nonce(const void* value, size_t size) {
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.auth.BasicRequest.nonce)
}
inline ::std::string* BasicRequest::mutable_nonce() {
  
  // @@protoc_insertion_point(field_mutable:proto.auth.BasicRequest.nonce)
  return nonce_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BasicRequest::release_nonce() {
  // @@protoc_insertion_point(field_release:proto.auth.BasicRequest.nonce)
  
  return nonce_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BasicRequest::set_allocated_nonce(::std::string* nonce) {
  if (nonce != NULL) {
    
  } else {
    
  }
  nonce_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nonce);
  // @@protoc_insertion_point(field_set_allocated:proto.auth.BasicRequest.nonce)
}

// -------------------------------------------------------------------

// BasicResponse

// .proto.auth.SessionType session_type = 1;
inline void BasicResponse::clear_session_type() {
  session_type_ = 0;
}
inline ::proto::auth::SessionType BasicResponse::session_type() const {
  // @@protoc_insertion_point(field_get:proto.auth.BasicResponse.session_type)
  return static_cast< ::proto::auth::SessionType >(session_type_);
}
inline void BasicResponse::set_session_type(::proto::auth::SessionType value) {
  
  session_type_ = value;
  // @@protoc_insertion_point(field_set:proto.auth.BasicResponse.session_type)
}

// string username = 2;
inline void BasicResponse::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BasicResponse::username() const {
  // @@protoc_insertion_point(field_get:proto.auth.BasicResponse.username)
  return username_.GetNoArena();
}
inline void BasicResponse::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.auth.BasicResponse.username)
}
#if LANG_CXX11
inline void BasicResponse::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.auth.BasicResponse.username)
}
#endif
inline void BasicResponse::set_username(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.auth.BasicResponse.username)
}
inline void BasicResponse::set_username(const char* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.auth.BasicResponse.username)
}
inline ::std::string* BasicResponse::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:proto.auth.BasicResponse.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BasicResponse::release_username() {
  // @@protoc_insertion_point(field_release:proto.auth.BasicResponse.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BasicResponse::set_allocated_username(::std::string* username) {
  if (username != NULL) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:proto.auth.BasicResponse.username)
}

// bytes key = 3;
inline void BasicResponse::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BasicResponse::key() const {
  // @@protoc_insertion_point(field_get:proto.auth.BasicResponse.key)
  return key_.GetNoArena();
}
inline void BasicResponse::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto.auth.BasicResponse.key)
}
#if LANG_CXX11
inline void BasicResponse::set_key(::std::string&& value) {
  
  key_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:proto.auth.BasicResponse.key)
}
#endif
inline void BasicResponse::set_key(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto.auth.BasicResponse.key)
}
inline void BasicResponse::set_key(const void* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto.auth.BasicResponse.key)
}
inline ::std::string* BasicResponse::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:proto.auth.BasicResponse.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BasicResponse::release_key() {
  // @@protoc_insertion_point(field_release:proto.auth.BasicResponse.key)
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BasicResponse::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:proto.auth.BasicResponse.key)
}

// -------------------------------------------------------------------

// BasicResult

// .proto.auth.Status status = 1;
inline void BasicResult::clear_status() {
  status_ = 0;
}
inline ::proto::auth::Status BasicResult::status() const {
  // @@protoc_insertion_point(field_get:proto.auth.BasicResult.status)
  return static_cast< ::proto::auth::Status >(status_);
}
inline void BasicResult::set_status(::proto::auth::Status value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:proto.auth.BasicResult.status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace auth
}  // namespace proto

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::proto::auth::Method> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::proto::auth::SessionType> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::proto::auth::Status> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_auth_5fsession_2eproto__INCLUDED
