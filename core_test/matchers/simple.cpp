#include "gmock/gmock-more-matchers.h"
#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"

namespace cop::matchers
{
    using namespace ::testing;

    /* $501$
    TEST(matchers, equivalents)
    {
        EXPECT_TRUE(true);
        EXPECT_THAT(true, IsTrue());

        EXPECT_EQ(1, 1);
        EXPECT_THAT(1, Eq(1));

        EXPECT_THAT(-2, -2);
        // DANGER // $502$
        EXPECT_THAT(true, "whatever");

        EXPECT_LT(1, 2);
        EXPECT_THAT(1, Lt(2));

        std::string s("something");

        EXPECT_STREQ("something", s.c_str());
        EXPECT_THAT(s, StrEq("something"));

        EXPECT_DOUBLE_EQ(6.6, 6.6);
        EXPECT_THAT(6.6, DoubleEq(6.6));
    }

    TEST(matchers, generics)
    {
        std::unique_ptr<int> ptr;
        EXPECT_THAT(ptr, IsNull());

        ptr = std::make_unique<int>(5);
        EXPECT_THAT(ptr, NotNull());
        EXPECT_THAT(ptr, Pointee(Eq(5)));


        std::optional<int> opt;
        EXPECT_THAT(opt, Eq(std::nullopt));

        opt = 2;
        EXPECT_THAT(opt, Ne(std::nullopt));
        EXPECT_THAT(opt, Optional(2));


        std::variant<std::string, int> variant;
        EXPECT_THAT(variant, Not(VariantWith<int>(3)));

        variant.emplace<std::string>("something");
        EXPECT_THAT(variant, Not(VariantWith<int>(3)));

        variant.emplace<int>(3);
        EXPECT_THAT(variant, VariantWith<int>(3));
        EXPECT_THAT(variant, Not(VariantWith<std::string>("something")));
    }

    TEST(matchers, floating)
    {
        EXPECT_NONFATAL_FAILURE(
            EXPECT_DOUBLE_EQ(std::sqrt(-1.0), std::sqrt(-1.0));
            , "");

        EXPECT_THAT(std::sqrt(-1.0), Not(DoubleEq(std::sqrt(-1.0))));
        EXPECT_THAT(std::sqrt(-1.0), NanSensitiveDoubleEq(std::sqrt(-1.0)));
        EXPECT_THAT(std::sqrt(-1.0), IsNan());

        EXPECT_THAT(-6.0, DoubleNear(-6.09, 0.1)); // EXPECT_NEAR
        EXPECT_THAT(0.0, DoubleNear(0.1, 0.1));
        EXPECT_THAT(-6.0, Not(DoubleNear(-6.11, 0.1)));

        EXPECT_THAT(std::sqrt(-1.0), Not(DoubleNear(std::sqrt(-1.0), 0.1)));
        EXPECT_THAT(std::sqrt(-1.0), NanSensitiveDoubleNear(std::sqrt(-1.0), 0.1));
    }

    TEST(matchers, containers)
    {
        std::vector values{ 0.4, 0.5, 0.6 };

        EXPECT_THAT(values, BeginEndDistanceIs(3));
        EXPECT_THAT(values, BeginEndDistanceIs(Gt(2)));

        // take out both `Not` for demonstration of error reporting
        EXPECT_THAT(values, Not(Eq(std::vector{ 0.4, 0.5 })));
        EXPECT_THAT(values, Not(ContainerEq(std::vector{ 0.4, 0.5 })));

        EXPECT_THAT(values, Contains(0.5));
        EXPECT_THAT(values, Contains(Lt(0.55)).Times(2));
        EXPECT_THAT(values, Contains(0.3).Times(0));

        EXPECT_THAT(values, Each(AllOf(Gt(0.3), Lt(0.7))));
        EXPECT_THAT(values, Each(AnyOf(Eq(0.6), Eq(0.4), Eq(0.5))));

        EXPECT_THAT(values, ElementsAre(Eq(0.4), 0.5, Ge(0.6)));
        EXPECT_THAT(values, UnorderedElementsAre(0.5, Ge(0.6), Eq(0.4)));

        EXPECT_THAT(values, WhenSortedBy(std::greater(), ElementsAre(0.6, 0.5, 0.4)));
    }

    MATCHER_P(mod_congruent, divisor, "") // MATCHER, MATCHER_P, MATCHER_P2, ... MATCHER_P10
    {
        return (std::get<0>(arg) % divisor) == (std::get<1>(arg) % divisor); // usage in `Pointwise` makes `arg` a tuple
    }

    TEST(matchers, container_mod)
    {
        const std::vector values{ 1, 4, 8, 9 };
        const std::vector expected{ 13, 1, 2, 3 };

        EXPECT_THAT(values, Pointwise(mod_congruent(3), expected));
        EXPECT_THAT(values, Not(Pointwise(mod_congruent(4), expected)));
        EXPECT_THAT(values, Pointwise(Not(Eq()), expected));

        const std::vector too_short{ 13, 1, 2 };
        const std::vector too_long{ 13, 1, 2, 3, 133 };
        const std::vector wrong{ 13, 1, 2, 4 };

        EXPECT_THAT(too_short, Not(Pointwise(Eq(), expected)));
        EXPECT_THAT(too_long, Not(Pointwise(Eq(), expected)));
        EXPECT_THAT(wrong, Not(Pointwise(Eq(), expected)));
    }

    TEST(matchers, class_based) // things exist for maps, pairs, tuples
    {
        struct my_struct
        {
            int some_field = 7;
            std::string some_property() const
            {
                return std::string{ "some value" };
            }
        };

        const my_struct instance;

        EXPECT_THAT(instance, Field(&my_struct::some_field, Eq(7)));
        EXPECT_THAT(instance, Property(&my_struct::some_property, StrEq("some value")));
    }

    int times_two(int arg)
    {
        return 2 * arg;
    }

    TEST(matchers, function_result)
    {
        EXPECT_THAT(3, ResultOf("Some description", times_two, Eq(6)));
    }

    TEST(matchers, conditional)
    {
        int value = 2;

        EXPECT_THAT(value, Conditional(value > 1, Eq(2), Eq(-4)));
        EXPECT_THAT(value, Conditional(Matches(Gt(1))(value), Eq(2), Eq(-4))); // matcher as predicate
        EXPECT_THAT(value, Conditional(Value(value, Gt(1)), Eq(2), Eq(-4))); // matcher as predicate
    }
    //*/
}
