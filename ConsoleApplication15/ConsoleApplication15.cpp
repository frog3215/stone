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
    int target = 0;
    bool isActive = false;
};

struct location_ {

    string name;
    string description;
    vector<items_> items;
    vector<portal_> portal;
    int gold;
};



struct player_ {

    int loc = 0;
    vector<items_> items;
    int gold;
    bool life = true;


};
 
    
location_ location[3];
player_ player;

void InitGame()
{
    location[0].name = "stone"; 
    
    location[0].portal.push_back({ 2, true });
    location[0].portal.push_back({ 1, false });
    location[1].name = "front";
    location[1].portal.push_back({ 0, true });
    location[1].portal.push_back({ 2, true });
    location[2].name = "back";
    location[2].portal.push_back({ 0, true });
    location[2].portal.push_back({ 1, false });

    portal_ a { 0, true };
    portal_ b { 1, true };
    portal_ z { 2, false };
}

int main() {
    InitGame();
    setlocale(LC_ALL, "Russian");
    while (player.life)
    {
        auto i = player.loc;
        cout << location[player.loc].name << "\n";

        string command;
        cin >> command;

        if (command == "go")
        {

            for (int j = 0; j < location->portal.size(); j++)
            {
             cout << "Портал: " << j+1 << " ведет в локацию " << location[j+1].name << endl;
            }

            int selected_way;
            cin >> selected_way;

            if (selected_way == 1 )
            {
                player.loc = location[player.loc].portal[selected_way].target;
                cout << "Вы перешли в локацию " << location[player.loc].name << endl;
            }


        }
    }

    
    
    
    

    

}


