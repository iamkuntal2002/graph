#include <bits/stdc++.h>
using namespace std;
int minSteps(int D)
{
    // code here
    int target = abs(D);
    int step = 0;
    int sum = 0;
    while (sum < target)
    {
        step++;
        sum += step;
    }
    cout<<"sum = "<<sum<<" step = "<<step<<endl;
    while ((sum - target) % 2 != 0)
    {
        step++;
        sum += step;
        cout<<"sum = "<<sum<<" step = "<<step<<endl;

    }
    return step;
}
int main()
{
    // cout << minSteps(13) << endl;
    cout<<(-1)%13<<endl;
}