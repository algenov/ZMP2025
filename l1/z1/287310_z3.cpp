#include <iostream>
using namespace std;

int main(){
    int n;
    int counter;
    counter = 1;
    int result;
    result = 0;

    int counter1;
    cin >> n;
    cout << "liczba zer na końcu liczby zależy od tego, ile razy mnożylismy przez 10. ale dwójek w silnie zawsze będzie więcej niż piątek, więc można zwrócić uwagę tylko na 5" << "\n";
    while (counter <= n)
    {
        counter1 = counter;
        while (counter1%5==0)
        {
            result = result + 1;
            counter1 = counter1 / 5;
        }
        counter = counter + 1;
        

    }
    cout << result << "\n";

    return 0;
}