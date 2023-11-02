#include <cassert>
#include <iostream>
#include <array>
#include <string.h>

using namespace std;

enum Suit
{
    dots = 0,
    bamboo = 1,
    characters = 2,
    east = 3,
    south = 4,
    west = 5,
    north = 6,
    red = 7,
    green = 8,
    white = 9
};
enum Num
{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    NON = 10
};

class Tile
{
public:
    // EFFECTS init piece to dots-one
    Tile()
    {
        suit = dots;
        num = ONE;
        altered = false;
    }
    // EFFECTS init piece with suit and num
    Tile(Suit suit, Num num)
    {
        this->suit = suit;
        this->num = num;
        altered = false;
    }

    // EFFECTS Return Suit
    Suit get_suit() const
    {
        return suit;
    }

    // EFFECTS Return Num
    Num get_num() const
    {
        return num;
    }
    
    // EFFECTS Return altered
    bool get_altered() const
    {
        return altered;
    }

    void set_altered()
    {
        // could do !altered but could lead to many bugs
        altered = true;
    }
private:
    Suit suit;
    Num num; 
    bool altered; // if the card is still playable
};

/* EFFECTS
    return 1 if a is greater than b
    return 0 if a is equal to b
    return -1 if a is less than b
*/
int tile_comp(const Tile &a, const Tile &b)
{
    
    if (a.get_suit() == b.get_suit())
    {
        // same value (if it's NON it would indicate that it's a same face card)
        if (a.get_num() == b.get_num())
        {
            return 0;
        }
        
    }
    else
    {
        int dif = b.get_suit() - a.get_suit();
        return dif/abs(dif); // -1 or 1
    }
}