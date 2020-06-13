int n;
int ans = 0;
for(int i=0;i<60;i++) /// assuming N has maximum 60 digits in binary form
    if((n>>i)&1)
        ans += (1ll<<(i+1)) - 1;
cout<<ans<<endl;
