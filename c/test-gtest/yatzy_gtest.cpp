#include <gtest/gtest.h>
#include "ApprovalTests.hpp"

extern "C"
{
#include "yatzy1.h"
}

using namespace std;

ostream& operator<<(ostream& ss, const Roll& roll)
{
    ss << "Roll [";

    bool first = true;
    for (int i = 0; i < 5; ++i) {
        if (first)
            first = false;
        else
            ss << ", ";
        ss << roll.dice[i];
    }

    ss << "]";
    return ss;
}



string printCategory(int category) {
    switch (category) {
        case CHANCE:
            return "Chance";
        case YATZY:
            return "Yatzy";
        case ONES:
            return "Ones";
        case TWOS:
            return "Twos";
        case THREES:
            return "Threes";
        case FOURS:
            return "Fours";
        case FIVES:
            return "Fives";
        case SIXES:
            return "Sixes";
        case PAIR:
            return "Pair";
        case TWO_PAIRS:
            return "Two Pairs";
        case THREE_OF_A_KIND:
            return "Three of a kind";
        case FOUR_OF_A_KIND:
            return "Four of a kind";
        case SMALL_STRAIGHT:
            return "Small Straight";
        case LARGE_STRAIGHT:
            return "Large Straight";
        case FULL_HOUSE:
            return "Full House";
        default:
            return "";
    }
}

ostream& operator<<(ostream& ss, const category& category)
{
    ss << printCategory(category);
    return ss;
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
        ss << *d << "\n";
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

TEST(Yatzy, YatzyCategoriesCombinations)
{
    vector<Roll> rolls = {
            *dice_factory(2, 3, 4, 5, 1),
            *dice_factory(4, 3, 4, 5, 1),
            *dice_factory(3, 3, 3, 3, 3),
            *dice_factory(2, 2, 1, 1, 1),
            *dice_factory(2, 6, 5, 6, 5),
            *dice_factory(2, 6, 5, 3, 4),

    };
    vector<category> categories = {CHANCE, YATZY, ONES, TWOS, THREES, FOURS, FIVES, SIXES,
                  PAIR, TWO_PAIRS, THREE_OF_A_KIND, FOUR_OF_A_KIND, SMALL_STRAIGHT, LARGE_STRAIGHT, FULL_HOUSE};

    auto f = [](Roll roll, category category) {
        return score(&roll, category);
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, rolls, categories);
}


