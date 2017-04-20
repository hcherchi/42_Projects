#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  FragTrap *player1;
  ScavTrap *player2;
  int turn = 0;
  std::string input = "";

  std::cout << "Welcome to the battle. You'll first have to decide who will be fighting." << std::endl;

  std::cout << "Hero 1 -> ";
  std::getline(std::cin, input, '\n');
  player1 = new FragTrap(input);

  std::cout << "Hero 2 -> ";
  std::getline(std::cin, input, '\n');
  player2 = new ScavTrap(input);

  while (player1->getHP() != 0 && player2->getHP() != 0 && !std::cin.eof())
  {
    std::cout << std::endl << std::endl;
    std::cout << player1->getName() << ": " << player1->getHP() << "HP / " << player1->getMP() << "MP" << std::endl;
    std::cout << player2->getName() << ": " << player2->getHP() << "HP / " << player2->getMP() << "MP" << std::endl;
    if (turn % 2)
    {
      std::cout << player2->getName() << "'s turn, you can either HEAL or attack with RANGE | MELEE | SPECIAL -> ";
      std::getline(std::cin, input, '\n');
      if (input == "RANGE")
        player1->takeDamage(player2->rangedAttack(player1->getName()));
      else if (input == "MELEE")
        player1->takeDamage(player2->meleeAttack(player1->getName()));
      else if (input == "SPECIAL")
        player1->takeDamage(player2->challengeNewcomer(player1->getName()));
      else if (input == "HEAL")
        player2->beRepaired(50);
      else
        continue;
      turn++;
    }
    else
    {
      std::cout << player1->getName() << "'s turn, you can either HEAL or attack with RANGE | MELEE | SPECIAL -> ";
      std::getline(std::cin, input, '\n');
      if (input == "RANGE")
        player2->takeDamage(player1->rangedAttack(player2->getName()));
      else if (input == "MELEE")
        player2->takeDamage(player1->meleeAttack(player2->getName()));
      else if (input == "SPECIAL")
        player2->takeDamage(player1->vaulthunter_dot_exe(player2->getName()));
      else if (input == "HEAL")
        player1->beRepaired(50);
      else
        continue;
      turn++;
    }
  }
  delete(player1);
  delete(player2);
  std::cout << std::endl << "THE END" << std::endl;
  return 0;
}
