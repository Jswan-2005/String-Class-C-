#include <iostream>
#include <string.h> //For strlen()
#include "string.h"

String::String(const char* s) {
   data = new char[strlen(s)+1];
   size = static_cast<int>(strlen(s))+1;
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
   data = new char[new_size];
   for (int i = 0; i < new_size; ++i) {
      data[i] = temp[i];
   }
   size = new_size;
   delete[] temp;
   return *this;
}


String &String::operator=(const String &other) {
   if (&other == this) {
      //Handles Self Assignment
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

String &String::operator+(const String &other) const {
   String* temp = new String("TEMP");
   temp->size = size + other.size - 1;
   int null_tracker = 0;
   delete[] temp->data;
   temp->data = new char[temp->size];
   for (int i = 0; i < size-1; ++i) {
      temp->data[i] = data[i];
      null_tracker++;
   }
   for (int i = 0; i < other.size-1;++i) {
      temp->data[size+i-1] = other.data[i];
      null_tracker++;
   }
   temp->data[null_tracker] = '\0';
   return *temp;
}

char String::operator[](int index) const {
   if (index > size-1) {
      std::cout << "Index out of bounds" << std::endl;
      return 0;
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
   os << s.data;
   return os;
}

int String::get_size() const {
   return size;
}

