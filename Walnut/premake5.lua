-- premake5.lua
workspace "ParticleSystem"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "ParticleSystem"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "WalnutExternal.lua"
include "ParticleSystem"