



p =../
incdir += -I ../

files += pathTranslate_test.c

tests_elfs = ${files:.c=.elf}

libDir = $(p)lib/
libName = libMacEmu.a

opts = -D__USE_INLINE__

libs = -lMacEmu

all:	  $(tests_elfs)

%.elf:	%.c
		gcc ${incdir} -L ${libDir} $(opts) $< $(libs) -o $@

clean:
	rm $(tests_elfs)


