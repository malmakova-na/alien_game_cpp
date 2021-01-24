#include "pch.h"
#include "Vector2.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}
Vector2::Vector2(double a, double b) {
	x = a;
	y = b;
}

Vector2::Vector2(const Vector2& oth) {
	x = oth.x;
	y = oth.y;
}
Vector2 Vector2::operator+(const Vector2& a){
	return Vector2(x + a.x, y + a.y);
	}

Vector2& Vector2::operator=(const Vector2& a) {
	if (&a != this) {
		x = a.x;
		y = a.y;
	}
	return *this;
}
Vector2 Vector2::operator-(const Vector2& a) {
		return Vector2(x - a.x, y - a.y);
}
double Vector2::operator*(const Vector2& a) {
	return x * a.x + y * a.y;
}
double Vector2::Len() {
	return sqrt(x*x + y * y);
}
