#pragma once

#include "../Common/Types/CommonColor.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace Argo::Utilities {
using namespace Argo::Types;

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
    static CommonColor FromRGBA( const Vec4 *rgba );

    /**
     * Creates a CommonColor from a hexadecimal number value with alpha
     * @param hex - 0xRRGGBBAA
     * @return CommonColor
     */
    static CommonColor FromHex( unsigned int hex );

    /**
     * Creates a CommonColor from a hexadecimal number value with alpha pointer
     * @param hex - 0xRRGGBBAA
     * @return CommonColor
     */
    static CommonColor FromHex( const unsigned int *hex );

    /**
     * Creates a CommonColor from a hexadecimal string RRGGBB or RRGGBBAA
     * @param hex - string
     * @return CommonColor
     */
    static CommonColor FromHex( const string &hex );
    static CommonColor FromHex( const string *hex );
};
}  // namespace Argo::Utilities
