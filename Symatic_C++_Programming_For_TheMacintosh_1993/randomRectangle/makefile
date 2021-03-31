
c=g++

p =../

libdir = -L ${p}${p}lib/

libs = -lMacEmu

incdir += -I $(p)
incdir += -I ${p}${p}

files += missing.cpp
files += TRandom.cpp
files += CRectangleApp.cpp
files += CRandomRectanglePane.cpp

name = randomRectangle

objs = ${files:.cpp=.o}

opts += -D__USE_INLINE__ 
opts += -Dpascal=
opts += -D_CLASSDEF(x)= 
opts += -Dfarcalloc=calloc 
opts += -Dfarrealloc=realloc

all:	$(objs)
	$(c) ${incdir} ${libdir} $(opts) randomRectangle.cpp $(objs) $(libs) -o $(name)


%.o:	%.cpp
		g++ -c ${incdir} ${libdir} $(opts)  $< -o $@

clean:
	rm $(objs) $(name)

