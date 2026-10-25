#pragma once
#include "statistics.h"
#include <cmath> 

class StdStatistics : public Statistics {
private:
    double m_sum;
    double m_sum_sq;
    size_t m_count;
public:
    StdStatistics() {
        m_sum = 0.0;
        m_sum_sq = 0.0;
        m_count = 0;
    }

    void update(double value) override {
        m_sum += value;              
        m_sum_sq += value * value;   
        m_count++;                  
    }

    void print() const override {
        if (m_count == 0) {
            std::cout << "std = 0" << std::endl;
            return;
        }

      
        double mean = m_sum / m_count;

        double variance = (m_sum_sq / m_count) - (mean * mean);

        if (variance < 0.0) {
            variance = 0.0;
        }

        double std_dev = std::sqrt(variance);

        std::cout << "std = " << std_dev << std::endl;
    }
};