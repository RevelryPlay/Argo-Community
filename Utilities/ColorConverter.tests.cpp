#include <gtest/gtest.h>

#include "../Common/Types/CommonColor.hpp"
#include "include/ColorConverter.hpp"

namespace Argo::Utilities {
  TEST(ColorConverter, ColorFromHexBlackPointer)
  {
    unsigned int inColor = 0x00000000;
    CommonColor color = ConvertColor().FromHex(&inColor);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 0.0f);
  }

  TEST(ColorConverter, ColorFromHexWhite)
  {
    CommonColor color = ConvertColor().FromHex(0xFFFFFFFF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromHexRed)
  {
    CommonColor color = ConvertColor().FromHex(0xFF0000FF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromHexGreen)
  {
    CommonColor color = ConvertColor().FromHex(0x00FF00FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromHexBlue)
  {
    CommonColor color = ConvertColor().FromHex(0x0000FFFF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromHexAlpha)
  {
    CommonColor color = ConvertColor().FromHex(0x000000FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromHexSoftBlue)
  {
    CommonColor color = ConvertColor().FromHex(0x1f7fbfc9);
    EXPECT_FLOAT_EQ(color.red, 0.12156863f);
    EXPECT_FLOAT_EQ(color.green, 0.49803922f);
    EXPECT_FLOAT_EQ(color.blue, 0.74901962f);
    EXPECT_FLOAT_EQ(color.alpha, 0.78823531f);
  }

  TEST(ColorConverter, ColorFromRGBABlack)
  {
    CommonColor color = ConvertColor().FromRGBA({ 0, 0, 0 });
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBAWhite)
  {
    CommonColor color = ConvertColor().FromRGBA({ 255, 255, 255 });
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBARed)
  {
    CommonColor color = ConvertColor().FromRGBA({ 255, 0, 0 });
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBAGreen)
  {
    CommonColor color = ConvertColor().FromRGBA({ 0, 255, 0 });
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBABlue)
  {
    CommonColor color = ConvertColor().FromRGBA({ 0, 0, 255 });
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBALimeGreen)
  {
    CommonColor color = ConvertColor().FromRGBA({ 133, 208, 79 });
    EXPECT_FLOAT_EQ(color.red, 0.52156866);
    EXPECT_FLOAT_EQ(color.green, 0.81568629);
    EXPECT_FLOAT_EQ(color.blue, 0.30980393);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
  }

  TEST(ColorConverter, ColorFromRGBAAlpha)
  {
    CommonColor color = ConvertColor().FromRGBA({ 51, 51, 51, 0.45 });
    EXPECT_FLOAT_EQ(color.red, 0.2);
    EXPECT_FLOAT_EQ(color.green, 0.2);
    EXPECT_FLOAT_EQ(color.blue, 0.2);
    EXPECT_FLOAT_EQ(color.alpha, 0.45f);
  }

  TEST(ColorConverter, Vec4FromCommonColor)
  {
    Vec4 color = ConvertColor().FromRGBA({ 133, 208, 79 }).ToVec4();
    EXPECT_FLOAT_EQ(color.x, 0.52156866);
    EXPECT_FLOAT_EQ(color.y, 0.81568629);
    EXPECT_FLOAT_EQ(color.z, 0.30980393);
    EXPECT_FLOAT_EQ(color.w, 1.0f);
  }
}// namespace Argo::Utilities
