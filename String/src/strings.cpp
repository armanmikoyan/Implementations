#include "strings.h"

size_t String::length(const char* chars){
	size_t count{0};
	while(*chars != '\0') {
		++count;
		++chars;
	}
	return count;
}

String::String() 
	: m_string{onstack} 
	, m_size{0}
	, m_cap{STACK_SIZE - 1}
{
}

String& String::operator=(String&& rhs) noexcept 
{
	if (this != &rhs)
	{
		if (m_string != onstack)
		{
            delete m_string;
        }
		m_cap = rhs.m_cap;
        m_size = rhs.m_size;
        m_string = rhs.m_string;
		rhs.m_cap = 0;
        rhs.m_size = 0;
        rhs.m_string = onstack;
	}

	return *this;
}

String::String(String&& rhs) noexcept
{	
	m_cap = rhs.m_cap;
	m_size = rhs.m_size;
	m_string = rhs.m_string;

	rhs.m_cap = 0;
	rhs.m_size = 0;
	rhs.m_string = nullptr;
}

String::String(const char* rhs) 
	: String() 
{
	if(!(length(rhs) < m_cap))
	{
		m_cap = length(rhs);
		m_string = new char[m_cap];		
	}	
	while(*(rhs) != '\0') {
		m_string[m_size++] = *rhs;
		rhs++;
	}
	m_string[m_size] = '\0';
}

String::String(const String& oth) 
	: String() 
{
	m_cap = oth.m_cap;
	m_size = oth.m_size;
	if(!(oth.m_cap <= STACK_SIZE))
	{
		m_string = new char[m_cap];	
	}
	for(size_t i = 0; i < oth.m_size; ++i) {
		m_string[i] = oth.m_string[i];
	}
	m_string[m_size] = '\0';
}

String& String::operator=(const char* literal)
{
	if(m_cap >= STACK_SIZE)
	{
		if(m_cap < length(literal))
		{
			delete[] m_string;
			m_string = new char[length(literal)];
		}	
	}
	else
	{	
		if(length(literal) > STACK_SIZE)
		{
			m_string = new char[length(literal)];
		}
	}
	m_cap = length(literal);
	m_size = 0;
	for(size_t i = 0; i < length(literal); ++i) {
		m_string[m_size++] = literal[i];
	}
	m_string[m_size] = '\0';
	return *this;
}

String& String::operator=(const String& rhs)
{
	if(m_cap >= STACK_SIZE)
	{
		if(m_cap < rhs.m_cap)
		{
			delete[] m_string;
			m_string = new char[rhs.m_cap];
		}	
	}
	else
	{	
		if(rhs.m_cap > STACK_SIZE)
		{
			m_string = new char[rhs.m_cap];
		}
	}
	m_cap = rhs.m_cap;
	m_size = 0;
	for(size_t i = 0; i < rhs.m_size; ++i) {
		m_string[m_size++] = rhs.m_string[i];
	}
	m_string[m_size] = '\0';
	return *this;
}

String String::operator+(const char* str)
{
	String tmp = *this;
	if(tmp.m_cap >= STACK_SIZE)
	{
		if(tmp.m_size + length(str) > tmp.m_cap)
		{
			delete[] tmp.m_string;
			tmp.m_string = new char[tmp.m_size + length(str)];
		}
	}
	else
	{
		if(tmp.m_size + length(str) >= STACK_SIZE)
		{
			tmp.m_string = new char[tmp.m_size + length(str)];
		}
	}
	tmp.m_size = 0;
	tmp.m_cap = m_size + length(str);
	for(size_t i = 0; i < m_size; ++i) {
		tmp.m_string[tmp.m_size++] = this->m_string[i];
	}
	for(size_t i = 0; i < length(str); ++i) {
		tmp.m_string[tmp.m_size++] = str[i];
	}
	return tmp;
}

String String::operator+(const String& oth)
{
	String tmp = *this;
	if(tmp.m_cap >= STACK_SIZE)
	{
		if(tmp.m_size + oth.m_size > tmp.m_cap)
		{
			delete[] tmp.m_string;
			tmp.m_string = new char[tmp.m_size + oth.m_size];
		}
	}
	else
	{
		if(tmp.m_size + oth.m_size >= STACK_SIZE)
		{
			tmp.m_string = new char[tmp.m_size + oth.m_size];
		}
	}
	tmp.m_size = 0;
	tmp.m_cap = m_size + oth.m_size;
	for(size_t i = 0; i < m_size; ++i) {
		tmp.m_string[tmp.m_size++] = this->m_string[i];
	}
	for(size_t i = 0; i < oth.m_size; ++i) {
		tmp.m_string[tmp.m_size++] =oth.m_string[i];
	}
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.m_string;
    return os;
}

char& String::operator[](size_t idx)
{
	if(idx < 0 || idx >= m_size)
	{
		  std::cerr << "range error: ";
	}
	return m_string[idx];
}

String::~String()
{
	if (length(m_string) >= STACK_SIZE)
	{
		delete m_string;
	}
		
}























