#include "console_ui.hpp"

#include <iostream>

#include "file_task_repository.hpp"

void ConsoleUI::run()
{
    std::cout << "Welcome to TODO program!\n";

    bool isActive = true;

    std::string userInput;

    while (isActive)
    {
        _printOptions();
        _userInput(userInput);

        if (userInput == "q")
        {
            break;
        }

        _handleInput(userInput);
    }
}

void ConsoleUI::_handleInput(const std::string &input)
{
    FileTaskRepository tasksRepo;

    if (input == "1")
    {
        std::cout << "Active tasks: \n";
        auto tasks = tasksRepo.getAllTasks();

        for (const auto &task : tasks)
        {
            if (task.taskData.completed)
            {
                continue;
            }
            std::cout << "--------------------------\n";
            std::cout << task.getInfo() << '\n';
            std::cout << "--------------------------\n";
        }
    }
    else if (input == "2")
    {
        std::cout << "Completed tasks: \n";
        auto tasks = tasksRepo.getAllTasks();

        for (const auto &task : tasks)
        {
            if (!(task.taskData.completed))
            {
                continue;
            }
            std::cout << "--------------------------\n";
            std::cout << task.getInfo() << '\n';
            std::cout << "--------------------------\n";
        }
    }
    else if (input == "3")
    {
        std::string title;
        std::string description;

        std::cout << "Enter a title: ";
        _userInput(title);
        std::cout << "Enter a description: ";
        _userInput(description);

        TaskData newTaskData(std::move(title), std::move(description));
        tasksRepo.addTask(std::move(newTaskData));
    }
    else
    {
        std::cerr << "Unknown command!\n";
    }
}

void ConsoleUI::_userInput(std::string &buffer) { std::getline(std::cin, buffer); }

void ConsoleUI::_printOptions()
{
    std::cout << "1 - print all active tasks, 2 - print all completed tasks, 3 - add a new one, 4 "
                 "- complete task, q - quit\n";
}