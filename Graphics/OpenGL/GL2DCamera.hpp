#pragma once
#include "../../Common/Types/BaseCamera.hpp"

namespace Argo::Graphics {

/**
 * \brief
 */

struct GL2DCamera : Types::BaseCamera {
    GL2DCamera( const int _width, const int _height, const int _xPos, const int _yPos );
};

}  // namespace Argo::Graphics
