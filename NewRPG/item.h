#pragma once

#include <cstdint>
#include <string>
#include <iostream>

class IEquipped
{
public:
  virtual ~IEquipped() = default;
  virtual void equip() const = 0;
};
class Item
{
protected:
  std::string name;
  uint32_t value{0};

public:
  Item(std::string wname, uint32_t wvalue) : name(wname), value(wvalue) {}
  virtual ~Item() = default;
  virtual void use() const
  {
    std::cout << "Used to print the usecase :\n";
  }
  [[nodiscard]] std::string getname() const { return name; }
  [[nodiscard]] uint32_t getvalue() const { return value; }
};

class weapon : public Item, public IEquipped
{
  int damage;

public:
  weapon(std::string wname, uint32_t wvalue, int damage) : Item(wname, wvalue), damage(damage) {}
  void use() const override
  {
    std::cout << ">>> You swing the " << name << " and deal " << damage << " DAMAGE!\n";
  }
  void equip() const override
  {
    std::cout << "[Equipped " << name << " to Main Hand]\n ";
  }
};

class potion : public Item
{
  int healAmount;

public:
  potion(std::string n, uint32_t v, int healAmount) : Item(n, v), healAmount(healAmount) {}
  void use() const override
  {
    std::cout << "+++ You drink the " << name << " and recover " << healAmount << " HP!\n";
  }
};

