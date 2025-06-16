#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <ostream>
#include <fstream>
#include "metric.h"

class Writer {
private:
    std::string filepath_;
    mutable std::mutex file_mutex_;

public:
    Writer(const std::string& filepath);
    Writer(std::string&& filepath);
    const std::string& GetFilePath() const;
    std::string GetTimeStamp() const;

    void PrintMetric(std::shared_ptr<Metric> metric) {
        std::lock_guard<std::mutex> lock(file_mutex_);

        std::ofstream file(filepath_, std::ios::app);

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filepath_);
        }

        file << GetTimeStamp() << " " << metric->GetName() << " " << metric->ToString()
             << std::endl;

        if (file.fail()) {
            throw std::runtime_error("Failed to write to file: " + filepath_);
        }
    }

};
