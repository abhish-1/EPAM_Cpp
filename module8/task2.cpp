#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>

void printTodoList(const std::vector<std::string>& tasks) {
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
    if (tasks.empty()) {
        std::cout << "No tasks.\n";
    }
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string toUpperString(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return s;
}

std::string toLowerString(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return s;
}

class TodoList {
private:
    std::vector<std::string> tasks;
    
public:
    void initializeTodoList() {
        tasks.clear();
        tasks.push_back("SendingStatusUpdateMail");
        tasks.push_back("PrepareForMeeting");
        tasks.push_back("CompletingTrainings");
        tasks.push_back("UrgentCriticalBugFix");
        tasks.push_back("KnowledgeTransferNotes");
        std::cout << "Initialized with 5 tasks.\n";
    }
    
    void displayInitialList() {
        printTodoList(tasks);
    }
    
    void addNewTask() {
        std::string task;
        std::cout << "Enter new task: ";
        clearInputBuffer();
        std::getline(std::cin, task);
        tasks.push_back(task);
        std::cout << "Task added.\n";
        printTodoList(tasks);
    }
    
    void insertHighPriorityTask() {
        if (tasks.empty()) {
            std::cout << "List is empty. Adding as first task.\n";
            std::string task;
            std::cout << "Enter high priority task: ";
            clearInputBuffer();
            std::getline(std::cin, task);
            tasks.insert(tasks.begin(), task);
        } else {
            std::string task;
            std::cout << "Enter high priority task: ";
            clearInputBuffer();
            std::getline(std::cin, task);
            std::cout << "Enter position (1 to " << tasks.size() + 1 << "): ";
            int pos;
            std::cin >> pos;
            clearInputBuffer();
            if (pos >= 1 && pos <= tasks.size() + 1) {
                tasks.insert(tasks.begin() + (pos - 1), task);
            } else {
                std::cout << "Invalid position. Adding at beginning.\n";
                tasks.insert(tasks.begin(), task);
            }
        }
        std::cout << "High priority task inserted.\n";
        printTodoList(tasks);
    }
    
    void viewFirstAndLastTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
        } else {
            std::cout << "First task: " << tasks.front() << "\n";
            std::cout << "Last task: " << tasks.back() << "\n";
        }
    }
    
    void removeLastTask() {
        if (tasks.empty()) {
            std::cout << "No tasks to remove.\n";
        } else {
            tasks.pop_back();
            std::cout << "Last task removed.\n";
            printTodoList(tasks);
        }
    }
    
    void markTaskComplete() {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
            return;
        }
        printTodoList(tasks);
        std::cout << "Enter task number to remove: ";
        int num;
        std::cin >> num;
        clearInputBuffer();
        if (num >= 1 && num <= tasks.size()) {
            tasks.erase(tasks.begin() + (num - 1));
            std::cout << "Task marked complete.\n";
            printTodoList(tasks);
        } else {
            std::cout << "Invalid number.\n";
        }
    }
    
    void sortTasksAlphabetically() {
        std::sort(tasks.begin(), tasks.end());
        std::cout << "Tasks sorted.\n";
        printTodoList(tasks);
    }
    
    void reverseTaskOrder() {
        std::reverse(tasks.begin(), tasks.end());
        std::cout << "Tasks reversed.\n";
        printTodoList(tasks);
    }
    
    void searchAndCountTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
            return;
        }
        std::string keyword;
        std::cout << "Enter keyword to search: ";
        clearInputBuffer();
        std::getline(std::cin, keyword);
        
        auto it = std::find(tasks.begin(), tasks.end(), keyword);
        if (it != tasks.end()) {
            std::cout << "First occurrence at position: " << (it - tasks.begin() + 1) << "\n";
        } else {
            std::cout << "Keyword not found.\n";
        }
        
        int count = std::count(tasks.begin(), tasks.end(), keyword);
        std::cout << "Total occurrences: " << count << "\n";
    }
    
    void transformToUppercase() {
        for (auto& task : tasks) {
            task = toUpperString(task);
        }
        std::cout << "All tasks converted to uppercase.\n";
        printTodoList(tasks);
    }
    
    void checkKeywordContainingTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
            return;
        }
        
        std::vector<std::string> keywords = {"URGENT", "DEADLINE"};
        bool found = false;
        
        for (const auto& keyword : keywords) {
            auto it = std::find_if(tasks.begin(), tasks.end(), [&](const std::string& task) {
                std::string upperTask = toUpperString(task);
                return upperTask.find(keyword) != std::string::npos;
            });
            
            if (it != tasks.end()) {
                std::cout << "Task containing '" << keyword << "': " << *it << "\n";
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No tasks containing 'URGENT' or 'DEADLINE'.\n";
        }
    }
    
    void findLexicographicallyFirstLast() {
        if (tasks.empty()) {
            std::cout << "No tasks.\n";
            return;
        }
        
        auto minIt = std::min_element(tasks.begin(), tasks.end());
        auto maxIt = std::max_element(tasks.begin(), tasks.end());
        
        std::cout << "Lexicographically first: " << *minIt << "\n";
        std::cout << "Lexicographically last: " << *maxIt << "\n";
    }
    
    void finalCleanup() {
        tasks.clear();
        std::cout << "All tasks cleared.\n";
        printTodoList(tasks);
    }
};

int main() {
    TodoList myTodoList;
    myTodoList.initializeTodoList();
    
    int choice;
    
    do {
        std::cout << "\n=== TO-DO LIST MENU ===\n";
        std::cout << "1. Initialize/Reset\n";
        std::cout << "2. Display List\n";
        std::cout << "3. Add New Task\n";
        std::cout << "4. Insert High-Priority Task\n";
        std::cout << "5. View First and Last Tasks\n";
        std::cout << "6. Remove Last Task\n";
        std::cout << "7. Mark Task Complete\n";
        std::cout << "8. Sort Alphabetically\n";
        std::cout << "9. Reverse Order\n";
        std::cout << "10. Search & Count\n";
        std::cout << "11. Transform to UPPERCASE\n";
        std::cout << "12. Check Keyword-Containing Tasks\n";
        std::cout << "13. Find Lexicographically First/Last\n";
        std::cout << "14. Clear All Tasks\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                myTodoList.initializeTodoList();
                break;
            case 2:
                myTodoList.displayInitialList();
                break;
            case 3:
                myTodoList.addNewTask();
                break;
            case 4:
                myTodoList.insertHighPriorityTask();
                break;
            case 5:
                myTodoList.viewFirstAndLastTasks();
                break;
            case 6:
                myTodoList.removeLastTask();
                break;
            case 7:
                myTodoList.markTaskComplete();
                break;
            case 8:
                myTodoList.sortTasksAlphabetically();
                break;
            case 9:
                myTodoList.reverseTaskOrder();
                break;
            case 10:
                myTodoList.searchAndCountTasks();
                break;
            case 11:
                myTodoList.transformToUppercase();
                break;
            case 12:
                myTodoList.checkKeywordContainingTasks();
                break;
            case 13:
                myTodoList.findLexicographicallyFirstLast();
                break;
            case 14:
                myTodoList.finalCleanup();
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
        
    } while (choice != 0);
    
    return 0;
}