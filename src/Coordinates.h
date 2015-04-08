//
// Created by dragongling on 4/7/15.
//

#ifndef GAME1_COORDINATES_H
#define GAME1_COORDINATES_H


class Coordinates {
public:
    int x, y;

    Coordinates();
    Coordinates(int x, int y);

    void operator*=(const double rvalue);
};


#endif //GAME1_COORDINATES_H
