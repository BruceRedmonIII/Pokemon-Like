#include "Monster.h"
#include "MonsterMove.h"
#include "MainCharacter.h"
#include "MonsterTrainer.h"

using namespace std;


Monster::Monster(string name, string type, int health, int attack, int specialAttack, int level, int exp)
    : m_monName{ name }
    , m_monType{ type }
    , m_monMaxHealth{ health }
    , m_monCurrentHealth{ health }
    , m_monAttack{ attack }
    , m_monSpecAttack{ specialAttack }
    , m_monLevel{ level }
    , m_monExp{ exp }
{
    for (int i = 0; i < 4; ++i)
    {
        Monster::m_pMonsterSkills[i] = nullptr;
    }
    m_monCaptureChance = 50;
};