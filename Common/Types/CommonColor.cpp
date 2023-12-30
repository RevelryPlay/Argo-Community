#include "CommonColor.hpp"

namespace Argo::Types {
string CommonColor::decimalToHex( int decimal ) {
    string hexString;
    int quotient = decimal;
    int remainder = 0;

    while ( quotient != 0 ) {
        remainder = quotient % 16;

        if ( remainder < 10 ) {
            hexString.insert( 0, 1, static_cast< char >( remainder + 48 ) );
        } else {
            hexString.insert( 0, 1, static_cast< char >( remainder + 55 ) );
        }

        quotient /= 16;
    }

    if ( hexString.length() == 1 ) {
        hexString.insert( 0, 1, '0' );
    }

    return hexString;
}

}  // namespace Argo::Types
