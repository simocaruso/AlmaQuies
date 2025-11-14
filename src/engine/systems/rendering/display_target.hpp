//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_DISPLAY_TARGET_HPP
#define FARMANDCONQUER_DISPLAY_TARGET_HPP


#include "render_target.hpp"
#include "../../display.hpp"

class DisplayTarget : public RenderTarget {
public:
    explicit DisplayTarget(Display* display);

    void begin() const override;

    void end() const override;

private:
    Display* display_;
};


#endif //FARMANDCONQUER_DISPLAY_TARGET_HPP
