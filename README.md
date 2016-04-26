# Shioshita_CSCI2270_FinalProject
CSCI 2270 Final Project: "Smart" Wish List

This program creates a "smart" wish list that will help people store items they are
are interested in buying, where to purchase the item, and how much it costs. 
The program will allow the user to add items to the list, delete items from the 
list and compare similar items, ultimately helping the user decide what to 
purchase. The user will be able to delete all items of a specific type 
or delete a single item. In addition, users will be able to edit a specific item.
Once the user is done making their wish list, their list can be saved
to a text file. The data in this program will be stored in a hash table since,
items that are the same will be stored at the same index, even though their
supplier and price may differ. This will make it easier for comparison between
items, based on who sells it and how much it costs.

How to Run:

The three files you need to run the program are called HashTable.cpp, HashTable.h, and main.cpp.

When the program is started it will print out a menu with all of the different functions
the Wish List can perform. The user is then able to enter a number corresponding to the 
action that the user wants. 

If the user selects 1, the entire Wish List is printed, with the item name, who supplies 
the item, and how much the item costs. 

If the user selects 2, they can insert a new item into their wish list. The user is prompted 
for the item name, who supplies the item, and how much the item costs. The item is then stored 
in a hash table so users can insert as many items as they want. 

If the user selects 3, the user can delete all instances of an item. If the user 
inserted the same item multiple times but the item is supplied by different companies, 
all items of the same type will be deleted. 

If the user only wants to delete a specific item they will select 4. The
program will prompt the user for the item name, who supplies it, and the price. The program
then searchs the list for an item that matches all three specifications and then deletes
the item. 

If the user selects 5, they will have the option to edit an item already in 
the Wish List. The user will be promted with an item name and then the program will go through
every item that has the same item name. The program will then print out an item and
ask the user if they want to edit the select item. If the user types in "yes", they
will be propted with the new item name, supplier, and price. If the user types in
"no" the program will ask the user if they want to edit the next item, with the same
name until the user edits the item or there are no more items with the same name.

If the user selects 6, they will be able to search the wish list for a certain
item name. The program will then print out the item name, supplier, and price, of all
the items that match the item the user is searching for.

If the user selects 7, the program will help the user decide which item they
should purchase. The program will prompt the user with the item that they are curious
about, and tell the user which item has the lowest price, and where to get it. 

If the user selects 8, they will have the ability to create a text file that saves
their Wish List. The text file will contain all of the items that are currently in the 
Wish List with the supplier, and price listed. 

If the user selects 9, the program will be exited.

System Requirements: Linux

