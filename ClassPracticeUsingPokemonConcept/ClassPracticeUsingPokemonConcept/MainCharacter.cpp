#include <string>
#include "MainCharacter.h"

using namespace std;

MainCharacter::MainCharacter(string name)
    : m_playerName{name}
{
    for (int i = 0; i < 9; ++i)
    {
        m_myMonsters[i] = nullptr;
    }
}

