#pragma once
#include "BaseCamera.hpp"
#include "BaseEntity.hpp"
#include "BaseLight.hpp"

#include <list>

namespace Argo::Types {
struct BaseScene {
    BaseScene() = default;
    BaseScene( const int width, const int height ) : width( width ), height( height ){};
    // GUID

    // list<GUID> entityIds = [];
    // list<GUID> lightIds = [];

    int width{ 0 };
    int height{ 0 };
};
}  // namespace Argo::Types
