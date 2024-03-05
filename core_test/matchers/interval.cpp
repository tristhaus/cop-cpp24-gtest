#include "gmock/gmock-more-matchers.h"
#include "gtest/gtest.h"

namespace cop::matchers
{
    using namespace ::testing;

    /* $503$
    class interval
    {
        int m_lower;
        int m_upper;

    public:
        interval(const int lower, const int upper) : m_lower(lower), m_upper(upper)
        {
        }

        int lower() const { return m_lower; }
        int upper() const { return m_upper; }
    };

    MATCHER_P(is_in_interval_handwritten, interval, "")
    {
        if (!(arg >= interval.lower() && arg <= interval.upper())) // note : this is originally a function from `boost`
        {
            *result_listener << arg << " is not inside [" << interval.lower() << ", " << interval.upper() << "]";

            return false;
        }

        return true;
    }

    TEST(matchers_interval, handwritten_matcher)
    {
        const interval interval{ 2, 4 };

        EXPECT_THAT(3, is_in_interval_handwritten(interval));
        EXPECT_THAT(5, Not(is_in_interval_handwritten(interval)));
    }

    TEST(matchers_interval, local_composite_matcher)
    {
        const interval interval{ 2, 4 };

        EXPECT_THAT(3, AllOf(Ge(interval.lower()), Le(interval.upper()))) << "3 is not inside [" << interval.lower() << ", " << interval.upper() << "]";
        EXPECT_THAT(5, Not(AllOf(Ge(interval.lower()), Le(interval.upper()))));
    }

    MATCHER_P(is_in_interval_composite, interval, "")
    {
        return ExplainMatchResult(AllOf(Ge(interval.lower()), Le(interval.upper())), arg, result_listener);
    }

    TEST(matchers_interval, composite_matcher)
    {
        const interval interval{ 2, 4 };

        EXPECT_THAT(3, is_in_interval_composite(interval));
        EXPECT_THAT(5, Not(is_in_interval_composite(interval)));
    }
    //*/
}