# MacEmuLib

This project contains a a few .c files to emulate some of MacOS 7.x.x toolbox features, 
the project also contains ThinkC examples converted for use with GNUC, for testing of the library.

The aim of this project is make it not too hard to port or convert MacOS7.x.x programs, so that they will run on AmigaOS4.x.

The approach to this project is kind ad-hok, no practical strategy, everything is loosely proto typed, the assumption I work by everything is correct until its not, then I refabricate code, to make it fit, this project is pretty much about fitting a square inside circle. the assumption is that examples are always correct, and fault is always inside the library if something is broken, all examples in the project should also be compilable on MacOS 7.x.x.

# License

Anyway this project will fall under MIT License with exceptions.

The Intended use is for libMacEmu is to be compiled into your projects, so you are allowed to use it commercially or none commercially. 

# Other License's

The AMS (Advanced Macintosh Substitution project)  Demos are under GPLv3 license, and can’t be used commercially.
(only demos are included, so that this files do not pollute the lib’s.)

As for the Symantic examples you should not use this commercially. I can’t and do not grant you right to sell other people’s work.
(if it turns out I was mistaken to includes these files, then I will remove these files from the project and reupload the project without.)

I’m assuming that Symantec examples where to allow beginner to get started, so I guess its ok to copy to modify and share, but it does not really say if you can use this commercially or not. Think C is publicly available on Macintosh repositories and manual, can also be found in PDF format, because Symantec has not asked these files to be removed, I assume its abandoned. The product (Think C) is from 1991, and is not really relevant today. I doubt they care anymore. (just because it abandoned does not mean they are not the copyright holders; they can ask to have these files removed.)

Old useful manuals and documentation can be found here:

https://vintageapple.org/macprogramming/

# Another projects of interest.

TCL – ToolBox Class Library was developed for Macintosh and was originally Pascal library, and fundamental part of GUI used on the Classic MacOS, predating MacOSX, TCL should not be confused by another TCL/Tk, (TCL/Tk is short for Tool Command Language that has its history in BSD  in 1988), the aim here is try to implement a subset of TCL – Tool Box Class Library, the idea here is create set of minimum classes for tutorial examples to work on AmigaOS4.1 Operating system. These days TCL is abandoned, and it was before YouTube was thing, so there are no videos that talk about it, luckily there is lot of Books in PDF format, floating around.

So I have googled around to find if someone done something similar, pulling resources from other project can speed up this project, or solve mysteries, I need to guess.

So I have found few projects, woolshed, has come close, it’s under GPL, the developer’s  aim is different as he choice GPL, because he did not wont recompile programs, but also emulated the PowerPC in MacOS8/9, clearly we want LGPL or MIT, as this allow it to be linked to other programs with different licenses.  Last change on his project was two years ago. Maybe he got stuck think about how to make Toolbox work as QT.

The “Advanced Mac Substitute» project, this project can be of interests it is however lacking in some areas, no support for resource files, as I’m writing this, maybe some of that are in the OS it boots, not in replacement rom, but project has some interesting test programs. It has GPL3.0 license, that prohibits, including any part of it into LibMacEmu as its going to be static linked into other projects, clearly, they never intended AMS to be used as a library.

Another project keeps popping up is Motif, I wonder how related it is to ToolBox, was it inspired by it, or the other way around? I have not really taken the time to read the manual and header files and compare.

Carbon is closed source and part of MacOSX, so that’s useless to this project.

Regarding resource files, there are projects for unpacking or extracting these files, but problem they not always written to be used as the original, some are in other language’s like phyton.




Best Regards
Kjetil
