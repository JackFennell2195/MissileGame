/// <summary>
/// Text Based Missile Game
/// @author: Jack Fennell
/// @login: C00220386
/// @date: 14/09/2017 
/// </summary>
#include <iostream>
#include <cstdlib> 
#include <ctime> 

typedef struct Position
{
	int x;
	int y;
	
	void print()
	{
		std::cout << x << y << std::endl;
	}
		
}Coordinates;

	enum Warhead {EXPLOSIVE, NUCLEAR};

	typedef struct Enemy 
	{
		Coordinates coordinates;
	}
	Target;

struct Missile {
	
	Warhead payload;
	Coordinates coordinates;
	Target target;
	bool armed;

	
	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}
};




int main()
{
	

	//Intro
	Missile missile;
	int select;
	std::cout << "This is missile command. You aim is to aquire a target and shoot a " << std::endl;
	std::cout << "nuclear or explosive warhead to destroy it. If your target is hit you win." << std::endl;
	std::cout << "Nuclear launch codes are 456 and explosive launch codes are 123 remember them" << std::endl;
	std::cout << "to arm the warheads." << std::endl;
	std::cout << std::endl;

	system("pause");

	system("cls");


	//Warhead Select
	std::cout << "Enter what kind of missile you would like to us" << std::endl;
	std::cout << "   0 for explosive and 1 for nuclear" << std::endl;
	std::cin >> select;

	if (select == 0)
	{
		missile.payload = EXPLOSIVE;
		std::cout << "You have selected a Explosive missile " << std::endl;
	}
	else if (select == 1)
	{
		missile.payload = NUCLEAR;
		std::cout << "You have selected a Nuclear missile " << std::endl;
	}
	else
	{
		std::cout << "   Game over!!!" << std::endl;
	}
	std::cout << std::endl;
	system("pause");

	system("cls");


	//Acquire Target

	srand((unsigned)time(0));
	int targetNorth=0;
	targetNorth = (rand() % 15) + 1;
	std::cout << "The Target is " << targetNorth << " km North" << std::endl;

	std::cout << std::endl;

	int targetEast=0;
	targetEast = (rand() % 15) + 1;
	std::cout << "The Target is " << targetEast << " km East" << std::endl;

	std::cout << std::endl;
	system("pause");

	system("cls");


	//Launch Code
	int explosiveArm = 123;
	int nuclearArm = 456;
	int codeEnter = 0;

	std::cout << "Enter the launch code.... if you remember it" << std::endl;
	std::cin >> codeEnter;


	
	if (codeEnter == explosiveArm|| codeEnter == nuclearArm)
	{
		std::cout << "You entered the right code!! " << std::endl;
	}

	std::cout << std::endl;
	system("pause");

	system("cls");


	//Arm Missile
	if (codeEnter == 123 && select == 0)
	{
		std::cout << "Explosive missile armed!!!" << std::endl;
		
	}
	else if(codeEnter == 456 && select == 1)
	{
		std::cout << "Nuclear missile armed!!!" << std::endl;
	}
	else
	{
		std::cout << "   Game over!!!" << std::endl;
	}

	std::cout << std::endl;
	system("pause");

	system("cls");
	

	//Collision
	int missileNorth=0;
	missileNorth = (rand() % 15) + 1;
	int missileEast=0;
	targetEast = (rand() % 15) + 1;

	while(missileNorth != targetNorth && missileEast != targetEast)
	{
		int fireAgain;
		missileNorth = (rand() % 15) + 1;
		missileEast = (rand() % 15) + 1;
		std::cout << "Your missile missed the target!!!!" << std::endl;
		std::cout << "Press 0 to fire again and 1 to stop firing" << std::endl;
		std::cin >> fireAgain;
		if (fireAgain != 0)
		{
			std::cout << "   Game over!!!" << std::endl;
			break;
		}

	}
	
		std::cout << "You hit the target nice job..." << std::endl;
		if (select == 1)
		{
			std::cout << "But the nuclear missile has caused a" << std::endl;
			std::cout << "nuclear fallout!! You Die!!!!" << std::endl;
		}
		else if (select == 0)
		{
			std::cout << "Good thing you picked the explosive missile" << std::endl;
			std::cout << "the nuclear would have probably killed you" << std::endl;
		}
		system("pause");
	
	return 0;
}


