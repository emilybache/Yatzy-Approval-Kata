#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "yatzy1.h"


int Chance(int d1, int d2, int d3, int d4, int d5) {
    int total = 0;
    total += d1;
    total += d2;
    total += d3;
    total += d4;
    total += d5;
    return total;
}

int yatzy(int dice[]) {
    int counts[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i != 5; i++)
        counts[dice[i] - 1]++;
    for (int i = 0; i != 6; i++)
        if (counts[i] == 5)
            return 50;
    return 0;
}

int Ones(int d1, int d2, int d3, int d4, int d5) {
    int sum = 0;
    if (d1 == 1) sum++;
    if (d2 == 1) sum++;
    if (d3 == 1) sum++;
    if (d4 == 1) sum++;
    if (d5 == 1)
        sum++;

    return sum;
}

int Twos(int d1, int d2, int d3, int d4, int d5) {
    int sum = 0;
    if (d1 == 2) sum += 2;
    if (d2 == 2) sum += 2;
    if (d3 == 2) sum += 2;
    if (d4 == 2) sum += 2;
    if (d5 == 2) sum += 2;
    return sum;
}

int Threes(int d1, int d2, int d3, int d4, int d5) {
    int s;
    s = 0;
    if (d1 == 3) s += 3;
    if (d2 == 3) s += 3;
    if (d3 == 3) s += 3;
    if (d4 == 3) s += 3;
    if (d5 == 3) s += 3;
    return s;
}


Roll *dice_factory(int d1, int d2, int d3, int d4, int _5) {
    Roll *yatzy = (malloc(sizeof(Roll)));
    int *dice = malloc(5 * sizeof(int));
    dice[0] = d1;
    dice[1] = d2;
    dice[2] = d3;
    dice[3] = d4;
    dice[4] = _5;
    yatzy->dice = dice;
    return yatzy;
}

Roll *dice_factory_from_array(int *d) {
    Roll *yatzy = (malloc(sizeof(Roll)));
    int *dice = malloc(5 * sizeof(int));
    dice[0] = d[0];
    dice[1] = d[1];
    dice[2] = d[2];
    dice[3] = d[3];
    dice[4] = d[4];
    yatzy->dice = dice;
    return yatzy;
}

void dice_destructor(Roll *yatzy) {
    free(yatzy->dice);
    free(yatzy);
}

int Fours(Roll *yatzy) {
    int sum;
    sum = 0;
    for (int at = 0; at != 5; at++) {
        if (yatzy->dice[at] == 4) {
            sum += 4;
        }
    }
    return sum;
}

int Fives(Roll *yatzy) {
    int s = 0;
    int i;
    for (i = 0; i < 5; i++)
        if (yatzy->dice[i] == 5)
            s = s + 5;
    return s;
}

int sixes(Roll *yatzy) {
    int sum = 0;
    for (int at = 0; at < 5; at++)
        if (yatzy->dice[at] == 6)
            sum = sum + 6;
    return sum;
}

int ScorePair(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int counts[6] = {0, 0, 0, 0, 0, 0};
    counts[d1 - 1]++;
    counts[d2 - 1]++;
    counts[d3 - 1]++;
    counts[d4 - 1]++;
    counts[d5 - 1]++;
    int at;
    for (at = 0; at != 6; at++)
        if (counts[6 - at - 1] >= 2)
            return (6 - at) * 2;
    return 0;
}

int TwoPair(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int counts[6] = {0};
    counts[d1 - 1]++;
    counts[d2 - 1]++;
    counts[d3 - 1]++;
    counts[d4 - 1]++;
    counts[d5 - 1]++;
    int n = 0;
    int score = 0;
    for (int i = 0; i < 6; i += 1)
        if (counts[6 - i - 1] >= 2) {
            n++;
            score += (6 - i);
        }
    if (n == 2)
        return score * 2;
    else
        return 0;
}

int FourOfAKind(Roll *yatzy, int _1, int _2, int d3, int d4, int d5) {
    int tallies[6];
    tallies[0] = tallies[1] = tallies[2] = 0;
    tallies[3] = tallies[4] = tallies[5] = 0;
    tallies[_1 - 1]++;
    tallies[_2 - 1]++;
    tallies[d3 - 1]++;
    tallies[d4 - 1]++;
    tallies[d5 - 1]++;
    for (int i = 0; i < 6; i++)
        if (tallies[i] >= 4)
            return (i + 1) * 4;
    return 0;
}

int ThreeOfAKind(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int t[6];
    t[0] = t[1] = t[2] = 0;
    t[3] = t[4] = t[5] = 0;
    t[d1 - 1]++;
    t[d2 - 1]++;
    t[d3 - 1]++;
    t[d4 - 1]++;
    t[d5 - 1]++;
    for (int i = 0; i < 6; i++)
        if (t[i] >= 3)
            return (i + 1) * 3;
    return 0;
}

int SmallStraight(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int tallies[6];
    memset(tallies, 0, sizeof(int) * 6);
    tallies[d1 - 1] += 1;
    tallies[d2 - 1] += 1;
    tallies[d3 - 1] += 1;
    tallies[d4 - 1] += 1;
    tallies[d5 - 1] += 1;
    if (tallies[0] == 1 &&
        tallies[1] == 1 &&
        tallies[2] == 1 &&
        tallies[3] == 1 &&
        tallies[4] == 1)
        return 15;
    return 0;
}

int LargeStraight(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int tallies[6];
    memset(tallies, 0, sizeof(*tallies) * 6);
    tallies[d1 - 1] += 1;
    tallies[d2 - 1] += 1;
    tallies[d3 - 1] += 1;
    tallies[d4 - 1] += 1;
    tallies[d5 - 1] += 1;
    if (tallies[1] == 1 &&
        tallies[2] == 1 &&
        tallies[3] == 1 &&
        tallies[4] == 1
        && tallies[5] == 1)
        return 20;
    return 0;
}

int FullHouse(Roll *yatzy, int d1, int d2, int d3, int d4, int d5) {
    int tallies[6];
    bool _2 = false;
    int i;
    int _2_at = 0;
    bool _3 = false;
    int _3_at = 0;

    memset(tallies, 0, sizeof(int) * 6);
    tallies[d1 - 1] += 1;
    tallies[d2 - 1] += 1;
    tallies[d3 - 1] += 1;
    tallies[d4 - 1] += 1;
    tallies[d5 - 1] += 1;

    for (i = 0; i != 6; i += 1)
        if (tallies[i] == 2) {
            _2 = true;
            _2_at = i + 1;
        }

    for (i = 0; i != 6; i += 1)
        if (tallies[i] == 3) {
            _3 = true;
            _3_at = i + 1;
        }

    if (_2 && _3)
        return _2_at * 2 + _3_at * 3;
    else
        return 0;
}

int score(Roll *d, int category) {
    switch (category) {
        case CHANCE:
            return Chance(d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case YATZY:
            return yatzy(d->dice);
        case ONES:
            return Ones(d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case TWOS:
            return Twos(d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case THREES:
            return Threes(d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case FOURS:
            return Fours(d);
        case FIVES:
            return Fives(d);
        case SIXES:
            return sixes(d);
        case PAIR:
            return ScorePair(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case TWO_PAIRS:
            return TwoPair(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case THREE_OF_A_KIND:
            return ThreeOfAKind(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case FOUR_OF_A_KIND:
            return FourOfAKind(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case SMALL_STRAIGHT:
            return SmallStraight(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case LARGE_STRAIGHT:
            return LargeStraight(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        case FULL_HOUSE:
            return FullHouse(d, d->dice[0], d->dice[1], d->dice[2], d->dice[3], d->dice[4]);
        default:
            return 0;
    };
}

