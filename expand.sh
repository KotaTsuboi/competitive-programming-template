oj-bundle main.cpp > expand.cpp

dirs=("a" "b" "c" "d" "e" "f" "g" "h")

for dir in ${dirs[@]}
do
    rm -rf dir
    mkdir $dir
    cp expand.cpp $dir/main.cpp
done

rm -f expand.cpp
