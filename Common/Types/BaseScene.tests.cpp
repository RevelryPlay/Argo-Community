#include "BaseScene.hpp"
#include <gtest/gtest.h>

TEST( BaseScene, DefaultConstructor ) {
    Argo::Types::BaseScene scene;
    EXPECT_EQ( scene.GetWidth(), 0 );
    EXPECT_EQ( scene.GetHeight(), 0 );
}

TEST( BaseScene, Constructor ) {
    Argo::Types::BaseScene scene( 100, 200 );
    EXPECT_EQ( scene.GetWidth(), 100 );
    EXPECT_EQ( scene.GetHeight(), 200 );
}

TEST( BaseScene, SetWidth ) {
    Argo::Types::BaseScene scene;
    scene.SetWidth( 100 );
    EXPECT_EQ( scene.GetWidth(), 100 );
}

TEST( BaseScene, SetHeight ) {
    Argo::Types::BaseScene scene;
    scene.SetHeight( 200 );
    EXPECT_EQ( scene.GetHeight(), 200 );
}
