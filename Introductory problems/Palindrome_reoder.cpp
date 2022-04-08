int cnt = 0;
bool chk[26];
string s, ans = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (char &c : s)
    {
        if (!chk[c - 'A'])
        {
            chk[c - 'A'] = true;
            cnt++;
        }
        else
        {
            ans += c;
            chk[c - 'A'] = false;
            cnt--;
        }
    }
    if (cnt >= 2)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    cout << ans;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (chk[c - 'A'])
        {
            cout << c;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}