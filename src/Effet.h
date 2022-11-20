#pragma once
#include <iostream>
using namespace std;

class Effet {
private:
	string description = "c'est l'effet de la carte";
public:
	string getDescription() const { return description; }
};