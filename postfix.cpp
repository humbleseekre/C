
#include <stack>
#include <string>
#include <unordered_set>
#include <climits>
#include <iostream>

using namespace std;

typedef int (*func)(int);

int print(int num){
    cout << num << endl;
    return num;
}

unordered_set<char> operators{{'+', '-', '/', '*'}};

int calculate(int num1, int num2, char operation){
    switch (operation) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
        case '/':
            return num1 / num2;
        case '*':
            return num1 * num2;
        default:
            break;
    }
    return 0;
}

// 73 4 *
int postFix(const char* input[], int size){
    stack<int> postFix;
    for(int i =0; i< size; ++i){
        int j =0;
        int num = INT_MIN;
        while(input[i][j] != '\0'){
            if(operators.find(input[i][j]) != operators.end()){
                int num2 = postFix.top();
                postFix.pop();
                int num1 = postFix.top();
                postFix.pop();
                int res = calculate(num1, num2, input[i][j++]);
                postFix.push(res);
            }
            else{
                num =   num * 10 + (input[i][j++] - '0');
            }
        }
        if(num != INT_MIN){
            postFix.push(num);
        }
    }
    return postFix.top();
}


int main(){
    const char *input[] = {"5", "3", "+", "8", "2", "-", "*"};
    int result = postFix(input, 7);
    //int result =0;
    cout << result << endl;
    func pp = print;
    pp(result);
    return result;
}
