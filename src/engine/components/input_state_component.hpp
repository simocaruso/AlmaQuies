//
// Created by simone on 28/02/26.
//

#ifndef ALMAQUIES_INPUT_STATE_COMPONENT_HPP
#define ALMAQUIES_INPUT_STATE_COMPONENT_HPP

struct InputStateComponent {
    float mouse_x, mouse_y;
    bool left_click;

    Vec2 request_player_movement{0, 0};
    Vec2 request_camera_movement{0, 0};
    int request_camera_zoom = 0;
};

#endif //ALMAQUIES_INPUT_STATE_COMPONENT_HPP
