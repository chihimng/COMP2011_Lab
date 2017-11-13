#ifndef CAFE_H_
#define CAFE_H_

// TODO 6: Include appropriate header



// TODO 4: Add and Definie all the appropriate global variables here





// TODO 1: Add the necessary Cafe struct here
struct Rating{
	User *user_ptr;
	float rating;
};








// TODO 5: Add the appropriate function declarations here.
float calc_avg_rating(const Cafe*);  // given
void load_cafe(Cafe[], int*, string);  // given
void load_rating(Cafe[], int, User[], int);  // given









#endif /* CAFE_H_ */
