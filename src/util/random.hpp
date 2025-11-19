//
// Created by simone on 19/11/25.
//

#ifndef FARMANDCONQUER_RANDOM_HPP
#define FARMANDCONQUER_RANDOM_HPP
#include <random>

class Random {
public:
    Random()
        : rng_(std::random_device{}())
    {}

    float floatInRange(const float min, const float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(rng_);
    }

    int intInRange(const int min, const int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng_);
    }

private:
    std::mt19937 rng_;
};

#endif //FARMANDCONQUER_RANDOM_HPP