#include <iostream>
using namespace std;

int main()
{
    char monthToView[10];
    cout << "What month do you want to view? (Input name): ";
    cin >> monthToView;

    //TODO function searches linked list check if monthToView is in it

    //  MonthMenu(monthToView);
    DisplayMainMenu();    
    
    return 0;
}

//void MonthMenu(
  //  {
        
        
//    })

void DisplayMainMenu()
{
   cout<<("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n");
   cout<<("===================================================== \n");
   cout<<(" \tWelcome to the Budget Planner\t \n ");
   cout<<(" \t\tTeam 1\t \n ");
   cout<<("===================================================== \n");
   
  //call for summery

   cout<<("1.Open month\n");
   cout<<("2.Exit\n");
}
void action_in_menu()
{
    int actionName;
    cout << "Select the action by entering the number: "
    cout << "[1] Insertion" << "\n" << "[2] Modification" << "\n" << "[3] Deletion";
    cin >> actionName;

    switch (actionName) //switch quantity not an integer.
    {
    case 1:
        //insetion call function
        //call the month here and do the action
        break;
    case 2:
        //call the month here and do the action
        // modification call function
        break;
    case 3:
        // modification call function
        //call the month here and do the action
        break;
        
    default:
        cout << "Error, enter valid actionName.";
    }
    return;
    
}