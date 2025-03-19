////////////////////////////////////////////////////////////////////////////////
/// @brief A simple contact management system with insert, search, delete and print operations.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/17
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

typedef struct {
    char firstName[25];
    char lastName[30];
    char phone[15];
} StRec;

std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string>& elems);
void process_print(const std::vector<StRec>& users, const std::vector<std::string>& inputs);
void process_search(const std::vector<StRec>& users, const std::vector<std::string>& inputs);
void process_delete(std::vector<StRec>& users, const std::vector<std::string>& inputs);
void process_insert(std::vector<StRec>& users, const std::vector<std::string>& inputs);

int main() {
#ifdef NTUST_DEV
    const std::istringstream iss(
        "print\n"
        "insert Elijah Smith 0912345585\n"
        "print\n"
        "insert Nicol Green 0901563245\n"
        "insert Tom Taylor 0905615613\n"
        "insert Paul Miller 0916548960\n"
        "print\n"
        "search Elijah Smith 0912345585\n"
        "search Tom Taylor 0905615613\n"
        "search Alen Lee 0953440450\n"
        "delete Tom Taylor 0905615613\n"
        "print\n"
        "delete David King 0946549409\n"
        "print\n"
        "insert Obmar Wood 0965406546\n"
        "print\n"
        "insert Jone Smith 0916504894\n"
        "insert Nicol Green 0901563245\n"
        "print\n"
        "insert ovuvuevuevueenyetuenwuevueugbemugbemosas Tom 0123456789012345\n"
        "insert Rainy Jazz 0987a12345987654\n"
        "insert Jone Six 0987580780\n"
        "insert Tom Seven 0951348632\n"
        "insert Jack Eight 886923654321\n"
        "insert Sam Nine 00886958643215\n"
        "insert TF Ten 0913648762\n"
        "insert Howard Eleven 0913215468\n");
    std::cin.rdbuf(iss.rdbuf());
#endif

    std::vector<StRec> users;
    users.reserve(10);

    std::string input_string;
    while (std::getline(std::cin, input_string)) {
        // std::cout << "\nProcessing: " << input_string << '\n';
        std::vector<std::string> inputs;
        split(input_string, ' ', inputs);

        // Input Error check
        if (static_cast<int>(inputs.size()) == 4) {
            if (static_cast<int>(inputs[1].size()) > 25 || static_cast<int>(inputs[2].size()) > 30 || static_cast<int>(inputs[3].size()) > 15 ||
                std::any_of(inputs[3].begin(), inputs[3].end(), [](const char& i) {
                    return !isdigit(i);
                }))
            {
                std::cout << "Input Error\n";
                continue;
            }
        }

        if (inputs[0] == "insert") {
            process_insert(users, inputs);
        } else if (inputs[0] == "search") {
            process_search(users, inputs);
        } else if (inputs[0] == "delete") {
            process_delete(users, inputs);
        } else if (inputs[0] == "print") {
            process_print(users, inputs);
        } else {
            std::cout << "Input Error\n";
        }
    }
}

std::vector<std::string>& split(const std::string& s, const char delim, std::vector<std::string>& elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void process_print(const std::vector<StRec>& users, const std::vector<std::string>& inputs) {
    if (users.empty()) {
        std::cout << "Print Error\n";
        return;
    }

    for (const auto i : users) {
        std::cout << i.firstName << ' ' << i.lastName << ' ' << i.phone << '\n';
    }
}

void process_insert(std::vector<StRec>& users, const std::vector<std::string>& inputs) {
    if (static_cast<int>(users.size()) == 10) {
        std::cout << "Insert Error\n";
        return;
    }

    const auto find_ref = std::find_if(users.begin(), users.end(), [&inputs](const StRec& i) {
            return (strcmp(inputs[1].c_str(), i.firstName) == 0) && (strcmp(inputs[2].c_str(), i.lastName) == 0) && (strcmp(inputs[3].c_str(), i.phone) == 0);
        });
    if (find_ref != users.end()) {
        std::cout << "Insert Error\n";
        return;
    }

    StRec new_rec{};
    strncpy(new_rec.firstName, inputs[1].c_str(), sizeof(new_rec.firstName) - 1);
    strncpy(new_rec.lastName, inputs[2].c_str(), sizeof(new_rec.lastName) - 1);
    strncpy(new_rec.phone, inputs[3].c_str(), sizeof(new_rec.phone) - 1);

    new_rec.firstName[sizeof(new_rec.firstName) - 1] = '\0';
    new_rec.lastName[sizeof(new_rec.lastName) - 1] = '\0';
    new_rec.phone[sizeof(new_rec.phone) - 1] = '\0';

    users.push_back(new_rec);
}

void process_search(const std::vector<StRec>& users, const std::vector<std::string>& inputs) {
    const auto find_ref = std::find_if(users.begin(), users.end(), [&inputs](const StRec& i) {
        return (strcmp(inputs[1].c_str(), i.firstName) == 0) && (strcmp(inputs[2].c_str(), i.lastName) == 0) && (strcmp(inputs[3].c_str(), i.phone) == 0);
    });

    if (find_ref == users.end()) {
        std::cout << "Search Error\n";
        return;
    }

    std::cout << find_ref - users.begin() << '\n';
}

void process_delete(std::vector<StRec>& users, const std::vector<std::string>& inputs) {
    const auto find_ref = std::find_if(users.begin(), users.end(), [&inputs](const StRec& i) {
        return (strcmp(inputs[1].c_str(), i.firstName) == 0) && (strcmp(inputs[2].c_str(), i.lastName) == 0) && (strcmp(inputs[3].c_str(), i.phone) == 0);
    });

    if (find_ref == users.end()) {
        std::cout << "Delete Error\n";
        return;
    }

    users.erase(find_ref);
}
