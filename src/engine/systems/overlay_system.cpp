//
// Created by simone on 03/12/25.
//

#include "overlay_system.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_allegro5.h"
#include "imgui/imgui_internal.h"
#include "../overlay/window_factory.hpp"

OverlaySystem::OverlaySystem(entt::registry* registry, const Display* display) : System(registry) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplAllegro5_Init(display->get_display());
    ImGui_ImplAllegro5_NewFrame();

    windows_.push_back(WindowFactory::create_fps_window(registry));
}

void OverlaySystem::update(int elapsed) {
    ImGui::NewFrame();
    for (const auto &window: windows_) {
        window.render();
    }
    ImGui::Render();
}

void OverlaySystem::render() {
    ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
}
