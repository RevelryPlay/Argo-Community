#include "ConsoleMenu.hpp"
#include "Runner.hpp"

using namespace Argo::System;

int main(int /*unused*/, char** /*unused*/) {
    Argo::Utilities::MainMenu main{"main", "Main Menu"};
    main.AddAction({
        "run", "Launch the Argo Test Project", []() {
            Argo::Runner runner{*new Argo::Runner()};
            runner.run();
        }
    });

    main.Init();
    return 0;
}
