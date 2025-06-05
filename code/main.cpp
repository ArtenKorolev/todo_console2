#include <exception>
#include <iostream>
#include <memory>

#include "console_ui.hpp"
#include "file_task_repository.hpp"

auto main() -> int
{
    try
    {
        ConsoleUI cli(std::make_unique<FileTaskRepository>());
        cli.run();
        return 0;
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        return 1;
    }
}
