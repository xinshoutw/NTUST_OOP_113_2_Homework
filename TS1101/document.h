//
// Created by xinshou on 2025/4/28.
//

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document {

public:
    explicit Document(std::string text)
        : text(std::move(text)) {}

    std::string getText() const {
        return text;
    }

    void setText(const std::string& text) {
        this->text = text;
    }

    Document& operator=(const Document& other) {
        if (this != &other) {
            text = other.text;
        }

        return *this;
    }

protected:
    std::string text;
};

using namespace std;

#endif // DOCUMENT_H
