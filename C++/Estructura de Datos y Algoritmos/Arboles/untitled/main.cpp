#include <iostream>

using namespace std;
class ElementoArbol {
    public:
        // Members
        TipoDato dato;
        std::vector<std::shared_ptr<ElementoArbol>> children;
    public:
        // Constructor
        ElementoArbol(const TipoDato& dato_) : dato{dato_} {};
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
