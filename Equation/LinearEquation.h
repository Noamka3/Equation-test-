#include "Function.h"

//represents a linear equation
class LinearEquation
{
private:
	Function L_variable;
	double result;

public:
	LinearEquation(Function);
	friend ostream& operator<<(ostream&, const LinearEquation&);//constructor
	LinearEquation& operator+(LinearEquation&);
	LinearEquation operator-(LinearEquation&);
	friend bool PossibleSingleSolution(LinearEquation*, int);//A function to use the department's tools
};
