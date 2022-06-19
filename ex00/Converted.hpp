#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstring>
#include <cstdio>

class Converted
{
    private:

            std::string _input;
            double _value;

    public:

            Converted() {  };
            Converted(const std::string input);
            Converted(const Converted &copy);
            Converted &operator=(const Converted &copy);
            ~Converted() {  };

            void toChar();
            void toInt();
            void toFloat();
            void toDouble();
    };

#endif
