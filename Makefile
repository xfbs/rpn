# target all (default):
# generate article into index.pdf, using lualatex, pack up source code files
# into a zip file
#
# for zip file creation, uses -X option to disable extended attributes — this
# means we don't store access time, which allows for reproducible zip files
# (somewhat).
#
# target build:
# build the example source code. needs to have cmake and a compiler installed.
# output goes to rpn-calc/build.
#
# target release.pdf:
# build release pdf file which is also a zip archive of the source/example code
# needs to have truepolyglot, provide the path to it via the POLYGLOT env var.

LATEX	= lualatex
MKDIR	= mkdir -p
CMAKE	= cmake
RM		= rm -rf
FILES	= $(shell git ls-files "*.md" "*.tex" "*.cpp" "*.txt" "*.h" "Makefile") _tag.tex
ZIP		= zip -X
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
	$(RM) release.pdf
