#pragma once

#include <metric.h>
#include <mutex>
#include <concepts>
#include <optional>

template <typename Func>
class CustomMetric final : public Metric {
private:
    std::mutex mutex_;
    using ReturnType = std::invoke_result_t<Func>;
    std::optional<ReturnType> result_;
    std::string name_;
    Func func_;
public:
    CustomMetric() = default;
    ~CustomMetric() = default;
    CustomMetric(const std::string& name, const Func& func) : name_(name), func_(func) {}
    std::string ToString() const override {
        if (result_.has_value()) {
            return std::to_string(result_.value());
        }
        return "";
    }
    std::string GetName() const override {return name_;}
    void Compute() override {
        std::lock_guard<std::mutex> lock(mutex_);
        result_ = func_();
    }
};