#ifndef VIEWENGINECOLOR_H
#define VIEWENGINECOLOR_H

struct ViewEngineColor
{
	int red;
	int green;
	int blue;
	int alpha;

	ViewEngineColor() {};
	ViewEngineColor(int red, int green, int blue, int alpha) : red(red), green(green), blue(blue), alpha(alpha) { }

};

#endif // !VIEWENGINECOLOR_H
