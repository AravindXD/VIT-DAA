#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_digits(int number) {
    int digit_count = 0;
    while (number > 0) {
        digit_count++;
        number /= 10;
    }
    return digit_count;
}

bool are_digits_unique(int x, int y) {
    int x_size = count_digits(x);
    int y_size = count_digits(y);
    int digits_x[x_size];
    int digits_y[y_size];
    int remainder, idx = 0;
    
    while (x > 0) {
        remainder = x % 10;
        digits_x[idx++] = remainder;
        x /= 10;
    }
    idx = 0;
    while (y > 0) {
        remainder = y % 10;
        digits_y[idx++] = remainder;
        y /= 10;
    }
    
    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            if (digits_x[i] == digits_y[j]) {
                return false;
            }
        }
    }
    return true;
}

void find_largest_unique_set(vector<int> numbers, int size) {
    int i, j, max_count = 0;
    vector<int> largest_set;
    
    for (i = 0; i < size; i++) {
        vector<int> current_set = {numbers[i]};
        
        for (j = i + 1; j < size; j++) {
            bool is_unique = true;
            for (int k = 0; k < current_set.size(); k++) {
                if (!are_digits_unique(current_set[k], numbers[j])) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                current_set.push_back(numbers[j]);
            }
        }
        
        if (current_set.size() > max_count) {
            max_count = current_set.size();
            largest_set = current_set;
        } else if (current_set.size() == max_count && current_set < largest_set) {
            largest_set = current_set;
        }
    }
    
    if (largest_set.empty()) {
        cout << "-1" << endl;
    } else {
        cout << largest_set.size() << endl;
        for (int x : largest_set) {
            cout << x << endl;
        }
    }
}

int main() {
    int n, element;
    cin >> n;
    vector<int> input_array;
    
    for (int i = 0; i < n; i++) {
        cin >> element;
        input_array.push_back(element);
    }
    
    sort(input_array.begin(), input_array.end());
    find_largest_unique_set(input_array, n);

    return 0;
}