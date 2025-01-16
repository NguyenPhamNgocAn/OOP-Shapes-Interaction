#include "stdafx.h"
#include "Point.h"
#include "Shape.h"
#include "Polygon.h"
#include <cmath>
void CPolygon::Draw(HDC hdc) const
{
	POINT apt[] = { A.GetX(), A.GetY(), B.GetX(), B.GetY(), C.GetX(), C.GetY(),D.GetX(), D.GetY(), E.GetX(), E.GetY(), F.GetX(), F.GetY() };
	Polygon(hdc, apt, 6);
}

void CPolygon::Scale(double s)
{
	A.Move(-s / 6,-s/6);
	B.Move(0, -s / 6);
	C.Move(s / 6, s / 6);
	D.Move(s / 6, s / 6);
	E.Move(0, s / 6);
	F.Move(-s / 6, s / 6);
}

bool CPolygon:: isInside(double x, double y)
{
	Point check(x, y);
	double sum = Area_triangle(A, B, check) + Area_triangle(B, C, check) \
		+ Area_triangle(C, D, check) + Area_triangle(D, E, check) + Area_triangle(E, F, check) + Area_triangle(F, A, check);
	return abs(sum - Area()) < 0.01;
}
int CPolygon ::isIntersect(CShape *s)
{
	if (s->isIntersect(this))
		return 1;
	return 0;
}

double CPolygon::Area_triangle(Point a, Point b, Point c)
{
	return (0.5*abs((c.GetX() - a.GetX())*(b.GetY() - a.GetY()) - (b.GetX() - a.GetX())*(c.GetY() - a.GetY())));
}

double CPolygon::Area()
{
	return Area_triangle(A, B, C) + Area_triangle(C, D, E)+ Area_triangle(E, F, A) + Area_triangle(A, E, C);
}

