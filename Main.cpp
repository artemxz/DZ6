#include <iostream>
#include <vector>

#include "statistics.h"
#include "MinStatistics.h"
#include "MaxStatistics.h"
#include "MeanStatistics.h"
#include "StdStatistics.h"

int main() {
    
    setlocale(LC_ALL, "RU");

    
    std::vector<Statistics*> stats;

   
    stats.push_back(new MinStatistics());
    stats.push_back(new MaxStatistics());
    stats.push_back(new MeanStatistics());
    stats.push_back(new StdStatistics());

    std::cout << "Введите числа (для завершения нажмите Ctrl+Z и Enter):\n";

    
    double value;
    while (std::cin >> value) {
       
        for (Statistics* stat : stats) {
            stat->update(value);
        }
    }

    std::cout << "\n--- Результаты статистики ---\n";

    for (Statistics* stat : stats) {
        stat->print();
    }

    for (Statistics* stat : stats) {
        delete stat;
    }
    stats.clear();

    return 0;
}