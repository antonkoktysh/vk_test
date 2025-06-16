#include "metric_manager.h"

MetricsManager::MetricsManager(std::shared_ptr<Writer> writer) : writer_(writer) {}

void MetricsManager::Compute(const std::string& name) {
    if (!metrics_.count(name)) {
        throw std::runtime_error("No such metric: " + name);
    }
    metrics_[name]->Compute();
}

void MetricsManager::ComputeAll() {
    for (auto&& metric : metrics_) {
        metric.second->Compute();
    }

}

void MetricsManager::WriteAll() {
    for (auto&& metric : metrics_) {
        writer_->PrintMetric(metric.second);
    }
}

void MetricsManager::Add(std::shared_ptr<Metric> metric) {
    metrics_[metric->GetName()] = metric;
}