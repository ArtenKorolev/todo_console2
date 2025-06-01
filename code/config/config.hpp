#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

class Config
{
   public:
    Config() = default;
    ~Config() = default;

    Config(const Config&) = delete;
    auto operator=(const Config&) -> Config& = delete;
    Config(Config&&) = delete;
    auto operator=(Config&&) -> Config& = delete;

    static constexpr auto tasksFilePath = "tasks.json";
};

#endif  // _CONFIG_HPP_
