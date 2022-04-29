#include <math.h>
#include <bitset>
#include "OctInterface.h"

string OctInterface::getStringValue(int data) // Взято из интернета
{
	string s;
	while (data > 0)
	{
		s += data % 8 + '0';
		data /= 8;
	}
	reverse(s.begin(), s.end());

	return s;
}
