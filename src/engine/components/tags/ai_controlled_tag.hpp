//
// Created by simone on 13/03/26.
//

#ifndef ALMAQUIES_AI_CONTROLLED_TAG_HPP
#define ALMAQUIES_AI_CONTROLLED_TAG_HPP

#include <array>
#include "../../systems/collision/ray.hpp"
#include "../../../util/constants.hpp"

struct AIControlledTag {
    std::array<Ray, AI_RAY_COUNT> rays{};
};

#endif //ALMAQUIES_AI_CONTROLLED_TAG_HPP
