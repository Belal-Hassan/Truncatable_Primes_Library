#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#define fpow(x, y) round(pow(x, y))
using namespace std;

/*_______________data types definition_______________*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long int uint64;
typedef vector<uint64> vect64;

/*_______________functions' decleration_______________*/
uint8 sizeofint(uint64 num); //output the number of digits of an integer.
bool flip(uint64* num); //flip the number via its pointer.
bool isPrime(uint64 num); //check if a number is prime.
bool isRTP(uint64 num); //check if a number is a right-truncatable prime.
bool isLTP(uint64 num); //Check if the a is a left-truncatable prime.
bool isTSP(uint64 num); //check if a number is a right-truncatable prime & a left-truncatable prime at the same time (two-sided prime).
uint64 rightNumberCombined(uint64 mainNumber, uint8 additionalNumber); //adds the additionalNumber to the right of the mainNumber.
uint64 leftNumberCombined(uint64 mainNumber, uint8 additionalNumber); //adds the additionalNumber to the left of the mainNumber.
vect64 RTPs(uint8 size); //output all n-digit right-truncatable primes.
vect64 LTPs(uint8 size); //outputs all n-digit left-truncatable primes.
vect64 TSPs(uint8 size); //Outputs all n-digit numbers that are right truncatable primes and left truncatable primes at the same time (Two-sided Primes).

/*_______________some useful arrays_______________*/
const char odds[4] = {1, 3, 7, 9}; //the odd numbers that could be added to the right of primes.
const char LTprimes[2] = {3, 7};
const char primes[4] = {2, 3, 5, 7};