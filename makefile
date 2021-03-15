

p =../
incdir += -I ./

files += libMacEmu.c
files_o = ${files:.c=.o}

libDir = lib/
libName = libMacEmu.a

opts = -D__USE_INLINE__

all:	  $(libName)	$(test_elfs)

$(libName): $(files_o)
	ar rcs $(libDir)$@ ${files_o}

%.o:	%.c
		gcc -c ${incdir} ${libdir} $(opts) $< $(libs) -o $@

clean:
	rm $(files_o) $(libDir)$(libName)

