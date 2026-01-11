#include<bits/stdc++.h>
using namespace std;

//passing function as argument
int apply(int x,int y,function<int(int,int)>f)
{
   return f(x,y);
}
int main()
{
   // tuple<int,int,int>t{1,2,3};
   // cout<<get<0>(t)<<endl;
   // cout<<get<1>(t)<<endl;
   // cout<<get<2>(t)<<endl;

   // auto [x,y,z] = t;

   // cout<<x<<" "<<y<<" "<<z<<" "<<endl; 

   // vector<tuple<int,int,int,int>>vt;
   // for(auto &[w,x,y,x]:vt){
   //    cout<<w x y z;
   // }
    
   //functional programming

   //lamda function
   auto add=[](int a,int b){
      return a+b;
   };

   cout<<add(3,4)<<endl;

   cout<<apply(4,5,add)<<endl;

   //MAP-->std::transform
   vector<int>v={1,2,3,4};
   vector<int>res(v.size());
   
   transform(v.begin(),v.end(),res.begin(),
             [](int x){return x*x;});
   for(auto i:res)cout<<i<<" ";  
   cout<<endl;
   
   //Filter-->copy_if
   vector<int>even;
   copy_if(v.being(),v.end(),back_insert(even),
         [](int x){return x%2==0;});
   
   //Reduce-->accumulate
   int sum=accumulate(v.begin(),v.end(),0,
             [](int a,int b){return a+b;});

             //function composition
             auto square = [](int x){ return x*x; };
auto inc = [](int x){ return x+1; };

auto square_then_inc = [&](int x){
    return inc(square(x));
};

cout << square_then_inc(4); // 17

}
