

#include <iostream>

using namespace std;

class A {

    int aa;
};

class B {

    int bb;
};

class C : public A, public B {

    int cc;
};

int main(){

    C* pC = new C;
    B* pB = dynamic_cast<B*> (pC);

    cout << pC << endl;
    cout << pB << endl;
    
    cout << (C*)pB << endl;
    cout << pC << endl;

    if(pC == pB)
        cout << " equal" << endl;
    
    else
        cout << " not equal" << endl;
    
 /*   cout << pC << endl;
    cout << pB << endl;
    cout << int (pC) << endl;
    cout << int (pB) << endl;

    if(int (pC) == int (pB))
        cout << "equal" << endl;
    else
        cout << " not equal" << endl;
*/

    return 0;
}