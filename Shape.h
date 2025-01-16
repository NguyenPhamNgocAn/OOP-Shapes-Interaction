class CShape
{
public:
	virtual void Draw(HDC hdc) const = NULL;
	virtual void Move(double dx, double dy) = NULL;
	virtual void Scale(double s) = NULL;
	virtual int isIntersect(CShape *s) { return true; };
	virtual bool isInside(double, double) { return true; };
};	