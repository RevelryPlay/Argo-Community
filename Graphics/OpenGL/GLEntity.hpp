#pragma once
#include "../../Common/Types/BaseEntity.hpp"
#include "GLSprite.hpp"

namespace Argo::Graphics {

/**
 * \brief GLEntity describe an entity and its functionality.
 */
struct GLEntity : Types::BaseEntity {
    GLSprite *sprite{};
};

}  // namespace Argo::Graphics
