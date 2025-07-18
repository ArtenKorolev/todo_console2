#include "file_task_repository.hpp"

#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "config.hpp"
#include "json_serialization.hpp"
#include "task.hpp"

std::uint64_t FileTaskRepository::_lastId = 0;

FileTaskRepository::FileTaskRepository()
{
    _loadTasksFromFile();
    FileTaskRepository::_lastId = _getLastIdFromTasks();
}

void FileTaskRepository::_loadTasksFromFile()
{
    std::ifstream file((config::kTasksFilePath));

    if (!file.is_open())
    {
        return;
    }

    json tasksJson;
    file >> tasksJson;
    _inMemoryTasks = tasksJson.get<std::vector<ExistingTask>>();
}

auto FileTaskRepository::_getLastIdFromTasks() noexcept -> std::uint64_t
{
    std::uint64_t lastId = 0;

    for (const auto& task : _inMemoryTasks)
    {
        lastId = std::max<std::uint64_t>(task.id, lastId);
    }

    return lastId;
}

FileTaskRepository::~FileTaskRepository()
{
    _saveTasksToFile();  // FIXME: Bad approach to save tasks in destructor, should be fixed later
}

void FileTaskRepository::_saveTasksToFile() const
{
    std::ofstream file(config::kTasksFilePath);

    if (!file.is_open())
    {
        return;
    }

    json tasksJson = _inMemoryTasks;
    file << tasksJson.dump(4);
}

void FileTaskRepository::addTask(TaskData&& newTask)
{
    ExistingTask taskToAdd(_getNewId(), std::move(newTask));
    _inMemoryTasks.emplace_back(std::move(taskToAdd));
}

[[nodiscard]] auto FileTaskRepository::_getNewId() noexcept -> std::uint64_t
{
    return ++FileTaskRepository::_lastId;
}

void FileTaskRepository::completeTask(std::uint64_t idToComplete)
{
    auto taskIterator = _getTaskById(idToComplete);
    (*taskIterator).taskData.completed = true;
}

auto FileTaskRepository::_getTaskById(std::uint64_t taskId) -> TasksIterator
{
    auto iterator = std::find_if(_inMemoryTasks.begin(), _inMemoryTasks.end(),
                                 [taskId](const ExistingTask& task) { return task.id == taskId; });

    if (iterator == _inMemoryTasks.end())
    {
        throw std::runtime_error("Task with given ID not found");
    }

    return iterator;
}

[[nodiscard]] auto FileTaskRepository::getAllTasks() const noexcept
    -> const std::vector<ExistingTask>&
{
    return _inMemoryTasks;
}
