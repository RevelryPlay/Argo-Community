#include "ColorConverter.hpp"

namespace Argo::Utilities {
CommonColor ConvertColor::FromRGBA(Argo::Vec4 rgba) { return ConvertColor::FromRGBA(&rgba); }

CommonColor ConvertColor::FromRGBA(Argo::Vec4 *rgba)
{
  CommonColor color = { rgba->w / 255, rgba->x / 255, rgba->y / 255, rgba->z };
  return color;
}

CommonColor ConvertColor::FromHex(unsigned int hex) { return ConvertColor::FromHex(&hex); }

CommonColor ConvertColor::FromHex(const unsigned int *hex)
{
  CommonColor rgba = CommonColor();

  rgba.red = ((*hex >> 24) & 0xFF) / 255.0;
  rgba.green = ((*hex >> 16) & 0xFF) / 255.0;
  rgba.blue = ((*hex >> 8) & 0xFF) / 255.0;
  rgba.alpha = ((*hex) & 0xFF) / 255.0;

  return rgba;
}

CommonColor ConvertColor::FromHex(const std::string hex) { return FromHex(&hex); }

CommonColor ConvertColor::FromHex(const std::string *hex)
{
  if (hex->length() != 6 && hex->length() != 8) {
    std::cout << "Invalid hexadecimal color. Please use the 6 or 8 digit format, e.g. FF0000 or FF0000FF" << '\n';
  }

  Vec4 rgba = Vec4();
  rgba.z = 1.0f;

  rgba.w = stoi(hex->substr(0, 2), nullptr, 16);
  rgba.x = stoi(hex->substr(2, 2), nullptr, 16);
  rgba.y = stoi(hex->substr(4, 2), nullptr, 16);

  // RGBA Hex
  if (hex->length() == 8) {
    rgba.z = stoi(hex->substr(6, 2), nullptr, 16) / 255.0f;
  }

  return FromRGBA(&rgba);
}
}// namespace Argo::Utilities
