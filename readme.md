# y_simple_log: simple log for cpp

------

### �÷�

```cpp
#include "y_simple_log.h"

int main(int argc, char** argv)
{
    // ��2����: ylogf �� ylogc, �ֱ�������־�� �ļ� �� �ն�
    // ��2���ȼ�,һ�����������Ϣ,һ���������Ϣ
    // �÷���std::coutһģһ��
    ylogf(debug,"y_simple_log.log") << "helloworld";
    ylogc(base) << "helloworld";
    ylogc(debug) << 10 << "��16����ֵΪ:" << std::hex << 10;
}
```