#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String()
    {
        str = nullptr;
    }
    String(const char *str)
    {
        int length = strlen(str);
        this->str = new char[length+1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
        
    }
    String& operator =(const String &other)
    {
        if(this->str!=nullptr)
        {
            delete[] str;
        }
        int length = strlen(other.str);
        this->str = new char[length+1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';

        return *this;
    }
    String(const String &other)
    {
        if(this->str!=nullptr)
        {
            delete[] str;
        }
        int length = strlen(other.str);
        this->str = new char[length+1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }
    String& operator +(const String &other)
    {
        String newString;
        newString.str = new char [strlen(this->str) + strlen(other.str)+1];
        int i = 0;
        for (; i < strlen(this->str); i++)
        {
            newString.str[i] = this->str[i];
        }
        for (int j = 0; j < strlen(other.str); j++, i++)
        {
            newString.str[i] = other.str[j];
        }
        newString.str[strlen(this->str) + strlen(other.str)] = '\0';
        return newString;
        
    }
    ~String()
    {
        delete [] this->str;
    }
private:
char *str;

};


int main()
{
    String str = "Delicious ";
    String str2 = "Fruit";
    String result = str + str2;
    return 0;
}