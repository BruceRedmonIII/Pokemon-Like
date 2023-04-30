#include <iostream>
#include "Monster.h"
#include "MainCharacter.h"
#include "MonsterMove.h"
#include "MonsterTrainer.h"
#include <string>
#include <time.h>
#include <tinyxml>
#include "Macros.h"

using namespace std;


//Functions
int ShowMenu(MainCharacter* player);
void SelectMonsters(MainCharacter* player, int& choice, MonsterTrainer* trainer, int& enemyChoice);
void SelectMonsterWildBattle(MainCharacter* player, int& choice);
void Battle(MainCharacter* player, int slotOne,  MonsterTrainer* trainer, int slotTwo);
bool StrongHitCheck(string attackType, string defendType);
bool CriticalCheck(int critHit);
bool AccuracyCheck(int accuracy);
bool CheckPlayerDefeat(MainCharacter* player);
bool CheckTrainerDefeat(MonsterTrainer* player);
void HealPlayerMonsters(MainCharacter* player);
void HealTrainerMonsters(MonsterTrainer* trainer);
void WildBattle(MainCharacter* player, int slotOne, Monster* monster);
int CaptureCheck(Monster* monster);


int main()
//------------------------------------------------------------------------------------------------------
{//Set the monsters/attacks       name   type   hp  att spec l  xp
    Monster* pDrago = new Monster("Sun", "Fire", 100, 10, 15, 1, 0);
    Monster* pMushy = new Monster("Mushy", "Grass", 100, 10, 15, 1, 0);
    Monster* pStraw = new Monster("Straw", "Water", 100, 10, 15, 1, 0);
    Monster* pMisting = new Monster("Misting", "Poison", 100, 10, 15, 1, 0);
    Monster* pTitan = new Monster("Titan", "Stone", 100, 10, 15, 1, 0);
    Monster* pMundane = new Monster("Mundane", "Normal", 100, 10, 15, 1, 0);
    Monster* pShade = new Monster("Shade", "Dark", 100, 10, 15, 1, 0);
    Monster* pSock = new Monster("Sock", "Electric", 100, 10, 15, 1, 0);
    Monster* pBladd = new Monster("Bladd", "Steel", 100, 10, 15, 1, 0);

    MonsterMove* pFireBall = new MonsterMove("FireBall", "Fire", "Grass", 20, 20, 10, 100);
    MonsterMove* pLeafBall = new MonsterMove("LeafBall", "Grass", "Water", 20, 20, 10, 100);
    MonsterMove* pWaterBall = new MonsterMove("WaterBall", "Water", "Fire", 20, 20, 10, 100);
    MonsterMove* pPoisonBall = new MonsterMove("PoisonBall", "Poison", "Normal", 20, 20, 10, 100);
    MonsterMove* pStoneBall = new MonsterMove("StoneBall", "Stone", "Electric", 20, 20, 10, 100);
    MonsterMove* pNormalBall = new MonsterMove("NormalBall", "Normal", "Nothing", 20, 20, 10, 100);
    MonsterMove* pDarkBall = new MonsterMove("DarkBall", "Dark", "Poison", 20, 20, 10, 100);
    MonsterMove* pElectricBall = new MonsterMove("ElectricBall", "Electric", "Steel", 20, 20, 10, 100);
    MonsterMove* pSteelBall = new MonsterMove("SteelBall", "Steel", "Stone", 20, 20, 10, 100);

    pDrago->SetMonsterAttack(pDrago, pFireBall, 0);
    pMushy->SetMonsterAttack(pMushy, pLeafBall, 0);
    pStraw->SetMonsterAttack(pStraw, pWaterBall, 0);
    pMisting->SetMonsterAttack(pMisting, pPoisonBall, 0);
    pTitan->SetMonsterAttack(pTitan, pStoneBall, 0);
    pMundane->SetMonsterAttack(pMundane, pNormalBall, 0);
    pShade->SetMonsterAttack(pShade, pDarkBall, 0);
    pSock->SetMonsterAttack(pSock, pElectricBall, 0);
    pBladd->SetMonsterAttack(pBladd, pSteelBall, 0);
    //------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------
    //set trainers
    MonsterTrainer* pEasyDave = new MonsterTrainer("Dave", 1000, 100);
    MonsterTrainer* pMediumMissy = new MonsterTrainer("Missy", 2000, 500);
    MonsterTrainer* pHardJake = new MonsterTrainer("Jake", 3000, 1000);
    //--------------------------------------------------------------------
    srand(time(NULL));


    //--------------------------------------------------------------------------
    //Randomize trainer monsters
    for (int i = 0; i < 2; ++i)
    {
        int randoMonster = (rand() % 9);
        if (randoMonster == 1)
        {
            Monster* pDragoOne = new Monster(*pDrago);
            pEasyDave->SetTrainerMonster(i, pDragoOne);
        }
        else if (randoMonster == 2)
        {
            Monster* pMushyOne = new Monster(*pMushy);
            pEasyDave->SetTrainerMonster(i, pMushyOne);
        }
        else if (randoMonster == 3)
        {
            Monster* pStrawOne = new Monster(*pStraw);
            pEasyDave->SetTrainerMonster(i, pStrawOne);
        }
        else if (randoMonster == 4)
        {
            Monster* pMistingOne = new Monster(*pMisting);
            pEasyDave->SetTrainerMonster(i, pMistingOne);
        }
        else if (randoMonster == 5)
        {
            Monster* pTitanOne = new Monster(*pTitan);
            pEasyDave->SetTrainerMonster(i, pTitanOne);
        }
        else if (randoMonster == 6)
        {
            Monster* pMundaneOne = new Monster(*pMundane);
            pEasyDave->SetTrainerMonster(i, pMundaneOne);
        }
        else if (randoMonster == 7)
        {
            Monster* pShadeOne = new Monster(*pShade);
            pEasyDave->SetTrainerMonster(i, pShadeOne);
        }
        else if (randoMonster == 8)
        {
            Monster* pSockOne = new Monster(*pSock);
            pEasyDave->SetTrainerMonster(i, pSockOne);
        }
        else if (randoMonster == 9)
        {
            Monster* pBladdOne = new Monster(*pBladd);
            pEasyDave->SetTrainerMonster(i, pBladdOne);
        }

    }

    for (int i = 0; i < 5; ++i)
    {
        int randoMonster = (rand() % 9);
        if (randoMonster == 1)
        {
            Monster* pDragoTwo = new Monster(*pDrago);
            pMediumMissy->SetTrainerMonster(i, pDragoTwo);
        }
        else if (randoMonster == 2)
        {
            Monster* pMushyTwo = new Monster(*pMushy);
            pMediumMissy->SetTrainerMonster(i, pMushyTwo);
        }
        else if (randoMonster == 3)
        {
            Monster* pStrawTwo = new Monster(*pStraw);
            pMediumMissy->SetTrainerMonster(i, pStrawTwo);
        }
        else if (randoMonster == 4)
        {
            Monster* pMistingTwo = new Monster(*pMisting);
            pMediumMissy->SetTrainerMonster(i, pMistingTwo);
        }
        else if (randoMonster == 5)
        {
            Monster* pTitanTwo = new Monster(*pTitan);
            pMediumMissy->SetTrainerMonster(i, pTitanTwo);
        }
        else if (randoMonster == 6)
        {
            Monster* pMundaneTwo = new Monster(*pMundane);
            pMediumMissy->SetTrainerMonster(i, pMundaneTwo);
        }
        else if (randoMonster == 7)
        {
            Monster* pShadeTwo = new Monster(*pShade);
            pMediumMissy->SetTrainerMonster(i, pShadeTwo);
        }
        else if (randoMonster == 8)
        {
            Monster* pSockTwo = new Monster(*pSock);
            pMediumMissy->SetTrainerMonster(i, pSockTwo);
        }
        else if (randoMonster == 9)
        {
            Monster* pBladdTwo = new Monster(*pBladd);
            pMediumMissy->SetTrainerMonster(i, pBladdTwo);
        }

    }

    for (int i = 0; i < 9; ++i)
    {
        int randoMonster = (rand() % 9);
        if (randoMonster == 1)
        {
            Monster* pDragoThree = new Monster(*pDrago);
            pHardJake->SetTrainerMonster(i, pDragoThree);
        }
        else if (randoMonster == 2)
        {
            Monster* pMushyThree = new Monster(*pMushy);
            pHardJake->SetTrainerMonster(i, pMushyThree);
        }
        else if (randoMonster == 3)
        {
            Monster* pStrawThree = new Monster(*pStraw);
            pHardJake->SetTrainerMonster(i, pStrawThree);
        }
        else if (randoMonster == 4)
        {
            Monster* pMistingThree = new Monster(*pMisting);
            pHardJake->SetTrainerMonster(i, pMistingThree);
        }
        else if (randoMonster == 5)
        {
            Monster* pTitanThree = new Monster(*pTitan);
            pHardJake->SetTrainerMonster(i, pTitanThree);
        }
        else if (randoMonster == 6)
        {
            Monster* pMundaneThree = new Monster(*pMundane);
            pHardJake->SetTrainerMonster(i, pMundaneThree);
        }
        else if (randoMonster == 7)
        {
            Monster* pShadeThree = new Monster(*pShade);
            pHardJake->SetTrainerMonster(i, pShadeThree);
        }
        else if (randoMonster == 8)
        {
            Monster* pSockThree = new Monster(*pSock);
            pHardJake->SetTrainerMonster(i, pSockThree);
        }
        else if (randoMonster == 9)
        {
            Monster* pBladdThree = new Monster(*pBladd);
            pHardJake->SetTrainerMonster(i, pBladdThree);
        }

    }
//-------------------------------------------------------------------------------------
//Choose player name

    bool gameStart = false;
    while (gameStart == false)
    {
        cout << "Choose your Players name!" << endl;
        string pPlayerName;
        cin >> pPlayerName;
        system("cls");
        //create character with chosen name
        MainCharacter* pMainPlayer = new MainCharacter(string(pPlayerName));

// -------------------------------------------------------------------------------------
        //Choose starter monster
        int choice = 0;
        while (choice == 0)
        {
            cout << "Choose your Monster!" << endl;
            cout << "1: ";
            pDrago->ShowMonsterStats();
            cout << "2: ";
            pMushy->ShowMonsterStats();
            cout << "3: ";
            pStraw->ShowMonsterStats();
            cin >> choice;
            if (choice == 1)
            {
                pMainPlayer->SetNewMonster(pDrago, 0);
            }
            else if (choice == 2)
            {
                pMainPlayer->SetNewMonster(pMushy, 0);
            }
            else if (choice == 3)
            {
                pMainPlayer->SetNewMonster(pStraw, 0);
            }
            else
            {
                cout << "Must be a number 1-3!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                system("pause");
                system("cls");
                choice = 0;
            }
        }
//----------------------------------------------------------------------------
        gameStart = true;
        system("cls");
#ifdef _DEBUG
        pMainPlayer->SetCaptureCards(99);
#endif
        bool gameOver = false;
        int playerChoice = 0;
        int enemyChoice = 0;
        bool wildMonsterFound = false;
        Monster* pWildMonster = nullptr;
//-----------------------------------------------------------------------------
        //Gameloop begins!
        while (gameOver == false)
        {
            int battleChoice;
            system("cls");
            //menu display
            battleChoice = ShowMenu(pMainPlayer);
            //If choice 1 then find a random monster that you havent caught
            if (battleChoice == 1)
            {
                wildMonsterFound = false;
                while (wildMonsterFound == false)
                {
                    enemyChoice = 0;
                    enemyChoice = ((rand() % 9) + 1);
                    if (enemyChoice == 1)
                    {
                        pWildMonster = pDrago;
                    }
                    else if (enemyChoice == 2)
                    {
                        pWildMonster = pMushy;
                    }
                    else if (enemyChoice == 3)
                    {
                        pWildMonster = pStraw;
                    }
                    else if (enemyChoice == 4)
                    {
                        pWildMonster = pSock;
                    }
                    else if (enemyChoice == 5)
                    {
                        pWildMonster = pMundane;
                    }
                    else if (enemyChoice == 6)
                    {
                        pWildMonster = pBladd;
                    }
                    else if (enemyChoice == 7)
                    {
                        pWildMonster = pMisting;
                    }
                    else if (enemyChoice == 8)
                    {
                        pWildMonster = pShade;
                    }
                    else if (enemyChoice == 9)
                    {
                        pWildMonster = pTitan;

                    }
                    if (pMainPlayer->MonsterAlreadyCapturedCheck(pWildMonster) == true)
                    {
                        wildMonsterFound = false;
                        enemyChoice = 0;

                    }
                    else
                    {
                        wildMonsterFound = true;
                        enemyChoice = 0;
                    }
                }
                //---------------------------------------------------------------------------------
                //then start battle loop that checks for defeat or monster capture after each instance of wild battle.
                while (CheckPlayerDefeat(pMainPlayer) == false && *pWildMonster->GetMonsterCurrentHealth() > 0 && pMainPlayer->MonsterAlreadyCapturedCheck(pWildMonster) == false)
                {
                    SelectMonsterWildBattle(pMainPlayer, playerChoice);
                    WildBattle(pMainPlayer, playerChoice, pWildMonster);
                }
                if (CheckPlayerDefeat(pMainPlayer) == true)
                {
                    cout << "You have been defeated by " << pWildMonster->GetmonName();
                    pWildMonster->Heal();
                    HealPlayerMonsters(pMainPlayer);
                    pMainPlayer->SetBattleLost();
                }
                else if (*pWildMonster->GetMonsterCurrentHealth() <= 0)
                {
                    cout << "You have defeated " << pWildMonster->GetmonName();
                    pWildMonster->Heal();
                    HealPlayerMonsters(pMainPlayer);
                    cout << endl;
                    cout << "You have earned 1 capture card!" << endl;
                    pMainPlayer->SetBattleWon();
                    pMainPlayer->SetCaptureCards(1);
                }
                else if (pMainPlayer->MonsterAlreadyCapturedCheck(pWildMonster) == true)
                {
                    cout << "You have captured " << pWildMonster->GetmonName();
                    pWildMonster->Heal();
                    HealPlayerMonsters(pMainPlayer);
                    cout << endl;
                    pMainPlayer->SetBattleWon();
                }
            //-------------------------------------------------------------------------------------------------------------------
            //if choice 2 then fight dave
            }
            if (battleChoice == 2)
            {
                if (CheckTrainerDefeat(pEasyDave) == false)
                {
                    while (CheckPlayerDefeat(pMainPlayer) == false && CheckTrainerDefeat(pEasyDave) == false)
                    {
                        SelectMonsters(pMainPlayer, playerChoice, pEasyDave, enemyChoice);
                        Battle(pMainPlayer, playerChoice, pEasyDave, enemyChoice);
                    }
                    if (CheckPlayerDefeat(pMainPlayer) == true)
                    {
                        cout << "You have lost!" << endl;
                            pMainPlayer->SetBattleLost();
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pEasyDave);
                    }
                    else
                    {
                        cout << "You have won!!" << endl;
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pHardJake);
                        pMainPlayer->SetBattleWon();
                    }
                }
                else
                {
                    cout << "You have defeated Dave already! choose another option!" << endl;
                }
            }
            //----------------------------------------------------------------------------------
            //choice 3 is missy
            else if (battleChoice == 3)
            {
                if (CheckTrainerDefeat(pMediumMissy) == false)
                {
                    while (CheckPlayerDefeat(pMainPlayer) == false && CheckTrainerDefeat(pMediumMissy) == false)
                    {
                        SelectMonsters(pMainPlayer, playerChoice, pMediumMissy, enemyChoice);
                        Battle(pMainPlayer, playerChoice, pMediumMissy, enemyChoice);
                    }
                    if (CheckPlayerDefeat(pMainPlayer) == true)
                    {
                        cout << "You have lost!" << endl;
                        pMainPlayer->SetBattleLost();
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pMediumMissy);
                    }
                    else
                    {
                        cout << "You have won!!" << endl;
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pHardJake);
                        pMainPlayer->SetBattleWon();
                    }
                }
                else
                {
                    cout << "You have defeated Missy already! choose another option!" << endl;
                }
            }
            //---------------------------------------------------------------------------------
            //choice 4 is jake
            else if (battleChoice == 4)
            {
                if (CheckTrainerDefeat(pHardJake) == false)
                {
                    while (CheckPlayerDefeat(pMainPlayer) == false && CheckTrainerDefeat(pHardJake) == false)
                    {
                        SelectMonsters(pMainPlayer, playerChoice, pHardJake, enemyChoice);
                        Battle(pMainPlayer, playerChoice, pHardJake, enemyChoice);
                    }
                    if (CheckPlayerDefeat(pMainPlayer) == true)
                    {
                        cout << "You have lost!" << endl;
                        pMainPlayer->SetBattleLost();
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pHardJake);
                    }
                    else
                    {
                        cout << "You have won!!" << endl;
                        HealPlayerMonsters(pMainPlayer);
                        HealTrainerMonsters(pHardJake);
                        pMainPlayer->SetBattleWon();
                    }
                }
                else
                {
                    cout << "You have defeated Jake already! choose another option!" << endl;
                }
            }
            system("pause");
        }
    }
}
//----------------------------------------------------------------------------------



int ShowMenu(MainCharacter* player)
{
    int choice = 0;
    int returnChoice = 0;

#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
    std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
    std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif

        //player chooses what they want to do
    while (returnChoice == 0)
    {
        player->PrintPlayerSheet();
        cout << "\n\n\n\n";

        cout << "Would you like to look for wild monster( Press 1 ), or fight a trainer? ( Press 2 )" << endl;
        cin >> choice;
        if (choice == 1)
        {
            returnChoice = 1;

        }
        else if (choice == 2)
        {
            char choiceTwo;
            cout << "Which trainer?" << endl;
            cout << "A: Trainer Dave: EASY" << endl;
            cout << "B: Trainer Missy: Medium" << endl;
            cout << "C: Trainer Jake: Hard" << endl;
            cin >> choiceTwo;
            if (choiceTwo == 'A')
            {
                
                returnChoice = 2;
            }
            else if (choiceTwo == 'B')
            {
                returnChoice = 3;
            }
            else if (choiceTwo == 'C')
            {
                returnChoice = 4;
            }
            else
            {
                cout << "Must choose a trainer! A, B, or C!" << endl;
                system("pause");
                system("cls");
            }
        }
        else
        {
            cout << "Must press 1 or 2!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            system("pause");
            system("cls");
        }
    }

#if SHOW_RETURN == 1
    cout << "CHOICE RETURNED IS " << returnChoice << endl;
#endif // SHOW_RETURN = 0


    return returnChoice;
}

void SelectMonsters(MainCharacter* player, int& choice, MonsterTrainer* trainer, int& enemyChoice)
{

    bool battle = false;
    Monster* pPlayerMonster = nullptr;
    Monster* pTrainerMonster = nullptr;
    bool playerMonsterSelected = false;
    system("cls");
    choice = NULL;
    enemyChoice = NULL;
    bool playerDefeated = false;
    while (playerMonsterSelected == false)
    {
        system("cls");
#ifdef VERBOSE_LOG

#if FILE_LOG == true
        std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
            std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
            std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
        //display players monsters to them
        cout << "Select your monster!" << endl;
        player->GetPlayerMonsters(player);
        choice = 8;

        cin >> choice;
        //Check for the monster to be alive, and to exist, after checking for failed inputs
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (choice == 0 && player->GetMonster(player, 0) != nullptr && *player->GetMonster(player, 0)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 0);
            choice = 0;
        }
        else if (choice == 1 && player->GetMonster(player, 1) != nullptr && *player->GetMonster(player, 1)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 1);
            choice = 1;
        }
        else if (choice == 2 && player->GetMonster(player, 2) != nullptr && *player->GetMonster(player, 2)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 2);
            choice = 2;
        }
        else if (choice == 3 && player->GetMonster(player, 4) != nullptr && *player->GetMonster(player, 3)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 3);
            choice = 3;
        }
        else if (choice == 4 && player->GetMonster(player, 4) != nullptr && *player->GetMonster(player, 4)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 4);
            choice = 4;
        }
        else if (choice == 5 && player->GetMonster(player, 5) != nullptr && *player->GetMonster(player, 5)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 5);
            choice = 5;
        }
        else if (choice == 6 && player->GetMonster(player, 6) != nullptr && *player->GetMonster(player, 6)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 6);
            choice = 6;
        }
        else if (choice == 7 && player->GetMonster(player, 7) != nullptr && *player->GetMonster(player, 7)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 7);
            choice = 7;
        }
        if (pPlayerMonster != nullptr)
        {
            playerMonsterSelected = true;
        }
        else if (choice < 0 || choice > 7)
        {
            cout << "Must select a monster! (0-7)" << endl;
            system("pause");
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 8;
        }
        else
        {
            playerMonsterSelected = false;
        }
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------
    //choose a monster for the trainer that is alive and exists also
        int i = 0;
        bool enemyHasChosen = false;
        while (enemyHasChosen == false)
        {
            if (trainer->GetMonster(trainer, i) != nullptr && *trainer->GetMonster(trainer, i)->GetMonsterCurrentHealth() > 0)
            {
                enemyChoice = i;
                enemyHasChosen = true;
            }
            else if (i == 8)
            {
                enemyHasChosen = true;
            }
            else
            {
                ++i;
            }

        }
  system("cls");
}

void Battle(MainCharacter* player, int slotOne, MonsterTrainer* trainer, int slotTwo)
{
    int selectedAttack = NULL;
    bool didHit = false;
    bool didCrit = false;
    bool strongHit = false;
    bool battle = true;
    int turn = 1;
    Monster* pMonsterOne = player->GetMonster(player, slotOne);
    Monster* pMonsterTwo = trainer->GetMonster(trainer, slotTwo);

    int* pMonsterOneHealth = pMonsterOne->GetMonsterCurrentHealth();
    int* pMonsterTwoHealth = pMonsterTwo->GetMonsterCurrentHealth();
    while (battle == true)
    {
        while (turn == 1)
        {
            if (*pMonsterOneHealth > 0)
            {

#ifdef VERBOSE_LOG

#if FILE_LOG == true
                std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
                    std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
                    std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
                pMonsterTwo->GetMonsterBattleInfo();
                cout << "\n\n\n\n";
                pMonsterOne->GetMonsterBattleInfo();
                pMonsterOne->GetMonsterSkills();
                cout << "\n Select your attack! 0-3" << endl;
                cin >> selectedAttack;
                //-------------------------------------------------------------------------------------------------------------
                //Will try to use the array slot of the number you chose, then will run all 3 checks to determine damage
                if (selectedAttack <= 3 && selectedAttack >= 0)
                {
                    if (pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack) == nullptr)
                    {
                        cout << "Must select a attack!" << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        didHit = AccuracyCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetAccuracy());
                        didCrit = CriticalCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetCritChance());
                        strongHit = StrongHitCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetStrongAgainstType(), pMonsterTwo->GetmonType());

                        if (didHit)
                        {
                            if (didCrit)
                            {

                                if (strongHit)
                                {
                                    pMonsterTwo->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3);
                                    cout << pMonsterOne->GetmonName();
                                    cout << " has Super Effective Critical Hit " << pMonsterTwo->GetmonName();
                                    cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 2;
                                }
                                else
                                {
                                    pMonsterTwo->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 2);
                                    cout << pMonsterOne->GetmonName();
                                    cout << " has critical hit " << pMonsterTwo->GetmonName();
                                    cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 2 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 2;
                                }
                            }
                            else if (strongHit)
                            {
                                pMonsterTwo->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3);
                                cout << pMonsterOne->GetmonName();
                                cout << " has Super Effective attacked " << pMonsterTwo->GetmonName();
                                cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3 << " damage!";
                                system("pause");
                                system("cls");
                                turn = 2;
                            }
                            else
                            {
                                pMonsterTwo->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage());
                                cout << pMonsterOne->GetmonName();
                                cout << " has Attacked " << pMonsterTwo->GetmonName();
                                cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() << " damage!";
                                system("pause");
                                system("cls");
                                turn = 2;
                            }
                        }
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    system("cls");
                }
            }
            else
            {
                battle = false;
                turn = NULL;
            }
            selectedAttack = 0;
        }
        //------------------------------------------------------------------------------------------------------------------------------------------
        //this will auto use the enemies first attack since there is no option for other attacks in the game yet - NEED TO CHANGE LATER IF I ADD MORE ATTACKS!!!!! -
        while (turn == 2)
        {
            if (*pMonsterTwoHealth > 0)
            {
                pMonsterTwo->GetMonsterBattleInfo();
                cout << "\n\n\n\n";
                pMonsterOne->GetMonsterBattleInfo();
                pMonsterOne->GetMonsterSkills();
#ifdef _DEBUG
                pMonsterOne->Heal(); \
                    std::cout << "Infinite health activated" << endl;
#endif // DEBUG
                selectedAttack = 0;
                if (selectedAttack <= 3 && selectedAttack >= 0)
                {
                    if (pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack) == nullptr)
                    {
                        system("pause");
                        system("clear");
                    }
                    else
                    {
                        didHit = AccuracyCheck(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetAccuracy());
                        didCrit = CriticalCheck(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetCritChance());
                        strongHit = StrongHitCheck(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetStrongAgainstType(), pMonsterOne->GetmonType());

                        if (didHit)
                        {
                            if (didCrit)
                            {

                                if (strongHit)
                                {
                                    pMonsterOne->MonsterTakeDamage(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 3);
                                    cout << pMonsterTwo->GetmonName();
                                    cout << " has Super Effective Critical Hit " << pMonsterOne->GetmonName();
                                    cout << " for " << pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 3 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 1;
                                }
                                else
                                {
                                    pMonsterOne->MonsterTakeDamage(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 2);
                                    cout << pMonsterTwo->GetmonName();
                                    cout << " has critical hit " << pMonsterOne->GetmonName();
                                    cout << " for " << pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 3 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 1;
                                }
                            }
                            else if (strongHit)
                            {
                                pMonsterOne->MonsterTakeDamage(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 3);
                                cout << pMonsterTwo->GetmonName();
                                cout << " has Super Effective attacked " << pMonsterOne->GetmonName();
                                cout << " for " << pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() * 3 << " damage!";
                                system("pause");
                                system("cls");
                                turn = 1;
                            }
                            else
                            {
                                pMonsterOne->MonsterTakeDamage(pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage());
                                cout << pMonsterTwo->GetmonName();
                                cout << " has Attacked " << pMonsterOne->GetmonName();
                                cout << " for " << pMonsterTwo->SelectedAttack(pMonsterTwo, selectedAttack)->GetDamage() << " damage!";
                                system("pause");
                                system("cls");
                                turn = 1;
                            }
                        }
                    }
                }
            }
            else
            {
                battle = false;
                turn = NULL;
                
            }
        }
    }
}

bool AccuracyCheck(int accuracy)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    int hitCheck = (rand() % 100) + 1;
    if (hitCheck <= accuracy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CriticalCheck(int critHit)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    int critCheck = (rand() % 100) + 1;
    if (critCheck <= critHit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool StrongHitCheck(string attackType, string defendType)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    if (attackType == defendType)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CheckPlayerDefeat(MainCharacter* player)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    bool playerDefeated = true;
    for (int i = 0; i < 8; ++i)
    {
        if (player->GetMonster(player, i) != nullptr)
        {
            if (*player->GetMonster(player, i)->GetMonsterCurrentHealth() > 0)
            {
                playerDefeated = false;
            }
        }
    }
    return playerDefeated;
}
bool CheckTrainerDefeat(MonsterTrainer* player)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    bool trainerDefeated = true;
    for (int i = 0; i < 8; ++i)
    {
        if (player->GetMonster(player, i) != nullptr)
        {
            if (*player->GetMonster(player, i)->GetMonsterCurrentHealth() > 0)
            {
                trainerDefeated = false;
            }
        }
    }
    return trainerDefeated;
}

void HealPlayerMonsters(MainCharacter* player)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    for (int i = 0; i < 8; ++i)
    {
        if (player->GetMonster(player, i) != nullptr)
        {
          
            player->GetMonster(player, i)->Heal();
        }
    }
}

void HealTrainerMonsters(MonsterTrainer* trainer)
{
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
    for (int i = 0; i < 8; ++i)
    {
        if (trainer->GetMonster(trainer, i) != nullptr)
        {

            trainer->GetMonster(trainer, i)->Heal();
        }
    }
}

void SelectMonsterWildBattle(MainCharacter* player, int& choice)
{
    //Same script as selectMonster but without the player monster being selected
    bool battle = false;
    Monster* pPlayerMonster = nullptr;
    Monster* pTrainerMonster = nullptr;
    bool playerMonsterSelected = false;
    system("cls");
    choice = NULL;
    bool playerDefeated = false;
    while (playerMonsterSelected == false)
    {
        system("cls");
#ifdef VERBOSE_LOG

#if FILE_LOG == true
        std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
            std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
            std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
        cout << "Select your monster!" << endl;
        player->GetPlayerMonsters(player);
        choice = 8;
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (choice == 0 && player->GetMonster(player, 0) != nullptr && *player->GetMonster(player, 0)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 0);
            choice = 0;
        }
        else if (choice == 1 && player->GetMonster(player, 1) != nullptr && *player->GetMonster(player, 1)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 1);
            choice = 1;
        }
        else if (choice == 2 && player->GetMonster(player, 2) != nullptr && *player->GetMonster(player, 2)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 2);
            choice = 2;
        }
        else if (choice == 3 && player->GetMonster(player, 4) != nullptr && *player->GetMonster(player, 3)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 3);
            choice = 3;
        }
        else if (choice == 4 && player->GetMonster(player, 4) != nullptr && *player->GetMonster(player, 4)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 4);
            choice = 4;
        }
        else if (choice == 5 && player->GetMonster(player, 5) != nullptr && *player->GetMonster(player, 5)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 5);
            choice = 5;
        }
        else if (choice == 6 && player->GetMonster(player, 6) != nullptr && *player->GetMonster(player, 6)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 6);
            choice = 6;
        }
        else if (choice == 7 && player->GetMonster(player, 7) != nullptr && *player->GetMonster(player, 7)->GetMonsterCurrentHealth() > 0)
        {
            pPlayerMonster = player->GetMonster(player, 7);
            choice = 7;
        }
        if (pPlayerMonster != nullptr)
        {
            playerMonsterSelected = true;
        }
        else if (choice < 0 || choice > 7 )
        {
            cout << "Must select a monster! (0-7)" << endl;
            system("pause");
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 8;
        }
        else
        {
            playerMonsterSelected = false;
        }
    }
    system("cls");
}

void WildBattle(MainCharacter* player, int slotOne, Monster* monster)
    {
    //same script as battle but has a extra capture function
        int selectedAttack = NULL;
        bool didHit = false;
        bool didCrit = false;
        bool strongHit = false;
        bool battle = true;
        int turn = 1;
        Monster* pMonsterOne = player->GetMonster(player, slotOne);

        int* pMonsterOneHealth = pMonsterOne->GetMonsterCurrentHealth();
        int* pMonsterTwoHealth = monster->GetMonsterCurrentHealth();
        while (battle == true)
        {
            while (turn == 1)
            {
                if (*pMonsterOneHealth > 0)
                {
#ifdef VERBOSE_LOG

#if FILE_LOG == true
                    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
                        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
                        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif
                    monster->GetMonsterBattleInfo();
                    cout << "\n\n\n\n";
                    pMonsterOne->GetMonsterBattleInfo();
                    pMonsterOne->GetMonsterSkills();
#ifdef _DEBUG
                    pMonsterOne->Heal(); \
                    std::cout << "Infinite health activated" << endl;
#endif // DEBUG

                    cout << "\n Select your attack! 0-3 or press 5 to use a capture card!" << endl;
                    cin >> selectedAttack;
                    if (selectedAttack <= 3 && selectedAttack >= 0)
                    {
                        if (pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack) == nullptr)
                        {
                            cout << "Must select a attack!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            didHit = AccuracyCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetAccuracy());
                            didCrit = CriticalCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetCritChance());
                            strongHit = StrongHitCheck(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetStrongAgainstType(), monster->GetmonType());

                            if (didHit)
                            {
                                if (didCrit)
                                {

                                    if (strongHit)
                                    {
                                        monster->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3);
                                        cout << pMonsterOne->GetmonName();
                                        cout << " has Super Effective Critical Hit " << monster->GetmonName();
                                        cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3 << " damage!";
                                        system("pause");
                                        system("cls");
                                        turn = 2;
                                    }
                                    else
                                    {
                                        monster->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 2);
                                        cout << pMonsterOne->GetmonName();
                                        cout << " has critical hit " << monster->GetmonName();
                                        cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 2 << " damage!";
                                        system("pause");
                                        system("cls");
                                        turn = 2;
                                    }
                                }
                                else if (strongHit)
                                {
                                    monster->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3);
                                    cout << pMonsterOne->GetmonName();
                                    cout << " has Super Effective attacked " << monster->GetmonName();
                                    cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() * 3 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 2;
                                }
                                else
                                {
                                    monster->MonsterTakeDamage(pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage());
                                    cout << pMonsterOne->GetmonName();
                                    cout << " has Attacked " << monster->GetmonName();
                                    cout << " for " << pMonsterOne->SelectedAttack(pMonsterOne, selectedAttack)->GetDamage() << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 2;
                                }
                            }
                        }
                    }
                    //Capture function - check for players cards, then run capture check
                    else if (selectedAttack == 5)
                    {
                      int i = 0;
                      int check = CaptureCheck(monster);
#ifdef _DEBUG
                      std::cout << "Gauranteed capture active" << endl;
#endif
                      bool captured = false;
                      if (player->GetCaptureCards() > 0)
                      {
                          if (check == 1)
                          {
                              if (player->MonsterAlreadyCapturedCheck(monster) == false)
                              {
                                  while (player->GetMonster(player, i) != nullptr && i < 9)
                                  {
                                      ++i;
                                  }
                                  player->SetNewMonster(monster, i);
                                  battle = false;
                                  turn = NULL;
                                  i = 0;
                              }
                              else
                              {
                                  cout << "You already have that monster!" << endl;
                                  system("pause");
                                  system("cls");
                                  turn = 1;
                              }
                          }
                          else
                          {
                              cout << "You have failed to capture " << monster->GetmonName();
                              cout << endl;
                              player->LoseACaptureCard();
                              turn = 2;
                              system("pause");
                          }
                      }
                      else
                      {
                          cout << "You have no capture cards!" << endl;
                          system("pause");
                          turn = 1;
                      }
                    }
                }
                else
                {
                    battle = false;
                    turn = NULL;
                }
                selectedAttack = 0;
            }
            while (turn == 2)
            {
                if (*pMonsterTwoHealth > 0)
                {
                    monster->GetMonsterBattleInfo();
                    cout << "\n\n\n\n";
                    pMonsterOne->GetMonsterBattleInfo();
                    pMonsterOne->GetMonsterSkills();
                    selectedAttack = 0;
                    if (selectedAttack <= 3 && selectedAttack >= 0)
                    {
                        if (monster->SelectedAttack(monster, selectedAttack) == nullptr)
                        {
                            system("pause");
                            system("clear");
                        }
                        else
                        {
                            didHit = AccuracyCheck(monster->SelectedAttack(monster, selectedAttack)->GetAccuracy());
                            didCrit = CriticalCheck(monster->SelectedAttack(monster, selectedAttack)->GetCritChance());
                            strongHit = StrongHitCheck(monster->SelectedAttack(monster, selectedAttack)->GetStrongAgainstType(), pMonsterOne->GetmonType());

                            if (didHit)
                            {
                                if (didCrit)
                                {

                                    if (strongHit)
                                    {
                                        pMonsterOne->MonsterTakeDamage(monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 3);
                                        cout << monster->GetmonName();
                                        cout << " has Super Effective Critical Hit " << pMonsterOne->GetmonName();
                                        cout << " for " << monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 3 << " damage!";
                                        system("pause");
                                        system("cls");
                                        turn = 1;
                                    }
                                    else
                                    {
                                        pMonsterOne->MonsterTakeDamage(monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 2);
                                        cout << monster->GetmonName();
                                        cout << " has critical hit " << pMonsterOne->GetmonName();
                                        cout << " for " << monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 3 << " damage!";
                                        system("pause");
                                        system("cls");
                                        turn = 1;
                                    }
                                }
                                else if (strongHit)
                                {
                                    pMonsterOne->MonsterTakeDamage(monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 3);
                                    cout << monster->GetmonName();
                                    cout << " has Super Effective attacked " << pMonsterOne->GetmonName();
                                    cout << " for " << monster->SelectedAttack(monster, selectedAttack)->GetDamage() * 3 << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 1;
                                }
                                else
                                {
                                    pMonsterOne->MonsterTakeDamage(monster->SelectedAttack(monster, selectedAttack)->GetDamage());
                                    cout << monster->GetmonName();
                                    cout << " has Attacked " << pMonsterOne->GetmonName();
                                    cout << " for " << monster->SelectedAttack(monster, selectedAttack)->GetDamage() << " damage!";
                                    system("pause");
                                    system("cls");
                                    turn = 1;
                                }
                            }
                        }
                    }
                }
                else
                {
                    battle = false;
                    turn = NULL;

                }
            }
        }
    }


int CaptureCheck(Monster* monster)
    {
#ifdef VERBOSE_LOG

#if FILE_LOG == true
    std::cout << "File Location: ";  VERBOSE_LOG(__FILE__)
#endif

#if LINE_LOG == true
        std::cout << "Line Number: "; VERBOSE_LOG(__LINE__)
#endif

#if FUNCTION_LOG == true
        std::cout << "Function Name: ";  VERBOSE_LOG(__func__)
#endif

#endif


        int captureChance = monster->GetmonCaptureChance();
        int captureAttempt = ((rand() % 100) + 1);
        if (captureAttempt <= captureChance)
        {
            return 1;
        }
#ifdef _DEBUG
return 1;
#endif
        return 2;
    }
