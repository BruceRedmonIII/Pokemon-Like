#pragma once

#include <iostream>
#include "Monster.h"

using namespace std;


class MainCharacter
{
public:
	MainCharacter(string name);
	MainCharacter() = default;

	void SetNewMonster(Monster* monsterToAdd, int monsterSlot) 
	{ 
		m_myMonsters[monsterSlot] = monsterToAdd;
	}
	void PrintPlayerSheet() { cout << "Name: " << m_playerName << " | Battles Won: " << m_battlesWon << " | Battles Lost: " << m_battlesLost << " Capture Cards: " << m_captureCards << endl; }
	Monster* GetMonster(MainCharacter* player, int monsterSlot) { return player->m_myMonsters[monsterSlot]; }

	void GetPlayerMonsters(MainCharacter* player)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (player->m_myMonsters[i] != nullptr) {
				cout << i << ": ";
				player->m_myMonsters[i]->ShowMonsterStats();
			}
		}
	}
	string GetPlayerName(MainCharacter* player) { return player->m_playerName; }
	void SetBattleWon() { ++m_battlesWon; }
	void SetBattleLost() { ++m_battlesLost; }
	void SetCaptureCards(int amount) { m_captureCards = m_captureCards + amount; }
	void LoseACaptureCard() { --m_captureCards; }
	int GetCaptureCards() { return m_captureCards; }

	bool MonsterAlreadyCapturedCheck(Monster* monster) 
	{
		for (int i = 0; i < 8; ++i)
		{
			if (m_myMonsters[i] == monster)
			{
				return true;
			}
			
		}
		return false;
	}

private:
	int m_captureCards = 0;
	int m_battlesWon = 0;
	int m_battlesLost = 0;
	string m_playerName;

protected:

	Monster* m_myMonsters[9];



};