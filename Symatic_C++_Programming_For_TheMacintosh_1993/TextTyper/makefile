
c=g++

p =../

libdir = -L ${p}${p}lib/

libs = -lMacEmu

incdir += -I $(p) -I ./
incdir += -I ${p}${p}

files += ../missing.cpp		# i think this was is called TCL in the book.
files += ../CApplication.cpp
files += ../CDocument.cpp
files += ../CDecorator.cpp
files += ../CScrollPane.cpp
files += ../CEditText.cpp
files += ../CDataFile.cpp
files += ../CView.cpp
files += CTextDoc.cpp
files += CTextApp.cpp

name = TextTyper

objs = ${files:.cpp=.o}

opts += -D__USE_INLINE__ 
opts += -Dpascal=
opts += -D_CLASSDEF(x)= 
opts += -Dfarcalloc=calloc 
opts += -Dfarrealloc=realloc
opts += -DENDTRY=

all:	$(objs)
	$(c) ${incdir} ${libdir} $(opts) $(name).cpp $(objs) $(libs) -o $(name)


%.o:	%.cpp
		g++ -c ${incdir} ${libdir} $(opts)  $< -o $@

clean:
	rm $(objs) $(name)

