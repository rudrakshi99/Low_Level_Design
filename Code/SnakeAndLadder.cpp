#include <bits/stdc++.h>
using namespace std;

class Player {

	string playerName;
	int id;
public:

	Player(string playerName, int id) {
		this->playerName = playerName;
		this->id = id;
	}

	string getPlayerName() {
		return playerName;
	}

};

class Dice {

	int numberOfDice;

public:
	Dice(int numberOfDice) {
		this->numberOfDice = numberOfDice;
	}

	int rollDice() {
		int ub = 6 * numberOfDice;
		int lb = 1 * numberOfDice;
		return ((int) rand() % (ub - lb + 1) + lb);
	}
};

class Jumper {
public:

	int startPoint;
	int endPoint;

	Jumper(int startPoint, int endPoint) {
		this->startPoint = startPoint;
		this->endPoint = endPoint;
	}
};

class GameBoard {
public:
	Dice dice;
	queue<Player> nextTurn;
	list<Jumper> snakes;
	list<Jumper> ladders;
	unordered_map<string, int> playersCurrentPosition; //name, position
	int boardSize;

	GameBoard( Dice dice, queue<Player> nextTurn, list<Jumper> snakes,
	           list<Jumper> ladders, unordered_map<string, int> playersCurrentPosition, int boardSize) : dice(dice)
	{
		this->dice = dice;
		this->nextTurn = nextTurn;
		this->snakes = snakes;
		this->ladders = ladders;
		this->playersCurrentPosition = playersCurrentPosition;
		this->boardSize = boardSize;
	}

	void startGame() {
		while (nextTurn.size() > 1) {
			Player player = nextTurn.front();
			nextTurn.pop();

			int currentPosition = playersCurrentPosition[player.getPlayerName()];
			int diceValue = dice.rollDice();
			int nextCell = currentPosition + diceValue;

			if (nextCell > boardSize) { // out of bound
				nextTurn.push(player);
			}
			else if (nextCell == boardSize) {
				cout << player.getPlayerName() << " won the game " << "\n";
			}
			else {
				int nextPosition = nextCell;
				bool b = false;

				for (auto i = snakes.begin(); i != snakes.end(); i++) {
					if ((*i).startPoint == nextCell) {
						nextPosition = (*i).endPoint;
					}
				}

				if (nextPosition != nextCell) {

					cout << player.getPlayerName() << " bitten by snake present at: " << nextCell << "\n";
				}

				for (auto i = ladders.begin(); i != ladders.end(); i++) {
					if ((*i).startPoint == nextCell) {
						nextPosition = (*i).endPoint;
						b = true;
					}
				}

				if (nextPosition != nextCell && b) {
					cout << player.getPlayerName() << " got the ladder present at: " << nextCell << "\n";
				}

				if (nextPosition == boardSize) {
					cout << player.getPlayerName() << " won the game" << "\n";
				} else {
					playersCurrentPosition[player.getPlayerName()] = nextPosition;
					cout << player.getPlayerName() << " is at position " << nextPosition << "\n";
					nextTurn.push(player);
				}

			}
		}
	}



};

int main() {

	Dice dice(1);
	Player p1("Alberts", 1);
	Player p2("Pintoss", 2);

	queue<Player> allPlayers;
	allPlayers.push(p1);
	allPlayers.push(p2);
	Jumper snake1(10, 2);
	Jumper snake2(99, 12);
	list<Jumper> snakes;
	snakes.push_back(snake1);
	snakes.push_back(snake2);
	Jumper ladder1(5, 25);
	Jumper ladder2(40, 89);
	list<Jumper> ladders;
	ladders.push_back(ladder1);
	ladders.push_back(ladder2);
	unordered_map<string, int> playersCurrentPosition;
	playersCurrentPosition["Alberts"] = 0;
	playersCurrentPosition["Pintoss"] = 0;
	GameBoard gb(dice, allPlayers, snakes, ladders, playersCurrentPosition, 100);
	gb.startGame();

	return 0;
}