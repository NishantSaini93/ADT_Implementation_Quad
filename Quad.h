/**
*Purpose:
*1)Experience creating an abstract data type.
*2)Implement an ADT in C++,using the operator overloading facility of C++ language.
*3)Learn about function object and how to define them.
*/
#ifndef _Quad_INCLUDED
#define _Quad_INCLUDED
#include <array>
#include<iostream>
#include <stdexcept>
#include <iomanip>
using std::setw;
using std::cin;
/**
*Implemented a ADT Quad having container "quadContainer" to store a quad number
*Operators are overloaded to provide services,handle quad numbers and process them.
*/
class Quad {
private:
	/**
	*Container to hold quad number
	*/
	std::array<long long int, 4> quadContainer;
public:
	/**
	*Constructor of Quad to initialize values
	*@param x1 Value at index 0 of container
	*@param x2 Value at index 1 of container
	*@param x3 Value at index 2 of container
	*@param x4 Value at index 3 of container 
	*/
	Quad(long long int x1 = 0, long long int x2 = 1, long long int x3 = 0, long long int x4 = 1);

	/**
	*Defaulted copy constructor
	*@param quad Quad object
	*/
	Quad(const Quad& quad) = default;

	/**
	*Defaulted  assignment operator
	*@param quad Quad object
	*/
	Quad& operator=(const Quad&) = default;

	/**
	*Defaulted destructor
	*/
	virtual ~Quad() = default;

	/**
	*Overloading of subscript operator for non constant
	*@param index Index
	*@return value at Index
	*/
	long long int& operator[](int index);

	/**
	*Overloading of subscript operator for constant
	*@param index Index
	*@return value at Index
	*/
	const long long int& operator[](int)const;

	/**
	*Function to get value from index 0 of quadContainer
	*@return Value at index 0 of quadContainer
	*/
	long long int getX1()const;

	/**
	*Function to get value from index 1 of quadContainer
	*@return Value at index 1 of quadContainer
	*/
	long long int getX2()const;

	/**
	*Function to get value from index 2 of quadContainer
	*@return Value at index 2 of quadContainer
	*/
	long long int getX3()const;

	/**
	*Function to get value from index 3 of quadContainer
	*@return Value at index 3 of quadContainer
	*/
	long long int getX4()const;

	/**
	*Function to set value for index 0 of quadContainer
	*@param x1 Value to set
	*/
	void setX1(long long int x1);

	/**
	*Function to set value for index 1 of quadContainer
	*@param x2 Value to set
	*/
	void setX2(long long int x2);

	/**
	*Function to set value for index 2 of quadContainer
	*@param x3 Value to set
	*/
	void setX3(long long int x3);

	/**
	*Function to set value for index 3 of quadContainer
	*@param x4 Value to set
	*/
	void setX4(long long int x4);
	
	/**
	*Overloading of compound operator += for adding object into object
	*@param y Quad object to add
	*@return Updated Quad
	*/
	Quad& operator+=(const Quad& y);
	
	/**
	*Overloading of compound operator += for adding scaler to object
	*@param k Integer to add
	*@return Updated Quad
	*/
	Quad& operator+=(const long long int& k);

	/**
	*Overloading of compound operator -= for subtracting object from object
	*@param y Object to subtract
	*@return Updated Quad
	*/
	Quad& operator-=(const Quad& y);

	/**
	*Overloading of compound operator -= for subtracting number from object
	*@param k Integer to subtract
	*@return Updated Quad
	*/
	Quad& operator-=(const long long int& k);

	/**
	*Overloading of compound operator *= for multiplying object with object
	*@param y Object to multiply
	*@return Updated Quad
	*/
	Quad& operator*=(const Quad& y);

	/**
	*Overloading of compound operator *= for multipying object with number
	*@param k Integer to multiply
	*@return Updated Quad
	*/
	Quad& operator*=(const long long int& k);

	/**
	*Overloading of unary - operator
	*@return Updated Quad
	*/
	Quad& operator-();

	/**
	*Overloading of unary + operator
	*@return Updated Quad
	*/
	Quad& operator+();

	/**
	*Overloading of unary -- operator(prefix)
	*@return Updated Quad
	*/
	Quad& operator--();

	/**
	*Overloading of unary ++ operator(prefix)
	*@return Updated Quad
	*/
	Quad& operator++();

	/**
	*Overloading of unary -- operator(postfix)
	*@param x Dummy value
	*@return Updated Quad
	*/
	Quad operator--(int x);

	/**
	*Overloading of unary ++ operator(postfix)
	*@param x Dummy value
	*@return Updated Quad
	*/
	Quad operator++(int x);

	/**
	*Overloading function call operator()
	*@return Absolute value of Quad
	*/
	double operator()();

	/**
	*Function to calculate norm
	*@return Norm value of quad
	*/
	double norm();

	/**
	*This function test for equality of quads
	@param quad Quad object to compare with
	*@return boolean value after test
	*/
	bool isSimilar(Quad quad);

	/**
	*This function test for equality of quads
	@param k Value from which second quad is made to compare with
	*@return boolean value after test
	*/
	bool isSimilar(long long int k);

	/**
	*Function to calculate inverse of Quad
	*@return Inverse of Quad
	*/
	Quad inverse()const;

	/**
	*Function to calculate absolute value
	*@return Absolute value in form of double
	*/
	double absoluteValue();

	/**
	*This function normalize the quad
	*/
	void normalize();

	/**
	*This function reduce the quad
	*/
	void reduce();

	/**
	*This function standardize the qaud 
	*/
	void standardize();

	/**
	*This function calculate the quad
	*@return conjugate if quad
	*/
	Quad conjugate();

	/**
	*This function convert size into double
	*/
	operator double();
};

/**
*Overloading of << operator
*@param out Ostream object
*@param quad Quad object
*@return Ostream reference
*/
std::ostream& operator<<(std::ostream& out, const Quad& quad);

/**
*Overloading of >> operator
*@param out Istream object
*@param quad Quad object
*@return Istream reference
*/
std::istream& operator>>(std::istream& in, Quad& quad);

/**
*Overloading of == operator 
*@param q1 Object of quad1
*@param q2 Object of quad2
*@return boolean value based upon test
*/
bool operator== (const Quad& q1, const Quad& q2);

/**
*Overloading of != operator
*@param q1 Object of quad1
*@param q2 Object of quad2
*@return boolean value based upon test
*/
bool operator!= (const Quad& q1, const Quad& q2);

/**
*Overloading of binary + operator
*@param x Object of quad1
*@param y Object of quad2
*@return Addition of two quads
*/
Quad operator+(const Quad x, const Quad y);

/**
*Overloading of binary + operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (addition)
*/
Quad operator+(const Quad x, const long long int k);

/**
*Overloading of binary + operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (addition)
*/
Quad operator+(const long long int k, const Quad x);

/**
*Overloading of binary - operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (subtraction)
*/
Quad operator-(const Quad x, const Quad y);

/**
*Overloading of binary - operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (subtraction)
*/
Quad operator-(const Quad x, const long long int k);

/**
*Overloading of binary - operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (subtraction)
*/
Quad operator-(const long long int k, const Quad x);

/**
*Overloading of binary * operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (multiplication)
*/
Quad operator*(const Quad x, const Quad y);

/**
*Overloading of binary * operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (multiplication)
*/
Quad operator*(const Quad x, const long long int k);

/**
*Overloading of binary * operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (multiplication)
*/
Quad operator*(const long long int k, const Quad x);

/**
*Overloading of binary / operator
*@param x Object of quad1
*@param y Object of quad2
*@return Quad (division)
*/
Quad operator/(const Quad x, Quad y);

/**
*Overloading of binary / operator
*@param x Object of quad1
*@param k Integer from which second quad is made
*@return Quad (division)
*/
Quad operator/(const Quad x, long long int k);

/**
*Overloading of binary * operator
*@param k Integer from which first quad is made
*@param x Object of quad1
*@return Quad (divison)
*/
Quad operator/(long long int k, const Quad x);

/**
*Overloading of ^ operator
*@param x Quad object
*@param k Power of quad
*@return Quad after calculation
*/
Quad operator^(const Quad x, const int k);

/**
*Overloading the < operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator<(Quad q1, Quad q2);

/**
*Overloading the <= operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator<=(Quad q1, Quad q2);

/**
*Overloading the > operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator>(Quad q1, Quad q2);

/**
*Overloading the >= operator
*@param q1 Object of Quad
*@param q2 Object of Quad
*@return boolean value based on comparision
*/
bool operator>=(Quad q1, Quad q2);

/**
*Overloading the < operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator<(Quad q1, const long long int k);

/**
*Overloading the <= operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator<=(Quad q1, const long long int k);

/**
*Overloading the > operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator>(Quad q1, const long long int k);

/**
*Overloading the >= operator
*@param q1 Object of Quad
*@param k value from which another Quad object is made
*@return boolean value based on comparision
*/
bool operator>=(Quad q1, const long long int k);

/**
*Overloading the < operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator<(const long long int k, Quad q1);

/**
*Overloading the <= operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator<=(const long long int k, Quad q1);

/**
*Overloading the > operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator>(const long long int k, Quad q1);

/**
*Overloading the >= operator
*@param k value from which another Quad object is made
*@param q1 Object of Quad
*@return boolean value based on comparision
*/
bool operator>=(const long long int k, Quad q1);

/**
*Function to calculate greatest common divisor
*@param a First number
*@param b Second number
*@return gcd
*/
long long int gcd(long long int a, long long int b);
#endif

