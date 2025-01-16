#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Ellipse.h"
#include <math.h>
bool CEllipse :: isInside(double x , double y)
{
	return pow(x-T.GetX(),2)/(rx*rx) + pow(y-T.GetY(),2)/(ry*ry) <=1;
}

double CEllipse::distance(double x, double y)
{
	return sqrt(pow(x - T.GetX(), 2) + pow(y - T.GetY(), 2));
}


int CEllipse:: isIntersect(CShape *s)
{
	double x_max, x_min, y_max, y_min;
	x_max = T.GetX() + rx;
	x_min = T.GetX() - rx;
	y_max = T.GetY() + ry;
	y_min = T.GetY() - ry;
	for (double i = x_min; i <= x_max; i = i + 1)
		for (double j = y_min; j <= y_max; j = j + 1)
		{
			if (s->isInside(i, j) == true && this->isInside(i,j))
				return 1;
		}

	return 0;
}