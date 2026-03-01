//
// Created by simone on 03/12/25.
//

#ifndef ALMAQUIES_WINDOW_FACTORY_HPP
#define ALMAQUIES_WINDOW_FACTORY_HPP
#include "window.hpp"
#include "entt/entt.hpp"


class WindowFactory {
public:
    static Window create_fps_window(entt::registry* registry);
};


#endif //ALMAQUIES_WINDOW_FACTORY_HPP
