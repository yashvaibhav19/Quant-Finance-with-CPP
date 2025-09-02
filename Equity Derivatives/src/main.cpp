#include <iostream>
#include <cmath>
#include <algorithm>

#include "random.hpp"

using namespace std;
void SingleStock()
{
	cout << "\n *** START EQ1: Monte Carlo European Call *** \n";
	// STEP 1: INPUT PARAMETERS
	double T = 1;		 // maturity
	double K = 100;		 // strike
	double S0 = 100;	 // spot
	double sigma = 0.10; // volatility
	double r = 0.05;	 // interest rate
	int N = 500;		 // number of steps
	int M = 10000;		 // number of simulations
	double S[N + 1];
	double sumpayoff = 0;
	double premium = 0;
	double dt = T / N;
	// STEP 2: MAIN SIMULATION LOOP
	for (int j = 0; j < M; j++)
	{
		S[0] = S0; // initialize each path for simulation
		// STEP 3: TIME INTEGRATION LOOP
		for (int i = 0; i < N; i++)
		{
			double epsilon = SampleBoxMuller(); // get Gaussian draw
			S[i + 1] = S[i] * (1 + r * dt + sigma * sqrt(dt) * epsilon);
		}
		// STEP 4: COMPUTE PAYOFF
		sumpayoff += max(S[N] - K, 0.0); // compute and ad payoff
	}
	// STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF
	premium =
		exp(-r * T) * (sumpayoff / M);
	// STEP 6: OUTPUT RESULTS
	cout << "premium = " << premium << "\n";
	cout << "\n *** END EQ1: Monte Carlo single asset *** \n";
}

void DoubleStock()
{
	cout << "\n *** START EQ2: Monte Carlo equity basket *** \n";
	// STEP 1: INPUT PARAMETERS
	double T = 1;		  // maturity
	double r = 0.05;	  // interest rate
	double S10 = 120;	  // spot equity 1
	double S20 = 100;	  // spot equity 2
	double sigma1 = 0.10; // volatility
	double sigma2 = 0.15; // volatility
	double rho = 0.5;	  // correlation
	int N = 300;		  // number of steps
	int M = 10000;		  // number of simulations
	double S1[N + 1];
	double S2[N + 1];
	double sumpayoff = 0;
	double premium = 0;
	double dt = T / N;

	// STEP 2: MAIN SIMULATION LOOP
	for (int j = 0; j < M; j++)
	{
		S1[0] = S10;
		S2[0] = S20;
		// STEP 3: TIME INTEGRATION LOOP
		for (int i = 0; i < N; i++)
		{
			double epsilon1 = SampleBoxMuller();
			double epsilon2 = SampleBoxMuller();
			S1[i + 1] = S1[i] * (1 + r * dt + sigma1 * sqrt(dt) * epsilon1);
			epsilon2 = epsilon1 * rho + sqrt(1 - rho * rho) * epsilon2;
			S2[i + 1] = S2[i] * (1 + r * dt + sigma2 * sqrt(dt) * epsilon2);
		}
		// STEP 4: TIME INTEGRATION LOOP
		sumpayoff += max(S1[N], S2[N]);
	}
	// STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF
	premium = exp(-r * T) * (sumpayoff / M);
	// STEP 6: OUTPUT RESULTS
	cout << "premium = " << premium << "\n";
	cout << "\n *** END EQ2: Monte Carlo equity basket *** \n";
}

int main()
{
	std::cout << R"(
                 _..--+~/@-~--.
             _-=~      (  .   "}
          _-~     _.--=.\ \""""
        _~      _-       \ \_\
       =      _=          '--'
      '      =                             .
     :      :       ____                   '=_. ___
___  |      ;                            ____ '~--.~.
     ;      ;                               _____  } |
  ___=       \ ___ __     __..-...__           ___/__/__
     :        =_     _.-~~          ~~--.__
_____ \         ~-+-~                   ___~=_______
     ~@#~~ == ...______ __ ___ _--~~--_
                                                    =
Archeopteryx asks do you want (1) MC simulation of single stock OR
							  (2) MC simulation of a basket of stocks
Type 1/2:)";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		SingleStock();
		break;
	}
	case 2:
	{
		DoubleStock();
		break;
	}
	default:
	{
		std::cout << "Wrong choice. Exiting program...\n";
	}
	}
	return 0;
}