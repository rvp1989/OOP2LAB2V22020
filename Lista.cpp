#include "Lista.h"
#include <iostream>

Lista::Lista()
	: _head(nullptr)
{
}

Lista::~Lista()
{
	~(*this);
}


Lista& Lista::operator+=(Obavestenje* ob)
{
	Element* elem = new Element();

	elem->next = _head;
	elem->ob = ob;
	_head = elem;

	return *this;
}

void Lista::operator()() const
{
	Element* elem = _head;

	while (elem)
	{
		if (!elem->ob->isProcitano())
		{
			std::cout << *elem->ob << std::endl;
		}

		elem = elem->next;
	}
}

int Lista::operator+() const
{
	int cnt = 0;
	Element* elem = _head;

	while (elem)
	{
		if (!elem->ob->isProcitano())
			cnt++;

		elem = elem->next;
	}

	return cnt;
}

void Lista::operator!()
{
	Element* element = _head;

	while (element)
	{
		element->ob->procitaj();
		element = element->next;
	}
}

void Lista::operator~()
{
	while (_head)
	{
		Element* el = _head;
		_head = _head->next;

		delete el->ob;
		delete el;
	}
}

Obavestenje* Lista::operator[](int id) const
{
	Element* el = _head;
	Obavestenje* ob = nullptr;

	while (el)
	{
		if (el->ob->getId() == id)
		{
			ob = el->ob;
			break;
		}

		el = el->next;
	}

	if (ob && !ob->isProcitano())
		return ob;
	else
		return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Lista& lista)
{
	Lista::Element* element = lista._head;

	// element->ob => Obavestenje*
	// *element->ob => Obavestenje
	while (element)
	{
		out << *element->ob << std::endl;

		element = element->next;
	}

	return out;
}
