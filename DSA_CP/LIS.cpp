 #include <bits/stdc++.h>
using namespace std;
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
    cout<<temp.size();
}


 