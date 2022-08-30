#!/usr/bin/env python
import os
import string
from itertools import combinations_with_replacement

import yatzy1

if __name__ == "__main__":
    options = list(range(1, 7))
    combinations = list(combinations_with_replacement(options, 5))
    categories = yatzy1.CATEGORIES
    testcase_dirs = []
    for category in categories:
        testcase_dir = string.capwords(category)
        testcase_dirs.append(testcase_dir)
        if not os.path.exists(testcase_dir):
            os.makedirs(testcase_dir)
        with open(os.path.join(testcase_dir, "stdin.yatzy"), "w") as f:
            for c in combinations:
                dice = ",".join(str(i) for i in c)
                print(f'{dice} {category}', file=f)
    with open("testsuite.yatzy", "w") as f:
        f.write("helptext\n")
        for d in testcase_dirs:
            f.write(f"{d}\n")

