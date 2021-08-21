pdf: report.pdf

report.pdf: figures report.tex paper.bib
	xelatex -pdf -shell-escape report.tex

figures: *.svg
	inkscape -D blockSize_1B.svg -o blockSize_1B.pdf --export-latex
	inkscape -D blockSize.svg -o blockSize.pdf --export-latex

.PHONY: clean
clean:
	latexmk -c && rm -rf report.synctex.gz && rm -f report.bbl
	rm -rf _minted-report
	rm -f report.pdf
	rm -f *.pdf_tex
