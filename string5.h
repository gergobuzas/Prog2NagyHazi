#ifndef STRING_H
#define STRING_H

#include <iostream>

#ifndef MEMTRACE

#endif // MEMTRACE

class String {
    char *pData;
    size_t len;
public:
    size_t size() const { return len; }

    String() :pData(nullptr), len(0) {}

    const char* c_str() const { if (pData) return pData; else return "";}

    String(char ch);

    String(const char *p);

    String(const String& s1);

    ~String() { delete[] pData; }

    String& operator=(const String& rhs_s);

    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }

    bool operator==(const String& rhs_s) {
        if (len == rhs_s.size()){
            for (int i = 0; i < len; ++i) {
                if (pData[i] != rhs_s[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool operator!=(const String& rhs_s) {
        if (len == rhs_s.size()){
            for (int i = 0; i < len; ++i) {
                if (pData[i] == rhs_s[i]){
                    return false;
                }
            }
            return true;
        }
        return true;
    }



    String operator+(const String& rhs_s) const ;

    char& operator[](unsigned int idx);

    const char& operator[](unsigned int idx) const;
};


std::ostream& operator<<(std::ostream& os, const String& s0);

std::istream& operator>>(std::istream& is, String& s0);

inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif

