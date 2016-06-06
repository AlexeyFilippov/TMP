#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}

class Base
{
protected:
	int data;
public:
	Base(int data_v) : data(data_v) {};

	virtual void show() = 0;

	~Base() {};
};

class A : public Base
{
public:
	A(int data_v) : Base(data_v) {};

	void show()
	{
		std::cout << "class A: " << data << std::endl;
	}

	~A() {};
};

class B : public Base
{
public:
	B(int data_v) : Base(data_v) {};

	void show()
	{
		std::cout << "class B: " << data << std::endl;
	}

	~B() {};
};

class C : public Base
{
public:
	C(int data_v) : Base(data_v) {};

	void show()
	{
		std::cout << "class C: " << data << std::endl;
	}

	~C() {};
};

std::vector<Base*> objects;

class Functor
{
public:
	Functor() {};

	virtual void operator()() {};
	virtual void operator()(std::string, int) {};

	~Functor() {};
};

class FunctorShow : public Functor
{
public:
	FunctorShow() {};

	void operator()()
	{
		for (unsigned int i = 0; i < objects.size(); i++)
			objects[i]->show();
	}

	~FunctorShow() {};
};

class FunctorCreate : public Functor
{
public:
	FunctorCreate() {};

	void operator()(std::string str, int data_v)
	{
		Base* b;
		if (str == "A")
			b = new A(data_v);
		else if (str == "B")
			b = new B(data_v);
		else if (str == "C")
			b = new C(data_v);
		else
		{
			std::cout << "wrong classname!" << std::endl;
			return;
		}

		objects.push_back(b);
		return;
	}

	~FunctorCreate() {};
};

int main()
{
	std::map<std::string, Functor*> f;
	Functor* fs = new FunctorShow;
	Functor* fc = new FunctorCreate;
	f["showall"] = fs;
	f["create"] = fc;

	std::string expr;
	std::vector<std::string> expressions;
	Functor* functor;
	int n;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 1; i < n + 1; i++)
	{
		std::cout << i << '>';
		getline(std::cin, expr);
		expressions = split(expr, ' ');
		functor = f[expressions[0]];

		if (functor == nullptr)
		{
			std::cout << "wrong operation" << std::endl;
			i--;
		}

		if (expressions.size() == 1)
			(*functor)();
		else if (expressions.size() == 3)
			(*functor)(expressions[1], stoi(expressions[2]));
		else
		{
			std::cout << "wrong operation" << std::endl;
			i--;
		}
	}

	system("pause");
	return 0;
}
