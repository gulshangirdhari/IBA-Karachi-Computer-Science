#include <iostream>
#include <string>

class Student {
private:
    std::string name, erpID;
    double* grades;
    int numCourses;
    double cgpa;

public:
    // Constructor
    Student(std::string n, std::string id, int courses)
        : name(n), erpID(id), numCourses(courses), cgpa(0.0) {
        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) grades[i] = 0.0;
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& other)
        : name(other.name), erpID(other.erpID), numCourses(other.numCourses), cgpa(other.cgpa) {
        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) grades[i] = other.grades[i];
    }

    // Destructor
    ~Student() {
        delete[] grades;
    }

    // Assignment Operator
    Student& operator=(const Student& other) {
        if (this == &other) return *this; // self-assignment check

        delete[] grades; // free old memory

        name = other.name;
        erpID = other.erpID;
        numCourses = other.numCourses;
        cgpa = other.cgpa;

        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) grades[i] = other.grades[i];

        return *this;
    }

    // Utility methods
    void setGrade(int courseIndex, double grade) {
        if (courseIndex >= 0 && courseIndex < numCourses && grade >= 0 && grade <= 100) {
            grades[courseIndex] = grade;
        }
    }

    void calculateCGPA() {
        double sum = 0.0;
        for (int i = 0; i < numCourses; i++) sum += grades[i];
        cgpa = sum / numCourses;
        cgpa = cgpa*0.04;
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ERP ID: " << erpID << std::endl;
        std::cout << "CGPA: " << cgpa << std::endl;
        std::cout << "Grades: ";
        for (int i = 0; i < numCourses; i++) std::cout << grades[i] << " ";
        std::cout << std::endl;
    }

    // Getters
    std::string getName() const { return name; }
    std::string getErpId() const { return erpID; }
    double getCGPA() const { return cgpa; }
    int getNumCourses() const { return numCourses; }
    double getGrade(int index) const {
        if (index >= 0 && index < numCourses) return grades[index];
        return -1; // invalid index
    }

    // Analysis methods
    double getHighestGrade() const {
        double maxGrade = grades[0];
        for (int i = 1; i < numCourses; i++)
            if (grades[i] > maxGrade) maxGrade = grades[i];
        return maxGrade;
    }

    double getLowestGrade() const {
        double minGrade = grades[0];
        for (int i = 1; i < numCourses; i++)
            if (grades[i] < minGrade) minGrade = grades[i];
        return minGrade;
    }

    int countFailingGrades() const {
        int count = 0;
        for (int i = 0; i < numCourses; i++)
            if (grades[i] < 50) count++;
        return count;
    }
};


// main function 
int main() {
    Student s1("Ali Ahmed", "26184", 5);
    s1.setGrade(0, 85);
    s1.setGrade(1, 90);
    s1.setGrade(2, 78);
    s1.setGrade(3, 92);
    s1.setGrade(4, 88);
    s1.calculateCGPA();

    std::cout << "--- Student Information---" << std::endl;
    s1.display();

    std::cout << "\n--- Grade Analysis---" << std::endl;
    std::cout << "Highest Grade: " << s1.getHighestGrade() << std::endl;
    std::cout << "Lowest Grade: " << s1.getLowestGrade() << std::endl;
    std::cout << "Failing Courses: " << s1.countFailingGrades() << std::endl;

    // Test deep copy (Copy Constructor)
    std::cout << "\n--- Testing Deep Copy---" << std::endl;
    Student s2 = s1; // Calls copy constructor
    s2.setGrade(0, 95);
    s2.calculateCGPA();

    std::cout << "\nOriginal Student (s1):" << std::endl;
    s1.display();

    std::cout << "\nCopied Student (s2) after modification:" << std::endl;
    s2.display();

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator---" << std::endl;
    Student s3("Sara Khan", "26185", 5);
    s3 = s1; // Calls assignment operator
    s3.setGrade(1, 100);
    s3.calculateCGPA();

    std::cout << "\nOriginal (s1):" << std::endl;
    s1.display();

    std::cout << "\nAssigned (s3) after modification:" << std::endl;
    s3.display();

    // Test self-assignment
    s3 = s3; // Should handle gracefully
    std::cout << "\nAfter self-assignment, s3:" << std::endl;
    s3.display();

    return 0;
}