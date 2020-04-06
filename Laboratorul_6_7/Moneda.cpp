#include "Moneda.h"
#include <string.h>

Moneda::Moneda()
{
	this->numar = 0;
	this->valoare = 0;
}

Moneda::Moneda(int numar, int valoare)
{
	this->numar = numar;
	this->valoare = valoare;
}

Moneda::Moneda(const Moneda& m)
{	
	this->valoare=m.valoare;
	this->numar = m.numar;
}


Moneda::~Moneda()
{
	this->numar = 0;
	this->valoare = 0;
}

int Moneda::get_numar()
{
	return this->numar;
}

int Moneda::get_valoare()
{
	return this->valoare;
}

void Moneda::set_numar(int numar)
{
	this->numar = numar;
	
}

bool Moneda::operator==(const Moneda& m)
{
	return this->numar == m.numar && this->valoare == m.valoare;
}

Moneda& Moneda::operator=(const Moneda& m)
{
	this->set_numar(m.numar);
	this->valoare = m.valoare;
	return*this;
}

ostream& operator<<(ostream& os, const Moneda& m)
{
	os << m.numar <<" "<< m.valoare<<endl;
	return os;
}

istream& operator>>(istream& is, Moneda& m)
{
	is >> m.numar >> m.valoare;
	return is;
}