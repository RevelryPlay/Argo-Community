#include "ColorConverter.hpp"

namespace Argo::Utilities {
auto const maxValue = 255.0F;

CommonColor ConvertColor::FromRGBA( Argo::Vec4 rgba ) { return ConvertColor::FromRGBA( &rgba ); }

CommonColor ConvertColor::FromRGBA( Argo::Vec4 *rgba ) {
    auto alpha = rgba->z != NULL ? rgba->z : 1.0F;
    CommonColor color = { rgba->w / maxValue, rgba->x / maxValue, rgba->y / maxValue, alpha };
    return color;
}

CommonColor ConvertColor::FromHex( unsigned int hex ) { return ConvertColor::FromHex( &hex ); }

CommonColor ConvertColor::FromHex( const unsigned int *hex ) {
    CommonColor rgba = CommonColor();

    rgba.red = ( ( *hex >> 24 ) & 0xFF ) / maxValue;
    rgba.green = ( ( *hex >> 16 ) & 0xFF ) / maxValue;
    rgba.blue = ( ( *hex >> 8 ) & 0xFF ) / maxValue;
    rgba.alpha = ( ( *hex ) & 0xFF ) / maxValue;

    return rgba;
}

CommonColor ConvertColor::FromHex( const std::string hex ) { return FromHex( &hex ); }

CommonColor ConvertColor::FromHex( const std::string *hex ) {
    if ( hex->length() != 6 && hex->length() != 8 ) {
        std::cout << "Invalid hexadecimal color. Please use the 6 or 8 digit format, e.g. FF0000 or FF0000FF" << '\n';
    }

    Vec4 rgba = Vec4();
    rgba.z = 1.0F;

    rgba.w = stoi( hex->substr( 0, 2 ), nullptr, 16 );
    rgba.x = stoi( hex->substr( 2, 2 ), nullptr, 16 );
    rgba.y = stoi( hex->substr( 4, 2 ), nullptr, 16 );

    // RGBA Hex
    if ( hex->length() == 8 ) {
        rgba.z = stoi( hex->substr( 6, 2 ), nullptr, 16 ) / maxValue;
    }

    return FromRGBA( &rgba );
}
}  // namespace Argo::Utilities
