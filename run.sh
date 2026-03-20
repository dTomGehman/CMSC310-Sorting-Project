#bash script to run everything:  
#   make executables
#   generate data if necessary (./data dne)
#   test all sorting algos on all files, tee to a file

make -C ./src

cd data_generation
./generate.sh
cd ..

outfile="$RANDOM.out"
echo "results to be teed to $outfile"

read -s -n 1 -p "Executables and data generated.  Press any key to start tests."

#mergesort
# size 10000
./src/tester ./data uns 10000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 10000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 10000 0 29 merge | tee -a $outfile
echo "">> $outfile
# size 100000
./src/tester ./data uns 100000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 100000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 100000 0 29 merge | tee -a $outfile
echo "">> $outfile
# size 1000000
./src/tester ./data uns 1000000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 1000000 0 29 merge | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 1000000 0 29 merge | tee -a $outfile
echo "">> $outfile

#quicksort
# size 10000
./src/tester ./data uns 10000 0 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 10000 0 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 10000 0 29 quick | tee -a $outfile
echo "">> $outfile
# size 100000
./src/tester ./data uns 100000 0 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 100000 0 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 100000 0 29 quick | tee -a $outfile
echo "">> $outfile
# size 1000000
# break some into chunks
./src/tester ./data uns 1000000 0 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data sor 1000000 0 4 quick | tee -a $outfile
./src/tester ./data sor 1000000 5 14 quick | tee -a $outfile
./src/tester ./data sor 1000000 15 29 quick | tee -a $outfile
echo "">> $outfile
./src/tester ./data "rev" 1000000 0 4 quick | tee -a $outfile
./src/tester ./data "rev" 1000000 5 14 quick | tee -a $outfile
./src/tester ./data "rev" 1000000 15 29 quick | tee -a $outfile
echo "">> $outfile

#selectionsort
# size 10000
./src/tester ./data uns 10000 0 29 selection | tee -a $outfile
./src/tester ./data sor 10000 0 29 selection | tee -a $outfile
./src/tester ./data "rev" 10000 0 29 selection | tee -a $outfile
# size 100000
./src/tester ./data uns 100000 0 29 selection | tee -a $outfile
./src/tester ./data sor 100000 0 29 selection | tee -a $outfile
./src/tester ./data "rev" 100000 0 29 selection | tee -a $outfile
# size 1000000
#do this in chunks in case of failure
./src/tester ./data uns 1000000 0 4 selection | tee -a $outfile
./src/tester ./data uns 1000000 5 9 selection | tee -a $outfile
./src/tester ./data uns 1000000 10 14 selection | tee -a $outfile
./src/tester ./data uns 1000000 15 19 selection | tee -a $outfile
./src/tester ./data uns 1000000 20 24 selection | tee -a $outfile
./src/tester ./data uns 1000000 25 29 selection | tee -a $outfile
echo "">> $outfile

./src/tester ./data sor 1000000 0 4 selection | tee -a $outfile
./src/tester ./data sor 1000000 5 9 selection | tee -a $outfile
./src/tester ./data sor 1000000 10 14 selection | tee -a $outfile
./src/tester ./data sor 1000000 15 19 selection | tee -a $outfile
./src/tester ./data sor 1000000 20 24 selection | tee -a $outfile
./src/tester ./data sor 1000000 25 29 selection | tee -a $outfile
echo "">> $outfile

./src/tester ./data rev 1000000 0 4 selection | tee -a $outfile
./src/tester ./data rev 1000000 5 9 selection | tee -a $outfile
./src/tester ./data rev 1000000 10 14 selection | tee -a $outfile
./src/tester ./data rev 1000000 15 19 selection | tee -a $outfile
./src/tester ./data rev 1000000 20 24 selection | tee -a $outfile
./src/tester ./data rev 1000000 25 29 selection | tee -a $outfile
echo "">> $outfile

