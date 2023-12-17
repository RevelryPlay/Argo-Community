#pragma once

#include "Vec4.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

namespace Argo::Types {
/**
 * Generic color that can be used throughout Argo
 */
struct CommonColor {
    float red{ 1.0f };
    float green{ 1.0f };
    float blue{ 1.0f };
    float alpha{ 1.0f };

    /**
     * Returns an Vec4 for compatibility with other libraries
     * @return Vec4
     */
    Vec4 ToVec4() const { return Vec4( { red, green, blue, alpha } ); }


    /**
     * Returns a hexadecimal string for the current CommonColor
     * @return string
     */
    auto ToHex() const {
        string hexRet;

        hexRet += decimalToHex( red * 255 );
        hexRet += decimalToHex( green * 255 );
        hexRet += decimalToHex( blue * 255 );
        hexRet += decimalToHex( alpha * 255 );

        return hexRet;
    }

  private:
    static string decimalToHex( int decimal );
};
}  // namespace Argo::Types
