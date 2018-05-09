/*
 * Author: Josue Galeas
 * Last Edit: 2018.05.09
 */

#ifndef NODE_HPP
#define NODE_HPP

#include "User.hpp"
#include <vector>

class Node
{
	private:
		double location[2]; // GPS Location
		int level = 2;
		std::vector<std::tuple<int, int, int, Node *>> neighbors; // List of neighbors stored as offsets
		std::vector<User> users; // List of users

	public:
		Node();
		void addNeighbor(Node &); // TODO has to determine offset?
		void addUser(); // TODO How do we assign a new user?
		void moveUser(); // TODO needs to be fast? needs to work in parallel
};

#endif /* NODE_HPP */
