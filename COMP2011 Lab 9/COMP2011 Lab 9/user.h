#ifndef USER_H_
#define USER_H_

#include "utils.h"
#include "point.h"

const int MAX_USER_NUM  = 100;
const int MAX_NAME_SIZE = 100;

struct User{
	int id;
	char name[MAX_NAME_SIZE];
};

void load_user(User[], int*, string); // given
void add_user(User[], int*, int, const char[]); // TODO 3
void print_user(const User*);  // TODO 3
User *search_user_by_id(User[], int, int);  // TODO 3


#endif /* USER_H_ */
