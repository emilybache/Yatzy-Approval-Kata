"""
This module adapts the Yatzy program for use on the command line with TextTest.
It uses three methods that the Yatzy program must define:

    valid_categories()
    parse_dice_and_category(input_string)
    score(dice, category)

It takes input on standard input.
It will then print out the results of the score on standard output and standard error.
It can alternatively print out help text if '--help' is included in the command line arguments.

"""
import sys

def main(valid_categories, parse_dice_and_category, score):
    if "--help" in sys.argv or '-h' in sys.argv:
        print("""\
Yatzy calculator program.

You should pass dice rolls to standard input, formatted as one roll of five dice followed by the category to score:

1,2,3,4,5 <category>
1,2,2,3,3 <category>

where <category> should be one of:

{}

This program will then print the calculated score to standard output, and any error messages to standard error.

        """.format(valid_categories()))
        sys.exit(0)
        
    for yatzy_input in sys.stdin.readlines():
        dice_and_category_str = yatzy_input.strip()
        category = None
        try:
            dice, category = parse_dice_and_category(dice_and_category_str)
            points = score(dice, category)
        except ValueError as e:
            sys.stderr.write("ERROR in input '{}': {}\n".format(dice_and_category_str, e))
            points = "BAD_INPUT"
        print("""[{}] {}""".format(dice_and_category_str, points))
