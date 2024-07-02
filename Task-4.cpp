#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include this for std::find

using namespace std;

vector<string> tasks;
vector<bool> taskStatus;

void addTask() {
    string task;
    char choice;
    
    while (true) {
        cout << "\nWould you like to add a task to the TO-DO LIST? (Y/N): ";
        cin >> choice;
        cin.ignore();  // Ignore leftover newline character
        
        if (choice != 'Y' && choice != 'y') {
            break;
        }
        
        cout << "Enter the task to add: ";
        getline(cin, task);
        tasks.push_back(task);
        
        char completion;
        cout << "Is the task completed? (Y/N): ";
        cin >> completion;
        taskStatus.push_back(completion == 'Y' || completion == 'y');
        
        cout << "Task has been added successfully!" << endl;
        cin.ignore();  // Ignore leftover newline character
    }
}

void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }
    
    cout << "Current TO-DO List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "Task: " << tasks[i] << "  Status: " 
             << (taskStatus[i] ? "Completed" : "Not Completed") << endl;
    }
}

void removeTask() {
    string task;
    cout << "Enter the task you want to remove: ";
    cin.ignore();  // Ignore leftover newline character
    getline(cin, task);
    
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        size_t index = distance(tasks.begin(), it);
        tasks.erase(it);
        taskStatus.erase(taskStatus.begin() + index);
        cout << "Task has been removed successfully!" << endl;
    } else {
        cout << "Task not found in the list." << endl;
    }
}

void updateTaskStatus() {
    string task;
    cout << "Enter the task you want to update: ";
    cin.ignore();  // Ignore leftover newline character
    getline(cin, task);
    
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        size_t index = distance(tasks.begin(), it);
        taskStatus[index] = !taskStatus[index];
        cout << "Task status has been updated to: " 
             << (taskStatus[index] ? "Completed" : "Not Completed") << endl;
    } else {
        cout << "Task not found in the list." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nMENU" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Update Task Status" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                updateTaskStatus();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
