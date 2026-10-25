#pragma once
#include "statistics.h"
#include <limits>

class MeanStatistics : public Statistics {
private:
    double summa;
    int m_size;

public:
    MeanStatistics() {
        summa = 0.0;
        m_size = 0; 
    }
    void update(double value) override {
        summa = value + summa;
        m_size++;
    }
    void print() const override {
        if (m_size == 0) {
            std::cout << "такое я не принимаю " << std::endl;
            return;
        }

        std::cout << "mean = " << (summa / m_size) << std::endl;
    }

};