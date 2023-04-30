#pragma once
#include <iostream>
#include <string>
#include "MonsterMove.h"
#include "Macros.h"

using namespace std;

class Monster
{
	PRIVATE_VARIABLE_WITH_PUBLIC_GETTER_AND_SETTER(string, monName)
	PRIVATE_VARIABLE_WITH_PUBLIC_GETTER_AND_SETTER(string, monType)
	PRIVATE_VARIABLE_WITH_PUBLIC_GETTER_AND_SETTER(int, monCaptureChance)
public:

	Monster(string name, string type, int health, int attack, int specialAttack, int level, int exp);


	void SetMonsterAttack(Monster* monster, MonsterMove* attack, int skillSlot)  {monster->m_pMonsterSkills[skillSlot] = attack; }

	void ShowMonsterStats() 
	{
		if (m_monCurrentHealth <= 0)
		{
			cout << "DEFEATED  - ";
		}
		cout << "Name: " << m_monName << "| Type: " << m_monType << "| Hp: " << m_monCurrentHealth << "| SpecialAttack: "
			<< m_monSpecAttack << "| Attack: " << m_monAttack << "| Level: " << m_monLevel << "| EXP: " << m_monExp << endl;
	}

	void GetMonsterBattleInfo()
	{
		cout << m_monName << " | Level: " << m_monLevel << endl;
		cout << "Health: " << m_monCurrentHealth << endl;

	}

	void GetMonsterSkills()
	{
		if (m_pMonsterSkills[0] != nullptr)
		{
			cout << "0: ";
			m_pMonsterSkills[0]->GetSkillInfo();
		}
		if (m_pMonsterSkills[1] != nullptr)
		{
			cout << "1: ";
			m_pMonsterSkills[1]->GetSkillInfo();
		}
		cout << endl;
		if (m_pMonsterSkills[2] != nullptr)
		{
			cout << "2: ";
			m_pMonsterSkills[2]->GetSkillInfo();
		}
		if (m_pMonsterSkills[3] != nullptr)
		{
			cout << "3: ";
			m_pMonsterSkills[3]->GetSkillInfo();
		}
	}
	int GetMonsterMaxHealth() { return m_monMaxHealth;  }


	MonsterMove* SelectedAttack(Monster* monster, int slot) { return monster->m_pMonsterSkills[slot];  }


	void MonsterTakeDamage(int damage) { m_monCurrentHealth = m_monCurrentHealth - damage; }
	void Heal() { m_monCurrentHealth = m_monMaxHealth;  }
	int* GetMonsterCurrentHealth() { return &m_monCurrentHealth;  }

private:

	int m_monCurrentHealth;
	int m_monMaxHealth;
	int m_monSpecAttack;
	int m_monAttack;
	int m_monLevel;
	int m_monExp;

	MonsterMove* m_pMonsterSkills[4];

protected:



};