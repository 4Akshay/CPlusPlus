#include<iostream>
#include<cstring>

class String
{
private:
	char* mBuffer;
	unsigned int len;
public:
	String() : mBuffer(nullptr), len(0) {};
	String(const char* ptr): len(strlen(ptr))
	{
		mBuffer = new char[len + 1];
		strcpy(mBuffer, ptr);
	}
	String(const String& obj)
	{
		len = obj.len;
		mBuffer = new char[len + 1];
		strcpy(mBuffer, obj.mBuffer);
	}
	String& operator= (const String& obj)
	{
		if (this != &obj)
		{
			len = obj.len;
			delete mBuffer;
			mBuffer = new char[len + 1];
			strcpy(mBuffer, obj.mBuffer);
		}
		return *this;
	}
	String operator+ (const String& obj)
	{
		String temp;
		temp.len = len + obj.len;
		temp.mBuffer = new char[temp.len + 1];
		strcpy(temp.mBuffer, mBuffer);
		strcat(temp.mBuffer, obj.mBuffer);
		return temp;
	}
	String operator+=(const String& obj)
	{
		*this =  *this + obj;
		return *this;
	}
	friend std::ostream& operator << (std::ostream& out, const String& obj)
	{
		int i = 0;
		while (i < obj.len)
		{
			out << obj.mBuffer[i];
			i++;
		}
		return out;
	}
	~String()
	{
		delete[]mBuffer;
		mBuffer = nullptr;
		len = 0;
	}
};

int main()
{
	String s = "hello";
	String s2 = "Akshay";
	s += s2;
	std::cout << s;
	return 0;
}