# `Logger` 介绍文档

Logger类提供了一系列功能，用于在终端上及log文件中显示不同级别的提示信息。

提示信息共分为 6 个级别，依次为TRACE、DEBUG、WARN、INFO、ERROR和FATAL。

## 使用方法

0. 包含 `logger.h` 头文件
```cpp
#include "./utils/logger/logger.h"
```

1. 定义一个 `Logger` 对象
```cpp
Logger logs;
```

2. 在使用相关功能前，需先调用 `init()` 或 `init(string filename)` 将此对象初始化。其中第二种方式可自定义输出的log文件名称，而第一种默认以当前日期及时间作为文件名
```cpp
logs.init();
//或是
logs.init("example.log");
```

3. 在你想要输出提示信息的地方调用 `Logger` 对象的相应函数，消息会以 `[TYPE] Message` 的格式显示
```cpp
logs.trace("A trace message.");
logs.debug("A debug message.");
logs.warn("A Warn message");
logs.info("An info message");
logs.error("An error message");
logs.fatal("A fatal message");
//或是
logs.fatal("A fatal message",-1);//自定义错误码-1
```

    注意，`fatal()`函数在显示信息后会强制结束程序，若不自定义错误码则默认返回值 0

4. 一般情况下，在写入文件后文件输出流会自动关闭，但您仍可使用 `close()` 函数主动关闭文件流
```cpp
logs.close();
```