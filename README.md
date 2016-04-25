# Shioshita_CSCI2270_FinalProject
CSCI 2270 Final Project
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

How to Run
When the program is started it will print out a menu with all of the different functions
the Wish List can perform. The user is then able to enter a number corresponding to the 
action that the user wants it to perform. If the user selects 1, the entire Wish List
is printed, with the item, who supplies the item, and how much the item costs. If the user 
selects 2, they can insert a new item into their wish list. The user is prompted for
the item, who supplies the item, and how much the item costs. The item is then stored 
in a hash table so they can insert as many items as they want. If the user selects 3, the
user can delete all instances of an item. If the user inserted the same item multiple times
but the item is supplied by different companies, all items of the same type will be
deleted. If the user only wants to delete a specific item they will select 4. The
program will prompt the user for the item name, who supplies it, and the price. If the 
user selects 5, they will have the option to edit an item already in the Wish List.
The user will be promted with an item name and then the program will go through
every item that has the same item name. The program will then print out an item and
ask the user if they want to edit the select item. If the user types in "yes", they
will be propted with the new item name, supplier, and price. If the user types in
"no" the program will ask the user if they want to edit the next item, with the same
name until the user edits the item or there are no more items with the same name.


