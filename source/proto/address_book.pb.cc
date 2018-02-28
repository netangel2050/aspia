// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: address_book.proto

#include "address_book.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace proto {
class ComputerGroupDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ComputerGroup>
      _instance;
} _ComputerGroup_default_instance_;
class AddressBookDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AddressBook>
      _instance;
} _AddressBook_default_instance_;
}  // namespace proto
namespace protobuf_address_5fbook_2eproto {
void InitDefaultsComputerGroupImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_computer_2eproto::InitDefaultsComputer();
  {
    void* ptr = &::proto::_ComputerGroup_default_instance_;
    new (ptr) ::proto::ComputerGroup();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::proto::ComputerGroup::InitAsDefaultInstance();
}

void InitDefaultsComputerGroup() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsComputerGroupImpl);
}

void InitDefaultsAddressBookImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::proto::_AddressBook_default_instance_;
    new (ptr) ::proto::AddressBook();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::proto::AddressBook::InitAsDefaultInstance();
}

void InitDefaultsAddressBook() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsAddressBookImpl);
}

}  // namespace protobuf_address_5fbook_2eproto
namespace proto {
bool AddressBook_EncryptionType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const AddressBook_EncryptionType AddressBook::ENCRYPTION_TYPE_UNKNOWN;
const AddressBook_EncryptionType AddressBook::ENCRYPTION_TYPE_NONE;
const AddressBook_EncryptionType AddressBook::ENCRYPTION_TYPE_XCHACHA20_POLY1305;
const AddressBook_EncryptionType AddressBook::EncryptionType_MIN;
const AddressBook_EncryptionType AddressBook::EncryptionType_MAX;
const int AddressBook::EncryptionType_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void ComputerGroup::InitAsDefaultInstance() {
}
void ComputerGroup::clear_computer() {
  computer_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ComputerGroup::kComputerFieldNumber;
const int ComputerGroup::kGroupFieldNumber;
const int ComputerGroup::kNameFieldNumber;
const int ComputerGroup::kCommentFieldNumber;
const int ComputerGroup::kExpandedFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ComputerGroup::ComputerGroup()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_address_5fbook_2eproto::InitDefaultsComputerGroup();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto.ComputerGroup)
}
ComputerGroup::ComputerGroup(const ComputerGroup& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      computer_(from.computer_),
      group_(from.group_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  comment_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.comment().size() > 0) {
    comment_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.comment_);
  }
  expanded_ = from.expanded_;
  // @@protoc_insertion_point(copy_constructor:proto.ComputerGroup)
}

void ComputerGroup::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  comment_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  expanded_ = false;
  _cached_size_ = 0;
}

ComputerGroup::~ComputerGroup() {
  // @@protoc_insertion_point(destructor:proto.ComputerGroup)
  SharedDtor();
}

void ComputerGroup::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  comment_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ComputerGroup::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ComputerGroup& ComputerGroup::default_instance() {
  ::protobuf_address_5fbook_2eproto::InitDefaultsComputerGroup();
  return *internal_default_instance();
}

ComputerGroup* ComputerGroup::New(::google::protobuf::Arena* arena) const {
  ComputerGroup* n = new ComputerGroup;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ComputerGroup::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.ComputerGroup)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  computer_.Clear();
  group_.Clear();
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  comment_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  expanded_ = false;
  _internal_metadata_.Clear();
}

bool ComputerGroup::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:proto.ComputerGroup)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto.Computer computer = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_computer()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .proto.ComputerGroup group = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_group()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string name = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "proto.ComputerGroup.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string comment = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_comment()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->comment().data(), static_cast<int>(this->comment().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "proto.ComputerGroup.comment"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool expanded = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &expanded_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto.ComputerGroup)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto.ComputerGroup)
  return false;
#undef DO_
}

void ComputerGroup::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto.ComputerGroup)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .proto.Computer computer = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->computer_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->computer(static_cast<int>(i)), output);
  }

  // repeated .proto.ComputerGroup group = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->group_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, this->group(static_cast<int>(i)), output);
  }

  // string name = 3;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "proto.ComputerGroup.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // string comment = 4;
  if (this->comment().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->comment().data(), static_cast<int>(this->comment().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "proto.ComputerGroup.comment");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->comment(), output);
  }

  // bool expanded = 5;
  if (this->expanded() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->expanded(), output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:proto.ComputerGroup)
}

size_t ComputerGroup::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.ComputerGroup)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  // repeated .proto.Computer computer = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->computer_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->computer(static_cast<int>(i)));
    }
  }

  // repeated .proto.ComputerGroup group = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->group_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->group(static_cast<int>(i)));
    }
  }

  // string name = 3;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // string comment = 4;
  if (this->comment().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->comment());
  }

  // bool expanded = 5;
  if (this->expanded() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ComputerGroup::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const ComputerGroup*>(&from));
}

void ComputerGroup::MergeFrom(const ComputerGroup& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto.ComputerGroup)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  computer_.MergeFrom(from.computer_);
  group_.MergeFrom(from.group_);
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.comment().size() > 0) {

    comment_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.comment_);
  }
  if (from.expanded() != 0) {
    set_expanded(from.expanded());
  }
}

void ComputerGroup::CopyFrom(const ComputerGroup& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.ComputerGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ComputerGroup::IsInitialized() const {
  return true;
}

void ComputerGroup::Swap(ComputerGroup* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ComputerGroup::InternalSwap(ComputerGroup* other) {
  using std::swap;
  computer_.InternalSwap(&other->computer_);
  group_.InternalSwap(&other->group_);
  name_.Swap(&other->name_);
  comment_.Swap(&other->comment_);
  swap(expanded_, other->expanded_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string ComputerGroup::GetTypeName() const {
  return "proto.ComputerGroup";
}


// ===================================================================

void AddressBook::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AddressBook::kEncryptionTypeFieldNumber;
const int AddressBook::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AddressBook::AddressBook()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_address_5fbook_2eproto::InitDefaultsAddressBook();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto.AddressBook)
}
AddressBook::AddressBook(const AddressBook& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.data().size() > 0) {
    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  encryption_type_ = from.encryption_type_;
  // @@protoc_insertion_point(copy_constructor:proto.AddressBook)
}

void AddressBook::SharedCtor() {
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  encryption_type_ = 0;
  _cached_size_ = 0;
}

AddressBook::~AddressBook() {
  // @@protoc_insertion_point(destructor:proto.AddressBook)
  SharedDtor();
}

void AddressBook::SharedDtor() {
  data_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void AddressBook::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const AddressBook& AddressBook::default_instance() {
  ::protobuf_address_5fbook_2eproto::InitDefaultsAddressBook();
  return *internal_default_instance();
}

AddressBook* AddressBook::New(::google::protobuf::Arena* arena) const {
  AddressBook* n = new AddressBook;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AddressBook::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.AddressBook)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  encryption_type_ = 0;
  _internal_metadata_.Clear();
}

bool AddressBook::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:proto.AddressBook)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .proto.AddressBook.EncryptionType encryption_type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_encryption_type(static_cast< ::proto::AddressBook_EncryptionType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes data = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto.AddressBook)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto.AddressBook)
  return false;
#undef DO_
}

void AddressBook::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto.AddressBook)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .proto.AddressBook.EncryptionType encryption_type = 1;
  if (this->encryption_type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->encryption_type(), output);
  }

  // bytes data = 2;
  if (this->data().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->data(), output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:proto.AddressBook)
}

size_t AddressBook::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.AddressBook)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  // bytes data = 2;
  if (this->data().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->data());
  }

  // .proto.AddressBook.EncryptionType encryption_type = 1;
  if (this->encryption_type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->encryption_type());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AddressBook::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const AddressBook*>(&from));
}

void AddressBook::MergeFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto.AddressBook)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.data().size() > 0) {

    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  if (from.encryption_type() != 0) {
    set_encryption_type(from.encryption_type());
  }
}

void AddressBook::CopyFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.AddressBook)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddressBook::IsInitialized() const {
  return true;
}

void AddressBook::Swap(AddressBook* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AddressBook::InternalSwap(AddressBook* other) {
  using std::swap;
  data_.Swap(&other->data_);
  swap(encryption_type_, other->encryption_type_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string AddressBook::GetTypeName() const {
  return "proto.AddressBook";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto

// @@protoc_insertion_point(global_scope)
