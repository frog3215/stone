#include <iostream> 
using namespace std;
#include <string>
#include <vector>

enum class items_ {
    key,
    hemlet,
    sword
};

vector<string> items_names;

struct portal_
{
    int target;
    bool isActive = false;
};

struct location_ {

    string name;
    string description;
    vector<items_> items;
    vector<portal_> portal;
    int gold;
};

location_ location[6];


struct player_ {

    int location = 0;
    vector<items_> items;
    int gold;
    bool life = true;


};
 

int main() {


    portal_ a = { 9 , true };
    portal_ b = { 2, false };
    
    int i = 9;
    cin >> i;
    cout << a.target << a.isActive << endl;
    cout << b.target << b.isActive;

   vector<int> p;
   p.push_back(9);

    

}


