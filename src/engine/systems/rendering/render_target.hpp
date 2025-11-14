//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_RENDER_TARGET_HPP
#define FARMANDCONQUER_RENDER_TARGET_HPP


class RenderTarget {
public:
    virtual void begin() const = 0;
    virtual void end() const = 0;
};


#endif //FARMANDCONQUER_RENDER_TARGET_HPP
