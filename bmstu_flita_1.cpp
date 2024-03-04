#include <iostream>
#include <vector>

using namespace std;

int bin_to_dec(int x){
    int result = 0, i = 1;
    while(x){
        result += (x % 10) * i;
        if (x % 10 > 1){
            cout << "ERROR\nInput is not binary\n";
            exit(0);
        }
        i *= 2;
        x /= 10;
    }
    return result;
}

int main(){
    int n;
    cout << "INPUT\nn > ";
    cin >> n;
    vector<int> bin_vec(n), vec(n);
    cout << "binary > ";
    for(int i = 0; i < n; i++){
        cin >> bin_vec[i];
        vec[i] = bin_to_dec(bin_vec[i]);
    }
    cout << "\nResult:\n";
    for (auto t : bin_vec)  cout << t << " ";
    cout << "\n";
    for (auto t : vec) cout << t << " ";
    return 0;
}