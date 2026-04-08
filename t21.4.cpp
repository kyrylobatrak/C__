#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>
#include <iterator>

struct ClockGenerator {
    clock_t operator()() {
        // Штучна затримка, щоб clock() встиг змінитися
        // volatile не дозволяє компілятору викинути цей цикл при оптимізації
        for (volatile int i = 0; i < 2000000; ++i);

        return std::clock();
    }
};

int main() {
    std::list<clock_t> time_list;
    ClockGenerator generator;

    std::generate_n(std::back_inserter(time_list), 20, generator);

    time_list.sort();

    time_list.unique();

    std::cout << "List contents: ";
    std::copy(time_list.begin(), time_list.end(), std::ostream_iterator<clock_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}