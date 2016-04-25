#include "HashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

int HashTable::hashSum(string key, int tableSize)
{
    int sum=0;
    for(int i=0;i<key.size();i++)
    {
        sum=sum+key[i]; //Gets ascii value of string
    }
    sum=sum%tableSize; //Divides ascii value by table size
    return sum; //Returns hash sum
}
void HashTable::insertItem(string item, string supplier, double price)
{
    HashElem *m=new HashElem; //Creates new hashElem
    m->item=item;
    m->supplier=supplier;
    m->price=price;
    m->next=NULL;
    m->previous=NULL;
    int index=hashSum(item, tableSize);
    if(hashTable[index]==NULL) //No element at hashTable index
    {
        hashTable[index]=m;
    }
    else if(hashTable[index]!=NULL)//Element already at hashTable index
    {
        HashElem *temp=new HashElem; //Temp pointer to traverse the linked list
        temp=hashTable[index];
        while(temp->next!=NULL)//Finds the end
        {
            temp=temp->next;
        }
        m->previous=temp; //Sets the new element's previous
        temp->next=m; //Makes the new element the last in the linked list
    }
}
void HashTable::deleteItem(string name)
{
    int index=hashSum(name,tableSize); //gets the index of the title to be deleted
    HashElem *m=hashTable[index];
    bool found=false;
    if(m!=NULL)
    {
        HashElem *temp=m; //Temp pointer to traverse linked list
        while(temp!=NULL)
        {
            if(temp->item==name)
            {
                found=true;
                if(temp->previous==NULL) //First element in the list
                {
                    if(temp->next==NULL) //Only one element in the list
                    {
                        hashTable[index]=NULL;
                    }
                    else
                    {
                        hashTable[index]=temp->next; //First element in the list is the temp's next
                        hashTable[index]->previous=NULL; //New first element's previous is NULL
                    }
                    temp=temp->next; //Exit the while
                }
                else
                {
                    if(temp->next!=NULL) //Delete middle element
                    {
                        temp->next->previous=temp->previous;
                        temp->previous->next=temp->next;
                        temp=temp->next;
                    }
                    else //Delete last element
                    {
                        temp->previous->next=temp->next;
                        temp=temp->next;
                    }
                }
            }
            else
            {
                temp=temp->next; //Moves to the next element
            }
        }
    }
    if(found==false)
    {
        cout<<"Item not found"<<endl;
    }
    else if(found==true)
    {
        cout<<"All instances of item deleted"<<endl;
    }
}
void HashTable::printTableContents()
{
    bool found=false; //Checks if the hash table is empty
    for(int i=0;i<tableSize;i++)
    {

        if(hashTable[i]!=NULL)
        {
            found=true; //Hash table isn't empty
            HashElem *temp=hashTable[i]; //Temp pointer traverses the linked list
            while(temp!=NULL)
            {
                cout<<temp->item<<" : "<<temp->supplier<<" - "<<temp->price<<endl; //Prints title and year
                temp=temp->next;
            }
        }
    }
    if(found==false) //Hash table is empty
    {
        cout<<"Your Wish List is Empty"<<endl;
    }
}
void HashTable::findItem(string name)
{
    int index=hashSum(name,tableSize); //Finds the index where the item should be located
    HashElem *m=hashTable[index];
    bool found=false; //Checks if the item is found in the list
    if(m!=NULL)
    {
        HashElem *temp=m;
        cout<<"======"<<temp->item<<"======"<<endl;
        while(temp!=NULL)
        {
            if(temp->item==name)
            {
                cout<<temp->supplier<<" - "<<temp->price<<endl;
                found=true;
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    if(found==false) //If item not found
    {
        cout<<"Item not found"<<endl;
    }
}
void HashTable::makeDecision(string item)
{
    int index=hashSum(item, tableSize);
    vector<HashElem *> compare;
    HashElem *m=hashTable[index];
    if(m!=NULL)
    {
        while(m!=NULL)
        {
            if(m->item==item)
            {
                compare.push_back(m);
                m=m->next;
            }
            else
            {
                m=m->next;
            }
        }
        if(!compare.empty())
        {
            HashElem *temp=compare.front();
            for(int i=0;i<compare.size();i++)
            {
                if(temp->price>compare[i]->price)
                {
                    temp=compare[i];
                }
            }
            cout<<"The best value is: "<<temp->item<<" : "<<temp->supplier<<" - "<<temp->price<<endl;
        }
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
}
void HashTable::saveWishList()
{
    ofstream myfile;
    myfile.open("WishList.txt");
    bool found=false; //Checks if the hash table is empty
    myfile<<"******Wish List******"<<endl;
    for(int i=0;i<tableSize;i++)
    {

        if(hashTable[i]!=NULL)
        {
            found=true; //Hash table isn't empty
            HashElem *temp=hashTable[i]; //Temp pointer traverses the linked list
            while(temp!=NULL)
            {
                myfile<<temp->item<<" : "<<temp->supplier<<" - "<<temp->price<<endl;
                temp=temp->next;
            }
        }
    }
    if(found==false) //Hash table is empty
    {
        myfile<<"Your Wish List is Empty"<<endl;
    }
}
void HashTable::editItem(string item)
{
    int index=hashSum(item,tableSize);
    HashElem *temp=hashTable[index];
    bool found=false;
    string user="no";
    while(temp!=NULL&&user!="yes")
    {
        cout<<"Edit this item: ";
        cout<<temp->item<<" : "<<temp->supplier<<" - "<<temp->price<<"?"<<endl;
        cin>>user;
        if(user=="yes")
        {
            found=true;
            cout<<"Enter any changes to the item:"<<endl;
            string item;
            cin>>item;
            temp->item=item;
            cout<<"Enter any changes to the supplier:"<<endl;
            string supplier;
            cin>>supplier;
            temp->supplier=supplier;
            cout<<"Enter any changes to the price:"<<endl;
            string price;
            cin>>price;
            double price1=atof(price.c_str());
            temp->price=price1;
        }
        temp=temp->next;

    }
    if(found==false)
    {
        cout<<"Item not found"<<endl;
    }
}
void HashTable::deleteSpecific(string item, string supplier, double price)
{
    int index=hashSum(item,tableSize);
    bool found=false;
    HashElem*temp=hashTable[index];
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            if((temp->item==item) && (temp->supplier==supplier) && (temp->price=price))
            {
                found=true;
                if(temp->previous==NULL) //First element in the list
                {
                    if(temp->next==NULL) //Only one element in the list
                    {
                        hashTable[index]=NULL;
                    }
                    else
                    {
                        hashTable[index]=temp->next; //First element in the list is the temp's next
                        hashTable[index]->previous=NULL; //New first element's previous is NULL
                    }
                    temp=NULL;//Exit the while
                }
                else
                {
                    if(temp->next!=NULL) //Delete middle element
                    {
                        temp->next->previous=temp->previous;
                        temp->previous->next=temp->next;
                        temp=temp->next;
                    }
                    else //Delete last element
                    {
                        temp->previous->next=temp->next;
                        temp=temp->next;
                    }
                }
                cout<<"Item deleted"<<endl;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    if(found=false)
    {
        cout<<"Item not found"<<endl;
    }
}
HashTable::HashTable()
{
    //ctor
    for(int i=0;i<tableSize;i++) //Initialize the hash table
    {
        hashTable[i]=NULL;
    }
}

HashTable::~HashTable()
{
    //dtor
}
