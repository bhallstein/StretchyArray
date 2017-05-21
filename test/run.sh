#
# run.sh [extra-c++-compiler flags] [yn](memcheck)
#

set -e

CCFLAGS=''
memcheck='n'
if [ `uname` = 'Linux' ]; then CCFLAGS='-lstdc++'; fi
if [ $# -gt 0 ]; then memcheck=$1; fi

cd ${0%/*}

compile_and_run() {
  if [ $# -ne 2 ]; then
    echo "?"
  else
    f=$1
    f_out="$f.out"
    compile_cmd=$2
    $compile_cmd $f -o $f_out
    "./$f_out"
    if [ $memcheck = 'y' ]; then
      valgrind ./$f_out
    fi
    rm "$f_out"
  fi
}

for f in *.cpp; do
  compile_and_run $f "clang++ $CCFLAGS -std=c++11"
done

for f in *.c; do
  compile_and_run $f clang
done
