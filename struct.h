#ifndef STRUCT
#define STRUCT
struct Sentence {
	wchar_t* Sent;
	size_t sentLenght;
};

struct Text {
	struct Sentence *sentences;
	size_t buffLenght;
};
#endif
