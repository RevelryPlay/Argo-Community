#include "CommonColor.hpp"
#include <gtest/gtest.h>

TEST( CommonColor, ToVec4 ) {
    using namespace Argo::Types;

    CommonColor color;
    color.red = 0.1F;
    color.green = 0.2F;
    color.blue = 0.3F;
    color.alpha = 0.4F;

    Vec4 vec4 = color.ToVec4();

    EXPECT_EQ( vec4.w, 0.1F );
    EXPECT_EQ( vec4.x, 0.2F );
    EXPECT_EQ( vec4.y, 0.3F );
    EXPECT_EQ( vec4.z, 0.4F );
}

TEST( CommonColor, ToHex ) {
    using namespace Argo::Types;

    CommonColor color;
    color.red = 0.1F;
    color.green = 0.2F;
    color.blue = 0.3F;
    color.alpha = 0.4F;

    EXPECT_EQ( color.ToHex(), "19334C66" );
}

TEST( CommonColor, DecimalToHex ) {
    using namespace Argo::Types;

    EXPECT_EQ( CommonColor::decimalToHex( 1 ), "01" );
    EXPECT_EQ( CommonColor::decimalToHex( 2 ), "02" );
    EXPECT_EQ( CommonColor::decimalToHex( 3 ), "03" );
    EXPECT_EQ( CommonColor::decimalToHex( 4 ), "04" );
    EXPECT_EQ( CommonColor::decimalToHex( 5 ), "05" );
    EXPECT_EQ( CommonColor::decimalToHex( 6 ), "06" );
    EXPECT_EQ( CommonColor::decimalToHex( 7 ), "07" );
    EXPECT_EQ( CommonColor::decimalToHex( 8 ), "08" );
    EXPECT_EQ( CommonColor::decimalToHex( 9 ), "09" );
    EXPECT_EQ( CommonColor::decimalToHex( 10 ), "0A" );
    EXPECT_EQ( CommonColor::decimalToHex( 11 ), "0B" );
    EXPECT_EQ( CommonColor::decimalToHex( 12 ), "0C" );
    EXPECT_EQ( CommonColor::decimalToHex( 13 ), "0D" );
    EXPECT_EQ( CommonColor::decimalToHex( 14 ), "0E" );
    EXPECT_EQ( CommonColor::decimalToHex( 15 ), "0F" );
    EXPECT_EQ( CommonColor::decimalToHex( 16 ), "10" );
    EXPECT_EQ( CommonColor::decimalToHex( 17 ), "11" );
    EXPECT_EQ( CommonColor::decimalToHex( 18 ), "12" );
    EXPECT_EQ( CommonColor::decimalToHex( 19 ), "13" );
    EXPECT_EQ( CommonColor::decimalToHex( 20 ), "14" );
    EXPECT_EQ( CommonColor::decimalToHex( 21 ), "15" );
    EXPECT_EQ( CommonColor::decimalToHex( 22 ), "16" );
    EXPECT_EQ( CommonColor::decimalToHex( 23 ), "17" );
    EXPECT_EQ( CommonColor::decimalToHex( 24 ), "18" );
    EXPECT_EQ( CommonColor::decimalToHex( 25 ), "19" );

    EXPECT_EQ( CommonColor::decimalToHex( 50 ), "32" );
    EXPECT_EQ( CommonColor::decimalToHex( 100 ), "64" );
    EXPECT_EQ( CommonColor::decimalToHex( 150 ), "96" );
    EXPECT_EQ( CommonColor::decimalToHex( 200 ), "C8" );
    EXPECT_EQ( CommonColor::decimalToHex( 255 ), "FF" );
}
