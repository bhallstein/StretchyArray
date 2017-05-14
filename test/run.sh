set -e

for f in *.cpp; do
	clang++ $f -std=c++11 -o out
	./out
	rm out
done

for f in *.c; do
	clang $f -o out
	./out
	rm out
done
