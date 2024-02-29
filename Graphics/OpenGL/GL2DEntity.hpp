#pragma once
#include "../../Common/Types/BaseEntity.hpp"
#include "GL2DSprite.hpp"

namespace Argo::Graphics {

/**
 * \brief GLEntity describe an entity and its functionality.
 */
struct GL2DEntity : Types::BaseEntity {
    GL2DSprite *sprite{};

    // Set the sprite of the entity.
    void setSprite( GL2DSprite *_sprite );
};

}  // namespace Argo::Graphics