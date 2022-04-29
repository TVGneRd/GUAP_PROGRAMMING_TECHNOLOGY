#pragma once

#include <iostream>

#include "List.h"

using namespace std;

class OctInterface : public List
{
public:
	string getStringValue(int data) override;
private:
};