#include<bits/stdc++.h>
using namespace std;
class Addressbook
{
    void addContacts();
    void editContact();
    void deleteContact();
    void viewContacts();
    void searchContact();
    public:
    Addressbook();
    void display()
    {
        cout<<"done";
    }

}ab;
Addressbook::Addressbook()
{
    bool run=true;
    do
    {
        int Option;               
        cout << "----------------------Address Book-----------------------------" << endl;
        cout << "\n";
        cout << "What would you like to do?" << endl;
        cout << "1.) Add Contact" << endl;
        cout << "2.) Edit Contact" << endl;
        cout << "3.) Delete Contact" << endl;
        cout << "4.) View All Contacts" << endl;
        cout << "5.) Search Address Book" << endl;
        cout << "6.) Exit" << endl << endl;
        cout << "Choose an option: ";
        cin >> Option;
        switch (Option)
        {
            case 1:
            {
                addContacts();
                break;
            }
            case 2:
            {
                editContact();
                break;
            }
            case 3:
            {
                deleteContact();
                break;
            }
            case 4:
            {
                viewContacts();
                break;
            }
            case 5:
            {
                searchContact();
                break;
            }
            case 6:
            {
                run = false;
                break;
            }
            default:
            {
                cout << "Please Choose between 1 to 6" <<endl;
            }
        }
    } while(run);
    cout << "Program Terminated";
}

void Addressbook::addContacts()
{
    system("cls");
    string Fname,Lname,Address,Contact,List,name,Fname2,Lname2,Address2,Contact2;
    double counter,number=0;
    cout << "----------------------Address Book-----------------------------" << endl<<endl;
    cout<<"Do not use spaces if entry has 2 or more words"<<endl;
    cout<<"Enter 'quit' at first name to quit"<<endl;
    cout<<"Enter first name: "<<endl;
    cin>>Fname;
    if(Fname=="quit")
    Addressbook();
    cout<<"Enter last name: ";
    cin>>Lname;
    cout<<"Enter Address: ";
    cin>>Address;
    cout<<"Enter Contact Number: ";
    cin>>Contact;
    ifstream asd("AddressBook.txt");
    while(asd >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (counter == 100)
        {
            cout << "Invalid Max number of contacts reached (100).";
        }
        else number = counter;
    }
    ofstream adb("AddressBook.txt", ios::app);
    number = number + 1;
    adb << number << " " << Fname << " " << Lname
    << " " << Address << " " << Contact << endl;
    system("pause");
    system("cls");
}
void Addressbook::editContact()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
    ifstream edit("AddressBook.txt");
    ofstream temp("Temp.txt", ios::app);
    cout << "Please type the Entry number that you wish to edit: ";
    cin >> choice;
    cout << endl;
    if (choice==0 || choice > 100)
    {
        cout << "Error, wrong entry";
        system("pause>0");
        Addressbook();
    }
    while (edit >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
    {
            if (counter==choice)
            {
                cout << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl<<endl;
                cout << "Is this the contact that you wish to edit? (y or n) ";
                cin >> choice3;
                cout <<endl;
            }
            if (choice3=="n") 
            {
                Addressbook();
            }
            if (choice3=="y")
            {
                if (counter<choice)
                {
                    temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
                }
                if (counter==choice)
                {
                    cout << "Enter New First name: ";
                    cin >> Fname;
                    cout << "Enter New Last name: ";
                    cin >> Lname;
                    cout << "Enter New Address: ";
                    cin >> Address;
                    cout << "Enter New Contact: ";
                    cin >> Contact;    
                    temp << choice << " " << Fname << " "<< Lname << " " << Address << " " << Contact << endl;
                }
                if (counter > choice)
                {
                    temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
                }
            }
    }
        
edit.close();
temp.close();
        
if (remove("AddressBook.txt")==0)
{
    cout << "Succesful Removing File" << endl;
}
else
{
    cout << "Error removing"<< endl;
}
if(rename("Temp.txt", "AddressBook.txt")==0)
{
    cout << "Succesful Renaming file"<< endl;    
}
else
{
    cout << "Error renaming"<<endl;
}
system("pause");
system("cls");
}
void Addressbook::deleteContact()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2,choice3;
    ifstream edit("AddressBook.txt");
    ofstream temp("Temp.txt", ios::app);
    cout << "Please type the Entry number that you wish to delete: ";
    cin >> choice;
    cout << endl;
    
    while (edit >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
    {
        if (counter==choice)
        {
            cout << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl<<endl;
            cout << "Is this the contact that you wish to delete? (y or n) ";
            cin >> choice3;
            cout << endl;
        }
        if (choice3=="n") 
        {
            Addressbook();
        }
        if (counter<choice)
        {
            temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        if (counter > choice)
        {
            temp << counter - 1 << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
    }
    
    
    
edit.close();
temp.close();
        
if (remove("AddressBook.txt")==0)
{
    cout << "Succesful Removing File" << endl;
}
else
{
    cout << "Error removing"<< endl;
}
if(rename("Temp.txt", "AddressBook.txt")==0)
{
    cout << "Succesful Renaming file"<< endl;    
}
else
{
    cout << "Error renaming"<<endl;
}
system("pause");
system("cls");
}
void Addressbook::viewContacts()
{
    system("cls");
    double counter;
    string Fname, Lname, Address, Contact;
    ifstream addressbook("AddressBook.txt");
    cout << "Entry #" << setw(17) << "First Name" << setw(23)<< "Last Name" << setw(23) <<"Address"<< setw(29)<<"Contact"<< endl << endl;
    while (addressbook >> counter >> Fname >> Lname >> Address >> Contact)
    {
        cout << setw(3)<< counter << setw(18)<< Fname << setw(25) << Lname << setw(25) << Address << setw(30) << Contact << endl;
    }
    cout << endl;
    system ("pause");
    system ("cls");
}
void Addressbook::searchContact()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2;
    cout << "----------------------Address Book-----------------------------" << endl << endl;
    cout << "---Search Address Book---" << endl;
    cout << "1.) First name" << endl;
    cout << "2.) Last name" << endl;
    cout << "3.) Address" << endl;
    cout << "4.) Contact " << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            cout << "Enter First Name: ";
            cin >> Fname;
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Enter Last Name: ";
            cin >> Lname;
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Enter Address: ";
            cin >> Address;
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Enter Contact: ";
            cin >> Contact;
            cout << endl;
            break;
        }
        default:
        {
            cout << "Please Enter choice from 1 to 4";
            searchContact();

        }
    }
    ifstream search("AddressBook.txt");
    if (choice==1)
    {
        while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
        {
            if(Fname == Fname2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
            }
        }
    }
    if (choice==2)
    {
        while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
        {
            if(Lname == Lname2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
            }
        }
    }
    if (choice==3)
    {
        while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
        {
            if(Address == Address2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl <<endl;
            }
        }
    }
    if (choice==4)
    {
        while (search >> counter >> Fname2 >> Lname2>> Address2 >> Contact2)
        {
            if(Contact == Contact2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl << endl;
            }
        }
    }
    system ("pause");
    system ("cls"); 
}
int main()
{
   ab;
}