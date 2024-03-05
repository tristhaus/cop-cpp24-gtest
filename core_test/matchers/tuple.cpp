#include "gmock/gmock-more-matchers.h"
#include "gtest/gtest.h"

#include <ranges>

namespace cop::matchers
{
    using namespace ::testing;

    /* $504$
    MATCHER_P(tuple_match_handwritten, expected, "")
    {
        const auto actual = arg;

        if (actual.size() != expected.size())
            return false;

        constexpr auto epsilon = 1E-7;
        for (const auto& [exp, act] : std::views::zip(expected, actual))
        {
            if (!(std::get<0>(exp) == std::get<0>(act) && std::get<1>(exp) == std::get<1>(act) &&
                std::abs(std::get<2>(exp) - std::get<2>(act)) < epsilon))
            {
                return false;
            }
        }

        return true;
    }

    TEST(matchers_tuple, handwritten_matcher)
    {
        const std::vector right{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };
        const std::vector wrong{ std::tuple{ 1, true, 0.4 }, std::tuple{ 2, false, 0.6 } };
        const std::vector reference{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };

        EXPECT_THAT(right, tuple_match_handwritten(reference));
        EXPECT_THAT(wrong, Not(tuple_match_handwritten(reference)));
    }

    MATCHER(is_domain_tuple_match, "")
    {
        const auto& [actual, expected] = arg; // because `Pointwise`
        const auto& [a, b, c] = expected;

        return ExplainMatchResult(FieldsAre(Eq(a), Eq(b), DoubleNear(c, 1E-7)), actual, result_listener);
    }

    TEST(matchers_tuple, composite_matcher_pointwise)
    {
        const std::vector right{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };
        const std::vector wrong{ std::tuple{ 1, true, 0.4 }, std::tuple{ 2, false, 0.6 } };
        const std::vector reference{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };

        EXPECT_THAT(right, Pointwise(is_domain_tuple_match(), reference));
        EXPECT_THAT(wrong, Not(Pointwise(is_domain_tuple_match(), reference)));
    }

    MATCHER_P(is_array_of_domain_tuple_match, expected_array, "")
    {
        return ExplainMatchResult(Pointwise(is_domain_tuple_match(), expected_array), arg, result_listener);
    }

    TEST(matchers_tuple, composite_matcher_on_vector)
    {
        const std::vector right{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };
        const std::vector wrong{ std::tuple{ 1, true, 0.4 }, std::tuple{ 2, false, 0.6 } };
        const std::vector reference{ std::tuple{ 1, true, 0.5 }, std::tuple{ 2, false, 0.6 } };

        EXPECT_THAT(right, is_array_of_domain_tuple_match(reference));
        EXPECT_THAT(wrong, Not(is_array_of_domain_tuple_match(reference)));
    }
    //*/
}