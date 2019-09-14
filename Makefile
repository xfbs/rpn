LATEX	= lualatex
MKDIR	= mkdir -p
CMAKE	= cmake
RM		= rm -rf
FILES	= $(shell find rpn-calc/src rpn-calc/include rpn-parse/src rpn-parse/src)
FILES	= $(shell git ls-files "*.md" "*.tex" "*.cpp" "*.txt" "*.h" "Makefile") _tag.tex
ZIP		= zip
GIT		= git
POLYGLOT= ../truepolyglot/truepolyglot

all: index.pdf index.zip

build: rpn-calc/build/calc-cli rpn-gen

index.pdf: index.tex _tag.tex
	$(LATEX) --shell-escape $<
	$(LATEX) --shell-escape $<

index.zip: $(FILES)
	$(ZIP) $@ $^

release.pdf: index.pdf index.zip
	$(POLYGLOT) pdfzip --pdffile index.pdf --zipfile index.zip $@

rpn-calc/build/calc-cli: rpn-calc/build/Makefile
	$(CMAKE) --build rpn-calc/build

rpn-calc/build/Makefile:
	$(MKDIR) rpn-calc/build
	$(CMAKE) -S rpn-calc -B rpn-calc/build

_tag.tex:
	$(GIT) tag > $@

clean:
	$(RM) _tag.tex
	$(RM) *.aux
	$(RM) *.toc
	$(RM) *.log
	$(RM) *.out
	$(RM) calc/build
	$(RM) parse/build
	$(RM) index.zip
	$(RM) _minted-index
