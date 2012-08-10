

#include "hash_table.h"
#include <iostream>
#include <cstring>
using namespace std;

//node struct
node::node() {
	data = NULL;
	next = NULL;
}

//constructor with int
hash_table::hash_table(int size) {
	table_size = size;
	ht = new node * [size];
}

//destructor loops through the linked list stored at each node
hash_table::~hash_table() {
	for (int i = 0; i < table_size; i++) {
		node * current = ht[i];
		node * temp = current;
		while (current != NULL) {
			current = current -> next;
			delete temp;
		}
		ht[i] = NULL;
	}
}

//adding to the table
int hash_table::add(char new_data[]) {
	int index = hash_function(new_data);
	
	//uncomment the following to see the index of each item added
	//cout<<index<<endl; 

	node * new_node = new node;
	new_node -> data = new char[strlen(new_data) + 1];
	strcpy(new_node -> data, new_data);
	new_node -> next = ht[index];
	ht[index] = new_node;
}

//retrieve function
char * hash_table::retrieve(char search_data[], char * blank_array) {
	int index = hash_function(search_data);
	node * current = ht[index];
	if (!current) {
		return blank_array;
	} else {
		while(current != NULL) {
			if(strcmp(search_data, current -> data) == 0) { //if the search term is found
				blank_array = new char[strlen(current -> data) + 1]; //allocate
				strcpy(blank_array, current -> data); //copy into the new memory
			}
			current = current -> next;
		}
		return blank_array; //return to client
	}

}

//display function to client
int hash_table::display(char search_data[]) {
	int index = hash_function(search_data);
	node * current = ht[index];
	if (!current) {
		return 0;
	} else {
		while(current != NULL) {
			if(strcmp(current -> data, search_data) == 0) { //if match is fond
			cout<<current -> data;
			return 1;
			}
			current = current -> next;
		}
		
		return 1;
	}
}

//remove function
int hash_table::remove(char search_data[]) {
	int index = hash_function(search_data);
	node * current = ht[index];
	node * previous = current;
	if (!current) {
		return 0;
	} else {
		while(current != NULL) {
			if(strcmp(current -> data, search_data) == 0) {//if match is found
			previous -> next = current -> next; //connect up around current
			delete current;
			return 1;
			}
			current = current -> next;
		}
		
		return 1;
	}
}

//hashing function that uses the first two characters' ascii values times seven mod table size to compute the array index 
int hash_table::hash_function(char data[]) {
	int sum = ((int)data[1] + (int)data[2]) * 7;
	int hash = sum % table_size;
	return hash; //returns hash to calling function
}

