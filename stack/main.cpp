#include <iostream>
#include "stack.hpp"
using namespace std;
int main()
{
    Stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;

    return 0;
}