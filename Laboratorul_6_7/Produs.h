#pragma once
#include <iostream>
using namespace std;

class Produs
{	
private:
	
	int  code;
	char* name;
	int price;

	/*bool AreSame(int a, int b);*/
public:
	Produs();
	Produs(int code, char* name, int price);
	Produs(const Produs& p);
	~Produs();

	char* get_name();
	int get_code();
	int get_price();

	void set_name(char* new_name);
	void set_code(int code);
	void set_price(int new_price);

	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);

	friend ostream& operator<<(ostream& os, const Produs& s);

	friend istream& operator>>(istream& is,Produs& s);
};