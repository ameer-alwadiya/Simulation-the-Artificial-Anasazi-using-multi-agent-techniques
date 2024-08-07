#include "Household.h"
#include "repast_hpc/AgentId.h"
#include "repast_hpc/SharedContext.h"
#include "repast_hpc/SharedDiscreteSpace.h"
#include <stdio.h>
#include "repast_hpc/Random.h"

Household::Household(repast::AgentId id, int a, int deAge, int mStorage)
{
	householdId = id;
	age = a;
	deathAge = deAge;
	maizeStorage = mStorage;
	assignedField = NULL;
}

Household::~Household()
{

}

int Household::splitMaizeStored(int percentage)
{
	int maizeEndowment;
	maizeEndowment = maizeStorage * percentage;
	maizeStorage = maizeStorage - maizeEndowment;
	return maizeEndowment;
}

bool Household::checkMaize(int needs)
{
	if((assignedField->getExpectedYield() + maizeStorage) > needs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Household::death()
{
	if(age>=deathAge)
	{
			return true;
	}
	else
	{
		return false;
	}
}

bool Household::fission(int minFissionAge, int maxFissionAge, double gen, double fProb)
{
	if((age>=minFissionAge && age<=maxFissionAge) && (gen <= fProb))
	{
			return true;
	}
	else
	{
		return false;
	}
}

void Household::nextYear(int needs)
{
	age++;
	maizeStorage = assignedField->getExpectedYield() + maizeStorage - needs;
}

void Household::chooseField(Location* Field)
{
	//set the old location as emtpy
	if (assignedField!=NULL) assignedField->setState(0);

	//set the new location as a field
	Field->setState(2);

	assignedField = Field;
}


// new function (1): probability
bool Household::askHelp(double gen, double helpProb)
{
	if(gen <= helpProb)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// new function (2):
// check neighbor can help?
bool Household::checkNeighborCanHelp(int needs, int mStorageForTarget)
{
    // maizeStorage for the neighbor (need to validate)
	if((maizeStorage) >= (needs * 2) - mStorageForTarget)
	{
	    // neighbor satisfy the conditions.
		return true;
	}
	else
	{
		return false;
	}
}

// new function (3): probability
bool Household::neighborAcceptToHelp(double gen, double acceptToHelpProb)
{
	if(gen <= acceptToHelpProb)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// new function (4): change maizeStorage
void Household::setMaizeStorage(int newMaizeStorage){
	maizeStorage = newMaizeStorage;
}

// new function (5): probability that some young agents will leave
bool Household::probabilityYoungToLeave(int minFissionAge, int maxFissionAge, double gen, double fProb)
{
	if((age>=minFissionAge && age<=maxFissionAge) && (gen <= fProb))
	{
		return true;
	}
	else
	{
		return false;
	}
}

