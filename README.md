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

```set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")```

Call one of the logging macros in your code (e.g. ___info("Hello, world!")).

The message will be printed to the console with a timestamp and log level.

## Example

Here is an example usage of the logging library:
```cd example```  
```mkdir build && cd build```  
```cmake``` or  ```cmake -DCMAKE_BUILD_TYPE=Debug  ..```  
```make```  
```./myapp``` or  ```./myapp > output.log 2> error.log```  

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

./myapp output:
2023.03.27 20:11:02.645  ERROR   An error occurred on iteration 7. /tmp/tmp/zlog/example/main.cpp main:14
2023.03.27 20:11:02.645  FATAL   Program terminated abnormally. /tmp/tmp/zlog/example/main.cpp main:19
2023.03.27 20:11:02.644  SUCCESS Program started :16 /tmp/tmp/zlog/example/main.cpp main:7
2023.03.27 20:11:02.644  INFO    Processing iteration 0 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.644  DEBUG   Debug information for iteration 0. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 1 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 1. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 2 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 2. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 3 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 3. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 4 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 4. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 5 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  WARNING An issue occurred on iteration 5. /tmp/tmp/zlog/example/main.cpp main:11
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 5. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 6 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 6. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 7 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  ERROR   An error occurred on iteration 7. /tmp/tmp/zlog/example/main.cpp main:14
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 7. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 8 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 8. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  INFO    Processing iteration 9 /tmp/tmp/zlog/example/main.cpp main:9
2023.03.27 20:11:02.645  DEBUG   Debug information for iteration 9. /tmp/tmp/zlog/example/main.cpp main:16
2023.03.27 20:11:02.645  DEBUG   ddddddddddddddddddddddddddddd /tmp/tmp/zlog/example/main.cpp main:18
2023.03.27 20:11:02.645  FATAL   Program terminated abnormally. /tmp/tmp/zlog/example/main.cpp main:19
