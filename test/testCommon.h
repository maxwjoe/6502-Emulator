#include "stdio.h"

#define LOG_FAIL(TEST_NAME) printf("\e[0;31m FAILED \x1b[0m %s\n", TEST_NAME)
#define LOG_PASS(TEST_NAME) printf("\e[0;32m PASSED \x1b[0m %s\n", TEST_NAME)

void RUN_TEST(int (*fn)(), const char *name)
{
    if (fn == NULL || name == NULL)
    {
        return;
    }

    int hasPassed = fn();

    if (hasPassed)
    {
        LOG_PASS(name);
        return;
    }

    LOG_FAIL(name);
}