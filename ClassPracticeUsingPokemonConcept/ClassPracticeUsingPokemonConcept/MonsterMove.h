#pragma once
#include <string>
#include <iostream>



using namespace std;

class MonsterMove
{
public:
	MonsterMove(string name, string type, string strongAgainst, int attack, int uses, int critChance, int accuracy);

	void GetSkillInfo() { cout << m_baseName << " | Type: " << m_baseType; }
	int GetDamage() { return m_baseDamage;  }
	int GetCritChance() { return m_baseCritChance;  }
	int GetAccuracy() { return m_baseAccuracy;  }
	string GetType() { return m_baseType; }
	string GetStrongAgainstType() { return m_strongAgainstType; }


private:

	string m_baseName;
	string m_baseType;
	string m_strongAgainstType;


	int m_baseDamage;
	int m_baseUses;
	int m_baseCritChance;
	int m_baseAccuracy;

	string m_baseDescription = "empty";
};