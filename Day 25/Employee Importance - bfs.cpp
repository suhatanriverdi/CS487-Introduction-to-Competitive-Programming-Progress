// Question Link ---> https://leetcode.com/problems/employee-importance
// Day #25
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importanceSum = 0;
        for (auto employee : employees) {
            if (employee->id == id) { // Find matching employee id
                queue<Employee*> allEmployees;
                allEmployees.push(employee);
                while (!allEmployees.empty()) {
                    Employee* currentEmployee = allEmployees.front();
                    allEmployees.pop();
                    importanceSum += currentEmployee->importance;
                    for (auto subordinateID : currentEmployee->subordinates) {
                        for (auto emp : employees) {
                            if (emp->id == subordinateID) {
                                allEmployees.push(emp);
                            }
                        }
                    }
                }
                break;
            }
        }
        return importanceSum;
    }
};