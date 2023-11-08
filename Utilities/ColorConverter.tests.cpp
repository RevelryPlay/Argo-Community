#include "ColorConverter.hpp"
#include <gtest/gtest.h>

TEST( ColorConverter, ColorFromHexBlackPointer ) {
    unsigned int const inColor = 0x00000000;
    auto color = Argo::Utilities::ConvertColor::FromHex( &inColor );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 0.0F );
}

TEST( ColorConverter, ColorFromHexWhite ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0xFFFFFFFF );
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexRed ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0xFF0000FF );
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexGreen ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0x00FF00FF );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexBlue ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0x0000FFFF );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexAlpha ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0x000000FF );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexSoftBlue ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( 0x1f7fbfc9 );
    EXPECT_FLOAT_EQ( color.red, 0.12156863f );
    EXPECT_FLOAT_EQ( color.green, 0.49803922f );
    EXPECT_FLOAT_EQ( color.blue, 0.74901962f );
    EXPECT_FLOAT_EQ( color.alpha, 0.78823531f );
}

TEST( ColorConverter, ColorFromHexString6White ) {
    auto color = Argo::Utilities::ConvertColor::FromHex("FFFFFF");
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexString6Black ) {
    auto color = Argo::Utilities::ConvertColor::FromHex("000000");
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexString8White ) {
    auto color = Argo::Utilities::ConvertColor::FromHex("FFFFFFFF");
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromHexString8Black ) {
    auto color = Argo::Utilities::ConvertColor::FromHex("00000000");
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 0.0F );
}

TEST( ColorConverter, ColorFromHexStringSoftBlue ) {
    auto color = Argo::Utilities::ConvertColor::FromHex( "1f7fbfc9" );
    EXPECT_FLOAT_EQ( color.red, 0.12156863F );
    EXPECT_FLOAT_EQ( color.green, 0.49803922F );
    EXPECT_FLOAT_EQ( color.blue, 0.74901962F );
    EXPECT_FLOAT_EQ( color.alpha, 0.78823531F );
}

TEST( ColorConverter, ColorFromRGBABlack ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 0, 0, 0 } );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBAWhite ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 255, 255, 255 } );
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBARed ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 255, 0, 0 } );
    EXPECT_FLOAT_EQ( color.red, 1.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBAGreen ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 0, 255, 0 } );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 1.0F );
    EXPECT_FLOAT_EQ( color.blue, 0.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBABlue ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 0, 0, 255 } );
    EXPECT_FLOAT_EQ( color.red, 0.0F );
    EXPECT_FLOAT_EQ( color.green, 0.0F );
    EXPECT_FLOAT_EQ( color.blue, 1.0F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBALimeGreen ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 133, 208, 79 } );
    EXPECT_FLOAT_EQ( color.red, 0.52156866F );
    EXPECT_FLOAT_EQ( color.green, 0.81568629F );
    EXPECT_FLOAT_EQ( color.blue, 0.30980393F );
    EXPECT_FLOAT_EQ( color.alpha, 1.0F );
}

TEST( ColorConverter, ColorFromRGBAAlpha ) {
    auto color = Argo::Utilities::ConvertColor::FromRGBA( { 51, 51, 51, 0.45 } );
    EXPECT_FLOAT_EQ( color.red, 0.2F );
    EXPECT_FLOAT_EQ( color.green, 0.2F );
    EXPECT_FLOAT_EQ( color.blue, 0.2F );
    EXPECT_FLOAT_EQ( color.alpha, 0.45F );
}

TEST( ColorConverter, Vec4FromCommonColor ) {
    Argo::Types::Vec4 const color = Argo::Utilities::ConvertColor::FromRGBA( { 133, 208, 79 } ).ToVec4();
    EXPECT_FLOAT_EQ( color.w, 0.52156866F );
    EXPECT_FLOAT_EQ( color.x, 0.81568629F );
    EXPECT_FLOAT_EQ( color.y, 0.30980393F );
    EXPECT_FLOAT_EQ( color.z, 1.0F );
}
