#ifndef _TASK_REPOSITORY_HPP_
#define _TASK_REPOSITORY_HPP_

#include <vector>

#include "Task.hpp"

class TaskRepository
{
   public:
    TaskRepository() = default;
    virtual ~TaskRepository() = default;

    TaskRepository(const TaskRepository&) = delete;
    auto operator=(const TaskRepository&) -> TaskRepository& = delete;
    TaskRepository(TaskRepository&&) = delete;
    auto operator=(TaskRepository&&) -> TaskRepository& = delete;

    virtual void addTask(TaskData&& newTask) = 0;
    virtual void removeTask(std::uint64_t idToRemove) = 0;
    [[nodiscard]] virtual auto getAllTasks() const -> std::vector<ExistingTask> = 0;
};

#endif  // _TASK_REPOSITORY_HPP_
