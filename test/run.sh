set -e

compile_and_run() {
  if [ $# -ne 2 ]; then
		echo "?"
	else
		f=$1
		f_out="$f.out"
		compile_cmd=$2
		$compile_cmd $f -o $f_out
		"./$f_out"
		rm "$f_out"
	fi
}

for f in *.cpp; do
	compile_and_run $f "clang++ -std=c++11"
done

for f in *.c; do
	compile_and_run $f clang
done
