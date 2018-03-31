//
//  main.cpp
//  Quiz1
//
//  Created by Nashir Janmohamed on 3/10/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
using namespace std;

class CountingPiggy {
public:
    CountingPiggy();
    void addDollar();
    void addQuarter();
    void addDime();
    void addNickel();
    void addPenny();
    void giveMeBills();
private:
    int m_cents;
};

CountingPiggy::CountingPiggy(){ m_cents = 0; }
void CountingPiggy::addDollar(){ m_cents += 100; }
void CountingPiggy::addQuarter(){ m_cents += 25; }
void CountingPiggy::addDime(){ m_cents += 10; }
void CountingPiggy::addNickel(){ m_cents += 5; }
void CountingPiggy::addPenny(){ m_cents += 1; }
void CountingPiggy::giveMeBills(){
    int cents = m_cents;
    int dollars = cents/100;
    cents %= 100;
    int quarters = cents/25;
    cents %= 25;
    int dimes = cents/10;
    cents %= 10;
    int nickels = cents/5;
    cents %= 5;
    cout << dollars << " dollar bill(s)\n";
    cout << quarters << " quarter(s)\n";
    cout << dimes << " dime(s)\n";
    cout << nickels << " nickel(s)\n";
    cout << cents << " penny(ies)" << endl;
}

int main(){
    CountingPiggy c;
    c.addDollar();
    c.addDollar();
    c.addDollar();
    c.addDollar();
    c.addQuarter();
    c.addQuarter();
    c.addDime();
    c.addNickel();
    c.addPenny();
    c.giveMeBills();
    /*
    int arr[3] = { 5, 10, 15 };
    int* ptr = arr;
    *ptr = 10; // set arr[0] to 10
    *(ptr + 1) = 20; // set arr[1] to 20
    ptr += 2;
    ptr[0] = 30; // set arr[2] to 30
    ptr++;
    
    while (ptr > arr) {
        ptr--;
        cout << ' ' << *ptr; // print values
    }
    cout << endl;
     */
}
