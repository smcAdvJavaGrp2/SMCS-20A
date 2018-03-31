//
//  Hotel.cpp
//  Worksheet1
//
//  Created by Nashir Janmohamed on 2/26/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
#include "Hotel.h"
using namespace std;


Hotel::Hotel(){
    for (int i = 0; i < FLOORS; i++)
        for (int j = 0; j < ROOMSPERFLOOR; j++)
            m_rooms[i][j] = EMPTY;
}

bool Hotel::reserve(int roomNum){
    //If the room is EMPTY, set it to RESERVED, and return true
    //In all other cases, do not change anything and return false
    setRoomNum(roomNum);
    if (isValidNum() && (isEmpty(m_rooms[m_floor][m_room]))){
        m_rooms[m_floor][m_room] = RESERVED;
        return true;
    }
    else
        return false;
}

bool Hotel::cancel(int roomNum){
    //If the room is RESERVED, set it to EMPTY, and return true
    //In all other cases, do not change anything and return false
    setRoomNum(roomNum);
    if (isValidNum() && (isReserved(m_rooms[m_floor][m_room]))){
        m_rooms[m_floor][m_room] = EMPTY;
        return true;
    }
    else
        return false;
}

bool Hotel::checkIn(int roomNum){
    //If the room is RESERVED, set it to OCCUPIED, and return true
    //In all other cases, do not change anything and return false
    setRoomNum(roomNum);
    if (isValidNum() && (isReserved(m_rooms[m_floor][m_room]))){
        m_rooms[m_floor][m_room] = OCCUPIED;
        return true;
    }
    else
        return false;
}

bool Hotel::checkOut(int roomNum){
    //If the room is OCCUPIED, set it to EMPTY, and return true
    //In all other cases, do not change anything and return false
    setRoomNum(roomNum);
    if (isValidNum() && (isOccupied(m_rooms[m_floor][m_room]))){
        m_rooms[m_floor][m_room] = EMPTY;
        return true;
    }
    else
        return false;
}

int Hotel::numEmpty(int floor) const{
    //Return the number of empty rooms on the floor
    //Return -1 if floor is invalid
    int emptyRooms = 0;
    if (floor >= 20 || floor < 0)
        return -1;
    else{
        for (int i = 0; i < ROOMSPERFLOOR; i++){
            if (isEmpty(m_rooms[floor][i]))
                emptyRooms++;
        }
        return emptyRooms;
    }
}

void Hotel::setRoomNum(int roomNum){
    //Set member variables for manipulating m_rooms[][]
    m_floor = roomNum/100;
    m_room = roomNum%100;
}

bool Hotel::isEmpty(char room) const{
    //Check if room is EMPTY
    if (room == EMPTY)
        return true;
    else
        return false;
}

bool Hotel::isReserved(char room){
    //Check if room is RESERVED
    if (room == RESERVED)
        return true;
    else
        return false;
}

bool Hotel::isOccupied(char room){
    //Check if room is OCCUPIED
    if (room == OCCUPIED)
        return true;
    else
        return false;
}

bool Hotel::isValidNum(void){
    //Check if m_floor and m_room are valid
    if ((m_floor < 0) || (m_floor > 19) || (m_room < 0) || (m_room > ROOMSPERFLOOR))
        return false;
    else
        return true;
}


