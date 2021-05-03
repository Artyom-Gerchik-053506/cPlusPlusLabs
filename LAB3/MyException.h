// ---------------------------------------------------------------------------

#ifndef MyExceptionH
#define MyExceptionH

#include "SysUtils.hpp"

class nullStudentsException : public Exception {
protected:
	UnicodeString exceptionName;

public:
	nullStudentsException(const UnicodeString &exceptionName)
		: Exception(exceptionName) {
		this->exceptionName = exceptionName;
	}

	virtual UnicodeString getName() {
		return exceptionName;
	}

};

class incorrectMarksException : public nullStudentsException {
protected:
	UnicodeString exceptionName;

public:
	incorrectMarksException(const UnicodeString &exceptionName)
		: nullStudentsException(exceptionName) {
		this->exceptionName = exceptionName;
	}

};

class incorrectAVGMarkException : public nullStudentsException {
protected:
	UnicodeString exceptionName;

public:
	incorrectAVGMarkException(const UnicodeString &exceptionName)
		: nullStudentsException(exceptionName) {
		this->exceptionName = exceptionName;
	}

};

// ---------------------------------------------------------------------------
#endif
