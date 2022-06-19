
#include "Converted.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
        Converted Converted(argv[1]);
        Converted.toChar();
        Converted.toInt();
        Converted.toFloat();
        Converted.toDouble();
	}
    else
        std::cout << "Error: ./convert <string>" << std::endl;
    return (0);
