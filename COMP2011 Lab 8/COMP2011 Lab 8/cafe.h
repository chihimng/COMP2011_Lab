//============================================================================
// Name        : cafe.h
// Author      : Serafeim Papadias
// Description : comp2017 2017S
//============================================================================

#ifndef LAB8_CAFE_H_
#define LAB8_CAFE_H_

// TODO 7: Include appropriate header
#include "point.h"

// TODO 5: Definite all the appropriate global variables here
const int MAX_NAME_LENGTH = 10;
const int MAX_CAFE_NUM = 10;
const int MAX_RATINGS_NUM = 10;

// TODO 1: Create the necessary Cafe struct here
struct Cafe {
    char name[MAX_NAME_LENGTH];
    Point location;
    float ratings[MAX_RATINGS_NUM];
    int num_of_ratings;
};

// TODO 6: Fill in the appropriate function declarations here.
void add_cafe(Cafe cafes[], int& cafe_num, const char cafe_name[],  const Point& location);
void add_rating(Cafe cafes[], int cafe_index,  float rating);
void recommend_based_on_rating(const Cafe cafes[], int cafe_num);
void recommend_based_on_distance(const Cafe cafes[], const Point& my_location, int cafe_num, int N);
#endif /* LAB8_CAFE_H_ */
