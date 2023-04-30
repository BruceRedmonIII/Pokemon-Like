#pragma once
#include <iostream>
#include "MainCharacter.h"


class MonsterTrainer: protected MainCharacter
{

public:

    MonsterTrainer() = default;
    MonsterTrainer(string name, int expDrop, int moneyDrop);
    Monster* GetMonster(MonsterTrainer* trainer, int monsterSlot) { return trainer->m_myMonsters[monsterSlot]; }

    void DisplayBattleStatus(int slot) { m_myMonsters[slot]->GetMonsterBattleInfo(); }
    void SetTrainerMonster(int monsterSlot, Monster* monsterToAdd) 
    {
        m_myMonsters[monsterSlot] = monsterToAdd; 
    }

    

private:
    int m_experienceDrop;
    int m_moneyDrop;
    string m_trainerName = "empty";
    

protected:



};



