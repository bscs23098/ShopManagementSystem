#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String {
private:
    int getlen(const char* array) const {
        if (!array) return 0;
        int len = 0;
        while (array[len] != '\0') {
            len++;
        }
        return len;
    }
    
    int len;
    int cap;
    char* Cs;
    
    int int_size(int Var) const {
        if (Var == 0) return 1;
        if (Var < 0) return int_size(-Var) + 1; 
        int i = 0;
        while (Var > 0) {
            Var /= 10;
            i++;
        }
        return i;
    }

public:
    String() : len(0), cap(1), Cs(new char[1]) {
        Cs[0] = '\0';
    }
    
    String(const char* X) {
        if (!X) {
            len = 0;
            cap = 1;
            Cs = new char[1];
            Cs[0] = '\0';
        } else {
            len = getlen(X);
            cap = len + 1;
            Cs = new char[cap];
            for (int i = 0; i < len; i++) {
                Cs[i] = X[i];
            }
            Cs[len] = '\0';
        }
    }
    
    String(int S, const char X) {
        if (S < 0) S = 0;
        len = S;
        cap = len + 1;
        Cs = new char[cap];
        for (int i = 0; i < len; i++) {
            Cs[i] = X;
        }
        Cs[len] = '\0';
    }
    
    String(int Var) {
        bool negative = (Var < 0);
        if (Var == 0) {
            len = 1;
            cap = 2;
            Cs = new char[cap];
            Cs[0] = '0';
            Cs[1] = '\0';
            return;
        }
        
        if (negative) Var = -Var;
        len = int_size(Var);
        if (negative) len++; 
        
        cap = len + 1;
        Cs = new char[cap];
        Cs[len] = '\0';
        
        int temp_var = Var;
        for (int i = len - 1; i >= (negative ? 1 : 0); i--) {
            int temp = temp_var % 10;
            Cs[i] = temp + '0';
            temp_var /= 10;
        }
        if (negative) {
            Cs[0] = '-';
        }
    }
    String(const String& S) {
        len = S.len;
        cap = S.cap;
        Cs = new char[cap];
        for (int i = 0; i <= len; i++) { 
            Cs[i] = S.Cs[i];
        }
    }
    
    String& operator=(const String& S) {
        if (this == &S) return *this; 
        
        delete[] Cs;
        len = S.len;
        cap = S.cap;
        Cs = new char[cap];
        for (int i = 0; i <= len; i++) { 
            Cs[i] = S.Cs[i];
        }
        return *this;
    }
    
    String& operator=(const char* X) {
        delete[] Cs;
        if (!X) {
            len = 0;
            cap = 1;
            Cs = new char[1];
            Cs[0] = '\0';
        } else {
            len = getlen(X);
            cap = len + 1;
            Cs = new char[cap];
            for (int i = 0; i < len; i++) {
                Cs[i] = X[i];
            }
            Cs[len] = '\0';
        }
        return *this;
    }
    ~String() {
        delete[] Cs;
    }
    const char* c_str() const {
        return Cs;
    }
    
    int length() const {
        return len;
    } 
    int capacity() const {
        return cap;
    }
    bool operator==(const String& M) const {
        if (len != M.len) return false;
        for (int i = 0; i < len; i++) {
            if (Cs[i] != M.Cs[i]) return false;
        }
        return true;
    }
    char operator[](int i) const {
        if (i < 0 || i >= len) {
            cout << "Index out of range!" << endl;
            return '\0';
        }
        return Cs[i];
    }
    char& operator[](int i) {
        if (i < 0 || i >= len) {
            cout << "Index out of range!" << endl;
            static char dummy = '\0';
            return dummy;
        }
        return Cs[i];
    }
    friend ostream& operator<<(ostream& os, const String& str) {
        for (int i = 0; i < str.len; i++) {
            os << str.Cs[i];
        }
        return os;
    }
    void clear() {
        delete[] Cs;
        len = 0;
        cap = 1;
        Cs = new char[1];
        Cs[0] = '\0';
    }
   


    friend istream& operator>>(istream& is, String& str) {
    str.clear();
    int capacity = 16;
    char* buffer = new char[capacity];
    int length = 0;
    char ch;

    // Consume leading whitespace but keep a space-only line intact
    while (is.get(ch) && ch == '\r') {} // skip carriage return
    if (!is) return is;
    if (ch == '\n') {
        buffer[length++] = '\n';
    } else {
        if (ch != EOF)
            is.putback(ch);
    }

    while (is.get(ch) && ch != '\n') {
        if (length >= capacity - 1) {
            capacity *= 2;
            char* new_buffer = new char[capacity];
            for (int i = 0; i < length; i++) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[length++] = ch;
    }

    buffer[length] = '\0';
    str.len = length;
    str.cap = length + 1;
    str.Cs = new char[str.cap];
    for (int i = 0; i < length; i++) {
        str.Cs[i] = buffer[i];
    }
    str.Cs[length] = '\0';
    delete[] buffer;
    return is;
}

};


#endif // STRING_H