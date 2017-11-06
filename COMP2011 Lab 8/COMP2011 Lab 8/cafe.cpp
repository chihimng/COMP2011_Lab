//============================================================================
// Name        : cafe.cpp
// Author      : Serafeim Papadias
// Description : comp2017 2017S
//============================================================================

// TODO 7: Include appropriate header
#include "cafe.h"

float calc_avg_rating(const Cafe& c)
{
	// Calculate average rating
	float sum_ratings = 0.0;
	for (int i = 0 ; i < c.num_of_ratings ; i++ )
		sum_ratings += c.ratings[i];

	float avg_rating;

	if (c.num_of_ratings > 0)
		avg_rating = sum_ratings / static_cast<float>(c.num_of_ratings);
	else
		avg_rating = 0;
	// Return the average
	return avg_rating;
}

void print_cafe(const Cafe& c)
{

	cout << "< " << c.name << ", Coordinates: (" << c.location.x << "," << c.location.y <<"), AVG_rating: " << calc_avg_rating(c) << " >" << endl;
}


// Write the extra functions needed here

void add_cafe(Cafe cafes[], int& cafe_num, const char cafe_name[],  const Point& location)
{
    if (cafe_num >= MAX_CAFE_NUM) {
        cout << "No space to add more cafes." << endl;
        return;
    }
    Cafe temp = {"", {location.x, location.y}, {}, 0};
    strcpy(temp.name, cafe_name);
    cafes[cafe_num] = temp;
    cafe_num += 1;
}

void add_rating(Cafe cafes[], int cafe_index,  float rating)
{
    if (cafes[cafe_index].num_of_ratings >= MAX_RATINGS_NUM) {
        cout << "No space to add more ratings for this cafe." << endl;
        return;
    }
    int& ratingIndex = cafes[cafe_index].num_of_ratings;
    cafes[cafe_index].ratings[ratingIndex] = rating;
    ratingIndex += 1;
}

void recommend_based_on_rating(const Cafe cafes[], int cafe_num)
{
	// TODO 3: According to Part 4 in the lab description. Recommend the cafe with the highest average rating.
    int currentMaxCafeIndex = 0;
    int currentMaxCafeAvgRating = 0;
    for (int i = 0; i < cafe_num; i++) {
        int avgRating = calc_avg_rating(cafes[i]);
        if (avgRating > currentMaxCafeAvgRating) {
            currentMaxCafeAvgRating = avgRating;
            currentMaxCafeIndex = i;
        }
    }
    print_cafe(cafes[currentMaxCafeIndex]);
}

void recommend_based_on_distance(const Cafe cafes[], const Point& my_location, int cafe_num, int N)
{
	// TODO 4: According to Part 5 in the lab description. Return the N nearest cafes (no need to sort).
    struct CafeWithDist {
        Cafe cafe;
        float distance;
    };
    CafeWithDist cafeWithDistList[MAX_CAFE_NUM] = {};
    for (int i = 0; i < cafe_num; i++) {
        cafeWithDistList[i].cafe = cafes[i];
        cafeWithDistList[i].distance = euclidean_distance(my_location, cafes[i].location);
    }
    for (int i = 0; i < cafe_num; i++) {
        for (int j = 0; j < cafe_num - i; j++) {
            if (cafeWithDistList[i].distance < cafeWithDistList[j].distance) {
                CafeWithDist temp = cafeWithDistList[i];
                cafeWithDistList[i] = cafeWithDistList[j];
                cafeWithDistList[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        print_cafe(cafeWithDistList[i].cafe);
    }
}
