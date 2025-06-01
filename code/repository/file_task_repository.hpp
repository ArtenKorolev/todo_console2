#ifndef _FILE_TASK_REPOSITORY_HPP_
#define _FILE_TASK_REPOSITORY_HPP_

#include "task_repository.hpp"

class FileTaskRepository : public TaskRepository
{
   public:
    FileTaskRepository();
    ~FileTaskRepository() override;

    FileTaskRepository(const FileTaskRepository&) = delete;
    auto operator=(const FileTaskRepository&) -> FileTaskRepository& = delete;
    FileTaskRepository(FileTaskRepository&&) = delete;
    auto operator=(FileTaskRepository&&) -> FileTaskRepository& = delete;

    void addTask(TaskData&& newTask) override;
    void removeTask(std::uint64_t idToRemove) override;
    [[nodiscard]] auto getAllTasks() const -> std::vector<ExistingTask> override;

   private:
    static std::uint64_t _lastId;
    std::vector<ExistingTask> _inMemoryTasks;

    void _getLastIdFromTasks();
    static auto _getNewId() -> std::uint64_t;
    void _loadTasksFromFile();
    void _saveTasksToFile() const;
};

#endif  // _FILE_TASK_REPOSITORY_HPP_
