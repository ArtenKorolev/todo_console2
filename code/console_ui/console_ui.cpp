#include "console_ui.hpp"

#include <exception>
#include <iostream>

ConsoleUI::ConsoleUI(std::unique_ptr<TaskRepository> tasksRepository)
    : _tasksRepository(std::move(tasksRepository))
{
}

void ConsoleUI::run()
{
    std::cout << "Welcome to TODO program!\n";

    _initializeCommands();

    while (_isRunning)
    {
        _printOptions();
        _userInput();

        auto command = _commands.find(_inputBuffer);
        std::cout << "\033[2J\033[1;1H";
        if (command != _commands.end())
        {
            command->second();
        }
        else
        {
            std::cerr << "Unknown command!\n";
        }
    }
}

void ConsoleUI::_initializeCommands()
{
    _commands = {{"1", [this] { _printTasks(false); }},
                 {"2", [this] { _printTasks(true); }},
                 {"3", [this] { _addANewTask(); }},
                 {"4", [this] { _completeTask(); }},
                 {"q", [this] { _quit(); }}};
}

void ConsoleUI::_printTasks(bool completed)
{
    std::cout << (completed ? "Completed tasks:\n" : "Active tasks:\n");
    const auto& tasks = _tasksRepository->getAllTasks();

    for (const auto& task : tasks)
    {
        if (task.taskData.completed == completed)
        {
            _printTaskInfo(task);
        }
    }
}

void ConsoleUI::_printTaskInfo(const ExistingTask& task)
{
    std::cout << "--------------------------\n";
    std::cout << task.getInfo() << '\n';
    std::cout << "--------------------------\n";
}

void ConsoleUI::_addANewTask()
{
    std::string title;
    std::string description;

    std::cout << "Enter a title: ";
    _userInput();
    title = _inputBuffer;

    std::cout << "Enter a description: ";
    _userInput();
    description = _inputBuffer;

    TaskData newTaskData(std::move(title), std::move(description));

    try
    {
        _tasksRepository->addTask(std::move(newTaskData));
        std::cout << "New task created successfully!\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Error while creating a new task: " + std::string(e.what()) << '\n';
    }
}

void ConsoleUI::_completeTask()
{
    std::cout << "Enter task id: ";
    _userInput();
    const auto taskToCompleteId = std::stoi(_inputBuffer);

    try
    {
        _tasksRepository->completeTask(taskToCompleteId);
        std::cout << "Task successfully completed!\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Error while completing task: " + std::string(e.what()) << '\n';
    }
}

void ConsoleUI::_quit() { _isRunning = false; }

void ConsoleUI::_userInput() { std::getline(std::cin, _inputBuffer); }

void ConsoleUI::_printOptions()
{
    std::cout << "1 - print all active tasks, 2 - print all completed tasks,\n"
              << "3 - add a new one, 4 - complete task, q - quit\n";
}
