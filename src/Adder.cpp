//============================================================================
// Name        : Adder.cpp
// Author      : DennyKim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int adder ( const unsigned int a, const unsigned int b)
{
	const unsigned int max = sizeof(unsigned int)*8;
	unsigned answer = 0, cin = 0;

	for (unsigned i = 1, k = 0 ; k < max ; i <<= 1, ++k) {
		unsigned int ua = (a & i) >> k;
		unsigned int ub = (b & i) >> k;
		unsigned int s = ua^ub;
		answer |= ( (s ^ cin) << k );
		cin = (ua&ub) ^ (s&cin);
	}
	return answer;
}

unsigned int adder_btr ( unsigned int s, unsigned int c)
{
	unsigned int sum = 0;
	do {
		sum = s^c;
		c = (s&c) << 1;
		s = sum;
	} while (c);

	return s;
}

unsigned int adder_rec ( const unsigned int s, const unsigned int c)
{
	if (!c) return s;
	return adder_rec (s^c, (s&c)<<1);
}

int main() {
	unsigned int a = 4294967294, b= 1;
	printf ("adder = %u\n", adder(a,b));
	printf ("adder_btr = %u\n", adder_btr(a,b));
	printf ("adder_rec = %u\n", adder_rec(a,b));
	return 0;
}
