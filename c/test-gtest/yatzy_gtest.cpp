#include <gtest/gtest.h>
#include "ApprovalTests.hpp"

extern "C"
{
#include "yatzy1.h"
}

using namespace std;

string printRoll(const Roll* roll) {
    stringstream ss = stringstream();
    ss << "Roll [" <<
       roll->dice[0] << ", " <<
       roll->dice[1] << ", " <<
       roll->dice[2] << ", " <<
       roll->dice[3] << ", " <<
       roll->dice[4]
       << "]";
    return ss.str();
}

TEST(Yatzy, Yatzy)
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
        ss << "\n";
    }

    ApprovalTests::Approvals::verify(ss.str());
}


