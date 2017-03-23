#include "Player.h"

Player::Player() :
		Moveable() {
	m_inHole = false;	// TODO Auto-generated constructor stub
	m_moves = 0;
}
Player::Player(int row, int column) :
		Moveable(row, column) {
	m_inHole = false;
	m_moves = 0;
	// overloaded constructor

}
void Player::pushBox(Box* box, Offset offset) {
	// function that changes the position of a box
	box->move(offset);
	move(offset);
}

// encapsulation for the inHole member variable
void Player::setInHole(bool inHole) {
	m_inHole = inHole;
}
bool Player::getInHole() {
	return m_inHole;
}
void Player::setMoves(int moves) {
	m_moves = moves;
}
int Player::getMoves() {
	return m_moves;
}
char Player::toString() {
	if (!m_inHole)
		return '@';
	else
		return '+';
}
Player::~Player() {
	// TODO Auto-generated destructor stub
}

