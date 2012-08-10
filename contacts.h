


#include "hash_table.h"
#include <iostream>
#include <cstring>
using namespace std;

class contacts {
public:
	contacts(int size); //constructor will hash table constructor with size as argument
	~contacts();
	int add(char to_add[]);
	char * retrieve(char search_contact[], char * blank_array); //second argument should be a blank pointer
	int display(char search_contact[]);
	int remove(char search_contact[]);

private:
	hash_table * contact_list;
};
   
