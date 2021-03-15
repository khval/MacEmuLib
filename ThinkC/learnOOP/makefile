
p =../
incdir += -I ${p}${p}
libdir = -L ${p}${p}lib/
libs = -lMacEmu

deps += learnOOPShapes.c
deps += windowUtils.c

objs = ${deps:.c=.o}

name = LearnOOP
name_c = $(name).c
name_exe = $(name).exe

opts = -D__USE_INLINE__

all:	$(objs)
	g++ ${incdir} ${libdir} $(opts) $(name_c) $(objs) $(libs) -o $(name_exe)


%.o:	%.c
		g++ -c ${incdir} ${libdir} $(opts) $< -o $@

clean:
	rm $(objs) $(name_exe)

