#include <cassert>
#include <iostream>
#include <array>
#include <string.h>
#include <vector>
#include <Tile.cpp>
using namespace std;

class player
{
public:
    virtual const string &get_name() const = 0;
    virtual void add_piece(const Tile &c) = 0;
    virtual Tile peng(const Tile &c) = 0;

private:
};
class BotPlayer : public player
{
public:
    BotPlayer()
    {
        name = "_";
    }
    BotPlayer(string name)
    {
        this->name = name;
    }
    const string &get_name() const override
    {
        return name;
    }

private:
    string name;
};
class HumanPlayer : public player
{
public:
    HumanPlayer()
    {
        name = "_";
    }
    HumanPlayer(string name)
    {
        this->name = name;
    }
    const string &get_name() const override
    {
        return name;
    }
    Tile play_tile()
    {
    }
    // REQUIRES Tile 'a' is a valid Tile
    // EFFECTS Check if there are two copies of the same card in the player hand
    bool can_pong(Tile a)
    {
        return find_card_amt(a) == 2;
    }
    // REQUIRES Tile 'a' is a valid Tile
    // EFFECTS Check if there are three copies of the same card in the player hand
    bool can_kong(Tile a)
    {
        return find_card_amt(a) == 3;
    }
    //REQUIRES Tile 'a' is a valid Tile
    //EFFECTS 
    bool can_chow(Tile a)
    {
        if (a.get_num() == 1)
        {
            ;
        }
        
    }
    int find_card_amt(Tile a)
    {
        int count = 0;
        for (int b = 0; b < hand.size(); b++)
        {
            if (tile_comp(a, hand[b]) == 0)
            {
                count++;
            }
        }
        return count;
    }
    bool has_card(Tile a)
    {
        for (int b = 0; b < hand.size(); b++)
        {
            if (tile_comp(a, hand[b]) == 0)
            {
                return true;
            }
        }
    }

private:
    string name;
    vector<Tile> hand;
    void sort_hand()
    {
        for (int b = 0; b < hand.size(); b++)
        {
            for (int a = 0; a < hand.size() - 1; a++)
            {
                if (tile_comp(hand[a], hand[b]) < 0)
                {
                    Tile temp = hand[a];
                    hand[a] = hand[a + 1];
                    hand[a + 1] = temp;
                }
            }
        }
    }
};