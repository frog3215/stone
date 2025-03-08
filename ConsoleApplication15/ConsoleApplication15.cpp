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

struct location_ {

    string name;
    string description;
    vector<items_> items;
    vector<int> portal;
    int gold;
};

location_ location[5];

struct player_ {

    int location = 0;
    vector<items_> items;
    int gold;
    bool life = true;

    void processLocation()
    {
        if (location == 1)
        {
            life = false;
        }
    }

};

player_ player;




int main() {

    items_names.push_back("key");
    items_names.push_back("hemlet");
    items_names.push_back("sword");

    location[0].name = "stone";
    location[0].description = "If you go to the left, you will find death!!!\n If you go front, you will be rich!!!\n If you go to the right, you will found sword.\n You can leave if you want\n";
    location[0].gold = 0;
    location[0].items.push_back(items_::key);
    location[0].items.push_back(items_::hemlet);
    location[0].portal.push_back(1);
    location[0].portal.push_back(2);
    location[0].portal.push_back(3);
    location[0].portal.push_back(4);
    
    location[1].name = "left";
    location[1].description = "Sorry, you died\n You cant go to the back\n";
    location[1].gold = 0;
    
    location[2].name = "front";
    location[2].description = " You found 10 gold\n";
    location[2].gold = 10;
    location[2].items.push_back(items_::hemlet);
    location[2].portal.push_back(0);

    location[3].name = "right";
    location[3].description = " You found sword \n";
    location[3].gold = 0;
    location[3].items.push_back(items_::sword);
    location[3].portal.push_back(0);

    location[4].name = "back";
    location[4].description = " Goodlack travler\n";
    location[4].gold = 0;
    location[4].portal.push_back(0);
    

    while (player.life)
    {
        auto cur_loc = location[player.location];
        cout << cur_loc.name << "\n" << cur_loc.description << "\n" << "gold: " << cur_loc.gold << "  \n" ;

        int sz = cur_loc.portal.size();
        for (int i = 0; i < sz; i++)
        {
            auto portal = cur_loc.portal[i];
            cout << "press " << i << " to go " << location[portal].name << "\n";
        }

        int az = cur_loc.items.size();
        cout << "items: \n";
        for (int i = 0; i < az; i++)
        {
            auto cur_loc_items = cur_loc.items[i];
            cout <<  items_names[(int)cur_loc_items] << "\n";
        }

        if (player.life)
        {
            int i;
            cin >> i;
            player.location = cur_loc.portal[i];


            player.processLocation();
        }

    }

}