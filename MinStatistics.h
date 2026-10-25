#pragma once
#include "statistics.h"
#include <limits>


class MinStatistics : public Statistics {
private:
    double min_val;

public:
    MinStatistics() {
        min_val = std::numeric_limits<double>::max();
    }
    void update(double value) override {
        if (value < min_val) {
            min_val = value;
        }
    }
    void print() const override {
        std::cout << "min = " << min_val << std::endl;
    }
};



