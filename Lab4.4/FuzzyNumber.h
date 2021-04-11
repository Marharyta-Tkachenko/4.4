#pragma once
#include "Pair.h"

class FuzzyNumber :public Pair
{
private:
	double x;

public:
	FuzzyNumber();
	FuzzyNumber(double a, double b, double x);
	FuzzyNumber(const FuzzyNumber& v);

	double GetX() const { return x; }
	void SetX(double value) { x = value; }

	virtual FuzzyNumber* operator = (Pair* r);

	virtual FuzzyNumber* operator + (Pair* Z);
	virtual FuzzyNumber* operator - (Pair* Z);
	virtual FuzzyNumber* operator * (Pair* Z);
	virtual FuzzyNumber* operator / (Pair* Z);
	friend FuzzyNumber operator / (int a, const FuzzyNumber Z);

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};
