import sys
sys.path.insert(1, '../../build/')

from pysycl import device

# list of available sycl platforms
platforms = device.platform_list()
print("Available platforms: ")
print("---------------------")

for platform in platforms:
  print(platform)

print("")

# list of available sycl devices for a given platform
print("Available devices for platform: " + platforms[0])
print("-----------------------------------------------")
platform_devices = device.device_list(0)

for platform_device in platform_devices:
  print(platform_device)

print("")

# Create a device object
gpu_queue = device.device_object(0, 0)

# printing device information
print("Device information: ")
print("--------------------")
print("Device name: " + gpu_queue.device_name())
print("Device vendor: " + gpu_queue.device_vendor())
