#include "Application.hpp"
#include <gtest/gtest.h>

TEST( Application, Setup ) {
    auto *app = new Argo::System::Application();
    EXPECT_TRUE( app->Setup() );
}

// These tests are not yet well defined and need something to test against
// TEST( Application, Run ) {
//     auto *app = new Argo::System::Application();
//     app->Setup();
//     app->Run();
// }
//
// TEST( Application, Cleanup ) {
//     auto *app = new Argo::System::Application();
//     app->Setup();
//     app->Cleanup();
// }

TEST( Application, RegisterCallback ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->Cleanup();
}

TEST( Application, RunCallback ) {
    auto *app = new Argo::System::Application();
    bool callbackRan = false;

    app->Setup();
    app->RegisterCallback( "Test", [ &callbackRan ]( float /*deltaTime*/ ) { callbackRan = true; } );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RunCallback( "Test", 0.0F );
    EXPECT_TRUE( callbackRan );
    app->Cleanup();
}

TEST( Application, MultipleCallbacksWithSameTitle ) {
    auto *app = new Argo::System::Application();
    bool firstCallbackRan = false;
    bool secondCallbackRan = false;

    app->Setup();
    app->RegisterCallback( "Test", [ &firstCallbackRan ]( float /*deltaTime*/ ) { firstCallbackRan = true; } );
    app->RegisterCallback( "Test", [ &secondCallbackRan ]( float /*deltaTime*/ ) { secondCallbackRan = true; } );

    EXPECT_EQ( app->callbacks.size(), 1 );
    EXPECT_EQ( app->callbacks[ "Test" ].size(), 2 );

    app->RunCallback( "Test", 0.0F );
    EXPECT_TRUE( firstCallbackRan );
    EXPECT_TRUE( secondCallbackRan );

    app->Cleanup();
}

// TODO: This test is for not yet implemented functionality
// TEST( Application, RemoveCallback ) {
//     auto app = new Argo::System::Application();
//     app->Setup();
//     app->RegisterCallback( "Test", []( float deltaTime ) {} );
//     EXPECT_EQ( app->callbacks.size(), 1 );
//     app->RemoveCallback( "Test", []( float deltaTime ) {} );
//     EXPECT_EQ( app->callbacks.size(), 0 );
//     app->Cleanup();
// }

TEST( Application, RemoveAllCallbacks ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RemoveAllCallbacks();
    EXPECT_EQ( app->callbacks.size(), 0 );
    app->Cleanup();
}

TEST( Application, RemoveAllCallbacksWithTitle ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RemoveAllCallbacksWithTitle( "Test" );
    EXPECT_EQ( app->callbacks.size(), 0 );
    app->Cleanup();
}
