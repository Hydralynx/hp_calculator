#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool estUnOperateur(const string& input);
void calculer(const string& input, stack<double>& calcStack);

int main()
{
    cout << "Calculatrice NPI moisie\n\n" << endl;

    stack<double> calcStack;
    string entree;

    while(1)
    {
        cout << ">> ";

        // On recupere l'entree clavier (bloquant)
        cin >> entree;

        // On verifie si le caractere entre est un nombre
        double num;
        if(istringstream(entree) >> num)
        {
            calcStack.push(num);
        }

        // On verifie si le caractere entre est un operateur
        else if(estUnOperateur(entree))
        {
            calculer(entree, calcStack);
        }

        // Si appui sur 'q' on quitte le main
        else if(entree == "q")
        {
            return 0;
        }
        // Si l'utilisateur rentre un mauvais caractere
        else
        {
            cout << "Entrée invalide." << endl;
        }
    }
    return 0;
}

bool estUnOperateur(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};

    for(int i = 0; i < 4; i++)
    {
        if(input == ops[i])
        {
            return true;
        }
    }
    return false;
}

void calculer(const string& input, stack<double>& calcStack)
{
    double lVal, rVal, result;

    rVal = calcStack.top();
    calcStack.pop();

    lVal = calcStack.top();
    calcStack.pop();

    if(input == "-")
    {
        result = lVal - rVal;
    }
    else if(input == "+")
    {
        result = lVal + rVal;
    }
    else if(input == "*")
    {
        result = lVal * rVal;
    }
    else
    {
        result = lVal / rVal;
    }

    cout << result << endl;

    calcStack.push(result);
}
