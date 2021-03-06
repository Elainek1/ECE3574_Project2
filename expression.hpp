#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <vector>
#include <tuple>

class Expression
{
	//enum expressionType { noneType, boolType, doubleType, stringType };
public:
	enum expressionType { noneType = 0, boolType, doubleType, stringType, pointType, lineType, arcType };
	expressionType atomType;
	bool boolAtom;
	double doubleAtom;
	std::string stringAtom;
	std::tuple<double, double> valueAtom;
	std::tuple<double, double> startAtom;
	std::tuple<double, double> endAtom;
	std::tuple<double, double> centerAtom;
	//double angleAtom;


	Expression * parent;
	//auto atom;
	std::vector<Expression *> children;

	// Default construct an Expression of type None
	Expression();

	//Default deconstructor
	~Expression();

	// Construct an Expression with a single Boolean atom with value
	Expression(bool value);

	// Construct an Expression with a single Number atom with value
	Expression(double value);

	// Construct an Expression with a single Symbol atom with value
	Expression(const std::string & value);

	// Construct an Expression with a single Point atom with value
	Expression(std::tuple<double, double> value);

	// Construct an Expression with a single Line atom with starting
	// point start and ending point end
	Expression(std::tuple<double, double> start,
		std::tuple<double, double> end);

	// Construct an Expression with a single Arc atom with center
	// point center, starting point start, and spanning angle angle in radians 
	Expression(std::tuple<double, double> center,
		std::tuple<double, double> start,
		double angle);

	bool almost_equal(const double x, const double y);

	// Equality operator for two Expressions, two expressions are equal if the have the same 
	// type, atom value, and number of arguments
	bool operator==(const Expression & exp) const noexcept;


};

#endif