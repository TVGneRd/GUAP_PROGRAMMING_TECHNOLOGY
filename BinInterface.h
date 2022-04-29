#pragma once

#include <iostream>

#include "List.h"

using namespace std;

class BinInterface: public List
{
public:
	string getStringValue(int data) override;
private:
};


