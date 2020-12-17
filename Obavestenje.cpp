#include "Obavestenje.h"
#include <iostream>

int Obavestenje::_id_generator = 0;

Obavestenje::Obavestenje(Korisnik* korisnik)
	: 
	_identifikator(_id_generator++),
	_korisnik(korisnik),
	_procitano(false)
{
	std::time(&_trenutno_vreme);
}

int Obavestenje::getId() const
{
	return _identifikator;
}

Korisnik* Obavestenje::getKorisnik() const
{
	return _korisnik;
}

bool Obavestenje::isProcitano() const
{
	return _procitano;
}

void Obavestenje::procitaj()
{
	_procitano = true;
}


std::ostream& operator<<(std::ostream& out, const Obavestenje& ob)
{
	out << ob.getId() << "|";
	// TODO: dohvatiti ime korisnika;

	tm local_time;

	localtime_s(&local_time, &ob._trenutno_vreme);

	out << local_time.tm_hour << ":" << local_time.tm_min << ":" << local_time.tm_sec << std::endl;
	out << ob.obavestenje();


	return out;
}