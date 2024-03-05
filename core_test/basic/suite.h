#pragma once

#include "gtest/gtest.h"

namespace cop::basic
{
    struct my_value_param
    {
        int input_a;
        int input_b;
        int result;
    };

    class TestSuiteName : public ::testing::TestWithParam<my_value_param>
    {};
}