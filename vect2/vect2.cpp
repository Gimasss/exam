#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y)  :_x(x), _y(y) {}

vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y){}

vect2 &vect2::operator=(const vect2 &other) {
	if (this != &other) {
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

vect2::~vect2() {}

//--------------

int &vect2::operator[](int index) {
	if (index == 0)
		return (_x);
	return (_y);
}

int vect2::operator[](int index) const {
	if (index == 0)
		return (_x);
	return (_y);
}

vect2 &vect2::operator++(){
	_x++;
	_y++;
	return *this;
}

vect2 vect2::operator++(int){
	vect2 tmp(*this);
	++(*this);
	return tmp;

}

vect2 &vect2::operator--(){
	_x--;
	_y--;
	return *this;
}

vect2 vect2::operator--(int){
	vect2 tmp(*this);
	--(*this);
	return tmp;
}

vect2 &vect2::operator+=(const vect2 &other) {
	_x += other._x;
	_y += other._y;
	return *this;
}

vect2 &vect2::operator-=(const vect2 &other) {
	_x -= other._x;
	_y -= other._y;
	return *this;

}

vect2 &vect2::operator*=(int scalar) {
	_x *= scalar;
	_y *= scalar;
	return *this;
}


vect2 vect2::operator-() const {
	return (vect2(-_x, -_y));
}

//----esterni
vect2 operator+(const vect2 &l, const vect2 &r) {
	return (vect2(l[0] + r [0], l[1] + r[1]));
}

vect2 operator-(const vect2 &l, const vect2 &r) {
	return (vect2(l[0] - r [0], l[1] - r[1]));
}

vect2 operator*(const vect2 &other, int scalar) {
	return (vect2(other[0] * scalar, other[1] * scalar));
}

vect2 operator*(int scalar, const vect2 &other) {
	return (other * scalar);
}

bool operator==(const vect2 &l, const vect2 &r){
	return (l[0] == r[0] && l[1] == r[1]);
}
bool operator!=(const vect2 &l, const vect2 &r){
	return (!(l == r));
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj){
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}


//Riassunto della regola generale:

//Unario che modifica l'oggetto (++, --, anche - unario che pur non modificando è naturalmente legato a un solo oggetto) → membro
//Binario dove i due operandi sono "alla pari" (+, -, *, ==, !=) → libero
//Binario compound che modifica il primo operando (+=, -=, *=) → membro (perché modifica *this)