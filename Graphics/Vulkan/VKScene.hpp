#pragma once
#include "../Common/System/Camera.hpp"
#include "../Common/System/Entity.hpp"
#include "../Common/Types/BaseScene.hpp"
#include "VKCamera.hpp"
#include "VKEntity.hpp"

namespace Argo::Graphics {

/**
 * \brief `VKScene` is a type of scene that adds Vulkan specific behaviors
 */
struct VKScene : Types::BaseScene {

    // Only one camera at this time in the future the entity component system will allow multiple
    System::Camera< VKCamera > *camera{};
    std::list< System::Entity< VKEntity > * > entities{};

};

}  // namespace Argo::Graphics
