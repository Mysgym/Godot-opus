#!/usr/bin/env python
import os
import sys

gdcpppath = "godot-cpp"

for key, value in ARGLIST:
    if(key == 'godot-cpp-path'):
        gdcpppath=ARGUMENTS.get('godot-cpp-path')

env = SConscript(gdcpppath + "/SConstruct")
# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
env.Append(CCFLAGS=["-Iinc","-Ilib/inc"])
sources = Glob("src/*.cpp")


if env["platform"] != "linux":
    print("ERROR : This project only supports linux, yet.")
else:
    env.Append(CPPPATH=['/usr/include/opus'])
    env.Append(LIBPATH=['/usr/lib'])
    env.Append(LIBS=['libopus'])
    library = env.SharedLibrary(
        "addons/Godot-opus/libgodotopus{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
