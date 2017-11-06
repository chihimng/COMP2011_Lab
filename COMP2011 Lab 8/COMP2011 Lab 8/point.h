#ifndef LAB8_POINT_H_
#define LAB8_POINT_H_

#include "utils.h"

struct Point{
	float x;
	float y;
};

// Function prototypes
float euclidean_distance(const Point&, const Point&);

#endif /* LAB8_POINT_H_ */
