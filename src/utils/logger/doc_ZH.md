# `Logger` 介绍文档

Logger类提供了一系列功能，用于在终端上及log文件中显示不同级别的提示信息。

提示信息共分为 6 个级别，依次为TRACE、DEBUG、WARN、INFO、ERROR和FATAL。

## 使用方法

0. 包含 logger.h 头文件
```cpp
#include "./utils/logger/logger.h"
```

1. 定义一个 Logger 对象
```cpp
Logger log;
```

2. 在使用相关功能前，先将此对象初始化，可自定义输出的log文件名称，空则默认为以当前日期及时间作文文件名
```cpp
log.init();
//OR
log.init("example.log");
```

3. 在你想要输出提示信息的地方调用 Logger 对象，并使用相应函数，消息会以 “[TYPE]Message” 的格式显示
```cpp
log.trace("A trace message.");
log.debug("A debug message.");
log.warn("A Warn message");
log.info("An info message");
log.error("An error message");
log.fatal("A fatal message");
//OR
log.fatal("A fatal message",-1);
```

    其中，fatal()函数在显示信息后会强制结束程序，若不自定义错误码则默认返回值0