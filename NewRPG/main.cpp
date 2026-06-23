#include <iostream>
#include <memory>
#include "player.h"
#include "item.h"

int main()
{
  std::unique_ptr<Player> hero = std::make_unique<Player>("Shiva", 150);

  Item item1{.name = "Iron Sword", .weight = 4.5, .id = 1, .value = 50, .isEquipped = false};
  Item item2{.name = "Dragon Shield", .weight = 12.0, .id = 2, .value = 500, .isEquipped = false};

  std::cout << "Action: Buying Iron Sword...\n";
  hero->buyItem(item1);

  std::cout << "\nAction: Buying Dragon Shield...\n";
  hero->buyItem(item2);

  std::cout << "\n--- " << hero->getName() << "'s Inventory ---\n";
  std::cout << "Remaining Gold: " << hero->getGold() << "\n";
  std::cout << "Items:\n";

  for (const Item &item : hero->getInventory())
  {
    std::cout << " - " << item.name << "\n";
  }

  return 0;
}
