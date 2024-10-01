#include <iostream>
#include <vector>
#include <string>


class Task {
private:
    std::string description;
    bool completed;

public:
   
    Task(std::string desc) : description(desc), completed(false) {}

   
    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

 
    std::string getDescription() const {
        return description;
    }
};


class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

   
    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
            std::cout << "Task " << index + 1 << " marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

  
    void showTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription()
                      << (tasks[i].isCompleted() ? " [Completed]" : " [Pending]") << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Menu\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Complete Task\n";
    std::cout << "3. Show All Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // To ignore the newline character after entering the choice

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                std::cout << "Enter task number to mark as completed: ";
                int taskNumber;
                std::cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber - 1);
                break;
            }
            case 3:
                todoList.showTasks();
                break;
            case 4:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}
