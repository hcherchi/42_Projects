#include "FragTrap.hpp"
#include "ScavTrap.hpp"

ClapTrap *getPlayer(int index)
{
  ClapTrap *player = NULL;
  std::string _name = "";
  std::string _type = "";

  std::cout << std::endl << "Hero " << index << std::endl << "Name -> ";
  std::getline(std::cin, _name, '\n');
  while (_type != "FragTrap" && _type != "ScavTrap" && !std::cin.eof())
  {
    std::cout << "Class -> ";
    std::getline(std::cin, _type, '\n');
  }
  if (_type == "FragTrap")
    player = new FragTrap(_name);
  else if (_type == "ScavTrap")
    player = new ScavTrap(_name);
  else
    exit(0);
  return player;
}

int main(void)
{
  ClapTrap *player1;
  ClapTrap *player2;
  ClapTrap *otherPlayer;
  ClapTrap *currentPlayer;
  int turn = 0;
  std::string input = "";

  std::cout << "Welcome to the battle. You'll first have to decide who will be fighting." << std::endl;
  player1 = getPlayer(1);
  player2 = getPlayer(2);

  while (player1->getHP() != 0 && player2->getHP() != 0 && !std::cin.eof())
  {
    currentPlayer = (turn % 2) ? player2 : player1;
    otherPlayer = (turn % 2) ? player1 : player2;

    std::cout << std::endl << std::endl;
    std::cout << player1->getName() << ": " << player1->getHP() << "HP / " << player1->getMP() << "MP" << std::endl;
    std::cout << player2->getName() << ": " << player2->getHP() << "HP / " << player2->getMP() << "MP" << std::endl;
    std::cout << currentPlayer->getName() << "'s turn, you can either HEAL or attack with RANGE | MELEE | SPECIAL -> ";
    std::getline(std::cin, input, '\n');

    if (input == "RANGE")
      otherPlayer->takeDamage(currentPlayer->rangedAttack(otherPlayer->getName()));
    else if (input == "MELEE")
      otherPlayer->takeDamage(currentPlayer->meleeAttack(otherPlayer->getName()));
    else if (input == "HEAL")
      currentPlayer->beRepaired(50);
      else if (input == "SPECIAL")
      {
        if (currentPlayer->getType() == "ScavTrap")
          otherPlayer->takeDamage(((ScavTrap*)currentPlayer)->challengeNewcomer(otherPlayer->getName()));
        else if (currentPlayer->getType() == "FragTrap")
          otherPlayer->takeDamage(((FragTrap*)currentPlayer)->vaulthunter_dot_exe(otherPlayer->getName()));
      }
    else
      continue;
    turn++;
  }
  delete(player1);
  delete(player2);
  std::cout << std::endl << "THE END" << std::endl;
  return 0;
}
