#include <iostream>
#include <memory>
#include "player.h"
#include "item.h"

int main()
{
  std::unique_ptr<Player> hero = std::make_unique<Player>("Shiva", 150);

  std::unique_ptr<weapon> sword = std::make_unique<weapon>("Iron Sword", 50, 25);
  std::unique_ptr<potion> Potion = std::make_unique<potion>("Health Potion", 15, 50);

  std::cout << "Action: Buying Iron Sword...\n";
  hero->buyItem(std::move(sword));

  std::cout << "\nAction: Buying Health Potion...\n";
  hero->buyItem(std::move(Potion));

  std::cout << "\n--- " << hero->getName() << "'s Inventory ---\n";
  std::cout << "Remaining Gold: " << hero->getGold() << "\n";
  std::cout << "Items:\n";

  for (const auto &item : hero->getInventory())
  {
    std::cout << " - " << item->getname() << "\n";

    IEquipped *isEquipped = dynamic_cast<IEquipped *>(item.get());
    if (isEquipped != nullptr)
    {
      isEquipped->equip();
    }
    else
    {
      std::cout << "The Item is not equippable \n";
    }

    return 0;
  }
}
