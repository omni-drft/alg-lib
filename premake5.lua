-- workspace specification
workspace "alg-lib"
    configurations {"Debug", "Release"}
    architecture "x86_64"

-- project specification
project "alglib_test"
    -- general properties
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Bin/%{cfg.buildcfg}"
    objdir "Obj/%{cfg.buildcfg}"

    -- warning level 
    warnings "Default" -- level 3 in MSVC
    
    -- file and library paths
    files {"Tests/**.cc", "Include/**.h"}
    includedirs {"Include/", "Dependencies/googletest/googletest/include"}
    links {"gtest", "gtest_main"}

    -- building the googletest library before alglib library
    prebuildcommands {
        "cmake -S Dependencies/googletest -B Dependencies/googletest/build",
        "cmake --build Dependencies/googletest/build --config %{cfg.buildcfg}"
    }

    -- Debug filter
    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        libdirs {"Dependencies/googletest/build/lib/Debug"}
    
    -- Release filter
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        libdirs {"Dependencies/googletest/build/lib/Release"}
