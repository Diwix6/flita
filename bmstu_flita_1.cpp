#include <iostream>
#include <vector>

using namespace std;

int bin_to_dec(int x){
    int result = 0, i = 1;
    
    while(x){
        result += (x % 10) * i;
        if (x % 10 != 1 && x % 10 != 0){
            cout << "___ERROR___\nWRONG INPUT\n";
            exit(0);
        }
        i *= 2;
        x /= 10;
    }
    return result;
}

bool duplicates_check(int x, vector<int> a){
    for (auto t : a)
        if (t == x) return false;
    return true;
}

int main(){
    int n = -1, tmp;
    cout << "___INPUT___\nsize > ";
    cin >> n;
    if (n <= 0) {
        cout << "___ERROR___\nWRONG SIZE";
        return 0;
    } 
    vector<int> vec(0), bin_vec(0);
    cout << "binary > ";
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if (duplicates_check(tmp, bin_vec)){
            bin_vec.push_back(tmp);
            vec.push_back(bin_to_dec(tmp));
        }
    }
    cout << "\nResult:\n";
    for (auto t : bin_vec)  cout << t << " ";
    cout << "\n";
    for (auto t : vec) cout << t << " ";
    return 0;
}