//
// Created by xinshou on 2025/4/28.
//

#ifndef FILE_H
#define FILE_H

#include "document.h"

class File : public Document {
public:
    explicit File(const std::string& text, std::string pathname)
        : Document(text)
        , pathname(std::move(pathname)) {}

    std::string getPathname() const {
        return pathname;
    }

    void setPathname(const std::string& pathname) {
        this->pathname = pathname;
    }

    File& operator=(const File& file) {
        this->text = file.text;
        this->pathname = file.pathname;
        return *this;
    }

private:
    std::string pathname;
};

#endif // FILE_H
