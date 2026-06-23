#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include "item.h"

class Player
{

  std::string name;
  uint32_t gold{0};
  std::vector<Item> Inventory;

public:
  Player(const std::string &playerName, uint32_t playerGold);
  void buyItem(const Item &itemToBuy);
  [[nodiscard]] std::string getName() const { return name; }
  [[nodiscard]] uint32_t getGold() const { return gold; }
  [[nodiscard]] const std::vector<Item> &getInventory() const { return Inventory; }
};
