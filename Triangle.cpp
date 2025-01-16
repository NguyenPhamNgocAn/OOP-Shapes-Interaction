#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
#include <cmath>
void CTriangle::Draw(HDC hdc) const
{
	POINT apt[] = { A.GetX(), A.GetY(), B.GetX(), B.GetY(), C.GetX(), C.GetY() };
	Polygon(hdc, apt, 3);
}

void CTriangle:: Scale(double s)
{
	double tx, ty;
	tx = (A.GetX() + B.GetX() + C.GetX()) / 3;
	ty = (A.GetY() + B.GetY() + C.GetY()) / 3;
	A.SetX(s*(A.GetX() - tx) + tx);
	A.SetY(s*(A.GetY() - ty) + ty);
	B.SetX(s*(B.GetX() - tx) + tx);
	B.SetY(s*(B.GetY() - ty) + ty);
	C.SetX(s*(C.GetX() - tx) + tx);
	C.SetY(s*(C.GetY() - ty) + ty);

}


double CTriangle::Area(Point a, Point b, Point c)
{
	return (0.5*abs((c.GetX() - a.GetX())*(b.GetY() - a.GetY()) - (b.GetX() - a.GetX())*(c.GetY() - a.GetY())));
}

bool CTriangle::isInside(double x , double y )
{
	Point check(x, y);
	double sum = Area(A, B, check) + Area(B, C, check) + Area(C, A, check) ;
	return abs(sum - Area(A,B,C)) < 0.01;
}

int CTriangle::isIntersect(CShape *s)
{
	double x_max, x_min, y_max, y_min;
	x_max = A.GetX();
	x_min = A.GetX();
	y_max = A.GetY();
	y_min = A.GetY();
	if (x_max < B.GetX())
		x_max = B.GetX();
	if (x_max < C.GetX())
		x_max = C.GetX();
	if (x_min > B.GetX())
		x_min = B.GetX();
	if (x_min > C.GetX())
		x_min = C.GetX();
	
	if (y_max < B.GetY())
		y_max = B.GetY();
	if (y_max < C.GetY())
		y_max = C.GetY();
	if (y_min > B.GetY())
		y_min = B.GetY();
	if (y_min > C.GetY())
		y_min = C.GetY();

	for (double i = x_min; i <= x_max; i = i + 1)
		for (double j = y_min; j <= y_max; j = j + 1)
		{
			if (s->isInside(i, j) == true && this->isInside(i, j) == true)
				return 1;
		}

	return 0;
}