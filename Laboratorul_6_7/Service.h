#pragma once
#include "RepoSTL.h"
#include "Moneda.h"
#include <map>
class Service
{
private:
	RepoSTL<Produs> repo_produse;
	RepoSTL<Moneda> repo_moneda;
	map<int, int> bani_introdusi;
public:
	Service();
	Service(RepoSTL<Produs> repo_service, RepoSTL<Moneda> repo_moneda, map<int, int> bani_introdusi);
	Service(const Service& s);
	~Service();

	void add_moneda(int moneda);
	Produs get_produs_by_cod(int cod);
	void scadere_stergere_moneda(int moneda);

	
	vector<Produs> get_all_produse();
	vector<Moneda> get_all_monede();
	map<int, int> get_monedele_tale();


	int transaction(int moneda, int cod);
	bool can_it_give_rest(int rest);
	int calculate_rest(int pret);

	
	void delete_monede(int rest);
	void give_rest(int cost);
	void clear();


	void descrescator();
	Moneda get_moneda_by_valoare(int valoare);
	void erase_moneda(Moneda moneda);

};