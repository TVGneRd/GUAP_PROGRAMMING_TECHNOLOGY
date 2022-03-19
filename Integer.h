class Integer{

	friend Integer& operator++(Integer& integer);
	friend Integer operator++(Integer &integer, int);

public:
	Integer(int number) { this->number = number; };
	Integer() { number = 0; };

	Integer& operator--();       // Prefix decrement operator.
	Integer operator--(int);     // Postfix decrement operator.

	int operator!();
	int getData();

private:
	int number;
};