#include <iostream>
#define _ASSERT_GLUE(a, b) a ## b
#define ASSERT_GLUE(a, b) _ASSERT_GLUE(a, b)

#define STATIC_ASSERT(expr) \
    enum \
    { \
        ASSERT_GLUE(g_assert_fail_, __LINE__) \
        = 1 / (int)(!!(expr)) \
    }

int main() {
    std::cout << "Hello world\n";
    STATIC_ASSERT(sizeof(int) == 4);
    //STATIC_ASSERT(sizeof(float) == 1);
    return 0;
}