#!/usr/bin/env python
import os
import string
from pathlib import Path
from itertools import combinations_with_replacement

import yatzy1


def all_dice_combinations():
    all_dice_values = list(range(1, 7))
    all_combinations_of_5_dice = list(combinations_with_replacement(all_dice_values, 5))
    return all_combinations_of_5_dice


def write_stdin_file(testcase_dir, all_possible_rolls, category, appname):
    with open(os.path.join(testcase_dir, f"stdin.{appname}"), "w") as f:
        for roll in all_possible_rolls:
            dice = ",".join(str(i) for i in roll)
            print(f'{dice} {category}', file=f)


def create_testcase(folder: Path, name: str, appname: str):
    testcase_dir = folder / name
    if not os.path.exists(testcase_dir):
        os.makedirs(testcase_dir)
    with open(folder / f"testsuite.{appname}", "a") as f:
        f.write(f"{name}\n")
    return testcase_dir


def main():
    appname = "yatzy"
    all_possible_rolls = all_dice_combinations()
    categories = yatzy1.CATEGORIES
    for category in categories:
        testcase_name = string.capwords(category)
        testcase_dir = create_testcase(Path(os.getcwd()), testcase_name, appname)
        write_stdin_file(testcase_dir, all_possible_rolls, category, appname)


if __name__ == "__main__":
    main()
