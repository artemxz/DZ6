#pragma once
#include "statistics.h"
#include <limits>

class MaxStatistics : public Statistics {
private: double max_val;
public:
    MaxStatistics() {
        max_val = std::numeric_limits<double>::lowest();
    }
    void update(double value) override {
        if (value > max_val) {
            max_val = value;
        }
    }
    void print() const override {
        std::cout << "max = " << max_val << std::endl;
    }

};