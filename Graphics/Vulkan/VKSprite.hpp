#pragma once

#include "../Common/Types/BaseSprite.hpp"

namespace Argo::Graphics {
struct VKSprite : Types::BaseSprite {
    [[nodiscard]] std::vector< Types::Vertex > calculateRecVertices( float viewPortWidth, float viewPortHeight ) const;
};
}  // namespace Argo::Graphics
