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


    folders = ["mutant_IKK_cFLIP_oxygen_0", "mutant_IKK_cFLIP_oxygen_100", "mutant_IKK_cFLIP_nooxygen_0", "mutant_IKK_cFLIP_nooxygen_100"]

    fig = plt.figure(figsize=(3, 2), dpi=2000)#, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    tables = []    
    for folder in folders:
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

            # print(table.head())
            # table['sum'] = table[0] + table[1]
            # table['ratio'] = table[1]/(table[1] + table[0])
            
            print(table)
            # table.plot(ax=ax)
            tables.append(table)
    
    tables[0][0].plot(ax=ax, color='green')
    tables[1][1].plot(ax=ax, color='red')
    # tables[2][0].plot(ax=ax, linestyle=':', linewidth=2)
    # tables[3][1].plot(ax=ax, linestyle=':', linewidth=2)
    plt.legend([
        "TNF",#, oxygen", 
        "No TNF",# oxygen", 
        # "TNF, no oxygen", "No TNF, no oxygen"
    ])
    # plt.title("Population sizes")
    plt.ylabel("Population size")
    plt.xlabel("Time (min)")
    plt.yticks([9000, 11000, 13000, 15000, 17000])
    fig_path = "celllines_compare.png"
    print(fig_path)
    fig.savefig(fig_path, bbox_inches='tight')

            


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))