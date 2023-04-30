#include <iostream>
#include "MonsterTrainer.h"

using namespace std;


MonsterTrainer::MonsterTrainer(string name, int expDrop, int moneyDrop)
    : m_trainerName{name}
    , m_experienceDrop{expDrop}
    , m_moneyDrop{moneyDrop}
{
    for (int i = 0; i < 8; ++i)
    {
        m_myMonsters[i] = nullptr;
    }

}
