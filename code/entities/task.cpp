#include "task.hpp"
#include <string>

TaskData::TaskData(std::string &&title, std::string &&description, bool completed)
    : title(std::move(title)), description(std::move(description)), completed(completed)
{
}

ExistingTask::ExistingTask(std::uint64_t taskId, TaskData &&taskData)
    : id(taskId), taskData(std::move(taskData))
{
}

auto ExistingTask::getInfo() const -> std::string
{
    return "ID:" + std::to_string(id) + "\nTitle: " + taskData.title + "\nDescription: " + taskData.description + "\nCompleted: " + (taskData.completed ? "Yes" : "No");
}
