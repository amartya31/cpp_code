#include <iostream>
using namespace std;

class Sig
{
public:
    template <typename Cb>
    void onSet(Cb call_back); // declared the call function function

    void consume(int a); // declared the consume

private:
    using _callBack = std::function<void(int, string)>; // defined the type
    _callBack callback = nullptr;                       // defined the varible
};
template <typename Cb>
void Sig::onSet(Cb call_back) // defined a function call_back
{
    callback = call_back; // assigning the calback to variable
}
void Sig::consume(int a)
{
    switch (a)
    {
    case 2:
        callback(a, "Correct");
        break;
    default:
        callback(a, "Incorrect");
        break;
    }
}

int main()
{
    Sig sig;
    sig.onSet([](int i, string s)
              { cout << "The value for [" << i << "] is string [" << s << "]" << endl; });
    sig.consume(2);
    return (0);
}
