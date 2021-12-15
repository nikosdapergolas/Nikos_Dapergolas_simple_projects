#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

string productionRules(char nonTerminalSymbol , int position , string simvoloseiraSoFar , int supremumForRandA , int supremumForRandB)
{
    // This function will return the simvoloseira after the aplied production rule in it

    cout << "By looking at the string from left to right, the first non-terminal symbol is: "<< nonTerminalSymbol << endl;


    int randomNumber; // The random number that I am going to use when the non-terminal symbol is A or B

    string firstPartOftempSimvoloseira; // All the charachters before the non-terminal symbol that i am about to replace
    for (int i = 0 ; i < position ; i++)
    {
        if ( i == 0)
        {
            firstPartOftempSimvoloseira = simvoloseiraSoFar[i];
        }
        else
        {
            firstPartOftempSimvoloseira += simvoloseiraSoFar[i];
        }
    }

    string secondPartOfTempSimvoloseira; // All the charachters after the non-terminal symbol that i am about to replace
    for (int j = position+1 ; j < simvoloseiraSoFar.length() ; j++)
    {
        if ( j == position + 1)
        {
            secondPartOfTempSimvoloseira = simvoloseiraSoFar[j];
        }
        else
        {
            secondPartOfTempSimvoloseira += simvoloseiraSoFar[j];
        }
    }

    if(nonTerminalSymbol == 'E')
    {
        simvoloseiraSoFar = firstPartOftempSimvoloseira + "(Y)" + secondPartOfTempSimvoloseira;
        cout << "and it is going to be replaced by: (Y)" << endl;
        return simvoloseiraSoFar;
    }
    else if (nonTerminalSymbol == 'Y')
    {
        simvoloseiraSoFar = firstPartOftempSimvoloseira + "AB" + secondPartOfTempSimvoloseira;
        cout << "and it is going to be replaced by: AB" << endl;
        return simvoloseiraSoFar;
    }
    else if (nonTerminalSymbol == 'A')
    {
        randomNumber = rand() % supremumForRandA;
        if (randomNumber == 0)
        {
            simvoloseiraSoFar = firstPartOftempSimvoloseira + "E" + secondPartOfTempSimvoloseira;
            cout << "and it is going to be replaced by: E" << endl;
            return simvoloseiraSoFar;
        }
        else
        {
            simvoloseiraSoFar = firstPartOftempSimvoloseira + "n" + secondPartOfTempSimvoloseira;
            cout << "and it is going to be replaced by: n" << endl;
            return simvoloseiraSoFar;
        }
    }
    else if (nonTerminalSymbol == 'B')
    {
        randomNumber = rand() % supremumForRandB; 
        if(randomNumber == 0)
        {
            simvoloseiraSoFar = firstPartOftempSimvoloseira + "-Y" + secondPartOfTempSimvoloseira;
            cout << "and it is going to be replaced by: -Y" << endl;
            return simvoloseiraSoFar;
        }
        else if (randomNumber == 1)
        {
            simvoloseiraSoFar = firstPartOftempSimvoloseira + "+Y" + secondPartOfTempSimvoloseira;
            cout << "and it is going to be replaced by: +Y" << endl;
            return simvoloseiraSoFar;
        }
        else
        {
            simvoloseiraSoFar = firstPartOftempSimvoloseira + secondPartOfTempSimvoloseira;
            cout << "and it is going to be replaced by: ε (in other words by nothing)" << endl;
            return simvoloseiraSoFar;
        }
    }
    
    

}

int main()
{
    srand(time(0)); // Use current time as seed for random generator  

    string simvoloseira = "E"; // Always the starting symbol of the output string 
    string tempSimvoloseira;
    bool simvoloseiraIsComplete = false; // the condition for the while loop to stop
    bool foundNonTerminalSymbol;  // It shows if the string i am looking at, has any non-terminal symbols left

    //-----------------------------------------------------------------------------
    int loopCounter = 0; // It counts how many loops the while loop has done
    
    // After the 10 first loops
    // if loopCounter % 5 = 0 then the supremum of the range of the random number generator ,
    // will go up by 1.
    // This means that the possibility of the productionRules function to return ,
    // a non-terminal symbol will get lower and lower after every 5 loops

    // This is happenning in order for the while loop not to get stack at an almost infinite loop,
    // because if the possibilities are always completely even , 
    // then there is always the possibility for the returning string by the function ,
    // to always contain a non-terminal symbol

    //-----------------------------------------------------------------------------

    int supremumOfA = 2; // As it has allready been said, the supremums are going to go up
    int supremumOfB = 3; // by 1 every 5 loops after the first 10 loops

    int i;
    
    while (true)
    {
        foundNonTerminalSymbol = false;
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "The string is now: "<< simvoloseira << endl;
        //cout << "simvoloseira.length() = " << simvoloseira.length() << endl;

        loopCounter++;
        
        if (loopCounter > 10 && (loopCounter % 5 == 0) )
        {
            supremumOfA++;
            supremumOfB++;
        }

        for(i = 0 ; i < simvoloseira.length() ; i++)
        {
            //cout << "simvoloseira[i] = " << simvoloseira[i] << endl;
            //cout << "i = " << i << endl;
            if(simvoloseira[i] == 'E')
            {
                tempSimvoloseira = productionRules('E' , i , simvoloseira , supremumOfA , supremumOfB);
                simvoloseira = tempSimvoloseira;                
                foundNonTerminalSymbol = true;
                break;
            }
            else if (simvoloseira[i] == 'Y')
            {
                tempSimvoloseira = productionRules('Y' , i , simvoloseira , supremumOfA , supremumOfB);   
                simvoloseira = tempSimvoloseira;             
                foundNonTerminalSymbol = true;
                break;
            }
            else if (simvoloseira[i] == 'A')
            {
                tempSimvoloseira = productionRules('A' , i , simvoloseira , supremumOfA , supremumOfB);  
                simvoloseira = tempSimvoloseira;              
                foundNonTerminalSymbol = true;
                break;
            }
            else if (simvoloseira[i] == 'B')
            {
                tempSimvoloseira = productionRules('B' , i , simvoloseira , supremumOfA , supremumOfB);  
                simvoloseira = tempSimvoloseira;              
                foundNonTerminalSymbol = true;
                break;
            }
            else
            {
                continue;
            }
        }

        if (foundNonTerminalSymbol == false)
        {
            break;
        }

    }

    cout << "Random symbol generation has ended. Final result:" << endl;
    cout << simvoloseira << endl;  
    
}