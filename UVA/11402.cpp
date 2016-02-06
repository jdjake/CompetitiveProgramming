#include <iostream>
#include <string>
#include <memory>

using namespace std;

string read_input_string() {
    int num_strings;
    cin >> num_strings;

    string total_string;
    for (int i = 0; i < num_strings; i++) {
        int string_repeat_num;
        cin >> string_repeat_num;

        string string_to_repeat;
        cin >> string_to_repeat;

        for (int j = 0; j < string_repeat_num; j++) {
            total_string += string_to_repeat;
        }
    }

    return total_string;
}

class segment_tree {
public:
    int left_boundary;
    int right_boundary;
    int value;

    unique_ptr<segment_tree> left;
    unique_ptr<segment_tree> right;

    ~segment_tree() {
        delete left;
        delete right;
    }
};

unique_ptr<segment_tree> build_segment_tree(string input, int left_range, int right_range) {
    // Bottom leaves of tree
    unique_ptr<segment_tree> x (new segment_tree);
    x->left_boundary = left_range;
    x->right_boundary = right_range;

    if (left_range == right_range) {
        x->value = (input.at(left_range) == 1) ? 1 : 0;
    }

    else {
        int halfway = left_range + (right_range - left_range)/2;

        // Recurse building up the tree
        x->left = build_segment_tree(input, left_range, halfway);
        x->right = build_segment_tree(input, halfway + 1, right_range);

        x->value = (x->left)->value + (x->right)->value;
    }

    return x;
}

void solve_test_case() {
    string input = read_input_string();
    cout << input << endl;

    unique_ptr<segment_tree> pirate_tree = build_segment_tree(input, 0, input.size() - 1);

    int query_num;
    cin << query_num;

    for (int i = 0; i < query_num; i++) {
        char instruction_type;
        int left_range, right_range;

        cin >> instruction_type >> left_range >> right_range;

        if (instruction_type == 'F') buccaneer();
        if (instruction_type == 'E') barbary();
    }
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) solve_test_case();
}