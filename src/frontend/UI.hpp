
#pragma once
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

class UI {
public:
    UI();
    void run();

private:
    std::vector<std::string> tab_values;
    int tab_selected;
    std::vector<std::string> tab_1_entries;
    std::vector<std::string> tab_2_entries;
    std::vector<std::string> tab_3_entries;
    int tab_1_selected;
    int tab_2_selected;
    int tab_3_selected;
};

