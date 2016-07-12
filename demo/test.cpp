#include <iostream>
#include <string>
#include "base/logging.h"
#include "base/base64.h"

using namespace std;
using namespace base;

int main(void) {
    StringPiece s = "fffffffffffff";
    string out;
    Base64Encode(s, &out);
    cout << out << endl;
    LOG(INFO) << "KJLJKLJLK";
    return 0;
}
