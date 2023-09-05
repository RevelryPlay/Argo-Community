#pragma once

#include "Vec4.hpp"

namespace Argo {
    /**
     * Generic color that can be used throughout Argo
     */
    class CommonColor {
    public:
        float red = 1.0f;
        float green = 1.0f;
        float blue = 1.0f;
        float alpha = 1.0f;

        /**
         * Returns an Vec4 for compatibility with other libraries
         * @return Vec4
         */
        Vec4 ToVec4() const {
            return Vec4(
              {
                    red,
                    green,
                    blue,
                    alpha
              }
            );
        }
    };
}
