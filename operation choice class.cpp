// Done By Smruthi (Will be integrated later)
#include <iostream>

using namespace std;

int main()
{

    cout << "1.Insertion" << "  2.Modification" << "  3.Deletion" ;
    cout<<"enter the number";
    int actionName;
    cin >> actionName;

    switch (actionName) 
    {
    case 1:
     
        //insetion call function
        cout << "Insertion";
        //call the insertion here
        break;
    case 2:
        // modification call function
        cout << "Modification";
        break;
    case 3:
        // modification call function
           cout << "Deletion";
        break;
    default:
        cout << "Error, enter valid actionName.";
    }
    return 0;


    return 0;
}

