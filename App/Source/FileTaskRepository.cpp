#include "FileTaskRepository.hpp"

#include "Task.hpp"

void FileTaskRepository::addTask(TaskData&& newTask)
{
    ExistingTask taskToAdd(_getNewId(), std::move(newTask));
    _inMemoryTasks.emplace_back(std::move(taskToAdd));
}

auto FileTaskRepository::_getNewId() const -> std::uint64_t
{
    // Temporary implementation, should be replaced with a proper ID generation logic
    return _inMemoryTasks.size() + 1;
}

void FileTaskRepository::removeTask(std::uint64_t idToRemove)
{
    auto iterator =
        std::remove_if(_inMemoryTasks.begin(), _inMemoryTasks.end(),
                       [idToRemove](const ExistingTask& task) { return task.id == idToRemove; });
    if (iterator != _inMemoryTasks.end())
    {
        _inMemoryTasks.erase(iterator, _inMemoryTasks.end());
    }
}

[[nodiscard]] auto FileTaskRepository::getAllTasks() const -> std::vector<ExistingTask>
{
    return _inMemoryTasks;
}
