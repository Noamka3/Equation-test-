#include "Function.h"
Function::Function() //constructor
{
	size = 0;
	F_var = nullptr;
};
Function::~Function()  //Destroys
{
	delete[]F_var;
}
Function::Function(const Function& copy) :size(copy.size) //copyconstructor
{

  F_var = new Variable[size];
  for (int i = 0; i < size; i++)
  {
	  F_var[i] = copy.F_var[i];
  }
}

//output funch
ostream& operator<<(ostream& output, const Function& F)
{


		output << F.F_var[0];
		
	
	

	if (F.size > 0)
	{
		for (int i = 1; i < F.size; i++)
		{
			if (F.F_var[i].get_coefficient() != 0)
			{

				if (F.F_var[i].get_coefficient() < 0)
				{
					output << F.F_var[i];
				}
				if (F.F_var[i].get_coefficient() > 0)
				{
					
						output << "+";
					
					
					output << F.F_var[i];
				}
				if (F.F_var[i].get_coefficient() == 0)
				{
					cout << " ";
				}
			}
		}
	}
	return output;

}

//add Variable
Function& Function::operator+=(const Variable& other) 
{
	int i;
	int flag = 0;
	

	
		{
			for (int i = 0; i < size; i++)
			{
				if (F_var[i].get_variable() == other.get_variable())
				{
					F_var[i].set_coefficient(F_var[i].get_coefficient() + other.get_coefficient());
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			Variable* temp = new Variable[size + 1]; //add 
			for (int i = 0; i < size; i++) 
			{
			temp[i].Set_variable(F_var[i].get_variable());
			temp[i].set_coefficient(F_var[i].get_coefficient());

			}
			temp[size] = other;

		temp[size].Set_variable(other.get_variable());
	    temp[size].set_coefficient(other.get_coefficient());


		if (F_var != 0)
			delete[]F_var;

		F_var = new Variable[size];
		F_var = temp;
		size++;
		F_shot();

		return *this;
		}

		
	}
Function& Function:: operator-=(const int num)
{
	if (0 <= num) 
	{
		int k = 0;
		Variable* temp = new Variable[size];
		for (int i = 0; i < size; i++)
		{
			if (i != num)
			{
				temp[k].Set_variable(F_var[i].get_variable());
				temp[k].set_coefficient(F_var[i].get_coefficient());
				k++;
			}

		}
		if (F_var) 
			delete[]F_var;
		F_var = new Variable[size-1];
		F_var = temp;
		size--;
		return *this;
    }
	else
	{
		cout << "EROR:Index out of bounds"<<endl;
	}
	return *this;
}
Function Function::operator+(const Function& other)
{

	Function temp;
	for (int i = 0; i <size; i++)
	{

		temp.operator+=(F_var[i]);
	}
	for (int i = 0; i < other.size; i++)
	{

		temp.operator+=(other.F_var[i]);
	}

	return temp;
}
Function& Function::operator-(const Function& other)
{// לחזור על האופרטור הזה !! 
	
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (F_var[i].get_variable() == other.F_var[j].get_variable())
			{
				
		
				F_var[i].set_coefficient(F_var[i].get_coefficient() - other.F_var[j].get_coefficient());

				if (F_var[i].get_coefficient() == 0)
				{
					
					int x = 0;
					Variable* temp = new Variable[size - 1];
					for (int k = 0; k < size; k++) 
					{
						if (F_var[k].get_coefficient() != F_var[i].get_coefficient())
						{
							temp[x] = F_var[k];
							x++;
						}
					}
					if (F_var != 0)
					delete[]F_var;
					F_var = new Variable[size - 1];
					F_var = temp;
					
					//F_var[i].set_coefficient(0);
					//F_var[i].Set_variable("");
					
				}
				
				//F_var[i].Set_variable(F_var[i].get_variable() other.F_var[j].get_variable());
			}

		}
	}
	return *this;
	

}
Function& Function::operator*(const Function& other)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{

			F_var[i].set_coefficient(F_var[i].get_coefficient() * other.F_var[j].get_coefficient());
			F_var[i].Set_variable(F_var[i].get_variable() + other.F_var[j].get_variable());


		}
	}
	F_shot();
	return *this;

}
Function& Function::operator*(const double num)
{
	for (int i = 0; i < size; i++)
	{

			F_var[i].set_coefficient(F_var[i].get_coefficient() * num);

		
	}
	return *this;
}

Function& Function::operator=(const Function& other)
{
	size = other.size;
	delete[]F_var;
	F_var = new Variable[size];
	for (int i = 0; i < size; i++)
	{

		F_var[i].Set_variable(other.F_var[i].get_variable());
		F_var[i].set_coefficient(other.F_var[i].get_coefficient());
			
		
	}
	return *this;
}
bool Function::operator==(const Function& other)const 
{
	if (size == other.size)
	{
		for (int i = 0; i < size; i++)
		{

			if (F_var[i].get_variable() != other.F_var[i].get_variable() && (F_var[i].get_coefficient() != other.F_var[i].get_coefficient()))
			{
				return false;
			}


		}
	
	}
	else 
	{
		return false;
	}
	return true;
}

Variable Function::operator[](const int index)const
{
	if (index >= size|| index < 0) 
	{
		cout << "index out of range" << endl;
		
		exit(1);
    }
	else 
	{
		return F_var[index];
	}
	
}
double Function::operator()(const char* Char, const double* coef)
{
	double sum = 0;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < sizeof(Char); j++) 
		{
			if (F_var[i].get_variable()[0] == Char[j])
			{
				sum += F_var[i].get_coefficient() * coef[j];
			}

		}
	}
	
	return sum;
}

void Function::F_shot()
{
	string temp;
	double temp1;
	for (int i = 0; i < size - 1; i++)
	{
		if (F_var[i].get_variable() > F_var[i+1].get_variable())
		{
			temp = F_var[i].get_variable();
			temp1 = F_var[i].get_coefficient();

			F_var[i].Set_variable(F_var[i + 1].get_variable());
			F_var[i].set_coefficient(F_var[i + 1].get_coefficient());

			F_var[i + 1].Set_variable(temp);
			F_var[i + 1].set_coefficient(temp1);

		}
	}
}
int Function::getsizeF_var()
{
	return size;
}
Variable* Function::get_F_var() 
{
	
	return F_var;
}

