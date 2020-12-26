#include <iostream>
using namespace std;
class Rectangle {
protected:
int width;
int height;
public:
void display() {
  cout << this->width << " " << this->height << endl;
}
};
class RectangleArea:public Rectangle {

  public:
    void read_input() {
    cin >> this->width;
    cin >> this->height;
  }
  void display() {
    cout << this->width*this->height << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  //	cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	#endif
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    



  return 0;
}