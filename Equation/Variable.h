#pragma once
#include <iostream>
#include <string>
using namespace std;

class Variable
{
private:
	string variable;
	double coefficient;

public:
	//constructor//Distractor.
	Variable(const string = "", double = 0.0);
	Variable(const Variable&);
	~Variable();

    void Set_variable(const string&);
	
	void set_coefficient(const double);
	string get_variable()const;
	double get_coefficient()const;
	
	//operator +,-,*

	Variable operator+(const Variable&)const;
	Variable operator-(const Variable&)const;
	Variable operator*(const Variable&)const;
	Variable operator*(const double) const;

	//operator +=,-=,*=
	//Moving the object itself and changing
	Variable& operator+=(const Variable&);
	Variable& operator-=(const Variable&);
	Variable operator*=(const Variable&);
	Variable& operator*=(const double);
	void operator=(const Variable&);
	bool operator==(const Variable&)const;
	Variable operator()(const char* ,const double*);
	friend ostream& operator<<(ostream&,const Variable&);
	void shot();
};

