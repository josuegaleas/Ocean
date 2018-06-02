/*
 * Author: Josue Galeas
 * Last Edit: 2018.05.10
 */

#ifndef CELL_HPP
#define CELL_HPP

#include <cstdio>
#include <vector>
#include "User.hpp"

union Location
{
	int relative[3];
	double absolute[3];
};

class Cell
{
	private:
		Location loc;
		int radius; // -1 is a cell, [0, 4] is a node
		std::vector<Cell *> cells;
		std::vector<User *> users;

	public:
		Cell(int, Location &);
		void grow();
};

Cell::Cell(int n, Location &l)
{
	if (n >= -1 && n <= 4) // Only values in [-1, 4]
	{
		if (n == -1) // If just a cell
		{
			for (int i = 0; i < 3; i++)
				loc.relative[i] = 0; // TODO: Should not be zero? Should be the distance from the home nodes
		}
		else // If a node
		{
			for (int i = 0; i < 3; i++)
				loc.absolute[i] = l.absolute[i];
		}

		radius = n;
	}
	else
	{
		// Handle this as bizarre behavior
		return;
	}


	// TODO: cells vector will be using for neighbors/homes
	// TODO: users vector will contain users within a cell
}

void Cell::grow()
{
	if (radius < 4)
	{
		printf("ERROR: Node cannot be larger than four.");
		return;
	}
}

#endif /* CELL_HPP */
