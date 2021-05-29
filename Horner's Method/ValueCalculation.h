#pragma once
#include <deque>
#include <cmath>
#include <iostream>


class ValueCalculation
{
public:
	ValueCalculation() = default;

	static double HornerMethod(std::deque<double> &polynominal, int x);
	static float HornerPrecision(std::deque<double> polynominal, int x_in, float desired_precision);
	static float HornerPrecision(int degree, int x_in, float desired_precision);
	static std::pair<double, double> HornerRange(std::deque<double>& polynominal, int x, float precision);
	static bool UpperFinder(std::deque<double>& polynominal, double i);
	static bool LowerFinder(std::deque<double> polynominal, double i);

	static double TylorMethod_e(double x, double n);

	static double TylorMethod_e(double x, double n, double precision);

};

