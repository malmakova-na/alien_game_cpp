#include <iostream>
#include <cmath>

struct Vector2 {
	double x, y;
	Vector2();
	Vector2(double a, double b);
	Vector2(const Vector2&  oth);
	Vector2 operator+(const Vector2& oth);
	Vector2& operator=(const Vector2& oth);
	Vector2 operator-(const Vector2& oth);
	double operator*(const Vector2& oth);
	double Len();
};
 