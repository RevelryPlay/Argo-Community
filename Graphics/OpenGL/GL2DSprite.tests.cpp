#include "GL2DSprite.hpp"
#include <gtest/gtest.h>

TEST( GL2DSprite, calculateRecVertices ) {
    Argo::Graphics::GL2DSprite sprite;
    sprite.width = 100;
    sprite.height = 100;

    const auto vertices = sprite.calculateRecVertices( 100, 100 );

    EXPECT_EQ( vertices[ 0 ].x, -1.0F );
    EXPECT_EQ( vertices[ 0 ].y, -1.0F );
    EXPECT_EQ( vertices[ 0 ].z, 0.0F );

    EXPECT_EQ( vertices[ 1 ].x, 1.0F );
    EXPECT_EQ( vertices[ 1 ].y, -1.0F );
    EXPECT_EQ( vertices[ 1 ].z, 0.0F );

    EXPECT_EQ( vertices[ 2 ].x, 1.0F );
    EXPECT_EQ( vertices[ 2 ].y, 1.0F );
    EXPECT_EQ( vertices[ 2 ].z, 0.0F );

    EXPECT_EQ( vertices[ 3 ].x, -1.0F );
    EXPECT_EQ( vertices[ 3 ].y, 1.0F );
    EXPECT_EQ( vertices[ 3 ].z, 0.0F );
}

TEST( GL2DSprite, calculateRecVerticesWithDifferentViewport ) {
    Argo::Graphics::GL2DSprite sprite;
    sprite.width = 100;
    sprite.height = 100;

    auto vertices = sprite.calculateRecVertices( 200, 200 );

    EXPECT_EQ( vertices[ 0 ].x, -0.5F );
    EXPECT_EQ( vertices[ 0 ].y, -0.5F );
    EXPECT_EQ( vertices[ 0 ].z, 0.0F );

    EXPECT_EQ( vertices[ 1 ].x, 0.5F );
    EXPECT_EQ( vertices[ 1 ].y, -0.5F );
    EXPECT_EQ( vertices[ 1 ].z, 0.0F );

    EXPECT_EQ( vertices[ 2 ].x, 0.5F );
    EXPECT_EQ( vertices[ 2 ].y, 0.5F );
    EXPECT_EQ( vertices[ 2 ].z, 0.0F );

    EXPECT_EQ( vertices[ 3 ].x, -0.5F );
    EXPECT_EQ( vertices[ 3 ].y, 0.5F );
    EXPECT_EQ( vertices[ 3 ].z, 0.0F );
}

TEST( GL2DSprite, calculateRecVerticesWithDifferentViewportAndDifferentSpriteSize ) {
    Argo::Graphics::GL2DSprite sprite;
    sprite.width = 50;
    sprite.height = 50;

    auto vertices = sprite.calculateRecVertices( 200, 200 );

    EXPECT_EQ( vertices[ 0 ].x, -0.25F );
    EXPECT_EQ( vertices[ 0 ].y, -0.25F );
    EXPECT_EQ( vertices[ 0 ].z, 0.0F );

    EXPECT_EQ( vertices[ 1 ].x, 0.25F );
    EXPECT_EQ( vertices[ 1 ].y, -0.25F );
    EXPECT_EQ( vertices[ 1 ].z, 0.0F );

    EXPECT_EQ( vertices[ 2 ].x, 0.25F );
    EXPECT_EQ( vertices[ 2 ].y, 0.25F );
    EXPECT_EQ( vertices[ 2 ].z, 0.0F );

    EXPECT_EQ( vertices[ 3 ].x, -0.25F );
    EXPECT_EQ( vertices[ 3 ].y, 0.25F );
    EXPECT_EQ( vertices[ 3 ].z, 0.0F );
}

TEST( GL2DSprite, calculateRecVerticesWithDifferentViewportAndDifferentSpriteSizeAndDifferentSpritePosition ) {
    Argo::Graphics::GL2DSprite sprite;
    sprite.width = 50;
    sprite.height = 50;
    sprite.xPos = 50;
    sprite.yPos = 50;

    auto vertices = sprite.calculateRecVertices( 200, 200 );

    EXPECT_EQ( vertices[ 0 ].x, -0.25F + 0.5F );
    EXPECT_EQ( vertices[ 0 ].y, -0.25F + 0.5F );
    EXPECT_EQ( vertices[ 0 ].z, 0.0F );

    EXPECT_EQ( vertices[ 1 ].x, 0.25F + 0.5F );
    EXPECT_EQ( vertices[ 1 ].y, -0.25F + 0.5F );
    EXPECT_EQ( vertices[ 1 ].z, 0.0F );

    EXPECT_EQ( vertices[ 2 ].x, 0.25F + 0.5F );
    EXPECT_EQ( vertices[ 2 ].y, 0.25F + 0.5F );
    EXPECT_EQ( vertices[ 2 ].z, 0.0F );

    EXPECT_EQ( vertices[ 3 ].x, -0.25F + 0.5F );
    EXPECT_EQ( vertices[ 3 ].y, 0.25F + 0.5F );
    EXPECT_EQ( vertices[ 3 ].z, 0.0F );
}


