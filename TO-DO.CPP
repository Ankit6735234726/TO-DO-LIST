#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
    std::vector<Task> tasks;
public:
    void addTask(const std::string& desc) {
        tasks.push_back({desc, false});
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size())
            tasks[index].completed = true;
        else
            std::cout << "Invalid task number.\n";
    }

    void showTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] "
                      << tasks[i].description << "\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    do {
        std::cout << "\n1. Add Task\n2. Mark Completed\n3. Show Tasks\n4. Exit\nChoose: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            std::string desc;
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            todo.addTask(desc);
        } else if (choice == 2) {
            int num;
            std::cout << "Enter task number to mark completed: ";
            std::cin >> num;
            todo.markCompleted(num - 1);
        } else if (choice == 3) {
            todo.showTasks();
        }
    } while (choice != 4);
    return 0;
}