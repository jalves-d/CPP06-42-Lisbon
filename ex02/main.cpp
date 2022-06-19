#include "Base.hpp"

Base *generate(void)
{
    srand(time(NULL));

    switch (rand() % 3)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    Base result;
	try
	{
        A result;
		result = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &exception){}
    try
	{
        B result;
		result = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &exception){}
    try
	{
        C result;
		result = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &exception){}
}

int main(void)
{
    Base* tclass;

    tclass = generate();
    identify(tclass);
    identify(*tclass);

    delete tclass;
}
