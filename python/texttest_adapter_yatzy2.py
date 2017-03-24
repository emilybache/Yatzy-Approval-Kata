#!/usr/bin/env python3

from yatzy2 import valid_categories, parse_dice_and_category, score

import texttest_adapter

if __name__ == "__main__":
	texttest_adapter.main(valid_categories, parse_dice_and_category, score)
	