#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <cstdint>
#include <string>

struct TaskData
{
    TaskData() = default;
    TaskData(std::string &&title, std::string &&description, bool completed = false);
    std::string title, description;
    bool completed = false;
};

struct ExistingTask
{
    std::uint64_t id{};
    TaskData taskData;

    ExistingTask() = default;
    ExistingTask(std::uint64_t taskId, TaskData &&taskData);
};

#endif  // _TASK_HPP_
