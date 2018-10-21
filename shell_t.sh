#!/bin/bash

#create file with size
#dd if=/dev/zero of=./junk.data bs=1M count=1
#ls -l ./junk.data
#wc -c ./junk.data

#compare two files
#-e to enable interpretation of escape sequence
echo -e "apple \norange \ngold \nsilver \nsteel \niron" > ./a.txt;
echo -e "orange \ngold \ncookies \ncarrot" > ./b.txt;
sort ./a.txt -o ./A.txt;
sort ./b.txt -o ./B.txt;
echo -e "base only\tstd only\tidentical"
comm ./A.txt ./B.txt;

#remove duplicate files
echo "hello" > test;
cp test test_cp1;
cp test test_cp2;
echo "other" > other
./remove_duplicates.sh