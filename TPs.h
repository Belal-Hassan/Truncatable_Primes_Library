#pragma once

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef unsigned long long int uint64;

bool isPrime(uint64 num);
bool isRTP(uint64 num);
bool isLTP(uint64 num);
bool isTP(uint64 num);
bool isLRTP(uint64 num);
void RTPs(uint8 size);
void LTPs(uint8 size);
void TPs(uint8 size);
void LRTPs(uint8 size);