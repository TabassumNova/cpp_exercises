#include <iostream>
class Screen0 {

private:
	size_t size;
	int* data;
    int color;
public:

	Screen0() : data(nullptr), size(0), color(0) {
		std::cout << "default constructor" << std::endl;
	}

	Screen0(size_t size_, int color) : color(color), size(size_),
		data(new int[size]) {
		std::cout << "size,col constructor" << std::endl;
	}

	Screen0(const Screen0&)
	{
		std::cout << "copy constructor" << std::endl;
	}
	Screen0 &operator=(Screen0&)
	{
		delete [] data;
		std::cout << "copy assignment" << std::endl; return *this;
	}

	Screen0(Screen0&&)
	{
		std::cout << "move constructor" << std::endl;
	}
	Screen0 &operator=(Screen0&&)
	{
		delete [] data;
		std::cout << "move assignment" << std::endl; return *this;
	}

	~Screen0() {
		std::cout << "destructor" << std::endl;
               if (data != nullptr)
               {
                   delete [] data;
               }

	}

	int getsize() const { std::cout << "getsize const" << std::endl; return size; }
	void setsize(const int& size) { this->size = size; }

	int getdata(int i) { return data[i]; }
};

int main()
{
    Screen0 sc1;
    Screen0 sc2(5,2);
    Screen0 sc3(4,1);
    Screen0 sc4(sc3);
    sc3 = sc2;
    Screen0 sc5(std::move(sc2));
    sc1 = std::move(sc3);
    return 0;
}
