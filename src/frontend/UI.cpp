
#include "UI.hpp"

using namespace ftxui;

UI::UI() : 
    tab_values{"tab_1", "tab_2", "tab_3"},
    tab_selected(0),
    tab_1_entries{"Forest", "Water", "I don't know"},
    tab_2_entries{"Hello", "Hi", "Hay"},
    tab_3_entries{"Table", "Nothing", "Is", "Empty"},
    tab_1_selected(0),
    tab_2_selected(0),
    tab_3_selected(0) {}

void UI::run() {
    auto tab_menu = Menu(&tab_values, &tab_selected);

    auto tab_container = Container::Tab(
        {
            Radiobox(&tab_1_entries, &tab_1_selected),
            Radiobox(&tab_2_entries, &tab_2_selected),
            Radiobox(&tab_3_entries, &tab_3_selected),
        },
        &tab_selected);

    auto container = Container::Horizontal({
        tab_menu,
        tab_container,
    });

    auto renderer = Renderer(container, [&] {
        return hbox({
            tab_menu->Render(),
            separator(),
            tab_container->Render(),
        }) | border;
    });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);
}
