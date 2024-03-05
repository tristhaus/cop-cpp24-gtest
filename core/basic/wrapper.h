#pragma once

#include <memory>

#include "adder.h"

namespace cop::basic
{
    class wrapper
    {
    private:
        std::shared_ptr<adder> m_adder;

    public:
        wrapper(const std::shared_ptr<adder>& instance) : m_adder(instance)
        {
        }

        int run(const int a, const int b) const
        {
            return m_adder->perform_addition(a, b);
        }
    };
}