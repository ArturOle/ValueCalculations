#include "ValueCalculation.h"


double ValueCalculation::HornerMethod(std::deque<double> &polynominal, int x)
{
    /// <summary>
    ///     The implementation of Horner method of calculating value of the polynominal.
    ///     Horner approach reduces complexity of calculating polunominals from O(n^2) to just O(n).
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

    std::cout << result << std::endl;

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

    std::cout << result << std::endl;

    return result;
}


std::pair<double, double> ValueCalculation::HornerRange(std::deque<double>& polynominal, int x, float precision)
{
    double lower_bound = 0;
    double upper_bound = precision;

    while (true)
    {
        double beta;

        beta = UpperFinder(polynominal, upper_bound);

        if (beta > 0)
        {
            break;
        }

        upper_bound += precision;
    }
    std::cout << upper_bound << std::endl;

    lower_bound = upper_bound-1;

    while (true)
    {
        double value;

        value = LowerFinder(polynominal, lower_bound);
        if (value > 0)
        {
            break;
        }

        lower_bound -= precision;
    }
    std::cout << lower_bound << std::endl;
    return std::pair<double, double>(lower_bound, upper_bound);
}


double ValueCalculation::UpperFinder(std::deque<double>& polynominal, double i)
{
    double beta = polynominal[0];
    int degree = polynominal.size() - 1;

    // Iterating over polynominal with constant iterator because it's read only
    for (int it = 1; it < degree; it++)
    {
        // New value is value times x plus value at it
        beta =  i*beta + polynominal[it];

        if (beta < 0)
        {
            return -1;
        }
    }

    return i;

}


double ValueCalculation::LowerFinder(std::deque<double>& polynominal, double i)
{
    int degree = polynominal.size()-1;
    double alfa;
    std::deque<double> cpy = polynominal;

    if (degree % 2) 
    {
         for (int it = 0; it < degree; it++)
         {
             cpy[it] = -polynominal[it];
         }
    }

    alfa = cpy[0];
    for (int it = degree-1; it > 1; it--)
    {

        if (it % 2)
        {
            value =  (i) + cpy[it];
        }
        else
        {
            value = -i + cpy[it];
        }

        if (value < 0)
        {
            return -1;  // Not right
        }

    }
    
    return i;
}


double ValueCalculation::TylorMethod(std::deque<double>& polynominal, int x, int n)
{
    double result = 0;

    for (int i = 0; i < n; i++) 
    {
        result = result;
    }

    return 0.0;
}
