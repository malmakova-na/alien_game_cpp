#include "Cell.h"

Cell::Cell() {
	type = 0;
}
Cell::Cell(int t) {
	type = t;
}
void Cell::change_type(int t) {
	type = t;
}
int Cell::get_type() {
	return type;
}