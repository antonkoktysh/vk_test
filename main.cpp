#include "metric_manager.h"
#include <custom_metric.h>
#include <random>
#include <writer.h>
#include <thread>

int AudiA8() {
    static std::mt19937 mt(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0, 54);
    return dist(mt);
}

void f(MetricsManager& manager) {
    for (size_t ind = 0; ind < 10; ++ind) {
        manager.ComputeAll();
        manager.WriteAll();
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::runtime_error("Wrong number of arguments!");
    }
    std::string filepath = argv[1];
    std::shared_ptr<Writer> writer = std::make_shared<Writer>(filepath);
    MetricsManager manager(writer);
    CustomMetric<decltype(&AudiA8)> metric("Audi", &AudiA8);
    auto base_ptr = std::make_shared<decltype(metric)>(metric.GetName(), &AudiA8);
    manager.Add(base_ptr);
    std::thread t1(f, std::ref(manager));
    for (size_t ind = 0; ind < 10; ++ind) {
        manager.ComputeAll();
        manager.WriteAll();
    }
    t1.join();
    return 0;
}
