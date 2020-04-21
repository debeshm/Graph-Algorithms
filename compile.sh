
dir=out

if [[ ! -e $dir ]]; then
	echo "creating output directory $out"
	mkdir $dir
elif [[ ! -d $dir ]]; then
	echo "$dir already exists"
fi

echo "compiling"

gcc src/graph.c -o out/graph.out

echo "completed compiling"
