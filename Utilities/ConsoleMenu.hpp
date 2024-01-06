#pragma once

#include <map>
#include <string>
#include <utility>

namespace Argo::Utilities {
using MenuItem = struct {
    std::string Name;
    std::string Description;

    void ( *Action )();
};

class Menu {
  public:
    std::map< std::string, Menu > submenus;
    std::map< std::string, MenuItem > actions;

    Menu() = default;

    Menu( std::string name, std::string desc ) : Name( std::move( name ) ), Description( std::move( desc ) ) {}

    std::string Name;
    std::string Description;
    void AddMenu( Menu const &m ) { this->submenus[ m.Name ] = m; }
    void AddAction( MenuItem const &m ) { this->actions[ m.Name ] = m; }

    void GetActions();

    void Init( const std::string & );
};

class MainMenu : public Menu {
  public:
    using Menu::Menu;
    void Init() { this->Menu::Init( "" ); }
};
}  // namespace Argo::Utilities
