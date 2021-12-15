#include <iostream>
#include <stack>

using namespace std;



int main() {

    stack<string> pushDownAutomaton;
    stack<char> simvoloseiraStack;

    string simvoloseira;
    cout << "please enter the string that is about to be examined: ";
    cin >> simvoloseira;
    cout << "Ok. Got it! " << endl;

    bool stringReachedTheEnd = false;
    bool simvoloseiraIsCorrect = true;
    bool notTheEnd = true;

    for (int i = simvoloseira.length() - 1 ; i >= 0 ; i--)
    {
        if(!(simvoloseira[i] == 'x' || simvoloseira[i] == 'y'))
        {
            simvoloseiraIsCorrect = false;
        }
        
    }
    
    pushDownAutomaton.push("$"); // Pushing the starting symbol "$" of the stack
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
            if(pushDownAutomaton.top() == "$")
            {
                if(!(currentChar == simvoloseira.length()))
                {
                    if(simvoloseira[currentChar] == 'x')
                    {
                        pushDownAutomaton.push("x");
                        cout << "the stack is empty and the input symbol is x.." << endl;
                        cout << "The pushdown Automaton pushes the symbol x in it" << endl;
                        
                        currentChar += 1;
                        charsLeft -= 1;

                        cout <<  "--------------------------------------------------------------" << endl;
                        cout <<"Now there are " << charsLeft   << " charachters left to be examined" << endl; //temp
                    }
                    else if (simvoloseira[currentChar] == 'y')
                    {
                        cout << "the stack is empty and the input symbol is y.." << endl;
                        cout << "Unidentifiable sequence of charachters" << endl;
                        cout << "the maschine can not recognise the pattern" << endl;

                        currentChar = simvoloseira.length() + 1; //gia na teleiwsei to while
                    }
                }
                else 
                {
                    
                    cout << "the pattern has been identifyed successfully" << endl;
                    
                    currentChar += 1;
                }           
               
                
            }
            else if (pushDownAutomaton.top() == "x")
            {
                if(!(currentChar == simvoloseira.length()))
                {
                    if(simvoloseira[currentChar] == 'x')
                    {
                        cout << "the stack's top symbol is x and the input symbol is x.." << endl;
                        cout << "The pushdown Automaton pushes the symbol x in it" << endl;
                        
                        pushDownAutomaton.push("x");
                        charsLeft -= 1;

                        cout <<  "--------------------------------------------------------------" << endl;
                        cout <<"Now there are " << charsLeft   << " charachters left to be examined" << endl; //temp

                        currentChar += 1; 
                    }
                    else if (simvoloseira[currentChar] == 'y')
                    {
                        cout << "the stack's top symbol is x and the input symbol is y.." << endl;
                        cout << "The pushdown Automaton pops the symbol x from it" << endl;

                        pushDownAutomaton.pop();  
                        charsLeft -= 1;

                        cout <<  "--------------------------------------------------------------" << endl;
                        cout <<"Now there are " << charsLeft   << " charachters left to be examined" << endl; //temp 

                        currentChar += 1;            
                    }
                }
                else 
                {
                    cout << "unidentifiable sequence of charachters" << endl;
                    cout << "the maschine can not recognise the pattern" << endl;
                    
                    currentChar += 1;
                }
            }
            
        }
    }
    return 0;
} 

