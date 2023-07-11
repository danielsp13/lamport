DOC := proyecto.tex

all: docs

docs: $(DOC:.tex=.pdf)

all: proyecto.pdf

%.pdf: %.tex FORCE
	pdflatex $< && bibtex $* && pdflatex $< && pdflatex $<

FORCE: 


