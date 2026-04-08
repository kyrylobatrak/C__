#include "main19.1.h"
#include <algorithm>
#include <limits>

QueueResult process_queue(const std::vector<double>& t) {
    QueueResult res;
    int n = t.size();

    if (n == 0) return res;

    res.c.resize(n);

    double prev_finish_time = 0.0;

    double min_service_val = t[0];
    res.min_service_idx = 1;

    double max_spent_val = -1.0;
    res.max_spent_idx = -1;

    for (int i = 0; i < n; ++i) {
        double arrival_time = static_cast<double>(i);

        double start_time = std::max(arrival_time, prev_finish_time);

        double finish_time = start_time + t[i];

        prev_finish_time = finish_time;

        res.c[i] = finish_time - arrival_time;

        if (t[i] < min_service_val) {
            min_service_val = t[i];
            res.min_service_idx = i + 1;
        }

        if (res.c[i] > max_spent_val) {
            max_spent_val = res.c[i];
            res.max_spent_idx = i + 1;
        }
    }

    return res;
}