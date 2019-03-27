#include <stack>
#include <string>

#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();
    std::string divide();
    std::string multiply();
    std::string add();
    std::string substract();
    std::string square();
    std::string displayTop();
    bool pushNumber(const double number);
    bool isInitialized();
    bool deleteNumber();
    void flushStack();
private:
    std::stack<double> m_stack;
};

#endif // CALCULATOR_H
