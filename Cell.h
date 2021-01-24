#pragma once

class Cell {
private:
	int type;
public:
	Cell();
	Cell(int type);
	void change_type(int type);
	int get_type();
};
