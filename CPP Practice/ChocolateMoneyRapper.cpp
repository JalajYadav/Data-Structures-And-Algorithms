// U r given sm money 
// U can buy 1 chocolate for 1$
// For every 3 rappersu give, u can take 1 more chocolate 

#include<iostream>
using namespace std;
int main()
{
    int money,choco,rap;
    cin>>money;
    choco=money/1;
    rap=choco;
    while (rap>2)
    {
        choco=choco+(rap/3);
        int x=rap;
        rap=(x/3)+(x%3);
    }
    cout<<choco;
    return 0;

}