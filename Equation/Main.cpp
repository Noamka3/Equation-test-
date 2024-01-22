#include "LinearEquation.h"
/*
**Job number 3 **
* 
* Name:Noam
* id:207328428
* 
*/

bool PossibleSingleSolution(LinearEquation*,int);

int main()
{
Variable v[][3] = { {Variable("", 4.5), Variable("x", 7.2), Variable("y",1)},
{Variable("x", 2.5), Variable("y", 3.2), Variable("z", 4)},
{Variable("",2.1), Variable("y",3.6), Variable("z", 5.5)}};
cout << "Variable:" << endl;//Variable
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << v[i][j] <<  " ";
	cout << endl<<endl;
	cout << "Function:" << endl<<endl;
	Function f[3]; //	Function
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			f[i] += v[i][j];
	for (int i = 0; i < 3; i++)
	{
		f[i].F_shot();
		cout << "f" << i + 1 << ": " << f[i] << endl;
	}
	cout << endl;
	LinearEquation eq[] = { LinearEquation(f[0]),LinearEquation(f[1]),LinearEquation(f[2]) };//LinearEquation
	cout << "Linear:" << endl<<endl;
	for (int i = 0; i < 3; i++)
	{	
		cout << "eq" << i + 1 << ": " << eq[i] << endl;
	}

	cout << "is there a chance for a single solution?(yes/no):"; //test // true or false.

	if (PossibleSingleSolution(eq, 3))
	{
		cout << "yes" << endl;
	}
	else { cout << "No" << endl; };
	
}

