 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     int a,b,n;
     cin>>a>>b;
     cin>>n;
     int flag=0;
     for(int i=0;i<10;++i)
     {
         if((10*a+i)%b==0)
         {
            
            cout<<(10*a+i)*pow(10,n-1)<<endl;
            flag++;
            break;
         }
     }
     if(!flag)
     {
         cout<<-1;
     }
     
 }
 