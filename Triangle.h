class CTriangle : public CShape
{
	Point A, B, C;
public:
	CTriangle(double xA, double yA, double xB, double yB, double xC, double yC) :A(xA, yA), B(xB, yB), C(xC, yC) {}
	void Draw(HDC hdc) const;
	void Move(double dx, double dy) { A.Move(dx, dy); B.Move(dx, dy); C.Move(dx, dy); }
	void Scale(double s);
	int isIntersect(CShape *s) ;
	bool isInside(double, double);
	double Area(Point,Point,Point);
};

