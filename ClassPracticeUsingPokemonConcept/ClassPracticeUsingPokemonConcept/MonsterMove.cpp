#include "MonsterMove.h"




MonsterMove::MonsterMove(string name, string type, string strongAgainst, int damage, int uses, int critChance, int accuracy)
    : m_baseName{name}
    , m_baseType{type}
    , m_strongAgainstType{strongAgainst}
    , m_baseDamage{damage}
    , m_baseUses{uses}
    , m_baseCritChance{critChance}
    , m_baseAccuracy{accuracy}
{



}
