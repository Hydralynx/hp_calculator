#include <stack>
#include <string>

#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();
    ~Calculator();
    std::string divide();
    std::string multiply();
    std::string add();
    std::string substract();
    std::string square();
    std::string displayTop();
    std::string addToTop(const double number);

    bool pushNumber(const double number);
    bool flagEnabled();
    bool flagDisable();
    bool isInitialized();
    void flushStack();
private:
    std::stack<double> m_stack;
    bool m_enterFlag;
};

#endif // CALCULATOR_H
