#pragma once
#include "Service.h"
class Console
{
	Service service;
public:
	Console(const Service& s);
	void menu();
	int run();
	
	int read_int();
	char read_char();
	template <typename B>
	void show(vector<B> obiecte)
	{
		for (int i = 0; i < obiecte.size(); i++)
			cout << obiecte[i];

	};

	void show_produse();
	void show_monede();
	void show_monedele_tale();
	void try_to_buy();


};
