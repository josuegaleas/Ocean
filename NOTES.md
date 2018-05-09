# Ocean

## NEW "COVERAGE" APPROACH
- Node should have “coverage” list?
- Coverage would be a list of all cells within its influence (based on level of course)
- Since it would be based on level, it’s always a fixed number of cells with relative position to the center
- If a cell is a neighbor, then mark it as a neighbor (perhaps a list of pointers to said neighbors?)
- Should we differentiate if a neighbor is sharing an edge, a corner, or is overlapping?
- With this coverage in mind, is it possible to discover dead spots? Especially when shrinking and growing nodes?
- How would path finding work in this case?
- Need to find the best way to see if two endpoints are connected, otherwise look up and repeat until a path is built
- Where would the constructed path be stored? Centralized somewhere or stored in maps along the way?

## Things To Consider
- Could abstract higher and make cluster of hubs (and nodes?)
- Nodes should be able to grow one level in and out
	- Should hubs be able to expand farther out?
- How do we initially lay out hubs and nodes?
	- Based on known density? How much data do we need?
	- What is the minimum distance? Assume level 2 nodes?
	- Should the algorithm just be fed density info and use ML to generate locations?
	- How do we measure the density of devices first of all?
- Nodes on drones to bridge gaps between hubs?
	- Maybe even between nodes?
	- Maybe for vertical coverage?
- Ford-Fulkerson's algorithm for deciding where to flow users
	- If there is an overlap between nodes, put users onto less filled node?
	- If two nodes are moderately full, somehow split users in half(?) to balance out
- There must definitely be hubs, paths branch out from hubs
- Machine learning to preemptively adjust levels
- Machine learning to handle moving users, especially around freeways
- Need to keep track of GPS location and altitude
- As nodes shrink, pick the least busy neighbors, then check for coverage
	- Might be able to determine this using the level for simplicity
	- Might need to propagate the shrinking/growing, but how far?
	- Can not shrink of grow a previous node, to avoid loops
- Might need to keep track if a node and its neighbors are being resized
	- If a certain area has multiple nodes changing at once, might need hub to handle resize
- Maybe LIDAR for bridges between hubs and dead zones?
- Should users have properties like priority and time allotted?
- There must be an interface to move users around, be in blocks or single users
- Thorup’s algorithm for finding shortest path?

## Behaviors
- The denser an area, the smaller the sphere of influence

## Assumptions
- Areas of dense population or office spaces will have higher density of connected devices
- On average, every user uses the same amount of bandwidth

## Node Structure
- Pointer to cluster? (Offset?)
- Pointer to hub? (Offset?)
- List of neighbors
	- Path to neighbors maybe?
	- Store location as an offset?
- Level
	- Dictates the sphere of influence
	- Can also be used to check for coverage and overlap?
- Capacity of users

## Hub Structure
- Pointer to cluster? (Offset?)
- List of neighboring hubs (probably fixed)
- List of all child nodes

## Cluster Structure
- Name of cluster (potentially over a region)
- List of all hubs

## UCI Courses
- CS 163 for graph algorithms
- CS 260
	- Week 7- 8 for dynamic programming
	- Week 9 for networking flow algorithms
