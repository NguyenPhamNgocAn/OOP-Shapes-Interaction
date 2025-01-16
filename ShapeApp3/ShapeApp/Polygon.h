#pragma once

class CPolygon : public CShape
{
	int n_vertice = 8;
	Point *n_point = new Point[n_vertice];
public:
	CPolygon(double arr[])
	{
		int pos = 0;
		for (int i = 0; i < n_vertice; i++)
		{
			n_point[i].SetX(arr[pos++]);
			n_point[i].SetY(arr[pos++]);
		}

	}
	~CPolygon() { delete[] n_point; };
	CPolygon() {};
	void Draw(HDC hdc) const 
	{ 
		POINT vertices[] = { {n_point[0].GetX(),n_point[0].GetY()},{ n_point[1].GetX(),n_point[1].GetY() } \
		, { n_point[2].GetX(),n_point[2].GetY() } };
		Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
		
		//Polygon(hdc, n_point, n_vertice); 
	};
	void Move( double , double);
	void Scale(double);
};

