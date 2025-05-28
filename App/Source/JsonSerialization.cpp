#include "JsonSerialization.hpp"

void to_json(json& taskJson, const ExistingTask& task)
{
    taskJson = json{{"id", task.id},
                    {"title", task.taskData.title},
                    {"description", task.taskData.description},
                    {"completed", task.taskData.completed}};
}

void from_json(const json& taskJson, ExistingTask& task)
{
    task.id = taskJson.at("id").get<std::uint64_t>();
    task.taskData.title = taskJson.at("title").get<std::string>();
    task.taskData.description = taskJson.at("description").get<std::string>();
    task.taskData.completed = taskJson.at("completed").get<bool>();
}
