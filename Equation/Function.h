#pragma once
#include "Variable.h"

//This class represents a mathematical function.
class Function
{
private:
	Variable* F_var;
	int size;
public:
	Function();
	~Function();
     Function(const Function&);
	Function& operator+=(const Variable&);
	Function& operator-=(const int);
	friend ostream& operator<<(ostream&, const Function&);
	Function operator+(const Function&);
	Function& operator-(const Function&);
	Function& operator*(const Function&);
	Function& operator*(const double);
	Function& operator=(const Function&);
	bool operator==(const Function&)const;
	Variable operator[](const int)const;
	Variable* get_F_var();
	double operator()(const char*,const double*);
	void  F_shot();
	int getsizeF_var();
	
};

