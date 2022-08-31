#!/usr/bin/env python
import os
import string

import yatzy1


from itertools import combinations_with_replacement


def all_dice_combinations():
    all_dice_values = list(range(1, 7))
    all_combinations_of_5_dice = list(combinations_with_replacement(all_dice_values, 5))
    return all_combinations_of_5_dice


if __name__ == "__main__":
    all_possible_rolls = all_dice_combinations()
    categories = yatzy1.CATEGORIES
    testcase_dirs = []
    for category in categories:
        testcase_dir = string.capwords(category)
        testcase_dirs.append(testcase_dir)
        if not os.path.exists(testcase_dir):
            os.makedirs(testcase_dir)
        with open(os.path.join(testcase_dir, "stdin.yatzy"), "w") as f:
            for roll in all_possible_rolls:
                dice = ",".join(str(i) for i in roll)
                print(f'{dice} {category}', file=f)
    with open("testsuite.yatzy", "w") as f:
        f.write("helptext\n")
        for d in testcase_dirs:
            f.write(f"{d}\n")

