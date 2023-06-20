-- WalnutExternal.lua

--VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
--IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"
IncludeDir["glm"] = "./Walnut/vendor/glm"

LibraryDir = {}
--LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Library = {}
--Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"

group "Dependencies"
   include "./Walnut/vendor/imgui"
   include "./Walnut/vendor/glfw"
   include "./Walnut/vendor/glad"
group ""

group "Core"
include "Walnut"
group ""