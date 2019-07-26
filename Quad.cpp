#include "Quad.h"

/**
*Constructor of Quad to initialize values
*@param x1 Value at index 0 of container
*@param x2 Value at index 1 of container
*@param x3 Value at index 2 of container
*@param x4 Value at index 3 of container
*/
Quad::Quad(long long int x1, long long int x2, long long int x3, long long int x4) :quadContainer{ x1,x2,x3,x4 } {
	this->standardize();
	if (x2==0||x4==0) {
		throw std::invalid_argument("x2 or x4 is zero");
	}
}

/**
*Overloading of subscript operator for non constant
*@param index Index
*@return value at Index
*/
long long int& Quad::operator[](int index) {
	if (1 < index || index <= quadContainer.size()) {
		return quadContainer[index - 1];
	}
	else {
		throw std::invalid_argument("index out of bound");
	}

}

/**
*Overloading of subscript operator for constant
*@param index Index
*@return value at Index
*/
const long long int& Quad::operator[](int index)const {
	if (1 < index || index <= quadContainer.size()) {
		return quadContainer[index - 1];
	}
	else {
		throw std::invalid_argument("index out of bound");
	}

}

/**
*Overloading of << operator
*@param out Ostream object
*@param quad Quad object
*@return Ostream reference
*/
std::ostream& operator<<(std::ostream& out, const Quad& quad)
{
	out << "[" << quad.getX1() << "," << quad.getX2() << "," << quad.getX3() << "," << quad.getX4() << "]" << std::endl;
	return out;
}

/**
*Overloading of >> operator
*@param out Istream object
*@param quad Quad object
*@return Istream reference
*/
std::istream& operator>>(std::istream& in, Quad& quad) {
	std::cout << "About to create the quad [a,b,c,d]" << std::endl;
	std::cout << "Enter four numbers a ,b ,c ,d in that order:" << std::endl;
	long long int z1{};
	long long int z2{};
	long long int z3{};
	long long int z4{};
	in >> z1 >> z2 >> z3 >> z4;
	quad.setX1(z1);
	quad.setX2(z2);
	quad.setX3(z3);
	quad.setX4(z4);
	return in;
}

/**
*Function to get value from index 0 of quadContainer
*@return Value at index 0 of quadContainer
*/
long long int Quad::getX1()const {
	return quadContainer[0];
}

/**
*Function to get value from index 1 of quadContainer
*@return Value at index 1 of quadContainer
*/
long long int Quad::getX2()const {
	return quadContainer[1];
}

/**
*Function to get value from index 2 of quadContainer
*@return Value at index 2 of quadContainer
*/
long long int Quad::getX3()const {
	return quadContainer[2];
}

/**
*Function to get value from index 3 of quadContainer
*@return Value at index 3 of quadContainer
*/
long long int Quad::getX4()const {
	return quadContainer[3];
}

/**
*Function to set value for index 0 of quadContainer
*@param x1 Value to set
*/
void Quad::setX1(long long int x1) {
	quadContainer[0] = x1;
}

/**
*Function to set value for index 1 of quadContainer
*@param x2 Value to set
*/
void Quad::setX2(long long int x2) {
	quadContainer[1] = x2;

}

/**
*Function to set value for index 2 of quadContainer
*@param x3 Value to set
*/
void Quad::setX3(long long int x3) {
	quadContainer[2] = x3;
}

/**
*Function to set value for index 3 of quadContainer
*@param x4 Value to set
*/
void Quad::setX4(long long int x4) {
	quadContainer[3] = x4;
}

/**
*Overloading of compound operator += for adding object into object
*@param y Quad object to add
*@return Updated Quad
*/
Quad& Quad:: operator+=(const Quad& y) {
	*this = *this + y;
	this->standardize();
	return *this;
}

/**
*Overloading of compound operator += for adding scaler to object
*@param k Integer to add
*@return Updated Quad
*/
Quad& Quad:: operator+=(const long long int& k) {
	*this = *this + k;
	this->standardize();
	return *this;
}

/**
*Overloading of compound operator -= for subtracting object from object
*@param y Object to subtract
*@return Updated Quad
*/
Quad& Quad:: operator-=(const Quad& y) {
	*this = *this - y;
	this->standardize();
	return *this;
}

/**
*Overloading of compound operator -= for subtracting number from object
*@param k Integer to subtract
*@return Updated Quad
*/
Quad& Quad:: operator-=(const long long int& k) {
	*this = *this - k;
	this->standardize();
	return *this;
}

/**
*Overloading of compound operator *= for multiplying object with object
*@param y Object to multiply
*@return Updated Quad
*/
Quad& Quad:: operator*=(const Quad& y) {
	*this = *this * y;
	this->standardize();
	return *this;
}

/**
*Overloading of compound operator *= for multipying object with number
*@param k Integer to multiply
*@return Updated Quad
*/
Quad& Quad:: operator*=(const long long int& k) {
	*this = *this * k;
	this->standardize();
	return *this;
}

/**
*Overloading of unary - operator
*@return Updated Quad
*/
Quad& Quad:: operator-() {
	this->quadContainer[0] = this->quadContainer[0];
	this->quadContainer[1] = this->quadContainer[1] * (-1);
	this->quadContainer[2] = this->quadContainer[2];
	this->quadContainer[3] = this->quadContainer[3] * (-1);
	this->standardize();
	return *this;
}

/**
*Overloading of unary + operator
*@return Updated Quad
*/
Quad& Quad:: operator+() {
	this->standardize();
	return *this;
}

/**
*Overloading of unary -- operator(prefix)
*@return Updated Quad
*/
Quad& Quad:: operator--() {
	*this -= 1;
	this->standardize();
	return *this;
}

/**
*Overloading of unary ++ operator(prefix)
*@return Updated Quad
*/
Quad& Quad::operator++() {
	*this += 1;
	this->standardize();
	return *this;
}

/**
*Overloading of unary -- operator(postfix)
*@param x Dummy value
*@return Updated Quad
*/
Quad Quad:: operator--(int x) {
	Quad copy{ *this };
	--(*this);
	this->standardize();
	return copy;
}

/**
*Overloading of unary ++ operator(postfix)
*@param x Dummy value
*@return Updated Quad
*/
Quad Quad::operator++(int x) {
	Quad copy{ *this };
	*this += 1;
	this->standardize();
	return copy;
}

/**
*Overloading function call operator()
*@return Absolute value of Quad
*/
double Quad::operator()() {
	return absoluteValue();
}

/**
*Function to calculate norm
*@return Norm value of quad
*/
double Quad::norm() {
	double z1{ (double)getX1() };
	double z2{ (double)getX2() };
	double z3{ (double)getX3() };
	double z4{ (double)getX4() };
	return ((z1 / z2) * (z1 / z2) + (z3 / z4) * (z3 / z4));
}

/**
*This function test for equality of quads
@param quad Quad object to compare with
*@return boolean value after test
*/
bool Quad::isSimilar(Quad quad) {
	if ((getX1() * quad.getX2() == quad.getX1() * getX2()) && (getX3() * quad.getX4() == quad.getX3() * getX4())) {
		return true;
	}
	else {
		return false;
	}
}

/**
*This function test for equality of quads
@param k Value from which second quad is made to compare with
*@return boolean value after test
*/
bool Quad::isSimilar(long long int k) {
	Quad tempQuad{ k };
	return this->isSimilar(tempQuad);
}

/**
*Function to calculate inverse of Quad
*@return Inverse of Quad
*/
Quad Quad::inverse() const {
	if ((getX1() * getX1()) * (getX4() * getX4()) - (2 * (getX2() * getX2()) * (getX3() * getX3()))==0) {
		throw std::invalid_argument("inversion :alpha is 0");
	}
	else {
		long long int z1{ getX1() * getX2() * (getX4() * getX4()) };
		long long int z2{ ((getX1() * getX1()) * (getX4() * getX4())) - (2 * (getX2() * getX2()) * (getX3() * getX3())) };
		long long int z3{ (-1) * (getX2() * getX2()) * (getX3()) * getX4() };
		long long int z4{ (getX1() * getX1()) * (getX4() * getX4()) - (2 * (getX2() * getX2()) * (getX3() * getX3())) };
		Quad result(z1, z2, z3, z4);
		return result;
	}
	

}

/**
*Function to calculate absolute value
*@return Absolute value in form of double
*/
double Quad::absoluteValue() {
	return sqrt(norm());
}

/**
*This function normalize the quad
*/
void Quad::normalize() {
	if (getX2() < 0 && getX4() < 0) {
		quadContainer[0] = -quadContainer[0];
		quadContainer[1] = -quadContainer[1];
		quadContainer[2] = -quadContainer[2];
		quadContainer[3] = -quadContainer[3];
	}
	else if (getX2() < 0) {
		quadContainer[0] = -quadContainer[0];
		quadContainer[1] = -quadContainer[1];
		quadContainer[2] = quadContainer[2];
		quadContainer[3] = quadContainer[3];
	}
	else if (getX4() < 0) {
		quadContainer[0] = quadContainer[0];
		quadContainer[1] = quadContainer[1];
		quadContainer[2] = -quadContainer[2];
		quadContainer[3] = -quadContainer[3];
	}
}

/**
*This function reduce the quad
*/
void Quad::reduce() {
	long long int z1{ quadContainer[0] / (gcd(quadContainer[0],quadContainer[1])) };
	long long int z2{ quadContainer[1] / (gcd(quadContainer[0], quadContainer[1])) };
	long long int z3{ quadContainer[2] / (gcd(quadContainer[2], quadContainer[3])) };
	long long int z4{ quadContainer[3] / (gcd(quadContainer[2], quadContainer[3])) };
	quadContainer[0] = z1;
	quadContainer[1] = z2;
	quadContainer[2] = z3;
	quadContainer[3] = z4;
	normalize();
}

/**
*This function standardize the qaud
*/
void Quad::standardize() {
	reduce();
	normalize();

}

/**
*This function calculate the quad
*@return conjugate if quad
*/
Quad Quad::conjugate() {
	if (quadContainer[1] == 0 || quadContainer[3] == 0) {
		throw std::invalid_argument("x2 or x4 is zero");
	}
	else {
		Quad result{ quadContainer[0],quadContainer[1],-quadContainer[2],quadContainer[3] };
		return result;
	}
	
}

/**
*This function convert size into double
*/
Quad::operator double() {
	return absoluteValue();
}

/**
*Overloading of == operator
*@param q1 Object of quad1
*@param q2 Object of quad2
*@return boolean value based upon test
*/
bool operator== (const Quad& q1, const Quad& q2) {
	return((q1.getX1() == q2.getX1()) && (q1.getX2() == q2.getX2()) && (q1.getX3() == q2.getX3()) && (q1.getX4() == q2.getX4()));
}

/**
*Overloading of != operator
*@param q1 Object of quad1
*@param q2 Object of quad2
*@return boolean value based upon test
*/
bool operator!= (const Quad& q1, const Quad& q2) {
	return(!(q1 == q2));
}

/**
*Overloading of binary + operator
*@param x Object of quad1
*@param y Object of quad2
*@return Addition of two quads
*/
Quad operator+(const Quad x, const Quad y) {
	long long int z1{ (x.getX1() * y.getX2()) + (x.getX2() * y.getX1()) };
	long long int z2{ x.getX2() * y.getX2() };
	long long int z3{ (x.getX3() * y.getX4()) + (x.getX4() * y.getX3()) };
	long long int z4{ x.getX4() * y.getX4() };
	Quad result{ z1, z2, z3, z4 };
	return result;
}

/**
*Overloading of binary + operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (addition)
*/
Quad operator+(const Quad x, const long long int k) {
	Quad temp{k};
	return x + temp;
}

/**
*Overloading of binary + operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (addition)
*/
Quad operator+(const long long int k, const Quad x) {
	Quad temp{ k };
	return x + temp;
}

/**
*Overloading of binary - operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (subtraction)
*/
Quad operator-(const Quad x, const Quad y) {
	long long int z1{ (x.getX1() * y.getX2()) - (x.getX2() * y.getX1()) };
	long long int z2{ x.getX2() * y.getX2() };
	long long int z3{ (x.getX3() * y.getX4()) - (x.getX4() * y.getX3()) };
	long long int z4{ x.getX4() * y.getX4() };
	Quad result{ z1, z2, z3, z4 };
	return result;
}

/**
*Overloading of binary - operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (subtraction)
*/
Quad operator-(const Quad x, const long long int k) {
	Quad temp{ k };
	return x - temp;
}

/**
*Overloading of binary - operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (subtraction)
*/
Quad operator-(const long long int k, const Quad x) {
	Quad temp{ k };
	return temp-x;
}

/**
*Overloading of binary * operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (multiplication)
*/
Quad operator*(const Quad x, const Quad y) {
		long long int z1{ (x.getX1() * y.getX1() * x.getX4() * y.getX4()) + (2 * x.getX3() * y.getX3() * x.getX2() * y.getX2()) };
		long long int z2{ x.getX2() * y.getX2() * x.getX4() * y.getX4() };
		long long int z3{ (x.getX1() * y.getX3() * y.getX2() * x.getX4()) + (y.getX1() * x.getX3() * x.getX2() * y.getX4()) };
		long long int z4{ x.getX2() * y.getX2() * x.getX4() * y.getX4() };
		Quad result{ z1, z2, z3, z4 };
		return result;
}

/**
*Overloading of binary * operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (multiplication)
*/
Quad operator*(const Quad x, const long long  int k) {
	long long int z1{ x.getX1() * k };
	long long int z2{ x.getX2() };
	long long int z3{ x.getX3() * k };
	long long int z4{ x.getX4() };
	Quad result{ z1,z2,z3,z4 };
	return result;
}

/**
*Overloading of binary * operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (multiplication)
*/
Quad operator*(const long long int k, const Quad x) {
	return x * k;
}

/**
*Overloading of binary / operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (division)
*/
Quad operator/(const Quad x, const Quad y) {
	Quad result{ x * (y.inverse()) };
	return result;
}

/**
*Overloading of binary / operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (division)
*/
Quad operator/(const Quad x, long long int k) {
	//check
	if (x.getX1() == 0 || x.getX2() == 0 || k == 0) {
		throw std::invalid_argument("one of x1 , x2 ,k is zero");
	}
	else {
		long long int z1{ x.getX1() };
		long long int z2{ x.getX2() * k };
		long long int z3{ x.getX3() };
		long long int z4{ x.getX4() * k };
		Quad result{ z1,z2,z3,z4 };
		return result;
	}
	
}

/**
*Overloading of binary * operator
*@param k Integer from which first quad is made
*@param q1 Object of quad1
*@return Quad (divison)
*/
Quad operator/(long long int k, const Quad x) {
	Quad temp{ k * (x.inverse()) };
	return temp;
}

/**
*Overloading of ^ operator
*@param x Quad object
*@param k Power of quad
*@return Quad after calculation
*/
Quad operator^(const Quad x, const int k) {
	if (x.getX1() == 0 && x.getX3() == 0) {
		Quad temp{ 0,1,0,1 };
		return temp;
	}
	else if (k < 0) {
		int number{ -1 };
		Quad result{ x.inverse() };
		Quad temp{ x.inverse() };
		while (number > k) {
			number--;
			result = result * temp;
		}
		result.standardize();
		return result;
	}
	else if (k == 0) {
		Quad temp{ 1,1,0,1 };
		return temp;
	}
	else {
		int number{ 1 };
		Quad result{ x };
		Quad temp{ x };
		while (number < k) {
			number++;
			result = result * temp;
		}
		result.standardize();
		return result;
	}

}

/**
*Overloading the < operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator<(Quad q1, Quad q2) {
	return (q1.norm() < q2.norm());
}

/**
*Overloading the <= operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator<=(Quad q1, Quad q2) {
	return (q1.norm() <= q2.norm());
}

/**
*Overloading the > operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator>(Quad q1, Quad q2) {
	return q1.norm() > q2.norm();
}

/**
*Overloading the >= operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator>=(Quad q1, Quad q2) {
	return (q1.norm() >= q2.norm());
	
}

/**
*Overloading the < operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator<(Quad q1, const long long int k) {
	Quad q2{k};
	return (q1.norm() < q2.norm());
	
}

/**
*Overloading the <= operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator<=(Quad q1, const long long int k) {
	Quad q2{k};
	return (q1.norm() <= q2.norm());		
}

/**
*Overloading the > operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator>(Quad q1, const long long int k) {
	Quad q2{ k };
	return (q1.norm() > q2.norm());
}

/**
*Overloading the >= operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator>=(Quad q1, const long long int k) {
	Quad q2{ k };
	return (q1.norm() >= q2.norm());
}

/**
*Overloading the < operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator<(const long long int k, Quad q1) {
	Quad q2{ k };
	return (q2.norm() < q1.norm());
}

/**
*Overloading the <= operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator<=(const long long int k, Quad q1) {
	Quad q2{ k };
	return (q2.norm() <= q1.norm());
}

/**
*Overloading the > operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator>(const long long int k, Quad q1) {
	Quad q2{ k };
	return (q2.norm() > q1.norm());
}

/**
*Overloading the >= operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator>=(const long long int k, Quad q1) {
	Quad q2{ k };
	return (q2.norm() >= q1.norm());
}

/**
*Function to calculate greatest common divisor
*@param a First number
*@param b Second number
*@return gcd
*/
long long int gcd(long long int a, long long int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}