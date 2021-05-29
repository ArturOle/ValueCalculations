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
	
	std::cout << "----------------\nHörner Scheme" << std::endl;

	precision = ValueCalculation::HornerPrecision(polynominal, x, 0.0001);
	range_of_roots = ValueCalculation::HornerRange(polynominal, x, precision=0.25);
	result_horner = ValueCalculation::HornerMethod(polynominal, x);

	std::cout << "Result: " << result_horner << "" << std::endl << "----------------" << std::endl;

	std::cout << "Taylor Series" << std::endl;
	std::cout << "Constant 10 iterations" << std::endl;
	result_tylor = ValueCalculation::TylorMethod_e(-1.5, 10);
	std::cout << "\nIterate until precision is met" << std::endl;
	result_tylor = ValueCalculation::TylorMethod_e(-1.5/*, precision=0.0001*/);
	return 0;
}
