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
    Position(int xPosition, int yPosition);
    void setCoordinates(int xPosition, int yPosition);
    int getX() const;
    int getY() const;
    void setX(int xPosition);
    void setY(int yPosition);
};


#endif //TREASURE_HUNTER_POSITION_H
