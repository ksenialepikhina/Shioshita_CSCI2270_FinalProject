#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string item;
	std::string supplier;
	int price;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(std::string in_item, int in_supplier)
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
		void insertItem(std::string item, std::string supplier, int price);
		void deleteItem(std::string item);
		void findItem(std::string item);
	private:
		int hashSum(std::string x, int s);
		int tableSize = 10;
		HashElem* hashTable[10];


};

#endif // HASHTABLE_H
