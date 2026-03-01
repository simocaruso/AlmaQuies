//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_RENDER_TARGET_HPP
#define ALMAQUIES_RENDER_TARGET_HPP


class RenderTarget {
public:
    virtual void begin() = 0;
    virtual void end() = 0;
};


#endif //ALMAQUIES_RENDER_TARGET_HPP
