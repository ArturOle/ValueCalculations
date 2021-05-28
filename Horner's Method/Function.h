#pragma once
class Function
{
public:
	Function() = default;

	virtual double eval_func() = 0;
};

class Exponential : public Function
{
	double x;
public:
	Exponential(double x_in);

	double eval_func() override;
};