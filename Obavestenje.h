#ifndef _OBAVESTENJE_H_
#define _OBAVESTENJE_H_

#include <chrono>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <ctime>

class Korisnik;
class Obavestenje
{
private:
	int _identifikator;
	time_t _trenutno_vreme;
	Korisnik* _korisnik;
	bool _procitano;

	static int _id_generator;
public:
	Obavestenje(Korisnik* korisnik);

	int getId() const;
	Korisnik* getKorisnik() const;
	bool isProcitano() const;
	void procitaj();

	virtual std::string obavestenje() const = 0;

	friend std::ostream& operator<<(std::ostream&, const Obavestenje&);
};



#endif
