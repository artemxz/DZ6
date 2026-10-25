#pragma once
#include <iostream>
#include <chrono>

class Statistics {   
    public:
        virtual ~Statistics() = default;
        virtual void update(double value) = 0;
        virtual void print() const = 0;
    };