#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    int id;
    string title;
    string description;
    bool completed;

    Task(int taskId, string taskTitle, string taskDescription) {
        id = taskId;
        title = taskTitle;
        description = taskDescription;
        completed = false;
    }
};

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }
    cout << "\n========== TASK LIST ==========\n";
    for (const Task& task : tasks) {
        cout << "\nTask ID: " << task.id;
        cout << "\nTitle: " << task.title;
        cout << "\nDescription: " << task.description;
        cout << "\nStatus: ";
        if (task.completed) {
            cout << "Completed";
        }
        else {
            cout << "Pending";
        }
        cout << "\n-------------------------------\n";
    }
}

void createTask(vector<Task>& tasks) {
    int id;
    string title;
    string description;

    cout << "\nEnter Task ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Task Title: ";
    getline(cin, title);

    cout << "Enter Task Description: ";
    getline(cin, description);

    tasks.push_back(Task(id, title, description));
    cout << "\nTask created successfully!\n";
}

void updateTask(vector<Task>& tasks) {
    int id;

    cout << "\nEnter Task ID to update: ";
    cin >> id;
    cin.ignore();

    for (Task& task : tasks) {
        if (task.id == id) {
            cout << "Enter new title: ";
            getline(cin, task.title);

            cout << "Enter new description: ";
            getline(cin, task.description);

            int status;
            cout << "Enter status (1 = Completed, 0 = Pending): ";
            cin >> status;

            task.completed = (status == 1);
            cout << "\nTask updated successfully!\n";
            return;
        }
    }

    cout << "\nTask not found.\n";
}

void deleteTask(vector<Task>& tasks) {
    int id;

    cout << "\nEnter Task ID to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "\nTask deleted successfully!\n";
            return;
        }
    }

    cout << "\nTask not found.\n";
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "=====================================\n";
    cout << "        COGNIFYZ TASK MANAGER\n";
    cout << "=====================================\n";

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Create Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "===========================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                updateTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "\nThank you for using Cognifyz Task Manager!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
