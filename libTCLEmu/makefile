
c=g++

p =../

libdir = -L ${p}lib/

libDir = ../lib/
libName = libTCLEmu.a

incdir += -I $(p) -I ./
incdir += -I ${p}libMacEmu

files += missing.cpp		# i think this was is called TCL in the book.
files += CApplication.cpp
files += CDocument.cpp
files += CDecorator.cpp
files += CScrollPane.cpp
files += CEditText.cpp
files += CDataFile.cpp
files += CView.cpp
files += CWindow.cpp
files += CBureaucrat.cpp
files += CCollaborator.cpp
files += CPane.cpp
files += CDirector.cpp

files_o = ${files:.cpp=.o}

opts += -D__USE_INLINE__ 
opts += -Dpascal=
opts += -D_CLASSDEF(x)= 
opts += -Dfarcalloc=calloc 
opts += -Dfarrealloc=realloc
opts += -DENDTRY=

all:	  $(libName)	$(test_elfs)

$(libName): $(files_o)
	ar rcs $(libDir)$@ ${files_o}


%.o:	%.cpp
		g++ -c ${incdir} ${libdir} $(opts)  $< -o $@

clean:
	rm $(files_o) $(name)

