#pragma once

#include <string>

class Metric {
public:
    virtual ~Metric() = default;
    Metric() = default;
    virtual std::string ToString() const = 0;
    virtual std::string GetName() const = 0;
    virtual void Compute() = 0;
};
