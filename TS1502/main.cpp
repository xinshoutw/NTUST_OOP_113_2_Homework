#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

template <typename T>
void join(const std::set<T>& elements, const std::string& seperator = ", ") {
    bool first = true;
    for (const auto& elem : elements) {
        if (!first) {
            std::cout << seperator;
        }
        std::cout << elem;
        first = false;
    }
}

class DB {
    // Key: pair<title, author>, Value: set of editions
    std::map<std::pair<std::string, std::string>, std::set<int>> database;

public:
    void insert(const std::string& command) {
        char title_c[200];
        char author_c[200];
        int edition;
        char extra_c[200];

        const int valid_count = sscanf(command.c_str(), R"(Insert "%199[^"]" "%199[^"]" %d %199s)", title_c, author_c, &edition, extra_c);

        if (valid_count != 3) {
            std::cout << "Incomplete Command.\n";
            return;
        }

        std::string title(title_c);
        std::string author(author_c);
        const std::pair<std::string, std::string> book_key = {title, author};

        const auto it = database.find(book_key);
        if (it == database.end()) {
            database[book_key].insert(edition);
            std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
            return;
        }

        auto& editions = it->second;
        const auto insert_result = editions.insert(edition);
        if (insert_result.second) {
            std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
        } else {
            std::cout << "Datum already exist.\n";
        }
    }

    void delete_item(const std::string& command) {
        char title_c[200];
        char author_c[200];
        int edition_val;
        char extra_c[200];

        if (command.rfind("Delete Edition ", 0) == 0) {
            const int vc = sscanf(command.c_str(), R"(Delete Edition "%199[^"]" "%199[^"]" %d %199s)", title_c, author_c, &edition_val, extra_c);
            if (vc != 3) {
                std::cout << "Incomplete Command.\n";
                return;
            }
            std::string title(title_c);
            std::string author(author_c);
            std::pair<std::string, std::string> book_key = {title, author};

            auto it = database.find(book_key);
            if (it != database.end()) {
                auto& editions = it->second;
                if (editions.count(edition_val)) {
                    editions.erase(edition_val);
                    std::cout << "Delete " << author << "'s " << title << ", Edition: " << edition_val << ".\n";
                    if (editions.empty()) {
                        database.erase(it);
                    }
                } else {
                    std::cout << "Datum doesn't exist.\n";
                }
            } else {
                std::cout << "Datum doesn't exist.\n";
            }
        } else if (command.rfind("Delete Book ", 0) == 0) {
            const int vc = sscanf(command.c_str(), R"(Delete Book "%199[^"]" "%199[^"]" %199s)", title_c, author_c, extra_c);
            if (vc != 2) {
                std::cout << "Incomplete Command.\n";
                return;
            }
            std::string title(title_c);
            std::string author(author_c);
            std::pair<std::string, std::string> book_key = {title, author};

            auto it = database.find(book_key);
            if (it != database.end() && !it->second.empty()) {
                std::cout << "Delete " << author << "'s " << title << ".\n";
                database.erase(it);
            } else {
                std::cout << "Book doesn't exist.\n";
            }
        } else {
            std::cout << "Unknown Command.\n";
        }
    }

    void find(const std::string& command) const {
        char title_c[200];
        char author_c[200];
        char extra_c[200];

        if (command.rfind("Find Book ", 0) == 0) {
            const int vc = sscanf(command.c_str(), R"(Find Book "%199[^"]" "%199[^"]" %199s)", title_c, author_c, extra_c);
            if (vc != 2) {
                std::cout << "Incomplete Command.\n";
                return;
            }
            std::string title(title_c);
            std::string author(author_c);

            const auto it = database.find({title, author});
            if (it != database.end() && !it->second.empty()) {
                std::cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
                join(it->second);
                std::cout << "\n";
            } else {
                std::cout << "Book doesn't exist.\n";
            }
        } else if (command.rfind("Find Author ", 0) == 0) {
            const int vc = sscanf(command.c_str(), R"(Find Author "%199[^"]" %199s)", author_c, extra_c);
            if (vc != 1) {
                std::cout << "Incomplete Command.\n";
                return;
            }
            const std::string author_to_find(author_c);
            std::set<std::string> found_titles;

            for (const auto& entry : database) {
                const std::string& current_book_author = entry.first.second;
                const std::string& current_book_title = entry.first.first;
                if (current_book_author == author_to_find && !entry.second.empty()) {
                    found_titles.insert(current_book_title);
                }
            }

            if (!found_titles.empty()) {
                std::cout << author_to_find << "'s Books: ";
                join(found_titles);
                std::cout << "\n";
            } else {
                std::cout << "No book found.\n";
            }
        } else {
            std::cout << "Unknown Command.\n";
        }
    }

    void sort_items(const std::string& command) const {
        char sort_by_what_c[200];
        char extra_c[200];

        const int vc = sscanf(command.c_str(), "Sort by %199s %199s", sort_by_what_c, extra_c);
        if (vc != 1) {
            std::cout << "Incomplete Command.\n";
            return;
        }

        const std::string sort_key(sort_by_what_c);
        std::vector<std::pair<std::pair<std::string, std::string>, std::set<int>>> sorted_entries;
        for (const auto& pair_entry : database) {
            if (!pair_entry.second.empty()) {
                sorted_entries.emplace_back(pair_entry);
            }
        }

        if (sort_key == "Title") {
            std::sort(sorted_entries.begin(), sorted_entries.end(), [](const auto& a, const auto& b) {
                if (a.first.first != b.first.first) {
                    return a.first.first < b.first.first;
                }
                return a.first.second < b.first.second;
            });
        } else if (sort_key == "Author") {
            std::sort(sorted_entries.begin(), sorted_entries.end(), [](const auto& a, const auto& b) {
                if (a.first.second != b.first.second) {
                    return a.first.second < b.first.second;
                }
                return a.first.first < b.first.first;
            });
        } else {
            std::cout << "Unknown Command.\n";
            return;
        }

        for (const auto& entry : sorted_entries) {
            const std::string& title = entry.first.first;
            const std::string& author = entry.first.second;
            const std::set<int>& editions = entry.second;

            std::cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
            join(editions);
            std::cout << "\n";
        }
    }
};

int main() {
    using namespace std;
    DB db;
    string command_line;
    while (getline(cin, command_line)) {
        if (command_line.rfind("Insert ", 0) == 0) {
            db.insert(command_line);
        } else if (command_line.rfind("Delete ", 0) == 0) {
            db.delete_item(command_line);
        } else if (command_line.rfind("Find ", 0) == 0) {
            db.find(command_line);
        } else if (command_line.rfind("Sort by ", 0) == 0) {
            db.sort_items(command_line);
        } else {
            if (!command_line.empty()) {
                std::cout << "Unknown Command.\n";
            }
        }
    }
    return 0;
}