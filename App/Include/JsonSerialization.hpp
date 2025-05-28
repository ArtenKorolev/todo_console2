#ifndef _JSON_SERIALIZATION_HPP_
#define _JSON_SERIALIZATION_HPP_

#include <nlohmann/json.hpp>

#include "Task.hpp"

using json = nlohmann::json;

void to_json(json& taskJson, const ExistingTask& task);

void from_json(const json& taskJson, ExistingTask& task);

#endif  // _JSON_SERIALIZATION_HPP_
