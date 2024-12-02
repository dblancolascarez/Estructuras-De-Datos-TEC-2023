#ifndef ARTICULOS_H
#define ARTICULOS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Article {
public:
    string id;
    int value;
    int quantity;
    char category;
    string code;
    Article* next;
    Article* prev;

    Article(string id, int value, int quantity, char category, string code) {
        this->id = id;
        this->value = value;
        this->quantity = quantity;
        this->category = category;
        this->code = code;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class ArticleList {
public:
    Article* head;
    Article* tail;

    ArticleList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert(Article* article) {
        if (this->head == nullptr) {
            this->head = article;
            this->tail = article;
        } else {
            this->tail->next = article;
            article->prev = this->tail;
            this->tail = article;
        }
    }

    bool has_duplicate(string id) {
        Article* current = this->head;
        while (current != nullptr) {
            if (current->id == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

bool validate(string filename, ArticleList& list) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        string id, code;
        int value, quantity;
        char category;

        istringstream iss(line);
        if (!(iss >> id >> value >> quantity >> category >> code)) {
            cerr << "Error reading line: " << line << endl;
            return false;
        }

        if (value < 0 || quantity < 0) {
            cerr << "Invalid value or quantity in line: " << line << endl;
            return false;
        }

        if (category != 'A' && category != 'B' && category != 'C') {
            cerr << "Invalid category in line: " << line << endl;
            return false;
        }

        if (list.has_duplicate(id)) {
            cerr << "Duplicate item code in line: " << line << endl;
            return false;
        }

        Article* article = new Article(id, value, quantity, category, code);
        list.insert(article);
    }
    file.close();
    return true;
}

#endif