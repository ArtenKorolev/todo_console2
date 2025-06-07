#include <exception>
#include <iostream>
#include <memory>

#include "console_ui.hpp"
#include "task_repository_factory.hpp"

auto main() -> int
{
    try
    {
        auto tasksRepo = TaskRepositoryFactory::getTaskRepository();
        ConsoleUI cli(std::move(tasksRepo));
        cli.run();
        return 0;
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        return 1;
    }
}
