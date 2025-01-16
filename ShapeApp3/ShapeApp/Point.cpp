#include "stdafx.h"
#include "Point.h"

void Point::Draw(HDC hdc) 
{
	Ellipse(hdc, x-2, y-2, x+2, y+2);
} 
