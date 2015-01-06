#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: main.cpp Song.h Song.cpp Word.h Word.cpp WordList.h \
	WordList.cpp hashfunc.h hashfunc.cpp
	${CXX} ${FLAGS} -o songsearch main.cpp Song.cpp Word.cpp \
	WordList.cpp hashfunc.cpp
	
clean:
	rm -f songsearch

#
# provide is a Tufts University homework delivery system
#

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 main.cpp Song.h Song.cpp Word.h Word.cpp \
	WordList.h WordList.cpp hashfunc.h hashfunc.cpp ReadMe.md Makefile

