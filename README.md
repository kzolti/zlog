zlog
====

The logging library provides a set of macros for logging messages with different levels of severity.
The library uses stderr for log levels  ERROR and FATAL and stdout for log levels INFO, SUCCESS, WARNING, and DEBUG.

## Log Levels

The available log levels, in increasing order of severity, are:

* SUCCESS
* INFO
* WARNING
* ERROR
* DEBUG
* FATAL

## Requirements

CMake (version 3.0 or higher)
C++ compiler (supporting C++11 standard)

## Customization

You can customize the behavior of the logging library by defining the `MY_DEBUG` preprocessor macro. If `MY_DEBUG` is not defined, the `___debug()` macro will not generate any output.

## Building

### To build the library, follow these steps:

* Clone the repository to your local machine.  
  &nbsp;&nbsp;&nbsp;&nbsp;```git clone git@github.com:kzolti/zlog.git```
* Create a build directory within the project directory and navigate to the build directory  
  &nbsp;&nbsp;&nbsp;&nbsp;```cd zlog && mkdir build && cd build```  
* Run cmake .. to generate build files and run make to build the library.  
  &nbsp;&nbsp;&nbsp;&nbsp;```cmake .. && make```  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  or  
  &nbsp;&nbsp;&nbsp;&nbsp;```cmake .. && cmake --build .```  
* Install lib and include  
  &nbsp;&nbsp;&nbsp;&nbsp;```sudo make install```  
  &nbsp;&nbsp;&nbsp;&nbsp; output:  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Install the project...  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-- Install configuration: ""  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-- Installing: /usr/local/lib/libzlog.a  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-- Installing: /usr/local/include/log.h  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-- Installing: /usr/local/include/logimpl.h  
* Uninstall lib and include  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```sudo make uninstall```  

## Usage

Include the log.h header in your project.

Add the following line to your CMakeLists.txt file to enable debug logging:

```set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG")```

Call one of the logging macros in your code (e.g. ___info("Hello, world!")).

The message will be printed to the console with a timestamp and log level.

## Example

Here is an example usage of the logging library:

```
#include "logger.h"

int main()
{
___success("Program started.");
for (int i = 0; i < 10; i++){
___info("Processing iteration %d.", i);
if (i == 5){
___warning("An issue occurred on iteration %d.", i);
}
if (i == 7){
___error("An error occurred on iteration %d.", i);
}
___debug("Debug information for iteration %d.", i);
}
___fatal("Program terminated abnormally.");
return 0;
}
```
