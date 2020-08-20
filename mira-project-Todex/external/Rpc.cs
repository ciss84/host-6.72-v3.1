// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: external/rpc.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from external/rpc.proto</summary>
public static partial class RpcReflection {

  #region Descriptor
  /// <summary>File descriptor for external/rpc.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static RpcReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChJleHRlcm5hbC9ycGMucHJvdG8iagoJUnBjSGVhZGVyEg0KBW1hZ2ljGAEg",
          "ASgNEh4KCGNhdGVnb3J5GAIgASgOMgwuUnBjQ2F0ZWdvcnkSDAoEdHlwZRgD",
          "IAEoDRINCgVlcnJvchgEIAEoAxIRCglpc1JlcXVlc3QYBSABKAgiOAoMUnBj",
          "VHJhbnNwb3J0EhoKBmhlYWRlchgBIAEoCzIKLlJwY0hlYWRlchIMCgRkYXRh",
          "GAIgASgMKlcKC1JwY0NhdGVnb3J5EggKBE5PTkUQABIKCgZTWVNURU0QARIH",
          "CgNMT0cQAhIJCgVERUJVRxADEggKBEZJTEUQBBILCgdDT01NQU5EEAUSBwoD",
          "TUFYEAZiBnByb3RvMw=="));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { },
        new pbr::GeneratedClrTypeInfo(new[] {typeof(global::RpcCategory), }, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::RpcHeader), global::RpcHeader.Parser, new[]{ "Magic", "Category", "Type", "Error", "IsRequest" }, null, null, null),
          new pbr::GeneratedClrTypeInfo(typeof(global::RpcTransport), global::RpcTransport.Parser, new[]{ "Header", "Data" }, null, null, null)
        }));
  }
  #endregion

}
#region Enums
public enum RpcCategory {
  [pbr::OriginalName("NONE")] None = 0,
  [pbr::OriginalName("SYSTEM")] System = 1,
  [pbr::OriginalName("LOG")] Log = 2,
  [pbr::OriginalName("DEBUG")] Debug = 3,
  [pbr::OriginalName("FILE")] File = 4,
  [pbr::OriginalName("COMMAND")] Command = 5,
  [pbr::OriginalName("MAX")] Max = 6,
}

#endregion

#region Messages
public sealed partial class RpcHeader : pb::IMessage<RpcHeader> {
  private static readonly pb::MessageParser<RpcHeader> _parser = new pb::MessageParser<RpcHeader>(() => new RpcHeader());
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<RpcHeader> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::RpcReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcHeader() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcHeader(RpcHeader other) : this() {
    magic_ = other.magic_;
    category_ = other.category_;
    type_ = other.type_;
    error_ = other.error_;
    isRequest_ = other.isRequest_;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcHeader Clone() {
    return new RpcHeader(this);
  }

  /// <summary>Field number for the "magic" field.</summary>
  public const int MagicFieldNumber = 1;
  private uint magic_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public uint Magic {
    get { return magic_; }
    set {
      magic_ = value;
    }
  }

  /// <summary>Field number for the "category" field.</summary>
  public const int CategoryFieldNumber = 2;
  private global::RpcCategory category_ = 0;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public global::RpcCategory Category {
    get { return category_; }
    set {
      category_ = value;
    }
  }

  /// <summary>Field number for the "type" field.</summary>
  public const int TypeFieldNumber = 3;
  private uint type_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public uint Type {
    get { return type_; }
    set {
      type_ = value;
    }
  }

  /// <summary>Field number for the "error" field.</summary>
  public const int ErrorFieldNumber = 4;
  private long error_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public long Error {
    get { return error_; }
    set {
      error_ = value;
    }
  }

  /// <summary>Field number for the "isRequest" field.</summary>
  public const int IsRequestFieldNumber = 5;
  private bool isRequest_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool IsRequest {
    get { return isRequest_; }
    set {
      isRequest_ = value;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as RpcHeader);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(RpcHeader other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Magic != other.Magic) return false;
    if (Category != other.Category) return false;
    if (Type != other.Type) return false;
    if (Error != other.Error) return false;
    if (IsRequest != other.IsRequest) return false;
    return true;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Magic != 0) hash ^= Magic.GetHashCode();
    if (Category != 0) hash ^= Category.GetHashCode();
    if (Type != 0) hash ^= Type.GetHashCode();
    if (Error != 0L) hash ^= Error.GetHashCode();
    if (IsRequest != false) hash ^= IsRequest.GetHashCode();
    return hash;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override string ToString() {
    return pb::JsonFormatter.ToDiagnosticString(this);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void WriteTo(pb::CodedOutputStream output) {
    if (Magic != 0) {
      output.WriteRawTag(8);
      output.WriteUInt32(Magic);
    }
    if (Category != 0) {
      output.WriteRawTag(16);
      output.WriteEnum((int) Category);
    }
    if (Type != 0) {
      output.WriteRawTag(24);
      output.WriteUInt32(Type);
    }
    if (Error != 0L) {
      output.WriteRawTag(32);
      output.WriteInt64(Error);
    }
    if (IsRequest != false) {
      output.WriteRawTag(40);
      output.WriteBool(IsRequest);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (Magic != 0) {
      size += 1 + pb::CodedOutputStream.ComputeUInt32Size(Magic);
    }
    if (Category != 0) {
      size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) Category);
    }
    if (Type != 0) {
      size += 1 + pb::CodedOutputStream.ComputeUInt32Size(Type);
    }
    if (Error != 0L) {
      size += 1 + pb::CodedOutputStream.ComputeInt64Size(Error);
    }
    if (IsRequest != false) {
      size += 1 + 1;
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(RpcHeader other) {
    if (other == null) {
      return;
    }
    if (other.Magic != 0) {
      Magic = other.Magic;
    }
    if (other.Category != 0) {
      Category = other.Category;
    }
    if (other.Type != 0) {
      Type = other.Type;
    }
    if (other.Error != 0L) {
      Error = other.Error;
    }
    if (other.IsRequest != false) {
      IsRequest = other.IsRequest;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(pb::CodedInputStream input) {
    uint tag;
    while ((tag = input.ReadTag()) != 0) {
      switch(tag) {
        default:
          input.SkipLastField();
          break;
        case 8: {
          Magic = input.ReadUInt32();
          break;
        }
        case 16: {
          category_ = (global::RpcCategory) input.ReadEnum();
          break;
        }
        case 24: {
          Type = input.ReadUInt32();
          break;
        }
        case 32: {
          Error = input.ReadInt64();
          break;
        }
        case 40: {
          IsRequest = input.ReadBool();
          break;
        }
      }
    }
  }

}

public sealed partial class RpcTransport : pb::IMessage<RpcTransport> {
  private static readonly pb::MessageParser<RpcTransport> _parser = new pb::MessageParser<RpcTransport>(() => new RpcTransport());
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<RpcTransport> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::RpcReflection.Descriptor.MessageTypes[1]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcTransport() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcTransport(RpcTransport other) : this() {
    Header = other.header_ != null ? other.Header.Clone() : null;
    data_ = other.data_;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RpcTransport Clone() {
    return new RpcTransport(this);
  }

  /// <summary>Field number for the "header" field.</summary>
  public const int HeaderFieldNumber = 1;
  private global::RpcHeader header_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public global::RpcHeader Header {
    get { return header_; }
    set {
      header_ = value;
    }
  }

  /// <summary>Field number for the "data" field.</summary>
  public const int DataFieldNumber = 2;
  private pb::ByteString data_ = pb::ByteString.Empty;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public pb::ByteString Data {
    get { return data_; }
    set {
      data_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as RpcTransport);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(RpcTransport other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (!object.Equals(Header, other.Header)) return false;
    if (Data != other.Data) return false;
    return true;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (header_ != null) hash ^= Header.GetHashCode();
    if (Data.Length != 0) hash ^= Data.GetHashCode();
    return hash;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override string ToString() {
    return pb::JsonFormatter.ToDiagnosticString(this);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void WriteTo(pb::CodedOutputStream output) {
    if (header_ != null) {
      output.WriteRawTag(10);
      output.WriteMessage(Header);
    }
    if (Data.Length != 0) {
      output.WriteRawTag(18);
      output.WriteBytes(Data);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (header_ != null) {
      size += 1 + pb::CodedOutputStream.ComputeMessageSize(Header);
    }
    if (Data.Length != 0) {
      size += 1 + pb::CodedOutputStream.ComputeBytesSize(Data);
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(RpcTransport other) {
    if (other == null) {
      return;
    }
    if (other.header_ != null) {
      if (header_ == null) {
        header_ = new global::RpcHeader();
      }
      Header.MergeFrom(other.Header);
    }
    if (other.Data.Length != 0) {
      Data = other.Data;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(pb::CodedInputStream input) {
    uint tag;
    while ((tag = input.ReadTag()) != 0) {
      switch(tag) {
        default:
          input.SkipLastField();
          break;
        case 10: {
          if (header_ == null) {
            header_ = new global::RpcHeader();
          }
          input.ReadMessage(header_);
          break;
        }
        case 18: {
          Data = input.ReadBytes();
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code
