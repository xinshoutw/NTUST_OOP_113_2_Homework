#include "password.h"
#include "user.h"
#include <iostream>

int main() {
    using namespace Authenticate;
    using namespace std;
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() << " and your password is: " << getPassword() << endl;

    return 0;
}
