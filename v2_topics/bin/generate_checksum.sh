#!/bin/bash

filearr=(File1.iso File2.iso File3.iso File4.iso File5.iso File6.iso File7.iso File8.iso)
for file in ${filearr[@]}
do
    #create file with sizes
    dd if=/dev/zero of=$file bs=10M count=1
done

#parlle
PIDARRAY=()
start=$(date +%s%N)
for file in ${filearr[@]}
do
    #"$!" is the latest PID
    md5sum $file & PIDARRAY+=("$!")
done
wait ${PIDARRAY[@]} #wait all process end
end=$(date +%s%N)
diff=$(( end - start ))
echo "Time1 :" $diff

#serial
start=$(date +%s%N)
md5sum ${filearr[@]}
end=$(date +%s%N)
diff=$(( end - start ))
echo "Time2 :" $diff