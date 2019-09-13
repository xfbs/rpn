LATEX	= lualatex
MKDIR	= mkdir -p
CMAKE	= cmake
RM		= rm -rf
FILES	= $(shell find -E . -regex ".*\.(txt|tex|cpp|h|md)")
ZIP		= zip
GIT		= git
POLYGLOT= truepolyglot

all: index.pdf index.zip

build: calc

index.pdf: index.tex
	$(GIT) tag > _tag.tex
	$(LATEX) --shell-escape $<
	$(LATEX) --shell-escape $<

index.zip: $(FILES) index.pdf
	$(ZIP) $@ $^

release.pdf: index.pdf index.zip

calc: calc/build/calc-cli

calc/build/calc-cli: calc/build/Makefile
	$(CMAKE) --build calc/build

calc/build/Makefile:
	$(MKDIR) calc/build
	$(CMAKE) -S calc -B calc/build

clean:
	$(RM) _tag.tex
	$(RM) *.aux
	$(RM) *.toc
	$(RM) *.log
	$(RM) *.out
	$(RM) calc/build
	$(RM) parse/build

.PHONY: calc
