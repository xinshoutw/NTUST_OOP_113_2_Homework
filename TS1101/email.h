//
// Created by xinshou on 2025/4/28.
//

#ifndef EMAIL_H
#define EMAIL_H

#include "document.h"
#include <string>

class Email : public Document {
public:
    Email(const std::string& text, std::string sender, std::string recipient, std::string title)
        : Document(text)
        , sender(std::move(sender))
        , recipient(std::move(recipient))
        , title(std::move(title)) {}
    std::string getSender() const {
        return sender;
    }
    std::string getRecipient() const {
        return recipient;
    }
    std::string getTitle() const {
        return title;
    }

    void setSender(const std::string& sender) {
        this->sender = sender;
    }
    void setRecipient(const std::string& recipient) {
        this->recipient = recipient;
    }
    void setTitle(const std::string& title) {
        this->title = title;
    }

    Email& operator=(const Email& other) {
        if (this != &other) {
            text = other.text;
            sender = other.sender;
            recipient = other.recipient;
            title = other.title;
        }

        return *this;
    }

private:
    std::string sender;
    std::string recipient;
    std::string title;
};

#endif // EMAIL_H
