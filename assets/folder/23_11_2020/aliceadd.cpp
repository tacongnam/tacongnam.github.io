#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll factorial(ll n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
int main()
{
    ll contribution = 0,votes=600;
    string s;
    cout << "Contribution Change after comment Calculator\n";
    cout << "Insert your CF Rank(Case Sensitive, e.x - Pupil, Specialist, Newbie, NO SPACES):   " << endl;
    cin >> s;
    cout << "Insert number of expected votes:" << endl;
    cin >> votes;
    if(s=="Newbie")
    {
        while(votes--){
            contribution--;
            if( votes < 10)
            {
                contribution+=2;
            }
        }
        cout << "Your new contribution score is: ";
        cout << contribution << endl;
    }
    if(s=="Pupil")
    {
        while(votes--)
        {
            contribution--;
            if(votes%5==0){
                contribution+=3;
            }
            if(votes%10==0){
                contribution++;
            }
        }
        cout << "Your new contribution score is: ";
        cout << contribution << endl;
    }
    if(s=="Specialist")
    {
        while(votes--)
        {
            int t = rand()%10+2;
            if(factorial(t) < 42069)
            {
                contribution++;
            }
            else
            {
                contribution--;
            }
        }
        cout << "Your new contribution score is: ";
        cout << contribution << endl;
    }
    if(s=="Expert")
    {
        int cc = __builtin_popcount(votes);
        contribution+=pow(3, min(5, cc-2))-pow(2, min(5, cc-3));
        cout << "Your new contribution score is: ";
        cout << contribution << endl;
    }
    if(s=="CandidateMaster")
    {
        cout << "If you have an anime profile picture input 1, else say 0" << endl;
        int anime = 0;
        cin >> anime;
        if(anime == 1)
        {
            cout << "n o";
            return 0;
        }
        else
        {
            int goodpost = rand()%2;
            int badpost = rand()%2;
            cout << "Your new contribution score is: ";
            cout << goodpost*(rand()%100+100)-badpost*(rand()%100+75) << endl;
        }
    }
    if(s=="Master")
    {
        cout << "If you have an anime profile picture input 1, else say 0" << endl;
        int anime = 0;
        cin >> anime;
        if(anime == 1)
        {
            cout << "n o";
            return 0;
        }
        else
        {
            cout << "Is your comment something like this 'How to solve E !???', 1 for yes, 0 for no" << endl;
            int lame = 0;
            cin >> lame;
            if(lame  == 1)
            {
                cout << "Your new contribution score is: ";
                cout << 3 << endl;
            }
            else
            {
                bool l = rand()%2;
                int c = 40;
                int nr = rand()%150;
                if(l == true)
                {
                    contribution = c+nr/2;
                }
                else
                {
                    contribution = c-max(nr*(-1), -52);
                }
            }
            cout << "Your new contribution score is: ";
            cout << contribution << endl;
        }
    }
    if(s=="InternationalMaster")
    {
        cout << "Do You have youtube channel? input 0 for yes, input 1 for no" << endl;
        int yt = 0;
        cin >> yt;
        if(!yt)
        {
            cout << "How many subscribar???" << endl;
            int sub = 0;
            cin >> sub;
            cout << "Your new contribution score is: ";
            cout << ((sub/3*3+15)*2/3+71)/2 << endl;
        }
        else
        {
            cout << "If you have an anime profile picture input 1, else say 0" << endl;
            int anime = 0;
            cin >> anime;
            if(anime == 1)
            {
                cout << "n o";
                return 0;
            }
            else
            {
                int goodpost = rand()%2;
                int badpost = rand()%2;
                cout << "Your new contribution score is: ";
                cout << goodpost*(rand()%100+100)-badpost*(rand()%100+75) << endl;
            }
        }
    }
    if(s=="Grandmaster")
    {
        int t = rand()%80+23;
        if(t == 69)
        {
            int hFBI = 0;
            cout << endl;
            cout << "This is the FBI, you need to come with us *blindfold over you*" << endl << endl;
            cout << "*helicopter noises*" << endl<< endl;
            cout << "*someone takes off the blindfold*" << endl<< endl;
            cout << "'You are in Area 51, we need to hack a Chinese Missle heading toward Alaska'" << endl<< endl;
            cout << "'can you help us?', 1 for yes, 0 for no" << endl<< endl;
            cin >> hFBI;
            cout << endl;
            if(hFBI == 0)
            {
                cout << "you get shot" << endl << endl;
                cout << "*Grandmaster dies*" << endl << endl;
            }
            else
            {
                cout << "some chinese guy that has like 15 IOI gold medals hacked you back and you failed" << endl << endl;
                cout << "you hear missles"<< endl << endl;
                cout << "*Grandmaster dies*" << endl << endl;
            }
        }
        else
        {
            cout << "Your new contribution score is: ";
            cout << t << endl;
        }
    }
    if(s=="LegendaryGrandmaster")
    {
        cout << "do you know tourist????" << endl;
    }
}