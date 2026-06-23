#pragma once

#include <cstdint>
#include <string>

struct Item
{
  std::string name;
  double weight{0.0};
  uint32_t id{0};
  uint32_t value{0};
  bool isEquipped{false};
};
