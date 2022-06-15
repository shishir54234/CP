#include<bits/stdc++.h>
using namespace std;
int convertbinary(string st, char *arr)
{
    int x=0;
    for(int i=0;i<st.length();i++)
    {
        if (memchr(arr, st[i], sizeof(arr)))
        {
            x=x+pow(2,i);
        }
    }
    return x;

}
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n;
        cin>>n;
        string st;
        cin>>st;
        int y;
        cin>>y;
        char arr[y];
        int lol;
        for(int i=0;i<y;i++)
        {
            char s;
            cin>>s;
            arr[i]=s;
        }
        lol=convertbinary(st,arr);
        

    }
}