#pragma once
#include <vector>
#include "Moneda.h"
#include "Produs.h"
#include "RepoSTL.h"
class Tests
{
	RepoSTL<Produs> repo_produse;
	RepoSTL<Moneda> repo_monede;
	vector<Produs> vector_produse;
	vector<Moneda> vector_moneda;

private:

	void test_get_all();
	void test_get_all_produse();
	void test_get_all_monede();


	void test_add_elem();
	void test_add_produs();
	void test_add_moneda();

	void test_update();
	void test_switch_by_position();


	void test_delete_obj();

	void test_products_gets();
	void test_products_sets();

	void moneda_gets();
	void moneda_sets();
	void moneda_operatori();

	void test_repo_load_file();
	void test_repo_load_to_file_produse();
	void test_repo_load_to_file_monede();



	void test_RepoSTL();
	void test_product();
	void test_moneda();
public:
	void test();
	Tests();




};