#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int r = rand() % 3;
	if (r == 0)
	{
		Base *a = new A();
		return (a);
	}
	else if (r == 1)
	{
		Base *b = new B();
		return (b);
	}
	else
	{
		Base *c = new C();
		return (c);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;	
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;	
	}
	catch(const std::exception& e)
	{
	}

}

int	main()
{
	Base	*a = new A();
	Base	*b = new B();
	Base	*c = new C();


	
	identify(a);
	identify(b);
	identify(c);

	identify(*a);
	identify(*b);
	identify(*c);

	Base	*ran = generate();

	identify(ran);

	delete a;
	delete b;
	delete c;
	delete ran;
}