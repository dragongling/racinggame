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
    Coordinates(const Coordinates &rvalue);

    Coordinates operator*(const Coordinates rvalue);

    Coordinates operator-(const Coordinates rvalue);
    void operator*=(const double rvalue);
    void operator+=(const Coordinates rvalue);
};


#endif //GAME1_COORDINATES_H
