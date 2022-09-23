#!/usr/bin/env python3

"""A simple python script template.
"""

import os
import pandas
import sys
import argparse
import matplotlib.pyplot as plt
import numpy as np
from sympy import Q

def main(arguments):

    # parser = argparse.ArgumentParser(
    #     description=__doc__,
    #     formatter_class=argparse.RawDescriptionHelpFormatter)
    # parser.add_argument('folder', help="Folder")
    
    # args = parser.parse_args(arguments)

    percents = [0, 5, 20, 50, 80, 95, 100]
    
    
    table = pandas.DataFrame()
    

    for percent in percents:

        folder = "mutant_IKK_cFLIP_oxygen_%d/output/" % percent
        initial_path = os.path.join(folder, "cells_00000.txt")
        final_path = os.path.join(folder, "cells_01440.txt")
        if os.path.exists(folder) and os.path.exists(initial_path) and os.path.exists(final_path):

            print("Loading ", folder)
            initial_table = pandas.read_csv(initial_path, sep=";")["cell_line"].value_counts()
            # print(initial_table)
            if len(initial_table) < 2:
                new_index = 0 if initial_table.index[0] == 1 else 1
                initial_table[new_index] = 0
            initial_table = initial_table.sort_index()
            initial_table['sum'] = initial_table[0] + initial_table[1]
            print(initial_table)

            final_table = pandas.read_csv(final_path, sep=";")["cell_line"].value_counts()
            if len(final_table) < 2:
                # print(final_table.)
                new_index = 0 if final_table.index[0] == 1 else 1
                final_table[new_index] = 0

            final_table = final_table.sort_index()
            final_table['sum'] = final_table[0] + final_table[1]
            print(final_table)

            print(final_table / initial_table)
            print("\n\n\n")

        table[percent] = final_table / initial_table
    print(table)

    # print(table.index)
    fig = plt.figure(figsize=(4, 3), dpi=500, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    table.loc[0, :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    # fig_path = "wt_growth_rate.png"
    # print(fig_path)
    # fig.savefig(fig_path)

    # fig = plt.figure(figsize=(4, 3), dpi=500, tight_layout=True)
    # ax = fig.add_subplot(1,1,1)
    table.loc[1, :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    # fig_path = "mutant_growth_rate.png"
    # print(fig_path)
    # fig.savefig(fig_path)

    table.loc['sum', :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    fig_path = "growth_rate.png"
    # print(fig_path)
    fig.savefig(fig_path)
            

    # percents = [0, 5, 20, 50, 80, 95, 100]
    
    
    table_noo = pandas.DataFrame()
    

    for percent in percents:

        folder = "mutant_IKK_cFLIP_nooxygen_%d/output/" % percent
        initial_path = os.path.join(folder, "cells_00000.txt")
        final_path = os.path.join(folder, "cells_01440.txt")
        if os.path.exists(folder) and os.path.exists(initial_path) and os.path.exists(final_path):

            print("Loading ", folder)
            initial_table = pandas.read_csv(initial_path, sep=";")["cell_line"].value_counts()
            # print(initial_table)
            if len(initial_table) < 2:
                new_index = 0 if initial_table.index[0] == 1 else 1
                initial_table[new_index] = 0
            initial_table = initial_table.sort_index()
            initial_table['sum'] = initial_table[0] + initial_table[1]
            print(initial_table)

            final_table = pandas.read_csv(final_path, sep=";")["cell_line"].value_counts()
            if len(final_table) < 2:
                # print(final_table.)
                new_index = 0 if final_table.index[0] == 1 else 1
                final_table[new_index] = 0

            final_table = final_table.sort_index()
            final_table['sum'] = final_table[0] + final_table[1]
            print(final_table)

            print(final_table / initial_table)
            print("\n\n\n")

        table_noo[percent] = final_table / initial_table
    print(table_noo)

    # print(table.index)
    fig = plt.figure(figsize=(4, 3), dpi=2000, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    table_noo.loc[0, :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    # fig_path = "wt_growth_rate.png"
    # print(fig_path)
    # fig.savefig(fig_path)

    # fig = plt.figure(figsize=(4, 3), dpi=500, tight_layout=True)
    # ax = fig.add_subplot(1,1,1)
    table_noo.loc[1, :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    # fig_path = "mutant_growth_rate.png"
    # print(fig_path)
    # fig.savefig(fig_path)

    table_noo.loc['sum', :].dropna().plot(ax=ax)
    # plt.legend(["Wild type", "Mutant", "Total"])
    # plt.title(folder.split("_")[-1] + "% of IKK cFLIP mutants")
    fig_path = "nooxygen_growth_rate.png"
    # print(fig_path)
    fig.savefig(fig_path)
            
    
    fig = plt.figure(figsize=(2.6, 2), dpi=500)#, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    from itertools import cycle, islice
    my_colors = list(islice(cycle(['#0055ff', '#ffaa00', '#0040bf', '#bf7f00']), None, 4))
    table_noo.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linestyle=':', linewidth=2)
    table_noo.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linestyle=':', linewidth=2)
    table.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linewidth=2)
    table.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linewidth=2)
    # lgd = plt.legend([
    #     "WT, no oxygen", "IKK+, cFLIP+, no oxygen", 
    #     "WT, oxygen", "IKK+, cFLIP+, oxygen"
    # ],loc='center left', bbox_to_anchor=(1, 0.5))
    plt.xlabel("Percentage of mutants")
    plt.ylabel("Growth rate")
    fig.savefig("compared_growth_rate.png", bbox_inches='tight')# ,bbox_extra_artists=(lgd,), bbox_inches='tight')


    fig = plt.figure(figsize=(2.6, 2), dpi=500)#, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    from itertools import cycle, islice
    my_colors = list(islice(cycle(['#0055ff', '#ffaa00', '#0040bf', '#bf7f00']), None, 4))
    table_noo.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linestyle=':', linewidth=2)
    table_noo.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linestyle=':', linewidth=2)
    table_noo.loc['sum', :].dropna().plot(ax=ax, color='#00b400', linestyle=':', linewidth=2)
    table.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linewidth=2)
    table.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linewidth=2)
    table.loc['sum', :].dropna().plot(ax=ax, color='#007800', linewidth=2)
    lgd = plt.legend([
        "WT, no oxygen", "IKK+, cFLIP+, no oxygen", "global population, no oxygen", 
        "WT, oxygen", "IKK+, cFLIP+, oxygen", "global population, oxygen"
    ],loc='center left', bbox_to_anchor=(1, 0.5))
    plt.xlabel("Percentage of mutants")
    plt.ylabel("Growth rate")
    
    fig.savefig("compared_growth_rate_2.png" ,bbox_extra_artists=(lgd,), bbox_inches='tight')

    fig = plt.figure(figsize=(3, 2), dpi=2000)#, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    from itertools import cycle, islice
    my_colors = list(islice(cycle(['#0055ff', '#ffaa00', '#0040bf', '#bf7f00']), None, 4))
    # table_noo.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linestyle=':', linewidth=2)
    # table_noo.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linestyle=':', linewidth=2)
    # table_noo.loc['sum', :].dropna().plot(ax=ax, color='#00b400', linestyle=':', linewidth=2)
    # print(table.index)
    table = table*100
    table.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linewidth=2)
    table.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linewidth=2)
    table.loc['sum', :].dropna().plot(ax=ax, color='#007800', linewidth=2)
    lgd = plt.legend([
        # "WT, no oxygen", "IKK+, cFLIP+, no oxygen", "global population, no oxygen", 
        "WT", "IKK+, cFLIP+", "Total"
    ],loc='upper left', bbox_to_anchor=(1, 1))
    plt.xlabel("Percentage of mutants")
    plt.ylabel("Population increase (%)")
    plt.yticks([100, 125, 150, 175, 200, 225])
    fig.savefig("compared_growth_rate_3.png" ,
    # bbox_extra_artists=(lgd,), 
        bbox_inches='tight'
    )


    fig = plt.figure(figsize=(2.6, 2), dpi=500)#, tight_layout=True)
    ax = fig.add_subplot(1,1,1)
    from itertools import cycle, islice
    # my_colors = list(islice(cycle(['#0055ff', '#ffaa00', '#0040bf', '#bf7f00']), None, 4))
    # table_noo.loc[0, :].dropna().plot(ax=ax, color='#0055ff', linestyle=':', linewidth=2)
    # table_noo.loc[1, :].dropna().plot(ax=ax, color='#ffaa00', linestyle=':', linewidth=2)
    pandas.DataFrame((table.loc[1, :].iloc[-1]*np.ones((len(percents), 1))), index=percents).dropna().plot(ax=ax, color='#0055ff', linewidth=2)
    # print(table2)
    # print(table.loc['sum', :])
    # print(pandas.Series())#.dropna().plot(ax=ax, color='#0055ff', linewidth=2)
    table.loc['sum', :].dropna().plot(ax=ax, color='#ffaa00', linewidth=2)
    # lgd = plt.legend([
    #     "WT, no oxygen", "IKK+, cFLIP+, no oxygen", 
    #     "WT, oxygen", "IKK+, cFLIP+, oxygen"
    # ],loc='center left', bbox_to_anchor=(1, 0.5))
    
    fig.savefig("growth_rate_tnf.png")# ,bbox_extra_artists=(lgd,), bbox_inches='tight')


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))