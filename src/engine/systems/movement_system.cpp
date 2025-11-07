//
// Created by simone on 07/11/25.
//

#include "movement_system.hpp"
#include "events/move_command_event.hpp"

MovementSystem::MovementSystem(entt::registry *registry, entt::dispatcher &dispatcher) : System(registry) {
    dispatcher.sink<MoveCommandEvent>().connect<&MovementSystem::on_move_command>(this);
}

void MovementSystem::on_move_command(const MoveCommandEvent &event) {
    printf("Request for movement \n");
}

void MovementSystem::update(int elapsed) {

}
