#include "../../core/basic/wrapper.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace
{
    class mock_adder : public cop::basic::adder
    {
    public:
        MOCK_METHOD(int, perform_addition, (const int a, const int b), (const, override));
    };
}

namespace cop::basic
{
    /* $105$
    TEST(wrapper, mock)
    {
        const auto adder_mock = std::make_shared<mock_adder>();
        const wrapper wrapper(adder_mock);

        EXPECT_CALL(*adder_mock, perform_addition(::testing::Eq(22), ::testing::_))
            .Times(1)
            .WillRepeatedly(::testing::Return(1337));

        const auto result = wrapper.run(22, 20);

        ASSERT_EQ(1337, result);
    }
    //*/
}