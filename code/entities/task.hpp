#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <cstdint>
#include <string>

struct TaskData
{
    TaskData() noexcept = default;
    explicit TaskData(std::string title, std::string description, bool completed = false);

    std::string title, description;
    bool completed = false;
};

struct ExistingTask
{
    ExistingTask() noexcept = default;
    explicit ExistingTask(std::uint64_t taskId, TaskData taskData);

    auto getInfo() const -> std::string;

    std::uint64_t id{};
    TaskData taskData;
};

#endif  // _TASK_HPP_
