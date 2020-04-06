#include "Tests.h"
#include <cassert>


Tests::Tests()
{
	this->repo_produse.set_filename("Produse_test.txt");
	this->repo_produse.load_to_file();
	this->repo_monede.set_filename("Monede_test.txt");
	this->repo_monede.load_to_file();

}


void Tests::test()
{
	this->test_RepoSTL();
	this->test_product();
	this->test_moneda();
}


void Tests::test_RepoSTL()
{


	this->test_add_elem();
	this->test_repo_load_file();
	this->test_update();
	this->test_switch_by_position();
	this->test_delete_obj();
}




void Tests::test_product()
{
	this->test_products_gets();
	this->test_products_sets();

}

void Tests::test_moneda()
{
	this->moneda_gets();
	this->moneda_sets();
	this->moneda_operatori();

}



void Tests::test_get_all()
{
	this->test_get_all_monede();
	this->test_get_all_produse();
}

void Tests::test_get_all_monede()
{	
	Moneda m1(4, 15);
	Moneda m2(3, 10);
	Moneda m3(2, 5);
	Moneda m4(1, 1);

	int n = this->repo_monede.get_all().size();

	assert(this->repo_monede.get_all()[0] == m1);
	assert(this->repo_monede.get_all()[1] == m2);
	assert(this->repo_monede.get_all()[2] == m3);
	assert(this->repo_monede.get_all()[3] == m4);
	
}

void Tests::test_get_all_produse()
{	

	char* name = new char[1 + strlen("Masina")];
	strcpy_s(name, 1 + strlen("Masina"), "Masina");
	Produs Produs_1 = Produs(3, name, 20);


	char* name_2 = new char[1 + strlen("Jucarie")];
	strcpy_s(name_2, 1 + strlen("Jucarie"), "Jucarie");
	Produs Produs_2 = Produs(4, name_2, 25);





	assert(this->repo_produse.get_all()[0] == Produs_1);
	assert(this->repo_produse.get_all()[1] == Produs_2);

	delete[] name;
	delete[] name_2;
	
}



void Tests::test_add_elem()
{
	this->test_add_moneda();
	this->test_add_produs();
	
}

void Tests::test_add_produs()
{
	RepoSTL<Produs> r = RepoSTL<Produs>();

	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	r.add_element(Produs_1);

	assert(r.get_all()[0] == Produs_1);


	delete[] name;

}

void Tests::test_add_moneda()
{
	RepoSTL< Moneda > monede= RepoSTL<Moneda>();
	Moneda m1(1, 4);
	monede.add_element(m1);
	assert(monede.get_all()[0] == m1);

}



void Tests::test_update()
{
	Moneda m1(4, 15);
	Moneda m2(3, 15);

	this->repo_monede.update(m1, m2);
	assert(this->repo_monede.get_all()[0] == m2);
	this->repo_monede.update(m2, m1);

}

void Tests::test_switch_by_position()
{
	Moneda m1 = this->repo_monede.get_all()[0];
	Moneda m2 = this->repo_monede.get_all()[1];
	this->repo_monede.switch_position(0,1);
	assert(this->repo_monede.get_all()[0] == m2);
	this->repo_monede.switch_position(0, 1);
}



void Tests::test_delete_obj()
{
	int size = this->repo_monede.get_all().size();

	Moneda m1(1, 4);
	this->repo_monede.add_element(m1);
	
	assert(this->repo_monede.get_all().size() == size + 1);

	this->repo_monede.delete_obj(m1);

	assert(this->repo_monede.get_all().size() == size);
	

}



void Tests::test_repo_load_file()
{
	this->test_repo_load_to_file_monede();
	this->test_repo_load_to_file_produse();
}

void Tests::test_repo_load_to_file_monede()
{
	Moneda m1(4, 15);
	Moneda m2(3, 10);
	Moneda m3(2,5);
	Moneda m4(1, 1);
	this->vector_moneda.push_back(m1);
	this->vector_moneda.push_back(m2);
	this->vector_moneda.push_back(m3);
	this->vector_moneda.push_back(m4);

	int n = this->repo_monede.get_all().size();

	for (int i = 0; i < n; i++) 
	{
		assert(this->repo_monede.get_all()[i] == this->vector_moneda[i]);
	}
}

void Tests::test_repo_load_to_file_produse()
{
	char* name = new char[1 + strlen("Masina")];
	strcpy_s(name, 1 + strlen("Masina"), "Masina");
	Produs Produs_1 = Produs(3, name, 20);

	this->vector_produse.push_back(Produs_1);

	char* name_2= new char[1 + strlen("Jucarie")];
	strcpy_s(name_2, 1 + strlen("Jucarie"), "Jucarie");
	Produs Produs_2 = Produs(4, name_2, 25);


	this->vector_produse.push_back(Produs_2);
	
	int n = this->repo_produse.get_all().size();

	for (int i = 0; i < n; i++)
	{
		assert(this->repo_produse.get_all()[i] == this->vector_produse[i]);
	}
	delete[] name;
	delete[] name_2;

}





void Tests::test_products_gets()
{
	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	assert(Produs_1.get_code() == 23);
	assert(strcmp(Produs_1.get_name(), name) == 0);
	assert(Produs_1.get_price() == 25);

	delete[] name;
}

void Tests::test_products_sets()
{
	char* name = new char[1 + strlen("nume")];
	strcpy_s(name, 1 + strlen("nume"), "nume");
	Produs Produs_1 = Produs(23, name, 25);

	char* name_2 = new char[1 + strlen("nume_2")];
	strcpy_s(name_2, 1 + strlen("nume_2"), "nume_2");

	Produs_1.set_code(24);
	Produs_1.set_name(name_2);
	Produs_1.set_price(45);


	assert(Produs_1.get_code() == 24);
	assert(strcmp(Produs_1.get_name(), name_2) == 0);
	assert(Produs_1.get_price() == 45);

	delete[] name;
	delete[] name_2;
}



void Tests::moneda_gets()
{
	Moneda m1(1,5);
	assert(m1.get_valoare() == 5);
	assert(m1.get_numar() == 1);
}

void Tests::moneda_sets()
{
	Moneda m1(1, 5);
	m1.set_numar(2);
	assert(m1.get_valoare() == 5);
	assert(m1.get_numar() == 2);
}

void Tests::moneda_operatori()
{
	Moneda m1(1, 5);
	Moneda m2(2, 4);
	Moneda m3(1, 2);

	assert(!(m1 == m2));
	m3 = m2;
	assert(m3 == m2);

}
