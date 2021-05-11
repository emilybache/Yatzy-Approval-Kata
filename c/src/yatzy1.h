#ifndef SAMPLE_H
#define SAMPLE_H

struct Roll {
    int* dice;
};

typedef struct Roll Roll;

enum category {CHANCE, YATZY, ONES, TWOS, THREES, FOURS, FIVES, SIXES,
        PAIR, TWO_PAIRS, THREE_OF_A_KIND, FOUR_OF_A_KIND, SMALL_STRAIGHT, LARGE_STRAIGHT, FULL_HOUSE};

int score(Roll*, category);

int Chance(int d1, int d2, int d3, int d4, int d5);
int yatzy(int dice[]);
int Ones(int d1, int d2, int d3, int d4, int d5);
int Twos(int d1, int d2, int d3, int d4, int d5);
int Threes(int d1, int d2, int d3, int d4, int d5);



Roll* dice_factory(int d1, int d2, int d3, int d4, int _5);
Roll* dice_factory_from_array(int* dice);
void dice_destructor(Roll* yatzy);

int Fours(Roll* yatzy);
int Fives(Roll* yatzy);
int sixes(Roll* yatzy);
int ScorePair(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);
int TwoPair(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);
int FourOfAKind(Roll* yatzy, int _1, int _2, int d3, int d4, int d5);
int ThreeOfAKind(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);
int SmallStraight(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);
int LargeStraight(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);
int FullHouse(Roll* yatzy, int d1, int d2, int d3, int d4, int d5);

#endif //SAMPLE_H
