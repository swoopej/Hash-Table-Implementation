

#include "apps.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructor
apps::apps(int size) {
	apps_list = new hash_table(size);
}

//destructor
apps::~apps() {
	delete apps_list;
}

//add function calls add function in hash_table.cpp
int apps::add(char to_add[]) {
	apps_list -> add(to_add);
	return 1;
}

//retrieve function calls retrieve in hash_table class.  First argument is search term, second argument is blank pointer that will be filled with data 
//if the search term is found
char * apps::retrieve(char search_app[], char * blank_array) {
	apps_list -> retrieve(search_app, blank_array);
	return blank_array;
}

//display function calls display in hash_table class
int apps::display(char search_app[]) {
	apps_list -> display(search_app);
	return 1;
}

//remove function calls remove in hash_table class
int apps::remove(char search_app[]) {
	apps_list -> remove(search_app);
	return 1;
}
