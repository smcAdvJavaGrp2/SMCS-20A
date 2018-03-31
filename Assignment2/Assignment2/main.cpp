//
//  main.cpp
//  Worksheet1
//
//  Created by Nashir Janmohamed on 2/26/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
#include "Hotel.h"
using namespace std;

int main() {
    Hotel my_hotel;
    cout << "Hi here's my hotel!" << endl;
    
    if (my_hotel.reserve(400))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    if (my_hotel.reserve(401))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    if (my_hotel.reserve(1900))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    if (my_hotel.cancel(500))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    cout << my_hotel.numEmpty(4) << endl;
    if (my_hotel.checkIn(401))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    if (my_hotel.cancel(1900))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    if (my_hotel.checkOut(401))
        cout << "Success!" << endl;
    else
        cout << "Sorry, that didn't work..." << endl;
    return 0;
}
