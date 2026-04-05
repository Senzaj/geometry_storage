#include "../Random/RandomGenerator.h"
#include <iostream>
#include <random>

int RandomGenerator::get_random_integer(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}
