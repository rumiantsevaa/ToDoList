#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Todo {
    string title;
    int priority;
    string description;
    string deadline;
};

vector<Todo> todoList;

void addTodo() {
    Todo newTodo;

    cout << "Введите название дела: ";
    getline(cin, newTodo.title);

    cout << "Выберите приоритет (1 - низкий, 2 - средний, 3 - высокий): ";
    cin >> newTodo.priority;
    cin.ignore();

    cout << "Введите описание дела: ";
    getline(cin, newTodo.description);

    cout << "Введите дату и время исполнения (в формате дд.мм.гггг): ";
    getline(cin, newTodo.deadline);

    todoList.push_back(newTodo);

    cout << "Дело успешно добавлено!\n";
}

void deleteTodo() {
    cout << "Введите номер дела для удаления: ";
    int index;
    cin >> index;

    if (index >= 1 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Дело успешно удалено!\n";
    }
    else {
        cout << "Неверный номер дела!\n";
    }
}

void editTodo() {
    cout << "Введите номер дела для редактирования: ";
    int index;
    cin >> index;

    if (index >= 1 && index <= todoList.size()) {
        Todo& todo = todoList[index - 1];

        cout << "Введите новое название дела: ";
        cin.ignore();
        getline(cin, todo.title);

        cout << "Выберите новый приоритет (1 - низкий, 2 - средний, 3 - высокий): ";
        cin >> todo.priority;
        cin.ignore();

        cout << "Введите новое описание дела: ";
        getline(cin, todo.description);

        cout << "Введите новую дату и время исполнения (в формате дд.мм.гггг): ";
        getline(cin, todo.deadline);

        cout << "Дело успешно отредактировано!\n";
    }
    else {
        cout << "Неверный номер дела!\n";
    }
}

void searchByTitle() {
    string keyword;
    cout << "Введите ключевое слово для поиска по названию: ";
    getline(cin, keyword);

    vector<Todo> matchingTodos;

    for (const Todo& todo : todoList) {
        if (todo.title.find(keyword) != string::npos) {
            matchingTodos.push_back(todo);
        }
    }

    if (matchingTodos.empty()) {
        cout << "Нет дел, соответствующих поиску по названию.\n";
    }
    else {
        cout << "Найденные дела (поиск по названию):\n";
        for (const Todo& todo : matchingTodos) {
            cout << "Название: " << todo.title << endl;
            cout << "Приоритет: " << todo.priority << endl;
            cout << "Описание: " << todo.description << endl;
            cout << "Дедлайн: " << todo.deadline << endl;
            cout << "==============================\n";
        }
    }
}

void searchByPriority() {
    int priority;
    cout << "Введите приоритет для поиска (1 - низкий, 2 - средний, 3 - высокий): ";
    cin >> priority;

    vector<Todo> matchingTodos;

    for (const Todo& todo : todoList) {
        if (todo.priority == priority) {
            matchingTodos.push_back(todo);
        }
    }

    if (matchingTodos.empty()) {
        cout << "Нет дел, соответствующих поиску по приоритету.\n";
    }
    else {
        cout << "Найденные дела (поиск по приоритету):\n";
        for (const Todo& todo : matchingTodos) {
            cout << "Название: " << todo.title << endl;
            cout << "Приоритет: " << todo.priority << endl;
            cout << "Описание: " << todo.description << endl;
            cout << "Дедлайн: " << todo.deadline << endl;
            cout << "==============================\n";
        }
    }
}

void searchByDescription() {
    string keyword;
    cout << "Введите ключевое слово для поиска по описанию: ";
    getline(cin, keyword);

    vector<Todo> matchingTodos;

    for (const Todo& todo : todoList) {
        if (todo.description.find(keyword) != string::npos) {
            matchingTodos.push_back(todo);
        }
    }

    if (matchingTodos.empty()) {
        cout << "Нет дел, соответствующих поиску по описанию.\n";
    }
    else {
        cout << "Найденные дела (поиск по описанию):\n";
        for (const Todo& todo : matchingTodos) {
            cout << "Название: " << todo.title << endl;
            cout << "Приоритет: " << todo.priority << endl;
            cout << "Описание: " << todo.description << endl;
            cout << "Дедлайн: " << todo.deadline << endl;
            cout << "==============================\n";
        }
    }
}

void searchByDeadline() {
    string deadline;
    cout << "Введите дату и время исполнения для поиска (в формате дд.мм.гггг): ";
    getline(cin, deadline);

    vector<Todo> matchingTodos;

    for (const Todo& todo : todoList) {
        if (todo.deadline == deadline) {
            matchingTodos.push_back(todo);
        }
    }

    if (matchingTodos.empty()) {
        cout << "Нет дел, соответствующих поиску по дате и времени исполнения.\n";
    }
    else {
        cout << "Найденные дела (поиск по дате и времени исполнения):\n";
        for (const Todo& todo : matchingTodos) {
            cout << "Название: " << todo.title << endl;
            cout << "Приоритет: " << todo.priority << endl;
            cout << "Описание: " << todo.description << endl;
            cout << "Дедлайн: " << todo.deadline << endl;
            cout << "==============================\n";
        }
    }
}

void sortByPriority() {
    sort(todoList.begin(), todoList.end(), [](const Todo& a, const Todo& b) {
        return a.priority < b.priority;
        });

    cout << "Список дел отсортирован по приоритету.\n";
}

void sortByDeadline() {
    sort(todoList.begin(), todoList.end(), [](const Todo& a, const Todo& b) {
        return a.deadline < b.deadline;
        });

    cout << "Список дел отсортирован по дате и времени исполнения.\n";
}

void displayTodoList() {
    if (todoList.empty()) {
        cout << "Список дел пуст.\n";
    }
    else {
        cout << "Список дел:\n";
        for (int i = 0; i < todoList.size(); i++) {
            const Todo& todo = todoList[i];
            cout << "Номер дела: " << (i + 1) << endl;
            cout << "Название: " << todo.title << endl;
            cout << "Приоритет: " << todo.priority << endl;
            cout << "Описание: " << todo.description << endl;
            cout << "Дедлайн: " << todo.deadline << endl;
            cout << "==============================\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    Todo todo1;
    todo1.title = "Позвонить коллеге";
    todo1.priority = 2;
    todo1.description = "Узнать о возможности подготовить проект";
    todo1.deadline = "28.05.2023";

    Todo todo2;
    todo2.title = "Сделать покупки";
    todo2.priority = 1;
    todo2.description = "Купить продукты";
    todo2.deadline = "29.05.2023";

    Todo todo3;
    todo3.title = "Подготовить презентацию";
    todo3.priority = 3;
    todo3.description = "Собрать информацию и составить слайды";
    todo3.deadline = "01.06.2023";

    Todo todo4;
    todo4.title = "Записаться на маникюр";
    todo4.priority = 2;
    todo4.description = "Выбрать подходящее время и записаться";
    todo4.deadline = "30.05.2023";

    Todo todo5;
    todo5.title = "Приготовить ужин";
    todo5.priority = 1;
    todo5.description = "Приготовить любимое блюдо";
    todo5.deadline = "28.05.2023";

    todoList.push_back(todo1);
    todoList.push_back(todo2);
    todoList.push_back(todo3);
    todoList.push_back(todo4);
    todoList.push_back(todo5);

    int choice;
    string name, description;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Добавить дело\n";
        cout << "2. Удалить дело\n";
        cout << "3. Редактировать дело\n";
        cout << "4. Поиск по названию\n";
        cout << "5. Поиск по приоритету\n";
        cout << "6. Поиск по описанию\n";
        cout << "7. Поиск по дате и времени исполнения\n";
        cout << "8. Сортировка по приоритету\n";
        cout << "9. Сортировка по дате и времени исполнения\n";
        cout << "10. Отобразить список дел\n";
        cout << "0. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addTodo();
            break;
        case 2:
            deleteTodo();
            break;
        case 3:
            editTodo();
            break;
        case 4:
            searchByTitle();
            break;
        case 5:
            searchByPriority();
            break;
        case 6:
            searchByDescription();
            break;
        case 7:
            searchByDeadline();
            break;
        case 8:
            sortByPriority();
            break;
        case 9:
            sortByDeadline();
            break;
        case 10:
            displayTodoList();
            break;
        case 0:
            cout << "До свидания!\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
