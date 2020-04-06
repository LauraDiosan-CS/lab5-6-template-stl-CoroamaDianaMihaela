#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Moneda
{
private:
	int numar;
	int valoare;
public:
	Moneda();
	Moneda(int numar, int valoare);
	Moneda(const Moneda& m);
	~Moneda();

	int get_numar();
	int get_valoare();

	void set_numar(int numar);
	
	bool operator==(const Moneda& m);
	Moneda& operator=(const Moneda& m);
	friend ostream& operator<<(ostream& os, const Moneda& m);
	friend istream& operator>>(istream& is, Moneda& m);
};