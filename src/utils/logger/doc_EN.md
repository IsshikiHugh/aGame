# `Logger` Introduction Document

The Logger class provides a range of functions that used to show different levels of messages on the terminal and in a log file.

There are 6 levels of the messages,in order of TRACE, DEBUG, WARN, INFO, ERROR and FATAL.

## Usage

0. Include `logger.h`
```cpp
#include "./utils/logger/logger.h"
```

1. Define a `Logger` object
```cpp
Logger logs;
```

2. Before using the functions, you need to initialize the object by using `init()` or `init(string filename)`. Using the second one can customize the name of log file, or the file name will be named as the current system time.
```cpp
logs.init();
//OR
logs.init("example.log");
```

3. When you want to output a message, use the function in the logger object and the message will be showed in the format of `[TYPE] Message`.
```cpp
logs.trace("A trace message.");
logs.debug("A debug message.");
logs.warn("A Warn message");
logs.info("An info message");
logs.error("An error message");
logs.fatal("A fatal message");
//OR
logs.fatal("A fatal message",-1);//customize the error code -1
```

    Mind that when calling `fatal()`, the function will force the program to exit with code 0 (if you didn't customize the error code) after showing the message.

4. Normally, the file output stream will be closed after writting to the file, but you still can use `close()` function to close the file stream manually.
```cpp
logs.close();
```