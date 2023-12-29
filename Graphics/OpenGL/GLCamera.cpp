#include "GLCamera.hpp"

namespace Argo::Graphics {

GLCamera::GLCamera( const int _width, const int _height, const int _xPos, const int _yPos ) {
    width = _width;
    height = _height;
    xPos = _xPos;
    yPos = _yPos;
}

}  // namespace Argo::Graphics
