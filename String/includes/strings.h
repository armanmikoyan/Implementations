#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>

#define STACK_SIZE 16

class String
{
public:
	String(); 
	String(const char*); 
	String(const String& oth); 
	String(String&&) noexcept;
	String& operator=(const String&); 
	String& operator=(String&&) noexcept;
	friend std::ostream& operator<<(std::ostream&,const String&); 

public:
	String& operator=(const char*);
	String operator+(const char*); 
	String operator+(const String&); 
	char& operator[](size_t); 
	~String();  

private:
	static size_t length(const char*);   //helper

private:
	char onstack[STACK_SIZE];
	char* m_string;
	size_t m_size;
	size_t m_cap;
};
#endif // STRINGS_H