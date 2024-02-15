class Vector {
private:
	int size = 0;
	double* data = nullptr;
public:
	Vector() = default;
	Vector(int s) : size(s), data(new double[size]) { cout << "Vector(int)" << endl; } // default constructor
	explicit Vector(const Vector&) { std::cout << "copy constructor" << std::endl; }
	Vector& operator=(const Vector5&) { std::cout << "operator=" << std::endl; return *this; }
	
	double& operator[](int i) {
		cout << "operator[](int i)" << endl;
		return data[i];
	}
	double operator[](int i) const {
		cout << "operator[](int i)" << endl;
		return data[i];
	}
	~Vector() { cout << "~Vector()" << endl; } // default destructor
};