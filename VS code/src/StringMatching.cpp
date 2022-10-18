
// DO PHUC TAP CUA THUAT TOAN LA O(mn)
// SO PHEP SO SANH: 4
// SO PHEP GAN: 6

#include <bits/stdc++.h>

using namespace std;

void search(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    
    for (int i = 0; i <= N - M; i++)
    {
        int j = 0;
        while(j < M && pat[j] == txt[i + j])
        {
            j++;
        }
        if(j == M)
            printf("Pattern found at index %d \n", i);
    }
}
 

int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    system("pause");
    return 0;
}