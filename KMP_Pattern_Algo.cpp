#include <bits/stdc++.h>
using namespace std;
//name lps indicates longest proper prefix which is also suffix
void lps_create(string pat,int* lps)
{
    int len=0;      //len is length of prefix which is similar to suffix length
    lps[0]=0;                           //  | 0 | A | A | A | C | A | A | A | A |
    int m = pat.length();               //  | 0 | 1 | 2 | 0 | 1 | 2 | 3 | 3 |
    int i=1;                            
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = len;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
        
    }                            
}
void search(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    lps_create(pat,lps);
    int j=0; //i is pointer for pattern
    for(int i =0; i<n;i++)//i is pointer for text
    {
        if(txt[i]==pat[j])
        {
            j++;
            if(j==m)
            {
                cout<<"Pattern Found";
            }
        }
        else
        {
            j=lps[j];
        }
    }

}

int main ()
{
    cout<<"Please enter the text >>> ";
    string text_input;
    getline(cin,text_input);
    cout<<"Please enter the pattern to be searched >>> ";
    string pattern_input;
    getline(cin,pattern_input);

    search(text_input,pattern_input);
    return 0;
}