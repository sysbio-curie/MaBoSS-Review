#!/bin/sh
#SBATCH --job-name=PhysiBoSS # Job name
#SBATCH --ntasks=1                   # Run a single task	
#SBATCH --ntasks-per-node=1            # Number of CPU cores per task
#SBATCH -c 18 
#SBATCH -vvv
#SBATCH --mem=2gb                  # Total memory limit
#SBATCH --time=4:00:00              # Time limit hrs:min:sec
#SBATCH --output=log_%j.log     # Standard output and error log

cd examples/review/mutant_IKK_cFLIP_oxygen_50/
../../../bin/PhysiBoSS .
