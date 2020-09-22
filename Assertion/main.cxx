#define _ASSERT_GLUE(a, b) a ## b
#define ASSERT_GLUE(a, b) _ASSERT_GLUE(a, b)

#ifdef __cplusplus
    #if __cplusplus >= 201103L
        #define STATIC_ASSERT(expr) \
            static_assert(expr, \
                          "static assert failed:" \
                          #expr)
    #else
        template<bool> class TStaticAssert;
        template<> class TStaticAssert<true> {};

        #define STATIC_ASSERT(expr) \
            enum \
            { \
                ASSERT_GLUE(g_assert_fail_, __LINE__) \
                    = sizeof(TStaticAssert<!!(expr)>) \
            }
    #endif
#endif

int main() {
    STATIC_ASSERT(sizeof(int) == 4);
    STATIC_ASSERT(sizeof(float) == 1);
    return 0;
}