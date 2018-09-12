// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using namespace std;

int teamAlive(Entity*, size_t);

const int squadSize = 10;
const int swarmSize = 20;

int main()
{
	Marine squad[squadSize];
	Zergling swarm[swarmSize];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (teamAlive(squad, squadSize) && teamAlive(swarm, swarmSize)) // If anyone is left alive to fight . . .
	{
		if (teamAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				if (squad[i].isAlive() && teamAlive(swarm, swarmSize)) // if the current marine is alive and there is a living zergling
				{
					// each marine will attack the first zergling in the swarm
					cout << "A marine fires for " << squad[i].getAtkPwr() << " damage. " << endl;
					int target = 0;
					while (!swarm[target].isAlive())
					{
						target++;
					}
					swarm[target].takeDamage(squad[i].getAtkPwr());
					if (!swarm[target].isAlive()) // if the zergling dies, it is marked as such
					{
						cout << "The zergling target dies" << endl;
					}
				}
			}
			cout << "There are " << teamAlive(swarm, swarmSize) << " zerglingss left." << endl;
		}
		if (teamAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize; i++) // loop through zerglings
			{
				if (swarm[i].isAlive() && teamAlive(squad, squadSize)) // if the current zergling is alive and there is a living marine
				{
					cout << "A zergling attacks for " << swarm[i].getAtkPwr() << " damage." << endl;
					int target = 0;
					while (!squad[target].isAlive())
					{
						target++;
					}
					squad[target].takeDamage(swarm[i].getAtkPwr());
					if (!squad[target].isAlive())
					{
						cout << "The marine succumbs to his wounds." << endl;
					}
				}
			}
			cout << "There are " << teamAlive(squad, squadSize) << " marines left." << endl;
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (teamAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
	//stop before program exits
	cout << "PRESS ENTER TO QUIT" << endl;

	cin.get();

	return 0;
}

// Is there a unit Alive?
int teamAlive(Entity* team, size_t size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (team[i].isAlive())
		{
			result++;
		}
	}
	return result;
}
