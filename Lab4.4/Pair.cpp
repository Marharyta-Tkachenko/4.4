#include "Pair.h"

double Pair::GetA() const { return a; }
double Pair::GetB() const { return b; }

void Pair::SetA(double a) { this->a = a; }
void Pair::SetB(double b) { this->b = b; }

Pair::Pair()
	: a(0), b(0)
{}

Pair::Pair(double a, double b)
	: a(a), b(b)
{}

Pair::Pair(const Pair& v)
	: a(v.a), b(v.b)
{}

