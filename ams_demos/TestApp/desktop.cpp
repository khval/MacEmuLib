/*
	desktop.cc
	----------
*/

#ifndef __amigaos4__

#include "desktop.hh"

// Mac OS X
#ifdef __APPLE__
#include <Carbon/Carbon.h>
#endif

// Mac OS
#ifndef __LOWMEM__
#include <LowMem.h>
#endif
#ifndef __MACWINDOWS__
#include <MacWindows.h>
#endif

#endif

#ifdef __amigaos4__
#include "libMacEmu.h"
#include "missing.h"

extern void LMSetDeskPattern( const Pattern *pattern );
extern GrafPort *LMGetWMgrPort();
extern void PaintOne( void *, RgnHandle visRgn );

#endif

void set_desktop_pattern( const Pattern& pattern )
{
#if ! TARGET_API_MAC_CARBON
	
	LMSetDeskPattern( &pattern );
	
	PaintOne( NULL, LMGetWMgrPort()->visRgn );
	
#endif
}
