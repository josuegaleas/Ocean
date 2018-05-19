/*
 * Author: Josue Galeas
 * Last Edit: 2018.05.10
 */

#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
	private:
		int loc[3];
		bool node;

	public:
		Cell(int, int, int);
};

Cell::Cell(int x, int y, int z)
{
	loc[0] = x;
	loc[1] = y;
	loc[2] = z;

	node = false; // FIXME: Do we really need this?
}

#endif /* CELL_HPP */
