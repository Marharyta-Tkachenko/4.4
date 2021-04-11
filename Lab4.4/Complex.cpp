#include "Complex.h"

Complex::Complex()
	: Pair()
{}

Complex::Complex(double x, double y)
	: Pair(x, y)
{}

Complex::Complex(const Complex& v)
	: Pair(v)
{}

Complex* Complex::operator = (Pair* r)
{
	this->SetA(r->GetA());
	this->SetB(r->GetB());
	return this;
}

Complex* Complex::operator + (Pair* Z)
{
	Complex* T = new Complex();
	T->SetA(this->GetA() + ((Complex*)Z)->GetA());
	T->SetB(this->GetB() + ((Complex*)Z)->GetB());
	return T;
}

Complex* Complex::operator - (Pair* Z)
{
	Complex* T = new Complex();
	T->SetA(this->GetA() - ((Complex*)Z)->GetA());
	T->SetB(this->GetB() - ((Complex*)Z)->GetB());
	return T;
}

Complex* Complex::operator * (Pair* Z)
{
	Complex* T = new Complex();
	T->SetA(this->GetA() * ((Complex*)Z)->GetA() - this->GetB() * ((Complex*)Z)->GetB());
	T->SetB(this->GetA() * ((Complex*)Z)->GetB() + ((Complex*)Z)->GetA() * this->GetB());
	return T;
}

Complex* Complex::operator / (Pair* Z)
{
	Complex* T = new Complex();
	T->SetA((this->GetA() * ((Complex*)Z)->GetA() + this->GetB() * ((Complex*)Z)->GetB()) / (((Complex*)Z)->GetA() * ((Complex*)Z)->GetA() + ((Complex*)Z)->GetB() * ((Complex*)Z)->GetB()));
	T->SetB((((Complex*)Z)->GetA() * this->GetB() - this->GetA() * ((Complex*)Z)->GetB()) / (((Complex*)Z)->GetA() * ((Complex*)Z)->GetA() + ((Complex*)Z)->GetB() * ((Complex*)Z)->GetB()));
	return T;
}

bool operator == (Complex Z1, Complex Z2)
{
	return (Z1.GetA() == Z2.GetA()) && (Z1.GetB() == Z2.GetB());
}

Complex& Complex::Conj()
{
	this->SetB(-this->GetB());
	return *this;
}

ostream& Complex::Print(ostream& out) const
{
	out << GetA() << " + i * " << GetB() << endl;
	return out;
}

istream& Complex::Insert(istream& in)
{
	double x, y;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;
	this->SetA(x); this->SetB(y);
	return in;
}