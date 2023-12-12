#pragma once
#include "GLCamera.hpp"
#include "GLEntity.hpp"

#include <list>

namespace Argo::Graphics {

/**
 * \brief
 */
class GLScene {
  public:
    // GUID

    // Only one camera at this time in the future the entity component system will allow multiple
    GLCamera *camera;

    std::list< GLEntity * > entities;

    // list<GUID> entityIds = [];
    // list<GUID> lightIds = [];

    float width = 0;
    float height = 0;
};

}  // namespace Argo::Graphics
