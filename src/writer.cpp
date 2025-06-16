#include "writer.h"
#include <chrono>
#include <fstream>

Writer::Writer(const std::string& filepath) : filepath_(filepath) {
}

Writer::Writer(std::string&& filepath) : filepath_(std::move(filepath)) {
}

const std::string& Writer::GetFilePath() const {
    return filepath_;
}

std::string Writer::GetTimeStamp() const {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    auto timer = std::chrono::system_clock::to_time_t(now);

    std::ostringstream timestamp;
    timestamp << std::put_time(std::localtime(&timer), "%Y-%m-%d %H:%M:%S") << "."
              << std::setfill('0') << std::setw(3) << ms.count();
    return timestamp.str();
}
