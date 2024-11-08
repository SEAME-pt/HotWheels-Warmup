#include "../includes/ACar.hpp"

/* Orthodox Canonical Form */
ACar::ACar() : make("Renault"), model("Megane"), year(2008) {}

ACar::~ACar() {}

ACar::ACar(const ACar& originalACar)
{
	this->make = originalACar.make;
	this->model = originalACar.model;
	this->year = originalACar.year;
}

ACar& ACar::operator=(const ACar& originalACar)
{
	if (this != &originalACar)
	{
		this->make = originalACar.make;
        this->model = originalACar.model;
        this->year = originalACar.year;
	}
	return *this;
}


/* ------------------------ */

ACar::ACar(const std::string &make, const std::string &model, int year) : make(make), model(model), year(year) {};