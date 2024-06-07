#pragma once
#include <iostream>

// My String make by me
class FString
{
private:
	char* m_Data;
	size_t m_Size;

public:
	//Constructor
	FString();

	//Parametrized Constructor
	FString(const char*);
	FString(const FString&);

	//Destructor
	~FString();

#pragma region OPERATORS
	//Operator =
	FString& operator=(const FString&);
	FString& operator=(const char*);

	//Operator +
	FString operator+(const FString&) const;
	FString operator+(const char*) const;
	friend FString operator+(const char*, const FString&);
	
	//Operator +=
	FString& operator+=(const FString&);
	FString& operator+=(const char*);

	//Operator ==
	bool operator==(const FString&) const;
	bool operator==(const char*) const;
	friend bool operator==(const char*, const FString&);

	//Operator !=
	bool operator!=(const FString&) const;
	bool operator!=(const char*) const;
	friend bool operator!=(const char*, const FString&);

	//Operator []
	char& operator[](size_t index) const;

	//Operator <<
	friend std::ostream& operator<<(std::ostream&, const FString&);

	//Operator >>
	friend std::istream& operator>>(std::istream&, FString&);

#pragma endregion

	//Getters
	size_t size() const;

	//Methods
	void clear();
	bool empty() const;
	const char* c_str() const;

	void erase(size_t);
	void erase(size_t, size_t);
	void insert(size_t, const char*);
	FString substr(size_t, size_t) const;
};