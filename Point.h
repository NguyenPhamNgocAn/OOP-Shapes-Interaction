class Point
{
	double x, y;
public:
	Point(double xx = 0, double yy = 0):x(xx), y(yy) { }
	double GetX() const {return x;}
	double GetY() const {return y;}
	void SetX(double xnew) { x = xnew; };
	void SetY(double ynew) { y = ynew; };
	void Draw(HDC hdc);
	void Move(double dx, double dy) { x += dx; y += dy; }
};

