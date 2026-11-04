#include <iostream>
using namespace std;

class Employee
{
public:
    virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
private:
    double salary;

public:
    FullTimeEmployee(double s)
    {
        salary = s;
    }

    double calculateSalary()
    {
        return salary;
    }
};

class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int h, double r)
    {
        hoursWorked = h;
        hourlyRate = r;
    }

    double calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{
    FullTimeEmployee e1(50000);
    PartTimeEmployee e2(80, 500);

    cout << "Full-Time Employee Salary: " << e1.calculateSalary() << endl;
    cout << "Part-Time Employee Salary: " << e2.calculateSalary() << endl;

    return 0;
}