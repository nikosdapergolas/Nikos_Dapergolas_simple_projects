/*
        Data structures 1st Assignment 2020-2021

As part of the work you are asked to write a program in C ++ which will solve the problem
which follows.
A set of k linear lists Li, i = 0, 1, 2, ..., k-1 is given. As part of the work should be
use the linked representation for linear lists. See details for details
Chapter 3.4 of the book "Data Structures, Algorithms and Applications in C ++".
The data at each node for all Li lists consists of an integer. Is not
it is necessary that all lists contain the same number of nodes, while the same is allowed to appear
number more times in each list. However, the use of ready-made structures is not allowed
data provided by C ++ (C ++ Containers).

The purpose of the program you will create is to create a new output list in which you will
place the Li elements that appear in at least half of the lists. Any such
item should only appear once in the output list and all list items
output should be sorted in ascending order.

At the end of the program the initial Li lists do not have to be in the same
situation in which they were at the beginning of the program. You are allowed to remove
any items you want from each Li list or rearrange items within each Li list by
the execution time of the algorithm. However, you are not allowed to edit Li lists from
before, e.g. you are not allowed to sort the lists at the beginning of the program.

The fact that you are allowed to modify the Li lists and that the output list must be
sorted allows you to optimize your algorithm by reducing it
the number of comparisons required until the final output of the output list is possible.
Try to think of and implement such optimizations in your algorithm.

The following figure is given to clarify details. For example, although the number 11
appears several times in total, but only appears in two lists (less than half)
and so should not be included in the output list. Instead, the number 33 only appears
three times, but it appears in three different lists (more than half) and so it should
to be included in the output list. Finally, notice that the items in the output list are
classified.

Implementation issues:
- The number k of lists should be read by your program at a time
execution. Therefore, the structure that will store the entire list of Li should
is dynamically constructed at runtime.
- Then your program will have to build the lists. It should be for everyone
list Li to specify its size (the number of nodes it will consist of) and for
each node must specify the number it will contain as a given. For this purpose
a random number generator can be used. C ++ offers a set of classes and
methods for this purpose (see https://www.cplusplus.com/reference/random). To
to use these features you should:

Include <random> and <functional> header files in your program:
#include <random>
#include <functional>

o Define a random number generator:
std :: default_random_engine generator;

o Define the allowable limits and the distribution for the random generated
numbers. With the following statements we ask for the size of each list to
use a uniform distribution and the numbers produced are integers
in the interval [100, 200] (ie the size of each list should be from 100 to 200
elements), while for the number that will contain each node we ask again uniform
distribution and the numbers generated to be integers in space
[0, 50]. You are free to change these limits:

std :: uniform_int_distribution <int> list_size_distribution (100, 200);
std :: uniform_int_distribution <int> data_element_distribution (0, 50);

o For ease of use you can "tie" together the random number generator with
desired distribution:
auto random_list_size = std :: bind (list_size_distribution, generator);
auto random_element = std :: bind (data_element_distribution, generator);

o Each time you call random_list_size () and random_element () you will
a random number is generated based on the distribution and limits you have set.
E.g. the following calls generate a random number for the size of a
list in the interval [100, 200] and a random number in the interval [0, 50] that
can be used as data for a node in a list:
int list_size = random_list_size ();
int data_element = random_element ();

- As mentioned above, from the moment that the using will be created using random numbers
Li lists are not allowed to be edited unless your algorithm for
the output list construction.

*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include<ctime>

using namespace std;


//---------------Liner List START------------------------------------------------------------------------------------------------------------------------------------
template<class L>
class List
{   public:
        List(int MaxListS=200);
        //~List() {delete [] element;}
    
        int Length() const {return length;}
        

        bool find(int k, L& x) const;//anazitisi stixiou  
       
        int search(const L& x) const;

        List<L>& Delete (int k, L& x);
        List<L>& insert(int k, const L& x); //edw kanume eisagogi stixion 13

        void outS(ostream& out) const; //edo kanume output 

  
        int length;
        int sizeM; //max size 
        L *element; // dynamikos pinakas 1D

};

template<class L> 
List<L>::List(int MaxListS)
{
    sizeM = MaxListS;
    element = new L[MaxListS];
    length=0;
}

template<class L> 
bool List<L>::find(int k, L& x) const 
{
    if(k < 1 || k > length)return false;
    
        
    x=element[k-1];
    return true;
    

}

template<class L>
int List<L>::search(const L& x) const
{
    for(int i = 0; i< length; i++)
        if(element[i]==x)return ++i;
    return 0;
} 




template<class L> 
List<L>& List<L>::insert(int k, const L& x)
{   
    for(int i = length-1; i>= k; i--)
    {
        element[i+1]=  element[i];
    }
    element[k] = x;
    length++;
    return *this;
}
template<class L>
List<L>& List<L>::Delete(int k, L& x )
{
    if(find(k,x))
    {
        for (int i =k; i < length; i++)
        {
            element[i-1] = element[i];
        }
        length--;
        return *this;
    }
    else
    {
        //cout<<"no such element in list \n";  // to evala se sxolia giati enoxlei poly sto apotelesma
    }
}

template<class L> 
void List<L>::outS(ostream& out) const
{
    for(int i =0; i<length; i++)
    {
        out << element[i] << " ";
    }
}
template<class L> 
ostream& operator<<(ostream& out ,const List<L>& x)
{
    x.outS(out); 
    return out;
}
//---------------Liner List END------------------------------------------------------------------------------------------------------------------------------------
//____________________________________________________________________________________________________________________________________________________________




//---------------Linked List Start------------------------------------------------------------------------------------------------------------------------------------

template <typename Lin>
class Chain;

template <class Lin>
class Cnode
{
    friend Chain<Lin>;
    public:
        Lin data;
        Cnode<Lin> *link; 
    


};

template<class Lin>
class Chain
{
    public:
        Chain() {first =0; }
        
    
        int Length() const;
    
        bool find(int k, Lin& x) const ;
    
        int search(const Lin& x) const;
   
        Chain<Lin>& Delete(int k, Lin& x);
    
        Chain<Lin>& insert(int k, const Lin& x);
    
        void OutP(ostream& out) const;
   
        Cnode<Lin> *first; //p
};

template <class Lin>
int Chain<Lin>::Length() const
{
    Cnode<Lin> *current = first;
    int length=0;
    while(current)
    {
        length++;
        current = current ->link;
    }
    return length;
}

template <class Lin>
bool Chain<Lin>::find(int k, Lin& x) const
{
    if (k <1)
    {
        return false;
    }

    Cnode<Lin> *current = first;
    int index = 1;
    while(index < k && current)
    {
        current = current->link;
        index++;

    }
    if(current)
    {
        x = current -> data;
        return true;
        
    }   
    return false; // den to vrike to k'osto stixio 

}

template<class Lin>
int Chain<Lin>::search(const Lin& x) const
{
    Cnode<Lin> *current = first;
    int index =1;
    while(current && current->data != x)
    {
        current = current->link;
        index++;
    }
    
    if(current)
    {
        return index;
    }
    return 0;
}

template<class Lin>
void Chain<Lin>::OutP(ostream& out) const
{
    Cnode<Lin> *current;
    for(current = first; current; current=current->link)
    {
        out << current->data << "  ";

    }


}

template<class Lin>
ostream& operator<<(ostream& out, const Chain<Lin>& x)
{
    x.OutP(out);
    return out;

}

template<class Lin>
Chain<Lin>& Chain<Lin>::Delete(int k, Lin& x) // kommati gia diagrafi apo thn lista 
{
    if(k<1 || !first)
    {
        cout<<"no such k'th element \n";

    }
    Cnode<Lin> * p = first;

    if(k==1)
    {
        first= first->link;
    }
    else
    {
        Cnode<Lin> *q = first;    
        for(int index =1; index <k-1 && q; index++)
        {
            q=q->link;
        }
        if(!q || !q->link)
        {
            cout<<" so such k'th element \n";
        }
        p=q->link;
        q->link = p->link; //petas stoixio ekso apo thn alisida 
    }
    
  
    
    x=p->data;
    delete p;
    return *this;

}

template<class Lin>
Chain<Lin>& Chain<Lin>::insert(int k, const Lin& x)
{
    Cnode<Lin> *p=first;
    for(int index =1 ; index <k && p; index++)
    {
        p = p->link;
    }

    /*if(k>0 && !p)
    {
        cout<<"no such k'th element to put it after \n";
    }*/

    Cnode<Lin> *y =new Cnode<Lin>;
    y->data =x;
    if(k)
    { //vazo meta to y to stoixeio 
        y->link=p->link;
        p->link=y;
    }
    else //apla beni san proto stoixeio 
    {
        y->link=first;
        first=y;
    }

    return *this;
}





//---------------Linked List END------------------------------------------------------------------------------------------------------------------------------------
//____________________________________________________________________________________________________________________________________________________________



int main() 
{
    cout<<"How many lists would you like to create"<<endl;
    int numberOfLists;
    cin >> numberOfLists;

    cout << "Nice!" << endl;
    cout << "You chose to create " << numberOfLists << " lists" << endl;
    cout << "Now creating them..." << endl;

    bool numberOfListsIsOdd;
    if(numberOfLists % 2 == 0)
    {
        numberOfListsIsOdd = false;
    }
    else
    {
        numberOfListsIsOdd = true;
    }

    srand(time(0));

    // The following for loop is for trying to fill the lists with some nodes
    // and also for trying(through the other loop inside) to fill the nodes with random values

    vector<List<int>> vectorOfLists; // vector pou periexei oles tis gramikes listes

    for(int i = 0 ; i < numberOfLists ; i++) 
    {
        int ListSize = rand() % 200 + 100 ; // trying to set the limits between 100 and 200
        if (ListSize > 200)
        {
            ListSize -= 100;
        }

        // εδω γίνεται αρχικοποίηση της κάθε λίστας
        List<int> Li(ListSize); 

        // Σε αυτό το for loop θα γίνεται αρχικά η αρχικοποίηση της κάθε λίστας ξεχωριστά
        // θα δηλωνεται μέσω του ακριβώς απο πάνω κώδικα το πόσα κελιά θα πρέπει να γεμιστούν
        // και με το for ακριβως απο κάτω κάθε κόμβος θα παίρνει απο μία τυχαία τιμή
        
        int value;
        for(int j = 0 ; j < ListSize ; j++)
        {
            value = rand() % 220;

            // Σε αυτό το for loop θα γίνεται το γέμισμα μίας συγκεκριμένης λίστας
            // με αριθμούς από το 0 εως το 249   
            Li.insert(j,value);         

        }
        vectorOfLists.push_back(Li); 
    }

    // Μέχρι αυτό το σημείο έχουμε καταφέρει να έχουμε Κ λίστες, και να τις έχουμε επίσης γεμίσει
    
    List<int> currentList(200);
    Chain<int> sortedOutput;
    //Cnode<int> node;
    vector<int> vectorToBeSorted;
    int currentIntCounter;
    int currentInteger;
    int positionInLinkedList = 0;
    bool everythingIsEmpty = false;

    // Apo edw kai pera akolouthei o algorithmos evreshs tou poioi aritmoi yparxoun
    // se perissoteres apo tis mises listes
    for(currentInteger = 0 ; currentInteger < 220 ; currentInteger++)
    { 
        //----------------------------------------------------------------------------------------
        // Σε αυτό το for loop θα γίνουν οι πιό βασικές διαδικασίες
        
        // θα αρχίσω να ψάχνω ένα ένα τα στοιχεία από όλες τις άλλες λίστες μέχρις ότου
        // Είτε το βρω (άρα προχωράω στην επόμενη λίστα)
        // Είτε ξεπεράσω σε value αυτό που ψάχνω (άρα παλι προχωράω στην επόμενη λίστα)
        //----------------------------------------------------------------------------------------

        // setting a counter to count how many times and at how many lists the current integer appears
        currentIntCounter = 0; 
        // showing what is the current integer that i am checking
        cout << "current integer = " << currentInteger << endl;  

        for(int i = 0 ; i < vectorOfLists.size() ; i++)
        {
            //----------------------------------------------------------------------------------------
            // se auto to for loop tha arxisoume na psaxnoume gia to an yparxei o current integer
            // ->An yparxei tha ksanakanw ena for gia na ton diagrapsw apo olh( thn sygkekrimenh ) lista
            // kai epishs tha anevasw ton currentIntCounter kata 1
            // ->An den yparxei proxwraw sthn epomenh lista
            //----------------------------------------------------------------------------------------

            // setting at this variable, what is the current list i am working with
            currentList = vectorOfLists[i];
            // searching if the current integer exists in this list
            if(currentList.search(currentInteger) != 0) // if 0 then, it doesnt exist
            {
                currentIntCounter ++;
                for(int j = 0 ; j < currentList.length ; j++)
                {
                    //----------------------------------------------------------------------------------------
                    // se auto to for loop tha diagrapsw ola ta stoixeia ths listas sthn opoia vriskomai
                    // gia 2 logous:
                        // a) giati h synthiki termatismou mou einai na einai oles oi listes adeies
                        // b) gia na meiwnetai o aritmos ton anazitisiwn pou tha prepei na kanei h 
                        //    synartisi search() kai h delete()
                    //----------------------------------------------------------------------------------------
                    int intThatISearch = currentList.find(++j,intThatISearch);
                    int positionToDelete;
                    int x;

                    if(intThatISearch == currentInteger)
                    {
                        positionToDelete = currentList.search(intThatISearch);
                        currentList.Delete(positionToDelete,x);                        
                    }

                    
                }
            }            

        }

        // checking if the current integer exists at at least half of them
        if(numberOfListsIsOdd)
        {
            if(currentIntCounter > numberOfLists/2)
            {
                //in this case the current integer will  get inserted in the linked list
                cout << "inserting " << currentInteger << " in the linked list because it exists in " << currentIntCounter << " of them" << endl;

                //inserting the element in the linked list
                sortedOutput.insert(positionInLinkedList,currentInteger);
                positionInLinkedList++;


            }
            else
            {
                //in this case the current integer will  NOT get inserted in the linked list
                cout << currentInteger << " was not in at least half of the lists.." << endl;
            }        
        }
        else
        {
            if(currentIntCounter >= numberOfLists/2)
            {
                //in this case the current integer will  get inserted in the linked list
                cout << "inserting " << currentInteger << " in the linked list because it exists in " << currentIntCounter << " of them" << endl;

                //inserting the element in the linked list
                sortedOutput.insert(positionInLinkedList,currentInteger);
                positionInLinkedList++;

            }
            else
            {
                //in this case the current integer will  NOT get inserted in the linked list
                cout << currentInteger << " was not in at least half of the lists.." << endl;                

            }
        } 

    }

    // for(int i = 0 ; i <= positionInLinkedList ; i++)
    // {
    //     cout << "the sorted list is: " << sortedOutput.OutP(i) << endl;
    // }

    cout<< "hi" << endl;

    cout << "the sorted list is: " << sortedOutput << endl;

}
