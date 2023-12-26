#pragma once
#include "../Common/System/Camera.hpp"
#include "../Common/System/Entity.hpp"
#include "../Common/Types/BaseScene.hpp"
#include "GLCamera.hpp"
#include "GLEntity.hpp"

namespace Argo::Graphics {

/**
 * \brief `GLScene` is a type of scene that adds OpenGL specific behaviors
 */
struct GLScene : Types::BaseScene {

    // Only one camera at this time in the future the entity component system will allow multiple
    System::Camera< GLCamera > *camera{};
    std::list< System::Entity< GLEntity > * > entities{};

};

}  // namespace Argo::Graphics
