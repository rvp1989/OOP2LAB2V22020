#include "Korisnik.h"
#include "Objava.h"
#include <iostream>

Korisnik::Korisnik(std::string ime)
	: _ime(ime)
{
}

std::string Korisnik::getIme() const
{
	return _ime;
}

void Korisnik::primi(Obavestenje* ob)
{
	_lista_obavestenja += ob;
}

void Korisnik::posalji(Korisnik* korisnik)
{
	Obavestenje* ob = new Objava("hello world", this);

	korisnik->primi(ob);
}

std::ostream& operator<<(std::ostream& out, const Korisnik& korisnik)
{
	out << korisnik.getIme() << std::endl;
	out << korisnik._lista_obavestenja << std::endl;

	return out;
}
