LATEX	= lualatex

all: index.pdf

index.pdf: index.tex
	$(LATEX) --shell-escape $<
