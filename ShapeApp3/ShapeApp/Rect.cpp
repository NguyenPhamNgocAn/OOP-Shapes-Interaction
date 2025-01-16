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
