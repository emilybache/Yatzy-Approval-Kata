Java version of Yatzy Approval Testing Kata
===========================================

Please read the instructions in the folder above this one first.

First update texttest's config file to point at the Java executable.
In the file ../texttests/config.yatzy, replace line 2 with these two lines:

    interpreter:java
    executable:org.yatzy.cli.CliAdapterYatzy1

Then you will be able run the tests interactively with the GUI as explained in the README file in the folder above this one.

To run the TextTests on the command line, first set the TEXTTEST_HOME, then use maven like this:

    $ export TEXTTEST_HOME=<absolute path to the "texttests" folder parallel to this one>
    $ mvn clean install

