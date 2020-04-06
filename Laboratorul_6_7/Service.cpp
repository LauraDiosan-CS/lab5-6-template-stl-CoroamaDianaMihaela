#include "Service.h"
#include "RepoSTL.h"

Service::Service()
{
	this->repo_produse = RepoSTL<Produs>();
	this->repo_moneda = RepoSTL<Moneda>();
	this->bani_introdusi.clear();
}

Service::Service(RepoSTL<Produs> repo_produse, RepoSTL<Moneda> repo_moneda, map<int, int> bani_introdusi)
{
	this->repo_produse = repo_produse;
	this->repo_moneda = repo_moneda;
	this->bani_introdusi = bani_introdusi;
}

Service::Service(const Service& s)
{
	this->repo_moneda = s.repo_moneda;
	this->repo_produse = s.repo_produse;
	this->bani_introdusi = s.bani_introdusi;

}

Service::~Service()
{
	this->bani_introdusi.clear();
}

void Service::clear()
{
	this->bani_introdusi.clear();
}




void Service::add_moneda(int moneda)
{
	if (this->bani_introdusi[moneda] >= 1)
	{
		this->bani_introdusi[moneda] += 1;
	}
	else
		this->bani_introdusi[moneda] = 1;

}

Produs Service::get_produs_by_cod(int cod)
{
	vector<Produs> produse = this->repo_produse.get_all();

	int i = 0;
	for (int i = 0; i < produse.size(); i++)
		if (produse[i].get_code() == cod)
			return produse[i];
	return Produs();

}






vector<Produs> Service::get_all_produse()
{
	return this->repo_produse.get_all();
}

vector<Moneda> Service::get_all_monede()
{
	return this->repo_moneda.get_all();
}

map<int, int> Service::get_monedele_tale()
{
	return this->bani_introdusi;
}




int Service::transaction(int moneda, int cod)
{
	this->add_moneda(moneda);
	Produs produs = this->get_produs_by_cod(cod);
	int rest = this->calculate_rest(produs.get_price());
	if (rest < 0)
		return -1;
	if (this->can_it_give_rest(rest))
	{
		this->give_rest(produs.get_price());
		this->delete_monede(rest);
		this->bani_introdusi.clear();
		this->descrescator();
		this->repo_moneda.save_to_file();
		return 1;
	}
	else
		return 0;

}




void Service::give_rest(int cost)
{

	for (const auto& x : this->bani_introdusi)
	{
		int i = 0;
		int numar = x.second;
		int valoare = x.first;
		Moneda moneda(x.second, x.first);

		while (i < numar)
		{

			i++;
			this->bani_introdusi[valoare] -= 1;
			Moneda moneda_pt_update = this->get_moneda_by_valoare(valoare);
			if (!(moneda_pt_update == Moneda()))
			{

				this->repo_moneda.update(moneda_pt_update, Moneda(moneda_pt_update.get_numar() + 1, valoare));
			}
			else
				this->repo_moneda.add_element(Moneda(1, valoare));

		}
	}

}

bool Service::can_it_give_rest(int rest)
{
	int rest_2 = rest;
	vector<Moneda> monede = this->get_all_monede();
	for (int i = 0; i < monede.size(); i++)
		while (rest >= monede[i].get_valoare() && monede[i].get_numar() > 0)
		{
			rest -= monede[i].get_valoare();


		}
	if (rest > 0)
		return false;
	else
		return true;


}

Moneda Service::get_moneda_by_valoare(int valoare)
{
	vector<Moneda> monede = this->repo_moneda.get_all();

	int i = 0;
	for (int i = 0; i < monede.size(); i++)
		if (monede[i].get_valoare() == valoare)
			return monede[i];
	return Moneda();
}

int Service::calculate_rest(int cost_produs)
{
	int sum = 0;
	for (const auto& x : this->bani_introdusi)
	{
		int i = 0;
		int numar = x.second;
		int valoare = x.first;
		sum += x.first * x.second;
	}
	return sum - cost_produs;
}

void Service::scadere_stergere_moneda(int valoare)
{
	Moneda moneda;
	int numar = 0;
	for (int i = 0; i < this->repo_moneda.get_all().size(); i++)
		if (this->repo_moneda.get_all()[i].get_valoare() == valoare)
		{
			moneda = this->repo_moneda.get_at_position(i);
			numar = moneda.get_numar();
			this->repo_moneda.update(moneda, Moneda(numar - 1, moneda.get_valoare()));
			moneda = this->repo_moneda.get_at_position(i);
			if (this->repo_moneda.get_all()[i].get_numar() == 0)
			{
				this->repo_moneda.delete_obj(moneda);
			}
		}

}

void Service::delete_monede(int rest)
{
	/*Imi scade numarul de monezi folosite pentru a da rest si in cazul in care numarul acest e 0 il sterge din vector*/
	vector<Moneda> monede = this->get_all_monede();
	for (int i = 0; i < monede.size(); i++)
		while (rest >= monede[i].get_valoare() && monede[i].get_numar() > 0)
		{
			rest -= monede[i].get_valoare();
			this->add_moneda(monede[i].get_valoare());
			this->scadere_stergere_moneda(monede[i].get_valoare());

		}

}

void Service::descrescator()
{
	int size = this->repo_moneda.get_all().size();
	Moneda temp = Moneda();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (this->repo_moneda.get_all()[i].get_valoare() < this->repo_moneda.get_all()[j].get_valoare())
			{
				this->repo_moneda.switch_position(i, j);
			}
		}
	}
	this->repo_moneda.save_to_file();

}
