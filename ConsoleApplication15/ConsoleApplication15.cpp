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
    string name_portal;
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

    int loc = 0;
    vector<items_> items;
    int gold;
    bool life = true;

   

    void processLocation()
    {
        if ( loc == 1)
        {
            life = false;
            cout << "Game over\n";
        }
        else if (loc == 5 && items.empty())
        {
            life = false;
            cout << "Game over\n";
        }
    }
   
    

};

player_ player;

struct enemy_
{
    int loc = 5;
    bool life = true;
};

enemy_ goblin;


void pickItemByName(string name_items)
{
    auto& cur_loc = location[player.loc];
    for (int i = 0; i < items_names.size(); i++)
    {
        if (items_names[i] == name_items)
        {
            for (int j = 0; j < cur_loc.items.size(); j++)
            {
                if (i == (int)cur_loc.items[j])
                {
                    player.items.push_back((items_)i);
                    cur_loc.items.erase(cur_loc.items.begin() + j);
                    return;
                }
            }
        }
    }

}
void InitGame()
{
    items_names.push_back("key");
    items_names.push_back("hemlet");
    items_names.push_back("sword");

    location[0].name = "stone";
    location[0].description = "If you go to the left, you will find death!!!\n If you go front, you will be rich!!!\n If you go to the right, you will found sword.\n You can leave if you want\n";
    location[0].gold = 0;
    location[0].items.push_back(items_::key);
    location[0].portal.push_back({ "left", 1, true});
    location[0].portal.push_back({ "front", 2, true});
    location[0].portal.push_back({ "right", 3, true});
    location[0].portal.push_back({ "back", 4, true});
    
    location[1].name = "left";
    location[1].description = "Sorry, you died\n You cant go to the back\n";
    location[1].gold = 0;
    
    location[2].name = "front";
    location[2].description = " You found 10 gold\n";
    location[2].gold = 10;
    location[2].items.push_back(items_::hemlet);    
    location[2].portal.push_back({ "stone", 0, true});

    location[3].name = "right";
    location[3].description = " You found sword \n";
    location[3].gold = 0;
    location[3].items.push_back(items_::sword);    
    location[3].portal.push_back({ "stone", 0, true});

    location[4].name = "back";
    location[4].description = " Goodlack travler\n";
    location[4].gold = 0;
    location[4].portal.push_back({"stone", 0, true});
    location[4].portal.push_back({ "secret", 5, false});

    location[5].name = "secret";
    location[5].description = " Goblin\n";
    location[5].gold = 100;
    location[5].portal.push_back({ "back", 4, true});

}
void Command()
{
    auto cur_loc = location[player.loc];
    cout << "help: List of commands\n";
        if (player.life)
        {
            bool validate_command = false;

            while (validate_command == false &&  player.life)
            { 
                string command;
                cin >> command;
                if (command == "help")
                {
                    if (player.loc == 4)
                    {
                        cout << "open: Open\n" << "protect: Protect yourself\n" << "attack: Attack\n";
                    }
                    else
                    {
                        cout << "info: Location information\n" << "go: Movement\n" << "seek: Search\n" << "pick: Pick up an item\n" << "gold: Pick up gold\n" << "List: View inventory\n";
                    }
                }
                if (command == "info")
                {
                    cout << cur_loc.name << "\n" << cur_loc.description << "\n" << "location gold: " << cur_loc.gold << "\n";
                }
                if (command == "go")
                {
                    int sz = cur_loc.portal.size();
                    for (int i = 0; i < sz; i++)
                    {
                        auto portal_target = cur_loc.portal[i];
                        cout << "press " << i << " to go " << location[player.loc].portal[i].name_portal << (location[player.loc].portal[i].isActive ? " (activ)": " (not activ)") << "\n";

                    }

                    validate_command = true;
                    bool validate = false;
                    while (validate == false)
                    {
                        int selected_way;
                        cin >> selected_way;

                        if (selected_way >= 0 && selected_way < cur_loc.portal.size() && location[player.loc].portal[selected_way].isActive)
                        {
                            player.loc = location[player.loc].portal[selected_way].target;
                            player.processLocation();
                            validate = true;
                        }
                        if (validate == false)
                        {
                            cout << "cold'nt go to this location, you back\n";
                            break;
                        }
                          
                    }

                }
                if (command == "pick")
                {
                    int az = cur_loc.items.size();
                    cout << "items: \n";
                    for (int i = 0; i < az; i++)
                    {
                        auto cur_loc_items = cur_loc.items[i];
                        cout << items_names[(int)cur_loc_items] << "\n";
                    }
                    string name_items;
                    cin >> name_items;
                    
                    pickItemByName(name_items);
                    validate_command = true;
                }
                if (command == "list")
                {
                    bool invent = false;
                    if (!player.items.empty())
                    {
                        invent = true;
                        cout << "player gold: " << player.gold << "\n";
                        for (int i = 0; i < player.items.size(); i++)
                        {
                            int item = (int)player.items[i];
                            cout << items_names[item] << "\n";
                        }
                    }
                    else if (!invent)
                    {
                        cout << "You havent items" << "\n" << "player gold: " << player.gold << "\n";
                    }
                    validate_command = true;
                    
                }
                if (command == "seek")
                {
                    for (int i = 0; i < cur_loc.items.size(); i++)
                    {
                        int item = (int)cur_loc.items[i];
                        cout << items_names[item] << "\n";
                    }
                    validate_command = true;
                }
                if (command == "gold")
                {
                    if (player.loc == 2 )
                    {
                        player.gold +=  location[2].gold;
                        location[2].gold = 0;
                        cout << "pick gold " << player.gold << "\n";
                    }
                    else if (player.loc == 5)
                    {
                        player.gold += location[5].gold;
                        location[5].gold = 0;
                        cout << "pick gold " << player.gold << "\n";
                    }
                    validate_command = true;
                }
                if (command == "open")
                {
                    if (player.loc == 4)
                    {
                        if (!player.items.empty())
                        {
                            bool temp = false;
                            for (int i = 0; i < player.items.size(); i++)
                            {
                                int item = (int)player.items[i];
                                if (item == (int)items_::key)
                                {
                                    temp = true;
                                    location[4].portal[1].isActive = true;
                                    cout << "Portal open\n";
                                    player.items.erase(player.items.begin() + i);
                                    return;
                                }
                            }
                            if (!temp)
                            {
                               cout << "You havent key\n";
                            }
                        }
                        else
                        {
                            cout << "You havent key\n";
                        }
                    }
                    else
                    {
                        cout << "you cant use this command in this location\n";
                    }
                }
                

            }

        }
}

void Protect()
{
    if (player.loc == 5 && goblin.life)
    {    
        bool validate_command = false;

        while (validate_command == false && player.life)
        {
            cout << "goblin attack you\n";
            string command;
            cin >> command;

            if (command == "protect")
            {
                if (!player.items.empty())
                {
                    bool tryp = false;
                    for (int i = 0; i < player.items.size(); i++)
                    {
                        int item = (int)player.items[i];
                        if (item == (int)items_::hemlet)
                        {
                            tryp = true;
                            player.items.erase(player.items.begin() + i);
                            return;
                        }
                    }
                    if (!tryp)
                    {
                        cout << "you died, you havent hemlet\n";
                        player.life = false;
                    }
                }
                validate_command = true;
            }
        }
    }
}
void Fight()
{
    if (player.loc == 5 && goblin.life)
    {
        bool validate_command = false;

        while (validate_command == false && player.life)
        {
            cout << "attack him\n";
            string command;
            cin >> command;
            if (command == "attack")
            {
                if (!player.items.empty())
                {
                    bool mod = false;
                    for (int i = 0; i < player.items.size(); i++)
                    {
                        int item = (int)player.items[i];
                        if (item == (int)items_::sword)
                        {
                            mod = true;
                            goblin.life = false;
                            cout << "Goblin death\n";
                            player.items.erase(player.items.begin() + i);
                            break;
                        }
                    }
                    if (!mod)
                    {
                        cout << "You havent sword, you died\n";
                        player.life = false;
                    }
                }
                else
                {
                    cout << "dolbaeb\n";
                }
                validate_command = true;
            }
            break;
        }
    }
}
void Win()
{
    if (goblin.life == false && player.life && player.loc == 5 && player.gold == 110)
    {
        cout << "You win\n";
        player.life = false;
    }
}

int main() {

    InitGame();
    

    while (player.life)
    {
        Command();
        Protect();
        Fight();
        Win();
      
    }

}