#include "random.hpp"

double SampleBoxMuller::operator()() const
{
    double x, y, xysquare;
    do
    {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        xysquare = x * x + y * y;
    } while (xysquare >= 1.0 || xysquare == 0.0);
    return x * std::sqrt(-2 * std::log(xysquare) / xysquare);
}