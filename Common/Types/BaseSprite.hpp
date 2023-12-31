#pragma once

#include "Vec3.hpp"
#include <string>
#include <vector>

namespace Argo::Types {
struct BaseSprite {
    // GUID

    float xPos{ 0 };
    float yPos{ 0 };
    float width{ 0 };
    float height{ 0 };
    float rotation{ 0 };

    std::string filePath{};
};
}  // namespace Argo::Types
