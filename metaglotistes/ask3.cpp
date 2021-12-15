#include <iostream>
#include <stack>

using namespace std;

bool topSymbolIsTerminal(char inputSymbol) 
{
    //IF this function returns "true" THEN the stack POPS the top element

    //If this function returns "false" THEN the main program calls another function, 
    //in order to push some symbols into the Automaton

    char arrayOfterminalSymbols[7] = { 'a' , 'b' ,'*' ,'-' ,'+' ,'(' ,')' };

    for(int i = 0 ; i < 7 ; i++)
    {
        if(inputSymbol == arrayOfterminalSymbols[i])
        {
            return true;
        }   
    }

    return false;    
}

string stackAction(char stackTop , char inputSymbol)
{
    //By now it is allready desided that the stack top is a non-terminal symbol,
    //so...something is going to be pushed in the stack

    //This function returns the symbols that are about to be pushed in the stack

    //IF the function returns "error" THEN the input string can not be recognised

    //There is only 1 special occasion where the stack just POPS the top symbol,
    //and this is when the stack top is "Z" and the input is: )

    if (stackTop == 'S')
    {
        if(!(inputSymbol == '('))
        {
            return "error";
        }
        else
        {
            return "(X)";
        }        
    }
    else if (stackTop == 'X')
    {
        if(inputSymbol =='(' || inputSymbol == 'a' || inputSymbol == 'b')
        {
            return "YZ";
        }
        else
        {
            return "error";
        }
        
    }
    else if (stackTop == 'Y')
    {
        if(inputSymbol == '(')
        {
            return "S";
        }
        else if (inputSymbol == 'a')
        {
            return "a";
        }
        else if (inputSymbol == 'b')
        {
            return "b";
        }
        else
        {
            return "error";
        }        
        
    }
    else if (stackTop == 'Z')
    {
        if(inputSymbol == ')')
        {
            return "POP";
        }
        else if (inputSymbol == '*')
        {
            return "*X";
        }
        else if (inputSymbol == '-')
        {
            return "-X";
        }
        else if (inputSymbol == '+')
        {
            return "+X";
        }
        else
        {
            return "error";
        }        
    }
    
}



int main()
{
    stack<char> pushDownAutomaton;

    string simvoloseira;

    cout << "please enter a string: " << endl;
    cin >> simvoloseira;
    cout << "Ok. Got it! " << endl;

    bool simvoloseiraIsCorrect = true;
    bool symbolIsTerminal;

    for (int i = simvoloseira.length() - 1 ; i >= 0 ; i--)
    {
        if(!(simvoloseira[i] == '(' || simvoloseira[i] == ')' || simvoloseira[i] == '*' || simvoloseira[i] == '-' || simvoloseira[i] == '+' || simvoloseira[i] == 'a' || simvoloseira[i] == 'b'))
        {
            simvoloseiraIsCorrect = false;
        }
        
    }

    pushDownAutomaton.push('$'); // Pushing the starting symbol "$" of the stack
    pushDownAutomaton.push('S'); // Always begining with the starting symbol
    int currentChar = 0;
    int charsLeft = simvoloseira.length();
    cout <<"There are " << charsLeft   << " charachters left to be examined" << endl; //temp

    while(currentChar <= simvoloseira.length())
    {

        if(simvoloseiraIsCorrect == false)
        {
            cout << "Sorry! You have entered an  unrecognizable from the machine charachter" << endl;
            currentChar = simvoloseira.length() + 1; //gia na teleiwsei to while
        }
        else
        {
            if(currentChar == simvoloseira.length())
            {
                if(pushDownAutomaton.top() == '$')
                {
                    cout << "The string has been recognised successfully! " << endl;
                    currentChar = simvoloseira.length() + 1; //gia na teleiwsei to while
                }
                else
                {
                    cout << "Sorry...The string can not be recognised by the machine" << endl;
                    currentChar = simvoloseira.length() + 1; //gia na teleiwsei to while
                }
            }
            else            
            {
                cout << "currently checking the input symbol \"" << simvoloseira[currentChar]  <<  "\" with the stack's top symbol being: \"" <<  pushDownAutomaton.top() <<  "\"" <<endl;
                symbolIsTerminal = topSymbolIsTerminal(pushDownAutomaton.top());

                // I called a function I made, to see if the current stack's top  symbol is terminal or not

                if (symbolIsTerminal)
                {
                    cout << "It seems that the symbol \"" << pushDownAutomaton.top() <<  "\" is terminal" << endl;
                    cout << "So..the automaton pops its top element" << endl;

                    cout << "**now popping: \"" << pushDownAutomaton.top() << "\" **" <<endl;

                    pushDownAutomaton.pop();
                    currentChar++;
                    charsLeft--;
                    cout << "--------------------------------------------------------------------" << endl;
                    cout <<"There are " << charsLeft   << " charachters left to be examined" << endl; //temp
                }
                else
                {
                    cout << "It seems that the symbol \"" << pushDownAutomaton.top() <<  "\" is not a terminal symbol" << endl;

                    string response = stackAction(pushDownAutomaton.top() , simvoloseira[currentChar]);

                    cout << "The function for input \"" << simvoloseira[currentChar] << "\" and with the stack top being: \"" << pushDownAutomaton.top() << "\" returned the string: " << response << endl;

                    if (response =="error")
                    {
                        cout << "Sorry...The string can not be recognised by the machine" << endl;
                        currentChar = simvoloseira.length() + 1; //gia na teleiwsei to while
                    }
                    else if (response == "POP")
                    {
                        cout << "it seems that the symbol \"Z\" wich is on the top must replace itself with \"ε\"" << endl;

                        pushDownAutomaton.pop();
                        continue;
                    }
                    else
                    {
                        cout << "popping: \"" << pushDownAutomaton.top() << "\"" <<endl;

                        pushDownAutomaton.pop(); // in order to replace it

                        for(int j = response.length() - 1 ; j >= 0 ; j--)
                        {
                            cout << "pushing: " << response[j] << " into the stack" << endl;
                            pushDownAutomaton.push(response[j]);
                        }
                        
                        cout << "--------------------------------------------------------------------" << endl;
                        cout <<"There are " << charsLeft   << " charachters left to be examined" << endl; //temp
                    }
                    

                }
                
            }
            
        }

    }
    
}