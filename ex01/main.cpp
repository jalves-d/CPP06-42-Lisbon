#include <stdint.h>
#include <iostream>

struct Data {

    int data;
    std::string month;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*   deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main(void)
{
    Data ptr = {42, "Lisbon"};
    Data* dest;

	std::cout << "Before serialize: " << ptr.data << " " << ptr.month << std::endl;
    uintptr_t t = serialize(&ptr);
	std::cout << "After serialize: " << t << std::endl;
	dest = deserialize(t);
	std::cout << "After deserialize: " << dest->data << " " << dest->month << std::endl;
	return 0;
}
