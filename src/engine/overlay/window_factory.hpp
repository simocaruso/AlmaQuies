//
// Created by simone on 03/12/25.
//

#ifndef FARMANDCONQUER_WINDOW_FACTORY_HPP
#define FARMANDCONQUER_WINDOW_FACTORY_HPP
#include "window.hpp"
#include "entt/entt.hpp"


class WindowFactory {
public:
    static Window create_fps_window(entt::registry* registry);
};


#endif //FARMANDCONQUER_WINDOW_FACTORY_HPP
