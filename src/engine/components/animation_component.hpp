//
// Created by simone on 04/12/25.
//

#ifndef FARMANDCONQUER_ANIMATION_COMPONENT_HPP
#define FARMANDCONQUER_ANIMATION_COMPONENT_HPP
#include <string>
#include <set>

struct Animation {
    std::string name;
    size_t num_frames;
    size_t frame_speed;
    std::set<std::string> animations;
};

struct AnimationComponent {
    size_t curr_frame;
    size_t curr_elapsed;
    Animation active;
    std::vector<Animation> animations;
};

#endif //FARMANDCONQUER_ANIMATION_COMPONENT_HPP
