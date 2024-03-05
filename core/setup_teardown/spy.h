#pragma once

#include <iostream>

namespace cop::setup_teardown
{
    class spy
    {
        std::string identifier;

    public:
        explicit spy(std::string identifier) : identifier(std::move(identifier))
        {
            std::cout << ">>>>>>>>>>>>>>> Constructing spy: \"" << this->identifier << "\" <<<<<<<<<<<<<<<\n";
            std::cout.flush();
        }

        ~spy()
        {
            std::cout << ">>>>>>>>>>>>>>> Destructing spy: \"" << this->identifier << "\" <<<<<<<<<<<<<<<\n";
            std::cout.flush();
        }
    };
}