#ifndef _KORISNIK_H_
#define _KORISNIK_H_

#include <string>
#include "Lista.h"

class Korisnik
{
public:
	Korisnik(std::string ime);
	std::string getIme() const;
	void primi(Obavestenje* ob);
	void posalji(Korisnik* korisnik);

	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

	friend std::ostream& operator<<(std::ostream& out, const Korisnik& korisnik);
private:
	std::string _ime;
	Lista _lista_obavestenja;
};
#endif // !_KORISNIK_H_

