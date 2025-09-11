// IR.hpp
#ifndef IR_HPP
#define IR_HPP

#include <vector>

// Stores simulation datapoints and the averaged NPV
struct IR_results
{
    std::vector<double> datapoints;
    double Value;
    IR_results(const std::vector<double> &dp, double val)
        : datapoints(dp), Value(val) {}
};

// Interest Rate Swap Monte Carlo simulator for 1F LMM
class IR
{
public:
    // Constructor: maps main.cpp signature
    IR(double notional_, double K_, double alpha_, double sigma_, double dT_, int N_, int M_)
        : notional(notional_), K(K_), alpha(alpha_), sigma(sigma_),
          dT(dT_), N(N_), M(M_) {}

    // Monte Carlo simulation: returns all datapoints and mean PV
    IR_results run_LIBOR_simulations() const;

    // User-facing API: runs simulation and returns results
    IR_results get_simulation_data() const { return run_LIBOR_simulations(); }

private:
    double notional; // Notional amount
    double K;        // Fixed rate for IRS
    double alpha;    // Day count fraction (e.g., 0.25)
    double sigma;    // Volatility
    double dT;       // Time step
    int N;           // Number of forward rates
    int M;           // Number of Monte Carlo paths
};

#endif // IR_HPP
