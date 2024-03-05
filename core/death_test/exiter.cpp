#include "exiter.h"

#include <cstdlib>
#include <iostream>

namespace cop::death_test
{
    namespace death_test
    {
        [[noreturn]]
        void quit_program()
        {
            std::cerr << "I'm quitting!\n";
            std::exit(EXIT_FAILURE);
        }

        [[noreturn]]
        void throw_something()
        {
            throw std::exception("up");
        }
    }
}
