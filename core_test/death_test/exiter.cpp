#include "../../core/death_test/exiter.h"

#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"

namespace cop::death_test
{
    namespace death_test
    {
        /* $301$
        TEST(ExiterDeathTest, quitProgramWorks)
        {
            EXPECT_DEATH(quit_program(), "quitting!") << "but it did not quit";
        }

        /* $302$
        TEST(ExiterDeathTest, throwSomething)
        {
            EXPECT_NONFATAL_FAILURE(
            EXPECT_DEATH(throw_something(), "") << "but it did not throw";
                , "but it did not throw");
        }
        //*/
    }
}