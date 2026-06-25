#include <iostream>
#include "player.h"
#include <memory>
Player::Player(const std::string &playerName, uint32_t playerGold)
{
  name = playerName;
  gold = playerGold;
}
void Player::buyItem(std::unique_ptr<Item> itemToBuy)
{
  if (gold < itemToBuy->getvalue())
  {
    std::cout << "Not enough gold to Buy :\n";
    return;
  }
  gold -= itemToBuy->getvalue();
  std::cout << "Item added to Inventory: " << itemToBuy->getname() << "\n";
  Inventory.push_back(std::move(itemToBuy));
}
