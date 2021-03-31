
class TRandom
{
	public:
		TRandom();
		TRandom(unsigned long seed);

		void advance();
		unsigned long value();
		unsigned long valueInRange(unsigned long low, unsigned long high);
	
	private:
		unsigned long fValue;
};


