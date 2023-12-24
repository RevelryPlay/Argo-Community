#pragma once

#include "../Common/Types/Vertex.hpp"
#include "../Common/Types/BaseSprite.hpp"
#include <string>
#include <vector>

namespace Argo::Graphics {

/**
 * \brief GLSprite handles the rendering of a texture to a specific region
 */
class GLSprite: public Types::BaseSprite {
  public:
    // GUID

    float xPos{ 0 };
    float yPos{ 0 };
    float width{ 0 };
    float height{ 0 };
    float rotation{ 0 };
    float scale{ 1.0F };

    std::string filePath{};

    std::vector< Types::Vertex > calculateRecVertices( float viewPortWidth, float viewPortHeight ) const;
};

}  // namespace Argo::Graphics
