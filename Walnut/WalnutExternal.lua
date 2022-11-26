-- WalnutExternal.lua

--VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
--IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"
IncludeDir["glm"] = "../vendor/glm"
IncludeDir["spdlog"] = "../vendor/spdlog"

LibraryDir = {}
--LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Library = {}
--Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"

group "Dependencies"
   include "vendor/imgui"
   include "vendor/glfw"
   include "vendor/Glad"
   
group ""

group "Core"
include "Walnut"
group ""
