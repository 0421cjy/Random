#include <iostream>
#include <chrono>
#include <map>
#include "Random.h"

using namespace std::chrono;

Random::Random()
{
}

Random::~Random()
{
}

void Random::Initialize()
{
    auto seed = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();

    m_generator.seed((unsigned int)seed);
    m_generator64.seed(seed);
}

int Random::GetRandomValue(int min, int max)
{
    uniform_int_distribution<int> distribution(min, max);

    return distribution(m_generator);
}

int64_t Random::GetRandomValue64(int64_t min, int64_t max)
{
    uniform_int_distribution<int64_t> distribution(min, max);

    return distribution(m_generator64);
}

int main()
{
    Random random;
    random.Initialize();

    std::map<int, int> sampleMap;
    std::map<int, int> sampleMap64;

    for (int i = 0; i < 100000; i++)
    {
        auto value = random.GetRandomValue(0, 10);
        ++sampleMap[value];
    }

    for (auto iter = sampleMap.begin(); iter != sampleMap.end(); ++iter)
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    for (int i = 0; i < 100000; i++)
    {
        auto value = random.GetRandomValue64(0, 10);
        ++sampleMap64[value];
    }

    for (auto iter = sampleMap64.begin(); iter != sampleMap64.end(); ++iter)
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
    }
}