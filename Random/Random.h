#pragma once

#include <random>

using namespace std;

class Random
{
private:
	mt19937	m_generator;
	mt19937_64 m_generator64;

public:
	Random();
	virtual ~Random();

public:
	void Initialize();

	int GetRandomValue(int min, int max);
	int64_t GetRandomValue64(int64_t min, int64_t max);
};
