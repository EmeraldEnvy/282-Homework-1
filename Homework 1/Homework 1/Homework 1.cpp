#include <iostream>
#include <random>
#include <array>
using namespace std;

int main()
{
	random_device rd{};
	default_random_engine engine{ rd() };
	uniform_int_distribution<int> range{ 1, 3 };
	//Initialize variables
	int goatDoorA, goatDoorB, revealedGoat, swappedDoor, prize;
	char userResponse;
	//Get winning door number
	int winningDoor = range(engine);
	//Get goat door A
	while (true) {
		//Gives goatDoorA an unused door number
		goatDoorA = range(engine);
		if (goatDoorA == winningDoor) {
			goatDoorA = range(engine);
		}
		else {
			break;
		}
	}
	//Get goat door B
	while (true) {
		//Gives goatDoorB remaining door number
		goatDoorB = range(engine);
		if (goatDoorB == winningDoor || goatDoorB == goatDoorA) {
			goatDoorB = range(engine);
		}
		else {
			break;
		}
	}
	//User chooses a door
	cout << "Choose a door 1, 2, or 3 : ";
	int userDoor;
	cin >> userDoor;
	cout << "You have chosen door " << userDoor << endl;

	//Reveal a goat door
	while (true) {
		revealedGoat = range(engine);
		//Checks to make sure the revealed door is a goat and not user's door
		if ((revealedGoat == goatDoorA || revealedGoat == goatDoorB) && revealedGoat != userDoor) {
			break;
		}
		else {
			revealedGoat = range(engine);
		}
	}
	cout << "There is a goat in door " << revealedGoat << ". Would you like to switch? (Y/N) : ";
	cin >> userResponse;
	//Checks user input
	while (userResponse != 'Y' && userResponse != 'N') {
		cout << "Would you like to switch? (Y/N) : ";
		cin >> userResponse;
	}

	//Switches the user's door to other non revealed door
	if (userResponse == 'Y') {
		while (true) {
			swappedDoor = range(engine);
			//Checks if the swapped door is already revealed or is user's current door
			if (swappedDoor == revealedGoat || swappedDoor == userDoor) {
				swappedDoor = range(engine);
			}
			else {
				break;
			}
		}
		userDoor = swappedDoor;
	}
	//Win
	if (userDoor == winningDoor) {
		array< string, 5 > prizePool = { "stick" , "spatula" , "steak dinner" , "saber" , "shoe" };
		uniform_int_distribution<int> range{ 0, 4 };
		prize = range(engine);
		cout << "Congratulations, you won a " << prizePool[prize];
	}
	//Loss
	else {
		cout << "You lost.";
	}

}

