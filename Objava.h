#ifndef _OBJAVA_H_
#define _OBJAVA_H_

#include "Obavestenje.h"

class Korisnik;
class Objava : public Obavestenje
{
public:
	Objava(std::string text, Korisnik* korisnik);

	std::string obavestenje() const override;
private:
	std::string _text;
};
#endif // !_OBJAVA_H_

