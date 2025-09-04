#ifndef IU450_WE76L_VCMN8
#define IU450_WE76L_VCMN8
// FX.hpp
#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#include "matrix.hpp"

struct result_data
{
    double alpha;
    double dtau;
    double k;
    std::vector<double> x;
    std::vector<double> S;
    std::vector<double> t;
    std::vector<double> tau;
    matrix<double> u;
    matrix<double> v;
    int closestToSpotIndex;
    result_data(double a, double d, double kk,
                const std::vector<double> &xx,
                const std::vector<double> &SS,
                const std::vector<double> &tt,
                const std::vector<double> &ttau,
                const matrix<double> &uu,
                const matrix<double> &vv,
                const int &closestToSpotIndex_)
        : alpha(a), dtau(d), k(kk), x(xx), S(SS), t(tt), tau(ttau),
          u(uu), v(vv), closestToSpotIndex(closestToSpotIndex_) {}

    // This operator converts all the relevant result data to a printable string.
    operator std::string() const
    {
        std::string out;
        for (size_t i = 0; i < x.size(); ++i)
        {
            for (size_t j = 0; j < t.size(); ++j)
            {
                out += "i= " + std::to_string(i) + ", j= " + std::to_string(j) +
                       " v[i][j] " + std::to_string(v[i][j]) + "\n";
            }
        }
        out += "\npremium = " + std::to_string(v[closestToSpotIndex][t.size() - 1]) + "\n"; // Example premium extraction
        return out;
    }
};

class FX
{
public:
    double T, K, S0, sigma, r, dt, dx;
    int N, M;
    FX(double T_, double K_, double S0_, double sigma_, double r_,
       double dt_, double dx_, int N_, int M_)
        : T(T_), K(K_), S0(S0_), sigma(sigma_), r(r_), dt(dt_), dx(dx_), N(N_), M(M_) {}

    result_data evaluate_data_and_premium() const;
    std::string get_data_and_premium() const
    {
        return evaluate_data_and_premium();
    }
};

#endif /* IU450_WE76L_VCMN8 */