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

#include "subject.h"
#include <math.h>

namespace corsim {

    double Subject::x() {
        return this->moveStrat->x();
    }

    double Subject::y() {
        return this->moveStrat->y();
    }

    void Subject::set_x(double x) {
        this->moveStrat->set_x(x);
    }

    void Subject::set_y(double y) {
        this->moveStrat->set_y(y);
    }

    double Subject::dx() {
        return this->moveStrat->dx();
    }

    double Subject::dy() {
        return this->moveStrat->dy();
    }

    void Subject::set_dx(double dx) {
        this->moveStrat->set_dx(dx);
    }

    void Subject::set_dy(double dy) {
        this->moveStrat->set_dy(dy);
    }

    int Subject::radius() {
        return this->_radius;
    }

    bool Subject::infected() {
        return this->_incubation > 0;
    }

    void Subject::infect() {
        if(!_immune)
            this->_incubation = INCUBATION;
    }

    bool Subject::immune() {
        return this->_immune > 0;
    }

    double Subject::angle() {
        return atan2(dy(), dx());
    }

    double Subject::speed() {
        return sqrt(dx() * dx() + dy() * dy());
    }

    void Subject::tick(){
        if(_incubation > 1)
            --_incubation;
        if(_immune > 0)
            --_immune;
        if(_incubation == 1){
            --_incubation;
            _immune = IMMUNITY;
        }
    }
}