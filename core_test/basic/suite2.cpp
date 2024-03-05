#include "suite.h"
#include "../../core/basic/adder.h"

#include <gtest/gtest.h>

namespace cop::basic
{
    /* $104$
    INSTANTIATE_TEST_SUITE_P(two, TestSuiteName,
        // will cross pollinate with the other INSTANTIATE_TEST_SUITE_P in `abstract.cpp`
        testing::Values(
            my_value_param(2, 1, 3),
            my_value_param(2, -1, 1),
            my_value_param(2, 6, 8)
        ));

    TEST_P(TestSuiteName, two_works)
    {
        const auto& value_param = GetParam();
        const adder instance;

        const auto result = instance.perform_addition(value_param.input_a, value_param.input_b);

        EXPECT_EQ(result, value_param.result);
    }
    //*/
}
