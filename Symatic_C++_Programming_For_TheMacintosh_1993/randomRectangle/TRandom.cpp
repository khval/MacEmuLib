
#include "TRandom.h"

#ifdef __amigaos4__
#include <time.h>
#endif

TRandom::TRandom()
{
#ifdef __amigaos4__
	fValue = time(0);
#else
	fValue = ::TicketCount();
#endif
}

TRandom::TRandom(unsigned long seed)
{
	fValue = seed;
}

unsigned long TRandom::value()
{
	return fValue;
}

unsigned long TRandom::valueInRange( unsigned long low, unsigned long high )
{
	return (value() % (high - low + 1)) + low;
}

void TRandom::advance()
{
	fValue = fValue * 12345 + 6789;
}

