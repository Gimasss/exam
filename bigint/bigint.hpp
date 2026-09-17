#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <string>
# include <sstream>

class bigint {

	private:
		std::string _digits;
	public:
		bigint();
		bigint(unsigned long num);
		bigint(const bigint &other);
		bigint &operator=(const bigint &other);
		~bigint();

		const std::string &getDigits() const;
		bigint operator+(const bigint &rhs) const;
		bigint &operator+=(const bigint &rhs);


		bigint operator++(int);
		bigint &operator++();

		bigint operator<<(const bigint &rhs) const;
		bigint operator>>(const bigint &rhs) const;
		bigint &operator<<=(const bigint &rhs);
		bigint &operator>>=(const bigint &rhs);

		bool operator==(const bigint &rhs) const;
		bool operator!=(const bigint &rhs) const;
		bool operator>=(const bigint &rhs) const;
		bool operator<=(const bigint &rhs) const;
		bool operator>(const bigint &rhs) const;
		bool operator<(const bigint &rhs) const;


};

std::ostream &operator<<(std::ostream &str, const bigint &obj);

#endif
