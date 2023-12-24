#pragma once
#include "../Common/Types/BaseEntity.hpp"
#include "GLSprite.hpp"

namespace Argo::Graphics {

/**
 * \brief GLEntity describe an entity and its functionality.
 */
struct GLEntity : Types::BaseEntity {
    // GUID
    // GUID spriteId

    GLSprite *sprite{};

    float xPos{ 0 };
    float yPos{ 0 };
    float width{ 0 };
    float height{ 0 };
    float rotation{ 0 };
    float scale{ 1.0F };
};

}  // namespace Argo::Graphics
