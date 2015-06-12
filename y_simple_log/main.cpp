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
    // 用法和std::cout一模一样
    ylogf(debug,"y_simple_log.log") << "helloworld";
    ylogc(base) << "helloworld";
    ylogc(debug) << 10 << "的16进制值为:" << std::hex << 10;
}
