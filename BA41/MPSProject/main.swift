import Metal
import MetalPerformanceShaders

// 创建 Metal 设备
guard let device = MTLCreateSystemDefaultDevice() else {
    fatalError("Metal is not supported on this device.")
}

print("Metal Device: \(device.name)")

// 创建命令队列
let commandQueue = device.makeCommandQueue()

// 测试运行 Metal 功能
print("Command Queue Created Successfully!")
