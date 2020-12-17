#include "Korisnik.h"
#include "Objava.h"
#include "Lista.h"
#include <iostream>


int main()
{
	Korisnik k1("Igor");
	Korisnik k2("Slavisa");

	Lista lista;
	Objava *ob1 = new Objava("Poruka1", &k1);
	Objava *ob2 = new Objava("Poruka2", &k2);
	Objava *ob3 = new Objava("Poruka3", &k1);

	((lista += ob1) += ob2) += ob3;

	// ob3 ob2 ob1

	std::cout << lista;

	lista();
	std::cout << (+lista) << std::endl;
	!lista;

	if (lista[1] == nullptr)
		std::cout << "Uspesno svi oznaceni kao procitani" << std::endl;
	else
		std::cout << "Neuspesno svi oznaceni kao procitani" << std::endl;

	k1.posalji(&k2);

	std::cout << k2 << std::endl;

	return 0;
}