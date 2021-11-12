//
// Created by NewUser on 2021/11/10.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <cstring>

class String : public string {
protected:
    int Length;
    char *Strp;
public:
    String() {
        Strp = nullptr;
        Length = 0;
    }

    String(const char *s);

    String(const String &s);

    ~String() {
        delete[]Strp;
    }

    void show() {
        cout << Strp << endl;
    }

    String &operator=(String &string);

    friend String &operator+(const String &string1, const String &string2);

    friend String &operator-(const String &string1, const String &string2);

    const char *IsIn(const char &c) const;

    bool IsSubStr(const char *str) const;

    bool operator>(const String &string1) const;

    bool operator<(const String &string1) const;

    bool operator==(const String &string1) const;

    operator const char *() const {
        return (const char *) Strp;
    }

    int GetLen() {
        return Length;
    }

    const char *GetString() {
        return Strp;
    }

    void SetString(const char *str);
};

String::String(const char *s) {
    if (s) {
        Length = strlen(s);
        Strp = new char[strlen(s) + 1];
        strcpy(Strp, s);
    } else {
        Length = 0;
        Strp = nullptr;
    }
}

String::String(const String &s) {
    if (s.Strp) {
        Length = s.Length;
        Strp = new char[Length + 1];
        strcpy(Strp, s.Strp);
    } else {
        Length = 0;
        Strp = nullptr;
    }
}

String &String::operator=(String &string) {
    if (&string == this) {
        return *this;
    }
    if (Strp) {
        delete[]Strp;
    }
    if (string.Strp) {
        Length = string.Length;
        Strp = new char[Length + 1];
        strcpy(Strp, string.Strp);
    } else {
        Length = 0;
        Strp = nullptr;
    }
    return *this;
}

String &operator+(const String &string1, const String &string2) {
    String *temp;
    temp = new String;
    temp->Length = string1.Length + string2.Length;
    temp->Strp = new char[temp->Length + 1];
    strcpy(temp->Strp, string1.Strp);
    strcat(temp->Strp, string2.Strp);
    return *temp;
}

String &operator-(const String &string1, const String &string2) {
    String *temp;
    char *p, *q;
    int i = 0;
    p = string1.Strp;
    temp = new String;
    temp->Length = string1.Length - string2.Length + 1;
    q = strstr(p, string2.Strp);
    if (q) {
        temp->Strp = new char[temp->Length];
        while (p < q) {
            temp->Strp[i++] = *p;
            p++;
        }
        p += string2.Length;
        while ((temp->Strp[i++] = *p++));
    }
    return *temp;
}

const char *String::IsIn(const char &c) const {
    char *p;
    p = Strp;
    while (*p) {
        if (*p++ == c) {
            return --p;
        }
    }
    return nullptr;
}

bool String::IsSubStr(const char *str) const {
    if (strstr(Strp, str)) {
        return true;
    } else {
        return false;
    }
}

bool String::operator>(const String &string1) const {
    return strcmp(Strp, string1.Strp) > 0;
}

bool String::operator<(const String &string1) const {
    return strcmp(Strp, string1.Strp) < 0;
}

bool String::operator==(const String &string1) const {
    return strcmp(Strp, string1.Strp) == 0;
}

void String::SetString(const char *str) {
    if(*str){
        Length = strlen(str);
        Strp = new char[Length + 1];
        strcpy(Strp, str);
    } else{
        Length = 0;
        Strp = nullptr;
    }
}

#endif //STRING_STRING_H
