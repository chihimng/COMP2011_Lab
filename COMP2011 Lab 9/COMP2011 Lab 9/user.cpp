#include "user.h"

// load user's information from a given file
void load_user(User users[], int *num_users, string filename)
{
	*num_users = 0;
	int id;
	char user_name[MAX_NAME_SIZE];
	ifstream ifs(filename);
	while (!ifs.eof()){
		ifs >> id >> user_name;
		add_user(users, num_users, id, user_name);
	}
	ifs.close();
}

// Add a User object to the User array, users, by the parameters, id, user_name.
// Moreover, increment the num_users accordingly.
void add_user(User users[], int* num_users, int id, const char user_name[])
{
	//TODO 3 Add Your Code Here
}

// This function returns the address of the User object in the User array, users, with the id member of the value, id.
// If not found, returns nullptr.
// Input for this function: users -- the array of User objects; 
//                          num_users -- the number of User objects in users array;
//                          id -- the id of the User object to be found. 
User *search_user_by_id(User users[], int num_users, int id)
{
	//TODO 3 Add Your Code Here
}

// This function will print user information including its ID and name
void print_user(const User *user)
{
	//TODO 3 Add Your Code Here
}