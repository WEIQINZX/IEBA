#include <metal_stdlib>
using namespace metal;

kernel void simple_shader(texture2d<float, access::read> inTexture [[texture(0)]],
                          texture2d<float, access::write> outTexture [[texture(1)]],
                          uint2 gid [[thread_position_in_grid]]) {
    // 获取像素颜色
    float4 color = inTexture.read(gid);
    // 输出颜色
    outTexture.write(color, gid);
}
