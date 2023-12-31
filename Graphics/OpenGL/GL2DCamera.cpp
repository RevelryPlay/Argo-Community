#include "GL2DCamera.hpp"

namespace Argo::Graphics {

GL2DCamera::GL2DCamera( const int _width, const int _height, const int _xPos, const int _yPos ) {
    width = _width;
    height = _height;
    xPos = _xPos;
    yPos = _yPos;
}

}  // namespace Argo::Graphics
