#ifndef _CONSOLE_UI_HPP_
#define _CONSOLE_UI_HPP_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "task.hpp"
#include "task_repository.hpp"

class ConsoleUI
{
   public:
    explicit ConsoleUI(std::unique_ptr<TaskRepository> tasksRepository);
    void run();

   private:
    void _initializeCommands();
    void _printTasks(bool completed);
    static void _printTaskInfo(const ExistingTask& task);
    void _addANewTask();
    static void _quit();
    void _userInput();
    void _completeTask();
    static void _printOptions();

    std::string _inputBuffer;
    std::unique_ptr<TaskRepository> _tasksRepository;
    std::unordered_map<std::string, std::function<void()>> _commands;
};

#endif  // _CONSOLE_UI_HPP_
