#include "Produs.h"
#include <string.h>




//bool Produs:: AreSame(int a,int b)
//	double epsilon = 00000.1;
//	return abs(b - a) < epsilon;
//}

Produs::Produs()
{
	this->code = 0;
	this->name = NULL;
	this->price = 0;
}

Produs::Produs(int code, char* name, int price)
{
	this->code = code;

	this->price = price;
	
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Produs::Produs(const Produs& p)
{
	this->code = p.code;

	this->price = p.price;

	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, strlen(p.name) + 1, p.name);

}

Produs::~Produs()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	
}


char* Produs::get_name()
{
	return this->name;
}

int Produs::get_code()
{
	return this->code;
}

int Produs::get_price()
{
	return this->price;
}


void Produs::set_name(char* new_name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
	}
	if (new_name != NULL)
	{
		this->name = new char[strlen(new_name) + 1];
		strcpy_s(this->name, strlen(new_name) + 1, new_name);
	}
	else
		this->name = NULL;
}

void Produs::set_code(int new_code)
{
	this->code = new_code;

}

void Produs::set_price(int new_price)
{
	this->price = new_price;
}



Produs& Produs::operator=(const Produs& p)
{	
	this->set_code(p.code);
	this->set_name(p.name);
	this->set_price(p.price);
	return *this;
}

bool Produs::operator==(const Produs& p)
{
	return this->code == p.code && strcmp(this->name, p.name) == 0 && this->price == p.price;
}

ostream& operator<<(ostream& os, const Produs& s)
{
	 os << s.code << "  "<< s.name <<"  " << s.price<<endl;
	 return os;
}

istream& operator>>(istream& is, Produs& p) {
	if (p.name == NULL)
		p.name = new char[20];
	is >> p.code >> p.name >> p.price;
	return is;
}
