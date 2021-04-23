#!/bin/bash
shopt -s globstar
for ind in **/index; do
	dir=$(dirname "$ind")
	rm -f "$dir"/*.md5hash
	for f in "$dir"/*; do
		[[ -f "$f" ]] || continue
		sed -e 's#\/\/.*##' "$f" | tr -s '\n\t ' ' ' | md5sum | head -c 8 > "$f".md5hash
	done
done
bundle install
bundle exec jekyll build
sed -ie 's/{VERSION}/'$(git describe --tags)'/' _site/markdown-tpl.txt
mkdir -p sudoku
./createlpsudoku -i <(qqwing --generate 26 --one-line --difficulty expert) | csplit -b '%d.tex' -f sudoku/ - '/^$/' '{*}'
pandoc --pdf-engine=xelatex --listings --toc --number-sections -s -f markdown -o codebook.pdf _site/markdown-tpl.txt
