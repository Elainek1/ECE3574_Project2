#include "environment.hpp"
#include "interpreter.hpp"
#include <math.h>

typedef Expression(*functPtr)(Expression *);

//the environment constructor basically adds the default values
//like pi
Environment::Environment()
{
	environmentMap1.clear();
	environmentMap2.clear();
	environmentMap4.clear();
	environmentMap5.clear();
	environmentMap6.clear();

//	environmentMap0["+"] = add;

	environmentMap2["pi"] = atan2(0, -1);
	environmentMap2["True"] = 0;
	environmentMap2["False"] = 0;
	environmentMap2["not"] = 0;
	environmentMap2["and"] = 0;
	environmentMap2["or"] = 0;
	environmentMap2["<"] = 0;
	environmentMap2["<="] = 0;
	environmentMap2[">"] = 0;
	environmentMap2[">="] = 0;
	environmentMap2["="] = 0;
	environmentMap2["+"] = 0;
	environmentMap2["-"] = 0;
	environmentMap2["*"] = 0;
	environmentMap2["/"] = 0;
	environmentMap2["define"] = 0;
	environmentMap2["begin"] = 0;
	environmentMap2["if"] = 0;
	environmentMap2["point"] = 0;
	environmentMap2["line"] = 0;
	environmentMap2["arc"] = 0;
	environmentMap2["sin"] = 0;
	environmentMap2["cos"] = 0;
	environmentMap2["arctan"] = 0;
	environmentMap2["draw"] = 0;
}

//this function takes in the symbol and the double value
//then adds the mapping to the environmentMap2 (because this is the map that contains double values)
//it then returns the double value
double Environment::addDoubleSymbol(std::string symbol, double value)
{
	environmentMap2[symbol] = value;
	return value;
}

//this function takes in the symbol and the bool value
//then adds the mapping to the environmentMap1 (because this is the map that contains bool values)
//it then returns the bool value
bool Environment::addBoolSymbol(std::string symbol, bool value)
{
	environmentMap1[symbol] = value;
	return value;
}

bool Environment::addPointSymbol(std::string symbol, std::tuple<double, double> value)
{
	environmentMap4[symbol] = value;
	return true;
}
bool Environment::addLineSymbol(std::string symbol, std::tuple<double, double> start, std::tuple<double, double> end)
{
	environmentMap5[symbol] = start;
	environmentMap4[symbol] = end;
	return true;
}
bool Environment::addArcSymbol(std::string symbol, std::tuple<double, double> center, std::tuple<double, double> start, double angle)
{
	environmentMap6[symbol] = center;
	environmentMap5[symbol] = start;
	environmentMap2[symbol] = angle;
	return true;
}
//this function takes in the string of symbol
//and sees if it exists in the mapping
//the value return indicates which map is it located in or 0 means it is not in any mapping
int Environment::symbolExist(std::string symbol)
{
	if (environmentMap6.find(symbol) != environmentMap6.end()) //if it is in the fourth map for points return 4
	{
		return 6;
	}
	else if (environmentMap5.find(symbol) != environmentMap5.end()) //if it is in the fourth map for points return 4
	{
		return 5;
	}
	else if (environmentMap4.find(symbol) != environmentMap4.end()) //if it is in the fourth map for points return 4
	{
		return 4;
	}
	else if (environmentMap1.find(symbol) != environmentMap1.end()) //if it is in the first map then return 1
	{
		return 1;
	}
	else if (environmentMap2.find(symbol) != environmentMap2.end()) //if it is in the second map then return 2
	{
		return 2;
	}
	else if (environmentMap0.find(symbol) != environmentMap0.end()) //this is for later when I implement function pointers
	{
		return 3;
	}
	else
	{
		return 0; //otherwise is not in any maps
	}
}

//this resets the environment to the beginning
void Environment::reset()
{
	environmentMap1.clear();
	environmentMap2.clear();
	environmentMap4.clear();
	environmentMap5.clear();
	environmentMap6.clear();

	environmentMap2["pi"] = atan2(0, -1);
	environmentMap2["True"] = 0;
	environmentMap2["False"] = 0;
	environmentMap2["not"] = 0;
	environmentMap2["and"] = 0;
	environmentMap2["or"] = 0;
	environmentMap2["<"] = 0;
	environmentMap2["<="] = 0;
	environmentMap2[">"] = 0;
	environmentMap2[">="] = 0;
	environmentMap2["="] = 0;
	environmentMap2["+"] = 0;
	environmentMap2["-"] = 0;
	environmentMap2["*"] = 0;
	environmentMap2["/"] = 0;
	environmentMap2["define"] = 0;
	environmentMap2["begin"] = 0;
	environmentMap2["if"] = 0;
	environmentMap2["point"] = 0;
	environmentMap2["line"] = 0;
	environmentMap2["arc"] = 0;
	environmentMap2["sin"] = 0;
	environmentMap2["cos"] = 0;
	environmentMap2["arctan"] = 0;
	environmentMap2["draw"] = 0;
}

//get the value for function ptr
functPtr Environment::getFunctPtr(std::string symbol)
{
	return environmentMap0[symbol];
}

//this returns the double symbol value
double Environment::getDoubleSymbol(std::string symbol)
{
	return environmentMap2[symbol];
}

//this returns the bool symbol value
bool Environment::getBoolSymbol(std::string symbol)
{
	return environmentMap1[symbol];
}

std::tuple<double, double> Environment::getPointSymbol(std::string symbol)
{
	return environmentMap4[symbol];
}

std::tuple<std::tuple<double, double>, std::tuple<double, double>> Environment::getLineSymbol(std::string symbol)
{
	std::tuple<std::tuple<double, double>, std::tuple<double, double>> answer = std::make_tuple(environmentMap5[symbol], environmentMap4[symbol]);
	return answer;
}

std::tuple<std::tuple<double, double>, std::tuple<double, double>, double> Environment::getArcSymbol(std::string symbol)
{
	std::tuple<std::tuple<double, double>, std::tuple<double, double>, double> answer = std::make_tuple(environmentMap6[symbol], environmentMap5[symbol], environmentMap2[symbol]);
	return answer;
}
