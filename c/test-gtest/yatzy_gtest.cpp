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

    int totalRolls = 2;
    int rolls[][5] = {
            {2, 3, 4, 5, 1},
            {3, 3, 4, 5, 1}
    };
    stringstream ss = stringstream();
    for (int i = 0; i < totalRolls; ++i) {
        Roll *d = dice_factory_from_array(rolls[i]);
        ss << printRoll(d) << "\n";
        ss << "   Chance: " << score(d, CHANCE) << "\n";
        // TODO: the other categories

        ss << "\n";
    }

    ApprovalTests::Approvals::verify(ss.str());
}


