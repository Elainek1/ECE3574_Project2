#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <unordered_map>
#include <string>
#include "expression.hpp"

//struct enviroVal
//{
//	enum enviroType{ functType, boolType, doubleType, stringType };
//		//envrioType;
//	std::string stringVal;
//	bool boolVal;
//	double doubleVal;
//	
//};

class Environment
{
public:
	typedef Expression(* functPtr)(Expression *);
	Environment();
	double addDoubleSymbol(std::string symbol, double value);
	bool addBoolSymbol(std::string symbol, bool value);
	bool addPointSymbol(std::string symbol, std::tuple<double, double> value);
	bool addLineSymbol(std::string symbol, std::tuple<double, double> start, std::tuple<double, double> end);
	bool addArcSymbol(std::string symbol, std::tuple<double, double> center, std::tuple<double, double> start, double angle);
	int symbolExist(std::string symbol); //returns 0 if doesn't exist, 1 for symbol is bool, 2 for symbol is double
	double getDoubleSymbol(std::string symbol);
	bool getBoolSymbol(std::string symbol);
	std::tuple<double, double> getPointSymbol(std::string symbol);
	std::tuple<std::tuple<double, double>, std::tuple<double, double>> getLineSymbol(std::string symbol);
	std::tuple<std::tuple<double, double>, std::tuple<double, double>, double> getArcSymbol(std::string symbol);
	//functPtr getFunctPtr(std::string symbol);
	//bool addBoolSymbol(std::string symbol, bool value);
	//void reset();
private:
	std::unordered_map < std::string, functPtr > environmentMap0;
	std::unordered_map<std::string, double> environmentMap2;
	std::unordered_map<std::string, bool> environmentMap1;
	std::unordered_map<std::string, std::tuple<double, double>> environmentMap4;
	std::unordered_map<std::string, std::tuple<double, double>> environmentMap5;
	std::unordered_map<std::string, std::tuple<double, double>> environmentMap6;
};
#endif