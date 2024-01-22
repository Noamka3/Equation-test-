#include "LinearEquation.h"

LinearEquation::LinearEquation(Function F_var) : L_variable(F_var), result(0)
{
	for (int i = 0; i < F_var.getsizeF_var(); i++)
	{
		if (F_var[i].get_variable().length() > 1 && F_var[i].get_variable() != "")
		{
			cout << "EROR:Cannot be converted to a Linear function" << endl;
			exit(1);
		}
		//Inserting values ??into the result (free number)
			if (F_var.get_F_var()[i].get_variable() == "") 
			{
				if (F_var.get_F_var()[i].get_coefficient() > 0)
				{
					this->result -= F_var[i].get_coefficient();
				
				}
				if (F_var.get_F_var()[i].get_coefficient() < 0)
				{
					this->result += F_var[i].get_coefficient()*-1;
					
				}
				L_variable -= i;
			}

		
	}


}
//output
ostream& operator<<(ostream& output , const LinearEquation& L)
{
	
	output << L.L_variable << "=" << L.result << endl;

	return  output;
	

}
//operstor+
LinearEquation& LinearEquation::operator+(LinearEquation& other)
{

		for (int i = 0; i < other.L_variable.getsizeF_var(); i++)
		{
			this->L_variable.operator+=(other.L_variable.get_F_var()[i]);//use funch operator+=.
			result += other.result;
		}
    

	return *this;
}	
//operstor-
LinearEquation LinearEquation::operator-(LinearEquation& other)
{

	Function temp = this->L_variable - other.L_variable;
	double temp_result = result - other.result;
	LinearEquation tempL(temp);//use funch operator+=.
	tempL.result = temp_result;

	return tempL;
}

bool PossibleSingleSolution(LinearEquation* arr_Linear, int arr_size)
{
	//A function that sums functions and checks if the
	//amount of variables is less than or equal to the check of a single solution
	//and returns true or false
	Function temp;
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_Linear[i].L_variable.getsizeF_var(); j++)
		{
			temp.operator+=(arr_Linear[i].L_variable[j]);
		
		}


	}
	
	if (temp.getsizeF_var() > arr_size)
	{
		return false;
	}
	else { return true; }

}

