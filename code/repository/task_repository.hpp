#ifndef _TASK_REPOSITORY_HPP_
#define _TASK_REPOSITORY_HPP_

#include <vector>

#include "task.hpp"

class ITaskRepository
{
   public:
    ITaskRepository() = default;
    virtual ~ITaskRepository() = default;

    ITaskRepository(const ITaskRepository&) = delete;
    auto operator=(const ITaskRepository&) -> ITaskRepository& = delete;
    ITaskRepository(ITaskRepository&&) = delete;
    auto operator=(ITaskRepository&&) -> ITaskRepository& = delete;

    virtual void addTask(TaskData&& newTask) = 0;
    [[nodiscard]] virtual auto getAllTasks() const -> const std::vector<ExistingTask>& = 0;
    virtual void completeTask(std::uint64_t idToComplete) = 0;
};

#endif  // _TASK_REPOSITORY_HPP_
