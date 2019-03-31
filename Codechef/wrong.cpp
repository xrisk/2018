#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void func(long long num, int digit)
{
    list<int> digit_arr;
    long long copy_num;
    int digit_count = 0, valid_count = 0;
    while(num > 0)
    {
        int r = num%10;
        if(r < digit)
        {
            digit_arr.push_front(r);
            valid_count++;
        }
        digit_count++;
        num /= 10;
        
    }
    int push_digit = digit_count - valid_count;
    
    while(push_digit--)
    digit_arr.push_back(digit);
    
    list <int> :: iterator it;
    for(it = digit_arr.begin();it != digit_arr.end(); it++)
        cout<<*it;
        
    return;
}

int main() {

    #ifdef __APPLE__
    freopen("input.txt", "r", stdin);
#endif
    
    int t, d;
    long long num;
    cin>>t;
    while(t--)
    {
        cin>>num>>d;
        func(num,d);
        cout<<"\n";
    }
    
	return 0;
}