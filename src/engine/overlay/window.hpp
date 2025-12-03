//
// Created by simone on 03/12/25.
//

#ifndef FARMANDCONQUER_WINDOW_HPP
#define FARMANDCONQUER_WINDOW_HPP
#include <functional>
#include <string>
#include "imgui/imgui.h"


class Window {
public:
    Window(std::string title);

    void set_flags(ImGuiWindowFlags flags);

    void set_content(const std::function<void()> &callback);

    void render() const;
private:
    ImGuiWindowFlags flags_;
    std::string title_;
    std::function<void()> content_callback_;
};


#endif //FARMANDCONQUER_WINDOW_HPP
