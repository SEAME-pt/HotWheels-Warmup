#include "../includes/Car.hpp"

int	main(void)
{
	Car car1("Porsche 991 GT3");
	Car car2("Mclaren P1");
	Car car3("Ferrari Purosangue");

	std::cout << "Car1's name is " << car1.getName() << std::endl;
	std::cout << "Car2's name is " << car2.getName() << std::endl;
	std::cout << "Car3's name is " << car3.getName() << std::endl;
}
