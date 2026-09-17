#include "bigint.hpp"


bigint::bigint() : _digits("0") {}

bigint::bigint(unsigned long num) {
	std::stringstream ss;

	ss << num;

	this->_digits = ss.str();

	//if (num == 0){
	//	_digits = "0";
	//	return;
	//}
	//_digits = "";
	//while (num > 0){
	//	char digit = '0' + (num % 10);
	//	_digits.insert(_digits.begin(), digit);
	//	num /= 10;
	//}
}

bigint::bigint(const bigint &other) : _digits(other._digits) {}

bigint &bigint::operator=(const bigint &other) {
	if (this != &other)
		_digits = other._digits;
	return *this;
}

bigint::~bigint(){}

//-------------------
const std::string &bigint::getDigits() const
{
	return (_digits);
}

//----addizione

static std::string addStrings(const std::string &a, const std::string &b)
{
	std::string result;
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry > 0){
		int sum = carry;
		if (i >= 0)
		{
			sum += a[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			sum += b[j] - '0';
			j--;
		}
		carry = sum /10;
		result.insert(result.begin(), (sum % 10) + '0');
	}
	return result;
}

bigint &bigint::operator+=(const bigint &rhs){
	_digits = addStrings(_digits, rhs._digits);
	return (*this);
}

bigint bigint::operator+(const bigint &rhs) const {
	bigint result (*this);
	result += rhs;
	return result;
}

bigint &bigint::operator++(){
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)      // postfisso: parametro int fittizio, mai usato
{
	bigint tmp(*this);
	++(*this);
	return (tmp);
}

//---shift
bigint bigint::operator<<(const bigint &rhs) const {
	bigint result(*this);
	result <<= rhs;
	return result;
}
bigint bigint::operator>>(const bigint &rhs) const {
	bigint result(*this);
	result >>= rhs;
	return result;
}

bigint &bigint::operator<<=(const bigint &rhs) {
	unsigned long num;
	std::stringstream ss;
	ss << rhs._digits;
	ss >> num;

	this->_digits.insert(this->_digits.end(), num, '0');
	return (*this);
}

bigint &bigint::operator>>=(const bigint &rhs) {
	unsigned long num;
	std::stringstream ss;
	ss << rhs._digits;
	ss >> num;

	if (this->_digits.size() <= num){
		this->_digits = "0";
		return (*this);
	}

	for (unsigned long i = 0; i < num; i++){
		this->_digits.pop_back();
	}

	return (*this);
}

//-------------------comparison
int compareStrings(const std::string &a, const std::string &b)
{
	if (a.size() < b.size())
		return (-1);
	if (a.size() > b.size())
		return (1);
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}


bool bigint::operator==(const bigint &rhs) const {
	return (compareStrings(this->_digits, rhs._digits) == 0);

}
bool bigint::operator!=(const bigint &rhs) const {
	return (compareStrings(this->_digits, rhs._digits) != 0);
}

bool bigint::operator>(const bigint &rhs) const {
	return (compareStrings(this->_digits, rhs._digits) > 0);
}
bool bigint::operator<(const bigint &rhs) const {
	return (compareStrings(this->_digits, rhs._digits) < 0);
}

bool bigint::operator>=(const bigint &rhs) const {
	return (*this > rhs || *this == rhs);
}
bool bigint::operator<=(const bigint &rhs) const {
	return (*this < rhs || *this == rhs);
}


std::ostream &operator<<(std::ostream &str, const bigint &obj)
{
	str << obj.getDigits();
	return str;
}