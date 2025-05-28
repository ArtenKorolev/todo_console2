#include "Task.hpp"

TaskData::TaskData(std::string &&title, std::string &&description, bool completed)
    : title(std::move(title)), description(std::move(description)), completed(completed)
{
}

ExistingTask::ExistingTask(std::uint64_t taskId, TaskData &&taskData)
    : id(taskId), taskData(std::move(taskData))
{
}
