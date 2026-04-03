#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->age = 42;
	data->sername = "Meier";

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;
	std::cout << serialized->sername << std::endl;

	delete data;
	return (0);
}