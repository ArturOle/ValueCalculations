#include "ValueCalculation.h"


double ValueCalculation::HornerMethod(std::deque<double> &polynominal, int x)
{
	/// <summary>
	///	 The implementation of Horner method of calculating value of the polynominal.
	///	 Horner approach reduces complexity of calculating polunominals from O(n^2) to just O(n).
	/// </summary>
	/// 
	/// <param name="polynominal"> 
	/// Array of scalars of the polynominal. 
	/// Polynominal array should be simplifide, example: "2x2 + 1x + 6" correct, "1x2 + 1x2 + 1x + 5" not correct
	/// </param>
	/// <param name="n"> The degree of the polynominal</param>
	/// <param name="x"> The value of x for polynominal</param>
	/// 
	/// <returns>double</returns>
	
	double value = polynominal[0];

	// Iterating over polynominal with constant iterator because it's read only
	for (auto it = polynominal.cbegin()+1; it != polynominal.cend(); ++it)
	{
		// New value is value times x plus value at it
		value = value * x + *it;
	}

	return value;
}


float ValueCalculation::HornerPrecision(std::deque<double> polynominal, int x_in, float desired_precision)
{
	int degree = polynominal.size()-1;
	double x = x_in;
	float result = 1;
	float precision = ((pow(abs(x), degree) - 1) / (abs(x) - 1)) * 0.5;

	while (precision * pow(10, result) >= desired_precision)
	{
		--result;
	}

	std::cout << "Precision: 1E" << result << std::endl;

	return precision;
}


float ValueCalculation::HornerPrecision(int degree, int x_in, float desired_precision)
{
	double x = x_in;
	float result = 1;
	float precision = ((pow(abs(x), degree) - 1) / (abs(x) - 1)) * 0.5;

	while (precision * pow(10, result) >= desired_precision)
	{
		--result;
	}

	std::cout << "Precision: 1E" << result << std::endl;

	return result;
}


std::pair<double, double> ValueCalculation::HornerRange(std::deque<double>& polynominal, int x, float precision)
{
	double lower_bound;
	double upper_bound = precision;

	while (true)
	{
		if ( UpperFinder(polynominal, upper_bound) )
		{
			break;
		}

		upper_bound += precision;
	}
	std::cout << "Upper bound: " << upper_bound << std::endl;

	lower_bound = upper_bound;

	while (true)
	{
		if ( LowerFinder(polynominal, lower_bound) )
		{
			break;
		}

		lower_bound += precision;
	}
	std::cout << "Lower bound: " << -lower_bound << std::endl;
	return std::pair<double, double>(-lower_bound, upper_bound);
}


bool ValueCalculation::UpperFinder(std::deque<double>& polynominal, double i)
{
	double beta = polynominal[0];

	// Iterating over polynominal with constant iterator because it's read only
	for (auto it = polynominal.cbegin() + 1; it != polynominal.cend(); ++it)
	{
		// New value is value times x plus value at it
		beta = i * beta + *it;

		if (beta < 0)
		{
			return false;
		}
	}

	return true;

}


bool ValueCalculation::LowerFinder(std::deque<double> cpy, double i)
{
	int degree = cpy.size()-1;
	double alpha;

	// Invert every second term [considering (-1)^n and Wn(-x)]
	for (auto it = cpy.begin() + 1; it < cpy.end()-1; it+=2)
	{
		*it = -*it;
	}

	alpha = cpy[0];
	for (int it = 1; it < degree; it++)
	{

		alpha = alpha * i + cpy[it];

		if (alpha < 0)
		{
			return false;  // Not right
		}

	}
	
	return true;
}


double ValueCalculation::TylorMethod_e(double x, int n)
{
	/// Summary:
	/// An implementation of the Tylor serie of the function exponent of x with 
	/// 
	/// x - choosen x value for the function
	/// n - number of iteration
	/// result - The value of the function at given x with after given number of iterations
	

	double result = 1;
	double factorial = 1;
	double x_calculation = 1;

	for (int i = 1; i < n + 1; i++) 
	{
		// Implementation of the formula for Tylor series of exp(x) 
		// with the power and factorial functions calculated dynamically
		x_calculation = x_calculation * x;
		factorial = factorial * i;
		result = result + x_calculation / factorial;

		// Showing the result at every iteration
		std::cout << "Iteration " << i << ": " << result << std::endl;
	}

	std::cout << "Result of exp(x) at x = " << x << " is: \e[4m" <<  result << "\e[0m" << std::endl;
	return result;
}


double ValueCalculation::TylorMethod_e(double x, double precision=0.001)
{
	/// Summary:
	/// An implementation of the Tylor serie of the function exponent of x with 
	/// 
	/// x - choosen x value for the function
	/// precision - the desired precision
	/// result - The value of the function at given x with given precision
	
	
	double result = 1;
	double factorial = 1;
	double x_calculation = 1;
	double temp;
	int i = 1;

	while(true)
	{
		// Implementation of the formula for Tylor series of exp(x) 
		// with the power and factorial functions calculated dynamically
		
		x_calculation = x_calculation * x;
		factorial = factorial * i;
		temp = result + x_calculation / factorial;		

		// Checking if delta is smaller than desired precision
		if (std::abs(temp - result) < precision)
		{
			result = temp;
			break;
		}
		else
		{
			result = temp;
		}

		// Showing the result at every iteration
		std::cout << "Iteration " << i << ": " << result << std::endl;
		i++;
	}

	std::cout << "Result of exp(x) at x = " << x << " is: \e[4m" << result << "\e[0m, after " << i << " iterations\n" << std::endl;
	return result;
}


std::deque<double> ValueCalculation::genereate_powers(int power, double x)
{
	double value = 1;
	std::deque<double> memory_powers;
	memory_powers.resize(power+1);

	// Iterating over polynominal with constant iterator because it's read only
	for (int i = 1; i < power; i++)
	{
		// New value is value times x
		value = value * x;
		memory_powers.push_front(value);
		std::cout << value << std::endl;
	}

	memory_powers.shrink_to_fit();
	return memory_powers;
}
