#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define TRUE 1
#define FALSE 0
#define QTY_EMPLOYEES 5
#define SIZE_NAME 51
#define RETRY 2
#define MIN_SALARY 500
#define MAX_SALARY 10000
#define MIN_SECTOR 1
#define MAX_SECTOR 10
#define UP 1
#define DOWN 0

struct
{
  int id;
  char name[SIZE_NAME];
  char lastName[SIZE_NAME];
  float salary;
  int sector;
  int isEmpty;

}typedef Employee;

int initEmployees(Employee* list, int len);
int entryEmployee(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len);
int removeEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int totalSalaryEmployees(Employee* list, int len);
int averageSalaryEmployees(Employee* list, int len);
int qtyAverageSalaryEmployees(Employee* list, int len);
int menuEmployee(int* option);

#endif /* EMPLOYEE_H_ */
