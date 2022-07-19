class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        string x1="";
        string x2="";
        
        int n1=v1.size();
        vector<int> arr1;
        for(int i=0;i<n1;i++)
        {
            if(v1[i]=='.')
            {
                if(x1=="")
                    arr1.push_back(0);
                else
                    arr1.push_back(stoi(x1));
                
                x1="";
            }
            else
            {
                x1+=v1[i];
            }
            
            if(i==n1-1&&v1[i]!='.')
            {
                    if(x1=="")
                        arr1.push_back(0);
                   else
                    arr1.push_back(stoi(x1));
            }
        }
        
        int n2=v2.size();
        vector<int> arr2;
        x1="";
         for(int i=0;i<n2;i++)
        {
            if(v2[i]=='.')
            {
                if(x1=="")
                    arr2.push_back(0);
                else
                    arr2.push_back(stoi(x1));
                
                x1="";
            }
            else
            {
                x1+=v2[i];
            }
            
            if(i==n2-1&&v2[i]!='.')
            {
                    if(x1=="")
                        arr2.push_back(0);
                   else
                    arr2.push_back(stoi(x1));
            }
             
            // cout<<x1<<endl;
        }
        
      
        int i=0;
        int j=0;
       // cout<<arr1.size()
        while(i<arr1.size()&&j<arr2.size())
        {
            //cout<<arr1[i]<<" "<<arr2[j]<<endl;
            if(arr1[i]>arr2[j])
            {
                return 1;
            }
            
            if(arr1[i]<arr2[j])
            {
                return -1;
            }
            i++;
            j++;
        }
        
        while(i<arr1.size())
        {
            if(arr1[i])
                return 1;
            i++;
        }
        
        while(j<arr2.size())
        {
            if(arr2[j])
                return -1;
            j++;
        }
        
        return 0;
    }
};