#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include "item.h"

class Player
{

  std::string name;
  uint32_t gold{0};
  std::vector<std::unique_ptr<Item>> Inventory;

public:
  Player(const std::string &playerName, uint32_t playerGold);
  void buyItem(std::unique_ptr<Item> itemToBuy);
  [[nodiscard]] std::string getName() const { return name; }
  [[nodiscard]] uint32_t getGold() const { return gold; }
  [[nodiscard]] const std::vector<std::unique_ptr<Item>> &getInventory() const { return Inventory; }
};
