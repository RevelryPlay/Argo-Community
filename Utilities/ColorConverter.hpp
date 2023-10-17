#pragma once

#include "../Common/Types/CommonColor.hpp"
#include <iostream>

using namespace std;

namespace Argo::Utilities {
struct ConvertColor {
    /**
     * Creates a CommonColor from a Vec 4 RGBA object
     *
     * @param rgba - { red, green, blue, alpha };
     * red, green, blue values are between 0 and 255;
     * alpha is a float between 0 and 1
     * @return CommonColor
     */
    static CommonColor FromRGBA( Vec4 rgba );

    /**
     * Creates a CommonColor from a Vec 4 RGBA object pointer
     *
     * @param rgba - { red, green, blue, alpha };
     * red, green, blue values are between 0 and 255;
     * alpha is a float between 0 and 1
     * @return CommonColor
     */
    static CommonColor FromRGBA( Vec4 *rgba );

    /**
     * Creates a CommonColor from a hexadecimal value with alpha
     * @param hex - 0xRRGGBBAA
     * @return CommonColor
     */
    static CommonColor FromHex( unsigned int hex );

    /**
     * Creates a CommonColor from a hexadecimal value with alpha pointer
     * @param hex - 0xRRGGBBAA
     * @return CommonColor
     */
    static CommonColor FromHex( const unsigned int *hex );

    /**
     * Creates a CommonColor from a hexadecimal string RRGGBB or RRGGBBAA
     * @param hex
     * @return CommonColor
     */
    static CommonColor FromHex( const string hex );
    static CommonColor FromHex( const string *hex );
};
}  // namespace Argo::Utilities
