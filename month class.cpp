// Done By Smruthi (Will be integrated later)

#include <iostream>

using namespace std;

int main()
{
    //call the read document here
cout<<"enter one of the 12 months in number\n";
cout << "1.Jan\n"<<"2.Feb\n"<<"3.Mar\n"<<"4.Apr\n"<<"5.May\n"<<"6.Jun\n"<<"7.Jul\n"<<"8.Aug\n"<<"9.Sep\n"<<"10.Oct\n"<<"11.Nov\n"<<"12.Dec\n";
cout<<"enter the number";
    int month;
    cin >> month;

    switch (month) //switch quantity not an integer.
    {
    case 1:
     
        cout << "Jan";
        //call operation choice here
        break;
    case 2:
     
        //call operation choice here
        cout << "Feb";
        break;
    case 3:
     //call operation choice here
        cout << "Mar";
        break;
    case 4:
     //call operation choice here
        cout << "Apr";
    
        break;
    case 5:
     cout << "May";
        //call and do the action
        break;
    case 6:
        cout << "Jun";
        //call and do the action
        break;
    case 7:
        cout << "Jul";
        //call and do the action
        break;
    case 8:
        cout << "Aug";
        //call and do the action
        break;
    case 9:
        cout << "Sep";
        //call and do the action
        break;
    case 10:
        cout << "Oct";
        //call and do the action
        break;
    case 11:
        cout << "Nov";
        //call and do the action
        break;
    case 12:
        cout << "Dec";
        //call and do the action
        break;
    default:
        cout << "Error, enter valid actionName.";
    }
    return 0;


    return 0;
}


//void MonthMenu(
  //  {
        
        