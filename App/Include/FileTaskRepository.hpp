#ifndef _FILE_TASK_REPOSITORY_HPP_
#define _FILE_TASK_REPOSITORY_HPP_

#include "TaskRepository.hpp"

class FileTaskRepository : public TaskRepository
{
   public:
    FileTaskRepository() = default;
    ~FileTaskRepository() override = default;

    FileTaskRepository(const FileTaskRepository&) = delete;
    auto operator=(const FileTaskRepository&) -> FileTaskRepository& = delete;
    FileTaskRepository(FileTaskRepository&&) = delete;
    auto operator=(FileTaskRepository&&) -> FileTaskRepository& = delete;

    void addTask(TaskData&& newTask) override;
    void removeTask(std::uint64_t idToRemove) override;
    [[nodiscard]] auto getAllTasks() const -> std::vector<ExistingTask> override;

   private:
    std::vector<ExistingTask> _inMemoryTasks;

    auto _getNewId() const -> std::uint64_t;
};

#endif  // _FILE_TASK_REPOSITORY_HPP_
