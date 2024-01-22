#include "Variable.h"

//constructor.
Variable::Variable(string variable, double coefficient):variable(variable), coefficient(coefficient){}

Variable::Variable(const Variable& other):variable(other.variable), coefficient(other.coefficient){}
Variable::~Variable()
{


}
//operator+
Variable Variable::operator+(const Variable& other)const
{
	if (this->variable != other.variable)
	{
		cout << "Couldn’t be performed("<<variable<<"!="<<other.variable<<")"<<endl;
		return *this;
	}
	else 
	{
		return Variable(variable, coefficient + other.coefficient);
	}
}
//operator-
Variable Variable::operator-(const Variable& other)const
{
	if (this->variable != other.variable)
	{
		cout << "Couldn’t be performed(" << variable << "!=" << other.variable << ")" << endl;
		return *this;
	}
	else
	{
		return Variable(variable, coefficient - other.coefficient);
	}
}
//operator*
Variable Variable::operator*(const Variable& other)const
{
	return Variable((variable + other.variable), coefficient * other.coefficient);

}
//operator* But of numbers.
Variable Variable::operator*(const double num)const
{
	return Variable(variable, coefficient * num);

}

//operator+=
Variable& Variable::operator+=(const Variable& other)
{
	if (this->variable != other.variable)
	{
		cout << "Variables must have the same name to be added" << endl;
		
	}
		coefficient += other.coefficient;
		return *this;
	
	
}
//operator-=
Variable& Variable::operator-=(const Variable& other)
{
	if (this->variable != other.variable)
	{
		cout << "Variables must have the same name to be added" << endl;
		return *this;
	}
	
	coefficient -= other.coefficient;
	return *this;

}

//operator*=

Variable Variable::operator *=(const Variable& other)
{
	variable = variable+other.variable;
	coefficient = coefficient*other.coefficient;
	return Variable(variable, coefficient);;


}
Variable& Variable::operator*=(const double num)
{
	coefficient = coefficient*num;
	return *this;


}
bool Variable:: operator==(const Variable& other)const
{
	if (variable == other.variable)
	{
		return true;
	}
	return false;
}
void Variable::operator=(const Variable& other)
{
	variable = other.variable;
	coefficient = other.coefficient;
	
}
//Variable value calculation
Variable Variable::operator()(const char* var ,const double* coef)
{
	double sum = coefficient;
	for (int i = 0; i < sizeof(var); i++) 
	{
		for (int j = 0; j < variable.length(); j++)
		{
			if (variable[j] == var[i])
			{
				sum *= coef[i];
			}
	    }
    }

	return Variable("", sum);//
	
}
ostream& operator<<(ostream& output,const Variable& V)
{
//	if (V.coefficient != 0)
	{
	}
		output << V.coefficient << V.variable;
	
		
	
	return output;
}
// method for ordering variables.
void Variable::shot()
{
	char temp;
	for (int i = 0; i < variable.length() - 1; i++) 
	{
		if (variable[i] > variable[i + 1]) 
		{
			temp = variable[i];
			variable[i] = variable[i+ 1];
			variable[i + 1] = temp;

		}
	}
}

//  method set,get 
void Variable::Set_variable(const string& name) 
{
	variable = name;
	
	
}

void Variable::set_coefficient(const double num)
{
	this->coefficient = num;
}
string Variable::get_variable()const { return variable;}
double Variable::get_coefficient()const { return coefficient;};

