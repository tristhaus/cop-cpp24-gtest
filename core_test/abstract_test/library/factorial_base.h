#pragma once

#include "../../../core/abstract_test/library/factorial_base.h"

#include "gtest/gtest.h"

#include <array>
#include <memory>

namespace cop::abstract_test::external_lib
{
    class factorial : public ::testing::TestWithParam<std::tuple<std::pair<unsigned, unsigned>, std::shared_ptr<abstract_factorial>>>
    {
    };

    constexpr std::array factorial_calculate_default =
    {
        std::make_pair<unsigned, unsigned>(0, 1),
        std::make_pair<unsigned, unsigned>(1, 1),
        std::make_pair<unsigned, unsigned>(3, 6),
        std::make_pair<unsigned, unsigned>(6, 720)
    };

    TEST_P(factorial, calculate)
    {
        const auto params = GetParam();

        const auto input = std::get<0>(params).first;
        const auto expected = std::get<0>(params).second;

        const auto instance = std::get<1>(params);

        EXPECT_EQ(expected, instance->calculate(input));
    }
}
