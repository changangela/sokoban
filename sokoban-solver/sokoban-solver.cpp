/*  ----------------------------------- 
	     SOKOBAN CHARACTER KEY
	-----------------------------------
		#				Wall           
		.				Empty goal     
		+				Player on goal 
		@				Player on floor
		*				Box on goal    
		$				Box on floor   
	-----------------------------------*/

#define pb push_back
#define pf pop_front

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


struct State {
	string map, moveList;
	int depth, moves, pushes;
};

struct Result {
	int nodeCount, exploredCount, repeatCount, fringeCount;
	State node;
};



bool isDest (State &currentState) {
	return ((currentState.map.find('.') == -1) && (currentState.map.find('+') == -1) && (currentState.map.find('$') == -1));
}

queue<State> generateStates(State &currentState) {
	queue<State> validMoves;
	
	stringstream ss(currentState.map);
	string line;

	vector<vector<char> > tempMap;
	State newState;

	bool playerFound = false;
	char playerState, boxMovePosition;
	int playerX, playerY, counter = 0;

	vector<vector<char> > map;

	while (getline(ss, line, '\n')) {
		vector<char> row;
		map.pb(row);

		for (int i = 0; i < line.length(); ++i) {
			if (!playerFound) {
				if (line[i] == '@' | line[i] == '+') {
					playerState  = line[i];
					playerX = i;
					playerY = counter;
					playerFound = true;
				}
			}
			map[counter].pb(line[i]);
		}

		counter++;
	}

	assert(playerFound); // there must be a player

	// now look north, west, east south
	
	int dYs[4] = {-1, 1, 0, 0};
	int dXs[4] = {0, 0, -1, 1};
	char direction[4] = {'w', 's', 'a', 'd'};

	for (int j = 0; j < 4; ++j) {
		int dY = dYs[j];
		int dX = dXs[j];
		char next = map[playerY + dY][playerX + dX];

		if (next == ' ' || next == '.') {
			tempMap = map;
			tempMap[playerY + dY][playerX + dX] = (next == ' ') ? '@' : '+';
			tempMap[playerY][playerX] = (playerState == '@') ? ' ' : '.';

			// create new string
			newState = currentState;
			newState.map = "";
			for (int i = 0; i < tempMap.size(); ++i) {
				vector<char> temp = tempMap[i];
				vector<char>::iterator it;
				for (it = temp.begin(); it != temp.end(); it++) {
					newState.map += (*it);
				}
				newState.map += "\n";
			}

			// update the newState
			newState.moveList += direction[j];
			newState.depth++;
			newState.moves++;
			validMoves.push(newState);
		} else if (next == '$' || next == '*') {
			tempMap = map;
			tempMap[playerY + dY][playerX + dX] = (next == '$') ? '@' : '+';
			tempMap[playerY][playerX] = (playerState == '@') ? ' ' : '.';
			boxMovePosition = tempMap[playerY + dY + dY][playerX + dX + dX];
			
			if (boxMovePosition == '#' || boxMovePosition == '$' || boxMovePosition == '*') {
				continue;
			} else if (boxMovePosition == ' ') {
				tempMap[playerY + dY + dY][playerX + dX + dX] = '$';
			} else if (boxMovePosition == '.') {
				tempMap[playerY + dY + dY][playerX + dX + dX] = '*';
			} else {
				continue;
			}

			newState = currentState;
			newState.map = "";
			for (int i = 0; i < tempMap.size(); ++i) {
				vector<char> temp = tempMap[i];
				vector<char>::iterator it;
				for (it = temp.begin(); it != temp.end(); it++) {
					newState.map += (*it);
				}
				newState.map += "\n";
			}

			// update the newState
			newState.moveList += direction[j];
			newState.depth++;
			newState.moves++;
			validMoves.push(newState);

		}
	}
	
	return validMoves;

}

Result bfs (State &initialState) {

	// queue for open states
	deque<State> open;
	unordered_map<string, bool> closed;

	// result path
	Result result;
	result.repeatCount = result.fringeCount = 0;
	result.nodeCount = result.exploredCount = 1;
	result.node.map = "ERROR";
	
	State currentState;

	// push first item into queue
	open.pb(initialState);
	closed[initialState.map] = true;

	while(!open.empty()) {
		// begin breadth first search traversal
		
		// pop off first node in queue
		currentState = open.front();
		open.pf();

		if (closed.size() % 5000 == 0) {
			cout << closed.size() << endl;
		}

		// check if the goal
		if (isDest(currentState)) {
			result.node = currentState;
			result.exploredCount = closed.size();
			break;
		}
		queue<State> validStates = generateStates(currentState);
		deque<State>::iterator it1;
		vector<State>::iterator it2;

		while(!validStates.empty()) {
			bool visited = false;
			State tempState = validStates.front();
			validStates.pop();

			if (closed.find(tempState.map) != closed.end()) {
				visited = true;
			}
			// for (it2 = closed.begin(); it2 != closed.end(); it2++) {
			// 	if (it2->map == tempState.map) {
			// 		visited = true;
			// 		break;
			// 	}
			// }

			if (!visited) {
				result.nodeCount++;
				open.pb(tempState);
				// push into stack currentState
				closed[tempState.map] = true;
			} else {
				result.repeatCount++;
			}
		}

	}

	result.fringeCount = open.size();
	return result;
}

int main() {
	unsigned t0 = clock();

	State initialState;
	string line;
	
	while (getline(cin, line)) {
		initialState.map += line + "\n";
	}

	initialState.depth = initialState.moves = initialState.pushes = 0;

	Result searchResult = bfs(initialState);
	cout << searchResult.node.moveList << endl;
	cout << searchResult.exploredCount << endl;
	cout << searchResult.node.moves << endl;

	cout << (clock() - t0) * 1.0 / 10e9 << endl;

	return 0;
}