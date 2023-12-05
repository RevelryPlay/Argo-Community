#pragma once

#include <string>
#include <vector>
#include "../Common/Types/Vertex2D.hpp"

namespace Argo::Graphics {

/**
 * \brief GLSprite handles the rendering of a texture to a specific region
 */
class GLSprite {
  public:
    // GUID

    float xPos = 0;
    float yPos = 0;
    float width = 0;
    float height = 0;
    float rotation = 0;
    float scale = 1.0F;

    std::string filePath;

    std::vector<Types::Vertex2D> calculateRecVertices(float viewPortWidth, float viewPortHeight);

};

}  // namespace Argo::Graphics
