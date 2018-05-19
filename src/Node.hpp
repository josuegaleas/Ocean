/*
 * Author: Josue Galeas
 * Last Edit: 2018.05.10
 */

#ifndef NODE_HPP
#define NODE_HPP

#include "User.hpp"
#include "Cell.hpp"
#include <vector>

class Node
{
	private:
		double loc[3]; // Longitude, latitude, and altitude of node
		int rad; // Radius of the node

		// TODO
		std::vector<User> users; // List of users

	public:
		Node(double, double, double);
		void grow();
		void shrink();

		// TODO
		void addCell(Node &); // TODO has to determine offset?
		void addUser(); // TODO How do we assign a new user?
		void moveUser(); // TODO needs to be fast? needs to work in parallel
};

Node::Node(double lon, double lat, double alt)
{
	loc[0] = lon;
	loc[1] = lat;
	loc[2] = alt;
	rad = 0;
}

void Node::grow()
{
	if (rad > 4)
	{
		printf("ERROR: Node can not be larger!");
		return;
	}

	rad++;
}

#endif /* NODE_HPP */
