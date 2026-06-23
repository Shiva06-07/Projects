#include <iostream>
#include "player.h"

Player::Player(const std::string &playerName, uint32_t playerGold)
{
  name = playerName;
  gold = playerGold;
}
void Player::buyItem(const Item &itemToBuy)
{
  if (gold < itemToBuy.value)
  {
    std::cout << "Not enough gold to Buy :\n";
    return;
  }
  gold -= itemToBuy.value;
  Inventory.push_back(itemToBuy);
  std::cout << "Item added to Inventory: " << itemToBuy.name << "\n";
}