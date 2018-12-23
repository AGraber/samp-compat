#define RUN_TESTS

#include <a_samp>
#include <YSI\y_testing>

#include "../../compat.inc"

main() {
    //
}

Test:RunTest() {
    new ret = Function();
    printf("ret: %d", ret);
    ASSERT(ret == 1);
}
