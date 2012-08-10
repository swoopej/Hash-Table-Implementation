

#include "contacts.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructor uses argument as size for array
contacts::contacts(int size){
	contact_list = new hash_table(size);	
}

//destructor
contacts::~contacts() {
	delete contact_list;
}

//add function calls add function in hash_table.cpp
int contacts::add(char to_add[]) {
	contact_list -> add(to_add);
	return 1;
}

//retrieve function calls retrieve in hash_table class.  First argument is search term, second argument is blank pointer that will be filled with data 
//if the search term is found
char * contacts::retrieve(char search_contact[], char * blank_array) {
	contact_list -> retrieve(search_contact, blank_array);
	return blank_array;
}

//display function calls display in hash_table class
int contacts::display(char search_contact[]) {
	contact_list -> display(search_contact);
	return 1;
}

//remove function calls remove in hash_table class
int contacts::remove(char search_contact[]) {
	contact_list -> remove(search_contact);
	return 1;
}
