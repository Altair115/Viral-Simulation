// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "movement_strategy.h"

//Duration Of Status effect in ticks
constexpr int INCUBATION = 140; //10 ticks = 1 day for sim purposes
constexpr int IMMUNITY = 280;

namespace corsim {

/**
 * A subject is an entity within the simulation. It is modeled as a
 * circle in 2D and can be infected.
 */
    class Subject {
    public:
        Subject(int x, int y, int radius, bool infected, MovementStrategy *moveStrat) :
                moveStrat(moveStrat), _x(x), _y(y), _incubation(infected), _radius(radius) {};
        double x();
        double y();
        void set_x(double x);
        void set_y(double y);
        double dx(); //Speed on x axis
        double dy(); //Speed on y axis
        int radius(); //Radius needed for collisions
        void set_dx(double dx);
        void set_dy(double dy);
        bool infected();
        void infect();
        bool immune();
        double angle();
        double speed();
        void tick();
        MovementStrategy* moveStrat = new RegularMovementStrategy(0, 0);
    private:
        double _x = 0, _y = 0, _dx = 0, _dy = 0;
        int _incubation = INCUBATION;
        int _radius = 0;
        int _immune = 0;
    };
};