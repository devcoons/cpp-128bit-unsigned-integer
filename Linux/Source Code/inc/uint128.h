#include <stdint.h>

class uint128
{
private:

public:
	unsigned char data[17];

	uint128();
	uint128(const uint64_t b);


	void print();

	uint128 operator++(int);
	uint128 operator++();

	uint128 operator--(int);
	uint128 operator--();

	uint128 operator=(uint128);
	uint128 operator=(uint64_t);


	uint128 operator+(const uint128&);
	uint128 operator+(const uint64_t);


	uint128 operator-(const uint128&);
	uint128 operator-(const uint64_t);


	uint128 operator*(const uint128&);
	uint128 operator*(const uint64_t);

	uint128 operator+=(const uint128&);
	uint128 operator+=(const uint64_t);


	uint128 operator-=(const uint128&);
	uint128 operator-=(const uint64_t);

	uint128 operator*=(const uint128&);
	uint128 operator*=(const uint64_t);

	uint128 operator<<(const int&);

	bool operator<(const uint128&);
	bool operator<(const uint64_t);

	bool operator>(const uint128&);
	bool operator>(const uint64_t);

	bool operator==(const uint128&);
	bool operator==(const uint64_t);

	bool operator!=(const uint128&);
	bool operator!=(const uint64_t);

	uint128 operator/(uint128);
	uint128 operator/(const uint64_t);

	uint128 operator%(const uint128&);
	uint128 operator%(const uint64_t);

	bool operator>=(const uint128&);
	bool operator>=(const uint64_t);

	bool operator<=(const uint128&);
	bool operator<=(const uint64_t);
};
