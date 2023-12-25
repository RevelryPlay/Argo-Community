#pragma once
#include "../Common/Types/BaseScene.hpp"
#include "GLCamera.hpp"
#include "GLEntity.hpp"

#include <list>

namespace Argo::Graphics {

/**
 * \brief
 */
struct GLScene : Types::BaseScene {

    // Only one camera at this time in the future the entity component system will allow multiple
    GLCamera *camera{};
    std::list< GLEntity * > entities{};
};

}  // namespace Argo::Graphics
