

#ifndef hash_table_h_included
#define hash_table_h_included

#include <iostream>
#include <cstring>
using namespace std;

struct node {
	node();
	char * data;
	node * next;
};

class hash_table {
public:
	hash_table(int size); //must pass in integer (preferably prime)
	~hash_table();
	int add(char data[]);
	char * retrieve(char search_data[], char * blank_array);
	int display(char search_data[]);
	int remove(char search_data[]);

private:
	int hash_function(char data[]);
	node ** ht;
	int table_size;
};

#endif
