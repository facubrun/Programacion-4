#ifndef DTFECHA
#define DTFECHA

#include <iostream>
#include <iomanip>

class DTFecha {
	private:
		int dia, mes, anio;
	public:
		DTFecha();
		DTFecha(int dia, int mes, int anio);
		int getDia();
		int getMes();
		int getAnio();
};

std::ostream& operator<<(std::ostream& os, DTFecha& fecha);
#endif