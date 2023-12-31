#include "GLSprite.hpp"
#include <__algorithm/clamp.h>

namespace Argo::Graphics {
std::vector< Types::Vec3 > GLSprite::calculateRecVertices( const int viewPortWidth, const int viewPortHeight ) const {
    // Calculate the vertices of the sprite based on the viewport width and height and the sprite's width and height
    // preserving aspect ratio The sprite's width and height are in pixels, the viewport's width and height are in
    // pixels Scale the sprite's width and height proportionally to the viewport's width and height
    // Vertices are in normalized device coordinates (NDC) which range from -1 to 1

    // Calculate the aspect ratio of the sprite
    const float aspectRatio = width / height;

    // Calculate the aspect ratio of the viewport
    const float viewPortAspectRatio = viewPortWidth / viewPortHeight;

    // Calculate the scale of the sprite
    const auto scale = std::clamp( viewPortAspectRatio / aspectRatio, 0.0F, 1.0F );

    // Calculate the scaled width and height of the sprite
    const auto scaledWidth = width * scale;
    const auto scaledHeight = height * scale;

    // Calculate the x and y coordinates of the sprite
    const auto x = xPos / viewPortWidth * 2.0F;
    const auto y = yPos / viewPortHeight * 2.0F;

    // Calculate normalized device coordinates (NDC) for the sprite
    const auto left = x - scaledWidth / viewPortWidth;
    const auto right = x + scaledWidth / viewPortWidth;

    const auto top = y + scaledHeight / viewPortHeight;
    const auto bottom = y - scaledHeight / viewPortHeight;

    // Calculate the vertices of the sprite
    return {
        { left, bottom, 0.0F },
        { right, bottom, 0.0F },
        { right, top, 0.0F },
        { left, top, 0.0F },
    };
}


}  // namespace Argo::Graphics
