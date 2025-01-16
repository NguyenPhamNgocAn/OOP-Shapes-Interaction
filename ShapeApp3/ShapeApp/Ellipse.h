class CEllipse: public CShape
{
	Point T;
	double rx, ry;
public:
	CEllipse() {};
	CEllipse(double x, double y, double a, double b) :T(x,y), rx(a), ry(b) {}
	~CEllipse() {};
	double GetTX() const { return T.GetX(); };
	double GetTY() const { return T.GetY(); };
	void SetTX(double x) { T.SetX(x); };
	void SetTY(double y) { T.SetY(y); };
	double getRX() const { return rx; };
	double getRY() const { return ry; };
	void setRX(double rx) { rx = rx; };
	void setRY(double ry) { ry = ry; };
	void Draw(HDC hdc) const { Ellipse(hdc, GetTX() - getRX(), GetTY() - getRY(), GetTX() + getRX(), GetTY() + getRY()); }
	//void Draw(HDC hdc) const { Ellipse(hdc, T.GetX()-rx, T.GetY()-ry, T.GetX()+rx, T.GetY()+ry); }
	void Move(double dx, double dy) { T.Move(dx, dy); }
	void Scale(double s) { rx *= s; ry *= s; }
};



class Circle : public CEllipse
{
public:
	Circle(double x, double y, double r) :CEllipse(x, y, r, r) {};
	Circle() {};
	~Circle() {};
	//void Draw(HDC hdc)const { Ellipse(hdc, GetTX() - getRX(), GetTY() - getRY(), GetTX() + getRX(), GetTY() + getRY()); }
	
};