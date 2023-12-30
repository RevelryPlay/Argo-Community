#pragma once

#include "Vec4.hpp"
#include <algorithm>
#include <string>

using namespace std;

namespace Argo::Types {
/**
 * Generic color that can be used throughout Argo
 */
struct CommonColor {
    float red{ 1.0F };
    float green{ 1.0F };
    float blue{ 1.0F };
    float alpha{ 1.0F };

    /**
     * Returns an Vec4 for compatibility with other libraries
     * @return Vec4
     */
    [[nodiscard]] Vec4 ToVec4() const { return Vec4( { red, green, blue, alpha } ); }


    /**
     * Returns a hexadecimal string for the current CommonColor
     * @return string
     */
    [[nodiscard]] string ToHex() const;

    static string decimalToHex( int decimal );
};
}  // namespace Argo::Types
