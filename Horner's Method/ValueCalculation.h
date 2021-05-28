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
	static std::pair<int, int> HornerRange(std::deque<double>& polynominal, int x, int precision);
	static double UpperFinder(std::deque<double>& polynominal, int i);
	static double LowerFinder(std::deque<double>& polynominal, int i);

	static double TylorMethod(std::deque<double> &polynominal, int x, int n);

};

