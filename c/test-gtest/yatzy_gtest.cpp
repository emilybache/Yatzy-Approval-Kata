#include <gtest/gtest.h>
#include "ApprovalTests.hpp"

extern "C"
{
#include "yatzy1.h"
}

using namespace std;

string printRoll(const Roll* roll) {
    stringstream ss = stringstream();
    ss << "Roll [";

    bool first = true;
    for (int i = 0; i < 5; ++i) {
        if (first)
            first = false;
        else
            ss << ", ";
        ss << roll->dice[i];
    }

    ss << "]";
    return ss.str();
}

TEST(Yatzy, YatzyCategories)
{

    int totalRolls = 6;
    int rolls[][5] = {
            {2, 3, 4, 5, 1},
            {4, 3, 4, 5, 1},
            {3, 3, 3, 3, 3},
            {2, 2, 1, 1, 1},
            {2, 6, 5, 6, 5},
            {2, 6, 5, 3, 4},

    };
    stringstream ss = stringstream();
    for (int i = 0; i < totalRolls; ++i) {
        Roll *d = dice_factory_from_array(rolls[i]);
        ss << printRoll(d) << "\n";
        ss << "   Chance: " << score(d, CHANCE) << "\n";
        ss << "   Yatzy: " << score(d, YATZY) << "\n";
        ss << "   Ones: " << score(d, ONES) << "\n";
        ss << "   Twos: " << score(d, TWOS) << "\n";
        ss << "   Threes: " << score(d, THREES) << "\n";
        ss << "   Fours: " << score(d, FOURS) << "\n";
        ss << "   Fives: " << score(d, FIVES) << "\n";
        ss << "   Sixes: " << score(d, SIXES) << "\n";
        ss << "   Pair: " << score(d, PAIR) << "\n";
        ss << "   Two Pairs: " << score(d, TWO_PAIRS) << "\n";
        ss << "   Three of a kind: " << score(d, THREE_OF_A_KIND) << "\n";
        ss << "   Four of a kind: " << score(d, FOUR_OF_A_KIND) << "\n";
        ss << "   Small Straight: " << score(d, SMALL_STRAIGHT) << "\n";
        ss << "   Large Straight: " << score(d, LARGE_STRAIGHT) << "\n";
        ss << "   Full House: " << score(d, FULL_HOUSE) << "\n";

        ss << "\n";
    }

    ApprovalTests::Approvals::verify(ss.str());
}


