#ifndef VECT_HPP
# define VECT_HPP

#include <iostream>
#include <sstream>
#include <vector>

class vect2 {
	private:
		int _x;
		int _y;

	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &);
		vect2 &operator=(const vect2 &);
		~vect2();

		int &operator[] (int index); //why with ref
		int operator[] (int index) const;

		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);

		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(int scalar);

		vect2 operator-() const;
};

vect2 operator+(const vect2 &l, const vect2 &r);
vect2 operator-(const vect2 &l, const vect2 &r);
vect2 operator*(int scalar, const vect2 &other);
vect2 operator*(const vect2 &other, int scalar);

bool operator==(const vect2 &lhs, const vect2 &rhs);
bool operator!=(const vect2 &lhs, const vect2 &rhs);

std::ostream &operator<<(std::ostream &str, const vect2 &obj);


#endif