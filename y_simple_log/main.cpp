#include "gtest/gtest.h"
#include "y_simple_log/y_simple_log.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

TEST(hehe, usage)
{
    // �÷���std::coutһģһ��
    ylogf(debug,"y_simple_log.log") << "helloworld";
    ylogc(base) << "helloworld";
    ylogc(debug) << 10 << "��16����ֵΪ:" << std::hex << 10;
}
