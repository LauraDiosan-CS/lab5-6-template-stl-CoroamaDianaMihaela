#include "RepoSTL.h"
#include "Produs.h"
#include <iostream>
#include "Tests.h"
#include "RepoSTL.h"
#include "Moneda.h"
#include "Service.h"
#include "Console.h"
using namespace std;


int main()
{
	Tests test;
	test.test();
	cout << "/--------------------------------------" << endl;
	cout << "Testele functioneaza" << endl;
	cout << "/--------------------------------------" << endl;
	cout << endl;
	RepoSTL<Produs> repo_produs("Produse.txt");
	RepoSTL<Moneda> repo_moneda("Moneda.txt");
	map<int, int> bani_introdusi;
	Service service(repo_produs, repo_moneda, bani_introdusi);
	Console c(service);
	c.run();
	
}