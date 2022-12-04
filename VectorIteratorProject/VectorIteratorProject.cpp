#include <iostream>
#include "Vector.h"

#include "ForwardList.h"

using namespace std;

template <typename T>
void ContainerPrint(Iterator<T>* it)
{
    for (it->Set(); !it->IsEnd(); it->Next())
        cout << it->Current() << " ";
}

int main()
{
    //srand(time(nullptr));

    //Vector<int> v1(10);


    //cout << v1.Size() << " " << v1.Capacity() << "\n";

    //Iterator<int>* it1 = v1.GetBeginIt();

    //for (int i = 0; i < v1.Size(); i++)
    //    v1[i] = rand() % 100;

    ///*for (int i = 0; i < v1.Size(); i++)
    //    cout << v1[i] << " ";*/

    //ContainerPrint(it1);

    //Vector<double> v2(5);
    //for (int i = 0; i < v2.Size(); i++)
    //    v2[i] = (rand() % 100) / 10.5;

    //cout << "\n";

    //Iterator<double>* it2 = v2.GetBeginIt();
    //ContainerPrint(it2);

    //cout << "\n";

    //ForwardList<int> list;
    //for (int i = 0; i < 8; i++)
    //    list.Insert(0, rand() % 100);

    //Iterator<int>* lit1 = list.GetBeginIt();
    //ContainerPrint(lit1);
    
}
