#!/bin/bash

#read -p "enter name:" name;
#echo -e "\nwelcome" $name; #translate '\n' with -e
name="kevin";

input='./input.data'
echo -e "hello" $name > $input
cat $input

#file type - user - user group - other user
#
output='./output.data'
touch $output
#sudo chmod u=rw g=rw o=r $output
chmod a+x $output
ls -l $output
chmod a-x $output
ls -l $output

dir='./data'
#mkdir $dir
touch ${$dir/buf.data}
chmod a+t $dir -R
ls -l $dir