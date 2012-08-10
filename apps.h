

#include "hash_table.h"
#include <iostream>
#include <cstring>
using namespace std;

class apps {
public:
	apps(int size);
	~apps();
	int add(char to_add[]);
	char * retrieve(char search_app[], char * blank_array);
	int display(char search_game[]);
	int remove(char search_game[]);

private:
	hash_table * apps_list;

};
