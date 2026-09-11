#pragma once

#include <vector>

struct QueueResult {
    std::vector<double> c;
    int min_service_idx;
    int max_spent_idx;
};

QueueResult process_queue(const std::vector<double>& t);