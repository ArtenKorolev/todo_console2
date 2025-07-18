#ifndef _TASK_REPOSITORY_FACTORY_HPP_
#define _TASK_REPOSITORY_FACTORY_HPP_

#include <memory>

#include "task_repository.hpp"

struct TaskRepositoryFactory
{
    static auto getTaskRepository() -> std::unique_ptr<ITaskRepository>;
};

#endif  // _TASK_REPOSITORY_FACTORY_HPP_