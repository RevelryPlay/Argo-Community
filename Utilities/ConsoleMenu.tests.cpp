#include "ConsoleMenu.hpp"
#include <gtest/gtest.h>

using namespace Argo::Utilities;

TEST( ConsoleMenu, AddAction ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    menu->AddAction( { "Test", "Test Action", []() {} } );
    EXPECT_EQ( menu->actions.size(), 1 );
}

TEST( ConsoleMenu, AddMenu ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    menu->AddMenu( *subMenu );
    EXPECT_EQ( menu->submenus.size(), 1 );
}

TEST( ConsoleMenu, AddMenuWithAction ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    menu->AddMenu( *subMenu );

    menu->AddAction( { "Test", "Test Action", []() {} } );
    EXPECT_EQ( menu->submenus.size(), 1 );
    EXPECT_EQ( menu->actions.size(), 1 );
}

TEST( ConsoleMenu, AddMenuWithMenu ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    menu->AddMenu( *subMenu );

    auto *subMenu2 = new Menu( "Sub Test 2", "Test Sub Menu" );
    menu->AddMenu( *subMenu2 );

    EXPECT_EQ( menu->submenus.size(), 2 );
}

TEST( ConsoleMenu, AddMenuWithMenuAndAction ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    menu->AddMenu( *subMenu );

    auto *subMenu2 = new Menu( "Sub Test 2", "Test Sub Menu" );
    menu->AddMenu( *subMenu2 );

    menu->AddAction( { "Test", "Test Action", []() {} } );
    EXPECT_EQ( menu->submenus.size(), 2 );
    EXPECT_EQ( menu->actions.size(), 1 );
}

TEST( ConsoleMenu, AddMenuWithMenuAndActionAndMenu ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    menu->AddMenu( *subMenu );
    auto *subMenu2 = new Menu( "Sub Test 2", "Test Sub Menu" );
    menu->AddMenu( *subMenu2 );

    menu->AddAction( { "Test", "Test Action", []() {} } );

    auto *subMenu3 = new Menu( "Sub Test 3", "Test Sub Menu" );
    menu->AddMenu( *subMenu3 );

    EXPECT_EQ( menu->submenus.size(), 3 );
    EXPECT_EQ( menu->actions.size(), 1 );
}

TEST( ConsoleMenu, AddMenuWithSubMenuThatHasActions ) {
    auto *menu = new MainMenu( "Test", "Test Menu" );
    auto *subMenu = new Menu( "Sub Test", "Test Sub Menu" );
    subMenu->AddAction( { "Test", "Test Action", []() {} } );
    menu->AddMenu( *subMenu );

    auto *subMenu2 = new Menu( "Sub Test 2", "Test Sub Menu" );
    menu->AddMenu( *subMenu2 );

    EXPECT_EQ( menu->submenus.size(), 2 );
    EXPECT_EQ( menu->actions.size(), 0 );
    EXPECT_EQ( subMenu->actions.size(), 1 );
}
