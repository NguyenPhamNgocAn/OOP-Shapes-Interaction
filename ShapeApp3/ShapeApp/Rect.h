class CMyRect: public CShape
{
	Point UL;
	double width, height;
public:
	CMyRect(double x, double y, double w, double h) :UL(x,y), width(w), height(h) {}
	void Draw(HDC hdc) const { Rectangle(hdc, UL.GetX(), UL.GetY(), UL.GetX()+width, UL.GetY()+height); }
	void Move(double dx, double dy) { UL.Move(dx, dy); }
	void Scale(double s);
};