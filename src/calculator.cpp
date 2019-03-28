#include "calculator.h"
#include <string>

Calculator::Calculator()
{
    m_enterFlag = false;
    m_operatorFlag = false;
}

Calculator::~Calculator()
{
}

bool Calculator::pushNumber(const double number)
{
    m_stack.push(number);
    m_enterFlag = true;
    m_operatorFlag = false;

    return true;
}

std::string Calculator::divide()
{
    // Si pas assez d'opérandes dans la pile
    if (m_stack.size() < 2)
        return "ERROR";

    double lVal, rVal, result;

    // Si division par 0
    if(m_stack.top() == 0)
        return "ERROR";

    rVal = m_stack.top();
    m_stack.pop();

    lVal = m_stack.top();
    m_stack.pop();

    result = lVal / rVal;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

std::string Calculator::multiply()
{
    // Si pas assez d'opérandes dans la pile
    if (m_stack.size() < 2)
        return "ERROR";

    double lVal, rVal, result;

    rVal = m_stack.top();
    m_stack.pop();

    lVal = m_stack.top();
    m_stack.pop();

    result = lVal * rVal;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

std::string Calculator::add()
{
    // Si pas assez d'opérandes dans la pile
    if (m_stack.size() < 2)
        return "ERROR";

    double lVal, rVal, result;

    rVal = m_stack.top();
    m_stack.pop();

    lVal = m_stack.top();
    m_stack.pop();

    result = lVal + rVal;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

std::string Calculator::substract()
{
    // Si pas assez d'opérandes dans la pile
    if (m_stack.size() < 2)
        return "ERROR";

    double lVal, rVal, result;

    rVal = m_stack.top();
    m_stack.pop();

    lVal = m_stack.top();
    m_stack.pop();

    result = lVal - rVal;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

std::string Calculator::square()
{
    if (m_stack.empty())
            return "ERROR";

    double Val, result;

    Val = m_stack.top();
    m_stack.pop();

    result = Val * Val;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

std::string Calculator::percent()
{
    // Si pas assez d'opérandes dans la pile
    if (m_stack.empty())
        return "ERROR";

    double Val, result;

    Val = m_stack.top();
    m_stack.pop();

    result = Val / 100;

    m_stack.push(result);

    m_operatorFlag = true;

    return std::to_string(result);
}

bool Calculator::isInitialized()
{
    if (!m_stack.empty())
        return false;

    return true;
}

void Calculator::flushStack()
{
    while (!m_stack.empty())
        m_stack.pop();
}

std::string Calculator::displayTop()
{
    if (m_stack.empty())
        return "ERROR";

    return std::to_string(m_stack.top());
}

std::string Calculator::addToTop(const double number)
{
    if (m_stack.empty())
        return "ERROR";

    double nb_temp = m_stack.top();
    m_stack.pop();
    m_stack.push(nb_temp + number);

    return std::to_string(m_stack.top());
}

bool Calculator::enterFlagEnabled()
{
    return m_enterFlag;
}

void Calculator::enterFlagDisable()
{
    m_enterFlag = false;
}

bool Calculator::operatorFlagEnabled()
{
    return m_operatorFlag;
}

void Calculator::operatorFlagDisable()
{
    m_operatorFlag = false;
}
