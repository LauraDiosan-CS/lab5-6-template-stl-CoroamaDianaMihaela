#pragma once
#include <fstream>
#include "Repo.h"
#include "Produs.h"
#include <cstddef>
template <class T>

class RepoSTL : public Repo<T>
{
private:
	char* filename;
public:
	

	RepoSTL() : Repo<T>()
	{
		this->filename = NULL;
	}

	RepoSTL(const char* filename)
	{
		this->filename = new char[strlen(filename) + 1];
		strcpy_s(this->filename, strlen(filename)+1,filename);
		this->load_to_file();
		
	}

	~RepoSTL()
	{
		delete[] this->filename;
	}

	RepoSTL(const RepoSTL& repo)
	{
		
		this->filename = new char[strlen(repo.filename) + 1];
		strcpy_s(this->filename, strlen(repo.filename) + 1, repo.filename);
		
		this->load_to_file();

	}



	void set_filename(const char* filename) {
		if (this->filename != NULL)
		{
			delete[] this->filename;
			this->filename = NULL;

		}
		if (filename != NULL)
		{
			this->filename = new char[strlen(filename) + 1];
			strcpy_s(this->filename, strlen(filename) + 1, filename);
		}
		else
			this->filename = NULL;
	}

	void add_element(T element) {
		Repo<T>::add_element(element);
	}




	vector<T> get_all()
	{
		return Repo<T>::get_all();
	}

	RepoSTL<T>& operator=(const RepoSTL<T>& s)
	{
		this->set_filename(s.filename);
		this->load_to_file();
		return *this;
	}

	T get_at_position(int position)
	{
		return Repo<T>::get_at_position(position);
	}

	bool element_in_repo(T param)
	{
		Repo<T>::element_in_repo(param);
	}



	void update(T& old,const T& new_t)
	{
		for (int i = 0; i < this->elem.size(); i++)
			if (this->elem[i] == old)
				this->elem[i] = new_t;
		this->save_to_file();
	}

	void switch_position(int position_1, int position_2)
	{
		T temp;
		temp = this->elem[position_1];
		this->elem[position_1] = this->elem[position_2];
		this->elem[position_2] = temp;

		this->save_to_file();

	}

	void delete_obj(T param)
	{
		for (int i = 0; i < this->elem.size(); i++)
			if (this->elem[i] == param)
				for (int j = i; j < this->elem.size()-1; j++)
					this->elem[j] = this->elem[j+1];

		Repo<T>::delete_last_obj();

		this->save_to_file();


	}

	

	
	void load_to_file()
	{
		if (this->filename != NULL)
		{
			ifstream f(this->filename);

			T element;

			while (f >> element)
			{
				Repo<T>::add_element(element);

			}

			f.close();
		}
		/*else
			Repo<T>::clear();*/
	}

	void save_to_file()
	{
		if (this->filename != NULL)
		{
			ofstream f(this->filename);
			for (int i = 0; i < this->elem.size(); i++)
				f << this->elem[i];

			f.close();
		}
	}


};

