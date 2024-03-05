#include "../../../core_test/abstract_test/library/factorial_base.h"

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(factorial);

#include "../../../core/abstract_test/consumer/loop_factorial.h"
#include "../../../core/abstract_test/consumer/recursive_factorial.h"

namespace cop::abstract_test::external_lib
{
    /* $201$
    INSTANTIATE_TEST_SUITE_P(insta, factorial, ::testing::Combine(
        ::testing::ValuesIn(factorial_calculate_default),
        ::testing::Values(
            std::make_shared<loop_factorial>(),
            std::make_shared<recursive_factorial>()
        )
    ));
    //*/
}
