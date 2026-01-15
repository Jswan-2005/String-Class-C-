#include <ostream>
#include <utility>

class String {
public:
    String(const char* s);
    ~String();
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    String& operator +=(const String& other);
    String(const String& other);
    int get_size() const;
    String& operator=(const String& other);
    String operator+(const String &other) const;
    bool operator==(const String& other) const;
    char operator[](int index) const;
    String (String&& other) noexcept;
    String& operator=(String&& other) noexcept;
private:
    char* data;
    int size = 0;
};
