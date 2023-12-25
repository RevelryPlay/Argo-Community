#pragma once

#include "../Common/Types/BaseScene.hpp"
#include "VKCamera.hpp"
#include "VKEntity.hpp"

#include <list>

namespace Argo::Graphics {
struct VKScene : Types::BaseScene {
    VKCamera *camera{};
    std::list< VKEntity * > entities{};
};
}  // namespace Argo::Graphics
