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
}// namespace Argo::Utilities
