#include <bits/stdc++.h>
using namespace std;

//To recursively find length of longest increasing subsequence
int recurseFn(vector<int> &ar,int i,int pr){
    if (i>= ar.size()) return 0;
    
    int len = 0 + recurseFn(ar,i+1,pr);
    if (pr == -1 || ar[i]>pr){
        len = max(len, 1 + recurseFn(ar,i+1,ar[i]));
    }
    
    return len;
}

int main()
{
    vector<int>nums={0,1,0,3,2,3};
    vector<int>temp;
    temp.push_back(nums[0]);
    int n=nums.size();
    for(int i=1;i<n;i++)
    {
        if(nums[i]>temp.back())
            temp.push_back(nums[i]);
        else
        {
            int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            // cout<<ind<<endl;
            temp[ind]=nums[i];
        }
    }
    cout<<"Output from recursive fn :"<<recurseFn(nums,0,-1)<<"\n";
    cout<<temp.size();
}


 
