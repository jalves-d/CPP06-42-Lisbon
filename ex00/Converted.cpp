
#include "Converted.hpp"

Converted::Converted(const std::string input) : _input(input)
{
	if (!(isdigit(*(_input.c_str()))))
	{
		if (_input.length() == 1){
			_value = static_cast<double>(*(_input.c_str()));
		}
		else {
			if (strcmp(_input.c_str(), "-0") && atof(_input.c_str()) == 0) {
				_input = "nan";
			}
			else {
				_value = atof(_input.c_str());
			}
		}
	}
	else {
		_value = atof(_input.c_str());
	}
}

Converted::Converted(const Converted &copy)
{
	*this = copy;
}

Converted &Converted::operator=(const Converted &copy)
{
	_value = copy._value;
	return (*this);
}

void Converted::toChar()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan" ||
		_input == "+inff" || _input == "-inff" || _input == "nanf" ||
		_input == "none")
		std::cout << "char: impossible\n";
	else
	{
		char c = static_cast<char>(_value);
		if (c < 32 || c > 126)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << c << "'\n";
	}
}

void Converted::toInt()
{
	if (_input == "+inf" || _input == "-inf" || _input == "nan" ||
		_input == "+inff" || _input == "-inff" || _input == "nanf" ||
		_input == "none")
		std::cout << "int: impossible\n";
	else
	{
		int i = static_cast<int>(_value);
		std::cout << "int: " << i << std::endl;
	}
}

void Converted::toFloat()
{
	if (_input == "none")
		std::cout << "float: impossible\n";
	else if (_input == "+inf" || _input == "-inf" || _input == "nan")
		std::cout << "float: " << _input << "f" << std::endl;
	else if (_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "float: " << _input << std::endl;
	else
	{
		float f = static_cast<float>(_value);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void Converted::toDouble()
{
	if (_input == "none")
		std::cout << "double: impossible\n";
	else if (_input == "+inf" || _input == "-inf" || _input == "nan")
		std::cout << "double: " << _input << std::endl;
	else if (_input == "+inff" || _input == "-inff" || _input == "nanf")
		std::cout << "double: " << _input.substr(0, _input.size() - 1) << std::endl;
	else
	{
		double d = static_cast<double>(_value);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}
