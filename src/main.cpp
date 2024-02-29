#include "ConsoleMenu.hpp"
#include "Runner.hpp"

#include "ArgoConfig.h"

// #include <libTesting/helloWorld.h>
#include <exception>
#include <iostream>

using namespace Argo::System;

int main(int /*unused*/, char** /*unused*/) {
    try {
        cout << "Welcome to " << PROJECT_NAME << '\n';
        cout << PROJECT_DESCRIPTION << '\n';
        cout << "Version " << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << "."
                << PROJECT_VERSION_PATCH << '\n';
        cout << '\n';
        cout << "Project Homepage " << PROJECT_URL << '\n';
        cout << "For help getting started please see the " << PROJECT_NAME <<
                " documentation at https://docs.revelryplay.com/argo" << '\n';
        cout << '\n';
        cout << "To see a list of available commands type `help`" << '\n';
        cout << '\n';

        Argo::Utilities::MainMenu main{"main", "Main Menu"};

        main.AddAction({
            "run", "Launch the Argo Test Project", []() {
                Argo::Runner runner{*new Argo::Runner()};
                runner.run();
            }
        });
        //
        // main.AddAction( {
        // "lib", "Testing loading a lib file built from another project", [] {
        //     hello();
        // }});

        main.Init();
    } catch (const std::exception& e) {
        std::cerr << "Error initializing ConsoleMenu: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
