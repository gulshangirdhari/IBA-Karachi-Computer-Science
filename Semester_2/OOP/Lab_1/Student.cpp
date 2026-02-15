#include <iostream>
#include <string>
// class
class Student {
    private:
    std::string erpId;
    std::string name;
    double cgpa;
    std::string phone;
    static int erp; 
    public:

    Student(std::string name, double cgpa, std::string phone) {
        if(!(cgpa >=0 && cgpa <=4)) {
            std::cout << "Error! Please enter cpga in the range (0-4).";
            return;
        }
        if(!(phone.length() == 11)) {
            std::cout << "Error! Length must be 11.";
            return;
        }
        for(int i = 0; i < 11; ++i) {
            if(phone[i] >= 48 && phone[i] <= 57) {
                continue;
            } else {
                std::cout << "There must be digit. " << std::endl;
                break;
            }
        } 
        this->name = name;
        this->cgpa = cgpa;
        this->phone = phone;
        this->erpId = std::to_string(erp);
        erp++;
    };
    
    // setters
    //Name
    void setName(std::string name) {
        this->name = name;
    }

    // cgpa
    void setCgpa(double cgpa) {
        if(cgpa >= 0 && cgpa <= 4) {
            this->cgpa = cgpa;
        } else {
            std::cout << "CGPA must be in this range (0-4)." << std::endl;
        }
    }
    
    // phone
    // void setPhone(std::string phone) {
    //     for(int i = 0; i < 11; ++i) {
    //         if(phone[i] >= 48 && phone[i] <= 57) {
    //             this->phone[i] = phone[i];
    //         } else {
    //             std::cout << "Invalid phone! Must be exactly 11 digits." << std::endl;
    //             break;
    //         }
    //     }   
    // }
    void setPhone(std::string phone) {
        if (phone.length() == 11) {
            bool allDigits = true;
            for (char c : phone) {
                if (!isdigit(c)) {
                    allDigits = false;
                    break;
                }
            }
            if (allDigits) {
                this->phone = phone;
                return;
            }
        }
        std::cout << "Invalid phone! Must be exactly 11 digits.\n";
    }

    
    // getters
    std::string getErpId() {
        return erpId;
    }
    std::string getName() {
        return name;
    }
    double getCgpa() {
        return cgpa;
    }
    std::string getPhone() {
        return phone;
    }
    void print() {
        std::cout << "\nName: " << this->name << std::endl;
        std::cout << "ERP ID: " << this->erpId << std::endl;
        std::cout << "CGPA: " << this->cgpa << std::endl;
        std::cout << "Phone: " << this->phone << std::endl;
    }
    
};
int Student::erp {1000};
int main() {

    Student s1("Ali", 3.34, "03108545632");
    Student s2("aslam", 2.34, "03105855632");
    s1.print();
    s1.setCgpa(5.0);          // invalid, rejected
    s1.setPhone("12345abc");  // invalid, rejected
    s2.print();
    return 0;
}