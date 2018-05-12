#include<iostream>
#include<string>
using namespace std;

// DEFINE YOUR TEST
#define TEST4

#ifdef TEST1
//        What single specific paricular uno ein one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"list.h"
int main() {
    
    
    List<int> l;
    
    l.addToRear(3);
    l.addToFront(-1);
    l.addToFront(9000);
    l.addToFront(2);
    l.printItems();
    l.addItem(1, 10);
    l.deleteRear();
    //    l.deleteItem(0);
    l.printItems();
    //    std::cout << l.getItem(1) << endl;
    
    return 0;
}

#elif defined(TEST2)
//        What single specific paricular uno ein one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"stack.h"
int main() {
    
    Stack<std::string> s;
    
    s.push("Harry");
    s.push("Ron");
    s.push("Hermione");
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    
    return 0;
}

#elif defined(TEST3) //Test the maze in lecture slides
//        What single specific paricular uno ein one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"
int main() {
    Game g("maze_lecture.txt", 4);
    g.play();
    return 0;
}
#elif defined(TEST4) //Test a custom maze.
//        What single specific paricular uno ein one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"
int main() {
    Game g("maze_stuck.txt", 0);
    g.play();
    return 0;
}
#elif defined(TEST5) //Test too many sharks
//        What single specific paricular uno ein one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"
int main() {
    Game g("maze.txt", 800);
    g.play();
    return 0;
}
#else
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
#endif
