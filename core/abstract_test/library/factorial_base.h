#pragma once

namespace cop::abstract_test::external_lib
{
    class abstract_factorial
    {
    public:
        virtual ~abstract_factorial() = default;
        virtual unsigned calculate(unsigned n) = 0;
    };
}