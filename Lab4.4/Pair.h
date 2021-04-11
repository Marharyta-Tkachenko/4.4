#pragma once
#pragma pack(1)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Pair
{
private: 
	double a;
	double b;
public:
	double GetA() const;
	double GetB() const;

	void SetA(double);
	void SetB(double);

	Pair();
	Pair(double a, double b);
	Pair(const Pair& v);

	virtual Pair* operator = (Pair* r) = 0;
	virtual Pair* operator + (Pair* Z) = 0;
	virtual Pair* operator - (Pair* Z) = 0;
	virtual Pair* operator * (Pair* Z) = 0;
	virtual Pair* operator / (Pair* Z) = 0;

	virtual ostream& Print(ostream& out) const = 0;
	virtual istream& Insert(istream& in) = 0;
};

