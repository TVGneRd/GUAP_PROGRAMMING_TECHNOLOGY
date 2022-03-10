class StackElement{
public:
	StackElement(int data, StackElement *prev);
	StackElement(const StackElement &stackElement);

	~StackElement();
	int getData();
	StackElement* getPrev();
	void setPrev(StackElement* prev);

private:
	int data;
	StackElement *prev;
};