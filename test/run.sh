#
# run.sh [extra-c++-compiler flags] [yn](memcheck)
#
#
# set -e
#
# CCFLAGS=''
# memcheck='n'
# if [ `uname` = 'Linux' ]; then CCFLAGS='-lstdc++'; fi
# if [ $# -gt 0 ]; then memcheck=$1; fi
#
# cd ${0%/*}
#
# compile_and_run() {
#   if [ $# -ne 2 ]; then
#     echo "?"
#   else
#     f=$1
#     f_out="$f.out"
#     compile_cmd=$2
#     $compile_cmd $f -o $f_out
#     "./$f_out"
#     if [ $memcheck = 'y' ]; then
#       valgrind ./$f_out
#     fi
#     rm "$f_out"
#   fi
# }

clang++ -std=c++11 test_StretchyArray.cpp -o 1.out &&
clang++ -std=c++11 test_swapRemove.cpp -o 2.out &&
clang test_StretchyArray_C.c -o 3.out &&
./1.out &&
./2.out &&
./3.out
