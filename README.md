This is the source code for the ALID algorithm published in our VLDB 2015 paper: "ALID: Scalable dominant cluster detection"

1) This code is compiled with g++ on Ubuntu 14.04. To compile this code, use "make clean & make". Thread level parallelism with openmp is built in.

2) After succesfully compiling the code, run the demo simply with command "./RUN". Use "./RUN -h" to see the manual. 

3) Format of input "md1_p1.00_N10000_D100_C20.bin":
--------------------------------------------------------------------------
Number of features N | Number of feature dimensions D | All features
      <int> x1       |              <int> x1          |     [float]*N*D
--------------------------------------------------------------------------
The file name of input file means:
Data mode: 1  # the first data geration case in the paper.
p = 1.00      # the only parameter in the data generation process.
N = 10000     # the number of features
D = 100       # the dimension of features
C = 20        # number of clusters
--------------------------------------------------------------------------

4) Formate of output file "PALID_result.txt":
There "N" rows and 2 columns in "PALID_result.txt".
The i-th row corresponds to the i-th feature.
The second column is the ID of dominant set that a feature belongs to.
The first column shows the density of the dominant set.

5) Auxiliary files "HASHPOOL.bin" and "WXPOOL.bin" store randomly generated numbers.
You can use any randomly generated numbers as you want.

6) The code has not been explicitly tested. Please contact the author "lca117@sfu.ca" is find any bug. Thanks!

