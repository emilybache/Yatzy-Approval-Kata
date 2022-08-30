Yatzy Approval Kata 
====================

This repo contains some code that could be used in a game of Yatzy. What the code should do is described in [Yatzy Kata Description](https://sammancoaching.org/kata_descriptions/yatzy.html).

Your job is to write tests for the code, and identify bugs. To make it more 
interesting, there are actually three implemenentations of the yatzy rules. They 
get buggier as you go from version 1 to 2 and from 2 to 3. I suggest you start
by writing lots of tests for version 1, then see how many bugs they catch in versions 2 and 3.

There is a version of the implementation in Python, a Java and C version are under development. Each language implementation includes all three versions of the code. To run the python version of yatzy1 and get the helptext:

	cd python
	python texttest_adapter_yatzy1.py --help

This 'adapter' script adds a command-line interface to the business logic which is
in the 'yatzy1.py' file.

Similar adapters exist for the yatzy2 and yatzy3 implementations.

Writing tests
-------------

You can write tests for whichever of the three implementations you wish, using whichever tool you wish. You are provided with an initial Approval Test using the tool [TextTest](http://texttest.org). Other approval testing tools exist, for example [Approval Tests](http://approvaltests.com/). 

There is a sample solution on the branch 'with_tests'. I suggest you do
the exercise yourself though, before you look at it.

Viewing and Running the texttests
---------------------------------

(assuming you already have texttest installed, see http://texttest.org)

Open texttest from the same folder as this README.md file:

    cd Yatzy-Approval-Kata
	texttest 

You can switch version from yatzy1 to yatzy2 and yatzy3 by changing the 'executable' listed in texttests/config.yatzy.

