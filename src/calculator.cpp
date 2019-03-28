#include "calculator.h"
#include <string>

Calculator::Calculator()
{
}

bool Calculator::pushNumber(const double number)
{
    m_stack.push(number);

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

