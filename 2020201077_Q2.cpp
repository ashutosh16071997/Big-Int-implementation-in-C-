#include<bits/stdc++.h>
using namespace std;
int multiply(int i, int arr[], int size)
{
    int carry = 0;
    for(int j = 0;j<size;j++)
    {
        int val = arr[j]*i + carry;
        arr[j] = val%10;
        carry = val/10;
    }
    while(carry)
    {
        arr[size] = carry%10;
        carry = carry/10;
        size++;
    }
    return size;
}
void fact()
{
    int n;
    cin>>n;
    int arr[5000];
    arr[0] = 1;
    int size = 1;
    int i = 2;
    while(i<=n)
    {
        size = multiply(i , arr, size);
        i++;
    }
    int j = size-1;
    while(j>=0)
    {
        cout<<arr[j];
        j--;
    }
}
string multiply(string a , string b)
{
    int n = a.length();
    int m = b.length();
    int arr[n+m] ;
    for(int i = 0;i<n+m;i++)
    {
        arr[i] = 0;
    }
    int c = 0; int d = 0;
    int i = a.length()-1;
    while(i>=0)
    {
        int carr = 0;
        int val = (a[i] - '0');
        d = 0;
        int j = b.length()-1;
        while(j>=0)
        {
            int (val2) = (val)*(b[j]-'0');
            int (val3) = (val2) + arr[c+d] + carr;
            carr = (val3)/10;
            arr[c+d] = (val3)%10;
            d++;
            j--;
        }
        if(carr>0)
        {
            arr[c+d]+= carr;
        }  
        i--;c++;
    }
    string res = "";
    int k = n+m-1;
    while(arr[k]==0 && k>=0)
    k--;
    while(k>=0)
    {
        res+=(arr[k] + '0');k--;
    }
    return res;
}

void exp()
{
    string res = "1";
    string a ; int b;
    cin>>a>>b;
    if(b==0)
      {
          cout<<res<<endl;
          return;
      }
      while(b>0)
      {
          if(b%2!=0)
          {
              res = multiply(res,a);
          }
           
      
         a = multiply(a,a);
         b = b/2;
      }
      cout<<res<<endl;
}

string zeroes(string str)
{
    long long int i = 0;
    while(i<str.length() && str[i] == 0)
           i++;
    string ptr ="";
    while(i<str.length())
     { ptr+=str[i];i++;}
     return ptr; 
}
long long int gcd3( long long int val,long long int sal)
{
    if(val>sal)
    {
        long long int tal = val;
        val = sal;
        sal = tal;
    }
    if(val == 0)
       return sal;
     return gcd3(val%sal,val);  
}
long long int gcd1(string s1,string s2)
{
    long long int val = 0;
    long long int sal = 0;
    for(int i = 0;i<s1.length();i++)
    val = val*10 + (s1[i] - '0');
    for(int i = 0;i<s2.length();i++)
    sal = sal*10 + (s2[i] - '0');
    return gcd3(val , sal);
}
long long int gcd2(string s1,string s2)
{
    long long int val = 0;
    long long int sal = 0;
    for(int i = 0;i<s2.length();i++)
    sal = sal*10 + (s2[i] - '0');
    for(int i = 0 ; i<s1.length();i++)
     {
         val = (val*10 +(s1[i] - '0'))%sal;
     }
     return gcd3(val,sal);
}

 
long long int gcd4(string s1,string s2)
{
    s1 = zeroes(s1);
    s2 = zeroes(s2);
    if(s1.length()<s2.length())
    {
        string c = s1;
        s1 = s2;
        s2 = c;
    }
    else if(s1.length()==s2.length())
    {
        string s3;
        int flag = 0;
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])       
               break;
            else
               {
                   string s3 = s1;
                   s1 = s2;
                   s2 = s3;
                   break;
               }
        }
        
    }
    while(s1.length()>s2.length())
    {
        s1 = zeroes(s1);
        s2 = zeroes(s2);
        string str = "";
        int n = s1.length();
        int m = s2.length();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int carr = 0;
        int i = 0;
        while(i<m)
        {
            int val = ((s1[i]-'0')-(s2[i]-'0')-carr);
        if (val < 0) 
        { 
            val = val + 10; 
            carr = 1; 
        } 
        else
            carr = 0; 
 
        str.push_back(val + '0'); 
         i++; 
        }
        while(i<n)
      { 
        int val= ((s1[i]-'0') - carr); 
 
        if (val < 0) 
        { 
            val = val + 10; 
            carr = 1; 
        } 
        else
            carr = 0; 
 
        str.push_back(val+ '0'); 
        i++;
      }
      reverse(str.begin(),str.end());
      s1 = str;
    }
    while(s1.length()>18)
    {
        s1 = zeroes(s1);
        s2 = zeroes(s2);
    if(s1.length()<s2.length())
    {
        string c = s1;
        s1 = s2;
        s2 = c;
    }
    else if(s1.length()==s2.length()) 
    {
        string s3;
        int flag = 0;
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])
              {
                
                  break;
              }
              else
              {
                  string c = s1;
                  s1 = s2;
                  s2 = c;
                  break;
              }
        }
 
    }
        string ptr = "";
        int t = s1.length();
        int q = s2.length();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int tarr = 0;
        int k = 0;
        while(k<q)
        {
            int val = ((s1[k]-'0')-(s2[k]-'0')-tarr);
             if (val < 0) 
           { 
            val = val + 10; 
            tarr = 1; 
           } 
        else
            tarr = 0; 
 
        ptr.push_back(val + '0'); 
         k++; 
        }
        while(k<t)
         { 
        int val= ((s1[k]-'0') - tarr); 
        if (val < 0) 
        { 
            val = val + 10; 
            tarr = 1; 
        } 
        else
            tarr = 0; 
 
        ptr.push_back(val + '0'); 
        k++;
      }
      reverse(ptr.begin(),ptr.end());
      s1 = ptr;
    }
    return gcd2(s1,s2);
 }
 
 
 
 
  void gcd()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    if(s1.length()<s2.length())
    {
        string s3 = s2;
        s2 = s1;
        s1 = s3;
    }
    else if(s1.length()==s2.length())
    {
        string s3;
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])       
               break;
            else
               {
                  s3 = s1;
                   s1 = s2;
                   s2 = s3;
                   break;
               }
        }
       
    }
    if(s1.length()<18)
    {
      
        long long int result = gcd1(s1,s2);
        cout<<result;
        return;
    }
    else if(s1.length()>18 && s2.length()<18)
    {
        long long int result = gcd2(s1,s2);
        cout<<result;
        return;
    }
    else if(s1.length()>18 && s2.length()>18)
    {
        long long int result = gcd4(s1,s2);
        cout<<result;
        return;
    }
}

int main()
{
    cout<<"Enter 1 for exponentiation, 2 for GCD, 3 for factorial"<<endl;
    int n;
    cin>>n;
    if(n==3)
   fact();
   else if(n==2)
   gcd();
   else if(n==1)
   exp();
   else
   {
   cout<<"Wrong Choice"<<endl;} 
    return 0;
}

