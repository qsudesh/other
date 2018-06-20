
/*

    http://www.drdobbs.com/cpp/counting-objects-in-c/184403484


    class ABCD { ... }; // ABCD = "A Big Complex Datatype"
    ABCD *p = new ABCD; // a new expression

    The new expression — whose meaning is built into the language and whose behavior you cannot change — does two things.
    First, it calls a memory allocation function called operator new. That function is responsible for finding enough memory to hold an ABCD object.
    If the call to operator new succeeds, the new expression then invokes an ABCD constructor on the memory that operator new found.

*/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Counter
{
    static int objectCreated;
    static int objectAlive;

    Counter(){
        ++objectCreated;
        ++objectAlive;
    }

    ~Counter(){
        --objectAlive;
    }
};

template<typename T> int Counter<T>::objectAlive(0);
template<typename T> int Counter<T>::objectCreated(0);


class X:Counter<X>
{

};


class Y:Counter<Y>
{

};


int main02(void)
{
    X x1;
    X x2;
    X x3;

    {
        X x4;
        Y y1;
    }

    Y y2;

    cout << Counter<X>::objectAlive << endl;
    cout << Counter<X>::objectCreated << endl;
    cout << Counter<Y>::objectAlive << endl;
    cout << Counter<Y>::objectCreated << endl;

    return 0;
}
