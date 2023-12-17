#include "CommonColor.hpp"

namespace Argo::Types {
string CommonColor::decimalToHex( int decimal ) {
    int remainder{ 0 };
    int product{ 1 };
    string hex;

    while ( decimal != 0 ) {
        remainder = decimal % 16;
        char ch = 0;

        if ( remainder >= 10 ) {
            ch = remainder + 55;
        } else {
            ch = remainder + 48;
        }

        hex += ch;

        decimal = decimal / 16;
        product *= 10;
    }

    ranges::reverse( hex );

    return hex;
}
}  // namespace Argo::Types
