#ifndef _FILE_TASK_REPOSITORY_HPP_
#define _FILE_TASK_REPOSITORY_HPP_

#include <vector>

#include "task.hpp"
#include "task_repository.hpp"

using TasksIterator = std::vector<ExistingTask>::iterator;

class FileTaskRepository : public ITaskRepository
{
   public:
    FileTaskRepository();
    ~FileTaskRepository() override;

    FileTaskRepository(const FileTaskRepository&) = delete;
    auto operator=(const FileTaskRepository&) -> FileTaskRepository& = delete;
    FileTaskRepository(FileTaskRepository&&) = delete;
    auto operator=(FileTaskRepository&&) -> FileTaskRepository& = delete;

    void addTask(TaskData&& newTask) override;
    [[nodiscard]] auto getAllTasks() const noexcept -> const std::vector<ExistingTask>& override;
    void completeTask(std::uint64_t idToComplete) override;

   private:
    static std::uint64_t _lastId;
    std::vector<ExistingTask> _inMemoryTasks;

    void _getLastIdFromTasks() noexcept;
    [[nodiscard]] auto _getTaskById(std::uint64_t taskId) -> TasksIterator;
    [[nodiscard]] static auto _getNewId() noexcept -> std::uint64_t;
    void _loadTasksFromFile();
    void _saveTasksToFile() const;
};

#endif  // _FILE_TASK_REPOSITORY_HPP_
