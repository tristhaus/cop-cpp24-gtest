#pragma once

#include "../library/factorial_base.h"

namespace cop::abstract_test
{
    class recursive_factorial : public external_lib::abstract_factorial
    {
    public:
        unsigned calculate(unsigned n) override
        {
            if (n <= 1) {
                return 1;
            }

            return n * this->calculate(n - 1);
        }
    };
}