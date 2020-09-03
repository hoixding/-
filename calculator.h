#ifndef CALCULATOR_H
#define CALCULATOR_H

#include"op.h"
class calculator
{
private:
       my_Stack<double > num;
       my_Stack<char> opera;
       my_Stack<my_struct> p;
public:
        calculator();
        ~calculator();
        void Infix_to_suffix(const string& a);
        double Suffix_expression_calculation();
};

#endif // CALCULATOR_H
