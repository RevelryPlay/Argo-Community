#include <iostream>
#include <map>
#include <ranges>

#include "ConsoleMenu.hpp"

namespace Argo::Utilities {
    void Menu::Init(const std::string&menu_path) {
        const std::string full_path = menu_path + this->Name;
        std::string input;

        while (true) {
            std::cout << full_path + "> ";
            std::cin >> input;
            if (this->actions.contains(input)) {
                actions[input].Action();
            }
            else if (this->submenus.contains(input)) {
                submenus[input].Init(full_path + "/");
            }
            else if (input == "back") {
                return;
            }
            else if (input == "exit") {
                exit(0);
            }
            else if (input == "info") {
                std::string name;
                std::cin >> name;

                if (this->submenus.contains(name)) {
                    std::cout << this->submenus[name].Description << '\n';
                }
                else if (this->actions.contains(name)) {
                    std::cout << this->actions[name].Description << '\n';
                }
                else {
                    std::cout << "unrecognized name: " << name << '\n';
                }
            }
            else if (input == "help") {
                std::cout << "back: return to the previous menu\n";
                std::cout << " exit: exit the program\n";
                std::cout << " info <name>: get the description of a submenu or action\n";
                std::cout << " help: show this help message\n";
                std::cout << " ls: list the submenus and actions for the current menu\n";

                std::cout << '\n';

                if (!this->submenus.empty()) {
                    std::cout << "Submenus: ";
                    for (const auto&name: this->submenus | std::views::keys) {
                        std::cout << name << " ";
                    }
                    std::cout << '\n';
                }

                if (!this->actions.empty()) {
                    std::cout << " Actions: \n";
                    for (const auto&name: this->actions | std::views::keys) {
                        std::cout << " " << name << ": " << this->actions[name].Description << '\n';
                    }
                    std::cout << '\n';
                }
            }
            else if (input == "ls") {
                if (!this->submenus.empty()) {
                    std::cout << "Submenus: ";
                    for (const auto&name: this->submenus | std::views::keys) {
                        std::cout << name << " ";
                    }
                    std::cout << '\n';
                }

                if (!this->actions.empty()) {
                    std::cout << "Actions: \n";
                    for (const auto&name: this->actions | std::views::keys) {
                        std::cout << " " << name << ": " << this->actions[name].Description << '\n';
                    }
                    std::cout << '\n';
                }

                if (this->submenus.empty() && this->actions.empty()) {
                    std::cout << "This menu has no submenus or actions\n";
                }
            }
            else {
                std::cout << "unrecognized name: " << input << '\n';
            }
        }
    }
} // namespace Argo::Utilities
