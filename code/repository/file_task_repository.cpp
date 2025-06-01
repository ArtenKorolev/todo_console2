#include "file_task_repository.hpp"

#include <algorithm>
#include <fstream>

#include "config.hpp"
#include "json_serialization.hpp"

std::uint64_t FileTaskRepository::_lastId = 0;

FileTaskRepository::FileTaskRepository()
{
    _loadTasksFromFile();
    _getLastIdFromTasks();
}

void FileTaskRepository::_getLastIdFromTasks()
{
    std::uint64_t lastId = 0;

    for (const auto& task : _inMemoryTasks)
    {
        lastId = std::max<uint64_t>(task.id, lastId);
    }

    FileTaskRepository::_lastId = lastId;
}

FileTaskRepository::~FileTaskRepository() { _saveTasksToFile(); }

void FileTaskRepository::addTask(TaskData&& newTask)
{
    ExistingTask taskToAdd(_getNewId(), std::move(newTask));
    _inMemoryTasks.emplace_back(std::move(taskToAdd));
}

auto FileTaskRepository::_getNewId() -> std::uint64_t { return ++FileTaskRepository::_lastId; }

void FileTaskRepository::removeTask(std::uint64_t idToRemove)
{
    auto removeIterator =
        std::find_if(_inMemoryTasks.begin(), _inMemoryTasks.end(),
                     [idToRemove](const ExistingTask& task) { return task.id == idToRemove; });

    if (removeIterator == _inMemoryTasks.end())
    {
        throw std::runtime_error("Task with given ID not found");
    }

    _inMemoryTasks.erase(removeIterator);
}

[[nodiscard]] auto FileTaskRepository::getAllTasks() const -> std::vector<ExistingTask>
{
    return _inMemoryTasks;
}

void FileTaskRepository::_loadTasksFromFile()
{
    std::ifstream file((Config::getTasksFilePath()));

    if (file.is_open())
    {
        json tasksJson;
        file >> tasksJson;
        _inMemoryTasks = tasksJson.get<std::vector<ExistingTask>>();
        file.close();
    }
}

void FileTaskRepository::_saveTasksToFile() const
{
    std::ofstream file(Config::getTasksFilePath());

    if (file.is_open())
    {
        json tasksJson = _inMemoryTasks;
        file << tasksJson.dump(4);
        file.close();
    }
}
