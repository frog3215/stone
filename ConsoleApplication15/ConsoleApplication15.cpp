#include <iostream> 
using namespace std;

int main() {
    int z; int a = 1; int a1 = 2; int a2 = 3; int a3 = 4; int a4 = 5; {
        cout << "Press 1 to start\n";
    }
    while (z = a) {
        {
            cin >> z;
        }
        if (z == a) {
            cout << "If you go to the left, you will find death!!! (Press 2 to go the left)\n"
                << " If you go front, you will be rich!!! (Press 3 to go the front)\n"
                << " If you go to the right, you will lose your horse. (Press 4 to go the right)\n"
                << "You can leave if you want (Press 5)\n";
        }
        else if (z == a1) {
            cout << "Sorry, you died\n" << " You cant go to the back\n"; break;
        }
        else if (z == a4) {
            cout << "Good luck traveler\n" << " You cant go to the back\n"; break;
        }
        else if (z == a2) {
            cout << "Congratulations, you are now rich\n" << " You can go to the back (press 1)\n";
        }
        else if (z == a3) {
            cout << "Sorry, you lost your horse\n" << " You can go to the back (press 1)\n";
        }

    }

}