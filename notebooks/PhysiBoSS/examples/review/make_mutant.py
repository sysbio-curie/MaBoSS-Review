#!/usr/bin/env python3

"""A simple python script template.
"""

import os
import pandas
import sys
import argparse
import shutil
import random

def main(arguments):

    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('percentage_mutant', help="Percentage of mutants")
    
    args = parser.parse_args(arguments)

    percentage_mutants = int(args.percentage_mutant)
    new_path = "mutant_IKK_cFLIP_nooxygen_" + str(percentage_mutants)
    shutil.copytree("mutant_IKK_cFLIP_nooxygen", new_path)
    table = pandas.read_csv("mutant_IKK_cFLIP_nooxygen/init.txt", sep=";", skiprows=1, header=None)#, encoding="utf_16")
    # print(table.iloc[0:10, 12])
    # print(table.shape)
    print(table.head())
    new_col = pandas.Series([0 if random.randint(1, 100) > percentage_mutants else 1 for _ in range(table.shape[0])])
    table.iloc[:, 12] = new_col
    
    # print(table.iloc[0:10, 12])
    table.to_csv("mutant_IKK_cFLIP_nooxygen_" + str(percentage_mutants) + "/init.txt", sep=";", index=None, header=None)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))