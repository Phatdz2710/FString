#include "FString.h"

#pragma region CONSTRUCTORS AND DESTRUCTOR
FString::FString() : m_Size(0)
{
	this->m_Data = new char[m_Size+1];
	this->m_Data[0] = '\0';
}

//Copy Constructor
FString::FString(const FString& other) : m_Size(other.m_Size)
{
	//Allocate memory for m_Data
	this->m_Data = new char[m_Size + 1];
	//Copy the data from other to this
	for (int i = 0; i <= m_Size; i++)
	{
		this->m_Data[i] = other.m_Data[i];
	}
}

FString::FString(const char* str)
{
	//Get the size of the str
	int sz = strlen(str);
	//Set m_Size
	this->m_Size = sz;
	//Allocate memory for m_Data
	this->m_Data = new char[m_Size + 1];
	//Copy the str to m_Data
	for (int i = 0; i <= m_Size; i++)
	{
		this->m_Data[i] = str[i];
	}
}

FString::~FString()
{
	delete[] m_Data;
}

#pragma endregion

#pragma region OPERATORS
FString& FString::operator=(const FString& other)
{
	//Check if the other FString is the same as this
	if (*this == other) return *this;
	//Delete the current m_Data
	delete[] m_Data;
	//Set the m_Size
	this->m_Size = other.m_Size;
	//Allocate memory for m_Data
	this->m_Data = new char[m_Size + 1];
	//Copy the data from other to this
	for (int i = 0; i <= m_Size; i++)
	{
		this->m_Data[i] = other.m_Data[i];
	}

	return *this;
}

FString& FString::operator=(const char* str)
{
	delete[] m_Data;
	//Get the size of the str
	int sz = 0;
	for (; str[sz] != '\0'; sz++);
	//Set m_Size
	this->m_Size = sz;
	//Allocate memory for m_Data
	this->m_Data = new char[sz + 1];
	//Copy the str to m_Data
	for (int i = 0; i <= sz; i++)
	{ 
		this->m_Data[i] = str[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream & os, const FString & str)
{
	os << str.m_Data;
	return os;
}

std::istream& operator>>(std::istream & is, FString & str)
{
	char buffer[256];
	is >> buffer;
	str = buffer;
	return is;
}

bool FString::operator==(const FString& other) const
{
	//Check if the sizes are the same
	if (this->m_Size != other.m_Size) return false;

	//Check if the data is the same 
	for (int i = 0; i < m_Size; i++)
	{
		if (this->m_Data[i] != other.m_Data[i]) return false;
	}

	return true;
}

bool FString::operator==(const char* str) const
{
	//Get the size of the str
	int sz = 0;
	for (; str[sz] != '\0'; sz++);

	//Check if the sizes are the same
	if (this->m_Size != sz) return false;
	//Check if the data is the same
	for (int i = 0; i < m_Size; i++)
	{
		if (this->m_Data[i] != str[i]) return false;
	}
	
	return true;
}

bool operator==(const char* str, const FString& other)
{
	return (other == str);
}

bool FString::operator!=(const FString& other) const
{
	return !(*this == other);
}

bool FString::operator!=(const char* str) const
{
	return !(*this == str);
}

bool operator!=(const char* str, const FString& other)
{
	return !(other == str);
}

char& FString::operator[](size_t index) const
{
	int t = index;
	//Check if the index is out of bounds
	if (t < 0)
	{
		int x = (m_Size - t - 1) / m_Size;
		t += x * m_Size;
	}
	else if (t >= m_Size)
	{
		int x = t / m_Size;
		t -= x * m_Size;
	}

	return m_Data[t];
}

FString FString::operator+(const FString& other) const
{
	//Create new FString and copy the data from this to it
	FString newFstr;
	//Set the size of the new FString
	newFstr.m_Data = new char[m_Size + other.m_Size + 1];
	
	//Copy the data from this to the new FString
	newFstr.m_Size = m_Size + other.m_Size;
	int pos = 0;
	for (; pos < m_Size; pos++)
	{
		newFstr.m_Data[pos] = m_Data[pos];
	}

	for (; pos <= m_Size + other.m_Size; pos++)
	{
		newFstr.m_Data[pos] = other.m_Data[pos - m_Size];
	}

	return newFstr;
}

FString FString::operator+(const char* str) const
{
	//Get size of str
	int sz = 0;
	for (; str[sz] != '\0'; sz++);
	
	//Set the size of the new FString
	FString newFstr;
	newFstr.m_Data = new char[m_Size + sz + 1];
	newFstr.m_Size = m_Size + sz;

	//Copy the data from this to the new FString
	int pos = 0;
	for (; pos < m_Size; pos++)
	{
		newFstr.m_Data[pos] = m_Data[pos];
	}

	for (; pos <= m_Size + sz; pos++)
	{
		newFstr.m_Data[pos] = str[pos - m_Size];
	}

	return newFstr;
}

FString operator+(const char* str, const FString& other)
{
	//Get size of str
	int sz = 0;
	for (; str[sz] != '\0'; sz++);
	//Create new FString
	FString newFstr;
	newFstr.m_Data = new char[sz + other.m_Size + 1];
	newFstr.m_Size = sz + other.m_Size;
	
	//Copy the data from str to the new FString
	int pos = 0;
	for (; pos < sz; pos++)
	{
		newFstr.m_Data[pos] = str[pos];
	}

	//Copy the data from other to the new FString
	for (; pos <= sz + other.m_Size; pos++)
	{
		newFstr.m_Data[pos] = other.m_Data[pos - sz];
	}

	return newFstr;
}

FString& FString::operator+=(const FString& other)
{
	//Create new FString
	FString newFstr;
	newFstr = (*this) + other;
	*this = newFstr;
	return *this;
}

FString& FString::operator+=(const char* str)
{
	//Create new FString
	FString newFstr;
	newFstr = (*this) + str;
	*this = newFstr;
	return *this;
}
#pragma endregion

#pragma region FUNCTIONS
size_t FString::size() const
{
	return m_Size;
}

void FString::clear()
{
	delete[] m_Data;
	m_Size = 0;
	m_Data = new char[m_Size + 1];
	m_Data[0] = '\0';
}

bool FString::empty() const
{
	return (m_Size == 0);
}

const char* FString::c_str() const
{
	return m_Data;
}

void FString::erase(size_t pos)
{
	//Check if the pos is out of bounds
	if (pos < 0 || pos >= m_Size) return;

	//New FString
	FString newFstr;
	newFstr.m_Data = new char[m_Size];
	newFstr.m_Size = m_Size - 1;

	//Copy the data from this to the new FString
	int i = 0;
	for (; i < pos; i++)
	{
		newFstr.m_Data[i] = m_Data[i];
	}
	for (; i < m_Size; i++)
	{
		newFstr.m_Data[i] = m_Data[i + 1];
	}
	
	*this = newFstr;
}

void FString::erase(size_t pos, size_t sz)
{
	if (pos < 0 || pos >= m_Size) return;
	if (sz <= 0) return;
	if (pos + sz >= m_Size) sz = m_Size - pos;

	//New FString
	FString newFstr;
	newFstr.m_Data = new char[m_Size - sz + 1];
	newFstr.m_Size = m_Size - sz;

	//Copy the data from this to the new FString
	int i = 0;
	for (; i < pos; i++)
	{
		newFstr.m_Data[i] = m_Data[i];
	}

	for (; i <= m_Size - sz; i++)
	{
		newFstr.m_Data[i] = m_Data[i + sz];
	}

	*this = newFstr;
}

FString FString::substr(size_t pos, size_t sz) const
{
	if (pos < 0 || pos >= m_Size) return "";
	if (sz <= 0) return "";

	if (pos + sz >= m_Size) sz = m_Size - pos;

	//New FString
	FString newFstr;
	newFstr.m_Data = new char[sz + 1];
	newFstr.m_Size = sz;

	//Copy the data from this to the new FString
	for (int i = 0; i < sz; i++)
	{
		newFstr.m_Data[i] = m_Data[i + pos];
	}

	newFstr.m_Data[sz] = '\0';
	return newFstr;
}

void FString::insert(size_t pos, const char* str) 
{
	if (pos < 0 || pos > m_Size) return;

	//New FString
	FString left = substr(0, pos);
	FString right = substr(pos, m_Size - pos + 1);
	FString newFstr = left + str + right;

	*this = newFstr;
}

#pragma endregion