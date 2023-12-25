#pragma once

#include "../Common/Types/BaseEntity.hpp"
#include "VKSprite.hpp"

namespace Argo::Graphics {

struct VKEntity : Types::BaseEntity {
    VKSprite *sprite{};
};

}  // namespace Argo::Graphics
