#include "ValueCalculation.cpp"
#include <iostream>


int main()
{
	std::deque<double> polynominal = { 3, 1, -2, 1, -3, 1 };
	std::pair<int, int> range_of_roots;
	int x = 3;

	double result_horner;
	double result_tylor;
	float precision;
	
	std::cout << "----------------\n\e[1mHörner Scheme\e[0m" << std::endl;

	precision = ValueCalculation::HornerPrecision(polynominal, x, 0.0001);
	range_of_roots = ValueCalculation::HornerRange(polynominal, x, precision=0.25);
	result_horner = ValueCalculation::HornerMethod(polynominal, x);

	std::cout << "\e[4mResult: " << result_horner << "\e[0m" << std::endl << "----------------" << std::endl;

	std::cout << "\e[1mTaylor Series\e[0m" << std::endl;
	std::cout << "\e[3mConstant 10 iterations\e[0m" << std::endl;
	result_tylor = ValueCalculation::TylorMethod_e(-1.5, 10);
	std::cout << "\n\e[3mIterate until precision is met\e[0m" << std::endl;
	result_tylor = ValueCalculation::TylorMethod_e(-1.5/*, precision=0.0001*/);
	return 0;
}
