#include "Console.h"
#include "Produs.h"
#include "Repo.h"
#include <iostream>

Console::Console(const Service& s)
{
	this->service = Service();
	this->service = s;
}


void Console::menu()
{
	cout << "1.Afisati produsele" << endl;
	cout << "2.Afisati monedele din tonomat" << endl;
	cout << "3.Introduceti moneda si alegeti produsul" << endl;
	cout << "x.Exit the program" << endl;
}

int Console::run()
{
	char op;
	while (true)
	{
		this->menu();
		cout << "Introduceti optiunea: " << endl;
		op = read_char();
		if (op == '1')
		{
			this->show_produse();
		}
		else if (op == '2')
		{
			this->show_monede();
		}
		else if (op == '3')
		{
			this->try_to_buy();
		}
		else
			return 0;
	}
}



int Console::read_int()
{
	int a;
	cin >> a;
	return a;
}

char Console::read_char()
{
	cout << "Enter option: ";
	char a;
	cin >> a;
	return a;
}



void Console::show_produse()
{
	vector<Produs> produse = this->service.get_all_produse();
	this->show(produse);
}

void Console::show_monede()
{
	vector<Moneda> monede = this->service.get_all_monede();
	this->show(monede);

}

void Console::show_monedele_tale()
{	
	map<int,int> bani_introdusi = this->service.get_monedele_tale();
	for (map<int, int>::iterator it = bani_introdusi.begin(); it != bani_introdusi.end(); ++it) {
		{
			cout << "Valoarea monedei: "<<it->first << " Cate monede sunt:  " << it->second << '\n';
			
		}
	}
}


void Console::try_to_buy()
{
	cout << "Introduceti o moneda: " << endl;
	int moneda = read_int();
	cout << "Introduceti codul produsul pe care vreti sa il achizitionati: " << endl;
	int cod = read_int();
	int rezultat = this->service.transaction(moneda, cod);
	if (rezultat==1)
	{
		cout << "Produsul a fost achitionat si restul v-a fost dat" << endl;
		
	}
	else
	{	if(rezultat==-1)
			cout << "Produsul nu a putut fi achizitionat deoarece nu ati introdus destul" << endl;
		else
			cout << "Din pacare nu avem cum sa va dam rest" << endl;
		cout << "/-----------------------------------------------------" << endl;
		cout << endl;
		cout << "Doriti sa introduceti inca o bancnota si sa incercati din nou?(y/n)" << endl;
		cout << "Daca alegeti nu banii dumneavoastra vor fi returnati" << endl;
		cout << endl;
		cout << "/----------------------------------------------------" << endl;
		cout << endl;
		char op = read_char();
		if (op == 'y')
		{
			this->try_to_buy();
		
		}
		else
			this->service.clear();

	}


}
