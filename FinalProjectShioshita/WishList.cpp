#include <iostream>
#include <cstdlib>
#include "HashTable.h"
using namespace std;

int main()
{
    int user;
    HashTable h1;
    while(user!=9)
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. View Wish List"<<endl;
        cout<<"2. Add to Wish List"<<endl;
        cout<<"3. Delete All Items of One Type"<<endl;
        cout<<"4. Delete One Item"<<endl;
        cout<<"5. Edit item"<<endl;
        cout<<"6. Find Item"<<endl;
        cout<<"7. Make a decision"<<endl;
        cout<<"8. Save wish list"<<endl;
        cout<<"9. Quit"<<endl;
        cin >>user;
        if(user==1)
        {
            h1.printTableContents(); //Prints movie contents
        }
        else if(user==2) //Add title
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            cout<<"Enter supplier:"<<endl;
            string data2;
            getline(cin,data2);
            cout<<"Enter price:"<<endl;
            string data3;
            getline(cin,data3);
            double price=atof(data3.c_str());
            h1.insertItem(data, data2, price); //Inserts item
        }
        else if(user==3)
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            h1.deleteItem(data);
        }
        else if(user==4) //Delete specific item
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            cout<<"Enter supplier:"<<endl;
            string data2;
            getline(cin,data2);
            cout<<"Enter price:"<<endl;
            string data3;
            getline(cin,data3);
            double price=atof(data3.c_str());
            h1.deleteSpecific(data, data2, price);
        }
        else if(user==5)
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            h1.editItem(data);
        }
        else if(user==6)
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            h1.findItem(data);
        }
        else if(user==7)
        {
            cout<<"Enter item:"<<endl;
            string data;
            cin.ignore(256,'\n');
            getline(cin,data);
            h1.makeDecision(data);
        }
        else if(user==8)
        {
            h1.saveWishList();
            cout<<"Your Wish List has been saved"<<endl;
        }
        else if(user==10) //Quit
        {
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
