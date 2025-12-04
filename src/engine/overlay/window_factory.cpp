//
// Created by simone on 03/12/25.
//

#include "window_factory.hpp"

#include "../systems/fps_system.hpp"
#include "entt/entt.hpp"

Window WindowFactory::create_fps_window(entt::registry *registry) {
    Window w("FPS");
    w.set_flags(ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar
                | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    w.set_content([registry] {
        ImGui::SetWindowPos(ImVec2(0,0));
        ImGui::SetWindowFontScale(1.5f);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 1));
        ImGui::TextWrapped("FPS %lu", registry->ctx().get<Fps>().value);
        ImGui::PopStyleColor();
    });
    return w;
}
