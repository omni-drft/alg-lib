# AlgLib
### Template based header-only C++ library containing data structures and algorithms.
## How to use?
To use alglib you only need the header files (`.h`) from `Include/` directory. Include use them just like normal header files. The compilation time of your project will increase. If you're worried about errors of version you're getting you can perform tests from `Tests/` directory. More about tests in [Tests](#tests) section.
## Manual
Precise API documentation can be found in [Docs](Docs/) folder in various formats. Easiest to use will probably be the [html](Docs/html) format.
## Tests
All tests are written using [Google Test](https://github.com/google/googletest). The easiest way to build those tests is to use included [premake5 script](premake5.lua).
## Known issues
Right now library is still in very early version and no issues are known so far. If you find any problems feel free to use git to report them. 
## Contributing
Feel free to open pull requests and suggest any changes. I will check every one of them.
