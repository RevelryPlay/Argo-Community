#pragma once

#include "../../Common/Types/BaseSprite.hpp"

namespace Argo::Graphics {

/**
 * \brief GLSprite handles the rendering of a texture to a specific region
 */
struct GLSprite : Types::BaseSprite {
    /**
     * \brief Calculates the vertices of the sprite based on the viewport width and height
     * \param viewPortWidth The width of the viewport
     * \param viewPortHeight The height of the viewport
     * \return A vector of x,y,z coordinates representing the vertices of the sprite
     */
    [[nodiscard]] std::vector< Types::Vec3 > calculateRecVertices( int viewPortWidth, int viewPortHeight ) const;
};

}  // namespace Argo::Graphics
