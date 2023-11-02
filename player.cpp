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
private:
    string name;
    vector<Tile> hand;
    
};