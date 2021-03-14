
p =../
incdir = -I ${p}${p}shockmac/ShockMac/Libraries/
incdir += -I ../

libdir = -I ${p}${p}shockmac/ShockMac/LIB/

deps += ${p}emuMac.c
deps += learnOOPShapes.c
deps += windowUtils.c


objs = ${deps:.c=.o}

name = LearnOOP
name_c = $(name).c
name_exe = $(name).exe

opts = -D__USE_INLINE__

all:	$(objs)
	g++ ${incdir} ${libdir} $(opts) $(name_c) $(objs) -o $(name_exe)


%.o:	%.c
		g++ -c ${incdir} ${libdir} $(opts) $< $(libs) -o $@

clean:
	rm $(objs) $(name_exe)