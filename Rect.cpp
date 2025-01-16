#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Rect.h"

void CMyRect::Scale(double s)
{
	UL.Move(width*(1-s)/2, height*(1-s)/2);
	width *= s;
	height *= s;
} 

bool CMyRect:: isInside(double a, double b)
{
	if (a >= UL.GetX() && a <= UL.GetX() + width && b >= UL.GetY() && b <= UL.GetY() + height)
		return true;
	else
		return false;
}

int CMyRect:: isIntersect(CShape *s)
{
	double x_max, x_min, y_max, y_min;
	x_max = UL.GetX() + width;
	x_min = UL.GetX();
	y_max = UL.GetY() + height;
	y_min = UL.GetY();
	for ( double i= x_min;i<=x_max;i=i+1)
		for (double j = y_min; j <= y_max; j = j + 1)
		{
			if(s->isInside(i, j) == true )
				return 1;
		}

	return 0;
}

