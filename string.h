#include <ostream>

class String
{
public:
    String();
    String(char*);
    String(const String&);
    String(String&&);
    ~String();
public:
    String& operator=(const String&);
    String& operator=(String&&);
    String operator+(const String&);
    String& operator+=(const String&);
    friend std::ostream& operator<<(std::ostream&, String&);
public:
    void push_back(char);
    int get_length(char*);
    void pop_back();
    void resize();
    int _capacity();
    int _size();
    
private:
    char* m_string;
    int m_size;
    int m_capacity;
};