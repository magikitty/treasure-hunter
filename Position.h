// Elina Widdowson
// Programming Languages 2

#ifndef TREASURE_HUNTER_POSITION_H
#define TREASURE_HUNTER_POSITION_H


class Position {
private:
    int xCoordinate;
    int yCoordinate;
public:
    Position();
    Position(int xCoordinate, int yCoordinate);
    void setCoordinates(int xCoordinate, int yCoordinate);
    int getX() const;
    int getY() const;
    void setX(int xCoordinate);
    void setY(int yCoordinate);
};


#endif //TREASURE_HUNTER_POSITION_H
