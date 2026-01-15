#include <iostream>
#include <cstring> //For strlen()
#include "MyString.h"

String::String(const char* s) {
   size = static_cast<int>(strlen(s))+1;
   data = new char[size];
   for (int i = 0; i < size; i++) {
      data[i] = s[i];
   }
};

String::~String() {
   delete[] data;
}

String &String::operator+=(const String &other) {
   int new_size = size + other.size - 1;
   int null_tracker = 0;
   char* temp = new char[new_size];
   for (int i = 0; i < size-1; ++i) {
      temp[i] = data[i];
      null_tracker++;
   }
   for (int i = 0; i < other.size-1;++i) {
      temp[size+i-1] = other.data[i];
      null_tracker++;
   }
   temp[null_tracker] = '\0';
   delete[] data;
   data = temp;
   size = new_size;
   return *this;
}


String &String::operator=(const String &other) {
   if (&other == this) {
      return *this;
   }
   delete[] data;
   data = new char[other.size];
   for (int i = 0; i < other.size; ++i) {
      data[i] = other.data[i];
   }
   size = other.size;
   return *this;
}

String String::operator+(const String &other) const {
   String result(*this);
   result += other;
   return result;
}

char String::operator[](int index) const {
   if (index > size-1 || index < 0) {
      throw std::out_of_range("Index out of range");
   }
   return data[index];
}

bool String::operator==(const String& other) const {
   if (this->size != other.size) {
      return false;
   }
   for (int i = 0; i < this->size; ++i) {
      if (this->data[i] != other.data[i]) {
         return false;
      }
   }
   return true;
}

String::String(const String& other) {
   size = other.size;
   data = new char[size];
   for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
   }
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
   if (s.data) {
      os << s.data;
   }
   else {
      os << "";
   }
   return os;
}

int String::get_size() const {
   return size;
}

String::String(String&& other) noexcept {
   this->data = std::exchange(other.data, nullptr);
   this->size = std::exchange(other.size, 0);
}

String& String::operator=(String&& other) noexcept {
   if (this == &other) {
      return *this;
   }
   delete[] data;
   this->data = std::exchange(other.data, nullptr);
   this->size = std::exchange(other.size, 0);
   return *this;
}