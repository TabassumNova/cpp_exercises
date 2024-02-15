#include <iostream>
#include <initializer_list>

class Abstract_Base {

public:
	virtual void print() = 0;

	Abstract_Base() { std::cout << "in Abstract_Base::stdconstructor" << std::endl; }
	~Abstract_Base() { std::cout << "in Abstract_Base::destructor" << std::endl; }

};

class Base : public Abstract_Base {
public:
	Base() : mem(0) { std::cout << "in Base::stdconstruct" << std::endl; }
	Base(int i) : mem(i) { std::cout << "in Base::construct(int)" << std::endl; }

	void print() override { std::cout << "in Base::print" << std::endl; }
	virtual void print_int(int i = 0) { std::cout << "in Base::print_int " << i << " " << std::endl; }

	// copy control
	Base(const Base&) { std::cout << "Base::copyconstructor" << std::endl; }
	Base& operator=(const Base&) { std::cout << "Base::operator=" << std::endl; return *this; }

	virtual ~Base() { std::cout << "in Base::destructor" << std::endl; }

protected:
	int mem;
};

class Derived final : public Base {

public:
	Derived() : mem(0) { std::cout << "in Derived::construct()" << std::endl; }
	Derived(int i) : mem(i), Base(i) { std::cout << "in Derived::construct(int)" << std::endl; }     // initializes Derived::mem
	Derived(std::initializer_list<int>) { std::cout << "in Derived::construct(list)" << std::endl; }


	int get_mem() { return mem; }  // returns Derived::mem
	int get_base_mem() { return Base::mem; }

	void print() override { std::cout << "in Derived::print" << std::endl; }
	void print_int(int i) { std::cout << "in Derived::print_int " << i << " " << std::endl; }

	~Derived() { std::cout << "in Derived::destructor" << std::endl; }

protected:
	int mem;   // hides mem in the base
	int* pi;
};

int main() {

	Abstract_Base* a;
	//Base b;
	Base* d = new Derived{ 1 };
	d->print();
	d->print_int(1);
	delete d;
	return 0;
}
