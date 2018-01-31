Yatzy Approval Kata 
====================

This repo contains some code that could be used in a game of Yatzy. What the code should do is described below under 'Yatzy rules'.
Your job is to write tests for the code, and identify bugs. To make it more 
interesting, there are actually three implemenentations of the yatzy rules. They 
get buggier as you go from version 1 to 2 and from 2 to 3. I suggest you start
by writing lots of tests for version 1, then see how many bugs they catch in versions 2 and 3.

There is a version of the implementation in Python, a Java version is under development. Each language implementation includes all three versions of the code. To run the python version of yatzy1 and get the helptext:

	cd python
	python texttest_adapter_yatzy1.py --help

This 'adapter' script adds a command-line interface to the business logic which is
in the 'yatzy1.py' file.

Similar adapters exist for the yatzy2 and yatzy3 implementations.

Writing tests
-------------

You can write tests for whichever of the three implementations you wish, using whichever tool you wish. You are provided with an initial Approval Test using the tool (TextTest)[http://texttest.org]. Other approval testing tools exist, for example (http://approvaltests.com/)[Approval Tests]. 

There is another repo on github that contains a sample solution using TextTest. I suggest you do
the exercise yourself though, before you look at it. (https://github.com/emilybache/Yatzy-Approval-Kata-sample-solution)

Viewing and Running the texttests
---------------------------------

(assuming you already have texttest installed, see http://texttest.org)

The simplest way is to open texttest like this:

	texttest -a yatzy -c $PWD -d $PWD/texttests 

Note that $PWD should automatically expand to the complete path to the current working directory. If it does not, insert it by hand instead.

You can switch version from yatzy1 to yatzy2 and yatzy3 by changing the 'executable' listed in texttests/config.yatzy.

Yatzy rules
-----------

The game of Yatzy is a simple dice game. Each player
rolls five six-sided dice. They can re-roll some or all
of the dice up to three times (including the original roll).

The player then places the roll in a category, such as ones,
twos, fives, pair, two pairs etc (see below). If the roll is
compatible with the category, the player gets a score for the
roll according to the rules. If the roll is not compatible
with the category, the player scores zero for the roll.

For example, suppose a player scores 5,6,5,5,2 in the fives
category they would score 15 (three fives). The score for
that go is then added to their total and the category cannot
be used again in the remaining goes for that game.
A full game consists of one go for each category. Thus, for
their last go in a game, a player must choose their only
remaining category.

Your task is to score a GIVEN roll in a GIVEN category.
You do NOT have to program the random dice rolling.
The game is NOT played by letting the computer choose the
highest scoring category for a given roll.

Yatzy Categories and Scoring Rules
----------------------------------

### Chance:
The player scores the sum of all dice, no matter what they read.
For example:

-   1,1,3,3,6 placed on "chance" scores 14 (1+1+3+3+6)
-   4,5,5,6,1 placed on "chance" scores 21 (4+5+5+6+1)

### Yatzy:
If all dice have the same number,
the player scores 50 points.
For example:

-   1,1,1,1,1 placed on "yatzy" scores 50
-   1,1,1,2,1 placed on "yatzy" scores 0

### Ones, Twos, Threes, Fours, Fives, Sixes:
The player scores the sum of the dice that reads one,
two, three, four, five or six, respectively.
For example:

-   1,1,2,4,4 placed on "fours" scores 8 (4+4)
-   2,3,2,5,1 placed on "twos" scores 4  (2+2)
-   3,3,3,4,5 placed on "ones" scores 0

### Pair:
The player scores the sum of the two highest matching dice.
For example, when placed on "pair":

-   3,4,5,6,6 scores 12 (6+6)
-   3,3,3,4,4 scores 8 (4+4)
-   1,1,6,2,6 scores 12 (6+6)
-   3,3,3,4,1 scores 6 (3+3)
-   3,3,3,3,1 scores 6 (3+3)

### Two pairs:
If there are two pairs of dice with the same number, the
player scores the sum of these dice.
For example, when placed on "two pairs":

-   1,1,2,3,3 scores 8 (1+1+3+3)
-   1,1,2,3,4 scores 0
-   1,1,2,2,2 scores 6 (1+1+2+2)

### Three of a kind:
If there are three dice with the same number, the player
scores the sum of these dice.
For example, when placed on "three of a kind":

-    3,3,3,4,5 scores 9 (3+3+3)
-    3,3,4,5,6 scores 0
-    3,3,3,3,1 scores 9 (3+3+3)

### Four of a kind:
If there are four dice with the same number, the player
scores the sum of these dice.
For example, when placed on "four of a kind":

-    2,2,2,2,5 scores 8 (2+2+2+2)
-    2,2,2,5,5 scores 0
-    2,2,2,2,2 scores 8 (2+2+2+2)

### Small straight:
When placed on "small straight", if the dice read

   1,2,3,4,5,

the player scores 15 (the sum of all the dice).

### Large straight:
When placed on "large straight", if the dice read

   2,3,4,5,6,

the player scores 20 (the sum of all the dice).

### Full house:
If the dice are two of a kind and three of a kind, the
player scores the sum of all the dice.
For example, when placed on "full house":

-    1,1,2,2,2 scores 8 (1+1+2+2+2)
-    2,2,3,3,4 scores 0
-    4,4,4,4,4 scores 0