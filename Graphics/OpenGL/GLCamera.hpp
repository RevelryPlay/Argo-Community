#pragma once
#include "../../Common/Types/BaseCamera.hpp"

namespace Argo::Graphics {

/**
 * \brief
 */

struct GLCamera : Types::BaseCamera {
    GLCamera( const int _width, const int _height, const int _xPos, const int _yPos );
};

}  // namespace Argo::Graphics
