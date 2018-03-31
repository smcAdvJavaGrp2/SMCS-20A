//
//  Hotel.h
//  Worksheet1
//
//  Created by Nashir Janmohamed on 2/26/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>

const char RESERVED = 'R';
const char OCCUPIED = 'O';
const char EMPTY = 'E';
const int FLOORS = 20;
const int ROOMSPERFLOOR = 50;

class Hotel{
public:
    Hotel();
    bool reserve(int roomNum);
    bool cancel(int roomNum);
    bool checkIn(int roomNum);
    bool checkOut(int roomNum);
    int numEmpty(int floor) const;
private:
    char m_rooms[FLOORS][ROOMSPERFLOOR];
    int m_floor, m_room;
    void setRoomNum(int roomNum);
    bool isEmpty(char room) const;
    bool isReserved(char room);
    bool isOccupied(char room);
    bool isValidNum(void);
};

#endif /* HOTEL_H */

