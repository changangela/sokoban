#include "Board.h"
#include <algorithm>
Board::Board() {
	// initializes all the stage designs
	addStage();
	// sets the board to the first level board
	m_board = parseStage(0);
}
Board::Board(int level) {
	// initializes all the stage designs
	addStage();
	// sets the board to the 'stage' level board
	m_board = parseStage(level);
	// level is now set
	m_level = level;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}
bool Board::isWin() {
	// if all the boxes are in holes, win
	if (Box::numBox == Box::numInHole)
		return true;
	else
		return false;
}
void Board::addStage() {
	// the first level of the game
	m_stage.push_back("###  \n#.###\n#*$ #\n# @ #\n#####");

	// level 2
	m_stage.push_back(
			"#######\n#     #\n#     #\n#. #  #\n#. $$ #\n#.$$  #\n#.#  @#\n#######");
	// level 3
	m_stage.push_back(
			"   ####\n#### @#\n#  *$ #\n#     #\n## .###\n #$ #  \n # .#  \n ####  \n");
	// level 4
	m_stage.push_back(
			" ######\n##  . #\n# * # #\n# .$  #\n#  #$##\n## @ # \n ##### ");
	// level 5
	m_stage.push_back(
			" #####   \n #   ####\n #      #\n### **# #\n#  #* *@#\n#   * ###\n#  ##  # \n##     # \n #.$#  # \n #  #### \n ####    \n");

}
int Board::getNumLevels() {
	// returns the number of levels in the game
	return m_board.size();
}
vector<vector<Unit*> > Board::parseStage(int level) {

	// parse through stage design string to store each char into a 2D vector

	// the base class 'Unit' is used to store polymorphic objects
	vector<vector<Unit*> > tempBoard;
	vector<Unit*> tempRow;

	int row = 0;
	int column = 0;

	for (unsigned int i = 0; i < m_stage[level].size(); i++) {
		if (m_stage[level][i] == '\n') {
			// if the character is a break sign, a new row is made
			tempBoard.push_back(tempRow);
			vector<Unit*>().swap(tempRow); // vector is swapped with empty container
			row++;
			column = 0;
		} else {
			// else the appropriate object is constructed into current row
			switch (m_stage[level][i]) {
			case '#':
				tempRow.push_back(new Wall(row, column));
				break;
			case '.':
				tempRow.push_back(new Hole(row, column));
				break;
			case '$':
				tempRow.push_back(new Space(row, column));
				m_boxes.push_back(new Box(row, column));
				break;
			case '@':
				tempRow.push_back(new Space(row, column));
				m_player = new Player(row, column);
				break;
			case '*':
				tempRow.push_back(new Hole(row, column));
				m_boxes.push_back(new Box(row, column, true));
				break;
			case '+':
				tempRow.push_back(new Hole(row, column));
				m_player = new Player(row, column);
				m_player->setInHole(true);
				break;
			default:
				tempRow.push_back(new Space(row, column));
			}
			column++;
		}
	}

	tempBoard.push_back(tempRow); // adds the final row into the board

	return tempBoard;

}

void Board::printBoard() {
	// prints out the elements of the current board
	for (unsigned int x = 0; x < m_board.size(); x++) {
		for (unsigned int y = 0; y < m_board[x].size(); y++) {
			bool overridden = false; // the background is first printed but overrode if a foreground object is present
			for (std::vector<Box*>::iterator box = m_boxes.begin();
					box != m_boxes.end(); ++box) {
				// hash table to find a matching Box object with given row and column
				// for pointer access, iterator was dereferenced
				if ((unsigned int) (*box)->getRow() == x
						&& (unsigned int) (*box)->getColumn() == y) {
					cout << (*box)->toString();
					overridden = true;
				}
			}
			if ((unsigned int) m_player->getRow() == x
					&& (unsigned int) m_player->getColumn() == y) {
				// prints the player at given row and column
				cout << m_player->toString();
				overridden = true;
			}
			if (!overridden) {
				// polymorphism - elements of vectors use their own overridden toString() function
				cout << m_board[x][y]->toString(); // prints out all elements of vector
			}
		}
		cout << endl;
	}
}

void Board::move(Offset offset) {
	// moves the player in the specified direction
	int newRow = offset.getX() + m_player->getRow(); // vertical offset
	int newColumn = offset.getY() + m_player->getColumn(); // horizontal offset

	bool isPushing = false;
	bool isBlocked = false;
	Box* pushedBox;

	for (std::vector<Box*>::iterator box = m_boxes.begin();
			box != m_boxes.end(); ++box) {
		// hash table to find a matching Box object with given row and column
		// for pointer access, iterator was dereferenced

		// an iteration search is used here to search for a specific box in the box array
		if ((*box)->getRow() == newRow && (*box)->getColumn() == newColumn) {

			isPushing = true; // the player is now pushing a box
			pushedBox = (*box); // a temporary reference variable is set to the pushed box

			// the box now has to move to position one offset away
			newRow = newRow + offset.getX();
			newColumn = newColumn + offset.getY();

			// check if the box has a box in front of it to prevent it from being pushed
			for (std::vector<Box*>::iterator block = m_boxes.begin();
					block != m_boxes.end(); ++block) {
				if ((*block)->getRow() == newRow
						&& (*block)->getColumn() == newColumn) {
					isBlocked = true;
				}
			}
		}
	}

	if (!dynamic_cast<Wall*>(m_board[newRow][newColumn]) && !isBlocked) {
		// dynamic cast is used in order to check the sub type of the polymorphic objects
		// if the new position is not a wall

		// increment the players moves by 1
		m_player->setMoves(m_player->getMoves() + 1);
		if (dynamic_cast<Hole*>(m_board[newRow][newColumn])) {
			if (!isPushing) {
				// if the position is a hole, player moves onto hole
				m_player->move(offset);
				m_player->setInHole(true);
			} else {
				// the player is pushing a box into a hole
				Box::setNumInHole(Box::getNumInHole() + 1);
				if (pushedBox->isInHole()) {
					// if the box was in hole, player now goes into a hole
					Box::setNumInHole(Box::getNumInHole() - 1);
					m_player->setInHole(true);
				} else {
					m_player->setInHole(false);
				}
				m_player->pushBox(pushedBox, offset);
				pushedBox->setInHole(true);
			}
		} else {
			// if the position is a space, player moves into space
			if (!isPushing) {
				m_player->move(offset);
				m_player->setInHole(false);
			} else {
				// the player is pushing a box into a space
				if (pushedBox->isInHole()) {
					// if the box was in hole, player now goes into a hole
					Box::setNumInHole(Box::getNumInHole() - 1);
					m_player->setInHole(true);
				} else {
					m_player->setInHole(false);
				}
				m_player->pushBox(pushedBox, offset);
				pushedBox->setInHole(false);
			}
		}

	} else {
		// if the new position is a wall

	}

}

// encapsulation for the member variables
void Board::setLevel(int level) {
	m_level = level;
}
int Board::getLevel() {
	return m_level;
}
int Board::getMoves() {
	return m_player->getMoves();
}

