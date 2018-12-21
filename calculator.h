#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include <vector>
#include <QString>
#include <set>


class calculator
{
public:
    calculator();

    double calculate(const QString& text);

    int push(char op);

private:
    std::stack<char> op;

    std::stack<double> num;

    std::set<char> operator_set;

    int get_level(char ch);

    double rekon(double lhs, double rhs, char op);

    void clear();

    bool is_operator(char ch);
};

#endif // CALCULATOR_H
