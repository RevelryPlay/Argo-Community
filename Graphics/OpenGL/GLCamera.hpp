#pragma once
#include "../Common/Types/BaseCamera.hpp"

namespace Argo::Graphics {

/**
 * \brief
 */

class GLCamera: public Types::BaseCamera {
  public:
    // GUID

    float xPos{ 0 };
    float yPos{ 0 };
    float width{ 0 };
    float height{ 0 };
};

}  // namespace Argo::Graphics
