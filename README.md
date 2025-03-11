<p align="center">
  <img src="https://github.com/omni-drft/alg-lib/blob/main/Misc/AlgLib_nobg.png", style="width: 15vw" />
</p>

# AlgLib
### Template based header-only C++ library containing various data structures.
## How to use?
To use alglib you only need the header files (`.h`) from `Include/` directory. Use them just like normal header files. The compilation time of your project may increase. If you're worried about errors in version you're getting you can perform tests from [Tests](Tests/) directory. More about tests in [Tests](#tests) section.
## Manual
Precise API documentation can be found in [Docs](Docs/) folder in various formats. Easiest to use will probably be the [html](Docs/html) format.
## Tests
All tests are written using [Google Test](https://github.com/google/googletest). The easiest way to build those tests is to use included [premake5 script](premake5.lua). It links [Google Test](https://github.com/google/googletest) with tests source code and library headers creating executable that performs all the tests. 
### How to run tests:
* Install [premake5](https://premake.github.io/) or get the portable version you can run from anywhere.
* In command line run `premake5 vs2022`. If you use want to generate solution files for other platforms you can use any platform that is listed [here](https://premake.github.io/docs/Using-Premake).
* Use the created solution files to compile project.
* Run the executable (`alglib_test.exe`) that will be created in `Bin` directory.

You can also create your own build script using any build system that You like. As long as you link [dependencies](Dependencies/) and compile them everything will work correctly. 
## Dependencies
All dependencies are located in [Dependencies](Dependencies/) directory as submodules. Clone with `--recursive` to download them as well. Compilation is handled by included [premake5 script](premake5.lua).
* [Google Test](https://github.com/google/googletest).
## Known issues
Currently there are no known issues. If you find any - feel free to report them using git.
## Contributing
Feel free to open pull requests and suggest any changes. I will check every one of them.
