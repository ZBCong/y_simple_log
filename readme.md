# y_simple_log: simple log for cpp

------

### 用法

```cpp
#include "y_simple_log.h"

int main(int argc, char** argv)
{
    // 就2个宏: ylogf 和 ylogc, 分别输入日志到 文件 和 终端
    // 就2个等级,一个输入调试信息,一个输入简单信息
    // 用法和std::cout一模一样
    ylogf(debug,"y_simple_log.log") << "helloworld";
    ylogc(base) << "helloworld";
    ylogc(debug) << 10 << "的16进制值为:" << std::hex << 10;
}
```