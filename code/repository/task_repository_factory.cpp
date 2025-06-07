#include "task_repository_factory.hpp"

#include <memory>

#include "file_task_repository.hpp"

auto TaskRepositoryFactory::getTaskRepository() -> std::unique_ptr<ITaskRepository>
{
    return std::make_unique<FileTaskRepository>();
}
