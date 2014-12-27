#include "ElementTypes.h"
class Element
{
public:
	Element()
	{
		type = AIR;
	}
	Element(types t)
	{
		type = t;
	}

	types getType()
	{
		return type;
	}
	void setType(types t)
	{
		type = t;
	}
private:
	types type;
};