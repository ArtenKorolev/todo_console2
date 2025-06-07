#ifndef _TASK_REPOSITORY_HPP_
#define _TASK_REPOSITORY_HPP_

#include <vector>

#include "task.hpp"

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
    [[nodiscard]] virtual auto getAllTasks() const -> const std::vector<ExistingTask>& = 0;
    virtual void completeTask(std::uint64_t idToComplete) = 0;
};

#endif  // _TASK_REPOSITORY_HPP_
