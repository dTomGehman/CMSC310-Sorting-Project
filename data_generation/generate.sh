#bash script to generate all required data files and 
#  place them in ../data

#I used .sh extension instead of shebang because 
#  I'm working on nixos, so add the shebang if you need

make clean
make

if [ -d ../data ]; then 
    rm ../data/*
else
    mkdir ../data
fi

echo "Generating random unsorted files..."
./datagen 30 10000
./datagen 30 100000
./datagen 30 1000000
echo "done"

echo "Generating sorted and reverse-sorted versions..."
filenames=uns*.dat

for f in $filenames
do
    ./datatrans $f
done
echo "done"

mv *.dat ../data/

