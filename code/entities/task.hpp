#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <cstdint>
#include <string>

struct TaskData
{
    TaskData() noexcept = default;
    TaskData(TaskData &&) noexcept = default;
    auto operator=(TaskData &&) -> TaskData & = default;
    auto operator=(const TaskData &) -> TaskData & = default;
    TaskData(const TaskData &) noexcept = default;
    explicit TaskData(std::string &&title, std::string &&description, bool completed = false);
    ~TaskData() noexcept = default;

    std::string title, description;
    bool completed = false;
};

struct ExistingTask
{
    ExistingTask() noexcept = default;
    ExistingTask(std::uint64_t taskId, TaskData &&taskData);
    ExistingTask(ExistingTask &&) noexcept = default;
    auto operator=(ExistingTask &&) -> ExistingTask & = default;
    auto operator=(const ExistingTask &) -> ExistingTask & = default;
    ExistingTask(const ExistingTask &) noexcept = default;
    explicit ExistingTask(std::string &&title, std::string &&description, bool completed = false);
    ~ExistingTask() noexcept = default;

    auto getInfo() const -> std::string;

    std::uint64_t id{};
    TaskData taskData;
};

#endif  // _TASK_HPP_
