#include <iostream>

// A custom string class (NOT std::string)
class string {
public:

    // Constructor that takes a C-style string (char array ending with '\0')
    string(const char* c) {

        // Temporary pointer to traverse the input string
        const char* ctemp = c;

        // Count length of the string manually
        while(*ctemp != '\0') {
            ++m_len;
            ++ctemp;
        }

        // Allocate dynamic memory to store characters
        m_arr = new char[m_len];

        // Copy characters from input string into our array
        for (size_t i = 0; i < m_len; ++i) {
            m_arr[i] = c[i];
        }
    }

    // Default constructor (creates an empty string of length 1)
    string(){
        m_len = 1;          // Set length to 1
        m_arr = new char;   // Allocate memory for 1 character
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

    // extending further
    // isPalindrome
    bool isPalindrome() {

        for(int i = 0; i < m_len/2; i++) {
            if(m_arr[i] != m_arr[m_len - i - 1]) {
                return false;
            } 
        }
        return true;
    }
    // at 
    char at(size_t index) {
        // if(index >= 0 && index < m_len)  >= 0 is redundant statement
        if(index < m_len)
            return m_arr[index];
        else {
            std::cout << "Error!" << std::endl;
            return '\0';
        }

    }
    // contains
    bool contains(char c) {
        for(int i = 0; i < m_len; i++) {
            if(m_arr[i] == c) {
                return true;
            } 
        }
        return false;
    }
    //find
    int find(char c) {
        for(int i = 0; i < m_len; i++) {
            if(m_arr[i] == c) {
                return i;
            } 
        }
        return -1;
    }
    // append
    void append(const string& other) {
        // firstly we have to create an new array
        char *newArray = new char[this->m_len + other.m_len + 1];
        // copying first string
        for(int i = 0; i < this->m_len; i++) {
            newArray[i] = m_arr[i];
        }
        //copying second string
        for(int j = 0; j < other.m_len; j++) {
            newArray[j + this->m_len] = other.m_arr[j];
        }
        // null character
        newArray[m_len + other.m_len] = '\0';
        delete[] m_arr; 
        m_len += other.m_len;
        m_arr = newArray;
    }


    

private:
    size_t m_len{0};     // Stores number of characters in the string
    char* m_arr{nullptr}; // Pointer to dynamically allocated character array
};

int main() {

    // Create a string object using default constructor
    string s = " community";

    // Other usage examples 
    string str1 = "civic";
    std::cout << "size: " << str1.size() << std::endl;
    str1.print();
    std::cout << "isPalindrome: " << str1.isPalindrome() << std::endl;
    std::cout << "at: " << str1.at(1) << std::endl;
    std::cout << "contains: " << str1.contains('c') << std::endl;
    std::cout << "find: " << str1.find('v')  << std:: endl;
    str1.append(s);
    str1.print();
    // string s("an other way!");

    return 0;
}
