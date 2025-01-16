class CShape
{
public:
	virtual void Draw(HDC hdc) const = NULL;
	virtual void Move(double dx, double dy) = NULL;
	virtual void Scale(double s) = NULL;
};	