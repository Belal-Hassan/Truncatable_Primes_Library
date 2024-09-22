#include "TPs.h"

uint8 sizeofint(uint64 num) //output the number of digits of an integer.
{
	uint8 size = 0;
	while (num > 0)
	{
		num /= 10; 
		size++; 
	}
	return size;
}
bool flip(uint64* num) //flip the number via its pointer.
{
	if(*num % 10 == 0)
		return false; //if the number ends in 0, it cannot be flipped.
    uint64 flipped = 0;
    while (*num > 0) {
        int digit = *num % 10;  //get the last digit.
        flipped = flipped * 10 + digit;  //build the flipped number.
        *num /= 10;  //remove the last digit from the original number.
    }
    *num = flipped;  //store the flipped number back in the original variable via pointer.
	return true;
}
bool isPrime(uint64 num) //check if a number is prime.
{
	if (num == 1)
		return false; 
	if (num == 2)
		return true;
	for (uint64 i = 2; i <= ceil(sqrt(num)); i++) 
		if (num % i == 0) //there exists at least a divisor less than the square root of the number if it's not prime.
			return false;
	return true;
}
bool isRTP(uint64 num) //check if a number is a right-truncatable prime
{
	if (sizeofint(num) > 8)
		return false; //return false because there are no right-truncatable primes with more than 8 digits.
	while (num > 0) //check if the number is prime after removing each rightmost digit.
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
bool isLTP(uint64 num) //Check if the a is a left-truncatable prime.
{
	if (sizeofint(num) > 19)
		return false; //The limit of the unsigned long long is 19 digits.
	while (num > 0) //check if the number is prime after removing each leftmost digit.
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
bool isTSP(uint64 num) //check if a number is a right-truncatable prime & a left-truncatable prime at the same time (two-sided prime).
{
	if (sizeofint(num) > 6)
		return false; //return false because there are no two-sided primes with more than 6 digits.
	if (isRTP(num) && isLTP(num)) 
		return true;
	return false;
}
uint64 rightNumberCombined(uint64 mainNumber, uint8 additionalNumber) //adds the additionalNumber to the right of the mainNumber.
{
  	return (mainNumber * 10) + additionalNumber; 
}
uint64 leftNumberCombined(uint64 mainNumber, uint8 additionalNumber) //adds the additionalNumber to the left of the mainNumber.
{
	uint64 cast = mainNumber; //cast in order not to manipulate the mainNumber.
	flip(&cast); 
	uint64 output = (cast * 10) + additionalNumber; 
	flip(&output); 
  	return output;
}
vect64 RTPs(uint8 n) //output all n-digit right-truncatable primes.
{
	if (n > 8)
    	return vect64(); //return an empty vector because there are no right-truncatable primes with more than 8 digits.
	vect64 RTPvector;
  	uint64 tempNumber;
  	uint16 vectSize = 0;
  	copy(&primes[0], &primes[4], back_inserter(RTPvector)); //start with a vector of primes to build up upon it.
  	for(uint8 counter = 1; counter < n; counter++)
  	{
    	vectSize = RTPvector.size();
    	for(uint16 vectCounter = 0; vectCounter < vectSize; vectCounter++)
    	{
      		for (uint8 oddCounter = 0; oddCounter < 4; oddCounter++)
      		{
        		tempNumber = rightNumberCombined(RTPvector[vectCounter], odds[oddCounter]); 
        		if(isPrime(tempNumber))
          			RTPvector.push_back(tempNumber);
      		}
    	}
    	RTPvector.erase(RTPvector.begin(), RTPvector.begin() + vectSize);
  	}
	RTPvector.erase(remove_if(RTPvector.begin(), RTPvector.end(), [](uint64 num) {return !isRTP(num);}), RTPvector.end());
	return RTPvector;
}
vect64 LTPs(uint8 n) //outputs all n-digit left-truncatable primes.
{
	if (n > 19)
		return vect64();
    vect64 LTPvector;
  	uint64 tempNumber;
  	uint16 vectSize = 0;
  	copy(&LTprimes[0], &LTprimes[2], back_inserter(LTPvector));
  	for(uint8 counter = 1; counter < n; counter++)
  	{
    	vectSize = LTPvector.size();
    	for(uint32 vectCounter = 0; vectCounter < vectSize; vectCounter++)
    	{
      		for (uint8 number = 1; number < 10; number++)
      		{
        		tempNumber = leftNumberCombined(LTPvector[vectCounter], number);
        		if(isPrime(tempNumber))
          			LTPvector.push_back(tempNumber);
      		}
    	}
    	LTPvector.erase(LTPvector.begin(), LTPvector.begin() + vectSize);
  	}
	LTPvector.erase(remove_if(LTPvector.begin(), LTPvector.end(), [](uint64 num) {return !isLTP(num);}), LTPvector.end());
	return LTPvector;
}
vect64 TSPs(uint8 n) //Outputs all n-digit numbers that are right truncatable primes and left truncatable primes at the same time (Two-sided Primes).
{
	if (n > 6)
		return vect64();
    vect64 TSPvector;
  	uint64 tempNumber;
  	uint16 vectSize = 0;
  	copy(&primes[0], &primes[4], back_inserter(TSPvector));
  	for(uint8 counter = 1; counter < n; counter++)
  	{
    	vectSize = TSPvector.size();
    	for(uint16 vectCounter = 0; vectCounter < vectSize; vectCounter++)
    	{
      		for (uint8 oddCounter = 0; oddCounter < 4; oddCounter++)
      		{
        		tempNumber = rightNumberCombined(TSPvector[vectCounter], odds[oddCounter]);
        		if(isPrime(tempNumber))
          			TSPvector.push_back(tempNumber);
      		}
    	}
    	TSPvector.erase(TSPvector.begin(), TSPvector.begin() + vectSize);
  	}
	TSPvector.erase(remove_if(TSPvector.begin(), TSPvector.end(), [](uint64 num) {return !isRTP(num);}), TSPvector.end());
  	TSPvector.erase(remove_if(TSPvector.begin(), TSPvector.end(), [](uint64 num) {return !isLTP(num);}), TSPvector.end());
	return TSPvector;
}