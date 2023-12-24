#pragma once
#include "GLSprite.hpp"
#include "../Common/Types/BaseEntity.hpp"

namespace Argo::Graphics {

/**
 * \brief GLEntity describe an entity and its functionality.
 */
class GLEntity: public Types::BaseEntity {
  public:
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
