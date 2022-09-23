#!/usr/bin/env python3

"""A simple python script template.
"""

import os
import pandas
import sys
import argparse
import matplotlib.pyplot as plt
import numpy as np

def main(arguments):

    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('folder', help="Folder")
    
    args = parser.parse_args(arguments)

    folder = args.folder
    output_folder = os.path.join(folder, "output")
    table = pandas.DataFrame()
    if os.path.exists(folder) and os.path.exists(output_folder):

        for tp in sorted(os.listdir(output_folder)):
            if tp.endswith(".txt"):
                tp_path = os.path.join(output_folder, tp)
                print("Loading ", tp_path)
                # print(table.head())
                tp_table = pandas.read_csv(tp_path, sep=";")["cell_line"].value_counts()
                tp_table.name = int(tp.split("_")[1].split(".")[0])
                table = table.append(tp_table.sort_index(0))
                # print(table.head())
        print(table.head())
        print(table.columns[0] == 1)
        if table.shape[1] < 2:
            new_index = 0 if table.columns[0] == 1 else 1
            table[new_index] = np.zeros((table.shape[0], 1))

        print(table.head())
        table['sum'] = table[0] + table[1]
        # table['ratio'] = table[1]/(table[1] + table[0])
        
        print(table)
        fig = plt.figure(figsize=(4, 3), dpi=500, tight_layout=True)
        ax = fig.add_subplot(1,1,1)
        table.plot(ax=ax)
        plt.legend(["Wild type", "Mutant", "Total"])
        plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
        fig_path = str(folder) + ".png"
        print(fig_path)
        fig.savefig(fig_path)

            


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))