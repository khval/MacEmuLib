

p =../
incdir += -I ./

files += Resources.cpp
files += libMacEmu.cpp
files += penAndLineDrawing.cpp
files += textDrawing.cpp
files += menu.cpp
files += pathTranslate.cpp
files += vector_array.cpp

files_o = ${files:.cpp=.o}

libDir = lib/
libName = libMacEmu.a

opts = -D__USE_INLINE__

all:	  $(libName)	$(test_elfs)

$(libName): $(files_o)
	ar rcs $(libDir)$@ ${files_o}

%.o:	%.cpp
		g++ -c ${incdir} ${libdir} $(opts) $< $(libs) -o $@

clean:
	rm $(files_o) $(libDir)$(libName)

