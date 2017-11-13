#include "utils.h"
#include "cafe.h"
#include "point.h"

// calculate average rating of a cafe
float calc_avg_rating(const Cafe* c)
{
	float sum_ratings = 0.0;
	for (int i = 0 ; i < c->num_of_ratings ; i++ )
		sum_ratings += c->ratings[i].rating;

	float avg_rating;

	if (c->num_of_ratings > 0)
		avg_rating = sum_ratings / static_cast<float>(c->num_of_ratings);
	else
		avg_rating = 0;

	return avg_rating;
}

// load cafes from a given file
void load_cafe(Cafe cafes[], int *cafe_num, string filename)
{
	*cafe_num = 0;
	Point p;
	char cafe_name[MAX_NAME_LENGTH];
	ifstream ifs(filename);
	while (!ifs.eof()){
		ifs >> cafe_name >> p.x >> p.y;
		add_cafe(cafes, cafe_num, cafe_name, &p);
	}
	ifs.close();
}

// load cafe ratings from a given file
void load_rating(Cafe cafes[], int cafe_num, User users[], int num_users, string filename)
{
	ifstream ifs(filename);
	int num_rating, id;
	float rating;
	for (int i = 0 ; i < cafe_num ; i++)
	{
		ifs >> num_rating;
		for (int j = 0 ; j < num_rating ; j++)
		{
			ifs >> id >> rating;
			User *user = search_user_by_id(users, num_users, id);
			if (user != nullptr)
				add_rating(&cafes[i], user, rating);
			else
				cout << "User ID: " << id << " NOT FOUND!" << endl;
		}
	}
	ifs.close();
}

// Implement the following functions
// add a Cafe object to the Cafe array, cafes.
void add_cafe(Cafe cafes[], int* cafe_num, const char cafe_name[],  const Point* location)
{
	//TODO 2 Add Your Code Here
    Cafe newCafe;
    for (int i = 0; i < MAX_NAME_LENGTH; i++) {
        newCafe.name[i] = cafe_name[i];
        if (cafe_name[i] == '\0') {
            break;
        }
    }
    newCafe.location = *location;
    newCafe.num_of_ratings = 0;
    cafes[*cafe_num] = newCafe;
    *cafe_num += 1;
}

// Add a Rating object to the Cafe c.
// You may call the search_user_by_id() function for finding the address of the corresponding User object.
void add_rating(Cafe *c, User *user, float rating)
{
	//TODO 2 Add Your Code Here
    Rating newRating;
    newRating.user_ptr = user;
    newRating.rating = rating;
    (*c).ratings[(*c).num_of_ratings] = newRating;
    (*c).num_of_ratings += 1;
}

float getAvgRatingOf(const Cafe cafe) {
    float sumOfRating = 0.0;
    for (int i = 0; i < cafe.num_of_ratings; i++) {
        sumOfRating += cafe.ratings[i].rating;
    }
    return sumOfRating / cafe.num_of_ratings;
}

// Similar to lab 8, implement this function to  show the cafe's name, location and its average rating.
void print_cafe(const Cafe* c)
{
	//TODO 2 Add Your Code Here
    Cafe cafeValue = *c;
    cout << "< " << cafeValue.name << ", Coordinates: (" << cafeValue.location.x << "," << cafeValue.location.y << "), AVG_rating: " << getAvgRatingOf(cafeValue) << " >" << endl;
}

// This function show the cafe ratings by each user and the average rating
void print_cafe_rating_by_user(const Cafe* c)
{
	//TODO 2 Add Your Code Here
    Cafe cafeValue = *c;
    cout << cafeValue.name << ", Coordinates: (" << cafeValue.location.x << "," << cafeValue.location.y << ")" << endl;
    for (int i = 0; i < cafeValue.num_of_ratings; i++) {
        Rating rating = cafeValue.ratings[i];
        cout << (*(rating.user_ptr)).name << " Rating: " << rating.rating << endl;
    }
    cout << "AVG_rating: " << getAvgRatingOf(cafeValue) << endl;
}

// Recommend best options of cafe w.r.t rating and distance
void recommend_best_options(const Cafe cafes[], const Point* my_location, int cafe_num)
{
	//TODO 2 Add Your Code Here
    struct CafeWithDist {
        Cafe cafe;
        float dist;
    };
    CafeWithDist cafesSortedByDist[MAX_CAFE_NUM];
    Cafe cafesSortedByRating[MAX_CAFE_NUM];
    for (int i = 0; i < cafe_num; i++) {
        cafesSortedByDist[i] = {cafes[i], euclidean_distance(*my_location, cafes[i].location)};
        cafesSortedByRating[i] = cafes[i];
    }
    for (int i = 0; i < cafe_num; i++) {
        for (int j = 0; j < cafe_num - i; j++) {
            if (cafesSortedByDist[i].dist < cafesSortedByDist[j].dist) {
                CafeWithDist temp = cafesSortedByDist[i];
                cafesSortedByDist[i] = cafesSortedByDist[j];
                cafesSortedByDist[j] = temp;
            }
            if (getAvgRatingOf(cafesSortedByRating[i]) > getAvgRatingOf(cafesSortedByRating[j])) {
                Cafe temp = cafesSortedByRating[i];
                cafesSortedByRating[i] = cafesSortedByRating[j];
                cafesSortedByRating[j] = temp;
            }
        }
    }
    if (strcmp(cafesSortedByDist[0].cafe.name, cafesSortedByRating[0].name) == 0) {
        print_cafe(&cafesSortedByRating[0]);
    } else {
        print_cafe(&cafesSortedByRating[0]);
        print_cafe(&cafesSortedByDist[0].cafe);
    }
}



