#include<iostream>
#include<string>

using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        int flag = 0;
        int type = 0;
        for(int j = 0; j < s.length(); j++) {
            if(s[j] >= '0' && s[j] <= '9') {
                flag = 1;
            }
            if(flag == 1 && s[j] >= 'A' && s[j] <= 'Z') {
                type = 1;
                break;
            }
        }
        if(type == 0) {
            int r = 0, c = 0;
            for(int j = 0; j < s.length(); j++) {
                if(s[j] >= 'A' && s[j] <= 'Z') {
                    c *= 26;
                    c+=s[j]-'A'+1;
                } else {
                    r*=10;
                    r+=s[j]-'0';
                }
            }
            cout<<"R"<<r<<"C"<<c<<endl;
        } else {
            int r = 0, c = 0;
            int flag = 0;
            for(int j = 0; j < s.length(); j++) {
                if(s[j] == 'C') {
                    flag = 1;
                } else if(s[j] != 'R') {
                    if(flag==0) {
                        r*=10;
                        r+=s[j]-'0';
                    } else {
                        c*=10;
                        c+=s[j]-'0';
                    }
                }
            }
            string sc = "";
            int k = 1;
            int s = 1;
            int n = 0;
            while(c >= s) { k *= 26; s += k; sc+="A";}
            s -= k;
            k /= 26;
            c -= s;
            for(int j = 0;c!=0;j++) {
                sc[sc.length() - j - 1] = (char)(c%26+'A');
                c/=26;
            }
            cout<<sc<<r<<endl;
        }
    }
}
