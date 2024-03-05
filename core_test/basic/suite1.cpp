#include "suite.h"
#include "../../core/basic/adder.h"

#include <gtest/gtest.h>

namespace cop::basic
{
    /* $102$
    INSTANTIATE_TEST_SUITE_P(one, TestSuiteName,
        testing::Values(
            my_value_param{ .input_a = 1, .input_b = 2, .result = 3 },
            my_value_param{ .input_a = -1, .input_b = 2, .result = 1 }
        ));

    TEST_P(TestSuiteName, one_works)
    {
        const auto& value_param = GetParam();
        const adder instance;

        const auto result = instance.perform_addition(value_param.input_a, value_param.input_b);

        EXPECT_EQ(result, value_param.result);
    }

    /* $103$
    TEST_P(TestSuiteName, one_also_works)
    {
        const auto value_param = GetParam();

        const auto local_result = value_param.input_a + value_param.input_b;

        EXPECT_EQ(local_result, value_param.result);
    }
    //*/
}
