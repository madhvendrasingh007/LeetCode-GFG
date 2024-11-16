class Solution {
public:
    string originalDigits(string s) {
        string k="";
    unordered_map<char,int> m;
        int arr[10]={0};
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        /*
        if w is present then 2
        if u is present then 4
        if x is present then 6
        if g is present then 8
        if z is present then 0
        */
   arr[2]=m['w'];
   arr[4]=m['u'];
   arr[6]=m['x'];
   arr[8]=m['g'];
   arr[0]=m['z'];
        
    /* To identify other numbers remove the common characters if they are present else 0 
    will get subtracted if character is not present 
    */
   arr[1]=m['o']-arr[2]-arr[4]-arr[0];
   arr[3]=m['h']-arr[8];
   arr[5]=m['f']-arr[4];
   arr[7]=m['s']-arr[6];
   arr[9]=m['i']-arr[5]-arr[8]-arr[6]; 
    for(int i=0;i<10;i++){
        while(arr[i]--)
       k+=to_string(i);  
    }
        
        sort(k.begin(),k.end());
      return k;
    }
};