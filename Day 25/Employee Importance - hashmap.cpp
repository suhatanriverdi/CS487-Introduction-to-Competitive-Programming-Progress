// Question Link ---> https://leetcode.com/problems/employee-importance
// Day #25
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> idMap;
        for (auto employee : employees) { // Save Employee id's as a key, employee itself as a value
            idMap.insert({employee->id, employee});
        }
        int importanceSum = 0;
        queue<Employee*> allEmployees;
        if (idMap.count(id)) {
            allEmployees.push(idMap[id]);
            while (!allEmployees.empty()) {
                Employee* currentEmployee = allEmployees.front();
                allEmployees.pop();
                importanceSum += currentEmployee->importance;
                for (auto subordinateID : currentEmployee->subordinates) {
                    allEmployees.push(idMap[subordinateID]);
                }
            }
        }
        return importanceSum;
    }
};