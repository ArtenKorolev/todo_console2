#include <exception>
#include <iostream>

#include "console_ui.hpp"

auto main() -> int
{
    try
    {
        ConsoleUI::run();
        return 0;
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        return 1;
    }
}
