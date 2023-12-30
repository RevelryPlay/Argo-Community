#include "Application.hpp"
#include <gtest/gtest.h>

TEST( Application, ApplicationSetup ) {
    auto *app = new Argo::System::Application();
    EXPECT_TRUE( app->Setup() );
}

// These tests are not yet well defined and need something to test against
// TEST( Application, ApplicationRun ) {
//     auto *app = new Argo::System::Application();
//     app->Setup();
//     app->Run();
// }
//
// TEST( Application, ApplicationCleanup ) {
//     auto *app = new Argo::System::Application();
//     app->Setup();
//     app->Cleanup();
// }

TEST( Application, ApplicationRegisterCallback ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->Cleanup();
}

TEST( Application, ApplicationRunCallback ) {
    auto *app = new Argo::System::Application();
    bool callbackRan = false;

    app->Setup();
    app->RegisterCallback( "Test", [ &callbackRan ]( float /*deltaTime*/ ) { callbackRan = true; } );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RunCallback( "Test", 0.0F );
    EXPECT_TRUE( callbackRan );
    app->Cleanup();
}

TEST( Application, ApplicationMultipleCallbacksWithSameTitle ) {
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
// TEST( Application, ApplicationRemoveCallback ) {
//     auto app = new Argo::System::Application();
//     app->Setup();
//     app->RegisterCallback( "Test", []( float deltaTime ) {} );
//     EXPECT_EQ( app->callbacks.size(), 1 );
//     app->RemoveCallback( "Test", []( float deltaTime ) {} );
//     EXPECT_EQ( app->callbacks.size(), 0 );
//     app->Cleanup();
// }

TEST( Application, ApplicationRemoveAllCallbacks ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RemoveAllCallbacks();
    EXPECT_EQ( app->callbacks.size(), 0 );
    app->Cleanup();
}

TEST( Application, ApplicationRemoveAllCallbacksWithTitle ) {
    auto *app = new Argo::System::Application();
    app->Setup();
    app->RegisterCallback( "Test", []( float deltaTime ) {} );
    EXPECT_EQ( app->callbacks.size(), 1 );
    app->RemoveAllCallbacksWithTitle( "Test" );
    EXPECT_EQ( app->callbacks.size(), 0 );
    app->Cleanup();
}
