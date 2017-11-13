#ifndef CAFE_H_
#define CAFE_H_

// TODO 6: Include appropriate header
#include "user.h"
#include "utils.h"
#include "point.h"

// TODO 4: Add and Definie all the appropriate global variables here
const int MAX_NAME_LENGTH = 10;
const int MAX_CAFE_NUM = 10;
const int MAX_RATINGS_NUM = 10;




// TODO 1: Add the necessary Cafe struct here
struct Rating{
	User *user_ptr;
	float rating;
};
struct Cafe{
    char name[MAX_NAME_LENGTH];
    Point location;
    Rating ratings[MAX_RATINGS_NUM];
    int num_of_ratings;
};







// TODO 5: Add the appropriate function declarations here.
float calc_avg_rating(const Cafe*);  // given
void load_cafe(Cafe[], int*, string);  // given
void load_rating(Cafe[], int, User[], int);  // given









#endif /* CAFE_H_ */
