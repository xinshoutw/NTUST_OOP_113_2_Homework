#include "document.h"
#include "email.h"
#include "file.h"

inline bool ContainsKeyword(const Document& doc, const std::string& keyword) {
    return doc.getText().find(keyword) != std::string::npos;
}

int main() {

    // Create several test objects
    Email email1("Body about programming in C++", "Larry", "Curly", "Programming");
    Email email2("Body about running marathons", "Speedy", "Gonzales", "races");

    File file1("Contents about some C++ file", "file.txt");
    File file2("Contents about marathon races", "run.txt");
    // stream vs buffer
    cout << "Which contains C++?" << endl;
    if (ContainsKeyword(email1, "C++"))
        cout << " Email1" << endl;
    if (ContainsKeyword(email2, "C++"))
        cout << " Email2" << '\n';
    if (ContainsKeyword(file1, "C++"))
        cout << " File1" << endl;
    if (ContainsKeyword(file2, "C++"))
        cout << " File2" << endl;

    // Test our assignment operator
    file2 = file1;
    file2.setPathname("c:");
    cout << "After assignment file2=file1 and file2.setPathname(\"c:\"): " << endl;
    cout << "File1's path = " << file1.getPathname() << endl;
    cout << "File2's path = " << file2.getPathname() << endl;

    return 0;
}
