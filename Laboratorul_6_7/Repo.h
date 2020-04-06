#pragma once
#include <vector>
using namespace std;

template <class T>
class Repo
{
protected:
	vector<T> elem;

public:
	//default
	Repo() {};

	//destructor
	~Repo()
	{
		this->elem.clear();
	};

	void add_element(T param)
	{	
		this->elem.push_back(param);
	}

	bool element_in_repo(T param)
	{
		for (int i = 0; i < this->elem.size(); i++)
			if (this->elem[i] == param)
				return true;
		return false;
	}
	
	//void clear()
	//{
	//	this->elem.clear();
	//}
	vector<T> get_all()
	{
		return this->elem;
	}

	void delete_last_obj()
	{
		this->elem.pop_back();

	}

	T get_at_position(int position) {
		return this->elem[position];
	}

	/*void update(T old, T new_t)
	{
		vector<T>::iterator it;
		it = find(this->elem.begin(), this->elem.end(), old);
		if (!(it == this->elem.end())) {
			*it = new_t;

		}

	}*/

	
};

