
class CPolygon : public CShape
{
	Point A, B, C,D,E,F;
public:
	CPolygon(double xA, double yA, double xB, double yB, double xC, double yC, double xD, double yD, double xE, double yE, double xF, double yF) :A(xA, yA), B(xB, yB), C(xC, yC), D(xD, yD), E(xE, yE), F(xF, yF) {}
	void Draw(HDC hdc) const;
	void Move(double dx, double dy) {
		A.Move(dx, dy); B.Move(dx, dy); C.Move(dx, dy); D.Move(dx, dy); E.Move(dx, dy); F.Move(dx, dy);
	}
	void Scale(double s);
	bool isInside(double, double);
	int isIntersect(CShape *s);
	double Area_triangle(Point, Point, Point);
	double Area();
	
};
