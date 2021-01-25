#ifndef CC_CORE_GFX_DEF_H_
#define CC_CORE_GFX_DEF_H_

namespace cc {
namespace gfx {

class Device;
class Buffer;
class GlobalBarrier;
class TextureBarrier;
class Texture;
class Sampler;
class Shader;
class InputAssembler;
class RenderPass;
class Framebuffer;
class DescriptorSetLayout;
class PipelineLayout;
class PipelineState;
class DescriptorSet;
class CommandAllocator;
class CommandBuffer;
class Fence;
class Queue;
class Window;
class Context;

#define GFX_MAX_ATTACHMENTS 4
#define GFX_INVALID_BINDING ((uint8_t)-1)
#define GFX_INVALID_HANDLE  ((uint)-1)

enum class ObjectType {
    UNKNOWN,
    BUFFER,
    TEXTURE,
    RENDER_PASS,
    FRAMEBUFFER,
    SAMPLER,
    SHADER,
    DESCRIPTOR_SET_LAYOUT,
    PIPELINE_LAYOUT,
    PIPELINE_STATE,
    DESCRIPTOR_SET,
    INPUT_ASSEMBLER,
    COMMAND_BUFFER,
    QUEUE,
    GLOBAL_BARRIER,
    TEXTURE_BARRIER,
    BUFFER_BARRIER,
};

enum class Status {
    UNREADY,
    FAILED,
    SUCCESS,
};

enum class API {
    UNKNOWN,
    GLES2,
    GLES3,
    METAL,
    VULKAN,
    WEBGL,
    WEBGL2,
    WEBGPU,
};

enum class SurfaceTransform {
    IDENTITY,
    ROTATE_90,
    ROTATE_180,
    ROTATE_270,
};

enum class Feature {
    COLOR_FLOAT,
    COLOR_HALF_FLOAT,
    TEXTURE_FLOAT,
    TEXTURE_HALF_FLOAT,
    TEXTURE_FLOAT_LINEAR,
    TEXTURE_HALF_FLOAT_LINEAR,
    FORMAT_R11G11B10F,
    FORMAT_D16,
    FORMAT_D16S8,
    FORMAT_D24,
    FORMAT_D24S8,
    FORMAT_D32F,
    FORMAT_D32FS8,
    FORMAT_ETC1,
    FORMAT_ETC2,
    FORMAT_DXT,
    FORMAT_PVRTC,
    FORMAT_ASTC,
    FORMAT_RGB8,
    MSAA,
    ELEMENT_INDEX_UINT,
    INSTANCED_ARRAYS,
    MULTIPLE_RENDER_TARGETS,
    BLEND_MINMAX,
    DEPTH_BOUNDS,
    LINE_WIDTH,
    STENCIL_WRITE_MASK,
    STENCIL_COMPARE_MASK,
    MULTITHREADED_SUBMISSION,
    COMPUTE_SHADER,
    COUNT,
};

enum class Format {

    UNKNOWN,

    A8,
    L8,
    LA8,

    R8,
    R8SN,
    R8UI,
    R8I,
    R16F,
    R16UI,
    R16I,
    R32F,
    R32UI,
    R32I,

    RG8,
    RG8SN,
    RG8UI,
    RG8I,
    RG16F,
    RG16UI,
    RG16I,
    RG32F,
    RG32UI,
    RG32I,

    RGB8,
    SRGB8,
    RGB8SN,
    RGB8UI,
    RGB8I,
    RGB16F,
    RGB16UI,
    RGB16I,
    RGB32F,
    RGB32UI,
    RGB32I,

    RGBA8,
    BGRA8,
    SRGB8_A8,
    RGBA8SN,
    RGBA8UI,
    RGBA8I,
    RGBA16F,
    RGBA16UI,
    RGBA16I,
    RGBA32F,
    RGBA32UI,
    RGBA32I,

    // Special Format
    R5G6B5,
    R11G11B10F,
    RGB5A1,
    RGBA4,
    RGB10A2,
    RGB10A2UI,
    RGB9E5,

    // Depth-Stencil Format
    D16,
    D16S8,
    D24,
    D24S8,
    D32F,
    D32F_S8,

    // Compressed Format

    // Block Compression Format, DDS (DirectDraw Surface)
    // DXT1: 3 channels (5:6:5), 1/8 origianl size, with 0 or 1 bit of alpha
    BC1,
    BC1_ALPHA,
    BC1_SRGB,
    BC1_SRGB_ALPHA,
    // DXT3: 4 channels (5:6:5), 1/4 origianl size, with 4 bits of alpha
    BC2,
    BC2_SRGB,
    // DXT5: 4 channels (5:6:5), 1/4 origianl size, with 8 bits of alpha
    BC3,
    BC3_SRGB,
    // 1 channel (8), 1/4 origianl size
    BC4,
    BC4_SNORM,
    // 2 channels (8:8), 1/2 origianl size
    BC5,
    BC5_SNORM,
    // 3 channels (16:16:16), half-floating point, 1/6 origianl size
    // UF16: unsigned float, 5 exponent bits + 11 mantissa bits
    // SF16: signed float, 1 signed bit + 5 exponent bits + 10 mantissa bits
    BC6H_UF16,
    BC6H_SF16,
    // 4 channels (4~7 bits per channel) with 0 to 8 bits of alpha, 1/3 original size
    BC7,
    BC7_SRGB,

    // Ericsson Texture Compression Format
    ETC_RGB8,
    ETC2_RGB8,
    ETC2_SRGB8,
    ETC2_RGB8_A1,
    ETC2_SRGB8_A1,
    ETC2_RGBA8,
    ETC2_SRGB8_A8,
    EAC_R11,
    EAC_R11SN,
    EAC_RG11,
    EAC_RG11SN,

    // PVRTC (PowerVR)
    PVRTC_RGB2,
    PVRTC_RGBA2,
    PVRTC_RGB4,
    PVRTC_RGBA4,
    PVRTC2_2BPP,
    PVRTC2_4BPP,

    // ASTC (Adaptive Scalable Texture Compression)
    ASTC_RGBA_4x4,
    ASTC_RGBA_5x4,
    ASTC_RGBA_5x5,
    ASTC_RGBA_6x5,
    ASTC_RGBA_6x6,
    ASTC_RGBA_8x5,
    ASTC_RGBA_8x6,
    ASTC_RGBA_8x8,
    ASTC_RGBA_10x5,
    ASTC_RGBA_10x6,
    ASTC_RGBA_10x8,
    ASTC_RGBA_10x10,
    ASTC_RGBA_12x10,
    ASTC_RGBA_12x12,

    // ASTC (Adaptive Scalable Texture Compression) SRGB
    ASTC_SRGBA_4x4,
    ASTC_SRGBA_5x4,
    ASTC_SRGBA_5x5,
    ASTC_SRGBA_6x5,
    ASTC_SRGBA_6x6,
    ASTC_SRGBA_8x5,
    ASTC_SRGBA_8x6,
    ASTC_SRGBA_8x8,
    ASTC_SRGBA_10x5,
    ASTC_SRGBA_10x6,
    ASTC_SRGBA_10x8,
    ASTC_SRGBA_10x10,
    ASTC_SRGBA_12x10,
    ASTC_SRGBA_12x12,

    // Total count
    COUNT,
};

enum class FormatType {
    NONE,
    UNORM,
    SNORM,
    UINT,
    INT,
    UFLOAT,
    FLOAT,
};

enum class Type {
    UNKNOWN,
    BOOL,
    BOOL2,
    BOOL3,
    BOOL4,
    INT,
    INT2,
    INT3,
    INT4,
    UINT,
    UINT2,
    UINT3,
    UINT4,
    FLOAT,
    FLOAT2,
    FLOAT3,
    FLOAT4,
    MAT2,
    MAT2X3,
    MAT2X4,
    MAT3X2,
    MAT3,
    MAT3X4,
    MAT4X2,
    MAT4X3,
    MAT4,
    // combined image samplers
    SAMPLER1D,
    SAMPLER1D_ARRAY,
    SAMPLER2D,
    SAMPLER2D_ARRAY,
    SAMPLER3D,
    SAMPLER_CUBE,
    // sampler
    SAMPLER,
    // sampled textures
    TEXTURE1D,
    TEXTURE1D_ARRAY,
    TEXTURE2D,
    TEXTURE2D_ARRAY,
    TEXTURE3D,
    TEXTURE_CUBE,
    // storage images
    IMAGE1D,
    IMAGE1D_ARRAY,
    IMAGE2D,
    IMAGE2D_ARRAY,
    IMAGE3D,
    IMAGE_CUBE,
    // input attachment
    SUBPASS_INPUT,
    COUNT,
};
bool isCombinedImageSampler(Type type);
bool isSampledImage(Type type);
bool isStorageImage(Type type);

enum class BufferUsageBit : FlagBits {
    NONE         = 0,
    TRANSFER_SRC = 0x1,
    TRANSFER_DST = 0x2,
    INDEX        = 0x4,
    VERTEX       = 0x8,
    UNIFORM      = 0x10,
    STORAGE      = 0x20,
    INDIRECT     = 0x40,
};
typedef BufferUsageBit BufferUsage;
CC_ENUM_OPERATORS(BufferUsageBit);

enum class BufferFlagBit : FlagBits {
    NONE         = 0,
    BAKUP_BUFFER = 0x4,
};
typedef BufferFlagBit BufferFlags;
CC_ENUM_OPERATORS(BufferFlagBit);

enum class MemoryAccessBit : FlagBits {
    NONE       = 0,
    READ_ONLY  = 0x1,
    WRITE_ONLY = 0x2,
    READ_WRITE = READ_ONLY | WRITE_ONLY,
};
typedef MemoryAccessBit MemoryAccess;

enum class MemoryUsageBit : FlagBits {
    NONE   = 0,
    DEVICE = 0x1,
    HOST   = 0x2,
};
typedef MemoryUsageBit MemoryUsage;
CC_ENUM_OPERATORS(MemoryUsageBit);

enum class TextureType {
    TEX1D,
    TEX2D,
    TEX3D,
    CUBE,
    TEX1D_ARRAY,
    TEX2D_ARRAY,
};

enum class TextureUsageBit : FlagBits {
    NONE                     = 0,
    TRANSFER_SRC             = 0x1,
    TRANSFER_DST             = 0x2,
    SAMPLED                  = 0x4,
    STORAGE                  = 0x8,
    COLOR_ATTACHMENT         = 0x10,
    DEPTH_STENCIL_ATTACHMENT = 0x20,
    TRANSIENT_ATTACHMENT     = 0x40,
    INPUT_ATTACHMENT         = 0x80,
};
typedef TextureUsageBit TextureUsage;
CC_ENUM_OPERATORS(TextureUsageBit);

enum class TextureFlagBit : FlagBits {
    NONE         = 0,
    GEN_MIPMAP   = 0x1,
    BAKUP_BUFFER = 0x2,
    IMMUTABLE    = 0x4,
};
typedef TextureFlagBit TextureFlags;
CC_ENUM_OPERATORS(TextureFlagBit);

enum class SampleCount {
    X1,
    X2,
    X4,
    X8,
    X16,
    X32,
    X64,
};

enum class Filter {
    NONE,
    POINT,
    LINEAR,
    ANISOTROPIC,
};

enum class Address {
    WRAP,
    MIRROR,
    CLAMP,
    BORDER,
};

enum class ComparisonFunc {
    NEVER,
    LESS,
    EQUAL,
    LESS_EQUAL,
    GREATER,
    NOT_EQUAL,
    GREATER_EQUAL,
    ALWAYS,
};

enum class StencilOp {
    ZERO,
    KEEP,
    REPLACE,
    INCR,
    DECR,
    INVERT,
    INCR_WRAP,
    DECR_WRAP,
};

enum class BlendFactor {
    ZERO,
    ONE,
    SRC_ALPHA,
    DST_ALPHA,
    ONE_MINUS_SRC_ALPHA,
    ONE_MINUS_DST_ALPHA,
    SRC_COLOR,
    DST_COLOR,
    ONE_MINUS_SRC_COLOR,
    ONE_MINUS_DST_COLOR,
    SRC_ALPHA_SATURATE,
    CONSTANT_COLOR,
    ONE_MINUS_CONSTANT_COLOR,
    CONSTANT_ALPHA,
    ONE_MINUS_CONSTANT_ALPHA,
};

enum class BlendOp {
    ADD,
    SUB,
    REV_SUB,
    MIN,
    MAX,
};

enum class ColorMask : FlagBits {
    NONE = 0x0,
    R    = 0x1,
    G    = 0x2,
    B    = 0x4,
    A    = 0x8,
    ALL  = R | G | B | A,
};
CC_ENUM_OPERATORS(ColorMask);

enum class ShaderStageFlagBit : FlagBits {
    NONE       = 0x0,
    VERTEX     = 0x1,
    CONTROL    = 0x2,
    EVALUATION = 0x4,
    GEOMETRY   = 0x8,
    FRAGMENT   = 0x10,
    COMPUTE    = 0x20,
    ALL        = 0x3f,
};
typedef ShaderStageFlagBit ShaderStageFlags;
CC_ENUM_OPERATORS(ShaderStageFlagBit);

enum class LoadOp {
    LOAD,    // Load the contents from the fbo from previous
    CLEAR,   // Clear the fbo
    DISCARD, // Ignore writing to the fbo and keep old data
};

enum class StoreOp {
    STORE,   // Write the source to the destination
    DISCARD, // Don't write the source to the destination
};

enum class AccessType {
    NONE,

    // Read access
    INDIRECT_BUFFER,                                     // Read as an indirect buffer for drawing or dispatch
    INDEX_BUFFER,                                        // Read as an index buffer for drawing
    VERTEX_BUFFER,                                       // Read as a vertex buffer for drawing
    VERTEX_SHADER_READ_UNIFORM_BUFFER,                   // Read as a uniform buffer in a vertex shader
    VERTEX_SHADER_READ_TEXTURE,                          // Read as a sampled image/uniform texel buffer in a vertex shader
    VERTEX_SHADER_READ_OTHER,                            // Read as any other resource in a vertex shader
    FRAGMENT_SHADER_READ_UNIFORM_BUFFER,                 // Read as a uniform buffer in a fragment shader
    FRAGMENT_SHADER_READ_TEXTURE,                        // Read as a sampled image/uniform texel buffer in a fragment shader
    FRAGMENT_SHADER_READ_COLOR_INPUT_ATTACHMENT,         // Read as an input attachment with a color format in a fragment shader
    FRAGMENT_SHADER_READ_DEPTH_STENCIL_INPUT_ATTACHMENT, // Read as an input attachment with a depth/stencil format in a fragment shader
    FRAGMENT_SHADER_READ_OTHER,                          // Read as any other resource in a fragment shader
    COLOR_ATTACHMENT_READ,                               // Read by standard blending/logic operations or subpass load operations
    DEPTH_STENCIL_ATTACHMENT_READ,                       // Read by depth/stencil tests or subpass load operations
    COMPUTE_SHADER_READ_UNIFORM_BUFFER,                  // Read as a uniform buffer in a compute shader
    COMPUTE_SHADER_READ_TEXTURE,                         // Read as a sampled image/uniform texel buffer in a compute shader
    COMPUTE_SHADER_READ_OTHER,                           // Read as any other resource in a compute shader
    TRANSFER_READ,                                       // Read as the source of a transfer operation
    HOST_READ,                                           // Read on the host
    PRESENT,                                             // Read by the presentation engine

    // Write access
    VERTEX_SHADER_WRITE,            // Written as any resource in a vertex shader
    FRAGMENT_SHADER_WRITE,          // Written as any resource in a fragment shader
    COLOR_ATTACHMENT_WRITE,         // Written as a color attachment during rendering, or via a subpass store op
    DEPTH_STENCIL_ATTACHMENT_WRITE, // Written as a depth/stencil attachment during rendering, or via a subpass store op
    COMPUTE_SHADER_WRITE,           // Written as any resource in a compute shader
    TRANSFER_WRITE,                 // Written as the destination of a transfer operation
    HOST_PREINITIALIZED,            // Data pre-filled by host before device access starts
    HOST_WRITE,                     // Written on the host
};

namespace AccessTypeV {
extern const AccessType INDIRECT_BUFFER;
extern const AccessType INDEX_BUFFER;
extern const AccessType VERTEX_BUFFER;
extern const AccessType VERTEX_SHADER_READ_UNIFORM_BUFFER;
extern const AccessType VERTEX_SHADER_READ_TEXTURE;
extern const AccessType VERTEX_SHADER_READ_OTHER;
extern const AccessType FRAGMENT_SHADER_READ_UNIFORM_BUFFER;
extern const AccessType FRAGMENT_SHADER_READ_TEXTURE;
extern const AccessType FRAGMENT_SHADER_READ_COLOR_INPUT_ATTACHMENT;
extern const AccessType FRAGMENT_SHADER_READ_DEPTH_STENCIL_INPUT_ATTACHMENT;
extern const AccessType FRAGMENT_SHADER_READ_OTHER;
extern const AccessType COLOR_ATTACHMENT_READ;
extern const AccessType DEPTH_STENCIL_ATTACHMENT_READ;
extern const AccessType COMPUTE_SHADER_READ_UNIFORM_BUFFER;
extern const AccessType COMPUTE_SHADER_READ_TEXTURE;
extern const AccessType COMPUTE_SHADER_READ_OTHER;
extern const AccessType TRANSFER_READ;
extern const AccessType HOST_READ;
extern const AccessType PRESENT;
extern const AccessType VERTEX_SHADER_WRITE;
extern const AccessType FRAGMENT_SHADER_WRITE;
extern const AccessType COLOR_ATTACHMENT_WRITE;
extern const AccessType DEPTH_STENCIL_ATTACHMENT_WRITE;
extern const AccessType COMPUTE_SHADER_WRITE;
extern const AccessType TRANSFER_WRITE;
extern const AccessType HOST_PREINITIALIZED;
extern const AccessType HOST_WRITE;
} // namespace AccessTypeV

typedef cc::vector<AccessType> AccessTypeList;

enum class PipelineBindPoint {
    GRAPHICS,
    COMPUTE,
    RAY_TRACING,
};

enum class PrimitiveMode {
    POINT_LIST,
    LINE_LIST,
    LINE_STRIP,
    LINE_LOOP,
    LINE_LIST_ADJACENCY,
    LINE_STRIP_ADJACENCY,
    ISO_LINE_LIST,
    // raycast detectable:
    TRIANGLE_LIST,
    TRIANGLE_STRIP,
    TRIANGLE_FAN,
    TRIANGLE_LIST_ADJACENCY,
    TRIANGLE_STRIP_ADJACENCY,
    TRIANGLE_PATCH_ADJACENCY,
    QUAD_PATCH_LIST,
};

enum class PolygonMode {
    FILL,
    POINT,
    LINE,
};

enum class ShadeModel {
    GOURAND,
    FLAT,
};

enum class CullMode {
    NONE,
    FRONT,
    BACK,
};

enum class DynamicStateFlagBit : FlagBits {
    NONE                 = 0x0,
    VIEWPORT             = 0x1,
    SCISSOR              = 0x2,
    LINE_WIDTH           = 0x4,
    DEPTH_BIAS           = 0x8,
    BLEND_CONSTANTS      = 0x10,
    DEPTH_BOUNDS         = 0x20,
    STENCIL_WRITE_MASK   = 0x40,
    STENCIL_COMPARE_MASK = 0x80,
};
typedef DynamicStateFlagBit DynamicStateFlags;
CC_ENUM_OPERATORS(DynamicStateFlagBit);

typedef cc::vector<DynamicStateFlagBit> DynamicStateList;

enum class StencilFace {
    FRONT,
    BACK,
    ALL,
};

enum class DescriptorType : FlagBits {
    UNKNOWN                = 0,
    UNIFORM_BUFFER         = 0x1,
    DYNAMIC_UNIFORM_BUFFER = 0x2,
    STORAGE_BUFFER         = 0x4,
    DYNAMIC_STORAGE_BUFFER = 0x8,
    SAMPLER_TEXTURE        = 0x10,
    SAMPLER                = 0x20,
    TEXTURE                = 0x40,
    STORAGE_IMAGE          = 0x80,
    INPUT_ATTACHMENT       = 0x100,
};
CC_ENUM_OPERATORS(DescriptorType);

enum class QueueType {
    GRAPHICS,
    COMPUTE,
    TRANSFER,
};

enum class CommandBufferType {
    PRIMARY,
    SECONDARY,
};

enum class ClearFlagBit : FlagBits {
    NONE          = 0,
    COLOR         = 0x1,
    DEPTH         = 0x2,
    STENCIL       = 0x4,
    DEPTH_STENCIL = DEPTH | STENCIL,
    ALL           = COLOR | DEPTH | STENCIL,
};
typedef ClearFlagBit ClearFlags;
CC_ENUM_OPERATORS(ClearFlagBit);

enum class VsyncMode {
    // The application does not synchronizes with the vertical sync.
    // If application renders faster than the display refreshes, frames are wasted and tearing may be observed.
    // FPS is uncapped. Maximum power consumption. If unsupported, "ON" value will be used instead. Minimum latency.
    OFF,
    // The application is always synchronized with the vertical sync. Tearing does not happen.
    // FPS is capped to the display's refresh rate. For fast applications, battery life is improved. Always supported.
    ON,
    // The application synchronizes with the vertical sync, but only if the application rendering speed is greater than refresh rate.
    // Compared to OFF, there is no tearing. Compared to ON, the FPS will be improved for "slower" applications.
    // If unsupported, "ON" value will be used instead. Recommended for most applications. Default if supported.
    RELAXED,
    // The presentation engine will always use the latest fully rendered image.
    // Compared to OFF, no tearing will be observed.
    // Compared to ON, battery power will be worse, especially for faster applications.
    // If unsupported,  "OFF" will be attempted next.
    MAILBOX,
    // The application is capped to using half the vertical sync time.
    // FPS artificially capped to Half the display speed (usually 30fps) to maintain battery.
    // Best possible battery savings. Worst possible performance.
    // Recommended for specific applications where battery saving is critical.
    HALF,
};

struct Size {
    uint x = 0u;
    uint y = 0u;
    uint z = 0u;
};

struct DeviceCaps {
    uint  maxVertexAttributes            = 0u;
    uint  maxVertexUniformVectors        = 0u;
    uint  maxFragmentUniformVectors      = 0u;
    uint  maxTextureUnits                = 0u;
    uint  maxImageUnits                  = 0u;
    uint  maxVertexTextureUnits          = 0u;
    uint  maxColorRenderTargets          = 0u;
    uint  maxShaderStorageBufferBindings = 0u;
    uint  maxShaderStorageBlockSize      = 0u;
    uint  maxUniformBufferBindings       = 0u;
    uint  maxUniformBlockSize            = 0u;
    uint  maxTextureSize                 = 0u;
    uint  maxCubeMapTextureSize          = 0u;
    uint  uboOffsetAlignment             = 0u;
    uint  depthBits                      = 0u;
    uint  stencilBits                    = 0u;
    uint  maxComputeSharedMemorySize     = 0u;
    uint  maxComputeWorkGroupInvocations = 0u;
    Size  maxComputeWorkGroupSize;
    Size  maxComputeWorkGroupCount;
    float clipSpaceMinZ    = -1.0f;
    float screenSpaceSignY = 1.0f;
    float UVSpaceSignY     = -1.0f;
};

struct Offset {
    int x = 0;
    int y = 0;
    int z = 0;
};

struct Rect {
    int  x      = 0;
    int  y      = 0;
    uint width  = 1u;
    uint height = 1u;

    bool operator==(const Rect &rs) {
        if (x == rs.x &&
            y == rs.y &&
            width == rs.width &&
            height == rs.height) {
            return true;
        } else
            return false;
    }

    bool operator!=(const Rect &rs) {
        return !(*this == rs);
    }
};

struct Extent {
    uint width  = 0;
    uint height = 0;
    uint depth  = 1;
};

struct TextureSubresLayers {
    uint mipLevel       = 0u;
    uint baseArrayLayer = 0u;
    uint layerCount     = 1u;
};

struct TextureSubresRange {
    uint baseMipLevel   = 0u;
    uint levelCount     = 1u;
    uint baseArrayLayer = 0u;
    uint layerCount     = 1u;
};

struct TextureCopy {
    TextureSubresLayers srcSubres;
    Offset              srcOffset;
    TextureSubresLayers dstSubres;
    Offset              dstOffset;
    Extent              extent;
};

struct TextureBlit {
    TextureSubresLayers srcSubres;
    Offset              srcOffset;
    Extent              srcExtent;
    TextureSubresLayers dstSubres;
    Offset              dstOffset;
    Extent              dstExtent;
};
typedef cc::vector<TextureBlit> TextureBlitList;

struct BufferTextureCopy {
    uint                buffStride    = 0;
    uint                buffTexHeight = 0;
    Offset              texOffset;
    Extent              texExtent;
    TextureSubresLayers texSubres;
};
typedef cc::vector<BufferTextureCopy> BufferTextureCopyList;
typedef cc::vector<const uint8_t *>   BufferDataList;

struct Viewport {
    int   left     = 0;
    int   top      = 0;
    uint  width    = 0;
    uint  height   = 0;
    float minDepth = 0.0f;
    float maxDepth = 1.0f;

    bool operator==(const Viewport &rs) {
        return (left == rs.left &&
                top == rs.top &&
                width == rs.width &&
                height == rs.height &&
                math::IsEqualF(minDepth, rs.minDepth) &&
                math::IsEqualF(maxDepth, maxDepth));
    }

    bool operator!=(const Viewport &rs) {
        return !(*this == rs);
    }
};

struct Color {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    bool operator==(const Color &rhs) {
        return (math::IsEqualF(x, rhs.x) &&
                math::IsEqualF(y, rhs.y) &&
                math::IsEqualF(z, rhs.z) &&
                math::IsEqualF(w, rhs.w));
    }
};
typedef cc::vector<Color> ColorList;

/**
 * For non-vulkan backends, to maintain compatibility and maximize
 * descriptor cache-locality, descriptor-set-based binding numbers need
 * to be mapped to backend-specific bindings based on maximum limit
 * of available descriptor slots in each set.
 *
 * The GFX layer assumes the binding numbers for each descriptor type inside each set
 * are guaranteed to be consecutive, so the mapping procedure is reduced
 * to a simple shifting operation. This data structure specifies the
 * offsets for each descriptor type in each set.
 */
struct BindingMappingInfo {
    cc::vector<int> bufferOffsets;
    cc::vector<int> samplerOffsets;
    uint            flexibleSet = 0u;
};

struct DeviceInfo {
    uintptr_t          windowHandle = 0;
    uint               width        = 0;
    uint               height       = 0;
    uint               nativeWidth  = 0;
    uint               nativeHeight = 0;
    Context *          sharedCtx    = nullptr;
    BindingMappingInfo bindingMappingInfo;
};

struct WindowInfo {
    String      title;
    int         left            = 0;
    int         top             = 0;
    uint        width           = 800;
    uint        height          = 600;
    Format      colorFmt        = Format::UNKNOWN;
    Format      depthStencilFmt = Format::UNKNOWN;
    bool        isOffscreen     = false;
    bool        isFullscreen    = false;
    VsyncMode   vsyncMode       = VsyncMode::OFF;
    uintptr_t   windowHandle    = 0;
    RenderPass *renderPass      = nullptr;
};

struct ContextInfo {
    uintptr_t windowHandle = 0;
    Context * sharedCtx    = nullptr;
    VsyncMode vsyncMode    = VsyncMode::RELAXED;
};

struct BufferInfo {
    BufferUsage usage    = BufferUsage::NONE;
    MemoryUsage memUsage = MemoryUsage::NONE;
    uint        size     = 0;
    uint        stride   = 0; // in bytes
    BufferFlags flags    = BufferFlagBit::NONE;
};

struct BufferViewInfo {
    Buffer *buffer = nullptr;
    uint    offset = 0u;
    uint    range  = 0u;
};

struct DrawInfo {
    uint vertexCount   = 0;
    uint firstVertex   = 0;
    uint indexCount    = 0;
    uint firstIndex    = 0;
    uint vertexOffset  = 0;
    uint instanceCount = 0;
    uint firstInstance = 0;
};

typedef cc::vector<DrawInfo> DrawInfoList;

struct DispatchInfo {
    uint groupCountX = 0;
    uint groupCountY = 0;
    uint groupCountZ = 0;

    Buffer *indirectBuffer = nullptr;
    uint    indirectOffset = 0;
};

typedef cc::vector<DispatchInfo> DispatchInfoList;

struct IndirectBuffer {
    DrawInfoList drawInfos;
};

struct TextureInfo {
    TextureType  type       = TextureType::TEX2D;
    TextureUsage usage      = TextureUsageBit::NONE;
    Format       format     = Format::UNKNOWN;
    uint         width      = 0u;
    uint         height     = 0u;
    TextureFlags flags      = TextureFlagBit::NONE;
    uint         layerCount = 1u;
    uint         levelCount = 1u;
    SampleCount  samples    = SampleCount::X1;
    uint         depth      = 1u;
};

struct TextureViewInfo {
    Texture *   texture    = nullptr;
    TextureType type       = TextureType::TEX2D;
    Format      format     = Format::UNKNOWN;
    uint        baseLevel  = 0u;
    uint        levelCount = 1u;
    uint        baseLayer  = 0u;
    uint        layerCount = 1u;
};

struct SamplerInfo {
    Filter         minFilter     = Filter::LINEAR;
    Filter         magFilter     = Filter::LINEAR;
    Filter         mipFilter     = Filter::NONE;
    Address        addressU      = Address::WRAP;
    Address        addressV      = Address::WRAP;
    Address        addressW      = Address::WRAP;
    uint           maxAnisotropy = 16;
    ComparisonFunc cmpFunc       = ComparisonFunc::NEVER;
    Color          borderColor;
    uint           minLOD     = 0;
    uint           maxLOD     = 1000;
    float          mipLODBias = 0.0f;
};

struct ShaderMacro {
    String macro;
    String value;
};

typedef cc::vector<ShaderMacro> ShaderMacroList;

struct Uniform {
    String name;
    Type   type  = Type::UNKNOWN;
    uint   count = 0u;
};

typedef cc::vector<Uniform> UniformList;

struct UniformBlock {
    uint        set     = 0u;
    uint        binding = 0u;
    String      name;
    UniformList members;
    uint        count = 0u;
};

typedef cc::vector<UniformBlock> UniformBlockList;

struct UniformSamplerTexture {
    uint   set     = 0u;
    uint   binding = 0u;
    String name;
    Type   type  = Type::UNKNOWN;
    uint   count = 0u;
};

typedef cc::vector<UniformSamplerTexture> UniformSamplerTextureList;

struct UniformSampler {
    uint   set     = 0u;
    uint   binding = 0u;
    String name;
    uint   count = 0u;
};

typedef cc::vector<UniformSampler> UniformSamplerList;

struct UniformTexture {
    uint   set     = 0u;
    uint   binding = 0u;
    String name;
    Type   type  = Type::UNKNOWN;
    uint   count = 0u;
};

typedef cc::vector<UniformTexture> UniformTextureList;

struct UniformStorageImage {
    uint         set     = 0u;
    uint         binding = 0u;
    String       name;
    Type         type         = Type::UNKNOWN;
    uint         count        = 0u;
    MemoryAccess memoryAccess = MemoryAccess::READ_WRITE;
};

typedef cc::vector<UniformStorageImage> UniformStorageImageList;

struct UniformStorageBuffer {
    uint         set     = 0u;
    uint         binding = 0u;
    String       name;
    uint         count        = 0u;
    MemoryAccess memoryAccess = MemoryAccess::READ_WRITE;
};

typedef cc::vector<UniformStorageBuffer> UniformStorageBufferList;

struct UniformInputAttachment {
    uint   set     = 0u;
    uint   binding = 0u;
    String name;
    uint   count = 0u;
};

typedef cc::vector<UniformInputAttachment> UniformInputAttachmentList;

struct ShaderStage {
    ShaderStageFlagBit stage = ShaderStageFlagBit::NONE;
    String             source;
};

typedef cc::vector<ShaderStage> ShaderStageList;

struct Attribute {
    String name;
    Format format       = Format::UNKNOWN;
    bool   isNormalized = false;
    uint   stream       = 0;
    bool   isInstanced  = false;
    uint   location     = 0;
};

typedef cc::vector<Attribute> AttributeList;

struct ShaderInfo {
    String                     name;
    ShaderStageList            stages;
    AttributeList              attributes;
    UniformBlockList           blocks;
    UniformStorageBufferList   buffers;
    UniformSamplerTextureList  samplerTextures;
    UniformSamplerList         samplers;
    UniformTextureList         textures;
    UniformStorageImageList    images;
    UniformInputAttachmentList subpassInputs;
};

typedef cc::vector<Buffer *> BufferList;
typedef cc::vector<TextureBarrier *> TextureBarrierList;

struct InputAssemblerInfo {
    AttributeList attributes;
    BufferList    vertexBuffers;
    Buffer *      indexBuffer    = nullptr;
    Buffer *      indirectBuffer = nullptr;
};

struct ColorAttachment {
    Format      format      = Format::UNKNOWN;
    SampleCount sampleCount = SampleCount::X1;
    LoadOp      loadOp      = LoadOp::CLEAR;
    StoreOp     storeOp     = StoreOp::STORE;
    AccessType  beginAccess = AccessType::NONE;
    AccessType  endAccess   = AccessType::PRESENT;
};

typedef cc::vector<ColorAttachment> ColorAttachmentList;

struct DepthStencilAttachment {
    Format      format         = Format::UNKNOWN;
    SampleCount sampleCount    = SampleCount::X1;
    LoadOp      depthLoadOp    = LoadOp::CLEAR;
    StoreOp     depthStoreOp   = StoreOp::STORE;
    LoadOp      stencilLoadOp  = LoadOp::CLEAR;
    StoreOp     stencilStoreOp = StoreOp::STORE;
    AccessType  beginAccess    = AccessType::NONE;
    AccessType  endAccess      = AccessType::DEPTH_STENCIL_ATTACHMENT_WRITE;
};

struct SubPassInfo {
    cc::vector<uint8_t> inputs;
    cc::vector<uint8_t> colors;
    cc::vector<uint8_t> resolves;
    uint8_t             depthStencil = GFX_INVALID_BINDING;
    cc::vector<uint8_t> preserves;
};

typedef cc::vector<SubPassInfo> SubPassInfoList;

struct RenderPassInfo {
    ColorAttachmentList    colorAttachments;
    DepthStencilAttachment depthStencilAttachment;
    SubPassInfoList        subPasses;
};

struct GlobalBarrierInfo {
    vector<AccessType> prevAccesses;
    vector<AccessType> nextAccesses;
};
typedef cc::vector<GlobalBarrierInfo> GlobalBarrierInfoList;

struct TextureBarrierInfo {
    vector<AccessType> prevAccesses;
    vector<AccessType> nextAccesses;

    bool     discardContents = false;

    Queue *srcQueue = nullptr;
    Queue *dstQueue = nullptr;
};
typedef cc::vector<TextureBarrierInfo> TextureBarrierInfoList;

typedef cc::vector<Buffer *>  BufferList;
typedef cc::vector<Texture *> TextureList;
typedef cc::vector<Sampler *> SamplerList;

struct FramebufferInfo {
    RenderPass *     renderPass = nullptr;
    TextureList      colorTextures;
    Texture *        depthStencilTexture = nullptr;
    cc::vector<uint> colorMipmapLevels;
    uint             depthStencilMipmapLevel = 0;
};

struct DescriptorSetLayoutBinding {
    uint             binding        = GFX_INVALID_BINDING;
    DescriptorType   descriptorType = DescriptorType::UNKNOWN;
    uint             count          = 0;
    ShaderStageFlags stageFlags     = ShaderStageFlagBit::NONE;
    SamplerList      immutableSamplers;
};
typedef cc::vector<DescriptorSetLayoutBinding> DescriptorSetLayoutBindingList;

struct DescriptorSetLayoutInfo {
    DescriptorSetLayoutBindingList bindings;
};

struct DescriptorSetInfo {
    DescriptorSetLayout *layout = nullptr;
};

typedef cc::vector<DescriptorSetLayout *> DescriptorSetLayoutList;

struct PipelineLayoutInfo {
    DescriptorSetLayoutList setLayouts;
};

struct InputState {
    AttributeList attributes;
};

// Use uint32_t for all boolean values to convert memory to RasterizerState* in shared memory.
struct RasterizerState {
    uint32_t    isDiscard        = 0;
    PolygonMode polygonMode      = PolygonMode::FILL;
    ShadeModel  shadeModel       = ShadeModel::GOURAND;
    CullMode    cullMode         = CullMode::BACK;
    uint32_t    isFrontFaceCCW   = 1;
    uint32_t    depthBiasEnabled = 0;
    float       depthBias        = 0.0f;
    float       depthBiasClamp   = 0.0f;
    float       depthBiasSlop    = 0.0f;
    uint32_t    isDepthClip      = 1;
    uint32_t    isMultisample    = 0;
    float       lineWidth        = 1.0f;
};

// Use uint32_t for all boolean values to convert memory to DepthStencilState* in shared memory.
struct DepthStencilState {
    uint32_t       depthTest             = 1;
    uint32_t       depthWrite            = 1;
    ComparisonFunc depthFunc             = ComparisonFunc::LESS;
    uint32_t       stencilTestFront      = 0;
    ComparisonFunc stencilFuncFront      = ComparisonFunc::ALWAYS;
    uint32_t       stencilReadMaskFront  = 0xffffffff;
    uint32_t       stencilWriteMaskFront = 0xffffffff;
    StencilOp      stencilFailOpFront    = StencilOp::KEEP;
    StencilOp      stencilZFailOpFront   = StencilOp::KEEP;
    StencilOp      stencilPassOpFront    = StencilOp::KEEP;
    uint32_t       stencilRefFront       = 1;
    uint32_t       stencilTestBack       = 0;
    ComparisonFunc stencilFuncBack       = ComparisonFunc::ALWAYS;
    uint32_t       stencilReadMaskBack   = 0xffffffff;
    uint32_t       stencilWriteMaskBack  = 0xffffffff;
    StencilOp      stencilFailOpBack     = StencilOp::KEEP;
    StencilOp      stencilZFailOpBack    = StencilOp::KEEP;
    StencilOp      stencilPassOpBack     = StencilOp::KEEP;
    uint32_t       stencilRefBack        = 1;
};

// Use uint32_t for all boolean values to do convert memory to BlendTarget* in shared memory.
struct BlendTarget {
    uint32_t    blend          = 0;
    BlendFactor blendSrc       = BlendFactor::ONE;
    BlendFactor blendDst       = BlendFactor::ZERO;
    BlendOp     blendEq        = BlendOp::ADD;
    BlendFactor blendSrcAlpha  = BlendFactor::ONE;
    BlendFactor blendDstAlpha  = BlendFactor::ZERO;
    BlendOp     blendAlphaEq   = BlendOp::ADD;
    ColorMask   blendColorMask = ColorMask::ALL;
};

typedef cc::vector<BlendTarget> BlendTargetList;

// Use uint32_t for all boolean values to do memeory copy in shared memory.
struct BlendState {
    uint32_t        isA2C      = 0;
    uint32_t        isIndepend = 0;
    Color           blendColor;
    BlendTargetList targets{1};
};

struct PipelineStateInfo {
    Shader *          shader         = nullptr;
    PipelineLayout *  pipelineLayout = nullptr;
    RenderPass *      renderPass     = nullptr;
    InputState        inputState;
    RasterizerState   rasterizerState;
    DepthStencilState depthStencilState;
    BlendState        blendState;
    PrimitiveMode     primitive     = PrimitiveMode::TRIANGLE_LIST;
    DynamicStateFlags dynamicStates = DynamicStateFlagBit::NONE;
    PipelineBindPoint bindPoint     = PipelineBindPoint::GRAPHICS;
};

struct CommandBufferInfo {
    Queue *           queue = nullptr;
    CommandBufferType type  = CommandBufferType::PRIMARY;
};
typedef cc::vector<CommandBuffer *> CommandBufferList;

struct QueueInfo {
    QueueType type = QueueType::GRAPHICS;
};

struct FenceInfo {
};

struct FormatInfo {
    String     name;
    uint       size         = 0;
    uint       count        = 0;
    FormatType type         = FormatType::NONE;
    bool       hasAlpha     = false;
    bool       hasDepth     = false;
    bool       hasStencil   = false;
    bool       isCompressed = false;
};

extern const DescriptorType DESCRIPTOR_BUFFER_TYPE;
extern const DescriptorType DESCRIPTOR_TEXTURE_TYPE;
extern const DescriptorType DESCRIPTOR_DYNAMIC_TYPE;

extern const FormatInfo GFX_FORMAT_INFOS[];
extern const uint       GFX_TYPE_SIZES[];

struct MemoryStatus {
    uint bufferSize  = 0;
    uint textureSize = 0;
};

extern uint FormatSize(Format format, uint width, uint height, uint depth);

extern uint FormatSurfaceSize(Format format, uint width, uint height, uint depth, uint mips);

} // namespace gfx
} // namespace cc

#endif // CC_CORE_GFX_DEF_H_
