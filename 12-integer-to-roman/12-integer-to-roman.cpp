class Solution {
public:
    string intToRoman(int num) {
        
        map<int,string> mp;
        
        mp[1]="I";
        mp[5]="V";
        mp[10]="X";
        mp[50]="L";
        mp[100]="C";
        mp[500]="D";
        mp[1000]="M";
        
        mp[4]="IV";
        mp[9]="IX";
        mp[40]="XL";
        mp[90]="XC";
        mp[400]="CD";
        mp[900]="CM";
        
        vector<int> arr;
        arr.push_back(1);
         arr.push_back(5);
         arr.push_back(10);
         arr.push_back(50);
         arr.push_back(100);
         arr.push_back(500);
         arr.push_back(1000);
         arr.push_back(4);
         arr.push_back(9);
         arr.push_back(40);
         arr.push_back(90);
         arr.push_back(400);
         arr.push_back(900);
        
        sort(arr.begin(),arr.end());
        
        string ans="";
        
        int cnt =0;
        
        while(num>0)
        {
            int k= num%10;
            num=num/10;
            
            
            
            k=k*(pow(10,cnt));
           
            
            if(mp.find(k)!=mp.end())
            {
                ans=mp[k]+ans;
            }
            else
            {
                string ss="";
               while(k!=0)
               {
                   int p = upper_bound(arr.begin(),arr.end(),k)-arr.begin();
                   
                   p--;
                   
                   int ut = k/arr[p];
                   
                   while(ut>0)
                   {
                       ss+=mp[arr[p]];
                       ut--;
                   }
                   
                   k=k%arr[p];
               }
                
                ans=ss+ans;
            }
            cnt++;
        }
        
        return ans;
        
    }
};