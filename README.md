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

You can customize the behavior of the logging library by defining the `DEBUG` preprocessor macro. If `DEBUG` is not defined, the `___debug` macro will not generate any output.

## Usage

Include the log.h header in your project.

Add the following line to your CMakeLists.txt file to enable debug logging:

```set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")```

Call one of the logging macros in your code (e.g. ___info<<"Hello, world!").

The message will be printed to the console with a timestamp and log level.

## Example

Here is an example usage of the logging library:
```cd example```  
```mkdir build && cd build```  
```cmake ..``` or  ```cmake -DCMAKE_BUILD_TYPE=Debug  ..```  
```make```  
```./myapp``` or  ```./myapp > output.log 2> error.log```  

```
#include "logger.h"

nt main()
{
    ___success<<"Program started :"<<16;
    for (int i = 0; i < 10; i++){
        ___info<<"Processing iteration "<<i;
        if (i == 5){
            ___warning<<"An issue occurred on iteration " <<i<<".";
        }
        if (i == 7){
            ___error<<"An error occurred on iteration "<<i<<".";
        }
        ___debug<<"Debug information for iteration "<<i<<".";
    }
    ___debug<<"ddddddddddddddddddddddddddddd";
    ___fatal<<"Program terminated abnormally.";
    return 0;
}
```

./myapp output:
```  
2023.03.27 20:25:48.742  SUCCESS Program started :16 /tmp/tmp/zlog/example/main.cpp main:7 
2023.03.27 20:25:48.742  INFO    Processing iteration 0 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 0. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 1 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 1. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 2 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 2. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 3 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 3. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 4 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 4. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 5 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  WARNING An issue occurred on iteration 5. /tmp/tmp/zlog/example/main.cpp main:11 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 5. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 6 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 6. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 7 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  ERROR   An error occurred on iteration 7. /tmp/tmp/zlog/example/main.cpp main:14 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 7. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 8 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 8. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  INFO    Processing iteration 9 /tmp/tmp/zlog/example/main.cpp main:9 
2023.03.27 20:25:48.742  DEBUG   Debug information for iteration 9. /tmp/tmp/zlog/example/main.cpp main:16 
2023.03.27 20:25:48.742  DEBUG   ddddddddddddddddddddddddddddd /tmp/tmp/zlog/example/main.cpp main:18 
2023.03.27 20:25:48.742  FATAL   Program terminated abnormally. /tmp/tmp/zlog/example/main.cpp main:19
```
