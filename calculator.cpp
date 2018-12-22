#include "calculator.h"
#include <stack>
#include <numeric>
#include <cassert>
#include <iostream>

calculator::calculator()
{
    operator_set.insert('(');
    operator_set.insert(')');
    operator_set.insert('+');
    operator_set.insert('-');
    operator_set.insert('*');
    operator_set.insert('/');

}

double calculator::calculate(const QString& text)
{
    QString number;
    this->clear();
    std::string wrapper = text.toStdString().data();
    wrapper = '(' + wrapper + ')';

    bool valid = false;
    for(auto iter = wrapper.begin(); iter != wrapper.end(); iter++){
        char ch = *iter;
        if(ch == '.' || (ch >= '0' && ch <= '9'))
        {
            number.append(ch);
            valid = true;
        }
        else if(is_operator(ch))
        {
            if(valid)
            {
                printf("number %c %s\n",ch, number.toStdString().data());
                double temp_number = number.toDouble();
                printf("pushing number %f__ \n", temp_number);
                num.push(temp_number);
                valid = false;
                number.clear();
            }

            this->push(ch);
        }
    }
    assert(num.size() == 1 && "numbers in stack not right");
    return num.top();
}

int calculator::push(char op_char)
{
    if(op_char == '(')
    {
        op.push(op_char);
        return 0;
    }

    printf("pushing %c\n", op_char);
    int level = get_level(op_char);
    while (!op.empty()) {
        char last_op = op.top();

        if(last_op == '(' && op_char == ')')
        {
            op.pop();
            return 0;
        }

        if(get_level(last_op) < level){
            break;
        }

        double rhs = num.top();
        num.pop();
        double lhs = num.top();
        num.pop();
        op.pop();
        printf("rekoning %f %f %c", lhs, rhs, last_op);
        double ret = rekon(lhs, rhs, last_op);
        num.push(ret);
    }
    if(op_char != ')')
    {
        op.push(op_char);
    }
    return 0;
}

int calculator::get_level(char ch)
{
    switch (ch) {
        case '(':
            return 0;
        case  ')':
            return 0;
        case  '*':
            return 2;
        case  '/':
            return 2;
        case  '+':
            return 1;
        case  '-':
            return 1;
    }
    printf("illegal operator, please checkout your input charactors __%d__\n", (int)ch);
    assert(false && "illegal operator, please checkout your input charactors");
    return -1;
}

double calculator::rekon(double lhs, double rhs, char oper)
{
    switch (oper) {
        case  '*':
            return lhs * rhs;
        case  '/':
            return lhs / rhs;
        case  '+':
            return lhs + rhs;
        case  '-':
            return lhs - rhs;
    }
    printf("illegal operator,rekoning __%c__", oper);
    assert(false && "illegal operator,rekonin");
    return 0;
}

void calculator::clear()
{
    while (!num.empty()) {
        num.pop();
    }

    while(!op.empty()){
        op.pop();
    }
}

bool calculator::is_operator(char ch)
{
    return operator_set.find(ch) != operator_set.end();
}
