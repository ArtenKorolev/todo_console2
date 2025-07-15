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
    explicit ConsoleUI(std::unique_ptr<ITaskRepository> tasksRepository);
    void run();

   private:
    void _initializeCommands();
    void _printCompletedTasks();
    void _printActiveTasks();
    void _printTasks(bool completed);
    void _addANewTask();
    void _userInput();
    void _completeTask();
    void _quit();

    static void _printOptions();
    static void _printTaskInfo(const ExistingTask& task);

    std::string _inputBuffer;
    std::unique_ptr<ITaskRepository> _tasksRepository;
    std::unordered_map<std::string, std::function<void()>> _commands;
    bool _isRunning = true;
};

#endif  // _CONSOLE_UI_HPP_
