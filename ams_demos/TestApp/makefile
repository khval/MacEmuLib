
c=g++

p =../
basedir += ${p}${p}

libdir = -L ${p}${p}lib/

libs = -lMacEmu -lTCLEmu

incdir += -I $(p)
incdir += -I $(basedir)libMacEmu
incdir += -I $(basedir)libTCLEmu

files += desktop.cpp
files += display.cpp
files += fullscreen.cpp
files += fullscreen_port.cpp
files += fullscreen_QT.cpp

name = test

objs = ${files:.cpp=.o}

opts += -D__USE_INLINE__ 
opts += -Dpascal=
opts += -D_CLASSDEF(x)= 
opts += -Dfarcalloc=calloc 
opts += -Dfarrealloc=realloc
opts += -DTARGET_CPU_68K=0
opts += -DTARGET_API_MAC_CARBON=0

all:	$(objs)
	$(c) ${incdir} ${libdir} $(opts) $(name).cpp $(objs) $(libs) -o $(name)


%.o:	%.cpp
		g++ -c ${incdir} ${libdir} $(opts)  $< -o $@

clean:
	rm  $(objs) $(name)

