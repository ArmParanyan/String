#include <ostream>

#include "string.h"

String::String() {
    m_size = 0;
    m_capacity = 1;
    m_string = new char[m_capacity];
    m_string[m_size] = '\0';
}

String::String(char* oth) {
    if (oth == nullptr) {
        m_string = new char[m_capacity];
        m_string[0] = '\0';
    }

    m_size = get_length(oth);
    m_string = new char[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_string[i] = oth[i];
    }
    m_string[m_size] = '\0';
}

String::String(const String& oth) {
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
    m_string = new char [m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_string[i] = oth.m_string[i];
    }
    m_string[m_size] = '\0';
}

String::String(String&& rhs) {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_string = rhs.m_string;

    rhs.m_size = {};
    rhs.m_capacity = {};
    rhs.m_string = {};
}

String::~String() {
    m_capacity = {};
    m_size = {};
    delete[] m_string;
    m_string = nullptr;
}

void String::resize() {
    m_capacity *= 2;
    char* tmp = new char[m_capacity];
    for (int i = 0; i < m_capacity; ++i) {
        tmp[i] = m_string[i];
    }
    delete[] m_string;
    m_string = tmp;
}

void  String::push_back(char symb) {
    if (m_size == m_capacity) {
        resize();
    }
    m_string[m_size] = symb;
    ++m_size;
    m_string[m_size] = '\0';

}

int String::get_length(char* str) {
    int size = 0;
    while (str[size] != '\0') {
        ++size;
    }
    return size;
}

void String::pop_back() {
    if (0 == m_size) {
        std::cout << "String is empty";
        return;
    }
    char* tmp = new char[m_capacity];
    for (int i = 0; i < m_size - 1; ++i) {
        tmp[i] = m_string[i];
    }
    delete[] m_string;
    m_string = tmp;
    m_string[m_size] = '\0';
    ++m_size;
}

int String::_capacity() { 
    return m_capacity;
}

int String::_size() {
    return m_size;
}

String& String::operator=(String&& rhs) {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    delete m_string;
    m_string = rhs.m_string;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
    rhs.m_string = nullptr;
    return *this;
}

String& String::operator=(const String& rhs) {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    for (int i = 0; i < this->m_size; ++i)
    {
        m_string[i] = rhs.m_string[i];
    }
    return *this;
}

String String::operator+(const String& rhs) {
    String tmp;
    tmp.m_size = m_size + rhs.m_size;
    if (tmp.m_size >= m_capacity)
    {
        resize();
    }
    for (int i = 0; i < this->m_size; ++i)
    {
        tmp.m_string[i] = this->m_string[i];
    }
    for (int i = m_size,j = 0; i < tmp.m_size; ++i)
    {
        tmp.m_string[i] = rhs.m_string[j++];
    }
    return tmp;
}

String& String::operator+=(const String& rhs) {
    int tmp_size = m_size;
    m_size = m_size + rhs.m_size;
    if (m_size >= m_capacity)
    {
        resize();
    }
    for (int i = tmp_size,j = 0; i < m_size; ++i)
    {
        m_string[i] = rhs.m_string[j++];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, String& obj) {
    for (int i = 0; obj.m_string[i] != '\0'; ++i) {
            os << obj.m_string[i];
        }
        return os;
}