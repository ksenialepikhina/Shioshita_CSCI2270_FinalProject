#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

using namespace std;

struct HashElem{
	string item;
	string supplier;
	double price;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(string in_item, int in_supplier)
	{
		item = in_item;
		supplier = in_supplier;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printTableContents();
		void insertItem(string item, string supplier, double price);
		void deleteItem(string item);
		void findItem(string item);
		void makeDecision(string item);
		void saveWishList();
		void editItem(string item);
		void deleteSpecific(string item, string supplier, double price);
		void countItems();//Ksenia Lepikhina's function

	private:
		int hashSum(string x, int s);
		int tableSize = 10;
		HashElem* hashTable[10];


};

#endif // HASHTABLE_H
