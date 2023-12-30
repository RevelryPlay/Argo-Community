#pragma once

#include "../../Common/Types/BaseSprite.hpp"

namespace Argo::Graphics {

/**
 * \brief GLSprite handles the rendering of a texture to a specific region
 */
struct GLSprite : Types::BaseSprite {
    [[nodiscard]] std::vector< Types::Vec3 > calculateRecVertices( float viewPortWidth, float viewPortHeight ) const;
};

}  // namespace Argo::Graphics
