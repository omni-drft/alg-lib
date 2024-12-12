workspace "alg-lib"
    configurations {"Debug", "Release"}
    architecture "x86_64"

project "alglib_test"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Bin/%{cfg.buildcfg}"
    objdir "Obj/%{cfg.buildcfg}"

    warnings "Default"
    
    files {"Tests/**.cc", "Include/**.h"}
    includedirs {"Include/"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
    
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

