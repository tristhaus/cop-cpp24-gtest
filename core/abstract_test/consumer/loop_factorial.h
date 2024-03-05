#pragma once

#include "../library/factorial_base.h"

namespace cop::abstract_test
{
    class loop_factorial : public external_lib::abstract_factorial
    {
    public:
        unsigned calculate(unsigned n) override
        {
            unsigned result = 1;

            for (unsigned factor = 2; factor <= n; ++factor) {
                result *= factor;
            }

            return result;
        }
    };
}