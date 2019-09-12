LATEX	= lualatex
MKDIR	= mkdir -p
CMAKE	= cmake
RM		= rm -rf

all: index.pdf

index.pdf: index.tex
	$(LATEX) --shell-escape $<

calc: calc/build/calc-cli

calc/build/calc-cli: calc/build/Makefile
	$(CMAKE) --build calc/build

calc/build/Makefile:
	$(MKDIR) calc/build
	$(CMAKE) -S calc -B calc/build

clean:
	$(RM) *.aux
	$(RM) *.toc
	$(RM) *.log
	$(RM) *.out
	$(RM) calc/build
	$(RM) parse/build

.PHONY: calc
