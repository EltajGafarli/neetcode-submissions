class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int end = num1.length() - 1;

        string ans = multiplyBySingleNum(num1[end], num2);
        end--;

        int k = 1;

        for (int i = end; i >= 0; i--) {
            string mul = multiplyBySingleNum(num1[i], num2);

            for (int j = 0; j < k; j++) {
                mul += "0";
            }
            k++;

            ans = add(ans, mul);
        }
        return ans;
    }

    string multiplyBySingleNum(char single, string num) {
        int end = num.length() - 1;

        int carr = 0;

        for(int i = end; i >= 0; i --) {
            int mul = (num[i] - '0') * (single - '0') + carr;

            int res = mul % 10;
            carr = mul / 10;

            num[i] = '0' + res;
        }

        if (carr != 0) {
            num = to_string(carr) + num;
        }

        return num;
    }

   string add(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res;

    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;

        int sum = x + y + carry;
        res.push_back('0' + sum % 10);
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}
};
