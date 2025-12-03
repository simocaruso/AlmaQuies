//
// Created by simone on 03/12/25.
//

#include "window.hpp"

Window::Window(std::string title) : flags_(0), title_(std::move(title)) {
}

void Window::set_flags(const ImGuiWindowFlags flags) {
    flags_ = flags;
}

void Window::set_content(const std::function<void()> &callback) {
    content_callback_ = callback;
}

void Window::render() const {
    ImGui::Begin(title_.c_str(), nullptr, flags_);
    content_callback_();
    ImGui::End();
}
