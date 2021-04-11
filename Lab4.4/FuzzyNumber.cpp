#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	: Pair(), x(0)
{}

FuzzyNumber::FuzzyNumber(double a, double b, double x)
{
	if (x > (x - a) && (x + b) > x)
	{
		SetA(a); SetB(b); SetX(x);
	}
	else
	{
		SetA(0); SetB(0); SetX(0);
	}
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	: Pair(v), x(v.x)
{}

FuzzyNumber* FuzzyNumber::operator = (Pair* r)
{
	this->SetA(r->GetA());
	this->SetB(r->GetB());
	((FuzzyNumber*)this)->SetX(this->GetX());
	return this;
}


FuzzyNumber* FuzzyNumber::operator + (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() + ((FuzzyNumber*)Z)->GetX());
	T->SetA(this->GetX() + ((FuzzyNumber*)Z)->GetX() - this->GetA() - ((FuzzyNumber*)Z)->GetA());
	T->SetB(this->GetX() + ((FuzzyNumber*)Z)->GetX() + this->GetB() + ((FuzzyNumber*)Z)->GetB());
	return T;
}

FuzzyNumber* FuzzyNumber::operator - (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() - ((FuzzyNumber*)Z)->GetX());
	T->SetA(this->GetX() - ((FuzzyNumber*)Z)->GetX() - this->GetA() - ((FuzzyNumber*)Z)->GetA());
	T->SetB(this->GetX() - ((FuzzyNumber*)Z)->GetX() + this->GetB() + ((FuzzyNumber*)Z)->GetB());
	return T;
}

FuzzyNumber* FuzzyNumber::operator * (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() * ((FuzzyNumber*)Z)->GetX());
	T->SetA(this->GetX() * ((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetX() * this->GetA() - this->GetX() * ((FuzzyNumber*)Z)->GetA() - this->GetA() * ((FuzzyNumber*)Z)->GetA());
	T->SetB(this->GetX() * ((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetX() * this->GetB() + this->GetX() * ((FuzzyNumber*)Z)->GetB() + this->GetB() * ((FuzzyNumber*)Z)->GetB());
	return T;
}

FuzzyNumber* FuzzyNumber::operator / (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	if (((FuzzyNumber*)Z)->GetX() > 0 && (((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetB()) > 0 && (((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetA()) > 0)
	{
		T->SetX(this->GetX() / ((FuzzyNumber*)Z)->GetX());
		T->SetA((this->GetX() - this->GetA()) / (((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetB()));
		T->SetB((this->GetX() + this->GetB()) / (((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetA()));
	}
	else
	{
		cout << "FuzzyNumbers can't be divided" << endl;
	}
	return T;
}

FuzzyNumber operator / (int a, const FuzzyNumber Z)
{
	FuzzyNumber T(0, 0, 0);
	T.SetX(a / Z.GetX());
	T.SetA(a / (Z.GetX() + Z.GetB()));
	T.SetB(a / (Z.GetX() - Z.GetA()));
	return T;
}

ostream& FuzzyNumber::Print(ostream& out) const
{
	out << "(" << GetA() << "; " << x << "; " << GetB() << ")" << endl;
	return out;
}

istream& FuzzyNumber::Insert(istream& in)
{
	double x, l, r;
	do
	{
		cout << "x = "; in >> x;
		cout << "l = "; in >> l;
		cout << "r = "; in >> r;
	} while (!(x > (x - l) && (x + r) > x));
	this->SetX(x); this->SetA(l); this->SetB(r);
	return in;
}
