//
// Created by dragongling on 4/7/15.
//

#include "Coordinates.h"

Coordinates::Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

Coordinates::Coordinates() {
    x = 0;
    y = 0;
}

void Coordinates::operator*=(const double rvalue) {
    x *= rvalue;
    y *= rvalue;
}
