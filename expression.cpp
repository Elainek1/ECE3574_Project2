#include "expression.hpp"
#include <iostream>
#include <tuple>

Expression::Expression()
{
	parent = nullptr;
	stringAtom = "";
	atomType = noneType;
}

Expression::~Expression()
{
	/*
	for (int i = 0; i < children.size(); i++)
	{
		(*children[i]).~Expression();
	}
	delete this;
	*/
	//delete parent;
}


Expression::Expression(bool value)
{
	parent = nullptr;
	atomType = boolType;
	stringAtom = "";
	boolAtom = value;
}

// Construct an Expression with a single Number atom with value
Expression::Expression(double value)
{
	parent = nullptr;
	atomType = doubleType;
	stringAtom = "";
	doubleAtom = value;
}

// Construct an Expression with a single Symbol atom with value
Expression::Expression(const std::string & value)
{
	parent = nullptr;
	atomType = stringType;
	stringAtom = value;
}

// Construct an Expression with a single Point atom with value
Expression::Expression(std::tuple<double, double> value)
{
	parent = nullptr;
	atomType = pointType;
	stringAtom = "";
	valueAtom = value;
}

// Construct an Expression with a single Line atom with starting
// point start and ending point end
Expression::Expression(std::tuple<double, double> start, std::tuple<double, double> end)
{
	parent = nullptr;
	atomType = lineType;
	stringAtom = "";
	startAtom = start;
	endAtom = end;
}

// Construct an Expression with a single Arc atom with center
// point center, starting point start, and spanning angle angle in radians 
Expression::Expression(std::tuple<double, double> center, std::tuple<double, double> start, double angle)
{
	parent = nullptr;
	atomType = arcType;
	stringAtom = "";
	centerAtom = center;
	startAtom = start;
	doubleAtom = angle;
}



// Equality operator for two Expressions, two expressions are equal if the have the same 
// type, atom value, and number of arguments
bool Expression::operator==(const Expression & exp) const noexcept
{
	//checks to see if it is the same type
	if (this->atomType == exp.atomType)
	{
		//if it a none type then its true
		if (this->atomType == 0)
		{
			return true;
		}
		//if it is a boolean
		else if (this->atomType == 1)
		{
			//check if boolean values are the same and they have same number of children
			if ((this->boolAtom == exp.boolAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if it is a double
		else if (this->atomType == 2)
		{
			//check if double values are the same and they have the same number of children
			if ((this->doubleAtom == exp.doubleAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if they are a string type
		else if (this->atomType == 3)
		{
			//check if string values are the same and they have the same number of children
			if ((this->stringAtom == exp.stringAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if they are a point type
		else if (this->atomType == 4)
		{
			//check if string values are the same and they have the same number of children
			if ((this->valueAtom == exp.valueAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if they are a line type
		else if (this->atomType == 5)
		{
			//check if string values are the same and they have the same number of children
			if ((this->startAtom == exp.startAtom) && (this->endAtom == exp.endAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//if they are a line type
		else if (this->atomType == 5)
		{
			//check if string values are the same and they have the same number of children
			if ((this->centerAtom == exp.centerAtom) && (this->startAtom == exp.startAtom) && (this->doubleAtom == exp.doubleAtom) && (this->children.size() == exp.children.size()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}

	return true;
}
