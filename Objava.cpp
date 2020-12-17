#include "Objava.h"

Objava::Objava(std::string text, Korisnik* korisnik)
	: Obavestenje(korisnik),
	  _text(text)
{
}

std::string Objava::obavestenje() const
{
	return _text;
}
