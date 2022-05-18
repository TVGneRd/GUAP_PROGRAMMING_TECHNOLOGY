#include <math.h>
#include <bitset>
#include "BinInterface.h"


string BinInterface::getStringValue(int data) 
{
	// Warning: this breaks for numbers with more than 64 bits
	char buffer[64];
	char* p = buffer + 64;
	do
	{
		*--p = '0' + (data & 1);
	} while (data >>= 1);

	return std::string(p, buffer + 64);
}
