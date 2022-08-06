#include <iostream>
using namespace std;
 
struct Employee {
    bool checked = false;
    int level{};
    Employee* superior{};
};
 
void put_employee_data (Employee* emps, const int* arr, int i) {
    if (emps[i].checked)
        return;
 
    if (arr[i] == -1) {
        emps[i].level = 1;
        emps[i].checked = true;
        emps[i].superior = nullptr;
        return;
    }
 
    if (not emps[arr[i]].checked) {
        put_employee_data(emps, arr, arr[i]);
    }
 
    emps[i].level = emps[arr[i]].level + 1;
    emps[i].superior = &emps[arr[i]];
    emps[i].checked = true;
}
 
int main() {
    int n;
    cin >> n;
    int maxim = 1;
    Employee emps[n+1];
    int arr[n+1];
 
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
 
    for (int i=1; i<=n; i++) {
        put_employee_data(emps, arr, i);
    }
 
    for (int i=1; i<=n; i++) {
        if (emps[i].level > maxim)
            maxim = emps[i].level;
    }
 
    cout << maxim << endl;
 
    return 0;
}