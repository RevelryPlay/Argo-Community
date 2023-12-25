#pragma once

#include "Vertex.hpp"
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
    float scale{ 1.0F };

    std::string filePath{};
};
}  // namespace Argo::Types
