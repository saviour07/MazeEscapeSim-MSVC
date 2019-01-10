#include "rng.h"

namespace mes_rng
{
    int Rng::GenerateNumber(int min, int max)
    {
        std::random_device randomDevice;
        std::mt19937 rng(randomDevice());
        std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);
        return distribution(rng);
    }
}