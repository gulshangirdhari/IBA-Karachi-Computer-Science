#include <iostream>


// A custom string class (NOT std::string)
class string {
public:

    // Constructor that takes a C-style string (char array ending with '\0')
    string(const char* c = "") {

        // Temporary pointer to traverse the input string
        const char* ctemp = c;

        // Count length of the string manually
        while(*ctemp != '\0') {
            ++m_len;
            ++ctemp;
        }
        if(m_len == 0) {
            m_arr = nullptr;
            return;
        }
        // Allocate dynamic memory to store characters
        m_arr = new char[m_len];

        // Copy characters from input string into our array
        for (size_t i = 0; i < m_len; ++i) {
            m_arr[i] = c[i];
        }
    }

    // destructor
    ~string() {
        if(!(m_arr == nullptr)){
            delete[] m_arr;
        }

        m_arr = nullptr;
        m_len = 0;
    }

    // copy constructor
    string(const string& other) {
        m_len = other.m_len;
        if (m_len == 0) {
            m_arr = nullptr;
            return;
        }
        m_arr = new char[m_len];
        //m_arr = new char[other.m_len + 1];
        // m_len = other.m_len;
        // m_arr = new char[m_len + 1];

        for(int i = 0; i < other.m_len; ++i) {
            m_arr[i] = other.m_arr[i];
        }
        //m_arr[other.m_len] = '\0';   
    }



    // copy assignment operator
    string& operator=(const string& other) {
        // self check
        if(this == &other) {
            return *this;
        }
        // if this->m_len is 0
        if(this->m_arr != nullptr) {
            delete[] m_arr;
            m_arr = nullptr;
            m_len = 0;
        }

        if(other.m_arr != nullptr) {
            m_len = other.m_len;
            m_arr = new char[m_len];
    
            for (size_t i = 0; i < m_len; ++i) {
                m_arr[i] = other.m_arr[i];
            }
        }   
        return *this;
    }


    // index operator
    // char& operator[](size_t index) const{
    //     char* n = new char('\0') ;
    //     if(index < 0 || index >= m_len) {
    //         return *n;
    //     }
    //     return m_arr[index];
    // }

    char& operator[](size_t index) const{
        if(index < 0 || index >= m_len) {
            throw;
        }
        return m_arr[index];
    }

    
    // concatenation operator
    string operator+(const string& other) const {
        string result;
        result.m_len = this->m_len + other.m_len;
        result.m_arr = new char[result.m_len];
        
        // copying first string
        for(size_t i = 0; i < this->m_len; i++) {
            result.m_arr[i] = this->m_arr[i];
        }
        // copying second string
        for(size_t j = 0; j < other.m_len; j++) {
            result.m_arr[j + this->m_len] = other.m_arr[j];
        }

        return result;
    }


    //equality operator
    bool operator== (const string& other) const {
        // checking the length factor
        if(this->m_len != other.m_len) {
            return false;
        }
        // self check
        if(this == &other) {
            return true;
        }
        // each character
        for(size_t i = 0; i < this->m_len; i++) {
            if(this->m_arr[i] != other.m_arr[i]) {      
                return false;
            } 
        } 
        return true;
    }


    //inequality operator !=
    // bool operator!=(const string& other) const {
    //     // checking the length factor
    //     if(this->m_len != other.m_len) {
    //         return true;
    //     }
    //     // self check
    //     if(this == &other) {
    //         return false; 
    //     }
    //             // each character
    //     for(size_t i = 0; i < this->m_len; i++) {
    //         if(this->m_arr[i] != other.m_arr[i]) {      
    //             return true;
    //         } 
    //     } 
    //     return false;
    // }
        // OR
    bool operator!=(const string& other) const {
        return !(*this == other);   
    }   




    // Returns the length of the string
    size_t size() {
        return m_len;
    }

    // Prints the stored characters to the console
    void print() {
        for (size_t i = 0; i < m_len; ++i) {
            std::cout << m_arr[i];
        }
        std::cout << "\n";
    }

    bool isPalindrome() {
        // Handle empty string or single character
        if (m_len <= 1) return true;
        
        for(size_t i = 0; i < m_len / 2; i++) {
            if (m_arr[i] != m_arr[m_len-1-i]) return false;
        }
        return true;
    }

    char at (size_t index) {
        // Bounds checking
        if (index >= m_len) {
            std::cout << "Error: Index out of bounds!" << std::endl;
            return '\0';  // Return null character on invalid index
        }
        return m_arr[index];
    }

    bool contains(char c) {
        for (size_t i = 0; i < m_len; i++) {
            if (m_arr[i] == c) return true; 
        }
        return false;
    }

    int find (char c) {
        for (size_t i = 0; i < m_len; i++) {
            if (m_arr[i] == c) return i; 
        }
        return -1;  // Return -1 if character not found
    }

    void append(const string& other) {
        // Handle edge case: appending empty string
        if (other.m_len == 0) return;
        
        size_t old_len = m_len;
        size_t new_len = m_len + other.m_len;
        
        // Create new array with combined size
        char* new_arr = new char[new_len];
        
        // Copy original string
        for(size_t i = 0; i < old_len; i++) {
            new_arr[i] = m_arr[i];
        }
        
        // Append other string
        for(size_t i = 0; i < other.m_len; i++) {
            new_arr[old_len + i] = other.m_arr[i];
        }
        
        // Delete old array and update pointer
        delete[] m_arr;
        m_arr = new_arr;
        m_len = new_len;
    }

private:
    size_t m_len{0};     // Stores number of characters in the string
    char* m_arr{nullptr}; // Pointer to dynamically allocated character array
};
// Assuming you have a custom String class implemented with:
// - constructors
// - copy constructor
// - assignment operator
// - operator[]
// - operator+
// - operator== and operator!=
// - size(), contains(), find(), isPalindrome(), at()
// - append()
// - print()


// Your custom class should be defined as: class string { ... };

int main() {
    // Test 1: Copy Constructor
    std::cout << "Test1: Copy Constructor" << std::endl;
    string s1("Hello"), s2("World"), s3 = s1;
    std::cout << "Original s1: "; s1.print(); std::cout << std::endl;
    std::cout << "Copy s3 = s1: "; s3.print(); std::cout << std::endl;

    s3[0] = 'h';
    std::cout << "After modifying s3[0] to 'h':" << std::endl;
    std::cout << "Original s1: "; s1.print(); std::cout << std::endl;
    std::cout << "Modified s3: "; s3.print(); std::cout << std::endl << std::endl;

    // Test 2: Assignment Operator
    std::cout << "Test2: Assignment Operator" << std::endl;
    string s4("Initial");
    std::cout << "Before assignment, s4: "; s4.print(); std::cout << std::endl;
    s4 = s2;
    std::cout << "After s4 = s2, s4: "; s4.print(); std::cout << std::endl << std::endl;

    // Test 3: Self-assignment
    std::cout << "Test3: Self-assignment" << std::endl;
    s4 = s4;
    std::cout << "After s4 = s4, s4: "; s4.print(); std::cout << std::endl << std::endl;

    // Test 4: [] operator
    std::cout << "Test4: Subscript Operator []" << std::endl;
    std::cout << "s1[1] = " << s1[1] << std::endl;
    s1[0] = 'J';
    std::cout << "After s1[0] = 'J': "; s1.print(); std::cout << std::endl << std::endl;

    // Test 5: + operator
    std::cout << "Test5: Concatenation Operator +" << std::endl;
    string s5("Hello"), s6("World"), s7 = s5 + s6;
    std::cout << "s5: "; s5.print(); std::cout << std::endl;
    std::cout << "s6: "; s6.print(); std::cout << std::endl;
    std::cout << "s7 = s5 + s6 = "; s7.print(); 

    // Test 6: == and != operators
    std::cout << "Test6: Equality Operators == and !=" << std::endl;
    string s8("Hello"), s9("hello"), s10("World");
    std::cout << (s8 == s9 ? "s8 and s9 are equal" : "s8 and s9 are NOT equal") << std::endl;
    std::cout << (s8 != s10 ? "s8 and s10 are NOT equal" : "s8 and s10 are equal") << std::endl << std::endl;

    // Test 7: Lab1 Methods
    std::cout << "Test7: Lab1 Methods Still Working" << std::endl;
    std::cout << "Size of s7: " << s7.size() << std::endl;
    std::cout << "s7 contains 'W': " << (s7.contains('W') ? "Yes" : "No") << std::endl;
    std::cout << "Index of 'W' in s7: " << s7.find('W') << std::endl;
    std::cout << "Is s8 palindrome? " << (s8.isPalindrome() ? "Yes" : "No") << std::endl;
    std::cout << "Character at index 1 in s8: " << s8.at(1) << std::endl << std::endl;

    // Test 8: Append
    std::cout << "Test8: Append" << std::endl;
    string s11("Hello"), s12("There");
    s11.append(s12);
    std::cout << "After s11.append(s12): "; s11.print(); std::cout << std::endl << std::endl;

    // Test 9: Chain operations
    std::cout << "Test9: Chained Operations" << std::endl;
    string f("C"), g("++"), h(" Programming"), r = f + g + h;
    std::cout << "Result of chaining: "; r.print(); std::cout << std::endl;

    // return 0;
}