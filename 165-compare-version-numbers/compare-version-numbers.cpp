class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1,ver2,ptr1=0,ptr2=0;
        int len1=version1.size();
        int len2=version2.size();
        while(ptr1<len1 || ptr2<len2){
            ver1=0,ver2=0;
            while(ptr1<len1 && version1[ptr1]!='.'){
                ver1*=10;
                ver1+=(version1[ptr1++]-'0');
            }
            while(ptr2<len2 && version2[ptr2]!='.'){
                ver2*=10;
                ver2+=(version2[ptr2++]-'0');
            }
            if(version1[ptr1]=='.')
                ptr1++;
            if(version2[ptr2]=='.')
                ptr2++;
            if(ver1>ver2)
                return 1;
            if(ver1<ver2)
                return -1;
        }
        return 0;
    }
};