#pragma once

#include "metric.h"
#include <memory>
#include <unordered_map>
#include <mutex>
#include "writer.h"
#include <stdexcept>

class MetricsManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Metric>> metrics_;
    std::mutex metrics_mutex_;
    std::shared_ptr<Writer> writer_;
public:
    MetricsManager(std::shared_ptr<Writer> writer);
    void Add(std::shared_ptr<Metric> metric);
    void Compute(const std::string& name);
    void ComputeAll();
    void WriteAll();
};
