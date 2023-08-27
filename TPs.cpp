#include "TPs.h"
#include <iostream>
#include <cmath>
using namespace std;

uint8 sizeofint(uint64 num)
{
	uint8 size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return size;
}

bool flip(uint64* num) //Flips a number (234 to 432) and returns true if it could be flipped
{
	uint64 size = 0, bu = *num;
	while (bu > 0)
	{
		if (bu % 10 == 0)
			return false;
		bu /= 10;
		size++;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		bu += (*num % 10) * pow(10, i);
		*num -= (*num % 10);
		*num /= 10;
	}
	*num = bu;
	return true;
}

bool isPrime(uint64 num) //Checks if a number is prime
{
	if (num == 1)
		return false;
	if (num == 2)
		return true;
	for (uint64 i = 2; i <= ceil(sqrt(num)); i++)
		if (num % i == 0)
			return false;
	return true;
}

bool isRTP(uint64 num) //Checks if a number is right-truncatable prime
{
	if (sizeofint(num) > 8)
		return false;
	while (num > 0)
	{
		if (!isPrime(num))
			return false;
		else
		{
			num -= (num % 10);
			num /= 10;
		}
	}
	return true;
}

bool isLTP(uint64 num) //Checks if the a is a left-truncatable prime
{
	if (sizeofint(num) > 24)
		return false;
	while (num > 0)
	{
		if (!isPrime(num))
			return false;
		if (!flip(&num))
			return false;
		num -= (num % 10);
		num /= 10;
		flip(&num);
	}
	return true;
}

bool isTP(uint64 num) //Checks if a number is a right-truncatable prime & a left-truncatable prime at the same time
{
	if (sizeofint(num) > 6)
		return false;
	if (isRTP(num) && isLTP(num))
		return true;
	return false;
}

bool isLRTP(uint64 num)
{
	if (sizeofint(num) > 97)
		return false;
	uint64 ph = num;
	while (num > 0)
	{
		if (!isPrime(num))
			return false;
		else
		{
			num -= (num % 10);
			num /= 10;
		}
		if (!flip(&num))
			return false;
		num -= (num % 10);
		num /= 10;
		flip(&num);
	}
	return true;
}

void RTPs(uint8 n) //Outputs all n-digit right-truncatable primes
{
	if (n > 8)
		return;
	uint64 begin = pow(10, n - 1) + 1, end = pow(10, n) - 3;
	for (int num = begin; num <= end; num += 2)
		if (isRTP(num))
			cout << num << endl;
}

void LTPs(uint8 n) //Outputs all n-digit left-truncatable primes
{
	if (n > 24)
		return;
	uint64 begin = pow(10, n - 1) + 1, end = pow(10, n) - 1;
	for (int num = begin; num <= end; num++)
		if (isLTP(num))
			cout << num << endl;
}

void TPs(uint8 n) //Outputs all n-digit numbers that are right truncatable primes and left truncatable primes at the same time.
{
	if (n > 6)
		return;
	uint64 begin = pow(10, n - 1) + 1, end = pow(10, n) - 3;
	for (int num = begin; num <= end; num += 2)
		if (isTP(num))
			cout << num << endl;
}

void LRTPs(uint8 n) //Outputs all n-digit right-and-left truncatable primes.
{
	if (n > 97)
		return;
	uint64 begin = pow(10, n - 1) + 1, end = pow(10, n) - 3;
	for (int num = begin; num <= end; num += 2)
		if (isLRTP(num))
			cout << num << endl;
}