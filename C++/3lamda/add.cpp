#include <iostream>

using namespace std;
class Sig
{
public:
    /* Create alias for the function which returns void and takes int */
    using Callback = std::function<void()>;

    /* Setting  the callback */
    void setCallback(Callback cbk)
    {
        callback = cbk;
    };
    /* Calling the calback  */
    void callCallback(int val)
    {
        cout << "Int val = " << val << endl;
        if (val % 2 == 0)
        {
            callback();
        }
    };

private:
    /* Creating a varible  */
    Callback callback;
};

int main()
{
    Sig sig;
    int data = 55;
    cout << "The value of data = " << data << endl;
    /* Setting the callback  */
    sig.setCallback([&]()
                    {
        data = data + 5;
        cout << "The added data = " << data << endl; });
    for (int i = 0; i < 5; i++)
    {
        sig.callCallback(i);
    }
    cout << "The added data final = " << data << endl;

    return (0);
}