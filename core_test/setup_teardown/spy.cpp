#include "../../core/setup_teardown/spy.h"

#include "gtest/gtest.h"

namespace cop::setup_teardown
{
    /* $401$
    TEST(Spy, WorksAsExpected)
    {
        spy function_instance("function");
    }

    /* $402$
    namespace
    {
        class test_fixture : public ::testing::Test
        {
        protected:
            spy object_instance;
            static std::unique_ptr<spy> static_instance;
        public:
            test_fixture() : object_instance(spy("object"))
            {
            }

            // void SetUp() override; // possible alternative to ctor/dtor
            // void TearDown() override;

            static void SetUpTestSuite()
            {
                static_instance = std::make_unique<spy>("static");
            }

            static void TearDownTestSuite()
            {
                static_instance.reset();
            }
        };

        std::unique_ptr<spy> test_fixture::static_instance;
    }

    TEST_F(test_fixture, object1)
    {
    }

    TEST_F(test_fixture, object2)
    {
    }

    /* $403$
    std::unique_ptr<spy> global_instance;

    class my_environment : public ::testing::Environment
    {
    public:
        void SetUp() override
        {
            global_instance = std::make_unique<spy>("global");
        }

        void TearDown() override
        {
            global_instance.reset();
        }
    };

    // non-owning pointer, just a trick to get this registered without a main()
    testing::Environment* const foo_env = testing::AddGlobalTestEnvironment(new my_environment);
    //*/
}