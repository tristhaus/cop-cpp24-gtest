#pragma once

namespace cop::basic
{
    class adder
    {
    public:
        virtual ~adder() = default;
        [[nodiscard]] virtual int perform_addition(const int a, const int b) const
        {
            return a + b;
        }
    };
}