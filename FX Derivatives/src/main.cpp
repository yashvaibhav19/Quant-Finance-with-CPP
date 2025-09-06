// FX1_main.cpp
// requires FX_source.cpp, FX_print.cpp
#include "FX.hpp"
using namespace std;

void FXOption()
{
	cout << "\n *** START FX1: Finite Difference European Call ***\n\n ";
	// STEP 1: INPUT PARAMETERS
	auto T = 0.5;	   // maturity
	auto K = 75.0;	   // strike
	auto S0 = 75.0;	   // spot
	auto sigma = 0.30; // volatility
	auto r = 0.05;	   // interest rate
	auto dx = 0.5;	   // space step
	auto dt = 0.1;	   // time step
	auto N = 5;		   // number of space steps
	auto M = 6;		   // number of time steps
	// Construct a FX_EQ1 object from the input parameters:
	FX fx_eq1(T, K, S0, sigma, r, dt, dx, N, M);
	// Ask the object to evaluate the FX data for European Call:
	auto result = fx_eq1.get_data_and_premium();
	// STEP 7: OUTPUT RESULTS
	cout << result;
	cout << "\n *** END FX1: Finite Difference European Call ***\n ";
}

void FXBarrierOption()
{
	cout << "\n *** START FX2: Finite Difference"
		 << " European Up-and-Out Barrier Call *** \n\n";
	// STEP 1: INPUT PARAMETERS
	auto T = 0.5;	   // maturity
	auto K = 75.0;	   // strike
	auto S0 = 75.0;	   // spot
	auto sigma = 0.30; // volatility
	auto r = 0.05;	   // interest rate
	auto dx = 0.5;	   // space step
	auto dt = 0.1;	   // time step
	auto N = 5;		   // number of space steps
	auto M = 6;		   // number of time steps
	// Construct a FX object from the input parameters:
	FX fx_eq2(T, K, S0, sigma, r, dt, dx, N, M);
	// Ask the object to evaluate the FX data
	// for European Up-and_Out Barrier Call:
	auto result = fx_eq2.get_data_and_premium_barrier();
	// STEP 7: OUTPUT RESULTS
	cout << result;
	cout << "\n *** END FX2: Finite Difference"
		 << " European Up-and-Out Barrier Call *** \n";
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
Archeopteryx asks do you want (1) FX Option
							  (2) FX Barrier Option
Type 1/2:)";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		FXOption();
		break;
	}
	case 2:
	{
		FXBarrierOption();
		break;
	}
	default:
	{
		std::cout << "Wrong choice. Exiting program...\n";
	}
	}
	return 0;
}