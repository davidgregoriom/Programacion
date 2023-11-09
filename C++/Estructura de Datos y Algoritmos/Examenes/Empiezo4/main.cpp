#include <iostream>

using namespace std;
class FigGeomRegular {
  public:
   FigGeomRegular(float _long, float _lados);
   float getArea() const;
   float getPerimeter() const;

  private:
    int n_lados;
    float longitud;
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
