#include "point.h"

float euclidean_distance(const Point& p1, const Point& p2)
{
	float x_diff = p1.x - p2.x;
	float y_diff = p1.y - p2.y;

	return sqrt(x_diff * x_diff + y_diff * y_diff);
}
