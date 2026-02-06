#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isAvailable;

    // Constructor
    Book(int id, string title, string author);
};

#endif