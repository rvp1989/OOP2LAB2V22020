#ifndef _LISTA_H_
#define _LISTA_H_

#include "Obavestenje.h"

class Lista
{
private:
	struct Element
	{
		Obavestenje* ob;
		Element* next;
	};

	Element* _head;
public:
	Lista();
	~Lista();

	Lista(const Lista&) = delete;
	Lista(Lista&&) = delete;
	Lista& operator=(const Lista&) = delete;
	Lista& operator=(Lista&&) = delete;

	Lista& operator+=(Obavestenje* ob);
	void operator()() const;
	int operator+() const;
	void operator!();
	void operator~();

	Obavestenje* operator[](int id) const;


	friend std::ostream& operator<<(std::ostream& out, const Lista& lista);
};

#endif // !_LISTA_H_

